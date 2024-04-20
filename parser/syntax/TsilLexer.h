
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_SAVE = 3, KW_DELETE = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_RETURN = 8, KW_STRUCT = 9, KW_EXTERN = 10, KW_AS = 11, 
    KW_SIZEOF = 12, KW_SECTION = 13, KW_IMPORT = 14, KW_EXPORT = 15, KW_COMPOSITION = 16, 
    KW_PROPERTY = 17, KW_PUBLIC = 18, KW_PRIVATE = 19, KW_NOT = 20, KW_OR = 21, 
    KW_AND = 22, EQUAL = 23, GREATER = 24, LESSER = 25, DOT = 26, PLUS = 27, 
    MINUS = 28, MULTIPLY = 29, DIVIDE = 30, MOD = 31, POWER = 32, AND = 33, 
    OR = 34, PAREN_OPEN = 35, PAREN_CLOSE = 36, BRACKET_OPEN = 37, BRACKET_CLOSE = 38, 
    QUESTION = 39, COLON = 40, TILDA = 41, QUOTE = 42, DOUBLE_QUOTE = 43, 
    EXCLAMATION = 44, COMA = 45, SEMICOLON = 46, QUOTE_OPEN = 47, QUOTE_CLOSE = 48, 
    INTEGER = 49, FLOAT = 50, HEX = 51, BIN = 52, ID = 53, STRING = 54, 
    COMMENT = 55, LINE_COMMENT = 56, NL = 57, WS = 58
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

