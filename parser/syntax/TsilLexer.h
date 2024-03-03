
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_SAVE = 3, KW_DELETE = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_RETURN = 8, KW_STRUCT = 9, KW_EXTERN = 10, KW_AS = 11, 
    EQUAL = 12, GREATER = 13, LESSER = 14, DOT = 15, PLUS = 16, MINUS = 17, 
    MULTIPLY = 18, DIVIDE = 19, MOD = 20, POWER = 21, AND = 22, OR = 23, 
    PAREN_OPEN = 24, PAREN_CLOSE = 25, BRACKET_OPEN = 26, BRACKET_CLOSE = 27, 
    QUESTION = 28, COLON = 29, TILDA = 30, QUOTE = 31, DOUBLE_QUOTE = 32, 
    EXCLAMATION = 33, COMA = 34, SEMICOLON = 35, QUOTE_OPEN = 36, QUOTE_CLOSE = 37, 
    NUMBER = 38, ID = 39, STRING = 40, NL = 41, WS = 42
  };

  explicit TsilLexer(antlr4::CharStream *input);

  ~TsilLexer() override;


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

