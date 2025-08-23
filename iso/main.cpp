#include <iostream>
#include <chrono>
#include <memory>
#include <dot_compiler.h>
#include "setNetwork.h"
#include "WaitingTime.h"
#include "Mapping.h"
#include "Injector.h"
#include "Primitive.h"
#include "Queue.h"
#include "UpdateNodeQueue.h"
#include <random>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-dot-file>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];

   //Phase 1: Parsing
   auto parse_start = std::chrono::high_resolution_clock::now();
   auto obj = new dot_lang::DOT(file_path);  
   auto parse_end = std::chrono::high_resolution_clock::now();

   dot_lang::Mapping& mapping=obj->getMapping();
   
   /*for(auto iter=mapping.primitive_map.begin();iter!=mapping.primitive_map.end();++iter){
   	if(iter->second->isInjector()){
		std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(iter->second);
		//std::cout<<"\nInjector: "<<iter->first<<" last Injection rate: "<<injector->getInjectionRate()<<" Enter updated injection rate: ";
		//double injection_rate;
		//std::cin>>injection_rate;
		 std::random_device rd;
   		 std::mt19937 gen(rd());
    		 std::uniform_real_distribution<double> dist(0.0, 1.0);
    		double injection_rate = dist(gen);
		std::cout << injection_rate << std::endl;
		injector->setInjectionRate(injection_rate);
		injector->setCoeffInterArrivalTime(1-injection_rate);
		model::update_connected_node(iter->first,mapping, injection_rate);
	}
   
   }*/
   //phase 2: Forward + Backward Pass
    auto model_exec_start = std::chrono::high_resolution_clock::now();
    model::read_network(obj->getMapping());
    auto model_exec_end = std::chrono::high_resolution_clock::now();

    //phase 3: Aggregating waiting time
    auto model_agg_start = std::chrono::high_resolution_clock::now();
    model::waiting_time_calc(obj->getMapping());
    auto model_agg_end = std::chrono::high_resolution_clock::now();

    std::chrono::microseconds parsing_time = std::chrono::duration_cast<std::chrono::microseconds>(parse_end - parse_start);
    std::chrono::microseconds model_exec_time = std::chrono::duration_cast<std::chrono::microseconds>(model_exec_end - model_exec_start);
    std::chrono::microseconds model_agg_time = std::chrono::duration_cast<std::chrono::microseconds>(model_agg_end - model_agg_start);
    std::chrono::microseconds total_model_time = std::chrono::duration_cast<std::chrono::microseconds>(model_exec_time + model_agg_time);

    std::chrono::duration<double> parsing_time_in_sec = parse_end - parse_start;
    std::chrono::duration<double> model_exec_time_in_sec = model_exec_end - model_exec_start;
    std::chrono::duration<double> model_agg_time_in_sec = model_agg_end - model_agg_start;
    std::chrono::duration<double> total_model_time_in_sec = model_exec_time_in_sec + model_agg_time_in_sec;

    //Result Printing.
    //dot_lang::Mapping& mapping=obj->getMapping();
    for(auto it=mapping.primitive_map.begin();it!=mapping.primitive_map.end();++it){
	    
            if(it->second->isInjector()){

		    std::shared_ptr<dot_lang::Injector> F = std::dynamic_pointer_cast<dot_lang::Injector>(it->second);
		    std::cout<<"Injector: "<<it->first<<'\t'<<"Waiting time: "<<F->getWaitingTime()<<std::endl;
            }
            if(it->second->isQueue()){
		    std::shared_ptr<dot_lang::Queue> Q = std::dynamic_pointer_cast<dot_lang::Queue>(it->second);
		    std::cout<<"Queue: "<<it->first<<'\t'<<"Waiting time: "<<Q->getWaitingTime()<<std::endl;
            }

    }

    std::cout<<"Parsing Time: "<<parsing_time.count()<<" \u00B5s"<<std::endl;
    //std::cout<<"Model Execution Time:  "<<model_exec_time.count()<<" \u00B5s"<<std::endl;
    //std::cout<<"Waiting_Time Aggregation Time: "<<model_agg_time.count()<<" \u00B5s"<<std::endl;
    std::cout<<"Total Analytical Model Execution Time: "<<total_model_time.count()<<" \u00B5s"<<std::endl;

    std::cout<<"Parsing Time in sec: "<<parsing_time_in_sec.count()<<" second"<<std::endl;
    //std::cout<<"Model Execution Time in sec:  "<<model_exec_time_in_sec.count()<<" second"<<std::endl;
    //std::cout<<"Waiting_Time Aggregation Time: "<<model_agg_time_in_sec.count()<<" second"<<std::endl;
    std::cout<<"Total Analytical Model Execution Time: "<<total_model_time_in_sec.count()<<" second"<<std::endl;

    delete obj;
    return 0;
}
