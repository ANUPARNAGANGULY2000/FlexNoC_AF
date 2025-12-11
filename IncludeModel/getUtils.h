#ifndef GET_UTILS_H
#define GET_UTILS_H

#include "Junction.h"
#include "Primitive.h"
#include <iostream>
#include <memory>
#include "Server.h"
#include "Mapping.h"

namespace model{
	
	std::shared_ptr<dot_lang::Server> getServer(std::shared_ptr<dot_lang::Junc> node, dot_lang::Mapping& mapping);
	std::string getPrimitiveName(std::shared_ptr<dot_lang::Primitive> primitive, dot_lang::Mapping& mapping);
	std::string getConnectedNode(std::string primitive_string, dot_lang::Mapping& mapping);
	std::shared_ptr<dot_lang::Junc> getPrevJunction(std::shared_ptr<dot_lang::Junc> junction, dot_lang::Mapping& mapping);
	std::shared_ptr<dot_lang::Junc> getNextJunction(std::shared_ptr<dot_lang::Junc> prevJunc, dot_lang::Mapping& mapping);
};
#endif
