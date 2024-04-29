
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "TsilParserListener.h"


/**
 * This class provides an empty implementation of TsilParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TsilParserBaseListener : public TsilParserListener {
public:

  virtual void enterFile(TsilParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(TsilParser::FileContext * /*ctx*/) override { }

  virtual void enterProgram(TsilParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(TsilParser::ProgramContext * /*ctx*/) override { }

  virtual void enterProgram_element(TsilParser::Program_elementContext * /*ctx*/) override { }
  virtual void exitProgram_element(TsilParser::Program_elementContext * /*ctx*/) override { }

  virtual void enterIdentifier(TsilParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(TsilParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterReal_section_access(TsilParser::Real_section_accessContext * /*ctx*/) override { }
  virtual void exitReal_section_access(TsilParser::Real_section_accessContext * /*ctx*/) override { }

  virtual void enterTake(TsilParser::TakeContext * /*ctx*/) override { }
  virtual void exitTake(TsilParser::TakeContext * /*ctx*/) override { }

  virtual void enterTake_parts(TsilParser::Take_partsContext * /*ctx*/) override { }
  virtual void exitTake_parts(TsilParser::Take_partsContext * /*ctx*/) override { }

  virtual void enterSection(TsilParser::SectionContext * /*ctx*/) override { }
  virtual void exitSection(TsilParser::SectionContext * /*ctx*/) override { }

  virtual void enterSection_element(TsilParser::Section_elementContext * /*ctx*/) override { }
  virtual void exitSection_element(TsilParser::Section_elementContext * /*ctx*/) override { }

  virtual void enterStructure(TsilParser::StructureContext * /*ctx*/) override { }
  virtual void exitStructure(TsilParser::StructureContext * /*ctx*/) override { }

  virtual void enterStructure_generics(TsilParser::Structure_genericsContext * /*ctx*/) override { }
  virtual void exitStructure_generics(TsilParser::Structure_genericsContext * /*ctx*/) override { }

  virtual void enterStructure_generic(TsilParser::Structure_genericContext * /*ctx*/) override { }
  virtual void exitStructure_generic(TsilParser::Structure_genericContext * /*ctx*/) override { }

  virtual void enterStructure_params(TsilParser::Structure_paramsContext * /*ctx*/) override { }
  virtual void exitStructure_params(TsilParser::Structure_paramsContext * /*ctx*/) override { }

  virtual void enterStructure_param(TsilParser::Structure_paramContext * /*ctx*/) override { }
  virtual void exitStructure_param(TsilParser::Structure_paramContext * /*ctx*/) override { }

  virtual void enterDiia_head(TsilParser::Diia_headContext * /*ctx*/) override { }
  virtual void exitDiia_head(TsilParser::Diia_headContext * /*ctx*/) override { }

  virtual void enterDiia(TsilParser::DiiaContext * /*ctx*/) override { }
  virtual void exitDiia(TsilParser::DiiaContext * /*ctx*/) override { }

  virtual void enterDiia_generics(TsilParser::Diia_genericsContext * /*ctx*/) override { }
  virtual void exitDiia_generics(TsilParser::Diia_genericsContext * /*ctx*/) override { }

  virtual void enterDiia_generic(TsilParser::Diia_genericContext * /*ctx*/) override { }
  virtual void exitDiia_generic(TsilParser::Diia_genericContext * /*ctx*/) override { }

  virtual void enterDiia_declaration(TsilParser::Diia_declarationContext * /*ctx*/) override { }
  virtual void exitDiia_declaration(TsilParser::Diia_declarationContext * /*ctx*/) override { }

  virtual void enterParams(TsilParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(TsilParser::ParamsContext * /*ctx*/) override { }

  virtual void enterParam(TsilParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(TsilParser::ParamContext * /*ctx*/) override { }

  virtual void enterBody(TsilParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(TsilParser::BodyContext * /*ctx*/) override { }

  virtual void enterBody_element(TsilParser::Body_elementContext * /*ctx*/) override { }
  virtual void exitBody_element(TsilParser::Body_elementContext * /*ctx*/) override { }

  virtual void enterReturn_body_element(TsilParser::Return_body_elementContext * /*ctx*/) override { }
  virtual void exitReturn_body_element(TsilParser::Return_body_elementContext * /*ctx*/) override { }

  virtual void enterBlock(TsilParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(TsilParser::BlockContext * /*ctx*/) override { }

  virtual void enterIf(TsilParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(TsilParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(TsilParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(TsilParser::WhileContext * /*ctx*/) override { }

  virtual void enterDeclare(TsilParser::DeclareContext * /*ctx*/) override { }
  virtual void exitDeclare(TsilParser::DeclareContext * /*ctx*/) override { }

  virtual void enterDefine(TsilParser::DefineContext * /*ctx*/) override { }
  virtual void exitDefine(TsilParser::DefineContext * /*ctx*/) override { }

  virtual void enterAssign(TsilParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(TsilParser::AssignContext * /*ctx*/) override { }

  virtual void enterSet(TsilParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(TsilParser::SetContext * /*ctx*/) override { }

  virtual void enterCall(TsilParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(TsilParser::CallContext * /*ctx*/) override { }

  virtual void enterAccess(TsilParser::AccessContext * /*ctx*/) override { }
  virtual void exitAccess(TsilParser::AccessContext * /*ctx*/) override { }

  virtual void enterGet(TsilParser::GetContext * /*ctx*/) override { }
  virtual void exitGet(TsilParser::GetContext * /*ctx*/) override { }

  virtual void enterParticle_section_access(TsilParser::Particle_section_accessContext * /*ctx*/) override { }
  virtual void exitParticle_section_access(TsilParser::Particle_section_accessContext * /*ctx*/) override { }

  virtual void enterNested(TsilParser::NestedContext * /*ctx*/) override { }
  virtual void exitNested(TsilParser::NestedContext * /*ctx*/) override { }

  virtual void enterGeneric(TsilParser::GenericContext * /*ctx*/) override { }
  virtual void exitGeneric(TsilParser::GenericContext * /*ctx*/) override { }

  virtual void enterArgs(TsilParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(TsilParser::ArgsContext * /*ctx*/) override { }

  virtual void enterAtom_particle(TsilParser::Atom_particleContext * /*ctx*/) override { }
  virtual void exitAtom_particle(TsilParser::Atom_particleContext * /*ctx*/) override { }

  virtual void enterNumber(TsilParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(TsilParser::NumberContext * /*ctx*/) override { }

  virtual void enterString(TsilParser::StringContext * /*ctx*/) override { }
  virtual void exitString(TsilParser::StringContext * /*ctx*/) override { }

  virtual void enterMolecule_atom(TsilParser::Molecule_atomContext * /*ctx*/) override { }
  virtual void exitMolecule_atom(TsilParser::Molecule_atomContext * /*ctx*/) override { }

  virtual void enterNot(TsilParser::NotContext * /*ctx*/) override { }
  virtual void exitNot(TsilParser::NotContext * /*ctx*/) override { }

  virtual void enterPositive(TsilParser::PositiveContext * /*ctx*/) override { }
  virtual void exitPositive(TsilParser::PositiveContext * /*ctx*/) override { }

  virtual void enterNegative(TsilParser::NegativeContext * /*ctx*/) override { }
  virtual void exitNegative(TsilParser::NegativeContext * /*ctx*/) override { }

  virtual void enterBitwise_not(TsilParser::Bitwise_notContext * /*ctx*/) override { }
  virtual void exitBitwise_not(TsilParser::Bitwise_notContext * /*ctx*/) override { }

  virtual void enterAdd(TsilParser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(TsilParser::AddContext * /*ctx*/) override { }

  virtual void enterAs(TsilParser::AsContext * /*ctx*/) override { }
  virtual void exitAs(TsilParser::AsContext * /*ctx*/) override { }

  virtual void enterComparison(TsilParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(TsilParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterMul(TsilParser::MulContext * /*ctx*/) override { }
  virtual void exitMul(TsilParser::MulContext * /*ctx*/) override { }

  virtual void enterBitwise(TsilParser::BitwiseContext * /*ctx*/) override { }
  virtual void exitBitwise(TsilParser::BitwiseContext * /*ctx*/) override { }

  virtual void enterOperation_molecule(TsilParser::Operation_moleculeContext * /*ctx*/) override { }
  virtual void exitOperation_molecule(TsilParser::Operation_moleculeContext * /*ctx*/) override { }

  virtual void enterLogical(TsilParser::LogicalContext * /*ctx*/) override { }
  virtual void exitLogical(TsilParser::LogicalContext * /*ctx*/) override { }

  virtual void enterConstruct(TsilParser::ConstructContext * /*ctx*/) override { }
  virtual void exitConstruct(TsilParser::ConstructContext * /*ctx*/) override { }

  virtual void enterExpr_operation(TsilParser::Expr_operationContext * /*ctx*/) override { }
  virtual void exitExpr_operation(TsilParser::Expr_operationContext * /*ctx*/) override { }

  virtual void enterConstruct_args(TsilParser::Construct_argsContext * /*ctx*/) override { }
  virtual void exitConstruct_args(TsilParser::Construct_argsContext * /*ctx*/) override { }

  virtual void enterConstruct_arg(TsilParser::Construct_argContext * /*ctx*/) override { }
  virtual void exitConstruct_arg(TsilParser::Construct_argContext * /*ctx*/) override { }

  virtual void enterSimple_type(TsilParser::Simple_typeContext * /*ctx*/) override { }
  virtual void exitSimple_type(TsilParser::Simple_typeContext * /*ctx*/) override { }

  virtual void enterArray_type(TsilParser::Array_typeContext * /*ctx*/) override { }
  virtual void exitArray_type(TsilParser::Array_typeContext * /*ctx*/) override { }

  virtual void enterSimple_function_type(TsilParser::Simple_function_typeContext * /*ctx*/) override { }
  virtual void exitSimple_function_type(TsilParser::Simple_function_typeContext * /*ctx*/) override { }

  virtual void enterComplex_function_type(TsilParser::Complex_function_typeContext * /*ctx*/) override { }
  virtual void exitComplex_function_type(TsilParser::Complex_function_typeContext * /*ctx*/) override { }

  virtual void enterFull_type_basic_type(TsilParser::Full_type_basic_typeContext * /*ctx*/) override { }
  virtual void exitFull_type_basic_type(TsilParser::Full_type_basic_typeContext * /*ctx*/) override { }

  virtual void enterComplex_function_type_args(TsilParser::Complex_function_type_argsContext * /*ctx*/) override { }
  virtual void exitComplex_function_type_args(TsilParser::Complex_function_type_argsContext * /*ctx*/) override { }

  virtual void enterBitwise_op(TsilParser::Bitwise_opContext * /*ctx*/) override { }
  virtual void exitBitwise_op(TsilParser::Bitwise_opContext * /*ctx*/) override { }

  virtual void enterComparison_op(TsilParser::Comparison_opContext * /*ctx*/) override { }
  virtual void exitComparison_op(TsilParser::Comparison_opContext * /*ctx*/) override { }

  virtual void enterLogical_op(TsilParser::Logical_opContext * /*ctx*/) override { }
  virtual void exitLogical_op(TsilParser::Logical_opContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

