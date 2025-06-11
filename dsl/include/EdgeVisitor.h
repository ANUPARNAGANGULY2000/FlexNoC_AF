#pragma once

#include "DOTBaseVisitor.h"
#include "defines.h"
#include "Node.h"
#include "network.h"
#include "Junction.h"
#include "TypeCheckVisitor.h"
#include "MakeConnection.h"
#include "Mapping.h"

namespace dot_lang {
    class EdgeVisitor : public DOTBaseVisitor {
    private:
        Network* network;
	Mapping& mapping;

    public:
        EdgeVisitor(Network* net, Mapping& m) : network(net), mapping(m) {}

	 std::any visitEdge_stmt(DOTParser::Edge_stmtContext *ctx) override {
		std::string source, destination;
		auto node_id = ctx->node_id();
		if(node_id){
			source = node_id->getText();
			//std::cout<<"source: "<<source<<std::endl;
		}

		auto edgeRHS = ctx->edgeRHS();
		if(edgeRHS){
			auto RHSnodes = edgeRHS->children;
			for(size_t index = 0; index<RHSnodes.size(); ++index){
				auto nodeIdCtx =  dynamic_cast<DOTParser::Node_idContext* >(RHSnodes[index]);
				if(nodeIdCtx){
					destination = nodeIdCtx->id_()->getText();
					 //std::cout<<"destination: "<<destination<<std::endl;
				}
			}
			
		}

		 std::string JunctionName = Junc::generateJunctionName();
		 MakeConnection::create_connection(JunctionName,source,destination,mapping);
		 auto srcIt = SymbolTable.find(source);
		 auto dstIt = SymbolTable.find(destination);
		 if(srcIt!=SymbolTable.end() && dstIt!=SymbolTable.end()){
		        TypeCheckVisitor::isValidConnection(srcIt->second, dstIt->second);
			 
		 }
		 else if(srcIt==SymbolTable.end() || dstIt==SymbolTable.end()){
			 if(srcIt == SymbolTable.end()){
		 	      std::cerr<<"Error: "<<"source is not declared "<<std::endl;
	                      assert(false);
			 }
			 if(dstIt == SymbolTable.end()){
			    std::cerr<<"Error: "<<"destination is not declared "<<std::endl;
                              assert(false);
			 }
		 }
		return nullptr;
	 }

    };
}
