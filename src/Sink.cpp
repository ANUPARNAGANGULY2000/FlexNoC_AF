#include "Sink.h"
#include <sstream>

dot_lang::Sink::Sink(){};

bool dot_lang::Sink::isQueue() const { return false; }
bool dot_lang::Sink::isServer() const { return false; }
bool dot_lang::Sink::isInjector() const { return false; }
bool dot_lang::Sink::isArbiter() const { return false; }
bool dot_lang::Sink::isSplit() const { return false; }
bool dot_lang::Sink::isSink() const { return isActive; }
bool dot_lang::Sink::isMerge() const { return false; }
bool dot_lang::Sink::isRRarbiter() const { return false; }
bool dot_lang::Sink::isPRarbiter() const { return false; }
bool dot_lang::Sink::isHybridArbiter() const { return false; }

void dot_lang::Sink::activeFlag() { isActive = true; }

std::string dot_lang::Sink::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + "\"";
    return label + ", " + _shape();
}

std::vector<double> dot_lang::Sink::primitive() {
    return {}; // Your actual primitive logic
}

std::string dot_lang::Sink::_shape(){
    return "shape=\"doublecircle\"";
}
