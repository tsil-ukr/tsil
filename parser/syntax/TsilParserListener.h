
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "TsilParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TsilParser.
 */
class  TsilParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(TsilParser::FileContext *ctx) = 0;
  virtual void exitFile(TsilParser::FileContext *ctx) = 0;

  virtual void enterProgram(TsilParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(TsilParser::ProgramContext *ctx) = 0;

  virtual void enterProgram_element(TsilParser::Program_elementContext *ctx) = 0;
  virtual void exitProgram_element(TsilParser::Program_elementContext *ctx) = 0;

  virtual void enterIdentifier(TsilParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(TsilParser::IdentifierContext *ctx) = 0;

  virtual void enterReal_section_access(TsilParser::Real_section_accessContext *ctx) = 0;
  virtual void exitReal_section_access(TsilParser::Real_section_accessContext *ctx) = 0;

  virtual void enterTake(TsilParser::TakeContext *ctx) = 0;
  virtual void exitTake(TsilParser::TakeContext *ctx) = 0;

  virtual void enterTake_parts(TsilParser::Take_partsContext *ctx) = 0;
  virtual void exitTake_parts(TsilParser::Take_partsContext *ctx) = 0;

  virtual void enterSection(TsilParser::SectionContext *ctx) = 0;
  virtual void exitSection(TsilParser::SectionContext *ctx) = 0;

  virtual void enterSection_element(TsilParser::Section_elementContext *ctx) = 0;
  virtual void exitSection_element(TsilParser::Section_elementContext *ctx) = 0;

  virtual void enterStructure(TsilParser::StructureContext *ctx) = 0;
  virtual void exitStructure(TsilParser::StructureContext *ctx) = 0;

  virtual void enterStructure_generics(TsilParser::Structure_genericsContext *ctx) = 0;
  virtual void exitStructure_generics(TsilParser::Structure_genericsContext *ctx) = 0;

  virtual void enterStructure_generic(TsilParser::Structure_genericContext *ctx) = 0;
  virtual void exitStructure_generic(TsilParser::Structure_genericContext *ctx) = 0;

  virtual void enterStructure_params(TsilParser::Structure_paramsContext *ctx) = 0;
  virtual void exitStructure_params(TsilParser::Structure_paramsContext *ctx) = 0;

  virtual void enterStructure_param(TsilParser::Structure_paramContext *ctx) = 0;
  virtual void exitStructure_param(TsilParser::Structure_paramContext *ctx) = 0;

  virtual void enterDiia_head(TsilParser::Diia_headContext *ctx) = 0;
  virtual void exitDiia_head(TsilParser::Diia_headContext *ctx) = 0;

  virtual void enterDiia(TsilParser::DiiaContext *ctx) = 0;
  virtual void exitDiia(TsilParser::DiiaContext *ctx) = 0;

  virtual void enterDiia_generics(TsilParser::Diia_genericsContext *ctx) = 0;
  virtual void exitDiia_generics(TsilParser::Diia_genericsContext *ctx) = 0;

  virtual void enterDiia_generic(TsilParser::Diia_genericContext *ctx) = 0;
  virtual void exitDiia_generic(TsilParser::Diia_genericContext *ctx) = 0;

  virtual void enterDiia_declaration(TsilParser::Diia_declarationContext *ctx) = 0;
  virtual void exitDiia_declaration(TsilParser::Diia_declarationContext *ctx) = 0;

  virtual void enterParams(TsilParser::ParamsContext *ctx) = 0;
  virtual void exitParams(TsilParser::ParamsContext *ctx) = 0;

  virtual void enterParam(TsilParser::ParamContext *ctx) = 0;
  virtual void exitParam(TsilParser::ParamContext *ctx) = 0;

  virtual void enterBody(TsilParser::BodyContext *ctx) = 0;
  virtual void exitBody(TsilParser::BodyContext *ctx) = 0;

  virtual void enterBody_element(TsilParser::Body_elementContext *ctx) = 0;
  virtual void exitBody_element(TsilParser::Body_elementContext *ctx) = 0;

  virtual void enterReturn_body_element(TsilParser::Return_body_elementContext *ctx) = 0;
  virtual void exitReturn_body_element(TsilParser::Return_body_elementContext *ctx) = 0;

  virtual void enterBlock(TsilParser::BlockContext *ctx) = 0;
  virtual void exitBlock(TsilParser::BlockContext *ctx) = 0;

  virtual void enterIf(TsilParser::IfContext *ctx) = 0;
  virtual void exitIf(TsilParser::IfContext *ctx) = 0;

  virtual void enterWhile(TsilParser::WhileContext *ctx) = 0;
  virtual void exitWhile(TsilParser::WhileContext *ctx) = 0;

  virtual void enterDeclare(TsilParser::DeclareContext *ctx) = 0;
  virtual void exitDeclare(TsilParser::DeclareContext *ctx) = 0;

  virtual void enterDefine(TsilParser::DefineContext *ctx) = 0;
  virtual void exitDefine(TsilParser::DefineContext *ctx) = 0;

  virtual void enterAssign(TsilParser::AssignContext *ctx) = 0;
  virtual void exitAssign(TsilParser::AssignContext *ctx) = 0;

  virtual void enterSet(TsilParser::SetContext *ctx) = 0;
  virtual void exitSet(TsilParser::SetContext *ctx) = 0;

  virtual void enterCall(TsilParser::CallContext *ctx) = 0;
  virtual void exitCall(TsilParser::CallContext *ctx) = 0;

  virtual void enterAccess(TsilParser::AccessContext *ctx) = 0;
  virtual void exitAccess(TsilParser::AccessContext *ctx) = 0;

  virtual void enterGet(TsilParser::GetContext *ctx) = 0;
  virtual void exitGet(TsilParser::GetContext *ctx) = 0;

  virtual void enterParticle_section_access(TsilParser::Particle_section_accessContext *ctx) = 0;
  virtual void exitParticle_section_access(TsilParser::Particle_section_accessContext *ctx) = 0;

  virtual void enterNested(TsilParser::NestedContext *ctx) = 0;
  virtual void exitNested(TsilParser::NestedContext *ctx) = 0;

  virtual void enterGeneric(TsilParser::GenericContext *ctx) = 0;
  virtual void exitGeneric(TsilParser::GenericContext *ctx) = 0;

  virtual void enterArgs(TsilParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(TsilParser::ArgsContext *ctx) = 0;

  virtual void enterAtom_particle(TsilParser::Atom_particleContext *ctx) = 0;
  virtual void exitAtom_particle(TsilParser::Atom_particleContext *ctx) = 0;

  virtual void enterNumber(TsilParser::NumberContext *ctx) = 0;
  virtual void exitNumber(TsilParser::NumberContext *ctx) = 0;

  virtual void enterString(TsilParser::StringContext *ctx) = 0;
  virtual void exitString(TsilParser::StringContext *ctx) = 0;

  virtual void enterMolecule_atom(TsilParser::Molecule_atomContext *ctx) = 0;
  virtual void exitMolecule_atom(TsilParser::Molecule_atomContext *ctx) = 0;

  virtual void enterNot(TsilParser::NotContext *ctx) = 0;
  virtual void exitNot(TsilParser::NotContext *ctx) = 0;

  virtual void enterPositive(TsilParser::PositiveContext *ctx) = 0;
  virtual void exitPositive(TsilParser::PositiveContext *ctx) = 0;

  virtual void enterNegative(TsilParser::NegativeContext *ctx) = 0;
  virtual void exitNegative(TsilParser::NegativeContext *ctx) = 0;

  virtual void enterBitwise_not(TsilParser::Bitwise_notContext *ctx) = 0;
  virtual void exitBitwise_not(TsilParser::Bitwise_notContext *ctx) = 0;

  virtual void enterAdd(TsilParser::AddContext *ctx) = 0;
  virtual void exitAdd(TsilParser::AddContext *ctx) = 0;

  virtual void enterAs(TsilParser::AsContext *ctx) = 0;
  virtual void exitAs(TsilParser::AsContext *ctx) = 0;

  virtual void enterComparison(TsilParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(TsilParser::ComparisonContext *ctx) = 0;

  virtual void enterMul(TsilParser::MulContext *ctx) = 0;
  virtual void exitMul(TsilParser::MulContext *ctx) = 0;

  virtual void enterBitwise(TsilParser::BitwiseContext *ctx) = 0;
  virtual void exitBitwise(TsilParser::BitwiseContext *ctx) = 0;

  virtual void enterOperation_molecule(TsilParser::Operation_moleculeContext *ctx) = 0;
  virtual void exitOperation_molecule(TsilParser::Operation_moleculeContext *ctx) = 0;

  virtual void enterLogical(TsilParser::LogicalContext *ctx) = 0;
  virtual void exitLogical(TsilParser::LogicalContext *ctx) = 0;

  virtual void enterExpr_operation(TsilParser::Expr_operationContext *ctx) = 0;
  virtual void exitExpr_operation(TsilParser::Expr_operationContext *ctx) = 0;

  virtual void enterConstruct(TsilParser::ConstructContext *ctx) = 0;
  virtual void exitConstruct(TsilParser::ConstructContext *ctx) = 0;

  virtual void enterConstruct_args(TsilParser::Construct_argsContext *ctx) = 0;
  virtual void exitConstruct_args(TsilParser::Construct_argsContext *ctx) = 0;

  virtual void enterConstruct_arg(TsilParser::Construct_argContext *ctx) = 0;
  virtual void exitConstruct_arg(TsilParser::Construct_argContext *ctx) = 0;

  virtual void enterSimple_type(TsilParser::Simple_typeContext *ctx) = 0;
  virtual void exitSimple_type(TsilParser::Simple_typeContext *ctx) = 0;

  virtual void enterArray_type(TsilParser::Array_typeContext *ctx) = 0;
  virtual void exitArray_type(TsilParser::Array_typeContext *ctx) = 0;

  virtual void enterSimple_function_type(TsilParser::Simple_function_typeContext *ctx) = 0;
  virtual void exitSimple_function_type(TsilParser::Simple_function_typeContext *ctx) = 0;

  virtual void enterComplex_function_type(TsilParser::Complex_function_typeContext *ctx) = 0;
  virtual void exitComplex_function_type(TsilParser::Complex_function_typeContext *ctx) = 0;

  virtual void enterFull_type_basic_type(TsilParser::Full_type_basic_typeContext *ctx) = 0;
  virtual void exitFull_type_basic_type(TsilParser::Full_type_basic_typeContext *ctx) = 0;

  virtual void enterComplex_function_type_args(TsilParser::Complex_function_type_argsContext *ctx) = 0;
  virtual void exitComplex_function_type_args(TsilParser::Complex_function_type_argsContext *ctx) = 0;

  virtual void enterBitwise_op(TsilParser::Bitwise_opContext *ctx) = 0;
  virtual void exitBitwise_op(TsilParser::Bitwise_opContext *ctx) = 0;

  virtual void enterComparison_op(TsilParser::Comparison_opContext *ctx) = 0;
  virtual void exitComparison_op(TsilParser::Comparison_opContext *ctx) = 0;

  virtual void enterLogical_op(TsilParser::Logical_opContext *ctx) = 0;
  virtual void exitLogical_op(TsilParser::Logical_opContext *ctx) = 0;


};

