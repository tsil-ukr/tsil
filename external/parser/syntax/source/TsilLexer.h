
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_DEFER = 7, KW_STRUCT = 8, KW_VARIATION = 9, KW_AS = 10, KW_SECTION = 11, 
    KW_IMPORT = 12, KW_EXPORT = 13, KW_COMPOSITION = 14, KW_PROPERTY = 15, 
    KW_PUBLIC = 16, KW_PRIVATE = 17, KW_LOCAL = 18, KW_NOT = 19, KW_OR = 20, 
    KW_AND = 21, KW_VAR = 22, KW_IMMUT = 23, KW_SYNONYM = 24, EQUAL = 25, 
    GREATER = 26, LESSER = 27, DOT = 28, PLUS = 29, MINUS = 30, MULTIPLY = 31, 
    DIVIDE = 32, MOD = 33, POWER = 34, AND = 35, OR = 36, PAREN_OPEN = 37, 
    PAREN_CLOSE = 38, BRACKET_OPEN = 39, BRACKET_CLOSE = 40, QUESTION = 41, 
    COLON = 42, TILDA = 43, QUOTE = 44, DOUBLE_QUOTE = 45, EXCLAMATION = 46, 
    COMA = 47, SEMICOLON = 48, QUOTE_OPEN = 49, QUOTE_CLOSE = 50, NUMBER = 51, 
    INTEGER = 52, FLOAT = 53, HEX = 54, BIN = 55, ID = 56, STRING = 57, 
    COMMENT = 58, LINE_COMMENT = 59, WS = 60, NL = 61
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

