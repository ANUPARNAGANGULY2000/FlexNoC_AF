#include <node_factory.h>
#include <iostream>
#include "Primitive.h"
#include "Injector.h"
#include "Arbiter.h"
#include "Queue.h"
#include "Server.h"
#include "RoundRobin.h"
#include "Priority.h"
#include "Sink.h"

namespace dot_lang
{

	std::shared_ptr<Node>
	NodeFactory::getNodeFromType(node_types _type, std::string name, std::map<std::string, std::string>& attributes) {
    	std::shared_ptr<Node> node;
    	switch (_type) {
        	case SOURCE:
			{
			 double rate = std::stod(attributes.at("rate"));
                         double cv = std::stod(attributes.at("cv"));
            		 node = std::make_shared<Injector>(rate,cv,0.0);
			 /*if(node){
			 	 std::cout<<"created an Injector: "<<name<<std::endl;
			 }*/
			}
			 break;
       		 case SINK:{
			   node = std::make_shared<Sink>();
			  /* if(node){
			   	std::cout<<"created a Sink"<<std::endl;
			    }*/
			   }
			   break;
        	 case QUEUE:
			 {
                         int depth = std::stod(attributes.at("depth"));
			 node = std::make_shared<Queue>(depth,0.0,0.0,0.0);
			 /*if(node){
                                 std::cout<<"created a Queue: "<<name<<std::endl;
                          }*/
			 }
           		 break;
        	case SERVER:
			 {
                           double t_serv = std::stod(attributes.at("t_serv"));
                           double coeff_var = std::stod(attributes.at("coeff_var"));
                           node = std::make_shared<Server>(t_serv,coeff_var);
                           /*if(node){
                                  std::cout<<"created a server: "<<name<<std::endl;
                          }*/
                        }
		        break;
        	case ARBITER:
			{
                           double zero_load = std::stod(attributes.at("zero_load"));
                           node = std::make_shared<RoundRobinArbiter>(zero_load);
                           /*if(node){
                                  std::cout<<"created an arbiter: "<<name<<std::endl;
                           }*/
                        }
			break;
		case ROUNDROBIN:
                        {
                           double zero_load = std::stod(attributes.at("zero_load"));
                           node = std::make_shared<RoundRobinArbiter>(zero_load);
                           /*if(node){
                                  std::cout<<"created an roundrobin arbiter: "<<name<<std::endl;
                           }*/
                        }
                        break;
		case PRIORITY:
                        {
                           double zero_load = std::stod(attributes.at("zero_load"));
                           node = std::make_shared<PriorityArbiter>(zero_load);
                           /*if(node){
                                  std::cout<<"created an priority arbiter: "<<name<<std::endl;
                           }*/
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

