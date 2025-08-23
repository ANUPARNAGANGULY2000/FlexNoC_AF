
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DOTParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, CV = 12, T_SERV = 13, COEFF_VAR = 14, 
    ZERO_LOAD = 15, DEPTH = 16, SIZE = 17, RATE = 18, SOURCE = 19, QUEUE = 20, 
    ARBITER = 21, ROUNDROBIN = 22, PRIORITY = 23, SERVER = 24, SINK = 25, 
    STRICT = 26, GRAPH = 27, DIGRAPH = 28, NODE = 29, EDGE = 30, SUBGRAPH = 31, 
    NUMBER = 32, STRING = 33, ID = 34, HTML_STRING = 35, COMMENT = 36, LINE_COMMENT = 37, 
    PREPROC = 38, WS = 39
  };

  enum {
    RuleGraph = 0, RuleStmt_list = 1, RuleStmt = 2, RuleAttr_stmt = 3, RuleAttr_list = 4, 
    RuleNode_attr_list = 5, RuleEdge_attr_list = 6, RuleGeneric_attr = 7, 
    RuleCv_attr = 8, RuleService_time_attr = 9, RuleCoeff_service_time_attr = 10, 
    RuleZero_load_latency_attr = 11, RuleDepth_attr = 12, RulePriority_attr = 13, 
    RuleRate_attr = 14, RuleType_attr = 15, RuleType_ = 16, RuleA_list = 17, 
    RuleAttr_ = 18, RuleEdge_stmt = 19, RuleEdgeRHS = 20, RuleEdgeop = 21, 
    RuleNode_stmt = 22, RuleNode_id = 23, RulePort = 24, RuleSubgraph = 25, 
    RuleId_ = 26
  };

  explicit DOTParser(antlr4::TokenStream *input);

  DOTParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DOTParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class GraphContext;
  class Stmt_listContext;
  class StmtContext;
  class Attr_stmtContext;
  class Attr_listContext;
  class Node_attr_listContext;
  class Edge_attr_listContext;
  class Generic_attrContext;
  class Cv_attrContext;
  class Service_time_attrContext;
  class Coeff_service_time_attrContext;
  class Zero_load_latency_attrContext;
  class Depth_attrContext;
  class Priority_attrContext;
  class Rate_attrContext;
  class Type_attrContext;
  class Type_Context;
  class A_listContext;
  class Attr_Context;
  class Edge_stmtContext;
  class EdgeRHSContext;
  class EdgeopContext;
  class Node_stmtContext;
  class Node_idContext;
  class PortContext;
  class SubgraphContext;
  class Id_Context; 

  class  GraphContext : public antlr4::ParserRuleContext {
  public:
    GraphContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stmt_listContext *stmt_list();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *DIGRAPH();
    antlr4::tree::TerminalNode *STRICT();
    Id_Context *id_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphContext* graph();

  class  Stmt_listContext : public antlr4::ParserRuleContext {
  public:
    Stmt_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Stmt_listContext* stmt_list();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Node_stmtContext *node_stmt();
    Edge_stmtContext *edge_stmt();
    Attr_stmtContext *attr_stmt();
    std::vector<Id_Context *> id_();
    Id_Context* id_(size_t i);
    SubgraphContext *subgraph();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  Attr_stmtContext : public antlr4::ParserRuleContext {
  public:
    Attr_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attr_listContext *attr_list();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *EDGE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attr_stmtContext* attr_stmt();

  class  Attr_listContext : public antlr4::ParserRuleContext {
  public:
    Attr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<A_listContext *> a_list();
    A_listContext* a_list(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attr_listContext* attr_list();

  class  Node_attr_listContext : public antlr4::ParserRuleContext {
  public:
    Node_attr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_attrContext *> type_attr();
    Type_attrContext* type_attr(size_t i);
    std::vector<Generic_attrContext *> generic_attr();
    Generic_attrContext* generic_attr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Node_attr_listContext* node_attr_list();

  class  Edge_attr_listContext : public antlr4::ParserRuleContext {
  public:
    Edge_attr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Generic_attrContext *> generic_attr();
    Generic_attrContext* generic_attr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_attr_listContext* edge_attr_list();

  class  Generic_attrContext : public antlr4::ParserRuleContext {
  public:
    Generic_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attr_Context *attr_();
    Cv_attrContext *cv_attr();
    Depth_attrContext *depth_attr();
    Priority_attrContext *priority_attr();
    Rate_attrContext *rate_attr();
    Service_time_attrContext *service_time_attr();
    Coeff_service_time_attrContext *coeff_service_time_attr();
    Zero_load_latency_attrContext *zero_load_latency_attr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generic_attrContext* generic_attr();

  class  Cv_attrContext : public antlr4::ParserRuleContext {
  public:
    Cv_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CV();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cv_attrContext* cv_attr();

  class  Service_time_attrContext : public antlr4::ParserRuleContext {
  public:
    Service_time_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *T_SERV();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Service_time_attrContext* service_time_attr();

  class  Coeff_service_time_attrContext : public antlr4::ParserRuleContext {
  public:
    Coeff_service_time_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COEFF_VAR();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coeff_service_time_attrContext* coeff_service_time_attr();

  class  Zero_load_latency_attrContext : public antlr4::ParserRuleContext {
  public:
    Zero_load_latency_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZERO_LOAD();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Zero_load_latency_attrContext* zero_load_latency_attr();

  class  Depth_attrContext : public antlr4::ParserRuleContext {
  public:
    Depth_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEPTH();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *SIZE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Depth_attrContext* depth_attr();

  class  Priority_attrContext : public antlr4::ParserRuleContext {
  public:
    Priority_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRIORITY();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Priority_attrContext* priority_attr();

  class  Rate_attrContext : public antlr4::ParserRuleContext {
  public:
    Rate_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RATE();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rate_attrContext* rate_attr();

  class  Type_attrContext : public antlr4::ParserRuleContext {
  public:
    Type_attrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_Context *type_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_attrContext* type_attr();

  class  Type_Context : public antlr4::ParserRuleContext {
  public:
    Type_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOURCE();
    antlr4::tree::TerminalNode *QUEUE();
    antlr4::tree::TerminalNode *ARBITER();
    antlr4::tree::TerminalNode *ROUNDROBIN();
    antlr4::tree::TerminalNode *PRIORITY();
    antlr4::tree::TerminalNode *SERVER();
    antlr4::tree::TerminalNode *SINK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_Context* type_();

  class  A_listContext : public antlr4::ParserRuleContext {
  public:
    A_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Attr_Context *> attr_();
    Attr_Context* attr_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  A_listContext* a_list();

  class  Attr_Context : public antlr4::ParserRuleContext {
  public:
    Attr_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Id_Context *> id_();
    Id_Context* id_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attr_Context* attr_();

  class  Edge_stmtContext : public antlr4::ParserRuleContext {
  public:
    Edge_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EdgeRHSContext *edgeRHS();
    Node_idContext *node_id();
    SubgraphContext *subgraph();
    Edge_attr_listContext *edge_attr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_stmtContext* edge_stmt();

  class  EdgeRHSContext : public antlr4::ParserRuleContext {
  public:
    EdgeRHSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EdgeopContext *> edgeop();
    EdgeopContext* edgeop(size_t i);
    std::vector<Node_idContext *> node_id();
    Node_idContext* node_id(size_t i);
    std::vector<SubgraphContext *> subgraph();
    SubgraphContext* subgraph(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeRHSContext* edgeRHS();

  class  EdgeopContext : public antlr4::ParserRuleContext {
  public:
    EdgeopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeopContext* edgeop();

  class  Node_stmtContext : public antlr4::ParserRuleContext {
  public:
    Node_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Node_idContext *node_id();
    Node_attr_listContext *node_attr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Node_stmtContext* node_stmt();

  class  Node_idContext : public antlr4::ParserRuleContext {
  public:
    Node_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Id_Context *id_();
    PortContext *port();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Node_idContext* node_id();

  class  PortContext : public antlr4::ParserRuleContext {
  public:
    PortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Id_Context *> id_();
    Id_Context* id_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PortContext* port();

  class  SubgraphContext : public antlr4::ParserRuleContext {
  public:
    SubgraphContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stmt_listContext *stmt_list();
    antlr4::tree::TerminalNode *SUBGRAPH();
    Id_Context *id_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubgraphContext* subgraph();

  class  Id_Context : public antlr4::ParserRuleContext {
  public:
    Id_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *HTML_STRING();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *SOURCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Id_Context* id_();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

