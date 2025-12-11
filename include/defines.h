#pragma once
#include <string>
#include <memory>
#include <set>
#include<map>
#include<iostream>

namespace dot_lang {
enum node_types {SOURCE=0, SINK, QUEUE, SERVER, ARBITER, SPLIT, ROUNDROBIN, HYBRID, PRIORITY, NODE_TYPE_COUNT };
}

const std::string _nodeTypeToString[dot_lang::NODE_TYPE_COUNT] = {
    "Source",
    "Sink",
    "Queue",
    "Server",
    "Arbiter",
    "Split",
    "roundrobin",
    "priority",
    "hybrid"
};

struct NodeSchema {

	std::set<std::string> required;
	std::set<std::string> allowed;
};

extern std::map<std::string, std::string> SymbolTable;

inline const std::map<std::string, NodeSchema> NODE_SCHEMAS = {
	
	{"source", {{"rate"}, {"rate", "cv", "label", "shape","type","depth","t_serv","coeff_var","zero_load", "priority_no"}}},
	{"queue", {{"depth"}, {"depth", "label", "shape","type","rate","cv","t_serv","coeff_var","zero_load","priority_no"}}},
	{"server", {{"t_serv", "coeff_var"},{"t_serv", "coeff_var", "label", "shape","type","rate","cv","depth","zero_load","priority_no"}}},
	{"arbiter", {{"zero_load"}, {"zero_load", "label", "shape","type","rate","cv","depth","t_serv","coeff_var","priority_no"}}},
	{"roundrobin", {{"zero_load"}, {"zero_load", "label", "shape","type","rate","cv","depth","t_serv","coeff_var","priority_no"}}},
	{"priority", {{"zero_load"}, {"zero_load", "label", "shape","type","rate","cv","depth","t_serv","coeff_var","priority_no"}}},
	{"hybrid", {{"zero_load"},{"zero_load", "label", "shape", "type", "rate", "cv", "depth", "t_serv", "coeff_var","priority_no"}}},
	{"split", {{"type"}, {"label", "shape","type"}}},
	{"sink", {{"type"}, {"label", "shape","type"}}}
};

inline NodeSchema getNodeSchema(const std::string &type) {
	
	auto find_type = NODE_SCHEMAS.find(type);
	if(find_type == NODE_SCHEMAS.end()) {
	     
		throw std::runtime_error("Unknown node type: " + type);
	}
	return find_type->second;
} 
