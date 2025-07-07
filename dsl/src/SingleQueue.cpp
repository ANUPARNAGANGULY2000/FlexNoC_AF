#include "SingleQueue.h"
#include <iostream>

namespace dot_lang{
//Single Queue Waiting Time calculation
double single_queue_waiting_time(double injection_rate, double service_time){
	double rho = injection_rate * service_time;
	double waiting_time = 0.0;
	waiting_time = 0.5*rho*(service_time - 1)/(1-rho);
	//cout<<"Injection_rate: "<<injection_rate<<" service_time : "<<service_time<<endl;
	//cout<<"Waiting time: "<<waiting_time<<endl;
return waiting_time;
}
}
