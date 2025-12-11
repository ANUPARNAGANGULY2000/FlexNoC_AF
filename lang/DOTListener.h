
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "DOTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DOTParser.
 */
class  DOTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterGraph(DOTParser::GraphContext *ctx) = 0;
  virtual void exitGraph(DOTParser::GraphContext *ctx) = 0;

  virtual void enterStmt_list(DOTParser::Stmt_listContext *ctx) = 0;
  virtual void exitStmt_list(DOTParser::Stmt_listContext *ctx) = 0;

  virtual void enterStmt(DOTParser::StmtContext *ctx) = 0;
  virtual void exitStmt(DOTParser::StmtContext *ctx) = 0;

  virtual void enterAttr_stmt(DOTParser::Attr_stmtContext *ctx) = 0;
  virtual void exitAttr_stmt(DOTParser::Attr_stmtContext *ctx) = 0;

  virtual void enterAttr_list(DOTParser::Attr_listContext *ctx) = 0;
  virtual void exitAttr_list(DOTParser::Attr_listContext *ctx) = 0;

  virtual void enterNode_attr_list(DOTParser::Node_attr_listContext *ctx) = 0;
  virtual void exitNode_attr_list(DOTParser::Node_attr_listContext *ctx) = 0;

  virtual void enterEdge_attr_list(DOTParser::Edge_attr_listContext *ctx) = 0;
  virtual void exitEdge_attr_list(DOTParser::Edge_attr_listContext *ctx) = 0;

  virtual void enterGeneric_attr(DOTParser::Generic_attrContext *ctx) = 0;
  virtual void exitGeneric_attr(DOTParser::Generic_attrContext *ctx) = 0;

  virtual void enterCv_attr(DOTParser::Cv_attrContext *ctx) = 0;
  virtual void exitCv_attr(DOTParser::Cv_attrContext *ctx) = 0;

  virtual void enterService_time_attr(DOTParser::Service_time_attrContext *ctx) = 0;
  virtual void exitService_time_attr(DOTParser::Service_time_attrContext *ctx) = 0;

  virtual void enterCoeff_service_time_attr(DOTParser::Coeff_service_time_attrContext *ctx) = 0;
  virtual void exitCoeff_service_time_attr(DOTParser::Coeff_service_time_attrContext *ctx) = 0;

  virtual void enterSplit_attr(DOTParser::Split_attrContext *ctx) = 0;
  virtual void exitSplit_attr(DOTParser::Split_attrContext *ctx) = 0;

  virtual void enterZero_load_latency_attr(DOTParser::Zero_load_latency_attrContext *ctx) = 0;
  virtual void exitZero_load_latency_attr(DOTParser::Zero_load_latency_attrContext *ctx) = 0;

  virtual void enterDepth_attr(DOTParser::Depth_attrContext *ctx) = 0;
  virtual void exitDepth_attr(DOTParser::Depth_attrContext *ctx) = 0;

  virtual void enterPriority_attr(DOTParser::Priority_attrContext *ctx) = 0;
  virtual void exitPriority_attr(DOTParser::Priority_attrContext *ctx) = 0;

  virtual void enterRate_attr(DOTParser::Rate_attrContext *ctx) = 0;
  virtual void exitRate_attr(DOTParser::Rate_attrContext *ctx) = 0;

  virtual void enterMap_attr(DOTParser::Map_attrContext *ctx) = 0;
  virtual void exitMap_attr(DOTParser::Map_attrContext *ctx) = 0;

  virtual void enterMapPair(DOTParser::MapPairContext *ctx) = 0;
  virtual void exitMapPair(DOTParser::MapPairContext *ctx) = 0;

  virtual void enterType_attr(DOTParser::Type_attrContext *ctx) = 0;
  virtual void exitType_attr(DOTParser::Type_attrContext *ctx) = 0;

  virtual void enterType_(DOTParser::Type_Context *ctx) = 0;
  virtual void exitType_(DOTParser::Type_Context *ctx) = 0;

  virtual void enterA_list(DOTParser::A_listContext *ctx) = 0;
  virtual void exitA_list(DOTParser::A_listContext *ctx) = 0;

  virtual void enterAttr_(DOTParser::Attr_Context *ctx) = 0;
  virtual void exitAttr_(DOTParser::Attr_Context *ctx) = 0;

  virtual void enterEdge_stmt(DOTParser::Edge_stmtContext *ctx) = 0;
  virtual void exitEdge_stmt(DOTParser::Edge_stmtContext *ctx) = 0;

  virtual void enterEdgeRHS(DOTParser::EdgeRHSContext *ctx) = 0;
  virtual void exitEdgeRHS(DOTParser::EdgeRHSContext *ctx) = 0;

  virtual void enterEdgeop(DOTParser::EdgeopContext *ctx) = 0;
  virtual void exitEdgeop(DOTParser::EdgeopContext *ctx) = 0;

  virtual void enterNode_stmt(DOTParser::Node_stmtContext *ctx) = 0;
  virtual void exitNode_stmt(DOTParser::Node_stmtContext *ctx) = 0;

  virtual void enterNode_id(DOTParser::Node_idContext *ctx) = 0;
  virtual void exitNode_id(DOTParser::Node_idContext *ctx) = 0;

  virtual void enterPort(DOTParser::PortContext *ctx) = 0;
  virtual void exitPort(DOTParser::PortContext *ctx) = 0;

  virtual void enterSubgraph(DOTParser::SubgraphContext *ctx) = 0;
  virtual void exitSubgraph(DOTParser::SubgraphContext *ctx) = 0;

  virtual void enterId_(DOTParser::Id_Context *ctx) = 0;
  virtual void exitId_(DOTParser::Id_Context *ctx) = 0;


};

