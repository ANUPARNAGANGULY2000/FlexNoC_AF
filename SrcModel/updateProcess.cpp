#include "updateProcess.h"
#include "Mapping.h"
#include "Primitive.h"
#include "setNetworkPrimitives.h"
#include "getUtils.h"
#include "SingleQueue.h"
#include "RoundRobin.h"
#include "Injector.h"
#include "Priority.h"
#include "Hybrid.h"
#include "findQueue.h"
#include <cmath>
//using dot_lang namespace;
namespace model{

void server_to_arbiter_track(std::shared_ptr<dot_lang::Server> server, dot_lang::Mapping& mapping){

	std::string server_string = getPrimitiveName(server,mapping);
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
					finding_queue(queue, mapping);	
				}
			}
                  }
         }
}


void update_arbiter_service_process(std::shared_ptr<dot_lang::Server> server_primitive, double t_cap, double Cs_square_cap, dot_lang::Mapping& mapping){
	std::string server;
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
	     else if(primitive->isHybridArbiter()){
	     
		     std::shared_ptr<dot_lang::HybridArbiter> arbiter = std::dynamic_pointer_cast<dot_lang::HybridArbiter>(primitive);
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
					set_network_primitive(primitive_out_node, mapping);
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
				 //if split primitive is connected to the Queue
				 else if(primitive_in_node->isSplit() && primitive_out_node->isQueue()){
			         
					std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(primitive_in_node);
                      		        std::map<std::string, double >SplitProbabilityMap = split->getSplitProbability();

                        		//first take string of corresponding primitive
                        		std::string split_primitive = getPrimitiveName(primitive_in_node, mapping);
					std::string node_connected_with_split = getConnectedNode(split_primitive,mapping);
					
                        		double total_injection_rate = 0.0;
                        		//get the connected nodes with this split
                        		std::vector<std::string> nodes_list = mapping.node_names[split_primitive];
                        		//now we have to get the queues from that nodes
                        		for(const auto& node:nodes_list){

                                		std::shared_ptr<dot_lang::Junc> junction_address = mapping.node_data[node];
                                		if(junction_address){

                                       		 std::shared_ptr<dot_lang::Primitive> primitive = junction_address->getPrimitiveOut();
                                        	 if(primitive->isQueue()){
                                                	std::string queue_name = getPrimitiveName(primitive, mapping);
                                                        std::shared_ptr<dot_lang::Queue> queue_address = std::dynamic_pointer_cast<dot_lang::Queue>(primitive);
                                                	double injection_rate = queue_address -> getInjectionRate();
                                               		 total_injection_rate += injection_rate;
                                                  }   
                                               } 
                                       }
                      			//set this total injection_rate to split
                        		split->setInjectionRate(total_injection_rate);
					double coeff_var = 1-total_injection_rate;
                        		split->setCoeffInterArrivalTime(coeff_var);
					
					//now we have to again get the prev node
                                        std::shared_ptr<dot_lang::Junc> Prev_to_Prev_node = mapping.node_data[node_connected_with_split];
                                        Prev_to_Prev_node->setInjectionRate(total_injection_rate);
                                        Prev_to_Prev_node->setCoeffInterArrivalTime(coeff_var);
					std::shared_ptr<dot_lang::Primitive> Prev_Primitive_in = Prev_to_Prev_node->getPrimitiveIn();
					std::shared_ptr<dot_lang::Primitive> Prev_Primitive_out = Prev_to_Prev_node->getPrimitiveOut();
			
					if(Prev_Primitive_in->isServer() && Prev_Primitive_out->isSplit()){
					
						std::shared_ptr<dot_lang::Server> serverPtr = std::dynamic_pointer_cast<dot_lang::Server>(Prev_Primitive_in);
						std::shared_ptr<dot_lang::Split> splitPtr = std::dynamic_pointer_cast<dot_lang::Split>(Prev_Primitive_out);
						
						//call the function to update the service time
						update_server_connected_to_Split(serverPtr,splitPtr, mapping);	
					}


				}
	                } 
	               }
                }
           }
   else if(primitive->isQueue()){}
}

void update_server_connected_to_Split(std::shared_ptr<dot_lang::Server> server, std::shared_ptr<dot_lang::Split> split, dot_lang::Mapping& mapping){

	double service_time = server->getServiceTime();
	double cs_square_cap = server->getCoeffServiceTime();
	double injection_rate = split->getInjectionRate();
	double rho = service_time * injection_rate;
	double serviceTime = 0.0;
        std::shared_ptr<dot_lang::Primitive> split_primitive_ptr = std::dynamic_pointer_cast<dot_lang::Primitive>(split);
	double p_full_cap = 0.0, t_cap=0.0;
	if(rho<=0.998){
	 std::map<std::string, double >SplitProbabilityMap = split->getSplitProbability();
	 //first take string of corresponding primitive
         std::string split_primitive = getPrimitiveName(split_primitive_ptr, mapping);
	 //get the connected nodes with this split
         std::vector<std::string> nodes_list = mapping.node_names[split_primitive];
	 //now we have to get the queues from that nodes
         for(const auto& node:nodes_list){

                std::shared_ptr<dot_lang::Junc> junction_address = mapping.node_data[node];
                if(junction_address){
			std::shared_ptr<dot_lang::Primitive> primitive = junction_address->getPrimitiveOut();
                        if(primitive->isQueue()){
				 std::string queue_name = getPrimitiveName(primitive, mapping);
                                 auto buffer_details = SplitProbabilityMap.find(queue_name);
                                 double probability = 0.0;
                                 if(buffer_details != SplitProbabilityMap.end()){
                                         probability = buffer_details->second;//get the split probability of that queue
                                 }
                                std::shared_ptr<dot_lang::Queue> queue_address = std::dynamic_pointer_cast<dot_lang::Queue>(primitive);
				std::shared_ptr<dot_lang::Junc> nextJunc = getNextJunction(junction_address, mapping);
				std::shared_ptr<dot_lang::Primitive> nextJuncPrimitiveOut = nextJunc->getPrimitiveOut();
				if(nextJuncPrimitiveOut->isArbiter()){
				
					std::shared_ptr<dot_lang::Arbiter> arbiter = std::dynamic_pointer_cast<dot_lang::Arbiter>(nextJuncPrimitiveOut);
					serviceTime = arbiter->getServiceTime();
				}
                                 double Probability_Q_full = probability_of_Queue_full(queue_address, serviceTime);
                                 p_full_cap += Probability_Q_full * probability;
                         }
                }
         }
	 //Modified service process
         if(p_full_cap<1.0){
             t_cap = service_time / (1 - p_full_cap);
	 }
        }
       else if(rho>=0.998){
             t_cap = service_time;
             p_full_cap = 1.0;
       }
       cs_square_cap = p_full_cap + cs_square_cap*(1 - p_full_cap);
       server->setServiceTime(t_cap);
       server->setCoeffServiceTime(cs_square_cap);
//now check the prev node and check their in and out. in will be server and out will be queue then send it to set_primitive
       std::shared_ptr<dot_lang::Primitive> server_primitive = std::dynamic_pointer_cast<dot_lang::Primitive>(server);
       std::string server_string = getPrimitiveName(server_primitive, mapping);
       std::string junction_string = getConnectedNode(server_string,mapping);
       std::shared_ptr<dot_lang::Junc> junction_string_address = mapping.node_data[junction_string];
       //now we have to get the prev junction
       std::shared_ptr<dot_lang::Junc> Prev_junction = getPrevJunction(junction_string_address, mapping);
       std::shared_ptr<dot_lang::Primitive> Primitive_in = Prev_junction ->getPrimitiveIn();
       std::shared_ptr<dot_lang::Primitive> Primitive_out = Prev_junction -> getPrimitiveOut();
       if(Primitive_in->isServer() && Primitive_out->isQueue()){
       
		 set_network_primitive(Primitive_out, mapping);
       }

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
                    sum_p_j += rho[l] * rho[l] * std::pow(pow_val, k + 1) / (n[l] - rho[l]);
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

double probability_of_Queue_full(std::shared_ptr<dot_lang::Queue>queue, double t_cap){

	double injection_rate = queue->getInjectionRate();
	double Ca_square = queue->getCoeffInterArrivalTime();
	int buffer_size = queue->getBufferSize();
	double rho = 0.0;
	double avg_occupancy = 0.0;
	double p_full = 0.0;
	double sum_p_j = 0.0;
	 
	rho = t_cap * injection_rate;

	//average occupancy calculation
	avg_occupancy = rho * (rho - 1 + Ca_square + Ca_square * rho) / (2 - 2 * rho) + rho;

	//probability of full queue using maximum entropy
	for(int packet=0; packet < buffer_size; ++packet){
	
		double pow_val = (avg_occupancy - rho) / avg_occupancy;
		sum_p_j += rho * rho * std::pow(pow_val, packet+1) / (avg_occupancy - rho);
	}
	p_full = rho - sum_p_j;

	return p_full;
}


void update_injection_process_after_saturation(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, double updated_injection_rate, dot_lang::Mapping& mapping){

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
	finding_queue(queues[queue_index], mapping);
   }
   
}

//update service process
std::shared_ptr<double[]> update_service_process(double lambda_a_sink,double ca_square_sink,double service_time, double cs_square_sink, int buffer_size, dot_lang::Mapping& mapping){

	double n_sink=0.0, pi_sink=0.0,rho_sink=0.0,sum_p_sink=0.0;
        double t_cap =0.0,cs_square_cap=0.0;
//	std::shared_ptr<double> service_process = std::make_shared<double>();
	std::shared_ptr<double[]> service_process(new double[2], std::default_delete<double[]>());

	std::vector<double> p_sink(buffer_size,0.0);
        rho_sink = lambda_a_sink * service_time;

	if(rho_sink<=0.998){
     		   //The average occupancy of Q_sink
        	n_sink = rho_sink*(rho_sink - 1 + ca_square_sink + rho_sink*ca_square_sink)/(2-2*rho_sink)+rho_sink;

       		// occupancy equation from WRR paper
          	//n_sink = (rho_sink*(rho_sink - 1 + ca_square_sink)/(2-2*rho_sink)) + (rho_sink*rho_sink*cs_square_sink)/(2-2*rho_sink)+rho_sink;
        	//the probability that Q_sink contains k packets
        	for(int k=0; k<buffer_size; ++k){
               		double pow_val = (n_sink - rho_sink)/n_sink;
              		 p_sink[k] = (rho_sink * rho_sink)/(n_sink - rho_sink) * std::pow(pow_val,k+1);
			//p_sink[k]=(1-rho_sink)*pow(rho_sink,k);
			sum_p_sink = sum_p_sink + p_sink[k];
        	}
       		 //probability  that Qsink is full
        	 pi_sink = rho_sink - sum_p_sink;
		 

                //Modified service process
   		if(pi_sink<1.0){
        	       t_cap = service_time / (1 - pi_sink);
         	}
	}
       else if(rho_sink>=0.998){
	     t_cap = service_time;
	     pi_sink = 1.0;
	}
       
        cs_square_sink = pi_sink + cs_square_sink*(1 - pi_sink);
        service_process.get()[0]=t_cap;
	service_process.get()[1]=cs_square_sink;
return service_process;
}
}
