
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

  virtual void enterConstructor(TsilParser::ConstructorContext * /*ctx*/) override { }
  virtual void exitConstructor(TsilParser::ConstructorContext * /*ctx*/) override { }

  virtual void enterConstructor_args(TsilParser::Constructor_argsContext * /*ctx*/) override { }
  virtual void exitConstructor_args(TsilParser::Constructor_argsContext * /*ctx*/) override { }

  virtual void enterConstructor_arg(TsilParser::Constructor_argContext * /*ctx*/) override { }
  virtual void exitConstructor_arg(TsilParser::Constructor_argContext * /*ctx*/) override { }

  virtual void enterDiia_head(TsilParser::Diia_headContext * /*ctx*/) override { }
  virtual void exitDiia_head(TsilParser::Diia_headContext * /*ctx*/) override { }

  virtual void enterDiia(TsilParser::DiiaContext * /*ctx*/) override { }
  virtual void exitDiia(TsilParser::DiiaContext * /*ctx*/) override { }

  virtual void enterDiia_declaration(TsilParser::Diia_declarationContext * /*ctx*/) override { }
  virtual void exitDiia_declaration(TsilParser::Diia_declarationContext * /*ctx*/) override { }

  virtual void enterIf(TsilParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(TsilParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(TsilParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(TsilParser::WhileContext * /*ctx*/) override { }

  virtual void enterDefine(TsilParser::DefineContext * /*ctx*/) override { }
  virtual void exitDefine(TsilParser::DefineContext * /*ctx*/) override { }

  virtual void enterAssign(TsilParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(TsilParser::AssignContext * /*ctx*/) override { }

  virtual void enterSet(TsilParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(TsilParser::SetContext * /*ctx*/) override { }

  virtual void enterSizeof(TsilParser::SizeofContext * /*ctx*/) override { }
  virtual void exitSizeof(TsilParser::SizeofContext * /*ctx*/) override { }

  virtual void enterCall(TsilParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(TsilParser::CallContext * /*ctx*/) override { }

  virtual void enterNegative(TsilParser::NegativeContext * /*ctx*/) override { }
  virtual void exitNegative(TsilParser::NegativeContext * /*ctx*/) override { }

  virtual void enterNot(TsilParser::NotContext * /*ctx*/) override { }
  virtual void exitNot(TsilParser::NotContext * /*ctx*/) override { }

  virtual void enterBitwise_not(TsilParser::Bitwise_notContext * /*ctx*/) override { }
  virtual void exitBitwise_not(TsilParser::Bitwise_notContext * /*ctx*/) override { }

  virtual void enterGet(TsilParser::GetContext * /*ctx*/) override { }
  virtual void exitGet(TsilParser::GetContext * /*ctx*/) override { }

  virtual void enterAtom_identifier(TsilParser::Atom_identifierContext * /*ctx*/) override { }
  virtual void exitAtom_identifier(TsilParser::Atom_identifierContext * /*ctx*/) override { }

  virtual void enterPositive(TsilParser::PositiveContext * /*ctx*/) override { }
  virtual void exitPositive(TsilParser::PositiveContext * /*ctx*/) override { }

  virtual void enterNested(TsilParser::NestedContext * /*ctx*/) override { }
  virtual void exitNested(TsilParser::NestedContext * /*ctx*/) override { }

  virtual void enterValue_atom(TsilParser::Value_atomContext * /*ctx*/) override { }
  virtual void exitValue_atom(TsilParser::Value_atomContext * /*ctx*/) override { }

  virtual void enterAtom_number(TsilParser::Atom_numberContext * /*ctx*/) override { }
  virtual void exitAtom_number(TsilParser::Atom_numberContext * /*ctx*/) override { }

  virtual void enterAtom_string(TsilParser::Atom_stringContext * /*ctx*/) override { }
  virtual void exitAtom_string(TsilParser::Atom_stringContext * /*ctx*/) override { }

  virtual void enterArithmetic_mul(TsilParser::Arithmetic_mulContext * /*ctx*/) override { }
  virtual void exitArithmetic_mul(TsilParser::Arithmetic_mulContext * /*ctx*/) override { }

  virtual void enterAs(TsilParser::AsContext * /*ctx*/) override { }
  virtual void exitAs(TsilParser::AsContext * /*ctx*/) override { }

  virtual void enterArithmetic_add(TsilParser::Arithmetic_addContext * /*ctx*/) override { }
  virtual void exitArithmetic_add(TsilParser::Arithmetic_addContext * /*ctx*/) override { }

  virtual void enterComparison(TsilParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(TsilParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterAtom_constructor(TsilParser::Atom_constructorContext * /*ctx*/) override { }
  virtual void exitAtom_constructor(TsilParser::Atom_constructorContext * /*ctx*/) override { }

  virtual void enterBitwise(TsilParser::BitwiseContext * /*ctx*/) override { }
  virtual void exitBitwise(TsilParser::BitwiseContext * /*ctx*/) override { }

  virtual void enterExpr_molecule(TsilParser::Expr_moleculeContext * /*ctx*/) override { }
  virtual void exitExpr_molecule(TsilParser::Expr_moleculeContext * /*ctx*/) override { }

  virtual void enterLogical(TsilParser::LogicalContext * /*ctx*/) override { }
  virtual void exitLogical(TsilParser::LogicalContext * /*ctx*/) override { }

  virtual void enterAtom_sizeof(TsilParser::Atom_sizeofContext * /*ctx*/) override { }
  virtual void exitAtom_sizeof(TsilParser::Atom_sizeofContext * /*ctx*/) override { }

  virtual void enterIdentifiers_chain(TsilParser::Identifiers_chainContext * /*ctx*/) override { }
  virtual void exitIdentifiers_chain(TsilParser::Identifiers_chainContext * /*ctx*/) override { }

  virtual void enterType(TsilParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(TsilParser::TypeContext * /*ctx*/) override { }

  virtual void enterArgs(TsilParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(TsilParser::ArgsContext * /*ctx*/) override { }

  virtual void enterParams(TsilParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(TsilParser::ParamsContext * /*ctx*/) override { }

  virtual void enterParam(TsilParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(TsilParser::ParamContext * /*ctx*/) override { }

  virtual void enterBody(TsilParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(TsilParser::BodyContext * /*ctx*/) override { }

  virtual void enterBody_element_or_return(TsilParser::Body_element_or_returnContext * /*ctx*/) override { }
  virtual void exitBody_element_or_return(TsilParser::Body_element_or_returnContext * /*ctx*/) override { }

  virtual void enterBody_element(TsilParser::Body_elementContext * /*ctx*/) override { }
  virtual void exitBody_element(TsilParser::Body_elementContext * /*ctx*/) override { }

  virtual void enterReturn_body_element(TsilParser::Return_body_elementContext * /*ctx*/) override { }
  virtual void exitReturn_body_element(TsilParser::Return_body_elementContext * /*ctx*/) override { }

  virtual void enterBitwise_op(TsilParser::Bitwise_opContext * /*ctx*/) override { }
  virtual void exitBitwise_op(TsilParser::Bitwise_opContext * /*ctx*/) override { }

  virtual void enterComparison_op(TsilParser::Comparison_opContext * /*ctx*/) override { }
  virtual void exitComparison_op(TsilParser::Comparison_opContext * /*ctx*/) override { }

  virtual void enterLogical_op(TsilParser::Logical_opContext * /*ctx*/) override { }
  virtual void exitLogical_op(TsilParser::Logical_opContext * /*ctx*/) override { }

  virtual void enterNumber(TsilParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(TsilParser::NumberContext * /*ctx*/) override { }

  virtual void enterString(TsilParser::StringContext * /*ctx*/) override { }
  virtual void exitString(TsilParser::StringContext * /*ctx*/) override { }

  virtual void enterIdentifier(TsilParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(TsilParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

