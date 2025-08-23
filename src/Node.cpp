#include <Node.h>

using namespace dot_lang;

unsigned int Node::_id_counter = 0; // Initialize counter

Node::Node() : _id(_id_counter++) {}

Node::Node(node_types type) : _id(_id_counter++), _type(type) {}

std::string
Node::getGraphVizProperties() {
    return "label=\"" + std::to_string(_id) + "\", type=\"" + _nodeTypeToString[_type] + "\"";
}
