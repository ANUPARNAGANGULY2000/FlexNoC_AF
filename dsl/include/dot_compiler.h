#pragma once

#include "DOTLexer.h"
#include "DOTParser.h"
#include "network.h"
#include "NodeVisitor.h"
#include "EdgeVisitor.h"
#include "TypeCheckVisitor.h"

namespace dot_lang {
class DOT {
public:
    DOT(std::string pathToDOTFile);
    ~DOT() = default;

    // example api to get the network object
    Network* getNetwork() { return network; }

    Mapping& getMapping() { return mapping; }
    int test() { return 1; }
private:
    void _compile(std::string);
    void _translate(std::string);
    void _optimize();
    void _codegen();
    Network* network;
    Mapping mapping;
};

}
