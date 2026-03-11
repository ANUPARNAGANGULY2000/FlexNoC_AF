#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Primitive.h"

namespace dot_lang {

//class representing node
class Junc{
    public:
        Junc(std::shared_ptr<Primitive> primitive_in , std::shared_ptr<Primitive> primitive_out, double injection_rate, double coeff_interarrival_time, double pipeline_delay);
	virtual ~Junc() = default;


        //primitive_in --> source primitive
	std::shared_ptr<Primitive> getPrimitiveIn() const;

        //primitive_out --> destination primitve
	std::shared_ptr<Primitive> getPrimitiveOut() const;

        //get
        double getInjectionRate() const;
        double getCoeffInterArrivalTime() const;
	double getPipelineDelay() const;
	
	//set
        void setInjectionRate(double &new_injection_rate);
        void setCoeffInterArrivalTime(double &new_coeff_interarrival_time);
	void setPipelineDelay(double &new_pipeline_delay);

	//create junction name
	static std::string generateJunctionName(){
	     return "N"+std::to_string(JunctionCounter++);
	}

    protected:
	std::shared_ptr<Primitive> primitive_in;
	std::shared_ptr<Primitive> primitive_out;
        double injection_rate;
	double pipeline_delay;
        double coeff_interarrival_time;
	static int JunctionCounter;
};

}
