#include "Queue.h"
#include <sstream>  // for building graphviz output

dot_lang::Queue::Queue(int buffer_size,double waiting_time,double injection_rate,double coeff_interarrival_time, int priority):
           buffer_size(buffer_size),waiting_time(waiting_time),injection_rate(injection_rate),coeff_interarrival_time(coeff_interarrival_time),priority(priority){}

bool dot_lang::Queue::isQueue() const { return isActive; }
bool dot_lang::Queue::isServer() const { return false; }
bool dot_lang::Queue::isInjector() const { return false; }
bool dot_lang::Queue::isArbiter() const { return false; }
bool dot_lang::Queue::isSplit() const { return false; }
bool dot_lang::Queue::isSink() const { return false; }
bool dot_lang::Queue::isMerge() const { return false; }
bool dot_lang::Queue::isRRarbiter() const { return false; }
bool dot_lang::Queue::isPRarbiter() const { return false; }
bool dot_lang::Queue::isHybridArbiter() const { return false; }
void dot_lang::Queue::activeFlag() { isActive = true; }

int dot_lang::Queue::getBufferSize() const { return buffer_size; }
double dot_lang::Queue::getWaitingTime() const { return waiting_time; }
double dot_lang::Queue::getInjectionRate() const { return injection_rate; }
double dot_lang::Queue::getCoeffInterArrivalTime() const { return coeff_interarrival_time; }
double dot_lang::Queue::getServiceTime() const { return service_time; }
int dot_lang::Queue::getPriorityValue() const {return priority;}

void dot_lang::Queue::setInjectionRate(double &new_injection_rate) {
    injection_rate = new_injection_rate;
}

void dot_lang::Queue::setPriorityValue(int &new_priority){

	priority = new_priority;
}

void dot_lang::Queue::setCoeffInterArrivalTime(double &new_coeff_interarrival_time) {
    coeff_interarrival_time = new_coeff_interarrival_time;
}

void dot_lang::Queue::setWaitingTime(double &new_waiting_time) {
    waiting_time = new_waiting_time;
}

void dot_lang::Queue::setServiceTime(double &new_service_time) {
    service_time = new_service_time;
}

std::vector<double> dot_lang::Queue::primitive() {
    return {}; // Your actual primitive logic
}

//activate is_injection_rate_updated_after_saturation variable if after saturation the injection rate get modified.
	void dot_lang::Queue::activeInjectionRateUpdateFlag(){
	     is_injection_rate_updated_after_saturation = true;
	}

	bool dot_lang::Queue::isInjectionRateUpdated(){ return is_injection_rate_updated_after_saturation; }

std::string dot_lang::Queue::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + " | Depth: " + std::to_string(buffer_size) + "\"";
    return label + ", " + _shape() + ", depth=" + std::to_string(buffer_size);
}

std::string dot_lang::Queue::_shape() {
    return "shape=\"cylinder\"";
}

