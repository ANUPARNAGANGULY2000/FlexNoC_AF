#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"


namespace dot_lang {

//class representing an injector
class Injector: public Primitive{
    public:
        Injector(double injection_rate, double coeff_interarrival_time,double waiting_time);
	 virtual ~Injector() = default;
	
	 // Type identification
        bool isInjector() const override;
        bool isQueue() const override;
        bool isServer() const override;
        bool isArbiter() const override;
        bool isMerge() const override;
        bool isSplit() const override;
        bool isSink() const override;
        bool isRRarbiter() const override;
        bool isPRarbiter() const override;
        //active flag variable for Injector
        void activeFlag() override;

	//get
        double getInjectionRate() const;
	double getCoeffInterArrivalTime() const;
	double getWaitingTime() const;

	//set
        void setInjectionRate(double &updated_injection_rate);
        void setCoeffInterArrivalTime(double updated_coeff_interarrival_time);
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
