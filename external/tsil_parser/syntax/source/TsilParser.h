
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
    KW_AND = 21, KW_VAR = 22, KW_IMMUT = 23, KW_SYNONYM = 24, KW_EXEC = 25, 
    KW_TRY = 26, KW_CATCH = 27, KW_THROW = 28, EQUAL = 29, GREATER = 30, 
    LESSER = 31, DOT = 32, PLUS = 33, MINUS = 34, MULTIPLY = 35, DIVIDE = 36, 
    MOD = 37, POWER = 38, AND = 39, OR = 40, PAREN_OPEN = 41, PAREN_CLOSE = 42, 
    BRACKET_OPEN = 43, BRACKET_CLOSE = 44, QUESTION = 45, COLON = 46, TILDA = 47, 
    QUOTE = 48, DOUBLE_QUOTE = 49, EXCLAMATION = 50, COMA = 51, SEMICOLON = 52, 
    QUOTE_OPEN = 53, QUOTE_CLOSE = 54, NUMBER = 55, TYPED_INTEGER = 56, 
    INTEGER = 57, TYPED_FLOAT = 58, FLOAT = 59, HEX = 60, BIN = 61, ID = 62, 
    STRING = 63, COMMENT = 64, LINE_COMMENT = 65, WS = 66, NL = 67
  };

  enum {
    RuleFile = 0, RuleProgram = 1, RuleAtom = 2, RuleCall_arg = 3, RuleOperation = 4, 
    RuleOp_lshift = 5, RuleOp_rshift = 6, RuleOp_urshift = 7, RuleOp_lte = 8, 
    RuleOp_gte = 9, RuleOp_eq = 10, RuleOp_neq = 11, RuleOp_land = 12, RuleOp_lor = 13, 
    RuleGendef = 14, RuleExpr = 15, RuleObject_arg = 16, RuleTypeless_object = 17, 
    RuleStructure_define = 18, RuleStructure_element = 19, RuleDiia_define = 20, 
    RuleTsil_define = 21, RuleAssign = 22, RuleSynonym = 23, RuleSynonym_fn = 24, 
    RuleSection_define = 25, RuleSet = 26, RulePosition_set = 27, RuleSection_set = 28, 
    RuleIf = 29, RuleWhile = 30, RuleExec = 31, RuleBody = 32, RuleBody_element = 33, 
    RuleReturn = 34, RuleSimple_type = 35, RuleType = 36, RuleParam = 37
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
  class Call_argContext;
  class OperationContext;
  class Op_lshiftContext;
  class Op_rshiftContext;
  class Op_urshiftContext;
  class Op_lteContext;
  class Op_gteContext;
  class Op_eqContext;
  class Op_neqContext;
  class Op_landContext;
  class Op_lorContext;
  class GendefContext;
  class ExprContext;
  class Object_argContext;
  class Typeless_objectContext;
  class Structure_defineContext;
  class Structure_elementContext;
  class Diia_defineContext;
  class Tsil_defineContext;
  class AssignContext;
  class SynonymContext;
  class Synonym_fnContext;
  class Section_defineContext;
  class SetContext;
  class Position_setContext;
  class Section_setContext;
  class IfContext;
  class WhileContext;
  class ExecContext;
  class BodyContext;
  class Body_elementContext;
  class ReturnContext;
  class Simple_typeContext;
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

    TsilParser::AtomContext *object = nullptr;
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    AtomContext *atom();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_getContext : public AtomContext {
  public:
    Atom_getContext(AtomContext *ctx);

    TsilParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *DOT();
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_section_getContext : public AtomContext {
  public:
    Atom_section_getContext(AtomContext *ctx);

    TsilParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_subjectContext : public AtomContext {
  public:
    Atom_subjectContext(AtomContext *ctx);

    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_position_getContext : public AtomContext {
  public:
    Atom_position_getContext(AtomContext *ctx);

    TsilParser::AtomContext *object = nullptr;
    TsilParser::ExprContext *position = nullptr;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    AtomContext *atom();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_callContext : public AtomContext {
  public:
    Atom_callContext(AtomContext *ctx);

    TsilParser::AtomContext *object = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    AtomContext *atom();
    std::vector<Call_argContext *> call_arg();
    Call_argContext* call_arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();
  AtomContext* atom(int precedence);
  class  Call_argContext : public antlr4::ParserRuleContext {
  public:
    Call_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_argContext* call_arg();

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

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_gteContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_gteContext *op_gte();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_neqContext : public OperationContext {
  public:
    Operation_neqContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_neqContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_neqContext *op_neq();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_xorContext : public OperationContext {
  public:
    Operation_xorContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
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

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_lteContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_lteContext *op_lte();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_plusContext : public OperationContext {
  public:
    Operation_pre_plusContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    antlr4::tree::TerminalNode *PLUS();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_addContext : public OperationContext {
  public:
    Operation_addContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
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

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *LESSER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_minusContext : public OperationContext {
  public:
    Operation_pre_minusContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    antlr4::tree::TerminalNode *MINUS();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_landContext : public OperationContext {
  public:
    Operation_landContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_landContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_landContext *op_land();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_orContext : public OperationContext {
  public:
    Operation_orContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *OR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_notContext : public OperationContext {
  public:
    Operation_pre_notContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    antlr4::tree::TerminalNode *EXCLAMATION();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_asContext : public OperationContext {
  public:
    Operation_asContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::TypeContext *right_type = nullptr;
    antlr4::Token *right_tsil = nullptr;
    OperationContext *operation();
    antlr4::tree::TerminalNode *KW_AS();
    TypeContext *type();
    antlr4::tree::TerminalNode *KW_TSIL();
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

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_modContext : public OperationContext {
  public:
    Operation_modContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
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

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
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

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
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

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_eqContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_eqContext *op_eq();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_stringContext : public OperationContext {
  public:
    Operation_stringContext(OperationContext *ctx);

    antlr4::Token *tt = nullptr;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_pre_bw_notContext : public OperationContext {
  public:
    Operation_pre_bw_notContext(OperationContext *ctx);

    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    antlr4::tree::TerminalNode *TILDA();
    OperationContext *operation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lorContext : public OperationContext {
  public:
    Operation_lorContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_lorContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_lorContext *op_lor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_ternaryContext : public OperationContext {
  public:
    Operation_ternaryContext(OperationContext *ctx);

    TsilParser::OperationContext *cond = nullptr;
    TsilParser::OperationContext *ifok = nullptr;
    TsilParser::OperationContext *ifnot = nullptr;
    antlr4::tree::TerminalNode *QUESTION();
    antlr4::tree::TerminalNode *COLON();
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_urshiftContext : public OperationContext {
  public:
    Operation_urshiftContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_urshiftContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_urshiftContext *op_urshift();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_divContext : public OperationContext {
  public:
    Operation_divContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
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

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_rshiftContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_rshiftContext *op_rshift();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_lshiftContext : public OperationContext {
  public:
    Operation_lshiftContext(OperationContext *ctx);

    TsilParser::OperationContext *left = nullptr;
    TsilParser::Op_lshiftContext *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Op_lshiftContext *op_lshift();
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

    TsilParser::OperationContext *left = nullptr;
    antlr4::Token *op = nullptr;
    TsilParser::OperationContext *right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *AND();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OperationContext* operation();
  OperationContext* operation(int precedence);
  class  Op_lshiftContext : public antlr4::ParserRuleContext {
  public:
    Op_lshiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LESSER();
    antlr4::tree::TerminalNode* LESSER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_lshiftContext* op_lshift();

  class  Op_rshiftContext : public antlr4::ParserRuleContext {
  public:
    Op_rshiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_rshiftContext* op_rshift();

  class  Op_urshiftContext : public antlr4::ParserRuleContext {
  public:
    Op_urshiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_urshiftContext* op_urshift();

  class  Op_lteContext : public antlr4::ParserRuleContext {
  public:
    Op_lteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_lteContext* op_lte();

  class  Op_gteContext : public antlr4::ParserRuleContext {
  public:
    Op_gteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_gteContext* op_gte();

  class  Op_eqContext : public antlr4::ParserRuleContext {
  public:
    Op_eqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_eqContext* op_eq();

  class  Op_neqContext : public antlr4::ParserRuleContext {
  public:
    Op_neqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCLAMATION();
    antlr4::tree::TerminalNode *EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_neqContext* op_neq();

  class  Op_landContext : public antlr4::ParserRuleContext {
  public:
    Op_landContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_landContext* op_land();

  class  Op_lorContext : public antlr4::ParserRuleContext {
  public:
    Op_lorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_lorContext* op_lor();

  class  GendefContext : public antlr4::ParserRuleContext {
  public:
    GendefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GendefContext* gendef();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr_objectContext : public ExprContext {
  public:
    Expr_objectContext(ExprContext *ctx);

    Simple_typeContext *simple_type();
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    std::vector<Object_argContext *> object_arg();
    Object_argContext* object_arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
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

  class  Object_argContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    Object_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    Typeless_objectContext *typeless_object();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_argContext* object_arg();

  class  Typeless_objectContext : public antlr4::ParserRuleContext {
  public:
    Typeless_objectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    std::vector<Object_argContext *> object_arg();
    Object_argContext* object_arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Typeless_objectContext* typeless_object();

  class  Structure_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    TsilParser::GendefContext *first_gendef = nullptr;
    Structure_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCT();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<GendefContext *> gendef();
    GendefContext* gendef(size_t i);
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    std::vector<Structure_elementContext *> structure_element();
    Structure_elementContext* structure_element(size_t i);

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

  class  Diia_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *extern_ = nullptr;
    antlr4::Token *local = nullptr;
    antlr4::Token *intern = nullptr;
    antlr4::Token *id = nullptr;
    TsilParser::GendefContext *first_gendef = nullptr;
    TsilParser::TypeContext *restyp = nullptr;
    Diia_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    BodyContext *body();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();
    std::vector<GendefContext *> gendef();
    GendefContext* gendef(size_t i);
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_defineContext* diia_define();

  class  Tsil_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *td_var = nullptr;
    antlr4::Token *td_immut = nullptr;
    antlr4::Token *td_const = nullptr;
    antlr4::Token *id = nullptr;
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    Tsil_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *KW_TSIL();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *KW_VAR();
    antlr4::tree::TerminalNode *KW_IMMUT();
    ExprContext *expr();
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tsil_defineContext* tsil_define();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  SynonymContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    TsilParser::GendefContext *first_gendef = nullptr;
    SynonymContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SYNONYM();
    antlr4::tree::TerminalNode *EQUAL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<GendefContext *> gendef();
    GendefContext* gendef(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SynonymContext* synonym();

  class  Synonym_fnContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
    TsilParser::GendefContext *first_gendef = nullptr;
    Synonym_fnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SYNONYM();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LESSER();
    std::vector<GendefContext *> gendef();
    GendefContext* gendef(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Synonym_fnContext* synonym_fn();

  class  Section_defineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
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
    TsilParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SEMICOLON();
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  Position_setContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::AtomContext *object = nullptr;
    TsilParser::ExprContext *idx = nullptr;
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    Position_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SEMICOLON();
    AtomContext *atom();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Position_setContext* position_set();

  class  Section_setContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::AtomContext *object = nullptr;
    antlr4::Token *id = nullptr;
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    Section_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SEMICOLON();
    AtomContext *atom();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Section_setContext* section_set();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::OperationContext *cond = nullptr;
    TsilParser::BodyContext *ifok = nullptr;
    TsilParser::BodyContext *ifnot = nullptr;
    TsilParser::IfContext *ifnotif = nullptr;
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
    TsilParser::OperationContext *cond = nullptr;
    WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_WHILE();
    BodyContext *body();
    OperationContext *operation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileContext* while_();

  class  ExecContext : public antlr4::ParserRuleContext {
  public:
    ExecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_EXEC();
    BodyContext *body();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecContext* exec();

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
    antlr4::Token *semi = nullptr;
    Body_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Structure_defineContext *structure_define();
    Diia_defineContext *diia_define();
    Tsil_defineContext *tsil_define();
    AssignContext *assign();
    SetContext *set();
    Section_setContext *section_set();
    Position_setContext *position_set();
    SynonymContext *synonym();
    Synonym_fnContext *synonym_fn();
    Section_defineContext *section_define();
    IfContext *if_();
    WhileContext *while_();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    BodyContext *body();
    ExecContext *exec();
    ReturnContext *return_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Body_elementContext* body_element();

  class  ReturnContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::ExprContext *value_expr = nullptr;
    TsilParser::Typeless_objectContext *value_object = nullptr;
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExprContext *expr();
    Typeless_objectContext *typeless_object();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnContext* return_();

  class  Simple_typeContext : public antlr4::ParserRuleContext {
  public:
    Simple_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Simple_typeContext() = default;
    void copyFrom(Simple_typeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Simple_type_section_getContext : public Simple_typeContext {
  public:
    Simple_type_section_getContext(Simple_typeContext *ctx);

    TsilParser::Simple_typeContext *object = nullptr;
    antlr4::Token *id = nullptr;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    Simple_typeContext *simple_type();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_type_subjectContext : public Simple_typeContext {
  public:
    Simple_type_subjectContext(Simple_typeContext *ctx);

    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_type_template_getContext : public Simple_typeContext {
  public:
    Simple_type_template_getContext(Simple_typeContext *ctx);

    TsilParser::Simple_typeContext *object = nullptr;
    antlr4::tree::TerminalNode *LESSER();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *GREATER();
    Simple_typeContext *simple_type();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_type_arrayContext : public Simple_typeContext {
  public:
    Simple_type_arrayContext(Simple_typeContext *ctx);

    TsilParser::Simple_typeContext *left = nullptr;
    antlr4::Token *size = nullptr;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    Simple_typeContext *simple_type();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simple_type_getContext : public Simple_typeContext {
  public:
    Simple_type_getContext(Simple_typeContext *ctx);

    TsilParser::Simple_typeContext *object = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *DOT();
    Simple_typeContext *simple_type();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Simple_typeContext* simple_type();
  Simple_typeContext* simple_type(int precedence);
  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Type_simple_typeContext : public TypeContext {
  public:
    Type_simple_typeContext(TypeContext *ctx);

    Simple_typeContext *simple_type();
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

  class  Type_fn_complexContext : public TypeContext {
  public:
    Type_fn_complexContext(TypeContext *ctx);

    TsilParser::TypeContext *restyp = nullptr;
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

  class  Type_fn_complex_namedContext : public TypeContext {
  public:
    Type_fn_complex_namedContext(TypeContext *ctx);

    TsilParser::TypeContext *restyp = nullptr;
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

    TsilParser::TypeContext *param_type = nullptr;
    TsilParser::TypeContext *restyp = nullptr;
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_fnContext : public TypeContext {
  public:
    Type_fnContext(TypeContext *ctx);

    TsilParser::TypeContext *restyp = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *id = nullptr;
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
  bool simple_typeSempred(Simple_typeContext *_localctx, size_t predicateIndex);
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

