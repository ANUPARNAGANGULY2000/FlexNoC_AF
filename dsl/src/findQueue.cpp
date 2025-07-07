#include "findQueue.h"

#include "Primitive.h"
#include "Junction.h"
#include "getUtils.h"
#include "updateProcess.h"
#include "Mapping.h"
#include "Injector.h"

namespace dot_lang{
void finding_queue(std::shared_ptr<dot_lang::Queue> queue, Mapping& mapping){

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
	    }
}

}
