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
#include "getUtils.h"
#include <random>
#include <vector>
#include <fstream>
#include <cassert>
#include <set>
#include <filesystem>
namespace fs = std::filesystem;

void DotFileProcess(std::string& fileName, double start_rate, double end_rate, double step){

   //Phase 1: Parsing & set data structure
   auto parse_start = std::chrono::high_resolution_clock::now();
   auto obj = new dot_lang::DOT(fileName);
   auto parse_end = std::chrono::high_resolution_clock::now();


   //track injector is going through which junction
   dot_lang::Mapping& mapping = obj->getMapping();
   for(auto iterator=mapping.junction_track.begin(); iterator!=mapping.junction_track.end(); ++iterator){
   	
	   std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(iterator -> first);
	   //std::vector<std::shared_ptr<dot_lang::Junc>> junction_list = iterator->second;
	   auto &junction_list = iterator->second;
	   std::shared_ptr<dot_lang::Junc> junction = std::dynamic_pointer_cast<dot_lang::Junc>(junction_list[0]);
	   model::trackJunction(injector, junction, mapping);
	   
   }
   
    int num_injectors = mapping.queue_flow.size();

    std::vector<std::vector<double>> latency_matrix;
    latency_matrix.resize(num_injectors);
   
    //phase 2:set injection_rate and coeff_inter_arrival_time
   auto model_exec_start = std::chrono::high_resolution_clock::now();

   std::vector<double> injection_rates;
   std::vector<std::shared_ptr<dot_lang::Injector>> injector_list;

	for(auto &it : mapping.queue_flow)
	{
    		injector_list.push_back(it.first);
	}
   
   for(double rate = start_rate; rate <= end_rate; rate += step){
	  
   for(int iteration=0; iteration<1; iteration++){
      
	   for(auto iter=mapping.primitive_map.begin();iter!=mapping.primitive_map.end();++iter){
	
		   //update injection process
        
		  if(iter->second->isInjector()){
                
			   std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(iter->second);
		
		
			   //if we don't modify injection rate
	       	
			   double injection_rate = injector->getInjectionRate();
                
			   double coeff_inter_arrival_time = injector->getCoeffInterArrivalTime();

               
				injector->setInjectionRate(rate);
                
			  	injector->setCoeffInterArrivalTime(1-rate);
               
			   model::update_connected_node(iter->first,mapping, rate);
			  // model::update_connected_node(iter->first,mapping, injection_rate);
		
        
		   }
	
		   // update Split probability of each direction
       
		   if(iter->second->isSplit()){

                
			   std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(iter->second);
                
			   std::map<std::string, double>SplitProbabilityMap = split->getSplitProbability();
               
			   double Probability;
               
			   for(auto sequence=SplitProbabilityMap.begin(); sequence!=SplitProbabilityMap.end(); ++sequence){

                        
				   std::string port = sequence->first;

			
				   //if user wants to update probability port wise
                        
				   //std::cout<<"Existing port: "<<port<<"\t enter new probability: ";
                        
				     //std::cin>>Probability;


			
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


   //for artifact evaluation
   injection_rates.push_back(rate);

	for(int i=0;i<injector_list.size();i++)
	{
    		double latency = injector_list[i]->getWaitingTime();
    		latency_matrix[i].push_back(latency);
	}
    //its done
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

 //  dot_lang::Mapping& mapping=obj->getMapping();

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
   }


//to write results in a  csv file
std::ofstream file("injector_latency.csv");

file << "InjectionRate";

for(int i=0;i<injector_list.size();i++)
{
    file << ",F" << i+1;
}

file << "\n";
for(int r=0;r<injection_rates.size();r++)
{
    file << injection_rates[r];

    for(int i=0;i<injector_list.size();i++)
    {
        file << "," << latency_matrix[i][r];
    }

    file << "\n";
}

file.close();

// Create result directory
std::string base = fileName;
size_t pos = base.find_last_of("/\\");
if(pos != std::string::npos)
    base = base.substr(pos + 1);

pos = base.find_last_of(".");
if(pos != std::string::npos)
    base = base.substr(0, pos);

std::string result_dir = "Results_" + base;

fs::create_directory(result_dir);

// Call python script to generate plots

for(int i = 0; i < injector_list.size(); i++)
{
    std::string injector_name = "F" + std::to_string(i+1);

    std::string command =
        "python3 ../scripts/plot_single_injector.py injector_latency.csv "
        + injector_name + " " + result_dir;

    int status = system(command.c_str());
	if(status != 0)
	{
    		std::cerr << "Plot generation failed for injector\n";
	}
}

//its done


   delete obj;
}

