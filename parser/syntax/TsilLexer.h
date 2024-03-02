
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_SAVE = 3, KW_DELETE = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_RETURN = 8, KW_STRUCT = 9, EQUAL = 10, GREATER = 11, 
    LESSER = 12, DOT = 13, PLUS = 14, MINUS = 15, MULTIPLY = 16, DIVIDE = 17, 
    MOD = 18, POWER = 19, AND = 20, OR = 21, PAREN_OPEN = 22, PAREN_CLOSE = 23, 
    BRACKET_OPEN = 24, BRACKET_CLOSE = 25, QUESTION = 26, COLON = 27, TILDA = 28, 
    QUOTE = 29, DOUBLE_QUOTE = 30, EXCLAMATION = 31, COMA = 32, SEMICOLON = 33, 
    QUOTE_OPEN = 34, QUOTE_CLOSE = 35, INTEGER = 36, NUMBER = 37, ID = 38, 
    STRING = 39, NL = 40, WS = 41
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

