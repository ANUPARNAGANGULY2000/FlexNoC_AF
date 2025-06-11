#pragma once
#include <string>
#include <memory>
#include <set>
#include<map>
#include<iostream>

namespace dot_lang {
enum node_types {SOURCE=0, SINK, QUEUE, SERVER, ARBITER};
}

const std::string _nodeTypeToString[] = {
    "Source",
    "Sink",
    "Queue",
    "Server",
    "Arbiter"
};

struct NodeSchema {

	std::set<std::string> required;
	std::set<std::string> allowed;
};

extern std::map<std::string, std::string> SymbolTable;

inline const std::map<std::string, NodeSchema> NODE_SCHEMAS = {

	{"source", {{"rate"}, {"rate", "cv", "label", "shape","type"}}},
	{"queue", {{"depth"}, {"depth", "label", "shape","type"}}},
	{"server", {{"t_serv", "coeff_var"},{"t_serv", "coeff_var", "label", "shape","type"}}},
	{"arbiter", {{"zero_load"}, {"zero_load", "label", "shape","type"}}},
	{"sink", {{}, {"label", "shape","type"}}}
};

inline NodeSchema getNodeSchema(const std::string &type) {
	auto find_type = NODE_SCHEMAS.find(type);
	if(find_type == NODE_SCHEMAS.end()) {
	     
		throw std::runtime_error("Unknown node type: " + type);
	}
	return find_type->second;
} 
