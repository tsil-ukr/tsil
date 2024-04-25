
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_STRUCT = 7, KW_AS = 8, KW_SECTION = 9, KW_IMPORT = 10, KW_EXPORT = 11, 
    KW_COMPOSITION = 12, KW_PROPERTY = 13, KW_PUBLIC = 14, KW_PRIVATE = 15, 
    KW_LOCAL = 16, KW_NOT = 17, KW_OR = 18, KW_AND = 19, EQUAL = 20, GREATER = 21, 
    LESSER = 22, DOT = 23, PLUS = 24, MINUS = 25, MULTIPLY = 26, DIVIDE = 27, 
    MOD = 28, POWER = 29, AND = 30, OR = 31, PAREN_OPEN = 32, PAREN_CLOSE = 33, 
    BRACKET_OPEN = 34, BRACKET_CLOSE = 35, QUESTION = 36, COLON = 37, TILDA = 38, 
    QUOTE = 39, DOUBLE_QUOTE = 40, EXCLAMATION = 41, COMA = 42, SEMICOLON = 43, 
    QUOTE_OPEN = 44, QUOTE_CLOSE = 45, NUMBER = 46, INTEGER = 47, FLOAT = 48, 
    HEX = 49, BIN = 50, ID = 51, STRING = 52, COMMENT = 53, LINE_COMMENT = 54, 
    WS = 55, NL = 56
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

