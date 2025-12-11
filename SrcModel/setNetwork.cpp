#include "setNetwork.h"
#include "Junction.h"
#include "setNetworkPrimitives.h"
#include "getUtils.h"
#include <iostream>
#include <algorithm>
#include <string>

namespace model{

//void read_network(dot_lang::Mapping& mapping){
void Invoke_analytical_model(dot_lang::Mapping& mapping){
    set_nodes(mapping);

    //check Sink is getting full or not
    for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();++it){

	std::string node_name = it->second;
	std::transform(node_name.begin(), node_name.end(), node_name.begin(), ::tolower);
   
    	if(node_name.find("sink") != std::string::npos){
		std::shared_ptr<dot_lang::Junc> get_node = mapping.node_data[it->first];
		std::shared_ptr<dot_lang::Primitive> primitive_in = get_node->getPrimitiveIn();//address of the connected Queue.
	 	if(!primitive_in->isQueue()){
	    		for(auto itr=mapping.node_files.begin(); itr!=mapping.node_files.end(); ++itr){
	 			if(itr->second == get_node){
					std::shared_ptr<dot_lang::Junc> prev_node = itr->first;
		   			primitive_in = prev_node->getPrimitiveIn();
		   			if(primitive_in->isQueue()){
		        			set_network_primitive(primitive_in, mapping);
		    			}
		 		  }
	      		}
	          }   
	  }
    }

    set_nodes(mapping);

}
}
