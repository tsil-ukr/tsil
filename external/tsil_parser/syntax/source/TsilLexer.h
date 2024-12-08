
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
    KW_TRY = 26, KW_CATCH = 27, KW_THROW = 28, KW_GOTO = 29, KW_ENUM = 30, 
    KW_ENUMERATE = 31, KW_IS = 32, EQUAL = 33, GREATER = 34, LESSER = 35, 
    DOT = 36, PLUS = 37, MINUS = 38, MULTIPLY = 39, DIVIDE = 40, MOD = 41, 
    POWER = 42, AND = 43, OR = 44, PAREN_OPEN = 45, PAREN_CLOSE = 46, BRACKET_OPEN = 47, 
    BRACKET_CLOSE = 48, QUESTION = 49, COLON = 50, TILDA = 51, QUOTE = 52, 
    DOUBLE_QUOTE = 53, EXCLAMATION = 54, COMA = 55, SEMICOLON = 56, QUOTE_OPEN = 57, 
    QUOTE_CLOSE = 58, NUMBER = 59, TYPED_INTEGER = 60, INTEGER = 61, TYPED_FLOAT = 62, 
    FLOAT = 63, HEX = 64, BIN = 65, ID = 66, STRING = 67, COMMENT = 68, 
    LINE_COMMENT = 69, WS = 70, NL = 71
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

