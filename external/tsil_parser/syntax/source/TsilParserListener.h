
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

  virtual void enterAtom_nested(TsilParser::Atom_nestedContext *ctx) = 0;
  virtual void exitAtom_nested(TsilParser::Atom_nestedContext *ctx) = 0;

  virtual void enterAtom_template_get(TsilParser::Atom_template_getContext *ctx) = 0;
  virtual void exitAtom_template_get(TsilParser::Atom_template_getContext *ctx) = 0;

  virtual void enterAtom_get(TsilParser::Atom_getContext *ctx) = 0;
  virtual void exitAtom_get(TsilParser::Atom_getContext *ctx) = 0;

  virtual void enterAtom_section_get(TsilParser::Atom_section_getContext *ctx) = 0;
  virtual void exitAtom_section_get(TsilParser::Atom_section_getContext *ctx) = 0;

  virtual void enterAtom_subject(TsilParser::Atom_subjectContext *ctx) = 0;
  virtual void exitAtom_subject(TsilParser::Atom_subjectContext *ctx) = 0;

  virtual void enterAtom_position_get(TsilParser::Atom_position_getContext *ctx) = 0;
  virtual void exitAtom_position_get(TsilParser::Atom_position_getContext *ctx) = 0;

  virtual void enterAtom_call(TsilParser::Atom_callContext *ctx) = 0;
  virtual void exitAtom_call(TsilParser::Atom_callContext *ctx) = 0;

  virtual void enterCall_arg(TsilParser::Call_argContext *ctx) = 0;
  virtual void exitCall_arg(TsilParser::Call_argContext *ctx) = 0;

  virtual void enterOperation_gte(TsilParser::Operation_gteContext *ctx) = 0;
  virtual void exitOperation_gte(TsilParser::Operation_gteContext *ctx) = 0;

  virtual void enterOperation_neq(TsilParser::Operation_neqContext *ctx) = 0;
  virtual void exitOperation_neq(TsilParser::Operation_neqContext *ctx) = 0;

  virtual void enterOperation_xor(TsilParser::Operation_xorContext *ctx) = 0;
  virtual void exitOperation_xor(TsilParser::Operation_xorContext *ctx) = 0;

  virtual void enterOperation_lte(TsilParser::Operation_lteContext *ctx) = 0;
  virtual void exitOperation_lte(TsilParser::Operation_lteContext *ctx) = 0;

  virtual void enterOperation_pre_plus(TsilParser::Operation_pre_plusContext *ctx) = 0;
  virtual void exitOperation_pre_plus(TsilParser::Operation_pre_plusContext *ctx) = 0;

  virtual void enterOperation_add(TsilParser::Operation_addContext *ctx) = 0;
  virtual void exitOperation_add(TsilParser::Operation_addContext *ctx) = 0;

  virtual void enterOperation_lt(TsilParser::Operation_ltContext *ctx) = 0;
  virtual void exitOperation_lt(TsilParser::Operation_ltContext *ctx) = 0;

  virtual void enterOperation_pre_minus(TsilParser::Operation_pre_minusContext *ctx) = 0;
  virtual void exitOperation_pre_minus(TsilParser::Operation_pre_minusContext *ctx) = 0;

  virtual void enterOperation_land(TsilParser::Operation_landContext *ctx) = 0;
  virtual void exitOperation_land(TsilParser::Operation_landContext *ctx) = 0;

  virtual void enterOperation_or(TsilParser::Operation_orContext *ctx) = 0;
  virtual void exitOperation_or(TsilParser::Operation_orContext *ctx) = 0;

  virtual void enterOperation_pre_not(TsilParser::Operation_pre_notContext *ctx) = 0;
  virtual void exitOperation_pre_not(TsilParser::Operation_pre_notContext *ctx) = 0;

  virtual void enterOperation_as(TsilParser::Operation_asContext *ctx) = 0;
  virtual void exitOperation_as(TsilParser::Operation_asContext *ctx) = 0;

  virtual void enterOperation_atom(TsilParser::Operation_atomContext *ctx) = 0;
  virtual void exitOperation_atom(TsilParser::Operation_atomContext *ctx) = 0;

  virtual void enterOperation_sub(TsilParser::Operation_subContext *ctx) = 0;
  virtual void exitOperation_sub(TsilParser::Operation_subContext *ctx) = 0;

  virtual void enterOperation_mod(TsilParser::Operation_modContext *ctx) = 0;
  virtual void exitOperation_mod(TsilParser::Operation_modContext *ctx) = 0;

  virtual void enterOperation_mul(TsilParser::Operation_mulContext *ctx) = 0;
  virtual void exitOperation_mul(TsilParser::Operation_mulContext *ctx) = 0;

  virtual void enterOperation_gt(TsilParser::Operation_gtContext *ctx) = 0;
  virtual void exitOperation_gt(TsilParser::Operation_gtContext *ctx) = 0;

  virtual void enterOperation_eq(TsilParser::Operation_eqContext *ctx) = 0;
  virtual void exitOperation_eq(TsilParser::Operation_eqContext *ctx) = 0;

  virtual void enterOperation_string(TsilParser::Operation_stringContext *ctx) = 0;
  virtual void exitOperation_string(TsilParser::Operation_stringContext *ctx) = 0;

  virtual void enterOperation_pre_bw_not(TsilParser::Operation_pre_bw_notContext *ctx) = 0;
  virtual void exitOperation_pre_bw_not(TsilParser::Operation_pre_bw_notContext *ctx) = 0;

  virtual void enterOperation_lor(TsilParser::Operation_lorContext *ctx) = 0;
  virtual void exitOperation_lor(TsilParser::Operation_lorContext *ctx) = 0;

  virtual void enterOperation_ternary(TsilParser::Operation_ternaryContext *ctx) = 0;
  virtual void exitOperation_ternary(TsilParser::Operation_ternaryContext *ctx) = 0;

  virtual void enterOperation_urshift(TsilParser::Operation_urshiftContext *ctx) = 0;
  virtual void exitOperation_urshift(TsilParser::Operation_urshiftContext *ctx) = 0;

  virtual void enterOperation_div(TsilParser::Operation_divContext *ctx) = 0;
  virtual void exitOperation_div(TsilParser::Operation_divContext *ctx) = 0;

  virtual void enterOperation_rshift(TsilParser::Operation_rshiftContext *ctx) = 0;
  virtual void exitOperation_rshift(TsilParser::Operation_rshiftContext *ctx) = 0;

  virtual void enterOperation_lshift(TsilParser::Operation_lshiftContext *ctx) = 0;
  virtual void exitOperation_lshift(TsilParser::Operation_lshiftContext *ctx) = 0;

  virtual void enterOperation_number(TsilParser::Operation_numberContext *ctx) = 0;
  virtual void exitOperation_number(TsilParser::Operation_numberContext *ctx) = 0;

  virtual void enterOperation_and(TsilParser::Operation_andContext *ctx) = 0;
  virtual void exitOperation_and(TsilParser::Operation_andContext *ctx) = 0;

  virtual void enterOp_lshift(TsilParser::Op_lshiftContext *ctx) = 0;
  virtual void exitOp_lshift(TsilParser::Op_lshiftContext *ctx) = 0;

  virtual void enterOp_rshift(TsilParser::Op_rshiftContext *ctx) = 0;
  virtual void exitOp_rshift(TsilParser::Op_rshiftContext *ctx) = 0;

  virtual void enterOp_urshift(TsilParser::Op_urshiftContext *ctx) = 0;
  virtual void exitOp_urshift(TsilParser::Op_urshiftContext *ctx) = 0;

  virtual void enterOp_lte(TsilParser::Op_lteContext *ctx) = 0;
  virtual void exitOp_lte(TsilParser::Op_lteContext *ctx) = 0;

  virtual void enterOp_gte(TsilParser::Op_gteContext *ctx) = 0;
  virtual void exitOp_gte(TsilParser::Op_gteContext *ctx) = 0;

  virtual void enterOp_eq(TsilParser::Op_eqContext *ctx) = 0;
  virtual void exitOp_eq(TsilParser::Op_eqContext *ctx) = 0;

  virtual void enterOp_neq(TsilParser::Op_neqContext *ctx) = 0;
  virtual void exitOp_neq(TsilParser::Op_neqContext *ctx) = 0;

  virtual void enterOp_land(TsilParser::Op_landContext *ctx) = 0;
  virtual void exitOp_land(TsilParser::Op_landContext *ctx) = 0;

  virtual void enterOp_lor(TsilParser::Op_lorContext *ctx) = 0;
  virtual void exitOp_lor(TsilParser::Op_lorContext *ctx) = 0;

  virtual void enterGendef(TsilParser::GendefContext *ctx) = 0;
  virtual void exitGendef(TsilParser::GendefContext *ctx) = 0;

  virtual void enterExpr_operation(TsilParser::Expr_operationContext *ctx) = 0;
  virtual void exitExpr_operation(TsilParser::Expr_operationContext *ctx) = 0;

  virtual void enterExpr_object(TsilParser::Expr_objectContext *ctx) = 0;
  virtual void exitExpr_object(TsilParser::Expr_objectContext *ctx) = 0;

  virtual void enterObject_arg(TsilParser::Object_argContext *ctx) = 0;
  virtual void exitObject_arg(TsilParser::Object_argContext *ctx) = 0;

  virtual void enterTypeless_object(TsilParser::Typeless_objectContext *ctx) = 0;
  virtual void exitTypeless_object(TsilParser::Typeless_objectContext *ctx) = 0;

  virtual void enterStructure_define(TsilParser::Structure_defineContext *ctx) = 0;
  virtual void exitStructure_define(TsilParser::Structure_defineContext *ctx) = 0;

  virtual void enterStructure_element(TsilParser::Structure_elementContext *ctx) = 0;
  virtual void exitStructure_element(TsilParser::Structure_elementContext *ctx) = 0;

  virtual void enterDiia_define(TsilParser::Diia_defineContext *ctx) = 0;
  virtual void exitDiia_define(TsilParser::Diia_defineContext *ctx) = 0;

  virtual void enterTsil_define(TsilParser::Tsil_defineContext *ctx) = 0;
  virtual void exitTsil_define(TsilParser::Tsil_defineContext *ctx) = 0;

  virtual void enterAssign(TsilParser::AssignContext *ctx) = 0;
  virtual void exitAssign(TsilParser::AssignContext *ctx) = 0;

  virtual void enterSynonym(TsilParser::SynonymContext *ctx) = 0;
  virtual void exitSynonym(TsilParser::SynonymContext *ctx) = 0;

  virtual void enterSynonym_fn(TsilParser::Synonym_fnContext *ctx) = 0;
  virtual void exitSynonym_fn(TsilParser::Synonym_fnContext *ctx) = 0;

  virtual void enterSection_define(TsilParser::Section_defineContext *ctx) = 0;
  virtual void exitSection_define(TsilParser::Section_defineContext *ctx) = 0;

  virtual void enterSet(TsilParser::SetContext *ctx) = 0;
  virtual void exitSet(TsilParser::SetContext *ctx) = 0;

  virtual void enterPosition_set(TsilParser::Position_setContext *ctx) = 0;
  virtual void exitPosition_set(TsilParser::Position_setContext *ctx) = 0;

  virtual void enterSection_set(TsilParser::Section_setContext *ctx) = 0;
  virtual void exitSection_set(TsilParser::Section_setContext *ctx) = 0;

  virtual void enterIf(TsilParser::IfContext *ctx) = 0;
  virtual void exitIf(TsilParser::IfContext *ctx) = 0;

  virtual void enterWhile(TsilParser::WhileContext *ctx) = 0;
  virtual void exitWhile(TsilParser::WhileContext *ctx) = 0;

  virtual void enterExec(TsilParser::ExecContext *ctx) = 0;
  virtual void exitExec(TsilParser::ExecContext *ctx) = 0;

  virtual void enterBody(TsilParser::BodyContext *ctx) = 0;
  virtual void exitBody(TsilParser::BodyContext *ctx) = 0;

  virtual void enterBody_element(TsilParser::Body_elementContext *ctx) = 0;
  virtual void exitBody_element(TsilParser::Body_elementContext *ctx) = 0;

  virtual void enterReturn(TsilParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(TsilParser::ReturnContext *ctx) = 0;

  virtual void enterSimple_type_section_get(TsilParser::Simple_type_section_getContext *ctx) = 0;
  virtual void exitSimple_type_section_get(TsilParser::Simple_type_section_getContext *ctx) = 0;

  virtual void enterSimple_type_subject(TsilParser::Simple_type_subjectContext *ctx) = 0;
  virtual void exitSimple_type_subject(TsilParser::Simple_type_subjectContext *ctx) = 0;

  virtual void enterSimple_type_template_get(TsilParser::Simple_type_template_getContext *ctx) = 0;
  virtual void exitSimple_type_template_get(TsilParser::Simple_type_template_getContext *ctx) = 0;

  virtual void enterSimple_type_array(TsilParser::Simple_type_arrayContext *ctx) = 0;
  virtual void exitSimple_type_array(TsilParser::Simple_type_arrayContext *ctx) = 0;

  virtual void enterSimple_type_get(TsilParser::Simple_type_getContext *ctx) = 0;
  virtual void exitSimple_type_get(TsilParser::Simple_type_getContext *ctx) = 0;

  virtual void enterType_simple_type(TsilParser::Type_simple_typeContext *ctx) = 0;
  virtual void exitType_simple_type(TsilParser::Type_simple_typeContext *ctx) = 0;

  virtual void enterType_fn_complex(TsilParser::Type_fn_complexContext *ctx) = 0;
  virtual void exitType_fn_complex(TsilParser::Type_fn_complexContext *ctx) = 0;

  virtual void enterType_fn_complex_named(TsilParser::Type_fn_complex_namedContext *ctx) = 0;
  virtual void exitType_fn_complex_named(TsilParser::Type_fn_complex_namedContext *ctx) = 0;

  virtual void enterType_fn_simple(TsilParser::Type_fn_simpleContext *ctx) = 0;
  virtual void exitType_fn_simple(TsilParser::Type_fn_simpleContext *ctx) = 0;

  virtual void enterType_fn(TsilParser::Type_fnContext *ctx) = 0;
  virtual void exitType_fn(TsilParser::Type_fnContext *ctx) = 0;

  virtual void enterType_nested(TsilParser::Type_nestedContext *ctx) = 0;
  virtual void exitType_nested(TsilParser::Type_nestedContext *ctx) = 0;

  virtual void enterType_single(TsilParser::Type_singleContext *ctx) = 0;
  virtual void exitType_single(TsilParser::Type_singleContext *ctx) = 0;

  virtual void enterType_variation(TsilParser::Type_variationContext *ctx) = 0;
  virtual void exitType_variation(TsilParser::Type_variationContext *ctx) = 0;

  virtual void enterParam(TsilParser::ParamContext *ctx) = 0;
  virtual void exitParam(TsilParser::ParamContext *ctx) = 0;


};

