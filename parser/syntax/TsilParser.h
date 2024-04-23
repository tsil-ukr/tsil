
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  TsilParser : public antlr4::Parser {
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

  enum {
    RuleFile = 0, RuleProgram = 1, RuleProgram_element = 2, RuleStructure = 3, 
    RuleStructure_generics = 4, RuleStructure_generic = 5, RuleStructure_params = 6, 
    RuleStructure_param = 7, RuleConstructor = 8, RuleConstructor_args = 9, 
    RuleConstructor_arg = 10, RuleDiia_head = 11, RuleDiia = 12, RuleDiia_declaration = 13, 
    RuleDiia_generics = 14, RuleDiia_generic = 15, RuleSection = 16, RuleSection_element = 17, 
    RuleIf = 18, RuleWhile = 19, RuleDefine = 20, RuleAssign = 21, RuleSet = 22, 
    RuleSizeof = 23, RuleAtom = 24, RuleMolecule = 25, RuleExpr = 26, RuleIdentifiers_chain = 27, 
    RuleFull_type = 28, RuleSimple_function_type_args = 29, RuleArgs = 30, 
    RuleParams = 31, RuleParam = 32, RuleBody = 33, RuleBody_element_or_return = 34, 
    RuleBody_element = 35, RuleReturn_body_element = 36, RuleBitwise_op = 37, 
    RuleComparison_op = 38, RuleLogical_op = 39, RuleNumber = 40, RuleString = 41, 
    RuleIdentifier = 42
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
  class StructureContext;
  class Structure_genericsContext;
  class Structure_genericContext;
  class Structure_paramsContext;
  class Structure_paramContext;
  class ConstructorContext;
  class Constructor_argsContext;
  class Constructor_argContext;
  class Diia_headContext;
  class DiiaContext;
  class Diia_declarationContext;
  class Diia_genericsContext;
  class Diia_genericContext;
  class SectionContext;
  class Section_elementContext;
  class IfContext;
  class WhileContext;
  class DefineContext;
  class AssignContext;
  class SetContext;
  class SizeofContext;
  class AtomContext;
  class MoleculeContext;
  class ExprContext;
  class Identifiers_chainContext;
  class Full_typeContext;
  class Simple_function_type_argsContext;
  class ArgsContext;
  class ParamsContext;
  class ParamContext;
  class BodyContext;
  class Body_element_or_returnContext;
  class Body_elementContext;
  class Return_body_elementContext;
  class Bitwise_opContext;
  class Comparison_opContext;
  class Logical_opContext;
  class NumberContext;
  class StringContext;
  class IdentifierContext; 

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
    StructureContext *structure();
    Diia_declarationContext *diia_declaration();
    DiiaContext *diia();
    SectionContext *section();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_elementContext* program_element();

  class  StructureContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *s_name = nullptr;
    TsilParser::Structure_genericsContext *s_generics = nullptr;
    TsilParser::Structure_paramsContext *s_params = nullptr;
    StructureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_STRUCT();
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    IdentifierContext *identifier();
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
    TsilParser::IdentifierContext *sg_name = nullptr;
    Structure_genericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

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
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_paramsContext* structure_params();

  class  Structure_paramContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *sp_name = nullptr;
    TsilParser::Full_typeContext *sp_type = nullptr;
    Structure_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    IdentifierContext *identifier();
    Full_typeContext *full_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_paramContext* structure_param();

  class  ConstructorContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *c_new = nullptr;
    TsilParser::Full_typeContext *c_type = nullptr;
    TsilParser::Constructor_argsContext *c_args = nullptr;
    ConstructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    Full_typeContext *full_type();
    antlr4::tree::TerminalNode *KW_SAVE();
    Constructor_argsContext *constructor_args();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorContext* constructor();

  class  Constructor_argsContext : public antlr4::ParserRuleContext {
  public:
    Constructor_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constructor_argContext *> constructor_arg();
    Constructor_argContext* constructor_arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_argsContext* constructor_args();

  class  Constructor_argContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *ca_name = nullptr;
    TsilParser::ExprContext *ca_value = nullptr;
    Constructor_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constructor_argContext* constructor_arg();

  class  Diia_headContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *d_name = nullptr;
    TsilParser::Diia_genericsContext *d_generics = nullptr;
    TsilParser::ParamsContext *d_params = nullptr;
    antlr4::Token *d_variadic = nullptr;
    TsilParser::Full_typeContext *d_type = nullptr;
    Diia_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DIIA();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LESSER();
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    antlr4::tree::TerminalNode *MINUS();
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
    TsilParser::StringContext *d_extern_type = nullptr;
    TsilParser::Diia_headContext *d_head = nullptr;
    TsilParser::BodyContext *d_body = nullptr;
    DiiaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    Diia_headContext *diia_head();
    antlr4::tree::TerminalNode *KW_EXTERN();
    BodyContext *body();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiiaContext* diia();

  class  Diia_declarationContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *d_extern = nullptr;
    TsilParser::StringContext *d_extern_type = nullptr;
    TsilParser::Diia_headContext *d_head = nullptr;
    TsilParser::IdentifierContext *d_as = nullptr;
    Diia_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    Diia_headContext *diia_head();
    antlr4::tree::TerminalNode *KW_AS();
    antlr4::tree::TerminalNode *KW_EXTERN();
    IdentifierContext *identifier();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_declarationContext* diia_declaration();

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
    TsilParser::IdentifierContext *dg_name = nullptr;
    Diia_genericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Diia_genericContext* diia_generic();

  class  SectionContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *s_name = nullptr;
    SectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SECTION();
    antlr4::tree::TerminalNode *QUOTE_OPEN();
    antlr4::tree::TerminalNode *QUOTE_CLOSE();
    IdentifierContext *identifier();
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
    StructureContext *structure();
    Diia_declarationContext *diia_declaration();
    DiiaContext *diia();
    SectionContext *section();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Section_elementContext* section_element();

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

  class  DefineContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *d_id = nullptr;
    TsilParser::Full_typeContext *d_type = nullptr;
    TsilParser::ExprContext *d_value = nullptr;
    DefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_TSIL();
    antlr4::tree::TerminalNode *EQUAL();
    IdentifierContext *identifier();
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLON();
    Full_typeContext *full_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefineContext* define();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::IdentifierContext *a_id = nullptr;
    TsilParser::ExprContext *a_value = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::Identifiers_chainContext *s_left = nullptr;
    TsilParser::IdentifierContext *s_id = nullptr;
    TsilParser::ExprContext *s_value = nullptr;
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *EQUAL();
    Identifiers_chainContext *identifiers_chain();
    IdentifierContext *identifier();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  SizeofContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::Full_typeContext *s_type = nullptr;
    TsilParser::ExprContext *s_value = nullptr;
    SizeofContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_SIZEOF();
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    Full_typeContext *full_type();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SizeofContext* sizeof_();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallContext : public AtomContext {
  public:
    CallContext(AtomContext *ctx);

    TsilParser::AtomContext *c_value = nullptr;
    TsilParser::Full_typeContext *c_first_generic_type = nullptr;
    TsilParser::ArgsContext *c_args = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    AtomContext *atom();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    ArgsContext *args();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeContext : public AtomContext {
  public:
    NegativeContext(AtomContext *ctx);

    TsilParser::AtomContext *n_value = nullptr;
    antlr4::tree::TerminalNode *MINUS();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotContext : public AtomContext {
  public:
    NotContext(AtomContext *ctx);

    TsilParser::AtomContext *n_value = nullptr;
    antlr4::tree::TerminalNode *EXCLAMATION();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bitwise_notContext : public AtomContext {
  public:
    Bitwise_notContext(AtomContext *ctx);

    TsilParser::AtomContext *bn_value = nullptr;
    antlr4::tree::TerminalNode *TILDA();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GetContext : public AtomContext {
  public:
    GetContext(AtomContext *ctx);

    TsilParser::AtomContext *g_left = nullptr;
    TsilParser::IdentifierContext *g_id = nullptr;
    antlr4::tree::TerminalNode *DOT();
    AtomContext *atom();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_identifierContext : public AtomContext {
  public:
    Atom_identifierContext(AtomContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositiveContext : public AtomContext {
  public:
    PositiveContext(AtomContext *ctx);

    TsilParser::AtomContext *p_value = nullptr;
    antlr4::tree::TerminalNode *PLUS();
    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NestedContext : public AtomContext {
  public:
    NestedContext(AtomContext *ctx);

    TsilParser::ExprContext *n_value = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();
  AtomContext* atom(int precedence);
  class  MoleculeContext : public antlr4::ParserRuleContext {
  public:
    MoleculeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MoleculeContext() = default;
    void copyFrom(MoleculeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_numberContext : public MoleculeContext {
  public:
    Atom_numberContext(MoleculeContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Value_atomContext : public MoleculeContext {
  public:
    Value_atomContext(MoleculeContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_stringContext : public MoleculeContext {
  public:
    Atom_stringContext(MoleculeContext *ctx);

    StringContext *string();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MoleculeContext* molecule();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Arithmetic_mulContext : public ExprContext {
  public:
    Arithmetic_mulContext(ExprContext *ctx);

    TsilParser::ExprContext *a_left = nullptr;
    antlr4::Token *a_operation = nullptr;
    TsilParser::ExprContext *a_right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *MOD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Not_textContext : public ExprContext {
  public:
    Not_textContext(ExprContext *ctx);

    TsilParser::MoleculeContext *nt_value = nullptr;
    antlr4::tree::TerminalNode *KW_NOT();
    MoleculeContext *molecule();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AsContext : public ExprContext {
  public:
    AsContext(ExprContext *ctx);

    TsilParser::MoleculeContext *a_left = nullptr;
    TsilParser::Full_typeContext *a_type = nullptr;
    antlr4::tree::TerminalNode *KW_AS();
    MoleculeContext *molecule();
    Full_typeContext *full_type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Arithmetic_addContext : public ExprContext {
  public:
    Arithmetic_addContext(ExprContext *ctx);

    TsilParser::ExprContext *a_left = nullptr;
    antlr4::Token *a_operation = nullptr;
    TsilParser::ExprContext *a_right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComparisonContext : public ExprContext {
  public:
    ComparisonContext(ExprContext *ctx);

    TsilParser::ExprContext *c_left = nullptr;
    TsilParser::Comparison_opContext *c_operation = nullptr;
    TsilParser::ExprContext *c_right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Comparison_opContext *comparison_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_constructorContext : public ExprContext {
  public:
    Atom_constructorContext(ExprContext *ctx);

    ConstructorContext *constructor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitwiseContext : public ExprContext {
  public:
    BitwiseContext(ExprContext *ctx);

    TsilParser::ExprContext *b_left = nullptr;
    TsilParser::Bitwise_opContext *b_operation = nullptr;
    TsilParser::ExprContext *b_right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Bitwise_opContext *bitwise_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_moleculeContext : public ExprContext {
  public:
    Expr_moleculeContext(ExprContext *ctx);

    MoleculeContext *molecule();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalContext : public ExprContext {
  public:
    LogicalContext(ExprContext *ctx);

    TsilParser::ExprContext *t_left = nullptr;
    TsilParser::Logical_opContext *t_operation = nullptr;
    TsilParser::ExprContext *t_right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Logical_opContext *logical_op();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Atom_sizeofContext : public ExprContext {
  public:
    Atom_sizeofContext(ExprContext *ctx);

    SizeofContext *sizeof_();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  Identifiers_chainContext : public antlr4::ParserRuleContext {
  public:
    TsilParser::Identifiers_chainContext *ic_left = nullptr;
    antlr4::Token *ic_id = nullptr;
    antlr4::Token *ic_right = nullptr;
    Identifiers_chainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *DOT();
    Identifiers_chainContext *identifiers_chain();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifiers_chainContext* identifiers_chain();
  Identifiers_chainContext* identifiers_chain(int precedence);
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

    TsilParser::Simple_function_type_argsContext *cft_args = nullptr;
    TsilParser::Full_typeContext *cft_ret = nullptr;
    antlr4::tree::TerminalNode *PAREN_OPEN();
    antlr4::tree::TerminalNode *PAREN_CLOSE();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *GREATER();
    Full_typeContext *full_type();
    Simple_function_type_argsContext *simple_function_type_args();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeContext : public Full_typeContext {
  public:
    TypeContext(Full_typeContext *ctx);

    TsilParser::Full_typeContext *t_first_generic_type = nullptr;
    TsilParser::ExprContext *ft_arr_size = nullptr;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LESSER();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *BRACKET_OPEN();
    antlr4::tree::TerminalNode *BRACKET_CLOSE();
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Full_typeContext* full_type();
  Full_typeContext* full_type(int precedence);
  class  Simple_function_type_argsContext : public antlr4::ParserRuleContext {
  public:
    Simple_function_type_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Full_typeContext *> full_type();
    Full_typeContext* full_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMA();
    antlr4::tree::TerminalNode* COMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_function_type_argsContext* simple_function_type_args();

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
    TsilParser::IdentifierContext *p_name = nullptr;
    TsilParser::Full_typeContext *p_type = nullptr;
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    IdentifierContext *identifier();
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
    std::vector<Body_element_or_returnContext *> body_element_or_return();
    Body_element_or_returnContext* body_element_or_return(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BodyContext* body();

  class  Body_element_or_returnContext : public antlr4::ParserRuleContext {
  public:
    Body_element_or_returnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Body_elementContext *body_element();
    Return_body_elementContext *return_body_element();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Body_element_or_returnContext* body_element_or_return();

  class  Body_elementContext : public antlr4::ParserRuleContext {
  public:
    Body_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfContext *if_();
    WhileContext *while_();
    DefineContext *define();
    antlr4::tree::TerminalNode *SEMICOLON();
    AssignContext *assign();
    SetContext *set();
    ExprContext *expr();

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

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *HEX();
    antlr4::tree::TerminalNode *BIN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *s_prefix = nullptr;
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool atomSempred(AtomContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);
  bool identifiers_chainSempred(Identifiers_chainContext *_localctx, size_t predicateIndex);
  bool full_typeSempred(Full_typeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

