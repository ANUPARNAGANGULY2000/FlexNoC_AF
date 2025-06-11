#include<setNetwork.h>
#include<Junction.h>
#include<setNetworkPrimitives.h>
#include<Mapping.h>



void read_network(){

    set_nodes();

    dot_lang::Mapping mapping;
    //check Sink is getting full or not
    for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();++it){
    	if(it->second == "Sink"){
		std::shared_ptr<Junc> get_node = mapping.node_data[it->first];
		std::shared_ptr<Primitive> primitive_in = get_node->getPrimitiveIn();//address of the connected Queue.
	 	if(!primitive_in->isQueue()){
	    		for(auto itr=mapping.node_files.begin(); itr!=mapping.node_files.end(); ++itr){
	 			if(itr->second == get_node){
					std::shared_ptr<Junc> prev_node = itr->first;
		   			primitive_in = prev_node->getPrimitiveIn();
		   			if(primitive_in->isQueue()){
		        			set_network_primitive(primitive_in);
		    			}
		 		  }
	      		}
	          }   
	  }
    }

    set_nodes();

}
