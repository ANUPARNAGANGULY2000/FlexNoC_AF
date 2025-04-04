#include <node_factory.h>

using namespace dot_lang;

std::shared_ptr<Node>
NodeFactory::getNodeFromType(node_types _type, std::string name) {
    std::shared_ptr<Node> node;
    switch (_type) {
        case SOURCE:
            node = std::make_shared<Injector>();
            break;
        case SINK:
        case QUEUE:
            node = std::make_shared<Queue>();
            break;
        case SERVER:
        case ARBITER:
        default:
            node = std::make_shared<Injector>();
    }
    if (!name.empty()) {
        node->setName(name);
    }
    return node;
}