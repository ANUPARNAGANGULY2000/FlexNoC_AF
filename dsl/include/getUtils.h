#ifndef GET_UTILS_H
#define GET_UTILS_H

#include<Junction.h>
#include<Primitive.h>
#include<iostream>
#include<memory>
#include<Server.h>

std::shared_ptr<dot_lang::Server> getServer(std::shared_ptr<dot_lang::Junc> node);
std::string getPrimitiveName(std::shared_ptr<dot_lang::Primitive> primitive);
std::string getConnectedNode(std::string primitive_string);

#endif
