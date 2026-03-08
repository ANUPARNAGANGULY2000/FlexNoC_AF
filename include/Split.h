#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"

namespace dot_lang {

//class sink if there is no destination primitive for a node
class Split : public Primitive{
    public:
	    Split();
	    virtual ~Split()= default;
        bool isSplit() const override;
	bool isSink() const override;
        bool isServer() const override;
        bool isQueue() const override;
        bool isArbiter() const override;
        bool isInjector() const override;
        bool isMerge() const override;
        bool isPRarbiter() const override;
        bool isRRarbiter() const override;
	bool isHybridArbiter() const override;
        void activeFlag() override;
	std::vector<double> primitive() override;

	std::string getGraphVizProperties() override;

	void addSplitProbability(const std::string &port, double probability);
	const std::map<std::string, double>& getSplitProbability() const;
	double getProbabilitySum() const;
	double getInjectionRate() const;
    	double getCoeffInterArrivalTime() const;

    	// Set
    	void setInjectionRate(double &new_injection_rate);
    	void setCoeffInterArrivalTime(double &new_coeff_interarrival_time);
	void updateSplitProbability(const std::string& port, double probability);


   protected:
    std::string _shape() override;


   private:
        bool isActive = false;
	std::map<std::string, double> SplitProbabilyMap; // store the spliting probability of every port.
	double injection_rate;
    	double coeff_interarrival_time;

};
}

