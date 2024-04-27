
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_STRUCT = 7, KW_AS = 8, KW_SECTION = 9, KW_IMPORT = 10, KW_EXPORT = 11, 
    KW_COMPOSITION = 12, KW_PROPERTY = 13, KW_PUBLIC = 14, KW_PRIVATE = 15, 
    KW_LOCAL = 16, KW_NOT = 17, KW_OR = 18, KW_AND = 19, KW_VAR = 20, EQUAL = 21, 
    GREATER = 22, LESSER = 23, DOT = 24, PLUS = 25, MINUS = 26, MULTIPLY = 27, 
    DIVIDE = 28, MOD = 29, POWER = 30, AND = 31, OR = 32, PAREN_OPEN = 33, 
    PAREN_CLOSE = 34, BRACKET_OPEN = 35, BRACKET_CLOSE = 36, QUESTION = 37, 
    COLON = 38, TILDA = 39, QUOTE = 40, DOUBLE_QUOTE = 41, EXCLAMATION = 42, 
    COMA = 43, SEMICOLON = 44, QUOTE_OPEN = 45, QUOTE_CLOSE = 46, NUMBER = 47, 
    INTEGER = 48, FLOAT = 49, HEX = 50, BIN = 51, ID = 52, STRING = 53, 
    COMMENT = 54, LINE_COMMENT = 55, WS = 56, NL = 57
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

