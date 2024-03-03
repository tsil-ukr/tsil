
// Generated from TsilLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilLexer : public antlr4::Lexer {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_SAVE = 3, KW_DELETE = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_RETURN = 8, KW_STRUCT = 9, KW_SPLAV = 10, EQUAL = 11, 
    GREATER = 12, LESSER = 13, DOT = 14, PLUS = 15, MINUS = 16, MULTIPLY = 17, 
    DIVIDE = 18, MOD = 19, POWER = 20, AND = 21, OR = 22, PAREN_OPEN = 23, 
    PAREN_CLOSE = 24, BRACKET_OPEN = 25, BRACKET_CLOSE = 26, QUESTION = 27, 
    COLON = 28, TILDA = 29, QUOTE = 30, DOUBLE_QUOTE = 31, EXCLAMATION = 32, 
    COMA = 33, SEMICOLON = 34, QUOTE_OPEN = 35, QUOTE_CLOSE = 36, NUMBER = 37, 
    ID = 38, STRING = 39, NL = 40, WS = 41
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

