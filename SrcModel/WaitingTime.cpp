#include<WaitingTime.h>
#include<Injector.h>
#include<Queue.h>
#include<iostream>
#include<memory>
#include<Mapping.h>
#include<Split.h>
#include <cmath>
namespace model{

void waiting_time_calc(dot_lang::Mapping& mapping){
    
	//iterate over the map to calculate waiting time of each injector
    for(auto it = mapping.queue_flow.cbegin(); it != mapping.queue_flow.cend(); ++it)
    {
	    std::shared_ptr<dot_lang::Injector> injector =it->first;
	    double probability = 1.0;
        //for every queue in the flow of the injector
        for(std::shared_ptr<dot_lang::Queue> queue: it->second){
		std::shared_ptr<dot_lang::Primitive> primitive_inj = std::dynamic_pointer_cast<dot_lang::Injector>(injector);
		 std::shared_ptr<dot_lang::Primitive> primitive_queue = std::dynamic_pointer_cast<dot_lang::Queue>(queue);

		for(auto itr = mapping.primitive_map.begin(); itr!=mapping.primitive_map.end(); itr++){
			
			if(itr->second == primitive_queue){
				 for(auto node = mapping.node_connections.begin(); node != mapping.node_connections.end(); ++node){
					if(node->second == itr->first){
						std::shared_ptr<dot_lang::Junc> prev_node = mapping.node_data[node->first];
						if(prev_node){
							 std::shared_ptr<dot_lang::Primitive> primitive_in = prev_node ->getPrimitiveIn();
				 			 if(primitive_in){
							 	if(primitive_in -> isSplit()){
									std::shared_ptr<dot_lang::Split> split = 
										std::dynamic_pointer_cast<dot_lang::Split>(primitive_in);
            									
            									std::map<std::string, double >SplitProbabilityMap = 
											split->getSplitProbability();
            										
            										auto directional_buffer = SplitProbabilityMap.find(itr->first);
           										 if(directional_buffer != SplitProbabilityMap.end()){

                    									  probability = directional_buffer->second;
                    
											  double queueWaitingTime =  queue -> getWaitingTime();

											  double new_split_waiting_time = queueWaitingTime * probability;
                    		
											 }

								}
							 }			 
						}	
					}
			  
				 }


                        }

		}
		if(std::isnan(queue->getWaitingTime()) || std::isinf(queue->getWaitingTime())){
			double queue_wait = 0.0;
		 	queue->setWaitingTime(queue_wait);
		}
		if(std::isnan(injector->getWaitingTime()) || std::isinf(injector->getWaitingTime())){
                        double injector_wait = 0.0;
                        injector->setWaitingTime(injector_wait);
                }

            double new_waiting_time= injector->getWaitingTime() + queue->getWaitingTime() * probability;
            injector->setWaitingTime(new_waiting_time);
	   

        }
	   
    }
}
}
