
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

  virtual std::any visitAtom_nested(TsilParser::Atom_nestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_template_get(TsilParser::Atom_template_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_get(TsilParser::Atom_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_section_get(TsilParser::Atom_section_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_subject(TsilParser::Atom_subjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_position_get(TsilParser::Atom_position_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_call(TsilParser::Atom_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_gte(TsilParser::Operation_gteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_neq(TsilParser::Operation_neqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_xor(TsilParser::Operation_xorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lte(TsilParser::Operation_lteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_atom(TsilParser::Operation_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_sub(TsilParser::Operation_subContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_add(TsilParser::Operation_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lt(TsilParser::Operation_ltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_mod(TsilParser::Operation_modContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_mul(TsilParser::Operation_mulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_gt(TsilParser::Operation_gtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_eq(TsilParser::Operation_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_string(TsilParser::Operation_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_land(TsilParser::Operation_landContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_or(TsilParser::Operation_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lor(TsilParser::Operation_lorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_ternary(TsilParser::Operation_ternaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_urshift(TsilParser::Operation_urshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_div(TsilParser::Operation_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_rshift(TsilParser::Operation_rshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lshift(TsilParser::Operation_lshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_number(TsilParser::Operation_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_and(TsilParser::Operation_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lshift(TsilParser::Op_lshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_rshift(TsilParser::Op_rshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_urshift(TsilParser::Op_urshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lte(TsilParser::Op_lteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_gte(TsilParser::Op_gteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_eq(TsilParser::Op_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_neq(TsilParser::Op_neqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_land(TsilParser::Op_landContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lor(TsilParser::Op_lorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGendef(TsilParser::GendefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_operation(TsilParser::Expr_operationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_object(TsilParser::Expr_objectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_declare(TsilParser::Structure_declareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_define(TsilParser::Structure_defineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_element(TsilParser::Structure_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_declare(TsilParser::Diia_declareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_define(TsilParser::Diia_defineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTsil_declare(TsilParser::Tsil_declareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTsil_define(TsilParser::Tsil_defineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSynonym(TsilParser::SynonymContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_declare(TsilParser::Section_declareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_define(TsilParser::Section_defineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet(TsilParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition_set(TsilParser::Position_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_set(TsilParser::Section_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(TsilParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(TsilParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(TsilParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody_element(TsilParser::Body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(TsilParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_get(TsilParser::Type_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_nested(TsilParser::Type_nestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_subject(TsilParser::Type_subjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_array(TsilParser::Type_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_fn_complex(TsilParser::Type_fn_complexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_template_get(TsilParser::Type_template_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_fn_complex_named(TsilParser::Type_fn_complex_namedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_fn_simple(TsilParser::Type_fn_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_fn(TsilParser::Type_fnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_section_get(TsilParser::Type_section_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(TsilParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }


};

