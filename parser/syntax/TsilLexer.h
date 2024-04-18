
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_SAVE = 3, KW_DELETE = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_RETURN = 8, KW_STRUCT = 9, KW_EXTERN = 10, KW_AS = 11, 
    KW_SIZEOF = 12, EQUAL = 13, GREATER = 14, LESSER = 15, DOT = 16, PLUS = 17, 
    MINUS = 18, MULTIPLY = 19, DIVIDE = 20, MOD = 21, POWER = 22, AND = 23, 
    OR = 24, PAREN_OPEN = 25, PAREN_CLOSE = 26, BRACKET_OPEN = 27, BRACKET_CLOSE = 28, 
    QUESTION = 29, COLON = 30, TILDA = 31, QUOTE = 32, DOUBLE_QUOTE = 33, 
    EXCLAMATION = 34, COMA = 35, SEMICOLON = 36, QUOTE_OPEN = 37, QUOTE_CLOSE = 38, 
    INTEGER = 39, FLOAT = 40, HEX = 41, BIN = 42, ID = 43, STRING = 44, 
    NL = 45, WS = 46
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

