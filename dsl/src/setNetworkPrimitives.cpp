#include<setNetworkPrimitives.h>
#include<Junction.h>
#include<Server.h>
#include<Mapping.h>
#include<Queue.h>
#include<iostream>
#include<updateProcess.h>
#include<SingleQueue.h>

//set Nodes after reading inputs
void set_nodes(){

	dot_lang::Mapping mapping;	
        for(auto itr=mapping.server_track.begin(); itr!=mapping.server_track.end(); ++itr){	
		std::string server_name=itr->first;
		std::string connected_primitive_name=itr->second;
                if(mapping.primitive_map.find(server_name)!=mapping.primitive_map.end() && mapping.primitive_map.find(connected_primitive_name)!=mapping.primitive_map.end()){
			std::shared_ptr<Primitive> server_primitive = mapping.primitive_map[server_name];
			std::shared_ptr<Primitive> connected_primitive=mapping.primitive_map[connected_primitive_name];
     			//RoundRobin Arbitration
     			if(connected_primitive->isRRarbiter()){
				std::shared_ptr<RoundRobinArbiter> rr_arbiter=std::dynamic_pointer_cast<RoundRobinArbiter>(connected_primitive);
				if(rr_arbiter){
	   				for(auto it=mapping.node_names.begin(); it!=mapping.node_names.end(); ++it){
	       					if(it->first == connected_primitive_name){
	        					set_nodes_for_primitive(rr_arbiter,it->second);
	       					 }
	   				}
				}
     			}	
     		       //Priority Arbiter
     			else if(connected_primitive->isPRarbiter()){
     				std::shared_ptr<PriorityArbiter> pr_arbiter=std::dynamic_pointer_cast<PriorityArbiter>(connected_primitive);
				if(pr_arbiter){
	  				for(auto it=mapping.node_names.begin(); it!=mapping.node_names.end(); ++it){
	     					if(it->first == connected_primitive_name){
	     						 set_nodes_for_primitive(pr_arbiter,it->second);
	     					}	
	                                 }  
	                        } 
     			}
     			else if(connected_primitive->isQueue()){
     				std::shared_ptr<Queue> queue=std::dynamic_pointer_cast<Queue>(connected_primitive);
				std::shared_ptr<Server> server=std::dynamic_pointer_cast<Server>(server_primitive);
				if(queue && server){
	  				double injection_rate=queue->getInjectionRate();
	  				double service_time=server->getServiceTime();
	  				double waiting_time=single_queue_waiting_time(injection_rate,service_time);
	  				queue->setWaitingTime(waiting_time);
				}
     			}
     		}  	
    	 }
}


//set notes for primitives(arbiter,merg,split)
void set_nodes_for_primitive(std::shared_ptr<Primitive> primitive, const std::vector<std::string> &node_names){

	dot_lang::Mapping mapping;
	std::vector<std::shared_ptr<Junc>> nodes;
        size_t index=0;
        for(const auto& node_name: node_names){
           auto it_node = mapping.node_data.find(node_name);
          if(it_node != mapping.node_data.end()){
             nodes.push_back(it_node->second);
          }
         } 
        primitive->setNodes(nodes);
       if(std::dynamic_pointer_cast<RoundRobinArbiter>(primitive)){
	       std::shared_ptr<RoundRobinArbiter> rr_arbiter = std::dynamic_pointer_cast<RoundRobinArbiter>(primitive);
	        rr_arbiter->arbiter();
        }
        if(std::dynamic_pointer_cast<PriorityArbiter>(primitive)){
		std::shared_ptr<PriorityArbiter> pr_arbiter = std::dynamic_pointer_cast<PriorityArbiter>(primitive);
		 pr_arbiter->arbiter();
	}
	
}



//To set network primitive
void set_network_primitive(std::shared_ptr<Primitive> primitive){

    dot_lang::Mapping mapping;
    double injection_rate=0.0,coeff_interarrival_time=0.0;
    double service_time=0.0,coeff_service_time=0.0;
    int Buffer_size=0;
    double t_cap=0.0, Cs_square_cap=0.0;
    std::string source,source_new;

    //taking corresponding string of the primitive
    if(primitive){
    for(auto it=mapping.primitive_map.begin();it!=mapping.primitive_map.end();++it){
       	if(it->second == primitive){
	source = it->first;
	}
      }
    }

    //taking injection_rate,coeff_inter_arrival_time and buffersize from the queue.
    std::shared_ptr<Queue> queue = std::dynamic_pointer_cast<Queue>(primitive);
    injection_rate = queue->getInjectionRate();
    coeff_interarrival_time = queue->getCoeffInterArrivalTime();
    Buffer_size = queue->getBufferSize();

   //checking which node is connected to that queue.
   for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();++it){
       if(it->first == source){
	       std::string connected_node = it->second;
	       std::shared_ptr<Junc> node = mapping.node_data[connected_node];
	       std::shared_ptr<Server> server_primitive = getServer(node);
            // server_primitive is a server
	     if(server_primitive->isServer()){
		     std::shared_ptr<Primitive> primitive_inn = std::dynamic_pointer_cast<Primitive>(server_primitive);
 		 if(primitive_inn){
	         for(auto it=mapping.primitive_map.begin();it!=mapping.primitive_map.end();++it){
       			 if(it->second == primitive_inn){
       			    source_new = it->first;
                         }
                   }
                 }
       service_time = server_primitive->getServiceTime();
       coeff_service_time = server_primitive->getCoeffServiceTime();
       std::shared_ptr<double> service_process = update_service_process(injection_rate,coeff_interarrival_time,service_time,coeff_service_time,Buffer_size);
       t_cap = service_process[0];
       Cs_square_cap = service_process[1];
       for(auto itr=mapping.node_connections.begin();itr!=mapping.node_connections.end(); ++itr){
	    if(itr->second==source){
		    std::string prev_connected_node = itr->first;
		    std::shared_ptr<Junc> node_primitive= mapping.node_data[prev_connected_node];
		    std::shared_ptr<Primitive> primitive_in = node_primitive->getPrimitiveIn();
		    if(primitive_in->isServer()){
			    std::shared_ptr<Server> server = std::dynamic_pointer_cast<Server>(primitive_in);
		   	    if(t_cap == service_time){
				    std:: cout<<"service time not changed "<<std::endl;
				    server_to_arbiter_track(server);
       		             }
      		           else if(t_cap!=service_time){
                        	std::cout<<"service time has changed "<<std::endl;
		    		server->setServiceTime(t_cap);
		        	server->setCoeffServiceTime(Cs_square_cap);
		        	server->activeServiceTimeFlag();
  		    		//update the sevice time of the arbiter connected to that server
  		    		update_arbiter_service_process(server,t_cap,Cs_square_cap);
		   	   }
		      }
	       }
          }
 	}

 	//primitive_in is a Injector
	// else if(primitive_in->isInjector()){}

 	//primitive_in is a merge
	// else if(primitive_in->isMerge()){}

	 //primitive_in is a split
       }
    }
}
