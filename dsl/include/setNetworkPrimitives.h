#ifndef SET_NETWORK_PRIMITIVES_H
#define SET_NETWORK_PRIMITIVES_H
#include<Primitive.h>
#include<memory>
#include<iostream>
#include<vector>

void set_network_primitive(std::shared_ptr<Primitive> primitive);
void set_nodes();
void set_nodes_for_primitive(std::shared_ptr<Primitive> primitive, const std::vector<std::string> &node_names);


#endif
