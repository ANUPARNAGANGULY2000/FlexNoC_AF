#include "Junction.h"
using namespace dot_lang;

     Junc::Junc(std::shared_ptr<Primitive> primitive_in , std::shared_ptr<Primitive> primitive_out, double injection_rate, double coeff_interarrival_time):
            primitive_in(primitive_in),primitive_out(primitive_out),injection_rate(injection_rate),coeff_interarrival_time(coeff_interarrival_time){}

        //primitive_in --> source primitive
	    std::shared_ptr<Primitive> Junc::getPrimitiveIn() const {return primitive_in;}
        //primitive_out --> destination primitve
	    std::shared_ptr<Primitive> Junc::getPrimitiveOut() const {return primitive_out;}

        double Junc::getInjectionRate() const{return injection_rate;}
        double Junc::getCoeffInterArrivalTime() const{return coeff_interarrival_time;}

        void Junc::setInjectionRate(double &new_injection_rate){
                injection_rate = new_injection_rate;
        }
        void Junc::setCoeffInterArrivalTime(double &new_coeff_interarrival_time){
                coeff_interarrival_time = new_coeff_interarrival_time;
        }

       int Junc::JunctionCounter = 1;
