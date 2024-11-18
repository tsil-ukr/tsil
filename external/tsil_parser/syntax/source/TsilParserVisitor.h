
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "TsilParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TsilParser.
 */
class  TsilParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TsilParser.
   */
    virtual std::any visitFile(TsilParser::FileContext *context) = 0;

    virtual std::any visitProgram(TsilParser::ProgramContext *context) = 0;

    virtual std::any visitAtom_nested(TsilParser::Atom_nestedContext *context) = 0;

    virtual std::any visitAtom_template_get(TsilParser::Atom_template_getContext *context) = 0;

    virtual std::any visitAtom_get(TsilParser::Atom_getContext *context) = 0;

    virtual std::any visitAtom_section_get(TsilParser::Atom_section_getContext *context) = 0;

    virtual std::any visitAtom_subject(TsilParser::Atom_subjectContext *context) = 0;

    virtual std::any visitAtom_position_get(TsilParser::Atom_position_getContext *context) = 0;

    virtual std::any visitAtom_call(TsilParser::Atom_callContext *context) = 0;

    virtual std::any visitCall_arg(TsilParser::Call_argContext *context) = 0;

    virtual std::any visitOperation_gte(TsilParser::Operation_gteContext *context) = 0;

    virtual std::any visitOperation_neq(TsilParser::Operation_neqContext *context) = 0;

    virtual std::any visitOperation_xor(TsilParser::Operation_xorContext *context) = 0;

    virtual std::any visitOperation_lte(TsilParser::Operation_lteContext *context) = 0;

    virtual std::any visitOperation_pre_plus(TsilParser::Operation_pre_plusContext *context) = 0;

    virtual std::any visitOperation_add(TsilParser::Operation_addContext *context) = 0;

    virtual std::any visitOperation_lt(TsilParser::Operation_ltContext *context) = 0;

    virtual std::any visitOperation_pre_minus(TsilParser::Operation_pre_minusContext *context) = 0;

    virtual std::any visitOperation_land(TsilParser::Operation_landContext *context) = 0;

    virtual std::any visitOperation_or(TsilParser::Operation_orContext *context) = 0;

    virtual std::any visitOperation_pre_not(TsilParser::Operation_pre_notContext *context) = 0;

    virtual std::any visitOperation_as(TsilParser::Operation_asContext *context) = 0;

    virtual std::any visitOperation_atom(TsilParser::Operation_atomContext *context) = 0;

    virtual std::any visitOperation_sub(TsilParser::Operation_subContext *context) = 0;

    virtual std::any visitOperation_mod(TsilParser::Operation_modContext *context) = 0;

    virtual std::any visitOperation_mul(TsilParser::Operation_mulContext *context) = 0;

    virtual std::any visitOperation_gt(TsilParser::Operation_gtContext *context) = 0;

    virtual std::any visitOperation_eq(TsilParser::Operation_eqContext *context) = 0;

    virtual std::any visitOperation_string(TsilParser::Operation_stringContext *context) = 0;

    virtual std::any visitOperation_pre_bw_not(TsilParser::Operation_pre_bw_notContext *context) = 0;

    virtual std::any visitOperation_lor(TsilParser::Operation_lorContext *context) = 0;

    virtual std::any visitOperation_ternary(TsilParser::Operation_ternaryContext *context) = 0;

    virtual std::any visitOperation_urshift(TsilParser::Operation_urshiftContext *context) = 0;

    virtual std::any visitOperation_div(TsilParser::Operation_divContext *context) = 0;

    virtual std::any visitOperation_rshift(TsilParser::Operation_rshiftContext *context) = 0;

    virtual std::any visitOperation_lshift(TsilParser::Operation_lshiftContext *context) = 0;

    virtual std::any visitOperation_number(TsilParser::Operation_numberContext *context) = 0;

    virtual std::any visitOperation_and(TsilParser::Operation_andContext *context) = 0;

    virtual std::any visitOp_lshift(TsilParser::Op_lshiftContext *context) = 0;

    virtual std::any visitOp_rshift(TsilParser::Op_rshiftContext *context) = 0;

    virtual std::any visitOp_urshift(TsilParser::Op_urshiftContext *context) = 0;

    virtual std::any visitOp_lte(TsilParser::Op_lteContext *context) = 0;

    virtual std::any visitOp_gte(TsilParser::Op_gteContext *context) = 0;

    virtual std::any visitOp_eq(TsilParser::Op_eqContext *context) = 0;

    virtual std::any visitOp_neq(TsilParser::Op_neqContext *context) = 0;

    virtual std::any visitOp_land(TsilParser::Op_landContext *context) = 0;

    virtual std::any visitOp_lor(TsilParser::Op_lorContext *context) = 0;

    virtual std::any visitGendef(TsilParser::GendefContext *context) = 0;

    virtual std::any visitExpr_operation(TsilParser::Expr_operationContext *context) = 0;

    virtual std::any visitExpr_object(TsilParser::Expr_objectContext *context) = 0;

    virtual std::any visitObject_arg(TsilParser::Object_argContext *context) = 0;

    virtual std::any visitTypeless_object(TsilParser::Typeless_objectContext *context) = 0;

    virtual std::any visitStructure_define(TsilParser::Structure_defineContext *context) = 0;

    virtual std::any visitStructure_element(TsilParser::Structure_elementContext *context) = 0;

    virtual std::any visitDiia_define(TsilParser::Diia_defineContext *context) = 0;

    virtual std::any visitTsil_define(TsilParser::Tsil_defineContext *context) = 0;

    virtual std::any visitAssign(TsilParser::AssignContext *context) = 0;

    virtual std::any visitSynonym(TsilParser::SynonymContext *context) = 0;

    virtual std::any visitSynonym_fn(TsilParser::Synonym_fnContext *context) = 0;

    virtual std::any visitSection_define(TsilParser::Section_defineContext *context) = 0;

    virtual std::any visitSet(TsilParser::SetContext *context) = 0;

    virtual std::any visitPosition_set(TsilParser::Position_setContext *context) = 0;

    virtual std::any visitSection_set(TsilParser::Section_setContext *context) = 0;

    virtual std::any visitAssign_op(TsilParser::Assign_opContext *context) = 0;

    virtual std::any visitIf(TsilParser::IfContext *context) = 0;

    virtual std::any visitWhile(TsilParser::WhileContext *context) = 0;

    virtual std::any visitExec(TsilParser::ExecContext *context) = 0;

    virtual std::any visitBody(TsilParser::BodyContext *context) = 0;

    virtual std::any visitBody_element(TsilParser::Body_elementContext *context) = 0;

    virtual std::any visitReturn(TsilParser::ReturnContext *context) = 0;

    virtual std::any visitLabel(TsilParser::LabelContext *context) = 0;

    virtual std::any visitGoto(TsilParser::GotoContext *context) = 0;

    virtual std::any visitSimple_type_section_get(TsilParser::Simple_type_section_getContext *context) = 0;

    virtual std::any visitSimple_type_subject(TsilParser::Simple_type_subjectContext *context) = 0;

    virtual std::any visitSimple_type_template_get(TsilParser::Simple_type_template_getContext *context) = 0;

    virtual std::any visitSimple_type_array(TsilParser::Simple_type_arrayContext *context) = 0;

    virtual std::any visitSimple_type_get(TsilParser::Simple_type_getContext *context) = 0;

    virtual std::any visitType_simple_type(TsilParser::Type_simple_typeContext *context) = 0;

    virtual std::any visitType_fn_complex(TsilParser::Type_fn_complexContext *context) = 0;

    virtual std::any visitType_fn_complex_named(TsilParser::Type_fn_complex_namedContext *context) = 0;

    virtual std::any visitType_fn_simple(TsilParser::Type_fn_simpleContext *context) = 0;

    virtual std::any visitType_fn(TsilParser::Type_fnContext *context) = 0;

    virtual std::any visitType_nested(TsilParser::Type_nestedContext *context) = 0;

    virtual std::any visitType_single(TsilParser::Type_singleContext *context) = 0;

    virtual std::any visitType_variation(TsilParser::Type_variationContext *context) = 0;

    virtual std::any visitParam(TsilParser::ParamContext *context) = 0;

    virtual std::any visitPreproc_if(TsilParser::Preproc_ifContext *context) = 0;

    virtual std::any visitPreproc_throw(TsilParser::Preproc_throwContext *context) = 0;

    virtual std::any visitTake(TsilParser::TakeContext *context) = 0;

    virtual std::any visitTake_element(TsilParser::Take_elementContext *context) = 0;


};

