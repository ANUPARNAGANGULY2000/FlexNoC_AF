
// Generated from DOT.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DOTLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, CV = 12, T_SERV = 13, COEFF_VAR = 14, 
    ZERO_LOAD = 15, DEPTH = 16, SIZE = 17, PRIORITY = 18, RATE = 19, SOURCE = 20, 
    QUEUE = 21, ARBITER = 22, SERVER = 23, SINK = 24, STRICT = 25, GRAPH = 26, 
    DIGRAPH = 27, NODE = 28, EDGE = 29, SUBGRAPH = 30, NUMBER = 31, STRING = 32, 
    ID = 33, HTML_STRING = 34, COMMENT = 35, LINE_COMMENT = 36, PREPROC = 37, 
    WS = 38
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

