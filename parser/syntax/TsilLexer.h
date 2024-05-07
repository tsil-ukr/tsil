
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_STRUCT = 7, KW_AS = 8, KW_SECTION = 9, KW_IMPORT = 10, KW_EXPORT = 11, 
    KW_COMPOSITION = 12, KW_PROPERTY = 13, KW_PUBLIC = 14, KW_PRIVATE = 15, 
    KW_LOCAL = 16, KW_NOT = 17, KW_OR = 18, KW_AND = 19, KW_VAR = 20, KW_SYNONYM = 21, 
    EQUAL = 22, GREATER = 23, LESSER = 24, DOT = 25, PLUS = 26, MINUS = 27, 
    MULTIPLY = 28, DIVIDE = 29, MOD = 30, POWER = 31, AND = 32, OR = 33, 
    PAREN_OPEN = 34, PAREN_CLOSE = 35, BRACKET_OPEN = 36, BRACKET_CLOSE = 37, 
    QUESTION = 38, COLON = 39, TILDA = 40, QUOTE = 41, DOUBLE_QUOTE = 42, 
    EXCLAMATION = 43, COMA = 44, SEMICOLON = 45, QUOTE_OPEN = 46, QUOTE_CLOSE = 47, 
    NUMBER = 48, INTEGER = 49, FLOAT = 50, HEX = 51, BIN = 52, ID = 53, 
    STRING = 54, COMMENT = 55, LINE_COMMENT = 56, WS = 57, NL = 58
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

