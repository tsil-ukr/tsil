
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_SAVE = 3, KW_DELETE = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_RETURN = 8, KW_STRUCT = 9, KW_AS = 10, KW_SIZEOF = 11, 
    KW_SECTION = 12, KW_IMPORT = 13, KW_EXPORT = 14, KW_COMPOSITION = 15, 
    KW_PROPERTY = 16, KW_PUBLIC = 17, KW_PRIVATE = 18, KW_LOCAL = 19, KW_NOT = 20, 
    KW_OR = 21, KW_AND = 22, KW_INCLUDE = 23, EQUAL = 24, GREATER = 25, 
    LESSER = 26, DOT = 27, PLUS = 28, MINUS = 29, MULTIPLY = 30, DIVIDE = 31, 
    MOD = 32, POWER = 33, AND = 34, OR = 35, PAREN_OPEN = 36, PAREN_CLOSE = 37, 
    BRACKET_OPEN = 38, BRACKET_CLOSE = 39, QUESTION = 40, COLON = 41, TILDA = 42, 
    QUOTE = 43, DOUBLE_QUOTE = 44, EXCLAMATION = 45, COMA = 46, SEMICOLON = 47, 
    QUOTE_OPEN = 48, QUOTE_CLOSE = 49, INTEGER = 50, FLOAT = 51, HEX = 52, 
    BIN = 53, ID = 54, STRING = 55, COMMENT = 56, LINE_COMMENT = 57, NL = 58, 
    WS = 59
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

