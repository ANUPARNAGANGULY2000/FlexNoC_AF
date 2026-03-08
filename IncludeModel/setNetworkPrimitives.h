#ifndef SET_NETWORK_PRIMITIVES_H
#define SET_NETWORK_PRIMITIVES_H
#include "Primitive.h"
#include<memory>
#include<iostream>
#include<vector>
#include "Mapping.h"

namespace model{

void set_network_primitive(std::shared_ptr<dot_lang::Primitive> primitive, dot_lang::Mapping& mapping);
void set_nodes(dot_lang::Mapping& mapping);
void set_nodes_for_primitive(std::shared_ptr<dot_lang::Primitive> primitive, const std::vector<std::string> &node_names, dot_lang::Mapping& mapping);
};

#endif
