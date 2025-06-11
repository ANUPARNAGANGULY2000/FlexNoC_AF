#include "SingleQueue.h"
#include <iostream>
#include "Mapping.h"
#include "getUtils.h"
#include "Primitive.h"
#include "updateProcess.h"
#include <vector>
#include "Junction.h"

//finding nodes connected to that queue
void finding_queue(std::shared_ptr<dot_lang::Queue> queue){
	
	dot_lang::Mapping mapping;
	std::string queue_name= getPrimitiveName(queue);
	std::string connected_node = getConnectedNode(queue_name);
	std::shared_ptr<dot_lang::Junc> node = mapping.node_data[connected_node]; //get address of the node which is connected to that queue
	if(node){
		std::shared_ptr<dot_lang::Primitive> primitive_in = node->getPrimitiveIn();
	        if(primitive_in->isServer()){// if this is server then we will get connected arbiter
	       		std::string server_name = getPrimitiveName(primitive_in);
			std::string connected_primitive = mapping.server_track[server_name];// taking which primitive is connected to that server
			std::shared_ptr<dot_lang::Primitive> primitive = mapping.primitive_map[connected_primitive];
               		if(primitive->isArbiter()){
                  	//check node_names to get which nodes is connected to that arbiter
				std::vector<std::string> nodes_list = mapping.node_names[connected_primitive];
				std::vector<shared_ptr<dot_lang::Queue>>queues;
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
		   		update_injection_process_after_saturation(queues,injection_rate);
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

//Single Queue Waiting Time calculation
double single_queue_waiting_time(double injection_rate, double service_time){
	std::cout<<"it's in the single queue"<<std::endl;
	double rho = injection_rate * service_time;
	double waiting_time = 0.0;
	waiting_time = 0.5*rho*(service_time - 1)/(1-rho);
	//cout<<"Injection_rate: "<<injection_rate<<" service_time : "<<service_time<<endl;
	//cout<<"Waiting time: "<<waiting_time<<endl;
return waiting_time;
}
