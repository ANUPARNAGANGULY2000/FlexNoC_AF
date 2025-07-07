#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Primitive.h"
#include "Queue.h"
#include "Injector.h"
#include "Junction.h"

namespace dot_lang{

	class Mapping{

	public:
//map from the name of primitive to its pointer
	std::map <std::string, std::shared_ptr<dot_lang::Primitive>> primitive_map;

//maps the injector to the primitives in the flow
	std::map<std::shared_ptr<dot_lang::Primitive>, std::shared_ptr<dot_lang::Injector>> primitive_flow;

//maps the injector to the queues in the flow
	std::map<std::shared_ptr<dot_lang::Injector>,std::vector<std::shared_ptr<dot_lang::Queue>>> queue_flow;

//maps the name of the node to its pointer
	std::map<std::string, std::shared_ptr<dot_lang::Junc>> node_data;

//maps the name of primitive_in to node and node_name to primitive_out names
	std::map<std::string,std::string> node_connections;

//maps the primitive(RR,PR,S,M) to a vector of nodes in each case
	std::map<std::string,std::vector<std::string>> node_names;

//maps the node_in to node_out
	std::map<std::shared_ptr<dot_lang::Junc>, std::shared_ptr<dot_lang::Junc>> node_files;

//maps the server is connected to which primitive
	std::map<std::string, std::string> server_track;


};
}
