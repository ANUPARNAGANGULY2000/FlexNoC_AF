
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DOTLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, CV = 13, T_SERV = 14, 
    S_ATTR = 15, COEFF_VAR = 16, ZERO_LOAD = 17, DEPTH = 18, PRIORITY_NO = 19, 
    SIZE = 20, RATE = 21, LATENCY = 22, PIPELINE_DELAY = 23, SOURCE = 24, 
    QUEUE = 25, ARBITER = 26, ROUNDROBIN = 27, PRIORITY = 28, HYBRID = 29, 
    SERVER = 30, SPLIT = 31, SINK = 32, STRICT = 33, GRAPH = 34, DIGRAPH = 35, 
    NODE = 36, EDGE = 37, SUBGRAPH = 38, NUMBER = 39, STRING = 40, ID = 41, 
    HTML_STRING = 42, COMMENT = 43, LINE_COMMENT = 44, PREPROC = 45, WS = 46
  };

  explicit DOTLexer(antlr4::CharStream *input);

  ~DOTLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

