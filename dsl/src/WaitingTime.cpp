#include<WaitingTime.h>
#include<Injector.h>
#include<Queue.h>
#include<iostream>
#include<memory>
#include<Mapping.h>

namespace dot_lang{

void waiting_time_calc(Mapping& mapping){
    
    //iterate over the map to calculate waiting time of each injector
    for(auto it = mapping.queue_flow.cbegin(); it != mapping.queue_flow.cend(); ++it)
    {
	    std::shared_ptr<dot_lang::Injector> injector =it->first;
        //for every queue in the flow of the injector

        for(std::shared_ptr<dot_lang::Queue> queue: it->second){
            double new_waiting_time= injector->getWaitingTime() + queue->getWaitingTime();
            injector->setWaitingTime(new_waiting_time);
        }
    }
}
}
