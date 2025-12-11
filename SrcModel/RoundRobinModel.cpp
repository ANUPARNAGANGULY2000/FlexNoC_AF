#include<RoundRobinModel.h>
#include<iostream>
#include<UpdateNodeQueue.h>

namespace model{
//Round Robin Arbitration
void roundrobin_model(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double service_time, double zero_load_latency, dot_lang::Mapping& mapping){

	std::vector<double> injection_rates;
	std::vector<double> interarrival_times;
	std::vector<int> buffer_sizes;

    //getting injection_rates,interarrival_times,buffer_sizes from queue
    for(auto queue_number=0; queue_number<queues.size(); ++queue_number){
    double injection_rate = queues[queue_number]->getInjectionRate();
    double coeff_interarrival_time = queues[queue_number]->getCoeffInterArrivalTime();
    double buffer_size = queues[queue_number]->getBufferSize();
    injection_rates.push_back(injection_rate);
    interarrival_times.push_back(coeff_interarrival_time);
    buffer_sizes.push_back(buffer_size);
    }

    std::vector<double> waiting_times(injection_rates.size(), 0.0); // To store Waiting time of each queue
     // Initialization of intermediate parameters
    std::vector<double> lambda_a_cap = injection_rates;
    std::vector<double> ca_square_cap = interarrival_times;
    std::vector<double> rho(injection_rates.size(), 0.0);
    std::vector<double> n(injection_rates.size(), 0.0);
    std::vector<double> pi_j(injection_rates.size(), 0.0);
    std::vector<double> t_cap(injection_rates.size(), service_time);
    int total_iteration = 1; // Number of iterations for convergence
    double rate =0;
    double total_utilization = 0.0;

    for (int i=0;i<injection_rates.size();++i) {
        rate = injection_rates[i];
        total_utilization += rate;
    }
    if(total_utilization < 0.998){
    // Waiting time before saturation
        for (int iteration = 0; iteration < total_iteration; ++iteration) {
            for (int queue_number = 0; queue_number < queues.size(); ++queue_number) {
                if(injection_rates[queue_number] != 0){
                // Calculate utilization rho
                rho[queue_number] = t_cap[queue_number] * lambda_a_cap[queue_number];
		// Occupancy equation from finite WRR paper
                n[queue_number] = rho[queue_number] * (rho[queue_number] - 1 + ca_square_cap[queue_number] + ca_square_cap[queue_number] * rho[queue_number]) / (2 - 2 * rho[queue_number]) + rho[queue_number];
            }
        }
	for(int queue_number=0; queue_number<queues.size();++queue_number)
            {
               if(injection_rates[queue_number] != 0){
                     double sum_min_occupancy = 0.0;
                     for(int other_queue=0; other_queue<queues.size(); ++other_queue){
                        if(other_queue!=queue_number){
                                sum_min_occupancy += lambda_a_cap[other_queue];
                        }
                    }
		    //modified service process for each queues
                    t_cap[queue_number] = service_time + service_time *std::min(1.0,(t_cap[queue_number] * lambda_a_cap[queue_number])) * std::min(1.0,t_cap[queue_number]*sum_min_occupancy);
		    //cout<<"updated t_cap for queue "<<queue_number<<" is: "<<t_cap[queue_number]<<endl;
               }
            }

            // Calculate waiting times before saturation
            for(int queue_number=0; queue_number<queues.size(); ++queue_number){
                if(injection_rates[queue_number]!=0){
                        waiting_times[queue_number] = n[queue_number] / lambda_a_cap[queue_number] - t_cap[queue_number];
			waiting_times[queue_number] = waiting_times[queue_number] + zero_load_latency ;
			//cout<<"waiting time for queue "<<queue_number<<" is: "<<waiting_times[queue_number]<<endl;
                        queues[queue_number]->setWaitingTime(waiting_times[queue_number]);
                }
            }
        }
    }
    // Check if the total injection rate leads to saturation
    else if (total_utilization >= 0.998) {

        // Calculate lambda_a_cap ensuring total utilization remains 1
        for (size_t index = 0; index < injection_rates.size(); ++index) {
                if(injection_rates[index]!= 0){
                    double other_sum = total_utilization - injection_rates[index];
                    lambda_a_cap[index] = std::min(injection_rates[index], std::max(0.5, 1 - other_sum));
		    queues[index]->setInjectionRate(lambda_a_cap[index]);
		    queues[index]->activeInjectionRateUpdateFlag();
                }
        }

        for(size_t index = 0;index < injection_rates.size() ; ++index){
                if(injection_rates[index] != 0){
                    t_cap[index] = 1/lambda_a_cap[index];
                }
        }

        // Calculate ca_square_cap for each class after determining p_full from lambda_cap
        for (size_t index = 0; index < injection_rates.size(); ++index) {
                if(injection_rates[index]!=0){
                    double p_full = 1 - lambda_a_cap[index] / injection_rates[index];
                    ca_square_cap[index] = (1 - p_full) * (1 - injection_rates[index]);
		    queues[index]->setCoeffInterArrivalTime(ca_square_cap[index]);
                }
        }

        // Model for waiting time after saturation for each class
        for (size_t queue_number = 0; queue_number < queues.size(); ++queue_number) {
                if(injection_rates[queue_number]!=0){
                    int buffer_size = buffer_sizes[queue_number];
                    waiting_times[queue_number] = (2 * buffer_size - 3) * (buffer_size + (2 - buffer_size) * ca_square_cap[queue_number]) / (2 * lambda_a_cap[queue_number] * buffer_size			) + t_cap[queue_number];
		    waiting_times[queue_number] = waiting_times[queue_number] + zero_load_latency ;
		    queues[queue_number]->setWaitingTime(waiting_times[queue_number]);
                }
        }
	update_node_from_Queue(queues, mapping);
 }
   // return waiting_times;

}
}
