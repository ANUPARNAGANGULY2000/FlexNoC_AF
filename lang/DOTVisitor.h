
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "DOTParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by DOTParser.
 */
class  DOTVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DOTParser.
   */
    virtual std::any visitGraph(DOTParser::GraphContext *context) = 0;

    virtual std::any visitStmt_list(DOTParser::Stmt_listContext *context) = 0;

    virtual std::any visitStmt(DOTParser::StmtContext *context) = 0;

    virtual std::any visitAttr_stmt(DOTParser::Attr_stmtContext *context) = 0;

    virtual std::any visitAttr_list(DOTParser::Attr_listContext *context) = 0;

    virtual std::any visitNode_attr_list(DOTParser::Node_attr_listContext *context) = 0;

    virtual std::any visitEdge_attr_list(DOTParser::Edge_attr_listContext *context) = 0;

    virtual std::any visitGeneric_attr(DOTParser::Generic_attrContext *context) = 0;

    virtual std::any visitCv_attr(DOTParser::Cv_attrContext *context) = 0;

    virtual std::any visitService_time_attr(DOTParser::Service_time_attrContext *context) = 0;

    virtual std::any visitCoeff_service_time_attr(DOTParser::Coeff_service_time_attrContext *context) = 0;

    virtual std::any visitSplit_attr(DOTParser::Split_attrContext *context) = 0;

    virtual std::any visitZero_load_latency_attr(DOTParser::Zero_load_latency_attrContext *context) = 0;

    virtual std::any visitDepth_attr(DOTParser::Depth_attrContext *context) = 0;

    virtual std::any visitPriority_attr(DOTParser::Priority_attrContext *context) = 0;

    virtual std::any visitRate_attr(DOTParser::Rate_attrContext *context) = 0;

    virtual std::any visitMap_attr(DOTParser::Map_attrContext *context) = 0;

    virtual std::any visitMapPair(DOTParser::MapPairContext *context) = 0;

    virtual std::any visitType_attr(DOTParser::Type_attrContext *context) = 0;

    virtual std::any visitType_(DOTParser::Type_Context *context) = 0;

    virtual std::any visitA_list(DOTParser::A_listContext *context) = 0;

    virtual std::any visitAttr_(DOTParser::Attr_Context *context) = 0;

    virtual std::any visitEdge_stmt(DOTParser::Edge_stmtContext *context) = 0;

    virtual std::any visitEdgeRHS(DOTParser::EdgeRHSContext *context) = 0;

    virtual std::any visitEdgeop(DOTParser::EdgeopContext *context) = 0;

    virtual std::any visitNode_stmt(DOTParser::Node_stmtContext *context) = 0;

    virtual std::any visitNode_id(DOTParser::Node_idContext *context) = 0;

    virtual std::any visitPort(DOTParser::PortContext *context) = 0;

    virtual std::any visitSubgraph(DOTParser::SubgraphContext *context) = 0;

    virtual std::any visitId_(DOTParser::Id_Context *context) = 0;


};

