#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"
#include "Node.h"

namespace dot_lang{

	class Injector: public Primitive {
         public:
         	Injector(double injection_rate, double coeff_interarrival_time,double waiting_time);
         virtual ~Injector() = default;

        // Type identification
        bool isInjector() const override;
        bool isQueue() const override;
        bool isServer() const override;
        bool isArbiter() const override;
        bool isMerge() const override;
        bool isSink() const override;
	bool isSplit() const override;
        bool isRRarbiter() const override;
        bool isPRarbiter() const override;
	bool isHybridArbiter() const override;
        void activeFlag() override;

        // get/set
        double getInjectionRate() const;
        void setInjectionRate(double &updated_injection_rate);

        double getCoeffInterArrivalTime() const;
        void setCoeffInterArrivalTime(double updated_coeff_interarrival_time);

        double getWaitingTime() const;
        void setWaitingTime(double &new_waiting_time);

        std::vector<double> primitive() override;
        std::string getGraphVizProperties() override;

    protected:
        std::string _shape() override;
        double injection_rate;
        double coeff_interarrival_time;
        double waiting_time;
        bool isActive = false;
};
}

