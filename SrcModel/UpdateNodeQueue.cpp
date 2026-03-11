#include<UpdateNodeQueue.h>
#include<MakeConnection.h>
#include<Mapping.h>
#include<Split.h>

namespace model{
//update node from queue
void update_node_from_Queue(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, dot_lang::Mapping& mapping){


	std::vector<std::string> queue_string;//to get Queue_string of the corresponding queue address

    	for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
    
		for(auto primitive=mapping.primitive_map.begin(); primitive!=mapping.primitive_map.end(); ++primitive){
	
		    	if(primitive->second == queues[queue_index]){
	
				queue_string.push_back(primitive->first);
           
			}

	
		}

    }

   
       	std::vector<std::shared_ptr<dot_lang::Junc>> nodes;
  
       	for(auto queue_index=0; queue_index!=queues.size(); ++queue_index){

     		std::string node_name = mapping.node_connections[queue_string[queue_index]];//node which is connected to the queue

     		std::shared_ptr<dot_lang::Junc> node_address = mapping.node_data[node_name];//address of the node
     
	    	if(node_address){
       	
			double injection_rate = queues[queue_index]->getInjectionRate();
		
			double coeff_inter_arrival_time = queues[queue_index]->getCoeffInterArrivalTime();
	        
			node_address->setInjectionRate(injection_rate);
		
			node_address->setCoeffInterArrivalTime(coeff_inter_arrival_time);
		
			nodes.push_back(node_address);
       
	       	}


   }


 
      	node_update_forward(nodes, mapping);
}


//update node's values in forward directions
void node_update_forward(std::vector<std::shared_ptr<dot_lang::Junc>>& nodes, dot_lang::Mapping& mapping){


	//check is there single node or multiple node
	int node_size = nodes.size();
	std::vector<std::shared_ptr<dot_lang::Junc>> connected_node;

	//if there is single node then update previous  node's value to next
	if(node_size == 1){
		std::shared_ptr<dot_lang::Junc> prev_node = nodes[0];
		std::shared_ptr<dot_lang::Junc> next_node = mapping.node_files[prev_node];

      		if(next_node){

	  		double injection_rate = prev_node ->getInjectionRate();
	  
		    	double coeff_interarrival_time = prev_node -> getCoeffInterArrivalTime();
	     
		       	next_node ->setInjectionRate(injection_rate);
	   
		     	next_node ->setCoeffInterArrivalTime(coeff_interarrival_time);
	     
		       	std::shared_ptr<dot_lang::Primitive> primitive_out = next_node->getPrimitiveOut();
	      
			std::shared_ptr<dot_lang::Primitive> primitive_in = next_node->getPrimitiveIn();
              
		       	if(!primitive_in->isSplit() && primitive_out->isQueue()){


	 			std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
         

				queue->setInjectionRate(injection_rate);
             
      		       
				queue->setCoeffInterArrivalTime(coeff_interarrival_time);
               
			}


	      
		       	if(primitive_out->isSplit()){


      		      
			       	std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(primitive_out);
      
    		       
				split->setInjectionRate(injection_rate);
    
  
	 			split->setCoeffInterArrivalTime(coeff_interarrival_time);
	 
		  	}
	      
		       	if(primitive_in->isSplit()){

       		       
				std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(primitive_in);
       		
	       	       
				double total_injection_rate = split -> getInjectionRate();
	

	 			std::map<std::string, double>SplitProbabilityMap = split->getSplitProbability();

	
		 		for(auto queue=SplitProbabilityMap.begin(); queue != SplitProbabilityMap.end(); ++queue){

 		
			 		auto  queuePointer = mapping.primitive_map.find(queue->first);

 			 
				  	if(queuePointer != mapping.primitive_map.end()){

       				  
					   	std::shared_ptr<dot_lang::Primitive> ptr = queuePointer -> second;

       				       
						std::shared_ptr<dot_lang::Queue> queuePtr = std::dynamic_pointer_cast<dot_lang::Queue>(ptr);

       				       
						double probability = queue->second;

       				       
						double new_injection_rate = total_injection_rate * probability;
 
       				      
					       	double coeff_var = 1 - new_injection_rate;

       				       
						queuePtr -> setInjectionRate(new_injection_rate);

       				       
						queuePtr -> setCoeffInterArrivalTime(coeff_var);


			      
					}
		       
		       
				}

	       
			} 

	     
		       	connected_node.push_back(next_node);
	      
			node_update_forward(connected_node, mapping);
	  }
	}

	//if there is multiple nodes then merge it and update that to next node.
	else if(node_size > 1){
		
		std::vector<double> injection_rates;
		
		std::vector<double> coeff_inter_arrival_times;
	
	     	for(auto node_index=0; node_index<nodes.size(); ++node_index){
	
	     		std::shared_ptr<dot_lang::Junc> node_address = nodes[node_index];
	     
		       	double injectionRate = node_address->getInjectionRate();
	      
			double coeffInterArrivalTime = node_address->getCoeffInterArrivalTime();
	      
			injection_rates.push_back(injectionRate);
	      
			coeff_inter_arrival_times.push_back(coeffInterArrivalTime);
	   
		}
	
	      	std::vector<double> merged_flows = dot_lang::MakeConnection::Merging_flow(injection_rates, coeff_inter_arrival_times);
           
	  
	       	double avg_injection_rate = merged_flows[0];

       		double avg_coeff_inter_arrival_time = merged_flows[1];

       		std::shared_ptr<dot_lang::Junc> prev_node = nodes[0];// as both nodes destination is same so we are taking only one node

       		std::shared_ptr<dot_lang::Junc> next_node = mapping.node_files[prev_node];

       		next_node -> setInjectionRate(avg_injection_rate);

       		next_node -> setCoeffInterArrivalTime(avg_coeff_inter_arrival_time);

       		std::shared_ptr<dot_lang::Primitive> primitive_out = next_node->getPrimitiveOut();

       		if(primitive_out->isQueue()){

       			std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);

	   		queue->setInjectionRate(avg_injection_rate);
	   
		      	queue->setCoeffInterArrivalTime(avg_coeff_inter_arrival_time);
	 
		}
	
	       	connected_node.push_back(next_node);
	
	       	node_update_forward(connected_node,mapping);
	
	}

}

void update_connected_node(std::string Injector, dot_lang::Mapping& mapping, double Injection_rate){
	
	double coeff_var = 1-Injection_rate;
	
	std::string node = mapping.node_connections[Injector];
	
	std::shared_ptr<dot_lang::Junc> node_ptr = mapping.node_data[node];
	
	if(node_ptr){
	
		node_ptr->setInjectionRate(Injection_rate);
	
		node_ptr->setCoeffInterArrivalTime(coeff_var);
	
		std::shared_ptr<dot_lang::Junc> connected_node_to_node = mapping.node_files[node_ptr];
	
		std::shared_ptr<dot_lang::Primitive> Primitive_in = connected_node_to_node->getPrimitiveIn();
	
		if(Primitive_in->isQueue()){
	
			std::shared_ptr<dot_lang::Queue> queue_ptr = std::dynamic_pointer_cast<dot_lang::Queue>(Primitive_in);
	
			connected_node_to_node->setInjectionRate(Injection_rate);
	
			connected_node_to_node->setCoeffInterArrivalTime(coeff_var);
	
			if(queue_ptr){
	
				queue_ptr->setInjectionRate(Injection_rate);
	
				queue_ptr->setCoeffInterArrivalTime(coeff_var);
	
			}
	
	
		}
	
	}



}
}
