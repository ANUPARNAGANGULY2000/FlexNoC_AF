#include<WaitingTime.h>
#include<Injector.h>
#include<Queue.h>
#include<iostream>
#include<memory>
#include<Mapping.h>

void waiting_time_calc(){
    
    dot_lang::Mapping mapping;
    //iterate over the map to calculate waiting time of each injector
    for(auto it = mapping.queue_flow.cbegin(); it != mapping.queue_flow.cend(); ++it)
    {
	    std::shared_ptr<Injector> injector =it->first;
        //for every queue in the flow of the injector

        for(std::shared_ptr<Queue> queue: it->second){
            double new_waiting_time= injector->getWaitingTime() + queue->getWaitingTime();
            injector->setWaitingTime(new_waiting_time);
        }
    }
}
