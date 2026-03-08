#include "findQueue.h"

#include "Primitive.h"
#include "Junction.h"
#include "getUtils.h"
#include "updateProcess.h"
#include "Mapping.h"
#include "Injector.h"

namespace model{
void finding_queue(std::shared_ptr<dot_lang::Queue> queue, dot_lang::Mapping& mapping){

	std::string queue_name = getPrimitiveName(queue,mapping);
	std::string connected_node = getConnectedNode(queue_name, mapping);
	std::shared_ptr<dot_lang::Junc> node = mapping.node_data[connected_node]; //get address of the node which is connected to that queue
	if(node){
		std::shared_ptr<dot_lang::Primitive> primitive_in = node->getPrimitiveIn();
	        if(primitive_in->isServer()){// if this is server then we will get connected arbiter
	       		std::string server_name = getPrimitiveName(primitive_in, mapping);
			std::string connected_primitive = mapping.server_track[server_name];// taking which primitive is connected to that server
			std::shared_ptr<dot_lang::Primitive> primitive = mapping.primitive_map[connected_primitive];
               		if(primitive->isArbiter()){
                  	//check node_names to get which nodes is connected to that arbiter
				std::vector<std::string> nodes_list = mapping.node_names[connected_primitive];
				std::vector<std::shared_ptr<dot_lang::Queue>>queues;
      		   		//taking list of the nodes connected to that arbiter
      		   		for(const auto& node_name:nodes_list) {
       			 		std::shared_ptr<dot_lang::Junc> it_node = mapping.node_data[node_name];
        		 		if(it_node){
						std::shared_ptr<dot_lang::Primitive> primitive = it_node->getPrimitiveIn();
						if(primitive->isQueue()){
							std::shared_ptr<dot_lang::Queue> queue_address = std::dynamic_pointer_cast<dot_lang::Queue>(primitive);
				   			queues.push_back(queue_address);
						}
                          		}
                   		}
		   		double injection_rate = queue->getInjectionRate();
		   		update_injection_process_after_saturation(queues,injection_rate, mapping);
                	}
	     	}
	        else if(primitive_in->isInjector()){
	    		double injection_rate = queue->getInjectionRate();
			double coeff_inter_arrival_time = queue->getCoeffInterArrivalTime();
			std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(primitive_in);
			injector->setInjectionRate(injection_rate);
			injector->setCoeffInterArrivalTime(coeff_inter_arrival_time);
	        }

		//queue can also be connected to split
		else if(primitive_in ->isSplit()){
		 
			std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(primitive_in);
			std::map<std::string, double >SplitProbabilityMap = split->getSplitProbability();

			//first take string of corresponding primitive
			std::string split_primitive = getPrimitiveName(primitive_in, mapping);
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
						auto buffer_details = SplitProbabilityMap.find(queue_name);
						double probability = 0.0;
						 if(buffer_details != SplitProbabilityMap.end()){
							 probability = buffer_details->second;//get the split probability of that queue
						 }
						std::shared_ptr<dot_lang::Queue> queue_address = std::dynamic_pointer_cast<dot_lang::Queue>(primitive);
						double injection_rate = queue_address -> getInjectionRate();
						total_injection_rate += injection_rate*probability;
					}
				}
			}	
		      //set this total injection_rate to split
			split->setInjectionRate(total_injection_rate);
			double coeff_var = 1-total_injection_rate;
		        split->setCoeffInterArrivalTime(coeff_var);
		       //now we have to again get the prev node
                        std::shared_ptr<dot_lang::Junc> Prev_to_Prev_node = getPrevJunction(node, mapping);
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
