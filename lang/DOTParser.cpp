
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
      "coeff_service_time_attr", "split_attr", "zero_load_latency_attr", 
      "depth_attr", "priority_attr", "rate_attr", "map_attr", "mapPair", 
      "type_attr", "type_", "a_list", "attr_", "edge_stmt", "edgeRHS", "edgeop", 
      "node_stmt", "node_id", "port", "subgraph", "id_"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "';'", "'='", "'['", "']'", "','", "':'", "'type'", 
      "'->'", "'--'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "CV", "T_SERV", "S_ATTR", 
      "COEFF_VAR", "ZERO_LOAD", "DEPTH", "PRIORITY_NO", "SIZE", "RATE", 
      "SOURCE", "QUEUE", "ARBITER", "ROUNDROBIN", "PRIORITY", "HYBRID", 
      "SERVER", "SPLIT", "SINK", "STRICT", "GRAPH", "DIGRAPH", "NODE", "EDGE", 
      "SUBGRAPH", "NUMBER", "STRING", "ID", "HTML_STRING", "COMMENT", "LINE_COMMENT", 
      "PREPROC", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,43,287,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,3,0,62,8,0,1,0,1,0,3,0,66,8,0,1,0,1,0,1,0,1,0,1,0,1,
  	1,1,1,3,1,75,8,1,5,1,77,8,1,10,1,12,1,80,9,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,3,2,90,8,2,1,3,1,3,1,3,1,4,1,4,1,4,1,4,4,4,99,8,4,11,4,12,4,100,
  	1,5,1,5,5,5,105,8,5,10,5,12,5,108,9,5,1,5,1,5,5,5,112,8,5,10,5,12,5,115,
  	9,5,1,5,1,5,4,5,119,8,5,11,5,12,5,120,1,6,1,6,4,6,125,8,6,11,6,12,6,126,
  	1,6,1,6,4,6,131,8,6,11,6,12,6,132,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,3,7,145,8,7,1,8,1,8,1,8,1,8,3,8,151,8,8,1,9,1,9,1,9,1,9,3,9,157,8,
  	9,1,10,1,10,1,10,1,10,3,10,163,8,10,1,11,1,11,1,11,1,11,3,11,169,8,11,
  	1,12,1,12,1,12,1,12,3,12,175,8,12,1,13,1,13,1,13,1,13,3,13,181,8,13,1,
  	13,1,13,1,13,1,13,3,13,187,8,13,3,13,189,8,13,1,14,1,14,1,14,1,14,3,14,
  	195,8,14,1,15,1,15,1,15,1,15,3,15,201,8,15,1,16,1,16,1,16,1,16,1,16,1,
  	16,5,16,209,8,16,10,16,12,16,212,9,16,1,16,1,16,3,16,216,8,16,1,17,1,
  	17,1,17,1,17,1,18,1,18,1,18,1,18,3,18,226,8,18,1,19,1,19,1,20,4,20,231,
  	8,20,11,20,12,20,232,1,21,1,21,1,21,3,21,238,8,21,1,21,3,21,241,8,21,
  	1,22,1,22,3,22,245,8,22,1,22,1,22,3,22,249,8,22,1,23,1,23,1,23,3,23,254,
  	8,23,4,23,256,8,23,11,23,12,23,257,1,24,1,24,1,25,1,25,1,25,1,26,1,26,
  	3,26,267,8,26,1,27,1,27,1,27,1,27,3,27,273,8,27,1,28,1,28,3,28,277,8,
  	28,3,28,279,8,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,0,0,30,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,0,6,1,0,31,32,2,0,31,31,33,34,2,0,3,3,7,7,1,0,21,29,1,0,10,11,2,
  	0,21,21,36,39,303,0,61,1,0,0,0,2,78,1,0,0,0,4,89,1,0,0,0,6,91,1,0,0,0,
  	8,98,1,0,0,0,10,118,1,0,0,0,12,130,1,0,0,0,14,144,1,0,0,0,16,146,1,0,
  	0,0,18,152,1,0,0,0,20,158,1,0,0,0,22,164,1,0,0,0,24,170,1,0,0,0,26,188,
  	1,0,0,0,28,190,1,0,0,0,30,196,1,0,0,0,32,202,1,0,0,0,34,217,1,0,0,0,36,
  	221,1,0,0,0,38,227,1,0,0,0,40,230,1,0,0,0,42,234,1,0,0,0,44,244,1,0,0,
  	0,46,255,1,0,0,0,48,259,1,0,0,0,50,261,1,0,0,0,52,264,1,0,0,0,54,268,
  	1,0,0,0,56,278,1,0,0,0,58,284,1,0,0,0,60,62,5,30,0,0,61,60,1,0,0,0,61,
  	62,1,0,0,0,62,63,1,0,0,0,63,65,7,0,0,0,64,66,3,58,29,0,65,64,1,0,0,0,
  	65,66,1,0,0,0,66,67,1,0,0,0,67,68,5,1,0,0,68,69,3,2,1,0,69,70,5,2,0,0,
  	70,71,5,0,0,1,71,1,1,0,0,0,72,74,3,4,2,0,73,75,5,3,0,0,74,73,1,0,0,0,
  	74,75,1,0,0,0,75,77,1,0,0,0,76,72,1,0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,
  	78,79,1,0,0,0,79,3,1,0,0,0,80,78,1,0,0,0,81,90,3,50,25,0,82,90,3,44,22,
  	0,83,90,3,6,3,0,84,85,3,58,29,0,85,86,5,4,0,0,86,87,3,58,29,0,87,90,1,
  	0,0,0,88,90,3,56,28,0,89,81,1,0,0,0,89,82,1,0,0,0,89,83,1,0,0,0,89,84,
  	1,0,0,0,89,88,1,0,0,0,90,5,1,0,0,0,91,92,7,1,0,0,92,93,3,8,4,0,93,7,1,
  	0,0,0,94,95,5,5,0,0,95,96,3,40,20,0,96,97,5,6,0,0,97,99,1,0,0,0,98,94,
  	1,0,0,0,99,100,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,9,1,0,0,0,102,
  	106,5,5,0,0,103,105,3,14,7,0,104,103,1,0,0,0,105,108,1,0,0,0,106,104,
  	1,0,0,0,106,107,1,0,0,0,107,109,1,0,0,0,108,106,1,0,0,0,109,113,3,36,
  	18,0,110,112,3,14,7,0,111,110,1,0,0,0,112,115,1,0,0,0,113,111,1,0,0,0,
  	113,114,1,0,0,0,114,116,1,0,0,0,115,113,1,0,0,0,116,117,5,6,0,0,117,119,
  	1,0,0,0,118,102,1,0,0,0,119,120,1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,
  	0,121,11,1,0,0,0,122,124,5,5,0,0,123,125,3,14,7,0,124,123,1,0,0,0,125,
  	126,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,128,1,0,0,0,128,129,5,
  	6,0,0,129,131,1,0,0,0,130,122,1,0,0,0,131,132,1,0,0,0,132,130,1,0,0,0,
  	132,133,1,0,0,0,133,13,1,0,0,0,134,145,3,28,14,0,135,145,3,16,8,0,136,
  	145,3,26,13,0,137,145,3,30,15,0,138,145,3,18,9,0,139,145,3,20,10,0,140,
  	145,3,24,12,0,141,145,3,22,11,0,142,145,3,32,16,0,143,145,3,42,21,0,144,
  	134,1,0,0,0,144,135,1,0,0,0,144,136,1,0,0,0,144,137,1,0,0,0,144,138,1,
  	0,0,0,144,139,1,0,0,0,144,140,1,0,0,0,144,141,1,0,0,0,144,142,1,0,0,0,
  	144,143,1,0,0,0,145,15,1,0,0,0,146,147,5,12,0,0,147,148,5,4,0,0,148,150,
  	5,36,0,0,149,151,7,2,0,0,150,149,1,0,0,0,150,151,1,0,0,0,151,17,1,0,0,
  	0,152,153,5,13,0,0,153,154,5,4,0,0,154,156,5,36,0,0,155,157,7,2,0,0,156,
  	155,1,0,0,0,156,157,1,0,0,0,157,19,1,0,0,0,158,159,5,15,0,0,159,160,5,
  	4,0,0,160,162,5,36,0,0,161,163,7,2,0,0,162,161,1,0,0,0,162,163,1,0,0,
  	0,163,21,1,0,0,0,164,165,5,14,0,0,165,166,5,4,0,0,166,168,5,36,0,0,167,
  	169,7,2,0,0,168,167,1,0,0,0,168,169,1,0,0,0,169,23,1,0,0,0,170,171,5,
  	16,0,0,171,172,5,4,0,0,172,174,5,36,0,0,173,175,7,2,0,0,174,173,1,0,0,
  	0,174,175,1,0,0,0,175,25,1,0,0,0,176,177,5,17,0,0,177,178,5,4,0,0,178,
  	180,5,36,0,0,179,181,7,2,0,0,180,179,1,0,0,0,180,181,1,0,0,0,181,189,
  	1,0,0,0,182,183,5,19,0,0,183,184,5,4,0,0,184,186,5,36,0,0,185,187,7,2,
  	0,0,186,185,1,0,0,0,186,187,1,0,0,0,187,189,1,0,0,0,188,176,1,0,0,0,188,
  	182,1,0,0,0,189,27,1,0,0,0,190,191,5,18,0,0,191,192,5,4,0,0,192,194,5,
  	36,0,0,193,195,7,2,0,0,194,193,1,0,0,0,194,195,1,0,0,0,195,29,1,0,0,0,
  	196,197,5,20,0,0,197,198,5,4,0,0,198,200,5,36,0,0,199,201,7,2,0,0,200,
  	199,1,0,0,0,200,201,1,0,0,0,201,31,1,0,0,0,202,203,3,58,29,0,203,204,
  	5,4,0,0,204,205,5,1,0,0,205,210,3,34,17,0,206,207,5,7,0,0,207,209,3,34,
  	17,0,208,206,1,0,0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,1,0,0,0,
  	211,213,1,0,0,0,212,210,1,0,0,0,213,215,5,2,0,0,214,216,7,2,0,0,215,214,
  	1,0,0,0,215,216,1,0,0,0,216,33,1,0,0,0,217,218,3,58,29,0,218,219,5,8,
  	0,0,219,220,5,36,0,0,220,35,1,0,0,0,221,222,5,9,0,0,222,223,5,4,0,0,223,
  	225,3,38,19,0,224,226,7,2,0,0,225,224,1,0,0,0,225,226,1,0,0,0,226,37,
  	1,0,0,0,227,228,7,3,0,0,228,39,1,0,0,0,229,231,3,42,21,0,230,229,1,0,
  	0,0,231,232,1,0,0,0,232,230,1,0,0,0,232,233,1,0,0,0,233,41,1,0,0,0,234,
  	237,3,58,29,0,235,236,5,4,0,0,236,238,3,58,29,0,237,235,1,0,0,0,237,238,
  	1,0,0,0,238,240,1,0,0,0,239,241,7,2,0,0,240,239,1,0,0,0,240,241,1,0,0,
  	0,241,43,1,0,0,0,242,245,3,52,26,0,243,245,3,56,28,0,244,242,1,0,0,0,
  	244,243,1,0,0,0,245,246,1,0,0,0,246,248,3,46,23,0,247,249,3,12,6,0,248,
  	247,1,0,0,0,248,249,1,0,0,0,249,45,1,0,0,0,250,253,3,48,24,0,251,254,
  	3,52,26,0,252,254,3,56,28,0,253,251,1,0,0,0,253,252,1,0,0,0,254,256,1,
  	0,0,0,255,250,1,0,0,0,256,257,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,
  	258,47,1,0,0,0,259,260,7,4,0,0,260,49,1,0,0,0,261,262,3,52,26,0,262,263,
  	3,10,5,0,263,51,1,0,0,0,264,266,3,58,29,0,265,267,3,54,27,0,266,265,1,
  	0,0,0,266,267,1,0,0,0,267,53,1,0,0,0,268,269,5,8,0,0,269,272,3,58,29,
  	0,270,271,5,8,0,0,271,273,3,58,29,0,272,270,1,0,0,0,272,273,1,0,0,0,273,
  	55,1,0,0,0,274,276,5,35,0,0,275,277,3,58,29,0,276,275,1,0,0,0,276,277,
  	1,0,0,0,277,279,1,0,0,0,278,274,1,0,0,0,278,279,1,0,0,0,279,280,1,0,0,
  	0,280,281,5,1,0,0,281,282,3,2,1,0,282,283,5,2,0,0,283,57,1,0,0,0,284,
  	285,7,5,0,0,285,59,1,0,0,0,36,61,65,74,78,89,100,106,113,120,126,132,
  	144,150,156,162,168,174,180,186,188,194,200,210,215,225,232,237,240,244,
  	248,253,257,266,272,276,278
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
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::STRICT) {
      setState(60);
      match(DOTParser::STRICT);
    }
    setState(63);
    _la = _input->LA(1);
    if (!(_la == DOTParser::GRAPH

    || _la == DOTParser::DIGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1030794248192) != 0)) {
      setState(64);
      id_();
    }
    setState(67);
    match(DOTParser::T__0);
    setState(68);
    stmt_list();
    setState(69);
    match(DOTParser::T__1);
    setState(70);
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
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1093071273986) != 0)) {
      setState(72);
      stmt();
      setState(74);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__2) {
        setState(73);
        match(DOTParser::T__2);
      }
      setState(80);
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
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      node_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
      edge_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(83);
      attr_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(84);
      id_();
      setState(85);
      match(DOTParser::T__3);
      setState(86);
      id_();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(88);
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
    setState(91);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 27917287424) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(92);
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
    setState(98); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(94);
      match(DOTParser::T__4);
      setState(95);
      a_list();
      setState(96);
      match(DOTParser::T__5);
      setState(100); 
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
    setState(118); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(102);
      match(DOTParser::T__4);
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1030796341248) != 0)) {
        setState(103);
        generic_attr();
        setState(108);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(109);
      type_attr();
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1030796341248) != 0)) {
        setState(110);
        generic_attr();
        setState(115);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(116);
      match(DOTParser::T__5);
      setState(120); 
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
    setState(130); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(122);
      match(DOTParser::T__4);
      setState(124); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(123);
        generic_attr();
        setState(126); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1030796341248) != 0));
      setState(128);
      match(DOTParser::T__5);
      setState(132); 
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

DOTParser::Priority_attrContext* DOTParser::Generic_attrContext::priority_attr() {
  return getRuleContext<DOTParser::Priority_attrContext>(0);
}

DOTParser::Cv_attrContext* DOTParser::Generic_attrContext::cv_attr() {
  return getRuleContext<DOTParser::Cv_attrContext>(0);
}

DOTParser::Depth_attrContext* DOTParser::Generic_attrContext::depth_attr() {
  return getRuleContext<DOTParser::Depth_attrContext>(0);
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

DOTParser::Split_attrContext* DOTParser::Generic_attrContext::split_attr() {
  return getRuleContext<DOTParser::Split_attrContext>(0);
}

DOTParser::Map_attrContext* DOTParser::Generic_attrContext::map_attr() {
  return getRuleContext<DOTParser::Map_attrContext>(0);
}

DOTParser::Attr_Context* DOTParser::Generic_attrContext::attr_() {
  return getRuleContext<DOTParser::Attr_Context>(0);
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
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      priority_attr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(135);
      cv_attr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(136);
      depth_attr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(137);
      rate_attr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(138);
      service_time_attr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(139);
      coeff_service_time_attr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(140);
      zero_load_latency_attr();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(141);
      split_attr();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(142);
      map_attr();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(143);
      attr_();
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
    setState(146);
    match(DOTParser::CV);
    setState(147);
    match(DOTParser::T__3);
    setState(148);
    match(DOTParser::NUMBER);
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(149);
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
    setState(152);
    match(DOTParser::T_SERV);
    setState(153);
    match(DOTParser::T__3);
    setState(154);
    match(DOTParser::NUMBER);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(155);
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
    setState(158);
    match(DOTParser::COEFF_VAR);
    setState(159);
    match(DOTParser::T__3);
    setState(160);
    match(DOTParser::NUMBER);
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(161);
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

//----------------- Split_attrContext ------------------------------------------------------------------

DOTParser::Split_attrContext::Split_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Split_attrContext::S_ATTR() {
  return getToken(DOTParser::S_ATTR, 0);
}

tree::TerminalNode* DOTParser::Split_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Split_attrContext::getRuleIndex() const {
  return DOTParser::RuleSplit_attr;
}

void DOTParser::Split_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSplit_attr(this);
}

void DOTParser::Split_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSplit_attr(this);
}


std::any DOTParser::Split_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitSplit_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Split_attrContext* DOTParser::split_attr() {
  Split_attrContext *_localctx = _tracker.createInstance<Split_attrContext>(_ctx, getState());
  enterRule(_localctx, 22, DOTParser::RuleSplit_attr);
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
    setState(164);
    match(DOTParser::S_ATTR);
    setState(165);
    match(DOTParser::T__3);
    setState(166);
    match(DOTParser::NUMBER);
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(167);
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
  enterRule(_localctx, 24, DOTParser::RuleZero_load_latency_attr);
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
    setState(170);
    match(DOTParser::ZERO_LOAD);
    setState(171);
    match(DOTParser::T__3);
    setState(172);
    match(DOTParser::NUMBER);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(173);
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
  enterRule(_localctx, 26, DOTParser::RuleDepth_attr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::DEPTH: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        match(DOTParser::DEPTH);
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
        break;
      }

      case DOTParser::SIZE: {
        enterOuterAlt(_localctx, 2);
        setState(182);
        match(DOTParser::SIZE);
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

tree::TerminalNode* DOTParser::Priority_attrContext::PRIORITY_NO() {
  return getToken(DOTParser::PRIORITY_NO, 0);
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
  enterRule(_localctx, 28, DOTParser::RulePriority_attr);
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
    setState(190);
    match(DOTParser::PRIORITY_NO);
    setState(191);
    match(DOTParser::T__3);
    setState(192);
    match(DOTParser::NUMBER);
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(193);
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
  enterRule(_localctx, 30, DOTParser::RuleRate_attr);
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
    setState(196);
    match(DOTParser::RATE);
    setState(197);
    match(DOTParser::T__3);
    setState(198);
    match(DOTParser::NUMBER);
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(199);
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

//----------------- Map_attrContext ------------------------------------------------------------------

DOTParser::Map_attrContext::Map_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Id_Context* DOTParser::Map_attrContext::id_() {
  return getRuleContext<DOTParser::Id_Context>(0);
}

std::vector<DOTParser::MapPairContext *> DOTParser::Map_attrContext::mapPair() {
  return getRuleContexts<DOTParser::MapPairContext>();
}

DOTParser::MapPairContext* DOTParser::Map_attrContext::mapPair(size_t i) {
  return getRuleContext<DOTParser::MapPairContext>(i);
}


size_t DOTParser::Map_attrContext::getRuleIndex() const {
  return DOTParser::RuleMap_attr;
}

void DOTParser::Map_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMap_attr(this);
}

void DOTParser::Map_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMap_attr(this);
}


std::any DOTParser::Map_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitMap_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Map_attrContext* DOTParser::map_attr() {
  Map_attrContext *_localctx = _tracker.createInstance<Map_attrContext>(_ctx, getState());
  enterRule(_localctx, 32, DOTParser::RuleMap_attr);
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
    setState(202);
    id_();
    setState(203);
    match(DOTParser::T__3);
    setState(204);
    match(DOTParser::T__0);
    setState(205);
    mapPair();
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DOTParser::T__6) {
      setState(206);
      match(DOTParser::T__6);
      setState(207);
      mapPair();
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(213);
    match(DOTParser::T__1);
    setState(215);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(214);
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

//----------------- MapPairContext ------------------------------------------------------------------

DOTParser::MapPairContext::MapPairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DOTParser::Id_Context* DOTParser::MapPairContext::id_() {
  return getRuleContext<DOTParser::Id_Context>(0);
}

tree::TerminalNode* DOTParser::MapPairContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::MapPairContext::getRuleIndex() const {
  return DOTParser::RuleMapPair;
}

void DOTParser::MapPairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapPair(this);
}

void DOTParser::MapPairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapPair(this);
}


std::any DOTParser::MapPairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitMapPair(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::MapPairContext* DOTParser::mapPair() {
  MapPairContext *_localctx = _tracker.createInstance<MapPairContext>(_ctx, getState());
  enterRule(_localctx, 34, DOTParser::RuleMapPair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    id_();
    setState(218);
    match(DOTParser::T__7);
    setState(219);
    match(DOTParser::NUMBER);
   
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
  enterRule(_localctx, 36, DOTParser::RuleType_attr);
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
    setState(221);
    match(DOTParser::T__8);
    setState(222);
    match(DOTParser::T__3);
    setState(223);
    type_();
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(224);
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

tree::TerminalNode* DOTParser::Type_Context::ROUNDROBIN() {
  return getToken(DOTParser::ROUNDROBIN, 0);
}

tree::TerminalNode* DOTParser::Type_Context::PRIORITY() {
  return getToken(DOTParser::PRIORITY, 0);
}

tree::TerminalNode* DOTParser::Type_Context::HYBRID() {
  return getToken(DOTParser::HYBRID, 0);
}

tree::TerminalNode* DOTParser::Type_Context::SERVER() {
  return getToken(DOTParser::SERVER, 0);
}

tree::TerminalNode* DOTParser::Type_Context::SPLIT() {
  return getToken(DOTParser::SPLIT, 0);
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
  enterRule(_localctx, 38, DOTParser::RuleType_);
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
    setState(227);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1071644672) != 0))) {
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
  enterRule(_localctx, 40, DOTParser::RuleA_list);
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
    setState(230); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(229);
      attr_();
      setState(232); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1030794248192) != 0));
   
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
  enterRule(_localctx, 42, DOTParser::RuleAttr_);
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
    setState(234);
    id_();
    setState(237);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__3) {
      setState(235);
      match(DOTParser::T__3);
      setState(236);
      id_();
    }
    setState(240);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(239);
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
  enterRule(_localctx, 44, DOTParser::RuleEdge_stmt);
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
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::SOURCE:
      case DOTParser::NUMBER:
      case DOTParser::STRING:
      case DOTParser::ID:
      case DOTParser::HTML_STRING: {
        setState(242);
        node_id();
        break;
      }

      case DOTParser::T__0:
      case DOTParser::SUBGRAPH: {
        setState(243);
        subgraph();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(246);
    edgeRHS();
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__4) {
      setState(247);
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
  enterRule(_localctx, 46, DOTParser::RuleEdgeRHS);
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
    setState(255); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(250);
      edgeop();
      setState(253);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DOTParser::SOURCE:
        case DOTParser::NUMBER:
        case DOTParser::STRING:
        case DOTParser::ID:
        case DOTParser::HTML_STRING: {
          setState(251);
          node_id();
          break;
        }

        case DOTParser::T__0:
        case DOTParser::SUBGRAPH: {
          setState(252);
          subgraph();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(257); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__9

    || _la == DOTParser::T__10);
   
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
  enterRule(_localctx, 48, DOTParser::RuleEdgeop);
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
    setState(259);
    _la = _input->LA(1);
    if (!(_la == DOTParser::T__9

    || _la == DOTParser::T__10)) {
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
  enterRule(_localctx, 50, DOTParser::RuleNode_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    node_id();
    setState(262);
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
  enterRule(_localctx, 52, DOTParser::RuleNode_id);
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
    setState(264);
    id_();
    setState(266);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__7) {
      setState(265);
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
  enterRule(_localctx, 54, DOTParser::RulePort);
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
    setState(268);
    match(DOTParser::T__7);
    setState(269);
    id_();
    setState(272);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__7) {
      setState(270);
      match(DOTParser::T__7);
      setState(271);
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
  enterRule(_localctx, 56, DOTParser::RuleSubgraph);
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
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::SUBGRAPH) {
      setState(274);
      match(DOTParser::SUBGRAPH);
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1030794248192) != 0)) {
        setState(275);
        id_();
      }
    }
    setState(280);
    match(DOTParser::T__0);
    setState(281);
    stmt_list();
    setState(282);
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
  enterRule(_localctx, 58, DOTParser::RuleId_);
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
    setState(284);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1030794248192) != 0))) {
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
