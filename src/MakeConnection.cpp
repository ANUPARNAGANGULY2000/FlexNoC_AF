#include<MakeConnection.h>
#include<iostream>
#include<algorithm>
#include<Primitive.h>
#include<Junction.h>
#include<Server.h>
#include<Priority.h>
#include<RoundRobin.h>
#include<Hybrid.h>
#include<Queue.h>
#include<SingleQueue.h>
#include<Split.h>
#include "getUtils.h"

namespace dot_lang{

void MakeConnection::create_connection(const std::string &node_name,const std::string &source, const std::string &destination, Mapping &mapping){

	std::shared_ptr<dot_lang::Primitive> primitive_out = nullptr;
        std::shared_ptr<dot_lang::Primitive> primitive_in = nullptr;
        double injection_rate=0.0;
        double coeff_interarrival_time=0.0;


	 //if source is already present just make the pointers to the node
         if(mapping.primitive_map.find(source)!=mapping.primitive_map.end()){
               primitive_in=mapping.primitive_map[source];
         }

            //if destination is already present just make pointers to them
         if(mapping.primitive_map.find(destination)!=mapping.primitive_map.end()){
                primitive_out=mapping.primitive_map[destination];
         }

	 //check for the primitives in the flow of injector
         auto iter = mapping.primitive_flow.find(primitive_in);
            //if present
            if(iter!=mapping.primitive_flow.end()){
                //if present and also it is a queue then add it to queue_flow map
                if(primitive_in->isQueue()){
                   std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(mapping.primitive_flow[primitive_in]);
                    if(injector){
			    std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_in);
                        if(queue){
                                auto& queues =mapping.queue_flow[injector];
                                if(std::find(queues.begin(),queues.end(),queue)==queues.end()){
                                         (mapping.queue_flow[injector]).push_back(queue);
                                }
                         }
                    }
                }
            }

	     //injection_rate and coeff_interrarrival_times for node obtained from that of injector
          if(primitive_in->isInjector()){
             std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(primitive_in);
                if(injector){
                    injection_rate = injector->getInjectionRate();
                    coeff_interarrival_time = injector->getCoeffInterArrivalTime();
                }
                //map the injector to the next primitive
                mapping.primitive_flow[primitive_out]=injector;
            }
            else if(!primitive_in->isInjector()){
                //also in each case update the next primitive
                mapping.primitive_flow[primitive_out]=mapping.primitive_flow[primitive_in];
            }

            //create the node
	    std::shared_ptr<dot_lang::Junc> node = std::make_shared<dot_lang::Junc>(primitive_in, primitive_out, injection_rate, coeff_interarrival_time);
            //update the node_data here
            mapping.node_data[node_name]=node;


            //update the node_connections
            mapping.node_connections[source]=node_name;
            mapping.node_connections[node_name]=destination;
	    
	    //for Q,PR,RR,M
              if(!primitive_in->isInjector()){
		      std::shared_ptr<dot_lang::Junc> node_in = nullptr;
                      //iterate over node_connections
                      for(auto it = mapping.node_connections.begin(); it!=mapping.node_connections.end(); it++){
                        if(it->second == source){
				std::string key = it->first;
                                auto node_name = mapping.node_data.find(key);
                                if(node_name != mapping.node_data.end()){
                                        node_in = node_name->second;
                                        mapping.node_files[node_in]=node;
                                }
                         }
                      }
               }
         if(primitive_in->isInjector() && primitive_out->isQueue()){
              std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
               if(queue){
                  queue->setInjectionRate(injection_rate);
                  queue->setCoeffInterArrivalTime(coeff_interarrival_time);
                  node->setInjectionRate(injection_rate);
                  node->setCoeffInterArrivalTime(coeff_interarrival_time);
               }
         }  
	if(primitive_in->isRRarbiter() || primitive_in->isPRarbiter() || primitive_in->isHybridArbiter() && primitive_out->isServer()){
              std::shared_ptr<dot_lang::Server> server =  std::dynamic_pointer_cast<dot_lang::Server>(primitive_out);
              if(server){
                  double service_time=0.0;
                  double coeff_service_time=0.0;
                  service_time = server->getServiceTime();
                  coeff_service_time = server->getCoeffServiceTime();
                   if(primitive_in->isPRarbiter()){
			   std::shared_ptr<dot_lang::PriorityArbiter> PrArbiter = std::dynamic_pointer_cast<dot_lang::PriorityArbiter>(primitive_in);
                           PrArbiter->setServiceTime(service_time);
                           PrArbiter->setCoeffServiceTime(coeff_service_time);
                    }
		   else if(primitive_in->isHybridArbiter()){
		   
			   std::shared_ptr<dot_lang::HybridArbiter> HybridArbiter = std::dynamic_pointer_cast<dot_lang::HybridArbiter>(primitive_in);
			   HybridArbiter->setServiceTime(service_time);
			   HybridArbiter->setCoeffServiceTime(coeff_service_time);
		   }
                   else if(primitive_in->isRRarbiter()){
			   std::shared_ptr<dot_lang::RoundRobinArbiter> RRarbiter = std::dynamic_pointer_cast<dot_lang::RoundRobinArbiter>(primitive_in);
                           RRarbiter->setServiceTime(service_time);
                           RRarbiter->setCoeffServiceTime(coeff_service_time);
                    } 

             }  
            mapping.server_track[destination]=source;
             //setting average injection rate and coeff_inter_arrival_time to the node.
            std::string key=source;
           double avg_injection_rate = 0.0,injection_rates=0.0;
           double avg_coeff_inter_arrival_time = 0.0,coeff_inter_arrival_times=0.0;
	   std::vector<double>injection_rates_list;
	   std::vector<double>coeff_inter_arrival_time_list;
	   std::vector<double>merged_flows;
          auto it =  mapping.node_names.find(key);
          if(it!=mapping.node_names.end()){
		  std::vector<std::string>& node_name = it->second;
                  for(const auto& nodes:node_name){
                        auto node_it = mapping.node_data.find(nodes);
                        if(node_it!=mapping.node_data.end()){
				std::shared_ptr<dot_lang::Junc> N = node_it->second;
                                injection_rates = N->getInjectionRate();
                                coeff_inter_arrival_times = N->getCoeffInterArrivalTime();
                                 injection_rates_list.push_back(injection_rates);
                                coeff_inter_arrival_time_list.push_back(coeff_inter_arrival_times);

                        }
                }
		 merged_flows = Merging_flow(injection_rates_list,coeff_inter_arrival_time_list);
                        avg_injection_rate = merged_flows[0];
                        avg_coeff_inter_arrival_time = merged_flows[1];
                        node->setInjectionRate(avg_injection_rate);
                        node->setCoeffInterArrivalTime(avg_coeff_inter_arrival_time);

        }

      }
     if(primitive_in->isQueue() && primitive_out->isRRarbiter() || primitive_out->isPRarbiter() || primitive_out->isHybridArbiter() || primitive_out->isServer()){
	     std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_in);
            if(queue){
                    injection_rate = queue->getInjectionRate();
                    coeff_interarrival_time = queue->getCoeffInterArrivalTime();
                    node->setInjectionRate(injection_rate);
                    node->setCoeffInterArrivalTime(coeff_interarrival_time);
            }
    }
    if(primitive_in->isServer() && primitive_out->isSplit()){
    
	    
	    std::string prevNode = model::getConnectedNode(source, mapping);
	    std::shared_ptr<dot_lang::Junc> junction_address = mapping.node_data[prevNode];
	    std::shared_ptr<dot_lang::Primitive> Primitive_in_ptr = junction_address->getPrimitiveIn();
	    if(Primitive_in_ptr->isQueue()){
	    std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(Primitive_in_ptr);
	    double injection_rate = queue->getInjectionRate();
	    std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(primitive_out);
	    split->setInjectionRate(injection_rate);
	    double split_total = split->getInjectionRate();
	    }
	    
    }
    //Single Queue is Connected with server
    if(primitive_in->isQueue() && primitive_out->isServer()){
	    std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_in);
	    std::shared_ptr<dot_lang::Server> server = std::dynamic_pointer_cast<dot_lang::Server>(primitive_out);
            if(queue && server){
                double injection_rate = queue->getInjectionRate();
                double coeff_inter_arrival_rate = queue->getCoeffInterArrivalTime();
                node->setInjectionRate(injection_rate);
                node->setCoeffInterArrivalTime(coeff_inter_arrival_rate);
                double service_time = server->getServiceTime();
                double waiting_time = model::single_queue_waiting_time(injection_rate,service_time);
                queue->setWaitingTime(waiting_time);
            }
            mapping.server_track[destination]=source;
    }
    if(primitive_in->isServer() && primitive_out->isMerge()){
        for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();it++){
                if(it->second==source){
                auto& nodes = it->first;
		std::shared_ptr<dot_lang::Junc> node_address = mapping.node_data[nodes];
                injection_rate = node_address->getInjectionRate();
                coeff_interarrival_time = node_address->getCoeffInterArrivalTime();
                node->setInjectionRate(injection_rate);
                node->setCoeffInterArrivalTime(coeff_interarrival_time);

                }
        }
    }
    if(primitive_out->isRRarbiter() ||primitive_out->isPRarbiter() || primitive_out->isHybridArbiter() ||primitive_out->isMerge()){
        //for RR,PR,M extract nodes which have them as destination primitive
        for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();it++){
            if(it->second==destination){
                    auto& nodes = mapping.node_names[destination];
                    //check if that node is already added to the list of the queues
                    if(find(nodes.begin(),nodes.end(),it->first)==nodes.end()){
                       mapping.node_names[destination].push_back(it->first);
               }
            }
        }
    }
     //for split extract nodes which have them as source primitive
    if(primitive_in->isSplit()){
        for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();it++){
            if(it->first==source){
                mapping.node_names[source].push_back(it->second);
            }
        }
    }

    if(primitive_in->isSplit() && primitive_out->isQueue()){
    
	    std::shared_ptr<dot_lang::Split> split = std::dynamic_pointer_cast<dot_lang::Split>(primitive_in);
	    std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
	    std::map<std::string, double >SplitProbabilityMap = split->getSplitProbability();
	    double total_injection_rate = split -> getInjectionRate();
	    auto directional_buffer = SplitProbabilityMap.find(destination);
	    if(directional_buffer != SplitProbabilityMap.end()){
	    
		    double probability = directional_buffer->second;
		    double new_injection_rate = total_injection_rate * probability;
		    double coeff_var = 1 - new_injection_rate;
		    queue -> setInjectionRate(new_injection_rate);
		    queue -> setCoeffInterArrivalTime(coeff_var);
		    double inj = queue -> getInjectionRate();
		    
	    }
    }
    //if(primitive_in->isRRarbiter() ||primitive_in->isPRarbiter() || primitive_in->isMerge() || primitive_in->isSplit() && primitive_out->isQueue()){
     if(primitive_in->isServer() || primitive_in->isMerge() || primitive_in->isSplit() && primitive_out->isQueue()){
	   
	     std::string key = source;
             if(primitive_in->isServer()){
                     auto iter = mapping.server_track.find(source);
                     if(iter!=mapping.server_track.end()){
                        key = iter->second;
                     }
              }
            //auto it=node_names.find(source);
            auto it = mapping.node_names.find(key);
            double avg_injection_rate =0.0;
            double avg_coeff_interarrival_time=0.0;
	    std::vector<double> injection_rates;
	    std::vector<double> coeff_inter_arrival_time;
	    std::vector<double> merged_flows;

            //new function implementation start
	    std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
            for(auto itr=mapping.node_files.begin();itr!=mapping.node_files.end();++itr){
                if(itr->second == node){
			std::shared_ptr<dot_lang::Junc> prev_node = itr->first;
			MakeConnection::back_tracking(prev_node,queue,mapping);
                }
            }
	   if(it!=mapping.node_names.end()){
		   std::vector<std::string> &node_name = it->second;
                    for(const auto& nodes:node_name){
                        auto node_it = mapping.node_data.find(nodes);
                        if(node_it != mapping.node_data.end()){
				std::shared_ptr<dot_lang::Junc> N= node_it->second;
                                injection_rate = N->getInjectionRate();
                                coeff_interarrival_time = N->getCoeffInterArrivalTime();
                                injection_rates.push_back(injection_rate);
                                coeff_inter_arrival_time.push_back(coeff_interarrival_time);
                        }
                        merged_flows = MakeConnection::Merging_flow(injection_rates,coeff_inter_arrival_time);
                        avg_injection_rate = merged_flows[0];
                        avg_coeff_interarrival_time = merged_flows[1];
                //go to node_connection and check whose second part is that node
                for(auto it=mapping.node_connections.begin();it!=mapping.node_connections.end();it++){
                        //get the first part of that node
                        if(it->second==nodes){
				std::string connected_queue = it->first;
				std::shared_ptr<dot_lang::Primitive> Primitive_ptr = mapping.primitive_map[connected_queue];
                                //just check if it is a queue
			       if(Primitive_ptr->isQueue()){
                                // if it is a queue then check the primitive flow and get the corresponding injection rate.

					std::shared_ptr<dot_lang::Primitive> primitive_new=mapping.primitive_map[connected_queue];
                                                if(primitive_new){
							std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(mapping.primitive_flow[primitive_new]);
                                                        if(injector){
                                                                auto& queues = mapping.queue_flow[injector];
								std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
                                                                if(queue && std::find(queues.begin(),queues.end(),queue)==queues.end()){
                                                                                        mapping.queue_flow[injector].push_back(queue);

                                                                                }

                                                                        }
                                                                }
                         }
                        }
                        }
                        }
                    node->setInjectionRate(avg_injection_rate);
                    node->setCoeffInterArrivalTime(avg_coeff_interarrival_time);
		    std::shared_ptr<dot_lang::Queue> queue = std::dynamic_pointer_cast<dot_lang::Queue>(primitive_out);
                    if(queue && avg_injection_rate != 0.0){
                            queue->setInjectionRate(avg_injection_rate);
                            queue->setCoeffInterArrivalTime(avg_coeff_interarrival_time);
                    }

            }


    }
    
}

//Merging the flows
std::vector<double> MakeConnection::Merging_flow(std::vector<double>injection_rates,std::vector<double>coeff_inter_arrival_time){
	std::vector<double> merging_flow;
        double avg_injection_rate =0.0;
        double avg_coeff_inter_arrival_time=0.0;
        for(int i=0;i<injection_rates.size();++i){
                avg_injection_rate += injection_rates[i];
                avg_coeff_inter_arrival_time += (injection_rates[i] * coeff_inter_arrival_time[i]);
        }
        avg_coeff_inter_arrival_time = avg_coeff_inter_arrival_time / avg_injection_rate ;
        merging_flow.push_back(avg_injection_rate);
        merging_flow.push_back(avg_coeff_inter_arrival_time);
return merging_flow;
}


//back tracking the nodes
void MakeConnection::back_tracking(std::shared_ptr<dot_lang::Junc> node, std::shared_ptr<dot_lang::Queue> queue, Mapping &mapping){

	std::shared_ptr<dot_lang::Primitive> primitive_in = node->getPrimitiveIn();
	std::string injector_name;
        for(auto it=mapping.primitive_map.begin();it!= mapping.primitive_map.end();++it){
                if(it->second == primitive_in){
                        injector_name = it->first;
                        break;
                }
        }
        if(injector_name[0]=='F'){
		std::shared_ptr<dot_lang::Injector> injector = std::dynamic_pointer_cast<dot_lang::Injector>(primitive_in);
                if(injector){
                        auto& queues = mapping.queue_flow[injector];
                        if(queue && std::find(queues.begin(),queues.end(),queue)==queues.end()){
                                mapping.queue_flow[injector].push_back(queue);
                        }
                }
        }
        else{
                for(auto it=mapping.node_files.begin();it!=mapping.node_files.end();++it){
                        if(it->second == node){
				std::shared_ptr<dot_lang::Junc> prev_node = it->first;
				MakeConnection::back_tracking(prev_node, queue,mapping);
                        }
                }
        }
}
}
