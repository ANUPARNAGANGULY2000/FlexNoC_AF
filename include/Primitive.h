#pragma once
#include <vector>
#include <string>
#include "Node.h" // from dot_lang

namespace dot_lang {

class Junc; // connector between two primitives

class Primitive : public Node {
public:
    using Node::Node;  // inherit constructors from Node

    virtual bool isServer() const = 0;
    virtual bool isQueue() const = 0;
    virtual bool isInjector() const = 0;
    virtual bool isArbiter() const = 0;
    virtual bool isMerge() const = 0;
    virtual bool isSplit() const = 0;
    virtual bool isSink() const = 0;
    virtual bool isRRarbiter() const = 0;
    virtual bool isPRarbiter() const = 0;
    virtual bool isHybridArbiter() const = 0;

    virtual void activeFlag() = 0;
    virtual std::vector<double> primitive() = 0;
    virtual void setJunction(const std::vector<std::shared_ptr<dot_lang::Junc>>& junction) {}

    virtual ~Primitive() = default;

    // Every Primitive must define DOT properties
    virtual std::string getGraphVizProperties() override = 0;
};
}
