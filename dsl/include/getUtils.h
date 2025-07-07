#ifndef GET_UTILS_H
#define GET_UTILS_H

#include "Junction.h"
#include "Primitive.h"
#include <iostream>
#include <memory>
#include "Server.h"
#include "Mapping.h"

namespace dot_lang{
	
	std::shared_ptr<dot_lang::Server> getServer(std::shared_ptr<dot_lang::Junc> node, Mapping& mapping);
	std::string getPrimitiveName(std::shared_ptr<dot_lang::Primitive> primitive, Mapping& mapping);
	std::string getConnectedNode(std::string primitive_string, Mapping& mapping);
};
#endif
