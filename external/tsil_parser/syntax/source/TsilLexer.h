
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
    KW_TRY = 26, KW_CATCH = 27, KW_THROW = 28, EQUAL = 29, GREATER = 30, 
    LESSER = 31, DOT = 32, PLUS = 33, MINUS = 34, MULTIPLY = 35, DIVIDE = 36, 
    MOD = 37, POWER = 38, AND = 39, OR = 40, PAREN_OPEN = 41, PAREN_CLOSE = 42, 
    BRACKET_OPEN = 43, BRACKET_CLOSE = 44, QUESTION = 45, COLON = 46, TILDA = 47, 
    QUOTE = 48, DOUBLE_QUOTE = 49, EXCLAMATION = 50, COMA = 51, SEMICOLON = 52, 
    QUOTE_OPEN = 53, QUOTE_CLOSE = 54, NUMBER = 55, INTEGER = 56, FLOAT = 57, 
    HEX = 58, BIN = 59, ID = 60, STRING = 61, COMMENT = 62, LINE_COMMENT = 63, 
    WS = 64, NL = 65
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

