
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DOTLexer : public antlr4::Lexer {
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

