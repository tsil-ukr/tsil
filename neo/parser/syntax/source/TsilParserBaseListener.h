
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

  virtual void enterAtom_nested(TsilParser::Atom_nestedContext * /*ctx*/) override { }
  virtual void exitAtom_nested(TsilParser::Atom_nestedContext * /*ctx*/) override { }

  virtual void enterAtom_template_get(TsilParser::Atom_template_getContext * /*ctx*/) override { }
  virtual void exitAtom_template_get(TsilParser::Atom_template_getContext * /*ctx*/) override { }

  virtual void enterAtom_get(TsilParser::Atom_getContext * /*ctx*/) override { }
  virtual void exitAtom_get(TsilParser::Atom_getContext * /*ctx*/) override { }

  virtual void enterAtom_section_get(TsilParser::Atom_section_getContext * /*ctx*/) override { }
  virtual void exitAtom_section_get(TsilParser::Atom_section_getContext * /*ctx*/) override { }

  virtual void enterAtom_subject(TsilParser::Atom_subjectContext * /*ctx*/) override { }
  virtual void exitAtom_subject(TsilParser::Atom_subjectContext * /*ctx*/) override { }

  virtual void enterAtom_position_get(TsilParser::Atom_position_getContext * /*ctx*/) override { }
  virtual void exitAtom_position_get(TsilParser::Atom_position_getContext * /*ctx*/) override { }

  virtual void enterAtom_call(TsilParser::Atom_callContext * /*ctx*/) override { }
  virtual void exitAtom_call(TsilParser::Atom_callContext * /*ctx*/) override { }

  virtual void enterOperation_gte(TsilParser::Operation_gteContext * /*ctx*/) override { }
  virtual void exitOperation_gte(TsilParser::Operation_gteContext * /*ctx*/) override { }

  virtual void enterOperation_neq(TsilParser::Operation_neqContext * /*ctx*/) override { }
  virtual void exitOperation_neq(TsilParser::Operation_neqContext * /*ctx*/) override { }

  virtual void enterOperation_xor(TsilParser::Operation_xorContext * /*ctx*/) override { }
  virtual void exitOperation_xor(TsilParser::Operation_xorContext * /*ctx*/) override { }

  virtual void enterOperation_lte(TsilParser::Operation_lteContext * /*ctx*/) override { }
  virtual void exitOperation_lte(TsilParser::Operation_lteContext * /*ctx*/) override { }

  virtual void enterOperation_atom(TsilParser::Operation_atomContext * /*ctx*/) override { }
  virtual void exitOperation_atom(TsilParser::Operation_atomContext * /*ctx*/) override { }

  virtual void enterOperation_sub(TsilParser::Operation_subContext * /*ctx*/) override { }
  virtual void exitOperation_sub(TsilParser::Operation_subContext * /*ctx*/) override { }

  virtual void enterOperation_add(TsilParser::Operation_addContext * /*ctx*/) override { }
  virtual void exitOperation_add(TsilParser::Operation_addContext * /*ctx*/) override { }

  virtual void enterOperation_lt(TsilParser::Operation_ltContext * /*ctx*/) override { }
  virtual void exitOperation_lt(TsilParser::Operation_ltContext * /*ctx*/) override { }

  virtual void enterOperation_mod(TsilParser::Operation_modContext * /*ctx*/) override { }
  virtual void exitOperation_mod(TsilParser::Operation_modContext * /*ctx*/) override { }

  virtual void enterOperation_mul(TsilParser::Operation_mulContext * /*ctx*/) override { }
  virtual void exitOperation_mul(TsilParser::Operation_mulContext * /*ctx*/) override { }

  virtual void enterOperation_gt(TsilParser::Operation_gtContext * /*ctx*/) override { }
  virtual void exitOperation_gt(TsilParser::Operation_gtContext * /*ctx*/) override { }

  virtual void enterOperation_eq(TsilParser::Operation_eqContext * /*ctx*/) override { }
  virtual void exitOperation_eq(TsilParser::Operation_eqContext * /*ctx*/) override { }

  virtual void enterOperation_string(TsilParser::Operation_stringContext * /*ctx*/) override { }
  virtual void exitOperation_string(TsilParser::Operation_stringContext * /*ctx*/) override { }

  virtual void enterOperation_land(TsilParser::Operation_landContext * /*ctx*/) override { }
  virtual void exitOperation_land(TsilParser::Operation_landContext * /*ctx*/) override { }

  virtual void enterOperation_or(TsilParser::Operation_orContext * /*ctx*/) override { }
  virtual void exitOperation_or(TsilParser::Operation_orContext * /*ctx*/) override { }

  virtual void enterOperation_lor(TsilParser::Operation_lorContext * /*ctx*/) override { }
  virtual void exitOperation_lor(TsilParser::Operation_lorContext * /*ctx*/) override { }

  virtual void enterOperation_ternary(TsilParser::Operation_ternaryContext * /*ctx*/) override { }
  virtual void exitOperation_ternary(TsilParser::Operation_ternaryContext * /*ctx*/) override { }

  virtual void enterOperation_urshift(TsilParser::Operation_urshiftContext * /*ctx*/) override { }
  virtual void exitOperation_urshift(TsilParser::Operation_urshiftContext * /*ctx*/) override { }

  virtual void enterOperation_div(TsilParser::Operation_divContext * /*ctx*/) override { }
  virtual void exitOperation_div(TsilParser::Operation_divContext * /*ctx*/) override { }

  virtual void enterOperation_rshift(TsilParser::Operation_rshiftContext * /*ctx*/) override { }
  virtual void exitOperation_rshift(TsilParser::Operation_rshiftContext * /*ctx*/) override { }

  virtual void enterOperation_lshift(TsilParser::Operation_lshiftContext * /*ctx*/) override { }
  virtual void exitOperation_lshift(TsilParser::Operation_lshiftContext * /*ctx*/) override { }

  virtual void enterOperation_number(TsilParser::Operation_numberContext * /*ctx*/) override { }
  virtual void exitOperation_number(TsilParser::Operation_numberContext * /*ctx*/) override { }

  virtual void enterOperation_and(TsilParser::Operation_andContext * /*ctx*/) override { }
  virtual void exitOperation_and(TsilParser::Operation_andContext * /*ctx*/) override { }

  virtual void enterExpr_operation(TsilParser::Expr_operationContext * /*ctx*/) override { }
  virtual void exitExpr_operation(TsilParser::Expr_operationContext * /*ctx*/) override { }

  virtual void enterStructure_declare(TsilParser::Structure_declareContext * /*ctx*/) override { }
  virtual void exitStructure_declare(TsilParser::Structure_declareContext * /*ctx*/) override { }

  virtual void enterStructure_define(TsilParser::Structure_defineContext * /*ctx*/) override { }
  virtual void exitStructure_define(TsilParser::Structure_defineContext * /*ctx*/) override { }

  virtual void enterStructure_element(TsilParser::Structure_elementContext * /*ctx*/) override { }
  virtual void exitStructure_element(TsilParser::Structure_elementContext * /*ctx*/) override { }

  virtual void enterDiia_declare(TsilParser::Diia_declareContext * /*ctx*/) override { }
  virtual void exitDiia_declare(TsilParser::Diia_declareContext * /*ctx*/) override { }

  virtual void enterDiia_define(TsilParser::Diia_defineContext * /*ctx*/) override { }
  virtual void exitDiia_define(TsilParser::Diia_defineContext * /*ctx*/) override { }

  virtual void enterTsil_declare(TsilParser::Tsil_declareContext * /*ctx*/) override { }
  virtual void exitTsil_declare(TsilParser::Tsil_declareContext * /*ctx*/) override { }

  virtual void enterTsil_define(TsilParser::Tsil_defineContext * /*ctx*/) override { }
  virtual void exitTsil_define(TsilParser::Tsil_defineContext * /*ctx*/) override { }

  virtual void enterSynonym(TsilParser::SynonymContext * /*ctx*/) override { }
  virtual void exitSynonym(TsilParser::SynonymContext * /*ctx*/) override { }

  virtual void enterSection_declare(TsilParser::Section_declareContext * /*ctx*/) override { }
  virtual void exitSection_declare(TsilParser::Section_declareContext * /*ctx*/) override { }

  virtual void enterSection_define(TsilParser::Section_defineContext * /*ctx*/) override { }
  virtual void exitSection_define(TsilParser::Section_defineContext * /*ctx*/) override { }

  virtual void enterSet(TsilParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(TsilParser::SetContext * /*ctx*/) override { }

  virtual void enterSection_set(TsilParser::Section_setContext * /*ctx*/) override { }
  virtual void exitSection_set(TsilParser::Section_setContext * /*ctx*/) override { }

  virtual void enterPosition_set(TsilParser::Position_setContext * /*ctx*/) override { }
  virtual void exitPosition_set(TsilParser::Position_setContext * /*ctx*/) override { }

  virtual void enterIf(TsilParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(TsilParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(TsilParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(TsilParser::WhileContext * /*ctx*/) override { }

  virtual void enterBody(TsilParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(TsilParser::BodyContext * /*ctx*/) override { }

  virtual void enterBody_element(TsilParser::Body_elementContext * /*ctx*/) override { }
  virtual void exitBody_element(TsilParser::Body_elementContext * /*ctx*/) override { }

  virtual void enterType_get(TsilParser::Type_getContext * /*ctx*/) override { }
  virtual void exitType_get(TsilParser::Type_getContext * /*ctx*/) override { }

  virtual void enterType_nested(TsilParser::Type_nestedContext * /*ctx*/) override { }
  virtual void exitType_nested(TsilParser::Type_nestedContext * /*ctx*/) override { }

  virtual void enterType_subject(TsilParser::Type_subjectContext * /*ctx*/) override { }
  virtual void exitType_subject(TsilParser::Type_subjectContext * /*ctx*/) override { }

  virtual void enterType_array(TsilParser::Type_arrayContext * /*ctx*/) override { }
  virtual void exitType_array(TsilParser::Type_arrayContext * /*ctx*/) override { }

  virtual void enterType_fn_complex(TsilParser::Type_fn_complexContext * /*ctx*/) override { }
  virtual void exitType_fn_complex(TsilParser::Type_fn_complexContext * /*ctx*/) override { }

  virtual void enterType_template_get(TsilParser::Type_template_getContext * /*ctx*/) override { }
  virtual void exitType_template_get(TsilParser::Type_template_getContext * /*ctx*/) override { }

  virtual void enterType_fn_complex_named(TsilParser::Type_fn_complex_namedContext * /*ctx*/) override { }
  virtual void exitType_fn_complex_named(TsilParser::Type_fn_complex_namedContext * /*ctx*/) override { }

  virtual void enterType_fn_simple(TsilParser::Type_fn_simpleContext * /*ctx*/) override { }
  virtual void exitType_fn_simple(TsilParser::Type_fn_simpleContext * /*ctx*/) override { }

  virtual void enterType_section_get(TsilParser::Type_section_getContext * /*ctx*/) override { }
  virtual void exitType_section_get(TsilParser::Type_section_getContext * /*ctx*/) override { }

  virtual void enterParam(TsilParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(TsilParser::ParamContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

