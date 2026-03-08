#include "PriorityModel.h"
#include "iostream"
#include "UpdateNodeQueue.h"

namespace model{
//Priority Arbitration
void priority_model(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double service_time, double zero_load_latency, dot_lang::Mapping& mapping){
	//getting service_time and zero_load_latency from the Priority arbiter
	//double service_time = PRarbiter->getServiceTime();
	//double zero_load_latency = PRarbiter->getZeroLoadLatency();
	// Initialization of intermediate parameters	
	
	std::vector<double> lambda;
	std::vector<double> lambda_a_cap(queues.size(),0.0);
	std::vector<double> Ca_square_cap(queues.size(),0.0);
	std::vector<double> t(queues.size(),service_time);
	std::vector<double> t_cap(queues.size(),service_time);
	std::vector<double> rho(queues.size(),0.0);
	std::vector<double> R(queues.size(),0.0);//residual time of each queue
	std::vector<double> rho_cap(queues.size(),0.0);
	std::vector<double> R_cap(queues.size(),0.0);
	std::vector<double> waiting_time(queues.size(),0.0);
	std::vector<int> Buffer_Size(queues.size(),0);
	std::vector<double> n(queues.size(),0.0);
	//taking injection rates from queues
        for(auto queue_index=0;queue_index<queues.size(); ++queue_index){
           double injection_rate = queues[queue_index]->getInjectionRate();
	   int buffer_size = queues[queue_index]->getBufferSize();
           lambda.push_back(injection_rate);
	   Buffer_Size.push_back(buffer_size);
        }
	
    //calculating total injection rate
    double total_utilization = 0.0, rate = 0.0;
    for(int queue_index=0; queue_index<queues.size(); ++queue_index){
    	rate = lambda[queue_index];
	total_utilization += rate ;
    }

    total_utilization = total_utilization * service_time;

    // calculating waiting time before saturation
   if(total_utilization < 0.998){
	   
   	//calculate utilization of each queue
        for(auto queue_index=0;queue_index<lambda.size(); ++queue_index){
           rho[queue_index]=lambda[queue_index] * t[queue_index];
	   
        }

        //calculate residual time of each queue
        for(int queue_index=0;queue_index<queues.size(); ++queue_index){
           //for higher priority class
            if(queue_index==0){
                R[0] = 0.5*rho[0]*(service_time-1);
            }
           //for lower priority class
            else{
                R[queue_index] = 0;
                for(int high_priority_queue_index=0; high_priority_queue_index<queue_index; ++high_priority_queue_index){
                   R[queue_index] += 0.5*rho[high_priority_queue_index]*(t[high_priority_queue_index]+1);
                }
                R[queue_index] = R[queue_index]+(0.5*rho[queue_index]*(t[queue_index] - 1));
              }
	    
        }

	//calculate the probability of blocking and modify service time
      for(auto queue_index=0;queue_index<queues.size(); ++queue_index){

      if(queue_index!=0){
        double P = 0.0, delta_t=0.0;
        double sum_rho=0.0, sum_lambda=0.0, sum_t = 0.0;
        for(auto high_priority_queue_index=0; high_priority_queue_index<queue_index; ++high_priority_queue_index){
           sum_rho += rho[high_priority_queue_index];
           sum_lambda += lambda[high_priority_queue_index];
           sum_t += t[high_priority_queue_index];
        }
        P = sum_rho + sum_lambda * R[queue_index];
        delta_t = sum_t * P/(1-P);
        t_cap[queue_index]=t[queue_index] + delta_t;

        //modified utilization
        rho_cap[queue_index]=lambda[queue_index]*t_cap[queue_index];

        //modified residual time
        R_cap[queue_index]=0.5*rho_cap[queue_index]*(t_cap[queue_index]-1);

        //modified waiting time
         waiting_time[queue_index]=R_cap[queue_index]/(1-rho_cap[queue_index]) + delta_t;

        //add zero load latency
        waiting_time[queue_index] = waiting_time[queue_index] + zero_load_latency;


//	waiting_time[queue_index]=R[queue_index]/(1-rho[0] - rho[queue_index]);
//	waiting_time[queue_index] = waiting_time[queue_index] + zero_load_latency;



        //set that waiting time to each queue
        queues[queue_index]->setWaitingTime(waiting_time[queue_index]);

        }

     else if(queue_index==0){
          //modified utilization
        rho_cap[queue_index]=lambda[queue_index]*t_cap[queue_index];

        //modified residual time
        R_cap[queue_index]=0.5*rho_cap[queue_index]*(t_cap[queue_index]-1);

        //modified waiting time
        waiting_time[queue_index]=R_cap[queue_index]/(1-rho_cap[queue_index]);


        //add zero load latency
        waiting_time[queue_index] = waiting_time[queue_index] + zero_load_latency;


        //set that waiting time to each queue
        queues[queue_index]->setWaitingTime(waiting_time[queue_index]);
	
        }
      }
  }
 // calculating waiting time after saturation
if(total_utilization >=0.998){


	 // effective injection rate of the lower priority class
     for(int priority_queue = 0; priority_queue < lambda.size(); ++priority_queue){
	 if(priority_queue == 0){
	 	rho[0]=lambda[0]*t_cap[0];
		lambda_a_cap[0] = 1.0/service_time * std::min(1.0,rho[0]);
		Ca_square_cap[0]=1.0 - lambda_a_cap[0];
		queues[priority_queue]->setInjectionRate(lambda_a_cap[0]);
		queues[priority_queue]->setCoeffInterArrivalTime(Ca_square_cap[0]);
		queues[priority_queue]->activeInjectionRateUpdateFlag();
		rho[0] = lambda_a_cap[0] * service_time;
		R[0] = 0.5 * rho[0] * (t_cap[0] - 1);
		waiting_time[0] = R[0] / (1 - rho[0] );
		waiting_time[0] = waiting_time[0] + zero_load_latency;
        	queues[priority_queue]->setWaitingTime(waiting_time[0]);
	 }
	 else{
		double total_rho = 0.0,temp=0.0;
		for(int high_priority_queue = 0; high_priority_queue  < priority_queue ; ++high_priority_queue){
		    //rho[high_priority_queue] = lambda_a_cap[high_priority_queue] * t_cap[high_priority_queue];
		    rho[high_priority_queue] = lambda_a_cap[high_priority_queue] * t[high_priority_queue];
         	    total_rho += rho[high_priority_queue];

		}
		temp = 1.0/service_time * total_rho;
        	lambda_a_cap[priority_queue] = std::min(lambda[priority_queue],(1.0-temp));
		queues[priority_queue]->setInjectionRate(lambda_a_cap[priority_queue]);
		double p_full = 1 - lambda_a_cap[priority_queue]/lambda[priority_queue];
		Ca_square_cap[priority_queue] = (1-p_full)*(1 - lambda_a_cap[priority_queue]);
		queues[priority_queue]->setCoeffInterArrivalTime(Ca_square_cap[priority_queue]);
		queues[priority_queue]->activeInjectionRateUpdateFlag();
		double X = 1.0 / Buffer_Size[priority_queue];
		n[priority_queue] = Ca_square_cap[priority_queue] / X + 1.0;
		waiting_time[priority_queue] = n[priority_queue] / lambda_a_cap[priority_queue] - service_time;
		

		waiting_time[priority_queue] = waiting_time[priority_queue] + zero_load_latency;
		queues[priority_queue]->setWaitingTime(waiting_time[priority_queue]);
 	}
    }
     //update_node_from_Queue(queues, mapping);
  }
}
}
