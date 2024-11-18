
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
    KW_TRY = 26, KW_CATCH = 27, KW_THROW = 28, KW_GOTO = 29, EQUAL = 30, 
    GREATER = 31, LESSER = 32, DOT = 33, PLUS = 34, MINUS = 35, MULTIPLY = 36, 
    DIVIDE = 37, MOD = 38, POWER = 39, AND = 40, OR = 41, PAREN_OPEN = 42, 
    PAREN_CLOSE = 43, BRACKET_OPEN = 44, BRACKET_CLOSE = 45, QUESTION = 46, 
    COLON = 47, TILDA = 48, QUOTE = 49, DOUBLE_QUOTE = 50, EXCLAMATION = 51, 
    COMA = 52, SEMICOLON = 53, QUOTE_OPEN = 54, QUOTE_CLOSE = 55, NUMBER = 56, 
    TYPED_INTEGER = 57, INTEGER = 58, TYPED_FLOAT = 59, FLOAT = 60, HEX = 61, 
    BIN = 62, ID = 63, STRING = 64, COMMENT = 65, LINE_COMMENT = 66, WS = 67, 
    NL = 68
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

