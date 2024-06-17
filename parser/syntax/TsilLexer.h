
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_STRUCT = 7, KW_VARIATION = 8, KW_AS = 9, KW_SECTION = 10, KW_IMPORT = 11, 
    KW_EXPORT = 12, KW_COMPOSITION = 13, KW_PROPERTY = 14, KW_PUBLIC = 15, 
    KW_PRIVATE = 16, KW_LOCAL = 17, KW_NOT = 18, KW_OR = 19, KW_AND = 20, 
    KW_VAR = 21, KW_SYNONYM = 22, EQUAL = 23, GREATER = 24, LESSER = 25, 
    DOT = 26, PLUS = 27, MINUS = 28, MULTIPLY = 29, DIVIDE = 30, MOD = 31, 
    POWER = 32, AND = 33, OR = 34, PAREN_OPEN = 35, PAREN_CLOSE = 36, BRACKET_OPEN = 37, 
    BRACKET_CLOSE = 38, QUESTION = 39, COLON = 40, TILDA = 41, QUOTE = 42, 
    DOUBLE_QUOTE = 43, EXCLAMATION = 44, COMA = 45, SEMICOLON = 46, QUOTE_OPEN = 47, 
    QUOTE_CLOSE = 48, NUMBER = 49, INTEGER = 50, FLOAT = 51, HEX = 52, BIN = 53, 
    ID = 54, STRING = 55, COMMENT = 56, LINE_COMMENT = 57, WS = 58, NL = 59
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

