
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "TsilParserVisitor.h"


/**
 * This class provides an empty implementation of TsilParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TsilParserBaseVisitor : public TsilParserVisitor {
public:

  virtual std::any visitFile(TsilParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(TsilParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram_element(TsilParser::Program_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection(TsilParser::SectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_element(TsilParser::Section_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure(TsilParser::StructureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_generics(TsilParser::Structure_genericsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_generic(TsilParser::Structure_genericContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_params(TsilParser::Structure_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_param(TsilParser::Structure_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_head(TsilParser::Diia_headContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia(TsilParser::DiiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_generics(TsilParser::Diia_genericsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_generic(TsilParser::Diia_genericContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_declaration(TsilParser::Diia_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(TsilParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(TsilParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(TsilParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody_element(TsilParser::Body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_body_element(TsilParser::Return_body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(TsilParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(TsilParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclare(TsilParser::DeclareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefine(TsilParser::DefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(TsilParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet(TsilParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(TsilParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(TsilParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccess(TsilParser::AccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGet(TsilParser::GetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNested(TsilParser::NestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(TsilParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_particle(TsilParser::Atom_particleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(TsilParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(TsilParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMolecule_atom(TsilParser::Molecule_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNot(TsilParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPositive(TsilParser::PositiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegative(TsilParser::NegativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise_not(TsilParser::Bitwise_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdd(TsilParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs(TsilParser::AsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(TsilParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMul(TsilParser::MulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise(TsilParser::BitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_molecule(TsilParser::Operation_moleculeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical(TsilParser::LogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_operation(TsilParser::Expr_operationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstruct(TsilParser::ConstructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstruct_args(TsilParser::Construct_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstruct_arg(TsilParser::Construct_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_type(TsilParser::Simple_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_type(TsilParser::Array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_function_type(TsilParser::Simple_function_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComplex_function_type(TsilParser::Complex_function_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFull_type_basic_type(TsilParser::Full_type_basic_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComplex_function_type_args(TsilParser::Complex_function_type_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise_op(TsilParser::Bitwise_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison_op(TsilParser::Comparison_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_op(TsilParser::Logical_opContext *ctx) override {
    return visitChildren(ctx);
  }


};

