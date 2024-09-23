
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilParser : public antlr4::Parser {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_DEFER = 7, KW_STRUCT = 8, KW_VARIATION = 9, KW_AS = 10, KW_SECTION = 11, 
    KW_IMPORT = 12, KW_EXPORT = 13, KW_COMPOSITION = 14, KW_PROPERTY = 15, 
    KW_PUBLIC = 16, KW_PRIVATE = 17, KW_LOCAL = 18, KW_NOT = 19, KW_OR = 20, 
    KW_AND = 21, KW_VAR = 22, KW_IMMUT = 23, KW_SYNONYM = 24, EQUAL = 25, 
    GREATER = 26, LESSER = 27, DOT = 28, PLUS = 29, MINUS = 30, MULTIPLY = 31, 
    DIVIDE = 32, MOD = 33, POWER = 34, AND = 35, OR = 36, PAREN_OPEN = 37, 
    PAREN_CLOSE = 38, BRACKET_OPEN = 39, BRACKET_CLOSE = 40, QUESTION = 41, 
    COLON = 42, TILDA = 43, QUOTE = 44, DOUBLE_QUOTE = 45, EXCLAMATION = 46, 
    COMA = 47, SEMICOLON = 48, QUOTE_OPEN = 49, QUOTE_CLOSE = 50, NUMBER = 51, 
    INTEGER = 52, FLOAT = 53, HEX = 54, BIN = 55, ID = 56, STRING = 57, 
    COMMENT = 58, LINE_COMMENT = 59, WS = 60, NL = 61
  };

  enum {
    RuleFile = 0, RuleProgram = 1, RuleAtom = 2, RuleOperation = 3, RuleExpr = 4, 
    RuleStructure_declare = 5, RuleStructure_define = 6, RuleStructure_element = 7, 
    RuleDiia_declare = 8, RuleDiia_define = 9, RuleTsil_declare = 10, RuleTsil_define = 11, 
    RuleSynonym = 12, RuleSection_declare = 13, RuleSection_define = 14, 
    RuleSet = 15, RuleSection_set = 16, RulePosition_set = 17, RuleIf = 18, 
    RuleWhile = 19, RuleBody = 20, RuleBody_element = 21, RuleType = 22, 
    RuleParam = 23
  };

  explicit TsilParser(antlr4::TokenStream *input);

  TsilParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~TsilParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class ProgramContext;
  class AtomContext;
  class OperationContext;
  class ExprContext;
  class Structure_declareContext;
  class Structure_defineContext;
  class Structure_elementContext;
  class Diia_declareContext;
  class Diia_defineContext;
  class Tsil_declareContext;
  class Tsil_defineContext;
  class SynonymContext;
  class Section_declareContext;
  class Section_defineContext;
  class SetContext;
  class Section_setContext;
  class Position_setContext;
  class IfContext;
  class WhileContext;
  class BodyContext;
  class Body_elementContext;
  class TypeContext;
  class ParamContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::ProgramContext *f_program = nullptr;
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Body_elementContext *> body_element();
    Body_elementContext* body_element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_nestedContext : public AtomContext {
  public:
    Atom_nestedContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_template_getContext : public AtomContext {
  public:
    Atom_template_getContext(AtomContext *ctx);

    AtomContext *atom();
    antlr4::tree::TerminalNode *LESSER();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *GREATER();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_getContext : public AtomContext {
  public:
    Atom_getContext(AtomContext *ctx);

    AtomContext *atom();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_section_getContext : public AtomContext {
  public:
    Atom_section_getContext(AtomContext *ctx);

    AtomContext *atom();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_subjectContext : public AtomContext {
  public:
    Atom_subjectContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_position_getContext : public AtomContext {
  public:
    Atom_position_getContext(AtomContext *ctx);

    AtomContext *atom();
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_callContext : public AtomContext {
  public:
    Atom_callContext(AtomContext *ctx);

    AtomContext *atom();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();
  AtomContext* atom(int precedence);
  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OperationContext() = default;
    void copyFrom(OperationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Operation_gteContext : public OperationContext {
  public:
    Operation_gteContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_neqContext : public OperationContext {
  public:
    Operation_neqContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *EXCLAMATION();
    antlr4::tree::TerminalNode *EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_xorContext : public OperationContext {
  public:
    Operation_xorContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *POWER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lteContext : public OperationContext {
  public:
    Operation_lteContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_atomContext : public OperationContext {
  public:
    Operation_atomContext(OperationContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_subContext : public OperationContext {
  public:
    Operation_subContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_addContext : public OperationContext {
  public:
    Operation_addContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_ltContext : public OperationContext {
  public:
    Operation_ltContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_modContext : public OperationContext {
  public:
    Operation_modContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MOD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_mulContext : public OperationContext {
  public:
    Operation_mulContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_gtContext : public OperationContext {
  public:
    Operation_gtContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *GREATER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_eqContext : public OperationContext {
  public:
    Operation_eqContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_stringContext : public OperationContext {
  public:
    Operation_stringContext(OperationContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_landContext : public OperationContext {
  public:
    Operation_landContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_orContext : public OperationContext {
  public:
    Operation_orContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *OR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lorContext : public OperationContext {
  public:
    Operation_lorContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_ternaryContext : public OperationContext {
  public:
    Operation_ternaryContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *QUESTION();
    antlr4::tree::TerminalNode *COLON();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_urshiftContext : public OperationContext {
  public:
    Operation_urshiftContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_divContext : public OperationContext {
  public:
    Operation_divContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *DIVIDE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_rshiftContext : public OperationContext {
  public:
    Operation_rshiftContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lshiftContext : public OperationContext {
  public:
    Operation_lshiftContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESSER();
    antlr4::tree::TerminalNode* LESSER(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_numberContext : public OperationContext {
  public:
    Operation_numberContext(OperationContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_andContext : public OperationContext {
  public:
    Operation_andContext(OperationContext *ctx);

    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *AND();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OperationContext* operation();
  OperationContext* operation(int precedence);
  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr_operationContext : public ExprContext {
  public:
    Expr_operationContext(ExprContext *ctx);

    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  Structure_declareContext : public antlr4::ParserRuleContext {
  public:
    Structure_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCT();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_declareContext* structure_declare();

  class  Structure_defineContext : public antlr4::ParserRuleContext {
  public:
    Structure_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCT();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<Structure_elementContext *> structure_element();
    Structure_elementContext* structure_element(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_defineContext* structure_define();

  class  Structure_elementContext : public antlr4::ParserRuleContext {
  public:
    Structure_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_elementContext* structure_element();

  class  Diia_declareContext : public antlr4::ParserRuleContext {
  public:
    Diia_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_declareContext* diia_declare();

  class  Diia_defineContext : public antlr4::ParserRuleContext {
  public:
    Diia_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    BodyContext *body();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_defineContext* diia_define();

  class  Tsil_declareContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *td_var = nullptr;
    antlr4::Token *td_immut = nullptr;
    antlr4::Token *td_const = nullptr;
    Tsil_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *KW_VAR();
    antlr4::tree::TerminalNode *KW_IMMUT();
    antlr4::tree::TerminalNode *KW_TSIL();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tsil_declareContext* tsil_declare();

  class  Tsil_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *td_var = nullptr;
    antlr4::Token *td_immut = nullptr;
    antlr4::Token *td_const = nullptr;
    Tsil_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *KW_VAR();
    antlr4::tree::TerminalNode *KW_IMMUT();
    antlr4::tree::TerminalNode *KW_TSIL();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tsil_defineContext* tsil_define();

  class  SynonymContext : public antlr4::ParserRuleContext {
  public:
    SynonymContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SYNONYM();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SynonymContext* synonym();

  class  Section_declareContext : public antlr4::ParserRuleContext {
  public:
    Section_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SECTION();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Section_declareContext* section_declare();

  class  Section_defineContext : public antlr4::ParserRuleContext {
  public:
    Section_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SECTION();
    antlr4::tree::TerminalNode *ID();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Section_defineContext* section_define();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  Section_setContext : public antlr4::ParserRuleContext {
  public:
    Section_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Section_setContext* section_set();

  class  Position_setContext : public antlr4::ParserRuleContext {
  public:
    Position_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Position_setContext* position_set();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IF();
    OperationContext *operation();
    std::vector<BodyContext *> body();
    BodyContext* body(size_t i);
    antlr4::tree::TerminalNode *KW_ELSE();
    IfContext *if_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfContext* if_();

  class  WhileContext : public antlr4::ParserRuleContext {
  public:
    WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_WHILE();
    OperationContext *operation();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileContext* while_();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    std::vector<Body_elementContext *> body_element();
    Body_elementContext* body_element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BodyContext* body();

  class  Body_elementContext : public antlr4::ParserRuleContext {
  public:
    Body_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Structure_declareContext *structure_declare();
    Structure_defineContext *structure_define();
    Diia_declareContext *diia_declare();
    Diia_defineContext *diia_define();
    Tsil_declareContext *tsil_declare();
    Tsil_defineContext *tsil_define();
    SetContext *set();
    Section_setContext *section_set();
    Position_setContext *position_set();
    SynonymContext *synonym();
    Section_declareContext *section_declare();
    Section_defineContext *section_define();
    ExprContext *expr();
    IfContext *if_();
    WhileContext *while_();
    BodyContext *body();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Body_elementContext* body_element();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Type_getContext : public TypeContext {
  public:
    Type_getContext(TypeContext *ctx);

    TypeContext *type();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_nestedContext : public TypeContext {
  public:
    Type_nestedContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    TypeContext *type();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_subjectContext : public TypeContext {
  public:
    Type_subjectContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_arrayContext : public TypeContext {
  public:
    Type_arrayContext(TypeContext *ctx);

    TypeContext *type();
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_fn_complexContext : public TypeContext {
  public:
    Type_fn_complexContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_template_getContext : public TypeContext {
  public:
    Type_template_getContext(TypeContext *ctx);

    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_fn_complex_namedContext : public TypeContext {
  public:
    Type_fn_complex_namedContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *PAREN_OPEN();
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_fn_simpleContext : public TypeContext {
  public:
    Type_fn_simpleContext(TypeContext *ctx);

    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_section_getContext : public TypeContext {
  public:
    Type_section_getContext(TypeContext *ctx);

    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool atomSempred(AtomContext *_localctx, size_t predicateIndex);
  bool operationSempred(OperationContext *_localctx, size_t predicateIndex);
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

