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
#include "Split.h"
#include "UpdateNodeQueue.h"
#include <random>
#include <cassert>

void RunRegular(std::string& fileName){

   //Phase 1: Parsing & set data structure
   auto parse_start = std::chrono::high_resolution_clock::now();
   auto obj = new dot_lang::DOT(fileName);
   auto parse_end = std::chrono::high_resolution_clock::now();


   //phase 2:set injection_rate and coeff_inter_arrival_time
   auto model_exec_start = std::chrono::high_resolution_clock::now();
   
   for(int iteration=0; iteration<1; iteration++){
   

	   dot_lang::Mapping& mapping=obj->getMapping();
   
	   for(auto iter=mapping.primitive_map.begin();iter!=mapping.primitive_map.end();++iter){
	
		   //update injection process
        
		   if(iter->second->isInjector()){
                
			   std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(iter->second);
		
		
			   //if we don't modify injection rate
	       	
			   double injection_rate = injector->getInjectionRate();
                
			   double coeff_inter_arrival_time = injector->getCoeffInterArrivalTime();

               
			   injector->setInjectionRate(injection_rate);
                
			   injector->setCoeffInterArrivalTime(1-injection_rate);
               
			   model::update_connected_node(iter->first,mapping, injection_rate);
		
        
		   }
	
		   // update Split probability of each direction
       
		   if(iter->second->isSplit()){

                
			   std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(iter->second);
                
			   std::map<std::string, double>SplitProbabilityMap = split->getSplitProbability();
               
			   double Probability;
               
			   for(auto sequence=SplitProbabilityMap.begin(); sequence!=SplitProbabilityMap.end(); ++sequence){

                        
				   std::string port = sequence->first;

			
				   //if user wants to update probability port wise
                        
				   /*std::cout<<"Existing port: "<<port<<"\t enter new probability: ";
                        
				     std::cin>>Probability;*/


			
				   //if user don't want to change the probability
			
				   Probability = sequence->second;
                        
				   split->updateSplitProbability(port,Probability);
                }
              
			   double total_probability_sum = split->getProbabilitySum();
                
               
			   std::shared_ptr<dot_lang::Primitive> queue_pointer;
              
			   for(auto sequence_number=SplitProbabilityMap.begin(); sequence_number!=SplitProbabilityMap.end(); ++sequence_number){

                        
				   std::string port = sequence_number->first;
                       
				   Probability = sequence_number ->second;
                       
				   if(mapping.primitive_map.find(port)!=mapping.primitive_map.end()){
                                 
					   queue_pointer=mapping.primitive_map[port];
                        
				   }
                      
				   std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(queue_pointer);
                        
				   double total_injection_rate = split -> getInjectionRate();
                       
				   double new_injection_rate = total_injection_rate * Probability;
                       
				   queue -> setInjectionRate(new_injection_rate);
                      
				   double cv = 1 - total_injection_rate;
		
			   	   queue ->setCoeffInterArrivalTime(cv);
                
			   }
        
		   }

   
	   }
   
   
	   //phase 3: invoke analytical model
  
	   model::Invoke_analytical_model(obj->getMapping());


   
   }
   
  
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

   dot_lang::Mapping& mapping=obj->getMapping();

   for(auto it=mapping.primitive_map.begin();it!=mapping.primitive_map.end();++it){


            if(it->second->isInjector()){

		    std::shared_ptr<dot_lang::Injector> F = std::dynamic_pointer_cast<dot_lang::Injector>(it->second);
                    
		    std::cout<<"Injector: "<<it->first<<'\t'<<"Waiting time: "<<F->getWaitingTime()<<std::endl;
            }

	    if(it->second->isQueue()){

		    std::shared_ptr<dot_lang::Queue> Q = std::dynamic_pointer_cast<dot_lang::Queue>(it->second);

		    if(Q->getWaitingTime()<0){

			    double newValue = 0.0;

			    Q->setWaitingTime(newValue);
	
		    }
        
	
		    std::cout<<"Queue: "<<it->first<<'\t'<<"Waiting time: "<<Q->getWaitingTime()<<std::endl;
        
	    }


    
   }

  

   
   //std::cout<<"Parsing Time in sec: "<<parsing_time_in_sec.count()<<" second"<<std::endl;
  
   //std::cout<<"Total Analytical Model Execution Time: "<<total_model_time_in_sec.count()<<" second"<<std::endl;
   
 
   delete obj;
}

