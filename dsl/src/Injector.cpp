#include <Injector.h>

using namespace dot_lang;

Injector::Injector() : Node(dot_lang::node_types::SOURCE) {
    _rate = 0.99;
}

std::string
Injector::_shape() {
    return "shape=\"rarrow\"";
}

std::string
Injector::getGraphVizProperties() {
    std::string label = "label=\"ID: " + std::to_string(getID()) + " | CV2: " + std::to_string(_rate) + "\"";
    return label + ", " + _shape() + ", cv2=" + std::to_string(_rate);
}

Queue::Queue() : Node(dot_lang::node_types::QUEUE) {
    _size = 4;
}

std::string
Queue::_shape() {
    return "shape=\"cylinder\"";
}

std::string
Queue::getGraphVizProperties() {
    std::string label = "label=\"ID: " + std::to_string(getID()) + " | Depth: " + std::to_string(_size) + "\"";
    return label + ", " + _shape() + ", depth=" + std::to_string(_size);
}