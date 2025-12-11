#include "Injector.h"
#include <sstream>


dot_lang::Injector::Injector(double injection_rate, double coeff_interarrival_time,double waiting_time)
    : injection_rate(injection_rate), coeff_interarrival_time(coeff_interarrival_time), waiting_time(waiting_time) {}

bool dot_lang::Injector::isInjector() const { return isActive; }
bool dot_lang::Injector::isQueue() const { return false; }
bool dot_lang::Injector::isServer() const { return false; }
bool dot_lang::Injector::isArbiter() const { return false; }
bool dot_lang::Injector::isMerge() const { return false; }
bool dot_lang::Injector::isSplit() const { return false; }
bool dot_lang::Injector::isSink() const { return false; }
bool dot_lang::Injector::isRRarbiter() const { return false; }
bool dot_lang::Injector::isPRarbiter() const { return false; }
bool dot_lang::Injector::isHybridArbiter() const { return false; }

void dot_lang::Injector::activeFlag() { isActive = true; }

double dot_lang::Injector::getInjectionRate() const { return injection_rate; }
void dot_lang::Injector::setInjectionRate(double &updated_injection_rate) {
    injection_rate = updated_injection_rate;
}

double dot_lang::Injector::getCoeffInterArrivalTime() const { return coeff_interarrival_time; }
void dot_lang::Injector::setCoeffInterArrivalTime(double updated_coeff_interarrival_time) {
    coeff_interarrival_time = updated_coeff_interarrival_time;
}

double dot_lang::Injector::getWaitingTime() const { return waiting_time; }
void dot_lang::Injector::setWaitingTime(double &new_waiting_time) {
    waiting_time = new_waiting_time;
}

std::vector<double> dot_lang::Injector::primitive() {
    return {};
}

std::string dot_lang::Injector::getGraphVizProperties() {
    std::string label = "label=\"ID: " + std::to_string(getID()) + " | rate: " + std::to_string(injection_rate) + "\"";
    return label + ", " + _shape() + ", injection=" + std::to_string(injection_rate);
}

std::string dot_lang::Injector::_shape() {
    return "\"rarrow\"";
}

