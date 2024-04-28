
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilParser : public antlr4::Parser {
public:
  enum {
    KW_TSIL = 1, KW_DIIA = 2, KW_IF = 3, KW_ELSE = 4, KW_WHILE = 5, KW_RETURN = 6, 
    KW_STRUCT = 7, KW_AS = 8, KW_SECTION = 9, KW_IMPORT = 10, KW_EXPORT = 11, 
    KW_COMPOSITION = 12, KW_PROPERTY = 13, KW_PUBLIC = 14, KW_PRIVATE = 15, 
    KW_LOCAL = 16, KW_NOT = 17, KW_OR = 18, KW_AND = 19, KW_VAR = 20, EQUAL = 21, 
    GREATER = 22, LESSER = 23, DOT = 24, PLUS = 25, MINUS = 26, MULTIPLY = 27, 
    DIVIDE = 28, MOD = 29, POWER = 30, AND = 31, OR = 32, PAREN_OPEN = 33, 
    PAREN_CLOSE = 34, BRACKET_OPEN = 35, BRACKET_CLOSE = 36, QUESTION = 37, 
    COLON = 38, TILDA = 39, QUOTE = 40, DOUBLE_QUOTE = 41, EXCLAMATION = 42, 
    COMA = 43, SEMICOLON = 44, QUOTE_OPEN = 45, QUOTE_CLOSE = 46, NUMBER = 47, 
    INTEGER = 48, FLOAT = 49, HEX = 50, BIN = 51, ID = 52, STRING = 53, 
    COMMENT = 54, LINE_COMMENT = 55, WS = 56, NL = 57
  };

  enum {
    RuleFile = 0, RuleProgram = 1, RuleProgram_element = 2, RuleSection_access = 3, 
    RuleTake = 4, RuleTake_parts = 5, RuleSection = 6, RuleSection_element = 7, 
    RuleStructure = 8, RuleStructure_generics = 9, RuleStructure_generic = 10, 
    RuleStructure_params = 11, RuleStructure_param = 12, RuleDiia_head = 13, 
    RuleDiia = 14, RuleDiia_generics = 15, RuleDiia_generic = 16, RuleDiia_declaration = 17, 
    RuleParams = 18, RuleParam = 19, RuleBody = 20, RuleBody_element = 21, 
    RuleReturn_body_element = 22, RuleIf = 23, RuleWhile = 24, RuleDeclare = 25, 
    RuleDefine = 26, RuleAssign = 27, RuleSet = 28, RuleParticle = 29, RuleArgs = 30, 
    RuleAtom = 31, RuleMolecule = 32, RuleOperation = 33, RuleExpr = 34, 
    RuleConstruct_args = 35, RuleConstruct_arg = 36, RuleBasic_type = 37, 
    RuleFull_type = 38, RuleComplex_function_type_args = 39, RuleBitwise_op = 40, 
    RuleComparison_op = 41, RuleLogical_op = 42
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
  class Program_elementContext;
  class Section_accessContext;
  class TakeContext;
  class Take_partsContext;
  class SectionContext;
  class Section_elementContext;
  class StructureContext;
  class Structure_genericsContext;
  class Structure_genericContext;
  class Structure_paramsContext;
  class Structure_paramContext;
  class Diia_headContext;
  class DiiaContext;
  class Diia_genericsContext;
  class Diia_genericContext;
  class Diia_declarationContext;
  class ParamsContext;
  class ParamContext;
  class BodyContext;
  class Body_elementContext;
  class Return_body_elementContext;
  class IfContext;
  class WhileContext;
  class DeclareContext;
  class DefineContext;
  class AssignContext;
  class SetContext;
  class ParticleContext;
  class ArgsContext;
  class AtomContext;
  class MoleculeContext;
  class OperationContext;
  class ExprContext;
  class Construct_argsContext;
  class Construct_argContext;
  class Basic_typeContext;
  class Full_typeContext;
  class Complex_function_type_argsContext;
  class Bitwise_opContext;
  class Comparison_opContext;
  class Logical_opContext; 

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
    std::vector<Program_elementContext *> program_element();
    Program_elementContext* program_element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Program_elementContext : public antlr4::ParserRuleContext {
  public:
    Program_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TakeContext *take();
    antlr4::tree::TerminalNode *SEMICOLON();
    DeclareContext *declare();
    DefineContext *define();
    SectionContext *section();
    StructureContext *structure();
    Diia_declarationContext *diia_declaration();
    DiiaContext *diia();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_elementContext* program_element();

  class  Section_accessContext : public antlr4::ParserRuleContext {
  public:
    Section_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Section_accessContext() = default;
    void copyFrom(Section_accessContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdentifierContext : public Section_accessContext {
  public:
    IdentifierContext(Section_accessContext *ctx);

    antlr4::Token *sa_id = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Real_section_accessContext : public Section_accessContext {
  public:
    Real_section_accessContext(Section_accessContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Section_accessContext* section_access();

  class  TakeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *t_type = nullptr;
    antlr4::Token *t_string = nullptr;
    TsilParser::Take_partsContext *t_parts = nullptr;
    TakeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IMPORT();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *STRING();
    Take_partsContext *take_parts();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TakeContext* take();

  class  Take_partsContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *tp_relative = nullptr;
    Take_partsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIVIDE();
    antlr4::tree::TerminalNode* DIVIDE(size_t i);
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Take_partsContext* take_parts();

  class  SectionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *s_name = nullptr;
    SectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SECTION();
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    antlr4::tree::TerminalNode *ID();
    std::vector<Section_elementContext *> section_element();
    Section_elementContext* section_element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SectionContext* section();

  class  Section_elementContext : public antlr4::ParserRuleContext {
  public:
    Section_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclareContext *declare();
    antlr4::tree::TerminalNode *SEMICOLON();
    DefineContext *define();
    SectionContext *section();
    StructureContext *structure();
    Diia_declarationContext *diia_declaration();
    DiiaContext *diia();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Section_elementContext* section_element();

  class  StructureContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *s_name = nullptr;
    TsilParser::Structure_genericsContext *s_generics = nullptr;
    TsilParser::Structure_paramsContext *s_params = nullptr;
    StructureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCT();
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    Structure_genericsContext *structure_generics();
    Structure_paramsContext *structure_params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructureContext* structure();

  class  Structure_genericsContext : public antlr4::ParserRuleContext {
  public:
    Structure_genericsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Structure_genericContext *> structure_generic();
    Structure_genericContext* structure_generic(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_genericsContext* structure_generics();

  class  Structure_genericContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *sg_name = nullptr;
    Structure_genericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_genericContext* structure_generic();

  class  Structure_paramsContext : public antlr4::ParserRuleContext {
  public:
    Structure_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Structure_paramContext *> structure_param();
    Structure_paramContext* structure_param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_paramsContext* structure_params();

  class  Structure_paramContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *sp_name = nullptr;
    TsilParser::Full_typeContext *sp_type = nullptr;
    Structure_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *ID();
    Full_typeContext *full_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_paramContext* structure_param();

  class  Diia_headContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_name = nullptr;
    TsilParser::Diia_genericsContext *d_generics = nullptr;
    TsilParser::ParamsContext *d_params = nullptr;
    antlr4::Token *d_variadic = nullptr;
    TsilParser::Full_typeContext *d_type = nullptr;
    Diia_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    antlr4::tree::TerminalNode *COLON();
    Diia_genericsContext *diia_generics();
    ParamsContext *params();
    antlr4::tree::TerminalNode *COMA();
    Full_typeContext *full_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_headContext* diia_head();

  class  DiiaContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_extern = nullptr;
    antlr4::Token *d_local = nullptr;
    antlr4::Token *d_internal = nullptr;
    TsilParser::Diia_headContext *d_head = nullptr;
    TsilParser::BodyContext *d_body = nullptr;
    DiiaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    Diia_headContext *diia_head();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiiaContext* diia();

  class  Diia_genericsContext : public antlr4::ParserRuleContext {
  public:
    Diia_genericsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Diia_genericContext *> diia_generic();
    Diia_genericContext* diia_generic(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_genericsContext* diia_generics();

  class  Diia_genericContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *dg_name = nullptr;
    Diia_genericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_genericContext* diia_generic();

  class  Diia_declarationContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_extern = nullptr;
    antlr4::Token *d_local = nullptr;
    antlr4::Token *d_internal = nullptr;
    TsilParser::Diia_headContext *d_head = nullptr;
    antlr4::Token *d_as = nullptr;
    Diia_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    Diia_headContext *diia_head();
    antlr4::tree::TerminalNode *KW_AS();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_declarationContext* diia_declaration();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *p_name = nullptr;
    TsilParser::Full_typeContext *p_type = nullptr;
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *ID();
    Full_typeContext *full_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    IfContext *if_();
    WhileContext *while_();
    DeclareContext *declare();
    antlr4::tree::TerminalNode *SEMICOLON();
    DefineContext *define();
    AssignContext *assign();
    SetContext *set();
    ExprContext *expr();
    Return_body_elementContext *return_body_element();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Body_elementContext* body_element();

  class  Return_body_elementContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::ExprContext *rbl_value = nullptr;
    Return_body_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_body_elementContext* return_body_element();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::ExprContext *i_value = nullptr;
    TsilParser::BodyContext *i_body = nullptr;
    TsilParser::BodyContext *i_else_body = nullptr;
    IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IF();
    std::vector<antlr4::tree::TerminalNode *> QUOTE_OPEN();
    antlr4::tree::TerminalNode* QUOTE_OPEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUOTE_CLOSE();
    antlr4::tree::TerminalNode* QUOTE_CLOSE(size_t i);
    ExprContext *expr();
    antlr4::tree::TerminalNode *KW_ELSE();
    std::vector<BodyContext *> body();
    BodyContext* body(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfContext* if_();

  class  WhileContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::ExprContext *w_value = nullptr;
    TsilParser::BodyContext *w_body = nullptr;
    WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_WHILE();
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    ExprContext *expr();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileContext* while_();

  class  DeclareContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_extern = nullptr;
    antlr4::Token *d_local = nullptr;
    antlr4::Token *d_internal = nullptr;
    antlr4::Token *d_tsil = nullptr;
    antlr4::Token *d_var = nullptr;
    antlr4::Token *d_id = nullptr;
    TsilParser::Full_typeContext *d_type = nullptr;
    DeclareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *ID();
    Full_typeContext *full_type();
    antlr4::tree::TerminalNode *KW_TSIL();
    antlr4::tree::TerminalNode *KW_VAR();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareContext* declare();

  class  DefineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_extern = nullptr;
    antlr4::Token *d_local = nullptr;
    antlr4::Token *d_internal = nullptr;
    antlr4::Token *d_tsil = nullptr;
    antlr4::Token *d_var = nullptr;
    antlr4::Token *d_id = nullptr;
    TsilParser::Full_typeContext *d_type = nullptr;
    TsilParser::ExprContext *d_value = nullptr;
    DefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    antlr4::tree::TerminalNode *KW_TSIL();
    antlr4::tree::TerminalNode *KW_VAR();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *KW_PUBLIC();
    antlr4::tree::TerminalNode *KW_LOCAL();
    antlr4::tree::TerminalNode *KW_PRIVATE();
    Full_typeContext *full_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefineContext* define();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *a_id = nullptr;
    TsilParser::ExprContext *a_value = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::ParticleContext *s_left = nullptr;
    antlr4::Token *s_id = nullptr;
    TsilParser::ExprContext *s_index = nullptr;
    TsilParser::ExprContext *s_value = nullptr;
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    ParticleContext *particle();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  ParticleContext : public antlr4::ParserRuleContext {
  public:
    ParticleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ParticleContext() = default;
    void copyFrom(ParticleContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallContext : public ParticleContext {
  public:
    CallContext(ParticleContext *ctx);

    TsilParser::ParticleContext *c_value = nullptr;
    TsilParser::ArgsContext *c_args = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    ParticleContext *particle();
    ArgsContext *args();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AccessContext : public ParticleContext {
  public:
    AccessContext(ParticleContext *ctx);

    TsilParser::ParticleContext *a_value = nullptr;
    TsilParser::ExprContext *a_index = nullptr;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    ParticleContext *particle();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GetContext : public ParticleContext {
  public:
    GetContext(ParticleContext *ctx);

    TsilParser::ParticleContext *g_left = nullptr;
    antlr4::Token *g_id = nullptr;
    antlr4::tree::TerminalNode *DOT();
    ParticleContext *particle();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Particle_section_accessContext : public ParticleContext {
  public:
    Particle_section_accessContext(ParticleContext *ctx);

    Section_accessContext *section_access();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NestedContext : public ParticleContext {
  public:
    NestedContext(ParticleContext *ctx);

    TsilParser::ExprContext *n_value = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GenericContext : public ParticleContext {
  public:
    GenericContext(ParticleContext *ctx);

    TsilParser::ParticleContext *g_left = nullptr;
    TsilParser::Full_typeContext *sa_generic_value = nullptr;
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    ParticleContext *particle();
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ParticleContext* particle();
  ParticleContext* particle(int precedence);
  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_particleContext : public AtomContext {
  public:
    Atom_particleContext(AtomContext *ctx);

    ParticleContext *particle();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberContext : public AtomContext {
  public:
    NumberContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public AtomContext {
  public:
    StringContext(AtomContext *ctx);

    antlr4::Token *s_prefix = nullptr;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();

  class  MoleculeContext : public antlr4::ParserRuleContext {
  public:
    MoleculeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MoleculeContext() = default;
    void copyFrom(MoleculeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Molecule_atomContext : public MoleculeContext {
  public:
    Molecule_atomContext(MoleculeContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotContext : public MoleculeContext {
  public:
    NotContext(MoleculeContext *ctx);

    TsilParser::MoleculeContext *n_value = nullptr;
    antlr4::tree::TerminalNode *EXCLAMATION();
    MoleculeContext *molecule();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeContext : public MoleculeContext {
  public:
    NegativeContext(MoleculeContext *ctx);

    TsilParser::AtomContext *n_value = nullptr;
    antlr4::tree::TerminalNode *MINUS();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bitwise_notContext : public MoleculeContext {
  public:
    Bitwise_notContext(MoleculeContext *ctx);

    TsilParser::AtomContext *bn_value = nullptr;
    antlr4::tree::TerminalNode *TILDA();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositiveContext : public MoleculeContext {
  public:
    PositiveContext(MoleculeContext *ctx);

    TsilParser::AtomContext *p_value = nullptr;
    antlr4::tree::TerminalNode *PLUS();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MoleculeContext* molecule();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OperationContext() = default;
    void copyFrom(OperationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddContext : public OperationContext {
  public:
    AddContext(OperationContext *ctx);

    TsilParser::OperationContext *a_left = nullptr;
    antlr4::Token *a_operation = nullptr;
    TsilParser::OperationContext *a_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AsContext : public OperationContext {
  public:
    AsContext(OperationContext *ctx);

    TsilParser::MoleculeContext *a_left = nullptr;
    TsilParser::Full_typeContext *a_type = nullptr;
    antlr4::tree::TerminalNode *KW_AS();
    MoleculeContext *molecule();
    Full_typeContext *full_type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComparisonContext : public OperationContext {
  public:
    ComparisonContext(OperationContext *ctx);

    TsilParser::OperationContext *c_left = nullptr;
    TsilParser::Comparison_opContext *c_operation = nullptr;
    TsilParser::OperationContext *c_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Comparison_opContext *comparison_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulContext : public OperationContext {
  public:
    MulContext(OperationContext *ctx);

    TsilParser::OperationContext *a_left = nullptr;
    antlr4::Token *a_operation = nullptr;
    TsilParser::OperationContext *a_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *MOD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitwiseContext : public OperationContext {
  public:
    BitwiseContext(OperationContext *ctx);

    TsilParser::OperationContext *b_left = nullptr;
    TsilParser::Bitwise_opContext *b_operation = nullptr;
    TsilParser::OperationContext *b_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Bitwise_opContext *bitwise_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Operation_moleculeContext : public OperationContext {
  public:
    Operation_moleculeContext(OperationContext *ctx);

    MoleculeContext *molecule();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalContext : public OperationContext {
  public:
    LogicalContext(OperationContext *ctx);

    TsilParser::OperationContext *t_left = nullptr;
    TsilParser::Logical_opContext *t_operation = nullptr;
    TsilParser::OperationContext *t_right = nullptr;
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    Logical_opContext *logical_op();
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

  class  ConstructContext : public ExprContext {
  public:
    ConstructContext(ExprContext *ctx);

    TsilParser::Full_typeContext *c_type = nullptr;
    TsilParser::Construct_argsContext *c_args = nullptr;
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    Full_typeContext *full_type();
    Construct_argsContext *construct_args();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  Construct_argsContext : public antlr4::ParserRuleContext {
  public:
    Construct_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Construct_argContext *> construct_arg();
    Construct_argContext* construct_arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Construct_argsContext* construct_args();

  class  Construct_argContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ca_name = nullptr;
    TsilParser::ExprContext *ca_value = nullptr;
    Construct_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Construct_argContext* construct_arg();

  class  Basic_typeContext : public antlr4::ParserRuleContext {
  public:
    Basic_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Basic_typeContext() = default;
    void copyFrom(Basic_typeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Simple_typeContext : public Basic_typeContext {
  public:
    Simple_typeContext(Basic_typeContext *ctx);

    TsilParser::Full_typeContext *t_first_generic_type = nullptr;
    Section_accessContext *section_access();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Array_typeContext : public Basic_typeContext {
  public:
    Array_typeContext(Basic_typeContext *ctx);

    TsilParser::Basic_typeContext *at_type = nullptr;
    antlr4::Token *at_size = nullptr;
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    Basic_typeContext *basic_type();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Basic_typeContext* basic_type();
  Basic_typeContext* basic_type(int precedence);
  class  Full_typeContext : public antlr4::ParserRuleContext {
  public:
    Full_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Full_typeContext() = default;
    void copyFrom(Full_typeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Simple_function_typeContext : public Full_typeContext {
  public:
    Simple_function_typeContext(Full_typeContext *ctx);

    TsilParser::Full_typeContext *sft_arg = nullptr;
    TsilParser::Full_typeContext *sft_ret = nullptr;
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Complex_function_typeContext : public Full_typeContext {
  public:
    Complex_function_typeContext(Full_typeContext *ctx);

    TsilParser::Complex_function_type_argsContext *cft_args = nullptr;
    TsilParser::Full_typeContext *cft_ret = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    Full_typeContext *full_type();
    Complex_function_type_argsContext *complex_function_type_args();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Full_type_basic_typeContext : public Full_typeContext {
  public:
    Full_type_basic_typeContext(Full_typeContext *ctx);

    Basic_typeContext *basic_type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Full_typeContext* full_type();
  Full_typeContext* full_type(int precedence);
  class  Complex_function_type_argsContext : public antlr4::ParserRuleContext {
  public:
    Complex_function_type_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Complex_function_type_argsContext* complex_function_type_args();

  class  Bitwise_opContext : public antlr4::ParserRuleContext {
  public:
    Bitwise_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POWER();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *AND();
    std::vector<antlr4::tree::TerminalNode *> LESSER();
    antlr4::tree::TerminalNode* LESSER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bitwise_opContext* bitwise_op();

  class  Comparison_opContext : public antlr4::ParserRuleContext {
  public:
    Comparison_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    antlr4::tree::TerminalNode *EXCLAMATION();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *LESSER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Comparison_opContext* comparison_op();

  class  Logical_opContext : public antlr4::ParserRuleContext {
  public:
    Logical_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    antlr4::tree::TerminalNode *KW_OR();
    antlr4::tree::TerminalNode *KW_AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_opContext* logical_op();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool particleSempred(ParticleContext *_localctx, size_t predicateIndex);
  bool operationSempred(OperationContext *_localctx, size_t predicateIndex);
  bool basic_typeSempred(Basic_typeContext *_localctx, size_t predicateIndex);
  bool full_typeSempred(Full_typeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

