
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
    KW_AND = 21, KW_VAR = 22, KW_SYNONYM = 23, EQUAL = 24, GREATER = 25, 
    LESSER = 26, DOT = 27, PLUS = 28, MINUS = 29, MULTIPLY = 30, DIVIDE = 31, 
    MOD = 32, POWER = 33, AND = 34, OR = 35, PAREN_OPEN = 36, PAREN_CLOSE = 37, 
    BRACKET_OPEN = 38, BRACKET_CLOSE = 39, QUESTION = 40, COLON = 41, TILDA = 42, 
    QUOTE = 43, DOUBLE_QUOTE = 44, EXCLAMATION = 45, COMA = 46, SEMICOLON = 47, 
    QUOTE_OPEN = 48, QUOTE_CLOSE = 49, NUMBER = 50, INTEGER = 51, FLOAT = 52, 
    HEX = 53, BIN = 54, ID = 55, STRING = 56, COMMENT = 57, LINE_COMMENT = 58, 
    WS = 59, NL = 60
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

