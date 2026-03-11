#include "getUtils.h"
#include "Mapping.h"
#include "Server.h"
#include <algorithm>

namespace model{
std::string getPrimitiveName(std::shared_ptr<dot_lang::Primitive> primitive, dot_lang::Mapping& mapping){

	std::string primitive_name;
	for(auto key=mapping.primitive_map.begin(); key!=mapping.primitive_map.end(); ++key){
	    if(key->second == primitive){
	        primitive_name = key->first;
	    }
	}
 return primitive_name;
}

std::string getConnectedNode(std::string primitive_string, dot_lang::Mapping& mapping){

	std::string key_string;
        for(auto key=mapping.node_connections.begin(); key!=mapping.node_connections.end(); ++key){
         if(key->second == primitive_string){
	      key_string = key->first;
	 }
     }
     return key_string;
}

std::shared_ptr<dot_lang::Server> getServer(std::shared_ptr<dot_lang::Junc> node, dot_lang::Mapping& mapping){

	std::shared_ptr<dot_lang::Primitive> primitive_out = node->getPrimitiveOut();
        if(primitive_out->isServer()){
		std::shared_ptr<dot_lang::Server> server = std::dynamic_pointer_cast<dot_lang::Server>(primitive_out);
	    return server;
         }
       else{
  	 std::shared_ptr<dot_lang::Junc> next_node = mapping.node_files[node];
   	 if(next_node){
 		return getServer(next_node, mapping);
	 }
       }
   return nullptr;
}

std::shared_ptr<dot_lang::Junc> getPrevJunction(std::shared_ptr<dot_lang::Junc> junction, dot_lang::Mapping& mapping){

         
	 for(auto it=mapping.node_files.begin(); it!=mapping.node_files.end(); ++it){
                 if(it->second == junction){
		    std::shared_ptr<dot_lang::Junc> PrevJunction = it->first;
		    return PrevJunction;
		 }
	 }
	 return nullptr;
}

std::shared_ptr<dot_lang::Junc> getNextJunction(std::shared_ptr<dot_lang::Junc> prevJunc, dot_lang::Mapping& mapping){

	std::shared_ptr<dot_lang::Junc> NextJunc = nullptr;
	for(auto it=mapping.node_files.begin(); it!=mapping.node_files.end(); ++it){
	
		if(it->first == prevJunc){
		
			NextJunc = it->second;
		}
	}
	return NextJunc;

}


void trackJunction(std::shared_ptr<dot_lang::Injector> injector,
                   std::shared_ptr<dot_lang::Junc> junction,
                   dot_lang::Mapping& mapping)
{
    auto& junction_list = mapping.junction_track[injector];

    // check if junction already exists
    auto it = std::find(junction_list.begin(), junction_list.end(), junction);

    if(it == junction_list.end())
    {
        // add junction
        junction_list.push_back(junction);
    }

        // get next junction
        auto nextJunction = getNextJunction(junction, mapping);

        if(nextJunction)
        {
            trackJunction(injector, nextJunction, mapping);
        }
    
}

double totalPipelineDelay(std::shared_ptr<dot_lang::Injector> injector, dot_lang::Mapping& mapping){

	auto ref = mapping.junction_track.find(injector);
	double delay = 0.0;
	if(ref != mapping.junction_track.end()){
	
		std::vector<std::shared_ptr<dot_lang::Junc>> junction_list = ref ->second;
                for(auto junction_iter : junction_list){
		

			delay += junction_iter ->getPipelineDelay();
			
		}

	}
	return delay;
}
}
