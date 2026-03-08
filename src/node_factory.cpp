#include <node_factory.h>
#include <iostream>
#include "Primitive.h"
#include "Injector.h"
#include "Arbiter.h"
#include "Queue.h"
#include "Server.h"
#include "RoundRobin.h"
#include "Priority.h"
#include "Hybrid.h"
#include "Sink.h"
#include "Split.h"
#include <cassert>
#include <cmath>


namespace dot_lang
{

	std::shared_ptr<Node>
	NodeFactory::getNodeFromType(node_types _type, std::string name, std::map<std::string, std::string>& attributes, Mapping &mapping) {
    	std::shared_ptr<Node> node;
    	switch (_type) {
        	case SOURCE:
			{
			 double rate = std::stod(attributes.at("rate"));
                         double cv = std::stod(attributes.at("cv"));
            		 node = std::make_shared<Injector>(rate,cv,0.0);
			}
			 break;
       		 case SINK:{
			   node = std::make_shared<Sink>();
			   }
			   break;
	         case SPLIT:{
                           auto SplitPtr = std::make_shared<Split>();
                          if(SplitPtr){
				  std::shared_ptr<dot_lang::Primitive> primitive_out = nullptr;			
				  for(auto &[key,value] : attributes){
					  if (key == "type" || key == "shape")
           				     continue;
        				 if(mapping.primitive_map.find(key)!=mapping.primitive_map.end()){
                				primitive_out=mapping.primitive_map[key];
         				  }
				   if(primitive_out->isQueue()){
					double probability = std::stod(value);
					SplitPtr->addSplitProbability(key,probability);
					}
				  }
				  node = SplitPtr;
              
                            }
                           }
                           break;

        	 case QUEUE:
			 {
                         int depth = std::stod(attributes.at("depth"));
			 int priority = 0;
			 if( attributes.count("priority_no")){
				 priority=std::stod(attributes.at("priority_no"));
		         }
			 node = std::make_shared<Queue>(depth,0.0,0.0,0.0,priority);
			 }
           		 break;
        	case SERVER:
			 {
                           double t_serv = std::stod(attributes.at("t_serv"));
                           double coeff_var = std::stod(attributes.at("coeff_var"));
                           node = std::make_shared<Server>(t_serv,coeff_var);
                        }
		        break;
        	case ARBITER:
			{
                           double zero_load = std::stod(attributes.at("zero_load"));
                           node = std::make_shared<RoundRobinArbiter>(zero_load);
                        }
			break;
		case ROUNDROBIN:
                        {
                           double zero_load = std::stod(attributes.at("zero_load"));
                           node = std::make_shared<RoundRobinArbiter>(zero_load);
                        }
                        break;
		case HYBRID:
			{
			
				double zero_load = std::stod(attributes.at("zero_load"));
				node = std::make_shared<HybridArbiter>(zero_load);
			}
			break;
		case PRIORITY:
                        {
                           double zero_load = std::stod(attributes.at("zero_load"));
                           node = std::make_shared<PriorityArbiter>(zero_load);
                        }
                        break;

        	default:
            	node = std::make_shared<Injector>(0.05,0.91,0.0);
    	}
   	 if (!name.empty()) {
        	node->setName(name);
    	 }

	 if(node!=nullptr){
             std::shared_ptr<Primitive> PrimitivePtr = std::dynamic_pointer_cast<Primitive>(node);
             PrimitivePtr->activeFlag();
        }

    	return node;
	}
}

