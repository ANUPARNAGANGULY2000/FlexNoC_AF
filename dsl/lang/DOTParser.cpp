
// Generated from DOT.g4 by ANTLR 4.13.2


#include "DOTListener.h"
#include "DOTVisitor.h"

#include "DOTParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct DOTParserStaticData final {
  DOTParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DOTParserStaticData(const DOTParserStaticData&) = delete;
  DOTParserStaticData(DOTParserStaticData&&) = delete;
  DOTParserStaticData& operator=(const DOTParserStaticData&) = delete;
  DOTParserStaticData& operator=(DOTParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag dotParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<DOTParserStaticData> dotParserStaticData = nullptr;

void dotParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (dotParserStaticData != nullptr) {
    return;
  }
#else
  assert(dotParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DOTParserStaticData>(
    std::vector<std::string>{
      "graph", "stmt_list", "stmt", "attr_stmt", "attr_list", "node_attr_list", 
      "edge_attr_list", "generic_attr", "cv_attr", "service_time_attr", 
      "coeff_service_time_attr", "zero_load_latency_attr", "depth_attr", 
      "priority_attr", "rate_attr", "type_attr", "type_", "a_list", "attr_", 
      "edge_stmt", "edgeRHS", "edgeop", "node_stmt", "node_id", "port", 
      "subgraph", "id_"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "';'", "'='", "'['", "']'", "','", "'type'", "'->'", 
      "'--'", "':'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "CV", "T_SERV", "COEFF_VAR", 
      "ZERO_LOAD", "DEPTH", "SIZE", "PRIORITY", "RATE", "SOURCE", "QUEUE", 
      "ARBITER", "SERVER", "SINK", "STRICT", "GRAPH", "DIGRAPH", "NODE", 
      "EDGE", "SUBGRAPH", "NUMBER", "STRING", "ID", "HTML_STRING", "COMMENT", 
      "LINE_COMMENT", "PREPROC", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,38,254,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,3,0,56,8,0,1,
  	0,1,0,3,0,60,8,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,3,1,69,8,1,5,1,71,8,1,10,
  	1,12,1,74,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,84,8,2,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,4,4,93,8,4,11,4,12,4,94,1,5,1,5,5,5,99,8,5,10,5,12,5,
  	102,9,5,1,5,1,5,5,5,106,8,5,10,5,12,5,109,9,5,1,5,1,5,4,5,113,8,5,11,
  	5,12,5,114,1,6,1,6,4,6,119,8,6,11,6,12,6,120,1,6,1,6,4,6,125,8,6,11,6,
  	12,6,126,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,137,8,7,1,8,1,8,1,8,1,8,
  	3,8,143,8,8,1,9,1,9,1,9,1,9,3,9,149,8,9,1,10,1,10,1,10,1,10,3,10,155,
  	8,10,1,11,1,11,1,11,1,11,3,11,161,8,11,1,12,1,12,1,12,1,12,3,12,167,8,
  	12,1,12,1,12,1,12,1,12,3,12,173,8,12,3,12,175,8,12,1,13,1,13,1,13,1,13,
  	3,13,181,8,13,1,14,1,14,1,14,1,14,3,14,187,8,14,1,15,1,15,1,15,1,15,3,
  	15,193,8,15,1,16,1,16,1,17,4,17,198,8,17,11,17,12,17,199,1,18,1,18,1,
  	18,3,18,205,8,18,1,18,3,18,208,8,18,1,19,1,19,3,19,212,8,19,1,19,1,19,
  	3,19,216,8,19,1,20,1,20,1,20,3,20,221,8,20,4,20,223,8,20,11,20,12,20,
  	224,1,21,1,21,1,22,1,22,1,22,1,23,1,23,3,23,234,8,23,1,24,1,24,1,24,1,
  	24,3,24,240,8,24,1,25,1,25,3,25,244,8,25,3,25,246,8,25,1,25,1,25,1,25,
  	1,25,1,26,1,26,1,26,0,0,27,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,0,6,1,0,26,27,2,0,26,26,28,29,2,0,3,
  	3,7,7,1,0,20,24,1,0,9,10,3,0,20,20,24,24,31,34,268,0,55,1,0,0,0,2,72,
  	1,0,0,0,4,83,1,0,0,0,6,85,1,0,0,0,8,92,1,0,0,0,10,112,1,0,0,0,12,124,
  	1,0,0,0,14,136,1,0,0,0,16,138,1,0,0,0,18,144,1,0,0,0,20,150,1,0,0,0,22,
  	156,1,0,0,0,24,174,1,0,0,0,26,176,1,0,0,0,28,182,1,0,0,0,30,188,1,0,0,
  	0,32,194,1,0,0,0,34,197,1,0,0,0,36,201,1,0,0,0,38,211,1,0,0,0,40,222,
  	1,0,0,0,42,226,1,0,0,0,44,228,1,0,0,0,46,231,1,0,0,0,48,235,1,0,0,0,50,
  	245,1,0,0,0,52,251,1,0,0,0,54,56,5,25,0,0,55,54,1,0,0,0,55,56,1,0,0,0,
  	56,57,1,0,0,0,57,59,7,0,0,0,58,60,3,52,26,0,59,58,1,0,0,0,59,60,1,0,0,
  	0,60,61,1,0,0,0,61,62,5,1,0,0,62,63,3,2,1,0,63,64,5,2,0,0,64,65,5,0,0,
  	1,65,1,1,0,0,0,66,68,3,4,2,0,67,69,5,3,0,0,68,67,1,0,0,0,68,69,1,0,0,
  	0,69,71,1,0,0,0,70,66,1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,72,73,1,0,0,
  	0,73,3,1,0,0,0,74,72,1,0,0,0,75,84,3,44,22,0,76,84,3,38,19,0,77,84,3,
  	6,3,0,78,79,3,52,26,0,79,80,5,4,0,0,80,81,3,52,26,0,81,84,1,0,0,0,82,
  	84,3,50,25,0,83,75,1,0,0,0,83,76,1,0,0,0,83,77,1,0,0,0,83,78,1,0,0,0,
  	83,82,1,0,0,0,84,5,1,0,0,0,85,86,7,1,0,0,86,87,3,8,4,0,87,7,1,0,0,0,88,
  	89,5,5,0,0,89,90,3,34,17,0,90,91,5,6,0,0,91,93,1,0,0,0,92,88,1,0,0,0,
  	93,94,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,9,1,0,0,0,96,100,5,5,0,0,
  	97,99,3,14,7,0,98,97,1,0,0,0,99,102,1,0,0,0,100,98,1,0,0,0,100,101,1,
  	0,0,0,101,103,1,0,0,0,102,100,1,0,0,0,103,107,3,30,15,0,104,106,3,14,
  	7,0,105,104,1,0,0,0,106,109,1,0,0,0,107,105,1,0,0,0,107,108,1,0,0,0,108,
  	110,1,0,0,0,109,107,1,0,0,0,110,111,5,6,0,0,111,113,1,0,0,0,112,96,1,
  	0,0,0,113,114,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,11,1,0,0,0,
  	116,118,5,5,0,0,117,119,3,14,7,0,118,117,1,0,0,0,119,120,1,0,0,0,120,
  	118,1,0,0,0,120,121,1,0,0,0,121,122,1,0,0,0,122,123,5,6,0,0,123,125,1,
  	0,0,0,124,116,1,0,0,0,125,126,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,
  	127,13,1,0,0,0,128,137,3,36,18,0,129,137,3,16,8,0,130,137,3,24,12,0,131,
  	137,3,26,13,0,132,137,3,28,14,0,133,137,3,18,9,0,134,137,3,20,10,0,135,
  	137,3,22,11,0,136,128,1,0,0,0,136,129,1,0,0,0,136,130,1,0,0,0,136,131,
  	1,0,0,0,136,132,1,0,0,0,136,133,1,0,0,0,136,134,1,0,0,0,136,135,1,0,0,
  	0,137,15,1,0,0,0,138,139,5,12,0,0,139,140,5,4,0,0,140,142,5,31,0,0,141,
  	143,7,2,0,0,142,141,1,0,0,0,142,143,1,0,0,0,143,17,1,0,0,0,144,145,5,
  	13,0,0,145,146,5,4,0,0,146,148,5,31,0,0,147,149,7,2,0,0,148,147,1,0,0,
  	0,148,149,1,0,0,0,149,19,1,0,0,0,150,151,5,14,0,0,151,152,5,4,0,0,152,
  	154,5,31,0,0,153,155,7,2,0,0,154,153,1,0,0,0,154,155,1,0,0,0,155,21,1,
  	0,0,0,156,157,5,15,0,0,157,158,5,4,0,0,158,160,5,31,0,0,159,161,7,2,0,
  	0,160,159,1,0,0,0,160,161,1,0,0,0,161,23,1,0,0,0,162,163,5,16,0,0,163,
  	164,5,4,0,0,164,166,5,31,0,0,165,167,7,2,0,0,166,165,1,0,0,0,166,167,
  	1,0,0,0,167,175,1,0,0,0,168,169,5,17,0,0,169,170,5,4,0,0,170,172,5,31,
  	0,0,171,173,7,2,0,0,172,171,1,0,0,0,172,173,1,0,0,0,173,175,1,0,0,0,174,
  	162,1,0,0,0,174,168,1,0,0,0,175,25,1,0,0,0,176,177,5,18,0,0,177,178,5,
  	4,0,0,178,180,5,31,0,0,179,181,7,2,0,0,180,179,1,0,0,0,180,181,1,0,0,
  	0,181,27,1,0,0,0,182,183,5,19,0,0,183,184,5,4,0,0,184,186,5,31,0,0,185,
  	187,7,2,0,0,186,185,1,0,0,0,186,187,1,0,0,0,187,29,1,0,0,0,188,189,5,
  	8,0,0,189,190,5,4,0,0,190,192,3,32,16,0,191,193,7,2,0,0,192,191,1,0,0,
  	0,192,193,1,0,0,0,193,31,1,0,0,0,194,195,7,3,0,0,195,33,1,0,0,0,196,198,
  	3,36,18,0,197,196,1,0,0,0,198,199,1,0,0,0,199,197,1,0,0,0,199,200,1,0,
  	0,0,200,35,1,0,0,0,201,204,3,52,26,0,202,203,5,4,0,0,203,205,3,52,26,
  	0,204,202,1,0,0,0,204,205,1,0,0,0,205,207,1,0,0,0,206,208,7,2,0,0,207,
  	206,1,0,0,0,207,208,1,0,0,0,208,37,1,0,0,0,209,212,3,46,23,0,210,212,
  	3,50,25,0,211,209,1,0,0,0,211,210,1,0,0,0,212,213,1,0,0,0,213,215,3,40,
  	20,0,214,216,3,12,6,0,215,214,1,0,0,0,215,216,1,0,0,0,216,39,1,0,0,0,
  	217,220,3,42,21,0,218,221,3,46,23,0,219,221,3,50,25,0,220,218,1,0,0,0,
  	220,219,1,0,0,0,221,223,1,0,0,0,222,217,1,0,0,0,223,224,1,0,0,0,224,222,
  	1,0,0,0,224,225,1,0,0,0,225,41,1,0,0,0,226,227,7,4,0,0,227,43,1,0,0,0,
  	228,229,3,46,23,0,229,230,3,10,5,0,230,45,1,0,0,0,231,233,3,52,26,0,232,
  	234,3,48,24,0,233,232,1,0,0,0,233,234,1,0,0,0,234,47,1,0,0,0,235,236,
  	5,11,0,0,236,239,3,52,26,0,237,238,5,11,0,0,238,240,3,52,26,0,239,237,
  	1,0,0,0,239,240,1,0,0,0,240,49,1,0,0,0,241,243,5,30,0,0,242,244,3,52,
  	26,0,243,242,1,0,0,0,243,244,1,0,0,0,244,246,1,0,0,0,245,241,1,0,0,0,
  	245,246,1,0,0,0,246,247,1,0,0,0,247,248,5,1,0,0,248,249,3,2,1,0,249,250,
  	5,2,0,0,250,51,1,0,0,0,251,252,7,5,0,0,252,53,1,0,0,0,33,55,59,68,72,
  	83,94,100,107,114,120,126,136,142,148,154,160,166,172,174,180,186,192,
  	199,204,207,211,215,220,224,233,239,243,245
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  dotParserStaticData = std::move(staticData);
}

}

DOTParser::DOTParser(TokenStream *input) : DOTParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

DOTParser::DOTParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  DOTParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *dotParserStaticData->atn, dotParserStaticData->decisionToDFA, dotParserStaticData->sharedContextCache, options);
}

DOTParser::~DOTParser() {
  delete _interpreter;
}

const atn::ATN& DOTParser::getATN() const {
  return *dotParserStaticData->atn;
}

std::string DOTParser::getGrammarFileName() const {
  return "DOT.g4";
}

const std::vector<std::string>& DOTParser::getRuleNames() const {
  return dotParserStaticData->ruleNames;
}

const dfa::Vocabulary& DOTParser::getVocabulary() const {
  return dotParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DOTParser::getSerializedATN() const {
  return dotParserStaticData->serializedATN;
}


//----------------- GraphContext ------------------------------------------------------------------

DOTParser::GraphContext::GraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Stmt_listContext* DOTParser::GraphContext::stmt_list() {
  return getRuleContext<DOTParser::Stmt_listContext>(0);
}

tree::TerminalNode* DOTParser::GraphContext::EOF() {
  return getToken(DOTParser::EOF, 0);
}

tree::TerminalNode* DOTParser::GraphContext::GRAPH() {
  return getToken(DOTParser::GRAPH, 0);
}

tree::TerminalNode* DOTParser::GraphContext::DIGRAPH() {
  return getToken(DOTParser::DIGRAPH, 0);
}

tree::TerminalNode* DOTParser::GraphContext::STRICT() {
  return getToken(DOTParser::STRICT, 0);
}

DOTParser::Id_Context* DOTParser::GraphContext::id_() {
  return getRuleContext<DOTParser::Id_Context>(0);
}


size_t DOTParser::GraphContext::getRuleIndex() const {
  return DOTParser::RuleGraph;
}

void DOTParser::GraphContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGraph(this);
}

void DOTParser::GraphContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGraph(this);
}


std::any DOTParser::GraphContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitGraph(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::GraphContext* DOTParser::graph() {
  GraphContext *_localctx = _tracker.createInstance<GraphContext>(_ctx, getState());
  enterRule(_localctx, 0, DOTParser::RuleGraph);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::STRICT) {
      setState(54);
      match(DOTParser::STRICT);
    }
    setState(57);
    _la = _input->LA(1);
    if (!(_la == DOTParser::GRAPH

    || _la == DOTParser::DIGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32230080512) != 0)) {
      setState(58);
      id_();
    }
    setState(61);
    match(DOTParser::T__0);
    setState(62);
    stmt_list();
    setState(63);
    match(DOTParser::T__1);
    setState(64);
    match(DOTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stmt_listContext ------------------------------------------------------------------

DOTParser::Stmt_listContext::Stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::StmtContext *> DOTParser::Stmt_listContext::stmt() {
  return getRuleContexts<DOTParser::StmtContext>();
}

DOTParser::StmtContext* DOTParser::Stmt_listContext::stmt(size_t i) {
  return getRuleContext<DOTParser::StmtContext>(i);
}


size_t DOTParser::Stmt_listContext::getRuleIndex() const {
  return DOTParser::RuleStmt_list;
}

void DOTParser::Stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt_list(this);
}

void DOTParser::Stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt_list(this);
}


std::any DOTParser::Stmt_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitStmt_list(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Stmt_listContext* DOTParser::stmt_list() {
  Stmt_listContext *_localctx = _tracker.createInstance<Stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 2, DOTParser::RuleStmt_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34176237570) != 0)) {
      setState(66);
      stmt();
      setState(68);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__2) {
        setState(67);
        match(DOTParser::T__2);
      }
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

DOTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Node_stmtContext* DOTParser::StmtContext::node_stmt() {
  return getRuleContext<DOTParser::Node_stmtContext>(0);
}

DOTParser::Edge_stmtContext* DOTParser::StmtContext::edge_stmt() {
  return getRuleContext<DOTParser::Edge_stmtContext>(0);
}

DOTParser::Attr_stmtContext* DOTParser::StmtContext::attr_stmt() {
  return getRuleContext<DOTParser::Attr_stmtContext>(0);
}

std::vector<DOTParser::Id_Context *> DOTParser::StmtContext::id_() {
  return getRuleContexts<DOTParser::Id_Context>();
}

DOTParser::Id_Context* DOTParser::StmtContext::id_(size_t i) {
  return getRuleContext<DOTParser::Id_Context>(i);
}

DOTParser::SubgraphContext* DOTParser::StmtContext::subgraph() {
  return getRuleContext<DOTParser::SubgraphContext>(0);
}


size_t DOTParser::StmtContext::getRuleIndex() const {
  return DOTParser::RuleStmt;
}

void DOTParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void DOTParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


std::any DOTParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::StmtContext* DOTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 4, DOTParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      node_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(76);
      edge_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(77);
      attr_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(78);
      id_();
      setState(79);
      match(DOTParser::T__3);
      setState(80);
      id_();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(82);
      subgraph();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_stmtContext ------------------------------------------------------------------

DOTParser::Attr_stmtContext::Attr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Attr_listContext* DOTParser::Attr_stmtContext::attr_list() {
  return getRuleContext<DOTParser::Attr_listContext>(0);
}

tree::TerminalNode* DOTParser::Attr_stmtContext::GRAPH() {
  return getToken(DOTParser::GRAPH, 0);
}

tree::TerminalNode* DOTParser::Attr_stmtContext::NODE() {
  return getToken(DOTParser::NODE, 0);
}

tree::TerminalNode* DOTParser::Attr_stmtContext::EDGE() {
  return getToken(DOTParser::EDGE, 0);
}


size_t DOTParser::Attr_stmtContext::getRuleIndex() const {
  return DOTParser::RuleAttr_stmt;
}

void DOTParser::Attr_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_stmt(this);
}

void DOTParser::Attr_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_stmt(this);
}


std::any DOTParser::Attr_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitAttr_stmt(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Attr_stmtContext* DOTParser::attr_stmt() {
  Attr_stmtContext *_localctx = _tracker.createInstance<Attr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, DOTParser::RuleAttr_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 872415232) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(86);
    attr_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_listContext ------------------------------------------------------------------

DOTParser::Attr_listContext::Attr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::A_listContext *> DOTParser::Attr_listContext::a_list() {
  return getRuleContexts<DOTParser::A_listContext>();
}

DOTParser::A_listContext* DOTParser::Attr_listContext::a_list(size_t i) {
  return getRuleContext<DOTParser::A_listContext>(i);
}


size_t DOTParser::Attr_listContext::getRuleIndex() const {
  return DOTParser::RuleAttr_list;
}

void DOTParser::Attr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_list(this);
}

void DOTParser::Attr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_list(this);
}


std::any DOTParser::Attr_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitAttr_list(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Attr_listContext* DOTParser::attr_list() {
  Attr_listContext *_localctx = _tracker.createInstance<Attr_listContext>(_ctx, getState());
  enterRule(_localctx, 8, DOTParser::RuleAttr_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(88);
      match(DOTParser::T__4);
      setState(89);
      a_list();
      setState(90);
      match(DOTParser::T__5);
      setState(94); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_attr_listContext ------------------------------------------------------------------

DOTParser::Node_attr_listContext::Node_attr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::Type_attrContext *> DOTParser::Node_attr_listContext::type_attr() {
  return getRuleContexts<DOTParser::Type_attrContext>();
}

DOTParser::Type_attrContext* DOTParser::Node_attr_listContext::type_attr(size_t i) {
  return getRuleContext<DOTParser::Type_attrContext>(i);
}

std::vector<DOTParser::Generic_attrContext *> DOTParser::Node_attr_listContext::generic_attr() {
  return getRuleContexts<DOTParser::Generic_attrContext>();
}

DOTParser::Generic_attrContext* DOTParser::Node_attr_listContext::generic_attr(size_t i) {
  return getRuleContext<DOTParser::Generic_attrContext>(i);
}


size_t DOTParser::Node_attr_listContext::getRuleIndex() const {
  return DOTParser::RuleNode_attr_list;
}

void DOTParser::Node_attr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_attr_list(this);
}

void DOTParser::Node_attr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_attr_list(this);
}


std::any DOTParser::Node_attr_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitNode_attr_list(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Node_attr_listContext* DOTParser::node_attr_list() {
  Node_attr_listContext *_localctx = _tracker.createInstance<Node_attr_listContext>(_ctx, getState());
  enterRule(_localctx, 10, DOTParser::RuleNode_attr_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(96);
      match(DOTParser::T__4);
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32231124992) != 0)) {
        setState(97);
        generic_attr();
        setState(102);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(103);
      type_attr();
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32231124992) != 0)) {
        setState(104);
        generic_attr();
        setState(109);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(110);
      match(DOTParser::T__5);
      setState(114); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Edge_attr_listContext ------------------------------------------------------------------

DOTParser::Edge_attr_listContext::Edge_attr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::Generic_attrContext *> DOTParser::Edge_attr_listContext::generic_attr() {
  return getRuleContexts<DOTParser::Generic_attrContext>();
}

DOTParser::Generic_attrContext* DOTParser::Edge_attr_listContext::generic_attr(size_t i) {
  return getRuleContext<DOTParser::Generic_attrContext>(i);
}


size_t DOTParser::Edge_attr_listContext::getRuleIndex() const {
  return DOTParser::RuleEdge_attr_list;
}

void DOTParser::Edge_attr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_attr_list(this);
}

void DOTParser::Edge_attr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_attr_list(this);
}


std::any DOTParser::Edge_attr_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitEdge_attr_list(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Edge_attr_listContext* DOTParser::edge_attr_list() {
  Edge_attr_listContext *_localctx = _tracker.createInstance<Edge_attr_listContext>(_ctx, getState());
  enterRule(_localctx, 12, DOTParser::RuleEdge_attr_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(116);
      match(DOTParser::T__4);
      setState(118); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(117);
        generic_attr();
        setState(120); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32231124992) != 0));
      setState(122);
      match(DOTParser::T__5);
      setState(126); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_attrContext ------------------------------------------------------------------

DOTParser::Generic_attrContext::Generic_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Attr_Context* DOTParser::Generic_attrContext::attr_() {
  return getRuleContext<DOTParser::Attr_Context>(0);
}

DOTParser::Cv_attrContext* DOTParser::Generic_attrContext::cv_attr() {
  return getRuleContext<DOTParser::Cv_attrContext>(0);
}

DOTParser::Depth_attrContext* DOTParser::Generic_attrContext::depth_attr() {
  return getRuleContext<DOTParser::Depth_attrContext>(0);
}

DOTParser::Priority_attrContext* DOTParser::Generic_attrContext::priority_attr() {
  return getRuleContext<DOTParser::Priority_attrContext>(0);
}

DOTParser::Rate_attrContext* DOTParser::Generic_attrContext::rate_attr() {
  return getRuleContext<DOTParser::Rate_attrContext>(0);
}

DOTParser::Service_time_attrContext* DOTParser::Generic_attrContext::service_time_attr() {
  return getRuleContext<DOTParser::Service_time_attrContext>(0);
}

DOTParser::Coeff_service_time_attrContext* DOTParser::Generic_attrContext::coeff_service_time_attr() {
  return getRuleContext<DOTParser::Coeff_service_time_attrContext>(0);
}

DOTParser::Zero_load_latency_attrContext* DOTParser::Generic_attrContext::zero_load_latency_attr() {
  return getRuleContext<DOTParser::Zero_load_latency_attrContext>(0);
}


size_t DOTParser::Generic_attrContext::getRuleIndex() const {
  return DOTParser::RuleGeneric_attr;
}

void DOTParser::Generic_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric_attr(this);
}

void DOTParser::Generic_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric_attr(this);
}


std::any DOTParser::Generic_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitGeneric_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Generic_attrContext* DOTParser::generic_attr() {
  Generic_attrContext *_localctx = _tracker.createInstance<Generic_attrContext>(_ctx, getState());
  enterRule(_localctx, 14, DOTParser::RuleGeneric_attr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::SOURCE:
      case DOTParser::SINK:
      case DOTParser::NUMBER:
      case DOTParser::STRING:
      case DOTParser::ID:
      case DOTParser::HTML_STRING: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        attr_();
        break;
      }

      case DOTParser::CV: {
        enterOuterAlt(_localctx, 2);
        setState(129);
        cv_attr();
        break;
      }

      case DOTParser::DEPTH:
      case DOTParser::SIZE: {
        enterOuterAlt(_localctx, 3);
        setState(130);
        depth_attr();
        break;
      }

      case DOTParser::PRIORITY: {
        enterOuterAlt(_localctx, 4);
        setState(131);
        priority_attr();
        break;
      }

      case DOTParser::RATE: {
        enterOuterAlt(_localctx, 5);
        setState(132);
        rate_attr();
        break;
      }

      case DOTParser::T_SERV: {
        enterOuterAlt(_localctx, 6);
        setState(133);
        service_time_attr();
        break;
      }

      case DOTParser::COEFF_VAR: {
        enterOuterAlt(_localctx, 7);
        setState(134);
        coeff_service_time_attr();
        break;
      }

      case DOTParser::ZERO_LOAD: {
        enterOuterAlt(_localctx, 8);
        setState(135);
        zero_load_latency_attr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cv_attrContext ------------------------------------------------------------------

DOTParser::Cv_attrContext::Cv_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Cv_attrContext::CV() {
  return getToken(DOTParser::CV, 0);
}

tree::TerminalNode* DOTParser::Cv_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Cv_attrContext::getRuleIndex() const {
  return DOTParser::RuleCv_attr;
}

void DOTParser::Cv_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCv_attr(this);
}

void DOTParser::Cv_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCv_attr(this);
}


std::any DOTParser::Cv_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitCv_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Cv_attrContext* DOTParser::cv_attr() {
  Cv_attrContext *_localctx = _tracker.createInstance<Cv_attrContext>(_ctx, getState());
  enterRule(_localctx, 16, DOTParser::RuleCv_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(DOTParser::CV);
    setState(139);
    match(DOTParser::T__3);
    setState(140);
    match(DOTParser::NUMBER);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(141);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Service_time_attrContext ------------------------------------------------------------------

DOTParser::Service_time_attrContext::Service_time_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Service_time_attrContext::T_SERV() {
  return getToken(DOTParser::T_SERV, 0);
}

tree::TerminalNode* DOTParser::Service_time_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Service_time_attrContext::getRuleIndex() const {
  return DOTParser::RuleService_time_attr;
}

void DOTParser::Service_time_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterService_time_attr(this);
}

void DOTParser::Service_time_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitService_time_attr(this);
}


std::any DOTParser::Service_time_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitService_time_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Service_time_attrContext* DOTParser::service_time_attr() {
  Service_time_attrContext *_localctx = _tracker.createInstance<Service_time_attrContext>(_ctx, getState());
  enterRule(_localctx, 18, DOTParser::RuleService_time_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(DOTParser::T_SERV);
    setState(145);
    match(DOTParser::T__3);
    setState(146);
    match(DOTParser::NUMBER);
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(147);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Coeff_service_time_attrContext ------------------------------------------------------------------

DOTParser::Coeff_service_time_attrContext::Coeff_service_time_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Coeff_service_time_attrContext::COEFF_VAR() {
  return getToken(DOTParser::COEFF_VAR, 0);
}

tree::TerminalNode* DOTParser::Coeff_service_time_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Coeff_service_time_attrContext::getRuleIndex() const {
  return DOTParser::RuleCoeff_service_time_attr;
}

void DOTParser::Coeff_service_time_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCoeff_service_time_attr(this);
}

void DOTParser::Coeff_service_time_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCoeff_service_time_attr(this);
}


std::any DOTParser::Coeff_service_time_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitCoeff_service_time_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Coeff_service_time_attrContext* DOTParser::coeff_service_time_attr() {
  Coeff_service_time_attrContext *_localctx = _tracker.createInstance<Coeff_service_time_attrContext>(_ctx, getState());
  enterRule(_localctx, 20, DOTParser::RuleCoeff_service_time_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(DOTParser::COEFF_VAR);
    setState(151);
    match(DOTParser::T__3);
    setState(152);
    match(DOTParser::NUMBER);
    setState(154);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(153);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Zero_load_latency_attrContext ------------------------------------------------------------------

DOTParser::Zero_load_latency_attrContext::Zero_load_latency_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Zero_load_latency_attrContext::ZERO_LOAD() {
  return getToken(DOTParser::ZERO_LOAD, 0);
}

tree::TerminalNode* DOTParser::Zero_load_latency_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Zero_load_latency_attrContext::getRuleIndex() const {
  return DOTParser::RuleZero_load_latency_attr;
}

void DOTParser::Zero_load_latency_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterZero_load_latency_attr(this);
}

void DOTParser::Zero_load_latency_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitZero_load_latency_attr(this);
}


std::any DOTParser::Zero_load_latency_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitZero_load_latency_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Zero_load_latency_attrContext* DOTParser::zero_load_latency_attr() {
  Zero_load_latency_attrContext *_localctx = _tracker.createInstance<Zero_load_latency_attrContext>(_ctx, getState());
  enterRule(_localctx, 22, DOTParser::RuleZero_load_latency_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(DOTParser::ZERO_LOAD);
    setState(157);
    match(DOTParser::T__3);
    setState(158);
    match(DOTParser::NUMBER);
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(159);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Depth_attrContext ------------------------------------------------------------------

DOTParser::Depth_attrContext::Depth_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Depth_attrContext::DEPTH() {
  return getToken(DOTParser::DEPTH, 0);
}

tree::TerminalNode* DOTParser::Depth_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}

tree::TerminalNode* DOTParser::Depth_attrContext::SIZE() {
  return getToken(DOTParser::SIZE, 0);
}


size_t DOTParser::Depth_attrContext::getRuleIndex() const {
  return DOTParser::RuleDepth_attr;
}

void DOTParser::Depth_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDepth_attr(this);
}

void DOTParser::Depth_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDepth_attr(this);
}


std::any DOTParser::Depth_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitDepth_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Depth_attrContext* DOTParser::depth_attr() {
  Depth_attrContext *_localctx = _tracker.createInstance<Depth_attrContext>(_ctx, getState());
  enterRule(_localctx, 24, DOTParser::RuleDepth_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::DEPTH: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        match(DOTParser::DEPTH);
        setState(163);
        match(DOTParser::T__3);
        setState(164);
        match(DOTParser::NUMBER);
        setState(166);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DOTParser::T__2

        || _la == DOTParser::T__6) {
          setState(165);
          _la = _input->LA(1);
          if (!(_la == DOTParser::T__2

          || _la == DOTParser::T__6)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

      case DOTParser::SIZE: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        match(DOTParser::SIZE);
        setState(169);
        match(DOTParser::T__3);
        setState(170);
        match(DOTParser::NUMBER);
        setState(172);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DOTParser::T__2

        || _la == DOTParser::T__6) {
          setState(171);
          _la = _input->LA(1);
          if (!(_la == DOTParser::T__2

          || _la == DOTParser::T__6)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Priority_attrContext ------------------------------------------------------------------

DOTParser::Priority_attrContext::Priority_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Priority_attrContext::PRIORITY() {
  return getToken(DOTParser::PRIORITY, 0);
}

tree::TerminalNode* DOTParser::Priority_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Priority_attrContext::getRuleIndex() const {
  return DOTParser::RulePriority_attr;
}

void DOTParser::Priority_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPriority_attr(this);
}

void DOTParser::Priority_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPriority_attr(this);
}


std::any DOTParser::Priority_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitPriority_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Priority_attrContext* DOTParser::priority_attr() {
  Priority_attrContext *_localctx = _tracker.createInstance<Priority_attrContext>(_ctx, getState());
  enterRule(_localctx, 26, DOTParser::RulePriority_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(DOTParser::PRIORITY);
    setState(177);
    match(DOTParser::T__3);
    setState(178);
    match(DOTParser::NUMBER);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(179);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rate_attrContext ------------------------------------------------------------------

DOTParser::Rate_attrContext::Rate_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Rate_attrContext::RATE() {
  return getToken(DOTParser::RATE, 0);
}

tree::TerminalNode* DOTParser::Rate_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Rate_attrContext::getRuleIndex() const {
  return DOTParser::RuleRate_attr;
}

void DOTParser::Rate_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRate_attr(this);
}

void DOTParser::Rate_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRate_attr(this);
}


std::any DOTParser::Rate_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitRate_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Rate_attrContext* DOTParser::rate_attr() {
  Rate_attrContext *_localctx = _tracker.createInstance<Rate_attrContext>(_ctx, getState());
  enterRule(_localctx, 28, DOTParser::RuleRate_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(DOTParser::RATE);
    setState(183);
    match(DOTParser::T__3);
    setState(184);
    match(DOTParser::NUMBER);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(185);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_attrContext ------------------------------------------------------------------

DOTParser::Type_attrContext::Type_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Type_Context* DOTParser::Type_attrContext::type_() {
  return getRuleContext<DOTParser::Type_Context>(0);
}


size_t DOTParser::Type_attrContext::getRuleIndex() const {
  return DOTParser::RuleType_attr;
}

void DOTParser::Type_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_attr(this);
}

void DOTParser::Type_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_attr(this);
}


std::any DOTParser::Type_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitType_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Type_attrContext* DOTParser::type_attr() {
  Type_attrContext *_localctx = _tracker.createInstance<Type_attrContext>(_ctx, getState());
  enterRule(_localctx, 30, DOTParser::RuleType_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(DOTParser::T__7);
    setState(189);
    match(DOTParser::T__3);
    setState(190);
    type_();
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(191);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

DOTParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Type_Context::SOURCE() {
  return getToken(DOTParser::SOURCE, 0);
}

tree::TerminalNode* DOTParser::Type_Context::QUEUE() {
  return getToken(DOTParser::QUEUE, 0);
}

tree::TerminalNode* DOTParser::Type_Context::ARBITER() {
  return getToken(DOTParser::ARBITER, 0);
}

tree::TerminalNode* DOTParser::Type_Context::SERVER() {
  return getToken(DOTParser::SERVER, 0);
}

tree::TerminalNode* DOTParser::Type_Context::SINK() {
  return getToken(DOTParser::SINK, 0);
}


size_t DOTParser::Type_Context::getRuleIndex() const {
  return DOTParser::RuleType_;
}

void DOTParser::Type_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_(this);
}

void DOTParser::Type_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_(this);
}


std::any DOTParser::Type_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitType_(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Type_Context* DOTParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 32, DOTParser::RuleType_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32505856) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- A_listContext ------------------------------------------------------------------

DOTParser::A_listContext::A_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::Attr_Context *> DOTParser::A_listContext::attr_() {
  return getRuleContexts<DOTParser::Attr_Context>();
}

DOTParser::Attr_Context* DOTParser::A_listContext::attr_(size_t i) {
  return getRuleContext<DOTParser::Attr_Context>(i);
}


size_t DOTParser::A_listContext::getRuleIndex() const {
  return DOTParser::RuleA_list;
}

void DOTParser::A_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterA_list(this);
}

void DOTParser::A_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitA_list(this);
}


std::any DOTParser::A_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitA_list(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::A_listContext* DOTParser::a_list() {
  A_listContext *_localctx = _tracker.createInstance<A_listContext>(_ctx, getState());
  enterRule(_localctx, 34, DOTParser::RuleA_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(196);
      attr_();
      setState(199); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32230080512) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attr_Context ------------------------------------------------------------------

DOTParser::Attr_Context::Attr_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::Id_Context *> DOTParser::Attr_Context::id_() {
  return getRuleContexts<DOTParser::Id_Context>();
}

DOTParser::Id_Context* DOTParser::Attr_Context::id_(size_t i) {
  return getRuleContext<DOTParser::Id_Context>(i);
}


size_t DOTParser::Attr_Context::getRuleIndex() const {
  return DOTParser::RuleAttr_;
}

void DOTParser::Attr_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr_(this);
}

void DOTParser::Attr_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr_(this);
}


std::any DOTParser::Attr_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitAttr_(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Attr_Context* DOTParser::attr_() {
  Attr_Context *_localctx = _tracker.createInstance<Attr_Context>(_ctx, getState());
  enterRule(_localctx, 36, DOTParser::RuleAttr_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    id_();
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__3) {
      setState(202);
      match(DOTParser::T__3);
      setState(203);
      id_();
    }
    setState(207);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(206);
      _la = _input->LA(1);
      if (!(_la == DOTParser::T__2

      || _la == DOTParser::T__6)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Edge_stmtContext ------------------------------------------------------------------

DOTParser::Edge_stmtContext::Edge_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::EdgeRHSContext* DOTParser::Edge_stmtContext::edgeRHS() {
  return getRuleContext<DOTParser::EdgeRHSContext>(0);
}

DOTParser::Node_idContext* DOTParser::Edge_stmtContext::node_id() {
  return getRuleContext<DOTParser::Node_idContext>(0);
}

DOTParser::SubgraphContext* DOTParser::Edge_stmtContext::subgraph() {
  return getRuleContext<DOTParser::SubgraphContext>(0);
}

DOTParser::Edge_attr_listContext* DOTParser::Edge_stmtContext::edge_attr_list() {
  return getRuleContext<DOTParser::Edge_attr_listContext>(0);
}


size_t DOTParser::Edge_stmtContext::getRuleIndex() const {
  return DOTParser::RuleEdge_stmt;
}

void DOTParser::Edge_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_stmt(this);
}

void DOTParser::Edge_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_stmt(this);
}


std::any DOTParser::Edge_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitEdge_stmt(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Edge_stmtContext* DOTParser::edge_stmt() {
  Edge_stmtContext *_localctx = _tracker.createInstance<Edge_stmtContext>(_ctx, getState());
  enterRule(_localctx, 38, DOTParser::RuleEdge_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::SOURCE:
      case DOTParser::SINK:
      case DOTParser::NUMBER:
      case DOTParser::STRING:
      case DOTParser::ID:
      case DOTParser::HTML_STRING: {
        setState(209);
        node_id();
        break;
      }

      case DOTParser::T__0:
      case DOTParser::SUBGRAPH: {
        setState(210);
        subgraph();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(213);
    edgeRHS();
    setState(215);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__4) {
      setState(214);
      edge_attr_list();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeRHSContext ------------------------------------------------------------------

DOTParser::EdgeRHSContext::EdgeRHSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::EdgeopContext *> DOTParser::EdgeRHSContext::edgeop() {
  return getRuleContexts<DOTParser::EdgeopContext>();
}

DOTParser::EdgeopContext* DOTParser::EdgeRHSContext::edgeop(size_t i) {
  return getRuleContext<DOTParser::EdgeopContext>(i);
}

std::vector<DOTParser::Node_idContext *> DOTParser::EdgeRHSContext::node_id() {
  return getRuleContexts<DOTParser::Node_idContext>();
}

DOTParser::Node_idContext* DOTParser::EdgeRHSContext::node_id(size_t i) {
  return getRuleContext<DOTParser::Node_idContext>(i);
}

std::vector<DOTParser::SubgraphContext *> DOTParser::EdgeRHSContext::subgraph() {
  return getRuleContexts<DOTParser::SubgraphContext>();
}

DOTParser::SubgraphContext* DOTParser::EdgeRHSContext::subgraph(size_t i) {
  return getRuleContext<DOTParser::SubgraphContext>(i);
}


size_t DOTParser::EdgeRHSContext::getRuleIndex() const {
  return DOTParser::RuleEdgeRHS;
}

void DOTParser::EdgeRHSContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdgeRHS(this);
}

void DOTParser::EdgeRHSContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdgeRHS(this);
}


std::any DOTParser::EdgeRHSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitEdgeRHS(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::EdgeRHSContext* DOTParser::edgeRHS() {
  EdgeRHSContext *_localctx = _tracker.createInstance<EdgeRHSContext>(_ctx, getState());
  enterRule(_localctx, 40, DOTParser::RuleEdgeRHS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(217);
      edgeop();
      setState(220);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DOTParser::SOURCE:
        case DOTParser::SINK:
        case DOTParser::NUMBER:
        case DOTParser::STRING:
        case DOTParser::ID:
        case DOTParser::HTML_STRING: {
          setState(218);
          node_id();
          break;
        }

        case DOTParser::T__0:
        case DOTParser::SUBGRAPH: {
          setState(219);
          subgraph();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(224); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__8

    || _la == DOTParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeopContext ------------------------------------------------------------------

DOTParser::EdgeopContext::EdgeopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DOTParser::EdgeopContext::getRuleIndex() const {
  return DOTParser::RuleEdgeop;
}

void DOTParser::EdgeopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdgeop(this);
}

void DOTParser::EdgeopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdgeop(this);
}


std::any DOTParser::EdgeopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitEdgeop(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::EdgeopContext* DOTParser::edgeop() {
  EdgeopContext *_localctx = _tracker.createInstance<EdgeopContext>(_ctx, getState());
  enterRule(_localctx, 42, DOTParser::RuleEdgeop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    _la = _input->LA(1);
    if (!(_la == DOTParser::T__8

    || _la == DOTParser::T__9)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_stmtContext ------------------------------------------------------------------

DOTParser::Node_stmtContext::Node_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Node_idContext* DOTParser::Node_stmtContext::node_id() {
  return getRuleContext<DOTParser::Node_idContext>(0);
}

DOTParser::Node_attr_listContext* DOTParser::Node_stmtContext::node_attr_list() {
  return getRuleContext<DOTParser::Node_attr_listContext>(0);
}


size_t DOTParser::Node_stmtContext::getRuleIndex() const {
  return DOTParser::RuleNode_stmt;
}

void DOTParser::Node_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_stmt(this);
}

void DOTParser::Node_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_stmt(this);
}


std::any DOTParser::Node_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitNode_stmt(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Node_stmtContext* DOTParser::node_stmt() {
  Node_stmtContext *_localctx = _tracker.createInstance<Node_stmtContext>(_ctx, getState());
  enterRule(_localctx, 44, DOTParser::RuleNode_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    node_id();
    setState(229);
    node_attr_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_idContext ------------------------------------------------------------------

DOTParser::Node_idContext::Node_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Id_Context* DOTParser::Node_idContext::id_() {
  return getRuleContext<DOTParser::Id_Context>(0);
}

DOTParser::PortContext* DOTParser::Node_idContext::port() {
  return getRuleContext<DOTParser::PortContext>(0);
}


size_t DOTParser::Node_idContext::getRuleIndex() const {
  return DOTParser::RuleNode_id;
}

void DOTParser::Node_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_id(this);
}

void DOTParser::Node_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_id(this);
}


std::any DOTParser::Node_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitNode_id(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Node_idContext* DOTParser::node_id() {
  Node_idContext *_localctx = _tracker.createInstance<Node_idContext>(_ctx, getState());
  enterRule(_localctx, 46, DOTParser::RuleNode_id);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    id_();
    setState(233);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__10) {
      setState(232);
      port();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortContext ------------------------------------------------------------------

DOTParser::PortContext::PortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::Id_Context *> DOTParser::PortContext::id_() {
  return getRuleContexts<DOTParser::Id_Context>();
}

DOTParser::Id_Context* DOTParser::PortContext::id_(size_t i) {
  return getRuleContext<DOTParser::Id_Context>(i);
}


size_t DOTParser::PortContext::getRuleIndex() const {
  return DOTParser::RulePort;
}

void DOTParser::PortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort(this);
}

void DOTParser::PortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort(this);
}


std::any DOTParser::PortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitPort(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::PortContext* DOTParser::port() {
  PortContext *_localctx = _tracker.createInstance<PortContext>(_ctx, getState());
  enterRule(_localctx, 48, DOTParser::RulePort);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(DOTParser::T__10);
    setState(236);
    id_();
    setState(239);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__10) {
      setState(237);
      match(DOTParser::T__10);
      setState(238);
      id_();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubgraphContext ------------------------------------------------------------------

DOTParser::SubgraphContext::SubgraphContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Stmt_listContext* DOTParser::SubgraphContext::stmt_list() {
  return getRuleContext<DOTParser::Stmt_listContext>(0);
}

tree::TerminalNode* DOTParser::SubgraphContext::SUBGRAPH() {
  return getToken(DOTParser::SUBGRAPH, 0);
}

DOTParser::Id_Context* DOTParser::SubgraphContext::id_() {
  return getRuleContext<DOTParser::Id_Context>(0);
}


size_t DOTParser::SubgraphContext::getRuleIndex() const {
  return DOTParser::RuleSubgraph;
}

void DOTParser::SubgraphContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubgraph(this);
}

void DOTParser::SubgraphContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubgraph(this);
}


std::any DOTParser::SubgraphContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitSubgraph(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::SubgraphContext* DOTParser::subgraph() {
  SubgraphContext *_localctx = _tracker.createInstance<SubgraphContext>(_ctx, getState());
  enterRule(_localctx, 50, DOTParser::RuleSubgraph);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::SUBGRAPH) {
      setState(241);
      match(DOTParser::SUBGRAPH);
      setState(243);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32230080512) != 0)) {
        setState(242);
        id_();
      }
    }
    setState(247);
    match(DOTParser::T__0);
    setState(248);
    stmt_list();
    setState(249);
    match(DOTParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_Context ------------------------------------------------------------------

DOTParser::Id_Context::Id_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Id_Context::ID() {
  return getToken(DOTParser::ID, 0);
}

tree::TerminalNode* DOTParser::Id_Context::STRING() {
  return getToken(DOTParser::STRING, 0);
}

tree::TerminalNode* DOTParser::Id_Context::HTML_STRING() {
  return getToken(DOTParser::HTML_STRING, 0);
}

tree::TerminalNode* DOTParser::Id_Context::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}

tree::TerminalNode* DOTParser::Id_Context::SOURCE() {
  return getToken(DOTParser::SOURCE, 0);
}

tree::TerminalNode* DOTParser::Id_Context::SINK() {
  return getToken(DOTParser::SINK, 0);
}


size_t DOTParser::Id_Context::getRuleIndex() const {
  return DOTParser::RuleId_;
}

void DOTParser::Id_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_(this);
}

void DOTParser::Id_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_(this);
}


std::any DOTParser::Id_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitId_(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Id_Context* DOTParser::id_() {
  Id_Context *_localctx = _tracker.createInstance<Id_Context>(_ctx, getState());
  enterRule(_localctx, 52, DOTParser::RuleId_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32230080512) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void DOTParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  dotParserInitialize();
#else
  ::antlr4::internal::call_once(dotParserOnceFlag, dotParserInitialize);
#endif
}
