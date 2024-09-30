
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
    KW_AND = 21, KW_VAR = 22, KW_IMMUT = 23, KW_SYNONYM = 24, KW_EXEC = 25, 
    EQUAL = 26, GREATER = 27, LESSER = 28, DOT = 29, PLUS = 30, MINUS = 31, 
    MULTIPLY = 32, DIVIDE = 33, MOD = 34, POWER = 35, AND = 36, OR = 37, 
    PAREN_OPEN = 38, PAREN_CLOSE = 39, BRACKET_OPEN = 40, BRACKET_CLOSE = 41, 
    QUESTION = 42, COLON = 43, TILDA = 44, QUOTE = 45, DOUBLE_QUOTE = 46, 
    EXCLAMATION = 47, COMA = 48, SEMICOLON = 49, QUOTE_OPEN = 50, QUOTE_CLOSE = 51, 
    NUMBER = 52, INTEGER = 53, FLOAT = 54, HEX = 55, BIN = 56, ID = 57, 
    STRING = 58, COMMENT = 59, LINE_COMMENT = 60, WS = 61, NL = 62
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

