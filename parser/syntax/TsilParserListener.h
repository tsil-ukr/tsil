
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

  virtual void enterDiia_declaration(TsilParser::Diia_declarationContext *ctx) = 0;
  virtual void exitDiia_declaration(TsilParser::Diia_declarationContext *ctx) = 0;

  virtual void enterIf(TsilParser::IfContext *ctx) = 0;
  virtual void exitIf(TsilParser::IfContext *ctx) = 0;

  virtual void enterWhile(TsilParser::WhileContext *ctx) = 0;
  virtual void exitWhile(TsilParser::WhileContext *ctx) = 0;

  virtual void enterDefine(TsilParser::DefineContext *ctx) = 0;
  virtual void exitDefine(TsilParser::DefineContext *ctx) = 0;

  virtual void enterAssign(TsilParser::AssignContext *ctx) = 0;
  virtual void exitAssign(TsilParser::AssignContext *ctx) = 0;

  virtual void enterSet(TsilParser::SetContext *ctx) = 0;
  virtual void exitSet(TsilParser::SetContext *ctx) = 0;

  virtual void enterCall(TsilParser::CallContext *ctx) = 0;
  virtual void exitCall(TsilParser::CallContext *ctx) = 0;

  virtual void enterNegative(TsilParser::NegativeContext *ctx) = 0;
  virtual void exitNegative(TsilParser::NegativeContext *ctx) = 0;

  virtual void enterNot(TsilParser::NotContext *ctx) = 0;
  virtual void exitNot(TsilParser::NotContext *ctx) = 0;

  virtual void enterAtom_number(TsilParser::Atom_numberContext *ctx) = 0;
  virtual void exitAtom_number(TsilParser::Atom_numberContext *ctx) = 0;

  virtual void enterBitwise_not(TsilParser::Bitwise_notContext *ctx) = 0;
  virtual void exitBitwise_not(TsilParser::Bitwise_notContext *ctx) = 0;

  virtual void enterGet(TsilParser::GetContext *ctx) = 0;
  virtual void exitGet(TsilParser::GetContext *ctx) = 0;

  virtual void enterAtom_identifier(TsilParser::Atom_identifierContext *ctx) = 0;
  virtual void exitAtom_identifier(TsilParser::Atom_identifierContext *ctx) = 0;

  virtual void enterPositive(TsilParser::PositiveContext *ctx) = 0;
  virtual void exitPositive(TsilParser::PositiveContext *ctx) = 0;

  virtual void enterNested(TsilParser::NestedContext *ctx) = 0;
  virtual void exitNested(TsilParser::NestedContext *ctx) = 0;

  virtual void enterAtom_string(TsilParser::Atom_stringContext *ctx) = 0;
  virtual void exitAtom_string(TsilParser::Atom_stringContext *ctx) = 0;

  virtual void enterArithmetic_mul(TsilParser::Arithmetic_mulContext *ctx) = 0;
  virtual void exitArithmetic_mul(TsilParser::Arithmetic_mulContext *ctx) = 0;

  virtual void enterArithmetic_add(TsilParser::Arithmetic_addContext *ctx) = 0;
  virtual void exitArithmetic_add(TsilParser::Arithmetic_addContext *ctx) = 0;

  virtual void enterComparison(TsilParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(TsilParser::ComparisonContext *ctx) = 0;

  virtual void enterBitwise(TsilParser::BitwiseContext *ctx) = 0;
  virtual void exitBitwise(TsilParser::BitwiseContext *ctx) = 0;

  virtual void enterValue_atom(TsilParser::Value_atomContext *ctx) = 0;
  virtual void exitValue_atom(TsilParser::Value_atomContext *ctx) = 0;

  virtual void enterLogical(TsilParser::LogicalContext *ctx) = 0;
  virtual void exitLogical(TsilParser::LogicalContext *ctx) = 0;

  virtual void enterIdentifiers_chain(TsilParser::Identifiers_chainContext *ctx) = 0;
  virtual void exitIdentifiers_chain(TsilParser::Identifiers_chainContext *ctx) = 0;

  virtual void enterType(TsilParser::TypeContext *ctx) = 0;
  virtual void exitType(TsilParser::TypeContext *ctx) = 0;

  virtual void enterArgs(TsilParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(TsilParser::ArgsContext *ctx) = 0;

  virtual void enterParams(TsilParser::ParamsContext *ctx) = 0;
  virtual void exitParams(TsilParser::ParamsContext *ctx) = 0;

  virtual void enterParam(TsilParser::ParamContext *ctx) = 0;
  virtual void exitParam(TsilParser::ParamContext *ctx) = 0;

  virtual void enterBody(TsilParser::BodyContext *ctx) = 0;
  virtual void exitBody(TsilParser::BodyContext *ctx) = 0;

  virtual void enterBody_element_or_return(TsilParser::Body_element_or_returnContext *ctx) = 0;
  virtual void exitBody_element_or_return(TsilParser::Body_element_or_returnContext *ctx) = 0;

  virtual void enterBody_element(TsilParser::Body_elementContext *ctx) = 0;
  virtual void exitBody_element(TsilParser::Body_elementContext *ctx) = 0;

  virtual void enterReturn_body_element(TsilParser::Return_body_elementContext *ctx) = 0;
  virtual void exitReturn_body_element(TsilParser::Return_body_elementContext *ctx) = 0;

  virtual void enterBitwise_op(TsilParser::Bitwise_opContext *ctx) = 0;
  virtual void exitBitwise_op(TsilParser::Bitwise_opContext *ctx) = 0;

  virtual void enterComparison_op(TsilParser::Comparison_opContext *ctx) = 0;
  virtual void exitComparison_op(TsilParser::Comparison_opContext *ctx) = 0;

  virtual void enterLogical_op(TsilParser::Logical_opContext *ctx) = 0;
  virtual void exitLogical_op(TsilParser::Logical_opContext *ctx) = 0;

  virtual void enterNumber(TsilParser::NumberContext *ctx) = 0;
  virtual void exitNumber(TsilParser::NumberContext *ctx) = 0;

  virtual void enterString(TsilParser::StringContext *ctx) = 0;
  virtual void exitString(TsilParser::StringContext *ctx) = 0;

  virtual void enterIdentifier(TsilParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(TsilParser::IdentifierContext *ctx) = 0;


};

