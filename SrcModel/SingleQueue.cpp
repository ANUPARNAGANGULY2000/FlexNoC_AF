#include "SingleQueue.h"
#include <iostream>

namespace model{
//Single Queue Waiting Time calculation
double single_queue_waiting_time(double injection_rate, double service_time){
	double rho = injection_rate * service_time;
	double waiting_time = 0.0;
	waiting_time = 0.5*rho*(service_time - 1)/(1-rho);
	//std::cout<<"Injection_rate: "<<injection_rate<<" service_time : "<<service_time<<std::endl;
	//std::cout<<"Single Queue Waiting time: "<<waiting_time<<std::endl;
return waiting_time;
}
}
