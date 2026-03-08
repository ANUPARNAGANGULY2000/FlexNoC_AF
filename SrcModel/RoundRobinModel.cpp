#include<RoundRobinModel.h>
#include<iostream>
#include<UpdateNodeQueue.h>
#include <cmath>
#include <unordered_set>

namespace model{
//Round Robin Arbitration
void roundrobin_model(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double service_time, double zero_load_latency, dot_lang::Mapping& mapping){

	if (queues.empty()) {
 	   std::cerr << "[RR] ERROR: queues vector is empty\n";
    	   return;
	}

	// ---- REMOVE DUPLICATE QUEUES ----
	std::unordered_set<dot_lang::Queue*> seen;
	std::vector<std::shared_ptr<dot_lang::Queue>> unique_queues;

	for (auto &q : queues) {
	    if (!q) continue;

 	    if (seen.insert(q.get()).second) {
       		 unique_queues.push_back(q);
    	    }
	}

	// Replace queues with unique queues
	queues.swap(unique_queues);

	if (queues.size() <= 1) {
    
		if (queues.empty()) {

			std::cerr << "[RR] queues is EMPTY\n";

			return;
                }

    	if (!queues[0]) {
        	std::cerr << "[RR] queues[0] is NULL (size = 1)\n";
       	 return;
    	}

    	queues[0]->setWaitingTime(zero_load_latency);
    	return;
       }	
	std::vector<double> injection_rates;
	std::vector<double> interarrival_times;
	std::vector<int> buffer_sizes;
	constexpr double EPS = 1e-12;

    //getting injection_rates,interarrival_times,buffer_sizes from queue
    for(auto queue_number=0; queue_number<queues.size(); ++queue_number){
	    if (!queues[queue_number]) {
       
		    std::cerr << "[RR] NULL queue at index " << queue_number << "\n";
        	    return;
            }
    	double injection_rate = queues[queue_number]->getInjectionRate();
   	 if (std::isnan(injection_rate) || std::isinf(injection_rate)){
    	injection_rate = 0.0;
    }
    
	 double coeff_interarrival_time = queues[queue_number]->getCoeffInterArrivalTime();

      	 //double coeff_interarrival_time = 1 - injection_rate;
   	 int buffer_size = queues[queue_number]->getBufferSize();
   	 if (buffer_size <= 0) {
  		  buffer_size = 1; 
   	 }
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
		if (injection_rates[queue_number] <= EPS) {
        		rho[queue_number] = 0.0;
        		n[queue_number] = 0.0;
       			 continue;
    		}

	    	rho[queue_number] = t_cap[queue_number] * lambda_a_cap[queue_number];
		if (rho[queue_number] >= 1.0 - EPS) {
        		rho[queue_number] = 1.0 - EPS;
    		}

   	n[queue_number] = rho[queue_number] * (rho[queue_number] - 1 + ca_square_cap[queue_number] + ca_square_cap[queue_number] * rho[queue_number]) /
		 (2 - 2 * rho[queue_number]) + rho[queue_number];

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
		    
               }
            }

            // Calculate waiting times before saturation
           

	for (int queue_number = 0; queue_number < queues.size(); ++queue_number) {

    	// Case 1: no traffic → only zero-load latency
   	 if (injection_rates[queue_number] <= EPS) {
        	queues[queue_number]->setWaitingTime(zero_load_latency);
        	continue;
    	 }

    	// Case 2: avoid division by zero
   	 if (lambda_a_cap[queue_number] <= EPS) {
        	queues[queue_number]->setWaitingTime(zero_load_latency);
        	continue;
    	 }
    	double wt = n[queue_number] / lambda_a_cap[queue_number] - t_cap[queue_number];
    	wt += zero_load_latency;

    	// Case 3: protect against NaN / Inf / negative
   	 if (std::isnan(wt) || std::isinf(wt) || wt < 0.0) {
        	wt = zero_load_latency;
    	 }

   	 queues[queue_number]->setWaitingTime(wt);
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

        /*for(size_t index = 0;index < injection_rates.size() ; ++index){
                if(injection_rates[index] != 0){
                    t_cap[index] = 1/lambda_a_cap[index];
		    std::cout<<"t_cap: "<<t_cap[index]<<std::endl;
                }
        }*/

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
                    waiting_times[queue_number] = (2 * buffer_size - 3) * (buffer_size + (2 - buffer_size) * ca_square_cap[queue_number]) / 
			    (2 * lambda_a_cap[queue_number] * buffer_size) + t_cap[queue_number];

		    waiting_times[queue_number] = waiting_times[queue_number] + zero_load_latency ;

		    //queues[queue_number]->setWaitingTime(waiting_times[queue_number]);
		    if (std::isnan(waiting_times[queue_number]) || std::isinf(waiting_times[queue_number])){
			    queues[queue_number]->setWaitingTime(zero_load_latency);
	            }
		     if(waiting_times[queue_number] < 0.0)
                                waiting_times[queue_number] = 0.0;
                        queues[queue_number]->setWaitingTime(waiting_times[queue_number]);
                     if (injection_rates[queue_number] <= EPS ||  n[queue_number]  <= EPS) {
                    	  queues[queue_number]->setWaitingTime(zero_load_latency);
                          continue;
                     }

		    }
                }
        }
	//update_node_from_Queue(queues, mapping);

   // return waiting_times;
}
}
