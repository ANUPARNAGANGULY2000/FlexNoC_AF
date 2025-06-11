#include<updateProcess.h>
#include<Mapping.h>
#include<Primitive.h>
#include<setNetworkPrimitives.h>
#include<getUtils.h>
#include<SingleQueue.h>
//using dot_lang namespace;

void server_to_arbiter_track(std::shared_ptr<dot_lang::Server> server){
	dot_lang::Mapping mapping;
	std::string server_string = getPrimitiveName(server);
        //check which primitive(arbiter) is connected to that server
	std::string connected_primitive = mapping.server_track[server_string];
        std::shared_ptr<dot_lang::Primitive> primitive = mapping.primitive_map[connected_primitive];
        if(primitive->isArbiter()){
          	//check node_names to get which nodes is connected to that arbiter
		std::vector<std::string> nodes_list = mapping.node_names[connected_primitive];
		std::vector<std::shared_ptr<dot_lang::Junc>>nodes;
		std::vector<std::shared_ptr<dot_lang::Queue>>queues;
      		//taking list of the nodes connected to that arbiter
     		 for(const auto& node_name:nodes_list) {
        		auto node = mapping.node_data[node_name];
			std::shared_ptr<dot_lang::Primitive> primitive_in = node->getPrimitiveIn();
			if(primitive_in->isQueue()){
				std::shared_ptr<dot_lang::Queue> queue= std::dynamic_pointer_cast<dot_lang::Queue>(primitive_in);
				if(queue->isInjectionRateUpdated()){
					finding_queue(queue);	
				}
			}
                  }
         }
}


void update_arbiter_service_process(std::shared_ptr<dot_lang::Server> server_primitive, double t_cap, double Cs_square_cap){
	std::string server;
	dot_lang::Mapping mapping;
	for(auto it=mapping.primitive_map.begin(); it!=mapping.primitive_map.end(); ++it){
		if(it->second==server_primitive){
			server = it->first;
     	 	}
 	}

	//check which arbiter is connected to that server
	std::string connected_primitive = mapping.server_track[server];
	std::shared_ptr<dot_lang::Primitive> primitive = mapping.primitive_map[connected_primitive];
	if(primitive->isArbiter()){
             if(primitive->isRRarbiter()){
  			std::shared_ptr<dot_lang::RoundRobinArbiter> arbiter = std::dynamic_pointer_cast<dot_lang::RoundRobinArbiter>(primitive);
	       		//update the service process of the RoundRobin arbiter
 	        	arbiter->setServiceTime(t_cap);
	        	arbiter->setCoeffServiceTime(Cs_square_cap);
              } 
  	       else if(primitive->isPRarbiter()){
  			std::shared_ptr<dot_lang::PriorityArbiter> arbiter = std::dynamic_pointer_cast<dot_lang::PriorityArbiter>(primitive);
  			//update the service_process od the Priority arbiter
 		 	arbiter->setServiceTime(t_cap);
 		 	arbiter->setCoeffServiceTime(Cs_square_cap);
  	       }
		  //check node_names to get which nodes is connected to that arbiter
	       std::vector<std::string> nodes_list = mapping.node_names[connected_primitive];
	       std::vector<std::shared_ptr<dot_lang::Junc>>nodes;
	       std::vector<std::shared_ptr<dot_lang::Queue>>queues;
	       std::vector<double> injection_rate_list;
	       std::vector<double>Ca_square_list;
	       std::vector<int>Buffer_size_list;
      	       double injection_rate=0.0, Ca_square=0.0;
      	       int buffer_size = 0;
               //taking list of the nodes connected to that arbiter
               for(const auto& node_name:nodes_list) {	
			auto it_node = mapping.node_data.find(node_name);
			if(it_node!=mapping.node_data.end()){
	    			nodes.push_back(it_node->second);
	    		}
         	} 

       		//taking list of the queues connected to that arbiter
 		for(const auto& node:nodes){
			std::shared_ptr<dot_lang::Primitive> primitive_in=node->getPrimitiveIn();
	   		if(primitive_in->isQueue()){
				std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_in);
	   			injection_rate = queue->getInjectionRate();
	   			Ca_square = queue->getCoeffInterArrivalTime();
	   			buffer_size = queue->getBufferSize();
	  		        queues.push_back(queue);
	   			injection_rate_list.push_back(injection_rate);
	   			Ca_square_list.push_back(Ca_square);
	  			 Buffer_size_list.push_back(buffer_size);	
	  		}

		}
		update_injection_process(injection_rate_list, Ca_square_list, t_cap, Buffer_size_list, queues, nodes);
 		//check the node_files
 		for(const auto& node_name:nodes){
 	    		for(auto it=mapping.node_files.begin(); it!=mapping.node_files.end(); ++it){
			if(it->second == node_name){
				std::shared_ptr<dot_lang::Junc> node_prev = it->first;
	            		injection_rate = node_name->getInjectionRate();
	            		Ca_square = node_name->getCoeffInterArrivalTime();
		   		node_prev->setInjectionRate(injection_rate);
	            		node_prev->setCoeffInterArrivalTime(Ca_square);
				std::shared_ptr<dot_lang::Primitive> primitive_in_node = node_prev->getPrimitiveIn();
				std::shared_ptr<dot_lang::Primitive> primitive_out_node = node_prev->getPrimitiveOut();
		    		//if server is connected to the Queue
	       	    		if(primitive_in_node->isServer() && primitive_out_node->isQueue()){
					set_network_primitive(primitive_out_node);
	             		}

	          		//if Injector is connected to the Queue
	         	  else if(primitive_in_node->isInjector() && primitive_out_node->isQueue()){
				  std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(primitive_in_node);
		    		  double updated_injection_rate=0.0, updated_Ca_square =0.0;
		    		   updated_injection_rate = node_prev->getInjectionRate();
		    		   updated_Ca_square = node_prev->getCoeffInterArrivalTime();
		    		   injector->setInjectionRate(updated_injection_rate);
		    		   injector->setCoeffInterArrivalTime(updated_Ca_square);
     	                   }
	                } 
	               }
                }
           }
   else if(primitive->isQueue()){}
}

void update_injection_process(std::vector<double> lambda_a, std::vector<double> Ca_square, double t_cap, std::vector<int>BUFFER_SIZE, std::vector<std::shared_ptr<dot_lang::Queue>>& queues, std::vector<std::shared_ptr<dot_lang::Junc>>& nodes){

	std::vector<double> lambda_a_cap = lambda_a;
	std::vector<double> Ca_square_cap = Ca_square;
	std::vector<double> rho(lambda_a.size(), 0.0);
	std::vector<double> n(lambda_a.size(), 0.0);
	std::vector<double> pi_j(lambda_a.size(), 0.0);

     for (size_t l = 0; l < lambda_a.size(); ++l) {
            rho[l] = t_cap * lambda_a[l];
            // Average occupancy calculation
            n[l] = rho[l] * (rho[l] - 1 + Ca_square_cap[l] + Ca_square_cap[l] * rho[l]) / (2 - 2 * rho[l]) + rho[l];

            // Probability of full queue using maximum entropy
                double sum_p_j = 0.0;
                for (int k = 0; k < BUFFER_SIZE[l]; ++k) {
                    double pow_val = (n[l] - rho[l]) / n[l];
                    sum_p_j += rho[l] * rho[l] * pow(pow_val, k + 1) / (n[l] - rho[l]);
                }
                pi_j[l] = rho[l] - sum_p_j;
            // Update lambda_a_cap and Ca_square_cap based on pi_j
            lambda_a_cap[l] =lambda_a[l]* (1 - pi_j[l]);
            Ca_square_cap[l] = Ca_square_cap[l] * (1 - pi_j[l]) + pi_j[l];
	    queues[l]->setInjectionRate(lambda_a_cap[l]);
	    queues[l]->setCoeffInterArrivalTime(Ca_square_cap[l]);
	    nodes[l]->setInjectionRate(lambda_a_cap[l]);
	    nodes[l]->setCoeffInterArrivalTime(Ca_square_cap[l]);
        }
}

void update_injection_process_after_saturation(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double updated_injection_rate){

	double sum_of_injection_rate = 0.0;
   		//calculating total injection_rate
   	for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
        	double injection_rate_of_queue = queues[queue_index]->getInjectionRate();
		sum_of_injection_rate += injection_rate_of_queue;
   	}

   //getting proportion of updated_injection_rate and set it to each queue
   for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
   	double injection_rate_of_queue = queues[queue_index]->getInjectionRate();
	double update_injection_rate_of_queue = (injection_rate_of_queue/sum_of_injection_rate) * updated_injection_rate;
	double update_coeff_inter_arrival_time_of_queue = 1 - update_injection_rate_of_queue;
	queues[queue_index]->setInjectionRate(update_injection_rate_of_queue);
	queues[queue_index]->setCoeffInterArrivalTime(update_coeff_inter_arrival_time_of_queue);
	queues[queue_index]->activeInjectionRateUpdateFlag();
	finding_queue(queues[queue_index]);
   }
   
}

//update service process
std::shared_ptr<double> update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size){

	double n_sink=0.0, pi_sink=0.0,rho_sink=0.0,sum_p_sink=0.0;
        double t_cap =0.0,cs_square_cap=0.0;
	std::shared_ptr<double> service_process = (double*)malloc(2*sizeof(double));
	std::vector<double> p_sink(buffer_size,0.0);
	std::cout<<"injection_rate: "<<lambda_a_sink<<" Ca_square_sink: "<<ca_square_sink<<std::endl;
	std::cout<<"service_time: "<<service_time<<" cs_square_sink: "<<cs_square_sink<<" buffer_size: "<<buffer_size<<std::endl;
        rho_sink = lambda_a_sink * service_time;

	if(rho_sink<=0.998){
     		   //The average occupancy of Q_sink
        	n_sink = rho_sink*(rho_sink - 1 + ca_square_sink + rho_sink*ca_square_sink)/(2-2*rho_sink)+rho_sink;

       		// occupancy equation from WRR paper
          	//n_sink = (rho_sink*(rho_sink - 1 + ca_square_sink)/(2-2*rho_sink)) + (rho_sink*rho_sink*cs_square_sink)/(2-2*rho_sink)+rho_sink;
        	//the probability that Q_sink contains k packets
        	for(int k=0; k<buffer_size; ++k){
               		double pow_val = (n_sink - rho_sink)/n_sink;
              		 p_sink[k] = (rho_sink * rho_sink)/(n_sink - rho_sink) * pow(pow_val,k+1);
			//p_sink[k]=(1-rho_sink)*pow(rho_sink,k);
			sum_p_sink = sum_p_sink + p_sink[k];
        	}
       		 //probability  that Qsink is full
        	 pi_sink = rho_sink - sum_p_sink;
		 std::cout<<"rho_sink: "<<rho_sink<<" sum_p_sink "<<sum_p_sink<<"pi_sink: "<<pi_sink<<std::endl;

                //Modified service process
   		if(pi_sink<1.0){
        	       t_cap = service_time / (1 - pi_sink);
         	}
	}
       else if(rho_sink>=0.998){
	     t_cap = service_time;
	     pi_sink = 1.0;
	}
       std::cout<<"previous service time was: "<<service_time<<std::endl;
       std::cout<<"updated service time is : "<<t_cap<<std::endl;
        cs_square_sink = pi_sink + cs_square_sink*(1 - pi_sink);
        service_process[0]=t_cap;
	service_process[1]=cs_square_sink;
return service_process;
}
