#pragma once
#include <Node.h>
#include <Injector.h>

namespace dot_lang {
    class NodeFactory {
    public:
        NodeFactory() {};
        ~NodeFactory() = default;

        std::shared_ptr<Node> getNodeFromType(node_types _type, std::string name="");
    };
}