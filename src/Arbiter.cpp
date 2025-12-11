#include "Arbiter.h"

dot_lang::Arbiter::Arbiter(double zero_load_latency)
    : zero_load_latency(zero_load_latency) {}

bool dot_lang::Arbiter::isArbiter() const { return isActive; }
bool dot_lang::Arbiter::isSplit() const { return false; }
bool dot_lang::Arbiter::isServer() const { return false; }
bool dot_lang::Arbiter::isQueue() const { return false; }
bool dot_lang::Arbiter::isInjector() const { return false; }
bool dot_lang::Arbiter::isMerge() const { return false; }
bool dot_lang::Arbiter::isSink() const { return false; }
bool dot_lang::Arbiter::isRRarbiter() const { return false; }
bool dot_lang::Arbiter::isPRarbiter() const { return false; }
bool dot_lang::Arbiter::isHybridArbiter() const { return false; }
void dot_lang::Arbiter::activeFlag() { isActive = true; }

void dot_lang::Arbiter::setJunction(const std::vector<std::shared_ptr<dot_lang::Junc>> &junction) {
    this->junction = junction;
}

std::string dot_lang::Arbiter::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + " | zero_load: " + std::to_string(zero_load_latency) + "\"";
    return label + ", " + _shape() + ", zero_load=" + std::to_string(zero_load_latency);
}

std::string dot_lang::Arbiter::_shape() {
    return "shape=\"diamond\"";
}

