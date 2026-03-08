#include "Split.h"
#include <sstream>

dot_lang::Split::Split(){};

bool dot_lang::Split::isQueue() const { return false; }
bool dot_lang::Split::isServer() const { return false; }
bool dot_lang::Split::isInjector() const { return false; }
bool dot_lang::Split::isArbiter() const { return false; }
bool dot_lang::Split::isSplit() const { return isActive; }
bool dot_lang::Split::isSink() const { return false; }
bool dot_lang::Split::isMerge() const { return false; }
bool dot_lang::Split::isRRarbiter() const { return false; }
bool dot_lang::Split::isPRarbiter() const { return false; }
bool dot_lang::Split::isHybridArbiter() const { return false; }

void dot_lang::Split::activeFlag() { isActive = true; }

std::string dot_lang::Split::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + "\"";
    return label + ", " + _shape();
}

std::vector<double> dot_lang::Split::primitive() {
    return {}; // Your actual primitive logic
}

void dot_lang::Split::addSplitProbability(const std::string &port, double probability){

	SplitProbabilyMap[port] = probability;
}

double dot_lang::Split::getProbabilitySum() const {

	double sum = 0.0;
	for(const auto&[_, value]: SplitProbabilyMap){
	
		sum += value;
	}
	return sum;
}

double dot_lang::Split::getInjectionRate() const { return injection_rate; }
double dot_lang::Split::getCoeffInterArrivalTime() const { return coeff_interarrival_time; }

void dot_lang::Split::setInjectionRate(double &new_injection_rate) {
    injection_rate = new_injection_rate;
}

void dot_lang::Split::setCoeffInterArrivalTime(double &new_coeff_interarrival_time) {
    coeff_interarrival_time = new_coeff_interarrival_time;
}

void dot_lang::Split::updateSplitProbability(const std::string& port, double probability){

	auto PortDirection = SplitProbabilyMap.find(port);
	if(PortDirection != SplitProbabilyMap.end()){
		PortDirection->second = probability;
	
	}

}

const std::map<std::string, double>& dot_lang::Split::getSplitProbability() const {

	return SplitProbabilyMap;

}
std::string dot_lang::Split::_shape(){
    return "shape=\"doublecircle\"";
}
