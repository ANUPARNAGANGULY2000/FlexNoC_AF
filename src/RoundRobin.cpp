#include "RoundRobin.h"
#include <iostream>
#include "RoundRobinModel.h"
#include "UpdateNodeQueue.h"

dot_lang::RoundRobinArbiter::RoundRobinArbiter(double zero_load_latency)
    : dot_lang::Arbiter(zero_load_latency) {}

bool dot_lang::RoundRobinArbiter::isRRarbiter() const { return isActive; }
bool dot_lang::RoundRobinArbiter::isSplit() const { return false; }
bool dot_lang::RoundRobinArbiter::isServer() const { return false; }
bool dot_lang::RoundRobinArbiter::isQueue() const { return false; }
bool dot_lang::RoundRobinArbiter::isInjector() const { return false; }
bool dot_lang::RoundRobinArbiter::isArbiter() const { return isActive; }
bool dot_lang::RoundRobinArbiter::isMerge() const { return false; }
bool dot_lang::RoundRobinArbiter::isSink() const { return false; }
bool dot_lang::RoundRobinArbiter::isPRarbiter() const { return false; }
bool dot_lang::RoundRobinArbiter::isHybridArbiter() const { return false; }

void dot_lang::RoundRobinArbiter::activeFlag() { isActive = true; }

void dot_lang::RoundRobinArbiter::arbiter(Mapping& mapping) {
    std::vector<std::shared_ptr<Queue>> queues;
    std::shared_ptr<RoundRobinArbiter> RRarbiter = nullptr;

    for (const auto& junc : junction) {
	    std::shared_ptr<Queue> queue_in = std::dynamic_pointer_cast<Queue>(junc->getPrimitiveIn());
        if (queue_in) {
            queues.push_back(queue_in);
        }
        RRarbiter = std::dynamic_pointer_cast<RoundRobinArbiter>(junc->getPrimitiveOut());
    }

    if (RRarbiter) {
	    double service_time = RRarbiter->getServiceTime();
	    double zero_load = RRarbiter->getZeroLoadLatency();
	    model::roundrobin_model(queues, service_time, zero_load, mapping);
	    model::update_node_from_Queue(queues, mapping);
    }
}

std::vector<double> dot_lang::RoundRobinArbiter::primitive() {
    return {};
}

double dot_lang::RoundRobinArbiter::getZeroLoadLatency() {
    return zero_load_latency;
}

void dot_lang::RoundRobinArbiter::setZeroLoadLatency(double& new_zero_load_latency) {
    zero_load_latency = new_zero_load_latency;
}

void dot_lang::RoundRobinArbiter::setServiceTime(double& new_service_time) {
    service_time = new_service_time;
}

double dot_lang::RoundRobinArbiter::getServiceTime() {
    return service_time;
}

void dot_lang::RoundRobinArbiter::setCoeffServiceTime(double& new_coeff_service_time) {
    coeff_service_time = new_coeff_service_time;
}

double dot_lang::RoundRobinArbiter::getCoeffServiceTime() {
    return coeff_service_time;
}

std::string dot_lang::RoundRobinArbiter::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + " | zero_load: " + std::to_string(zero_load_latency) + "\"";
    return label + ", " + _shape() + ", zero_load=" + std::to_string(zero_load_latency);
}

std::string dot_lang::RoundRobinArbiter::_shape() {
    return "shape=\"diamond\"";
}
