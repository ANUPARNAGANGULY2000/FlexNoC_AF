
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
      "depth_attr", "priority_attr", "rate_attr", "pipeline_delay_attr", 
      "map_attr", "mapPair", "latency_attr", "expr", "term", "type_attr", 
      "type_", "a_list", "attr_", "edge_stmt", "edgeRHS", "edgeop", "node_stmt", 
      "node_id", "port", "subgraph", "id_"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "';'", "'='", "'['", "']'", "','", "':'", "'+'", 
      "'type'", "'->'", "'--'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "CV", "T_SERV", 
      "S_ATTR", "COEFF_VAR", "ZERO_LOAD", "DEPTH", "PRIORITY_NO", "SIZE", 
      "RATE", "LATENCY", "PIPELINE_DELAY", "SOURCE", "QUEUE", "ARBITER", 
      "ROUNDROBIN", "PRIORITY", "HYBRID", "SERVER", "SPLIT", "SINK", "STRICT", 
      "GRAPH", "DIGRAPH", "NODE", "EDGE", "SUBGRAPH", "NUMBER", "STRING", 
      "ID", "HTML_STRING", "COMMENT", "LINE_COMMENT", "PREPROC", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,46,321,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,3,0,70,8,0,1,
  	0,1,0,3,0,74,8,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,3,1,83,8,1,5,1,85,8,1,10,
  	1,12,1,88,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,98,8,2,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,4,4,107,8,4,11,4,12,4,108,1,5,1,5,5,5,113,8,5,10,5,12,
  	5,116,9,5,1,5,1,5,5,5,120,8,5,10,5,12,5,123,9,5,1,5,1,5,4,5,127,8,5,11,
  	5,12,5,128,1,6,1,6,4,6,133,8,6,11,6,12,6,134,1,6,1,6,4,6,139,8,6,11,6,
  	12,6,140,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,155,8,7,
  	1,8,1,8,1,8,1,8,3,8,161,8,8,1,9,1,9,1,9,1,9,3,9,167,8,9,1,10,1,10,1,10,
  	1,10,3,10,173,8,10,1,11,1,11,1,11,1,11,3,11,179,8,11,1,12,1,12,1,12,1,
  	12,3,12,185,8,12,1,13,1,13,1,13,1,13,3,13,191,8,13,1,13,1,13,1,13,1,13,
  	3,13,197,8,13,3,13,199,8,13,1,14,1,14,1,14,1,14,3,14,205,8,14,1,15,1,
  	15,1,15,1,15,3,15,211,8,15,1,16,1,16,1,16,1,16,3,16,217,8,16,1,17,1,17,
  	1,17,1,17,1,17,1,17,5,17,225,8,17,10,17,12,17,228,9,17,1,17,1,17,3,17,
  	232,8,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,3,19,242,8,19,1,20,1,
  	20,1,20,5,20,247,8,20,10,20,12,20,250,9,20,1,21,1,21,3,21,254,8,21,1,
  	22,1,22,1,22,1,22,3,22,260,8,22,1,23,1,23,1,24,4,24,265,8,24,11,24,12,
  	24,266,1,25,1,25,1,25,3,25,272,8,25,1,25,3,25,275,8,25,1,26,1,26,3,26,
  	279,8,26,1,26,1,26,3,26,283,8,26,1,27,1,27,1,27,3,27,288,8,27,4,27,290,
  	8,27,11,27,12,27,291,1,28,1,28,1,29,1,29,1,29,1,30,1,30,3,30,301,8,30,
  	1,31,1,31,1,31,1,31,3,31,307,8,31,1,32,1,32,3,32,311,8,32,3,32,313,8,
  	32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,0,0,34,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,
  	66,0,6,1,0,34,35,2,0,34,34,36,37,2,0,3,3,7,7,1,0,24,32,1,0,11,12,2,0,
  	24,24,39,42,339,0,69,1,0,0,0,2,86,1,0,0,0,4,97,1,0,0,0,6,99,1,0,0,0,8,
  	106,1,0,0,0,10,126,1,0,0,0,12,138,1,0,0,0,14,154,1,0,0,0,16,156,1,0,0,
  	0,18,162,1,0,0,0,20,168,1,0,0,0,22,174,1,0,0,0,24,180,1,0,0,0,26,198,
  	1,0,0,0,28,200,1,0,0,0,30,206,1,0,0,0,32,212,1,0,0,0,34,218,1,0,0,0,36,
  	233,1,0,0,0,38,237,1,0,0,0,40,243,1,0,0,0,42,253,1,0,0,0,44,255,1,0,0,
  	0,46,261,1,0,0,0,48,264,1,0,0,0,50,268,1,0,0,0,52,278,1,0,0,0,54,289,
  	1,0,0,0,56,293,1,0,0,0,58,295,1,0,0,0,60,298,1,0,0,0,62,302,1,0,0,0,64,
  	312,1,0,0,0,66,318,1,0,0,0,68,70,5,33,0,0,69,68,1,0,0,0,69,70,1,0,0,0,
  	70,71,1,0,0,0,71,73,7,0,0,0,72,74,3,66,33,0,73,72,1,0,0,0,73,74,1,0,0,
  	0,74,75,1,0,0,0,75,76,5,1,0,0,76,77,3,2,1,0,77,78,5,2,0,0,78,79,5,0,0,
  	1,79,1,1,0,0,0,80,82,3,4,2,0,81,83,5,3,0,0,82,81,1,0,0,0,82,83,1,0,0,
  	0,83,85,1,0,0,0,84,80,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,
  	0,87,3,1,0,0,0,88,86,1,0,0,0,89,98,3,58,29,0,90,98,3,52,26,0,91,98,3,
  	6,3,0,92,93,3,66,33,0,93,94,5,4,0,0,94,95,3,66,33,0,95,98,1,0,0,0,96,
  	98,3,64,32,0,97,89,1,0,0,0,97,90,1,0,0,0,97,91,1,0,0,0,97,92,1,0,0,0,
  	97,96,1,0,0,0,98,5,1,0,0,0,99,100,7,1,0,0,100,101,3,8,4,0,101,7,1,0,0,
  	0,102,103,5,5,0,0,103,104,3,48,24,0,104,105,5,6,0,0,105,107,1,0,0,0,106,
  	102,1,0,0,0,107,108,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,9,1,0,
  	0,0,110,114,5,5,0,0,111,113,3,14,7,0,112,111,1,0,0,0,113,116,1,0,0,0,
  	114,112,1,0,0,0,114,115,1,0,0,0,115,117,1,0,0,0,116,114,1,0,0,0,117,121,
  	3,44,22,0,118,120,3,14,7,0,119,118,1,0,0,0,120,123,1,0,0,0,121,119,1,
  	0,0,0,121,122,1,0,0,0,122,124,1,0,0,0,123,121,1,0,0,0,124,125,5,6,0,0,
  	125,127,1,0,0,0,126,110,1,0,0,0,127,128,1,0,0,0,128,126,1,0,0,0,128,129,
  	1,0,0,0,129,11,1,0,0,0,130,132,5,5,0,0,131,133,3,14,7,0,132,131,1,0,0,
  	0,133,134,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,136,1,0,0,0,136,
  	137,5,6,0,0,137,139,1,0,0,0,138,130,1,0,0,0,139,140,1,0,0,0,140,138,1,
  	0,0,0,140,141,1,0,0,0,141,13,1,0,0,0,142,155,3,32,16,0,143,155,3,28,14,
  	0,144,155,3,16,8,0,145,155,3,26,13,0,146,155,3,30,15,0,147,155,3,18,9,
  	0,148,155,3,20,10,0,149,155,3,24,12,0,150,155,3,22,11,0,151,155,3,34,
  	17,0,152,155,3,38,19,0,153,155,3,50,25,0,154,142,1,0,0,0,154,143,1,0,
  	0,0,154,144,1,0,0,0,154,145,1,0,0,0,154,146,1,0,0,0,154,147,1,0,0,0,154,
  	148,1,0,0,0,154,149,1,0,0,0,154,150,1,0,0,0,154,151,1,0,0,0,154,152,1,
  	0,0,0,154,153,1,0,0,0,155,15,1,0,0,0,156,157,5,13,0,0,157,158,5,4,0,0,
  	158,160,5,39,0,0,159,161,7,2,0,0,160,159,1,0,0,0,160,161,1,0,0,0,161,
  	17,1,0,0,0,162,163,5,14,0,0,163,164,5,4,0,0,164,166,5,39,0,0,165,167,
  	7,2,0,0,166,165,1,0,0,0,166,167,1,0,0,0,167,19,1,0,0,0,168,169,5,16,0,
  	0,169,170,5,4,0,0,170,172,5,39,0,0,171,173,7,2,0,0,172,171,1,0,0,0,172,
  	173,1,0,0,0,173,21,1,0,0,0,174,175,5,15,0,0,175,176,5,4,0,0,176,178,5,
  	39,0,0,177,179,7,2,0,0,178,177,1,0,0,0,178,179,1,0,0,0,179,23,1,0,0,0,
  	180,181,5,17,0,0,181,182,5,4,0,0,182,184,5,39,0,0,183,185,7,2,0,0,184,
  	183,1,0,0,0,184,185,1,0,0,0,185,25,1,0,0,0,186,187,5,18,0,0,187,188,5,
  	4,0,0,188,190,5,39,0,0,189,191,7,2,0,0,190,189,1,0,0,0,190,191,1,0,0,
  	0,191,199,1,0,0,0,192,193,5,20,0,0,193,194,5,4,0,0,194,196,5,39,0,0,195,
  	197,7,2,0,0,196,195,1,0,0,0,196,197,1,0,0,0,197,199,1,0,0,0,198,186,1,
  	0,0,0,198,192,1,0,0,0,199,27,1,0,0,0,200,201,5,19,0,0,201,202,5,4,0,0,
  	202,204,5,39,0,0,203,205,7,2,0,0,204,203,1,0,0,0,204,205,1,0,0,0,205,
  	29,1,0,0,0,206,207,5,21,0,0,207,208,5,4,0,0,208,210,5,39,0,0,209,211,
  	7,2,0,0,210,209,1,0,0,0,210,211,1,0,0,0,211,31,1,0,0,0,212,213,5,23,0,
  	0,213,214,5,4,0,0,214,216,5,39,0,0,215,217,7,2,0,0,216,215,1,0,0,0,216,
  	217,1,0,0,0,217,33,1,0,0,0,218,219,3,66,33,0,219,220,5,4,0,0,220,221,
  	5,1,0,0,221,226,3,36,18,0,222,223,5,7,0,0,223,225,3,36,18,0,224,222,1,
  	0,0,0,225,228,1,0,0,0,226,224,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,0,
  	228,226,1,0,0,0,229,231,5,2,0,0,230,232,7,2,0,0,231,230,1,0,0,0,231,232,
  	1,0,0,0,232,35,1,0,0,0,233,234,3,66,33,0,234,235,5,8,0,0,235,236,5,39,
  	0,0,236,37,1,0,0,0,237,238,5,22,0,0,238,239,5,4,0,0,239,241,3,40,20,0,
  	240,242,7,2,0,0,241,240,1,0,0,0,241,242,1,0,0,0,242,39,1,0,0,0,243,248,
  	3,42,21,0,244,245,5,9,0,0,245,247,3,42,21,0,246,244,1,0,0,0,247,250,1,
  	0,0,0,248,246,1,0,0,0,248,249,1,0,0,0,249,41,1,0,0,0,250,248,1,0,0,0,
  	251,254,5,39,0,0,252,254,3,66,33,0,253,251,1,0,0,0,253,252,1,0,0,0,254,
  	43,1,0,0,0,255,256,5,10,0,0,256,257,5,4,0,0,257,259,3,46,23,0,258,260,
  	7,2,0,0,259,258,1,0,0,0,259,260,1,0,0,0,260,45,1,0,0,0,261,262,7,3,0,
  	0,262,47,1,0,0,0,263,265,3,50,25,0,264,263,1,0,0,0,265,266,1,0,0,0,266,
  	264,1,0,0,0,266,267,1,0,0,0,267,49,1,0,0,0,268,271,3,66,33,0,269,270,
  	5,4,0,0,270,272,3,66,33,0,271,269,1,0,0,0,271,272,1,0,0,0,272,274,1,0,
  	0,0,273,275,7,2,0,0,274,273,1,0,0,0,274,275,1,0,0,0,275,51,1,0,0,0,276,
  	279,3,60,30,0,277,279,3,64,32,0,278,276,1,0,0,0,278,277,1,0,0,0,279,280,
  	1,0,0,0,280,282,3,54,27,0,281,283,3,12,6,0,282,281,1,0,0,0,282,283,1,
  	0,0,0,283,53,1,0,0,0,284,287,3,56,28,0,285,288,3,60,30,0,286,288,3,64,
  	32,0,287,285,1,0,0,0,287,286,1,0,0,0,288,290,1,0,0,0,289,284,1,0,0,0,
  	290,291,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,55,1,0,0,0,293,294,
  	7,4,0,0,294,57,1,0,0,0,295,296,3,60,30,0,296,297,3,10,5,0,297,59,1,0,
  	0,0,298,300,3,66,33,0,299,301,3,62,31,0,300,299,1,0,0,0,300,301,1,0,0,
  	0,301,61,1,0,0,0,302,303,5,8,0,0,303,306,3,66,33,0,304,305,5,8,0,0,305,
  	307,3,66,33,0,306,304,1,0,0,0,306,307,1,0,0,0,307,63,1,0,0,0,308,310,
  	5,38,0,0,309,311,3,66,33,0,310,309,1,0,0,0,310,311,1,0,0,0,311,313,1,
  	0,0,0,312,308,1,0,0,0,312,313,1,0,0,0,313,314,1,0,0,0,314,315,5,1,0,0,
  	315,316,3,2,1,0,316,317,5,2,0,0,317,65,1,0,0,0,318,319,7,5,0,0,319,67,
  	1,0,0,0,40,69,73,82,86,97,108,114,121,128,134,140,154,160,166,172,178,
  	184,190,196,198,204,210,216,226,231,241,248,253,259,266,271,274,278,282,
  	287,291,300,306,310,312
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
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::STRICT) {
      setState(68);
      match(DOTParser::STRICT);
    }
    setState(71);
    _la = _input->LA(1);
    if (!(_la == DOTParser::GRAPH

    || _la == DOTParser::DIGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8246353985536) != 0)) {
      setState(72);
      id_();
    }
    setState(75);
    match(DOTParser::T__0);
    setState(76);
    stmt_list();
    setState(77);
    match(DOTParser::T__1);
    setState(78);
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
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8744570191874) != 0)) {
      setState(80);
      stmt();
      setState(82);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DOTParser::T__2) {
        setState(81);
        match(DOTParser::T__2);
      }
      setState(88);
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
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(89);
      node_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      edge_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(91);
      attr_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(92);
      id_();
      setState(93);
      match(DOTParser::T__3);
      setState(94);
      id_();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(96);
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
    setState(99);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 223338299392) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(100);
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
    setState(106); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(102);
      match(DOTParser::T__4);
      setState(103);
      a_list();
      setState(104);
      match(DOTParser::T__5);
      setState(108); 
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
    setState(126); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(110);
      match(DOTParser::T__4);
      setState(114);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8246370754560) != 0)) {
        setState(111);
        generic_attr();
        setState(116);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(117);
      type_attr();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8246370754560) != 0)) {
        setState(118);
        generic_attr();
        setState(123);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(124);
      match(DOTParser::T__5);
      setState(128); 
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
    setState(138); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(130);
      match(DOTParser::T__4);
      setState(132); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(131);
        generic_attr();
        setState(134); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8246370754560) != 0));
      setState(136);
      match(DOTParser::T__5);
      setState(140); 
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

DOTParser::Pipeline_delay_attrContext* DOTParser::Generic_attrContext::pipeline_delay_attr() {
  return getRuleContext<DOTParser::Pipeline_delay_attrContext>(0);
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

DOTParser::Latency_attrContext* DOTParser::Generic_attrContext::latency_attr() {
  return getRuleContext<DOTParser::Latency_attrContext>(0);
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
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      pipeline_delay_attr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(143);
      priority_attr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(144);
      cv_attr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(145);
      depth_attr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(146);
      rate_attr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(147);
      service_time_attr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(148);
      coeff_service_time_attr();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(149);
      zero_load_latency_attr();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(150);
      split_attr();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(151);
      map_attr();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(152);
      latency_attr();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(153);
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
    setState(156);
    match(DOTParser::CV);
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
    setState(162);
    match(DOTParser::T_SERV);
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
    setState(168);
    match(DOTParser::COEFF_VAR);
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
    setState(174);
    match(DOTParser::S_ATTR);
    setState(175);
    match(DOTParser::T__3);
    setState(176);
    match(DOTParser::NUMBER);
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(177);
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
    setState(180);
    match(DOTParser::ZERO_LOAD);
    setState(181);
    match(DOTParser::T__3);
    setState(182);
    match(DOTParser::NUMBER);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(183);
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
    setState(198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DOTParser::DEPTH: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        match(DOTParser::DEPTH);
        setState(187);
        match(DOTParser::T__3);
        setState(188);
        match(DOTParser::NUMBER);
        setState(190);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DOTParser::T__2

        || _la == DOTParser::T__6) {
          setState(189);
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
        setState(192);
        match(DOTParser::SIZE);
        setState(193);
        match(DOTParser::T__3);
        setState(194);
        match(DOTParser::NUMBER);
        setState(196);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DOTParser::T__2

        || _la == DOTParser::T__6) {
          setState(195);
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
    setState(200);
    match(DOTParser::PRIORITY_NO);
    setState(201);
    match(DOTParser::T__3);
    setState(202);
    match(DOTParser::NUMBER);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(203);
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
    setState(206);
    match(DOTParser::RATE);
    setState(207);
    match(DOTParser::T__3);
    setState(208);
    match(DOTParser::NUMBER);
    setState(210);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(209);
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

//----------------- Pipeline_delay_attrContext ------------------------------------------------------------------

DOTParser::Pipeline_delay_attrContext::Pipeline_delay_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Pipeline_delay_attrContext::PIPELINE_DELAY() {
  return getToken(DOTParser::PIPELINE_DELAY, 0);
}

tree::TerminalNode* DOTParser::Pipeline_delay_attrContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}


size_t DOTParser::Pipeline_delay_attrContext::getRuleIndex() const {
  return DOTParser::RulePipeline_delay_attr;
}

void DOTParser::Pipeline_delay_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPipeline_delay_attr(this);
}

void DOTParser::Pipeline_delay_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPipeline_delay_attr(this);
}


std::any DOTParser::Pipeline_delay_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitPipeline_delay_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Pipeline_delay_attrContext* DOTParser::pipeline_delay_attr() {
  Pipeline_delay_attrContext *_localctx = _tracker.createInstance<Pipeline_delay_attrContext>(_ctx, getState());
  enterRule(_localctx, 32, DOTParser::RulePipeline_delay_attr);
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
    setState(212);
    match(DOTParser::PIPELINE_DELAY);
    setState(213);
    match(DOTParser::T__3);
    setState(214);
    match(DOTParser::NUMBER);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(215);
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
  enterRule(_localctx, 34, DOTParser::RuleMap_attr);
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
    setState(218);
    id_();
    setState(219);
    match(DOTParser::T__3);
    setState(220);
    match(DOTParser::T__0);
    setState(221);
    mapPair();
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DOTParser::T__6) {
      setState(222);
      match(DOTParser::T__6);
      setState(223);
      mapPair();
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(229);
    match(DOTParser::T__1);
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(230);
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
  enterRule(_localctx, 36, DOTParser::RuleMapPair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    id_();
    setState(234);
    match(DOTParser::T__7);
    setState(235);
    match(DOTParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Latency_attrContext ------------------------------------------------------------------

DOTParser::Latency_attrContext::Latency_attrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::Latency_attrContext::LATENCY() {
  return getToken(DOTParser::LATENCY, 0);
}

DOTParser::ExprContext* DOTParser::Latency_attrContext::expr() {
  return getRuleContext<DOTParser::ExprContext>(0);
}


size_t DOTParser::Latency_attrContext::getRuleIndex() const {
  return DOTParser::RuleLatency_attr;
}

void DOTParser::Latency_attrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLatency_attr(this);
}

void DOTParser::Latency_attrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLatency_attr(this);
}


std::any DOTParser::Latency_attrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitLatency_attr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::Latency_attrContext* DOTParser::latency_attr() {
  Latency_attrContext *_localctx = _tracker.createInstance<Latency_attrContext>(_ctx, getState());
  enterRule(_localctx, 38, DOTParser::RuleLatency_attr);
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
    setState(237);
    match(DOTParser::LATENCY);
    setState(238);
    match(DOTParser::T__3);
    setState(239);
    expr();
    setState(241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(240);
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

//----------------- ExprContext ------------------------------------------------------------------

DOTParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DOTParser::TermContext *> DOTParser::ExprContext::term() {
  return getRuleContexts<DOTParser::TermContext>();
}

DOTParser::TermContext* DOTParser::ExprContext::term(size_t i) {
  return getRuleContext<DOTParser::TermContext>(i);
}


size_t DOTParser::ExprContext::getRuleIndex() const {
  return DOTParser::RuleExpr;
}

void DOTParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void DOTParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any DOTParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::ExprContext* DOTParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 40, DOTParser::RuleExpr);
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
    setState(243);
    term();
    setState(248);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DOTParser::T__8) {
      setState(244);
      match(DOTParser::T__8);
      setState(245);
      term();
      setState(250);
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

//----------------- TermContext ------------------------------------------------------------------

DOTParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DOTParser::TermContext::NUMBER() {
  return getToken(DOTParser::NUMBER, 0);
}

DOTParser::Id_Context* DOTParser::TermContext::id_() {
  return getRuleContext<DOTParser::Id_Context>(0);
}


size_t DOTParser::TermContext::getRuleIndex() const {
  return DOTParser::RuleTerm;
}

void DOTParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void DOTParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DOTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any DOTParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DOTVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

DOTParser::TermContext* DOTParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 42, DOTParser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(251);
      match(DOTParser::NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(252);
      id_();
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
  enterRule(_localctx, 44, DOTParser::RuleType_attr);
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
    match(DOTParser::T__9);
    setState(256);
    match(DOTParser::T__3);
    setState(257);
    type_();
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(258);
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
  enterRule(_localctx, 46, DOTParser::RuleType_);
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
    setState(261);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8573157376) != 0))) {
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
  enterRule(_localctx, 48, DOTParser::RuleA_list);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(263);
      attr_();
      setState(266); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8246353985536) != 0));
   
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
  enterRule(_localctx, 50, DOTParser::RuleAttr_);
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
    id_();
    setState(271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__3) {
      setState(269);
      match(DOTParser::T__3);
      setState(270);
      id_();
    }
    setState(274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__2

    || _la == DOTParser::T__6) {
      setState(273);
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
  enterRule(_localctx, 52, DOTParser::RuleEdge_stmt);
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
    switch (_input->LA(1)) {
      case DOTParser::SOURCE:
      case DOTParser::NUMBER:
      case DOTParser::STRING:
      case DOTParser::ID:
      case DOTParser::HTML_STRING: {
        setState(276);
        node_id();
        break;
      }

      case DOTParser::T__0:
      case DOTParser::SUBGRAPH: {
        setState(277);
        subgraph();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(280);
    edgeRHS();
    setState(282);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__4) {
      setState(281);
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
  enterRule(_localctx, 54, DOTParser::RuleEdgeRHS);
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
    setState(289); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(284);
      edgeop();
      setState(287);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DOTParser::SOURCE:
        case DOTParser::NUMBER:
        case DOTParser::STRING:
        case DOTParser::ID:
        case DOTParser::HTML_STRING: {
          setState(285);
          node_id();
          break;
        }

        case DOTParser::T__0:
        case DOTParser::SUBGRAPH: {
          setState(286);
          subgraph();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(291); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DOTParser::T__10

    || _la == DOTParser::T__11);
   
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
  enterRule(_localctx, 56, DOTParser::RuleEdgeop);
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
    setState(293);
    _la = _input->LA(1);
    if (!(_la == DOTParser::T__10

    || _la == DOTParser::T__11)) {
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
  enterRule(_localctx, 58, DOTParser::RuleNode_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    node_id();
    setState(296);
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
  enterRule(_localctx, 60, DOTParser::RuleNode_id);
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
    setState(298);
    id_();
    setState(300);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__7) {
      setState(299);
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
  enterRule(_localctx, 62, DOTParser::RulePort);
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
    setState(302);
    match(DOTParser::T__7);
    setState(303);
    id_();
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::T__7) {
      setState(304);
      match(DOTParser::T__7);
      setState(305);
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
  enterRule(_localctx, 64, DOTParser::RuleSubgraph);
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
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DOTParser::SUBGRAPH) {
      setState(308);
      match(DOTParser::SUBGRAPH);
      setState(310);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8246353985536) != 0)) {
        setState(309);
        id_();
      }
    }
    setState(314);
    match(DOTParser::T__0);
    setState(315);
    stmt_list();
    setState(316);
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
  enterRule(_localctx, 66, DOTParser::RuleId_);
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
    setState(318);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8246353985536) != 0))) {
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
