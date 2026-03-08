#pragma once

#include "DOTBaseVisitor.h"
#include "defines.h"
#include "Primitive.h"
#include "Node.h"
#include "network.h"
#include "node_factory.h"
#include "Mapping.h"

namespace dot_lang {
    class NodeVisitor : public DOTBaseVisitor {
    private:
        Network* network;
        NodeFactory nodeFactory;
	Mapping& mapping;

    public:
        NodeVisitor(Network* net, Mapping& m) : network(net), mapping(m) {}

        std::any visitNode_stmt(DOTParser::Node_stmtContext *ctx) override {
            // node_id node_attr_list
            // get id
            auto nodeName = visitNode_id(ctx->node_id());
	    std::string node_name = std::any_cast<std::string>(nodeName);
            // find type attribute in node_attr_list to create node:
            auto nodeType = std::any_cast<node_types>(visitType_(ctx->node_attr_list()->type_attr(0)->type_()));
	    std::string TypeAttribute = convertToString(nodeType);
	    SymbolTable[node_name]=TypeAttribute;
	    std::transform(TypeAttribute.begin(), TypeAttribute.end(), TypeAttribute.begin(),
                   [](unsigned char c) { return std::tolower(c); });
            // set node properties from node_attr_list
             std::map<std::string, std::string> attrs = std::any_cast<std::map<std::string, std::string>>(visitNode_attr_list(ctx->node_attr_list()));
	     attrs["type"] = TypeAttribute;

	     //type validation
	      std::string type = attrs["type"];
       	      auto schema = getNodeSchema(type);
	      if(type == "source" && attrs.find("cv") == attrs.end()){
          	  if(attrs.find("rate") == attrs.end()){
            		throw std::runtime_error("For '" + node_name + "' of type '" + type + "'requires 'rate' attribute");
            	  }
            	double rate = std::stod(attrs["rate"]);
            	double cv = 1.0 - rate;
            	attrs["cv"] = std::to_string(cv);
             }
       	     for(const auto &required_attr : schema.required) {
                if(attrs.find(required_attr) == attrs.end()){
                        throw std::runtime_error("For '" + node_name + "' missing required attribute: " + required_attr);
                }
	      }	
	     for(const auto &[key, _] : attrs){

		 //special handling for split type node
		 if(type == "split" && mapping.primitive_map.find(key)!=mapping.primitive_map.end() ){
			 continue;
		 }
                 if(schema.allowed.find(key)==schema.allowed.end()) {
                         throw std::runtime_error("For '" + node_name + "' attribute '" + key + "' is not allowed for type '" + type + "'");
                }
            }
	    
	     // create node
            std::shared_ptr<Node> node = nodeFactory.getNodeFromType(nodeType, std::any_cast<std::string>(nodeName), attrs, mapping);
	    
	    // create a Primitive
	    std::shared_ptr<Primitive> PrimitivePtr = std::dynamic_pointer_cast<Primitive>(node);
	    std::string PrimitiveName = std::any_cast<std::string>(nodeName);
	    mapping.primitive_map[PrimitiveName] = PrimitivePtr;
	    network -> addPrimitive(std::any_cast<std::string>(nodeName), PrimitivePtr);
            // add node to network
            network->addNode(node);

            return nullptr;
        }

	std::any visitGraph(DOTParser::GraphContext* ctx) override {
    	    return visitChildren(ctx);
       }

	std::any visitStmt_list(DOTParser::Stmt_listContext* ctx) override {
    	return visitChildren(ctx);
	}

	std::any visitStmt(DOTParser::StmtContext* ctx) override {
   	 return visitChildren(ctx);
	}

        std::any visitNode_id(DOTParser::Node_idContext *ctx) override {
            // id port
            // get id
            auto id = ctx->id_()->ID();
            return id->getText();
        }

        std::any visitType_(DOTParser::Type_Context *ctx) override {
            // type
            // type is a token from the grammar (SOURCE, QUEUE, ARBITER, SERVER, SINK)
            //   use token to determine node type
            if (ctx->SOURCE()) {
                return std::any(SOURCE);
            } else if (ctx->QUEUE()) {
                return std::any(QUEUE);
            } else if (ctx->ARBITER()) {
                return std::any(ARBITER);
            } else if (ctx->ROUNDROBIN()){
	        return std::any(ROUNDROBIN);
	    } else if (ctx->PRIORITY()){
		return std::any(PRIORITY);
            } else if (ctx->HYBRID()){
		return std::any(HYBRID);
	    }else if (ctx->SERVER()) {
                return std::any(SERVER);
	    } else if (ctx->SPLIT()) {
	        return std::any(SPLIT);
            } else if (ctx->SINK()) {
                return std::any(SINK);
            }
            return nullptr;
        }

      std::string convertToString(node_types type) {
    	switch (type) {
        	case SOURCE: return "SOURCE";
        	case QUEUE: return "QUEUE";
       	        case ARBITER: return "ARBITER";
	        case ROUNDROBIN: return "ROUNDROBIN";
		case PRIORITY: return "PRIORITY"; 
		case HYBRID: return "HYBRID";
        	case SERVER: return "SERVER";
	        case SPLIT: return "SPLIT";
        	case SINK: return "SINK";
        	default: return "UNKNOWN";
    }
}


        std::any visitNode_attr_list(DOTParser::Node_attr_listContext *ctx) {
            // node_attr_list
            // generic_attr* type_attr generic_attr*
            // get type_attr from ctx
	    std::map<std::string, std::string> attrs;
            // any generic_attr before or after type_attr, visit each:
            for (auto genericAttr : ctx->generic_attr()) {
		std::map<std::string, std::string> attributeValue  = std::any_cast<std::map<std::string, std::string>>(visitGeneric_attr(genericAttr));
		for (const auto& [key, value] : attributeValue) {
    		    // Optional: check for duplicate keys if needed
        	   if (attrs.find(key) != attrs.end()) {
            			std::cerr << "Warning: Duplicate attribute key '" << key << "' found. Overwriting previous value." << std::endl;
        		}
        		attrs[key] = value;
                }
	    }
	    return attrs;
        }

	std::any visitGeneric_attr(DOTParser::Generic_attrContext *ctx) {
            // generic_attr
            // attr_ cv_attr depth_attr priority_attr rate_attr
            // get attr from ctx
	    std::string key,value;
	    std::map<std::string, std::string>result;

            // any of the possible attribute may or may not exist
            auto priorityAttr = ctx->priority_attr() ? visitPriority_attr(ctx->priority_attr()) : std::any();
	    auto attr = ctx->attr_() ? visitAttr_(ctx->attr_()) : std::any();
            auto cvAttr = ctx->cv_attr() ? visitCv_attr(ctx->cv_attr()) : std::any();
            auto depthAttr = ctx->depth_attr() ? visitDepth_attr(ctx->depth_attr()) : std::any();
            //auto priorityAttr = ctx->priority_attr() ? visitPriority_attr(ctx->priority_attr()) : std::any();
            auto rateAttr = ctx->rate_attr() ? visitRate_attr(ctx->rate_attr()) : std::any();
	    auto serviceTimeAttr = ctx->service_time_attr() ? visitService_time_attr(ctx->service_time_attr()) : std::any();
	    auto coeffVarAttr = ctx->coeff_service_time_attr() ? visitCoeff_service_time_attr(ctx->coeff_service_time_attr()) : std::any();
	    auto zeroLoadAttr = ctx->zero_load_latency_attr() ? visitZero_load_latency_attr(ctx->zero_load_latency_attr()) : std::any();

            if (attr.has_value()) {
                std::cout << "attr: " << std::any_cast<std::string>(attr) << std::endl;
                // node->setAttribute(std::any_cast<std::string>(attr));
            }
            if (cvAttr.has_value()) {
		key = "cv";
	        value = std::any_cast<std::string>(cvAttr);
		result[key]=value;
            }
            if (depthAttr.has_value()) {
		key = "depth";
		value = std::any_cast<std::string>(depthAttr);
		result[key]=value;
            }
            if (priorityAttr.has_value()) {
                key = "priority_no";
		value = std::any_cast<std::string>(priorityAttr);
		result[key]=value;
            }
            if (rateAttr.has_value()) {
	        key = "rate";
	        value = std::any_cast<std::string>(rateAttr);
		result[key]=value;
            }
	    if (serviceTimeAttr.has_value()){
	        key = "t_serv";
	        value = std::any_cast<std::string>(serviceTimeAttr);
		result[key]=value;
            }
	    if (coeffVarAttr.has_value()){
	        key = "coeff_var";
	        value = std::any_cast<std::string>(coeffVarAttr);
		result[key]=value;
            }
	    if (zeroLoadAttr.has_value()){
	        key = "zero_load";
	        value = std::any_cast<std::string>(zeroLoadAttr);
		result[key]=value;
             }
	    if (ctx->split_attr()){
	    	auto splitPortPair = std::any_cast<std::pair<std::string,std::string>>(visitSplit_attr(ctx->split_attr()));
		result[splitPortPair.first] = splitPortPair.second;
	     }
	    if(ctx->map_attr()){
	    	auto splitProbabilityPair = std::any_cast<std::map<std::string, std::string>>(visitMap_attr(ctx->map_attr()));
		//result[splitProbabilityPair.first] = splitProbabilityPair.second;
		 for (const auto &[key, value] : splitProbabilityPair) {
        		result[key] = value;
    		}
	    }
	    
	return result;
	}	    
        std::any visitCv_attr(DOTParser::Cv_attrContext *ctx) override {
            // CV '=' NUMBER (';' | ',')?
            // get cv from ctx
            auto cv = ctx->NUMBER();
            return std::any(cv->getText());
        }

        std::any visitDepth_attr(DOTParser::Depth_attrContext *ctx) override {
            // DEPTH '=' NUMBER (';' | ',')?
            // get depth from ctx
            auto depth = ctx->NUMBER();
            return std::any(depth->getText());
        }

        std::any visitPriority_attr(DOTParser::Priority_attrContext *ctx) override {
            // PRIORITY '=' NUMBER (';' | ',')?
            // get priority from ctx
            auto priority = ctx->NUMBER()->getText();
            return priority;
        }

        std::any visitRate_attr(DOTParser::Rate_attrContext *ctx) override {
            // RATE '=' NUMBER (';' | ',')?
            // get rate from ctx
            auto rate = ctx->NUMBER();
            return std::any(rate->getText());
        }

        std::any visitService_time_attr(DOTParser::Service_time_attrContext *ctx) override {
	   //get t_serv from ctx
	   auto t_serv = ctx->NUMBER();
    	   return std::any(t_serv->getText());
  	}

       std::any visitCoeff_service_time_attr(DOTParser::Coeff_service_time_attrContext *ctx) override {
	   //get coeff_var from ctx
	   auto coeff_var = ctx->NUMBER();
    	   return std::any(coeff_var->getText());
  	}

       std::any visitZero_load_latency_attr(DOTParser::Zero_load_latency_attrContext *ctx) override {
	   //get zero_load from ctx
	   auto zero_load = ctx->NUMBER();
        return std::any(zero_load->getText());
  	}
   
 	std::any visitSplit_attr(DOTParser::Split_attrContext *ctx) override {
           
		std::string key = ctx->S_ATTR()->getText();
		std::string value = ctx->NUMBER()->getText();
		return std::make_pair(key,value);
 	  }
   
   	std::any visitMap_attr(DOTParser::Map_attrContext *ctx) override {
		std::string attrName = ctx->id_()->getText();
		std::map<std::string, std::string> probMapping;
	        for(auto pair:ctx->mapPair()){
		
			std:: string destination = pair->id_()->getText();
			std::string probability = pair->NUMBER()->getText();
			probMapping[destination] = probability;
		}
    	return probMapping;
      }


    };
}
