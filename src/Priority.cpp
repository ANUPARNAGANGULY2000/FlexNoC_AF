#include "Priority.h"
#include <iostream>
#include "PriorityModel.h"
#include "UpdateNodeQueue.h"

dot_lang::PriorityArbiter::PriorityArbiter(double zero_load_latency)
    : dot_lang::Arbiter(zero_load_latency) {}

bool dot_lang::PriorityArbiter::isRRarbiter() const { return false; }
bool dot_lang::PriorityArbiter::isSplit() const { return false; }
bool dot_lang::PriorityArbiter::isServer() const { return false; }
bool dot_lang::PriorityArbiter::isQueue() const { return false; }
bool dot_lang::PriorityArbiter::isInjector() const { return false; }
bool dot_lang::PriorityArbiter::isArbiter() const { return isActive; }
bool dot_lang::PriorityArbiter::isMerge() const { return false; }
bool dot_lang::PriorityArbiter::isSink() const { return false; }
bool dot_lang::PriorityArbiter::isHybridArbiter() const { return false; }
bool dot_lang::PriorityArbiter::isPRarbiter() const { return isActive; }

void dot_lang::PriorityArbiter::activeFlag() { isActive = true; }

void dot_lang::PriorityArbiter::arbiter(Mapping& mapping) {
    std::vector<std::shared_ptr<Queue>> queues;
    std::shared_ptr<PriorityArbiter> PRarbiter = nullptr;

    for (const auto& junc : junction) {
	    std::shared_ptr<Queue> queue_in = std::dynamic_pointer_cast<Queue>(junc->getPrimitiveIn());
        if (queue_in) {
            queues.push_back(queue_in);
        }
        PRarbiter = std::dynamic_pointer_cast<PriorityArbiter>(junc->getPrimitiveOut());
    }

    if (PRarbiter) {
	    double service_time = PRarbiter->getServiceTime();
	    double zero_load = PRarbiter->getZeroLoadLatency();
	    model::priority_model(queues, service_time, zero_load, mapping);
	    model::update_node_from_Queue(queues, mapping);
	    
    }
}

std::vector<double> dot_lang::PriorityArbiter::primitive() {
    return {};
}

double dot_lang::PriorityArbiter::getZeroLoadLatency() {
    return zero_load_latency;
}

void dot_lang::PriorityArbiter::setZeroLoadLatency(double& new_zero_load_latency) {
    zero_load_latency = new_zero_load_latency;
}

void dot_lang::PriorityArbiter::setServiceTime(double& new_service_time) {
    service_time = new_service_time;
}

double dot_lang::PriorityArbiter::getServiceTime() {
    return service_time;
}

void dot_lang::PriorityArbiter::setCoeffServiceTime(double& new_coeff_service_time) {
    coeff_service_time = new_coeff_service_time;
}

double dot_lang::PriorityArbiter::getCoeffServiceTime() {
    return coeff_service_time;
}
std::string dot_lang::PriorityArbiter::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + " | zero_load: " + std::to_string(zero_load_latency) + "\"";
    return label + ", " + _shape() + ", zero_load=" + std::to_string(zero_load_latency);
}
std::string dot_lang::PriorityArbiter::_shape() {
    return "shape=\"diamond\"";
}
