
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "DOTVisitor.h"


/**
 * This class provides an empty implementation of DOTVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DOTBaseVisitor : public DOTVisitor {
public:

  virtual std::any visitGraph(DOTParser::GraphContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt_list(DOTParser::Stmt_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(DOTParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttr_stmt(DOTParser::Attr_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttr_list(DOTParser::Attr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_attr_list(DOTParser::Node_attr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdge_attr_list(DOTParser::Edge_attr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeneric_attr(DOTParser::Generic_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCv_attr(DOTParser::Cv_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitService_time_attr(DOTParser::Service_time_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCoeff_service_time_attr(DOTParser::Coeff_service_time_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSplit_attr(DOTParser::Split_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitZero_load_latency_attr(DOTParser::Zero_load_latency_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDepth_attr(DOTParser::Depth_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPriority_attr(DOTParser::Priority_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRate_attr(DOTParser::Rate_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMap_attr(DOTParser::Map_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapPair(DOTParser::MapPairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_attr(DOTParser::Type_attrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_(DOTParser::Type_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitA_list(DOTParser::A_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttr_(DOTParser::Attr_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdge_stmt(DOTParser::Edge_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeRHS(DOTParser::EdgeRHSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeop(DOTParser::EdgeopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_stmt(DOTParser::Node_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_id(DOTParser::Node_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPort(DOTParser::PortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubgraph(DOTParser::SubgraphContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId_(DOTParser::Id_Context *ctx) override {
    return visitChildren(ctx);
  }


};

