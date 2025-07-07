#include<UpdateNodeQueue.h>
#include<MakeConnection.h>
#include<Mapping.h>

namespace dot_lang{
//update node from queue
void update_node_from_Queue(std::vector<std::shared_ptr<dot_lang::Queue>>& queues, Mapping& mapping){

	std::cout<<"it's coming to update node from queue "<<std::endl;
	std::vector<std::string> queue_string;//to get Queue_string of the corresponding queue address
    for(auto queue_index=0; queue_index<queues.size(); ++queue_index){
    	for(auto primitive=mapping.primitive_map.begin(); primitive!=mapping.primitive_map.end(); ++primitive){
	    if(primitive->second == queues[queue_index]){
		    std::cout<<"string: "<<primitive->first<<std::endl;
		queue_string.push_back(primitive->first);
           }

	}
    }

    std::vector<std::shared_ptr<dot_lang::Junc>> nodes;
   for(auto queue_index=0; queue_index!=queues.size(); ++queue_index){
	   std::string node_name = mapping.node_connections[queue_string[queue_index]];//node which is connected to the queue
	   std::shared_ptr<dot_lang::Junc> node_address = mapping.node_data[node_name];//address of the node
	   std::cout<<"node name: "<<node_name<<"   node_address: "<<node_address<<std::endl;
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
void node_update_forward(std::vector<std::shared_ptr<dot_lang::Junc>>& nodes, Mapping& mapping){


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
	      std::shared_ptr<Primitive> primitive_out = next_node->getPrimitiveOut();
               if(primitive_out->isQueue()){
		       std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
             		 queue->setInjectionRate(injection_rate);
             		 queue->setCoeffInterArrivalTime(coeff_interarrival_time);
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
	   std::vector<double> merged_flows = MakeConnection::Merging_flow(injection_rates, coeff_inter_arrival_times);
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
}
