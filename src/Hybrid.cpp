#include "Hybrid.h"
#include <iostream>
#include "PriorityModel.h"
#include "RoundRobinModel.h"
#include "MakeConnection.h"
#include <unordered_map>
#include "UpdateNodeQueue.h"
#include<vector>
#include<memory>

dot_lang::HybridArbiter::HybridArbiter(double zero_load_latency)
    : dot_lang::Arbiter(zero_load_latency) {}

bool dot_lang::HybridArbiter::isRRarbiter() const { return false; }
bool dot_lang::HybridArbiter::isSplit() const { return false; }
bool dot_lang::HybridArbiter::isServer() const { return false; }
bool dot_lang::HybridArbiter::isQueue() const { return false; }
bool dot_lang::HybridArbiter::isInjector() const { return false; }
bool dot_lang::HybridArbiter::isArbiter() const { return isActive; }
bool dot_lang::HybridArbiter::isMerge() const { return false; }
bool dot_lang::HybridArbiter::isSink() const { return false; }
bool dot_lang::HybridArbiter::isHybridArbiter() const { return isActive; }
bool dot_lang::HybridArbiter::isPRarbiter() const { return false; }

void dot_lang::HybridArbiter::activeFlag() { isActive = true; }

void dot_lang::HybridArbiter::arbiter(Mapping& mapping) {

     	std::vector<std::shared_ptr<Queue>> queues_Priority_arbiter;
    	std::vector<std::shared_ptr<Queue>> queues_RoundRobin_arbiter;
	std::vector<std::shared_ptr<Queue>> Queues;
    	std::shared_ptr<HybridArbiter> Hybrid_Arbiter = nullptr;
    	std::unordered_map<int, std::vector<std::shared_ptr<Queue>>>QueuePriorityList;
        
	int priorityR = 0;

	for (const auto& junc : junction) {
            std::shared_ptr<Queue> queue_in = std::dynamic_pointer_cast<Queue>(junc->getPrimitiveIn());
            if (queue_in) {
		 Queues.push_back(queue_in);
	    	int priority_of_Queue = queue_in->getPriorityValue();
	    	QueuePriorityList[priority_of_Queue].push_back(queue_in);
             }
	      Hybrid_Arbiter = std::dynamic_pointer_cast<HybridArbiter>(junc->getPrimitiveOut());
    	}
    	if (!Hybrid_Arbiter) {
            throw std::runtime_error("HybridArbiter is required");
    	}
   
    	double service_time = Hybrid_Arbiter->getServiceTime();
    	double zero_load = Hybrid_Arbiter->getZeroLoadLatency();
  
	std::unordered_map<int, std::shared_ptr<Queue>> VirtualQueueList;

	//for each priority list
   	for(auto& [priority,queues]:QueuePriorityList){
   	   if(queues.size() == 1){
	   	   queues_Priority_arbiter.push_back(queues[0]);

	   }else{
		   std::vector<double> injection_rates;
        	   std::vector<double> coeff_inter_arrival_times;
	   	 for(auto& q:queues){
		   	   queues_RoundRobin_arbiter.push_back(q);
			   injection_rates.push_back(q->getInjectionRate());
			   coeff_inter_arrival_times.push_back(q->getCoeffInterArrivalTime());
			   
		 }

		  //merging the same priority queue
		  std::vector<double> merge_flow = dot_lang::MakeConnection::Merging_flow(injection_rates, coeff_inter_arrival_times);
                  auto virtual_queue = std::make_shared<Queue>(1,0.0,merge_flow[0],merge_flow[1],priority);
		  VirtualQueueList[priority] = virtual_queue;
		  queues_Priority_arbiter.push_back(virtual_queue);

	   }
        }
	
        if(!queues_RoundRobin_arbiter.empty()){
      		  model::roundrobin_model(queues_RoundRobin_arbiter, service_time, zero_load, mapping);
        }
       if(!queues_Priority_arbiter.empty()){
	        //bubble sort by priority
		for(size_t i=0; i<queues_Priority_arbiter.size(); ++i){
		
			for(size_t j=0; j<queues_Priority_arbiter.size() - i - 1; ++j){
			
				int priority1 = queues_Priority_arbiter[j]->getPriorityValue();
				int priority2 = queues_Priority_arbiter[j+1]->getPriorityValue();

				if(priority1 > priority2){
				
					std::swap(queues_Priority_arbiter[j], queues_Priority_arbiter[j+1]);
				}
			}
		}
                model::priority_model(queues_Priority_arbiter, service_time, zero_load, mapping);
       }

       for(auto& [priority,queues]:QueuePriorityList){
       
	       if(queues.size() == 1) continue;

	       auto virtualQueue = VirtualQueueList[priority];
	       double waitingTime = virtualQueue->getWaitingTime();

	       for(auto& queue:queues){
		       double WaitingTimeOfQueue = queue->getWaitingTime() + waitingTime;
		       queue->setWaitingTime(WaitingTimeOfQueue);

	       }
       }
     
      model::update_node_from_Queue(Queues, mapping);

}

std::vector<double> dot_lang::HybridArbiter::primitive() {
    return {};
}

double dot_lang::HybridArbiter::getZeroLoadLatency() {
    return zero_load_latency;
}

void dot_lang::HybridArbiter::setZeroLoadLatency(double& new_zero_load_latency) {
    zero_load_latency = new_zero_load_latency;
}

void dot_lang::HybridArbiter::setServiceTime(double& new_service_time) {
    service_time = new_service_time;
}

double dot_lang::HybridArbiter::getServiceTime() {
    return service_time;
}

void dot_lang::HybridArbiter::setCoeffServiceTime(double& new_coeff_service_time) {
    coeff_service_time = new_coeff_service_time;
}

double dot_lang::HybridArbiter::getCoeffServiceTime() {
    return coeff_service_time;
}
std::string dot_lang::HybridArbiter::getGraphVizProperties() {
     std::string label = "label=\"ID: " + std::to_string(getID()) + " | zero_load: " + std::to_string(zero_load_latency) + "\"";
    return label + ", " + _shape() + ", zero_load=" + std::to_string(zero_load_latency);
}
std::string dot_lang::HybridArbiter::_shape() {
    return "shape=\"diamond\"";
}

