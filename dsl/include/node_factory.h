#pragma once
#include <string>
#include <map>
#include <memory>
#include "Node.h"

namespace dot_lang {
    class NodeFactory {
    public:
        NodeFactory() {};
        ~NodeFactory() = default;

	std::shared_ptr<Node> getNodeFromType(node_types _type, std::string name, std::map<std::string, std::string>& attributes);
    };
}
