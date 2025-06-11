#pragma once

#include "DOTBaseVisitor.h"
#include "Node.h"
#include "network.h"
#include "DOTParser.h"
#include <map>
#include <string>

namespace dot_lang {

    class TypeCheckVisitor{
    public:
	TypeCheckVisitor(){};
	~TypeCheckVisitor() = default;
	//constructor that accepts a Network pointer
       static void isValidConnection(std::string source, std::string destination);
	
        //TypeCheckVisitor(Network* net) : network(net) {}

    };
}
