#pragma once

#ifndef TSIL_PARSER_H
#define TSIL_PARSER_H

#include <string>
#include <vector>

#include "syntax/antlr4-cpp-runtime/runtime/src/antlr4-runtime.h"
#include "syntax/source/TsilLexer.h"
#include "syntax/source/TsilParser.h"
#include "syntax/source/TsilParserBaseVisitor.h"
#include "tools.h"
#include "розбирач.h"

#define AAV(any) std::any_cast<АСДЗначення*>(any)
#define AAVec(any) (std::any_cast<std::vector<АСДЗначення*>>(any))

namespace tsil::parser {
  class TsilASTVisitor;

  Місцезнаходження* LOC(TsilASTVisitor* visitor,
                        antlr4::ParserRuleContext* context);
  Місцезнаходження* LOC(TsilASTVisitor* visitor, antlr4::Token* token);

  void FILL(TsilASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::ParserRuleContext* context);
  void FILL(TsilASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::Token* token);

  АСДЗначення* AV(TsilASTVisitor* visitor, size_t kind, void* data);
  АСДЗначення* AV(TsilASTVisitor* visitor,
                  antlr4::ParserRuleContext* context,
                  size_t kind,
                  void* data);
  АСДЗначення* AV(TsilASTVisitor* visitor,
                  antlr4::Token* token,
                  size_t kind,
                  void* data);

  СписокАСДЗначень AAVecToList(std::vector<АСДЗначення*> vec);

  class TsilASTVisitor final : public TsilParserBaseVisitor {
   public:
    antlr4::CommonTokenStream* tokens = nullptr;
    ТекстКоду* текст_коду = nullptr;

    std::any visitContext(antlr4::ParserRuleContext* ctx);

    std::any visitFile(TsilParser::FileContext* ctx) override;

    std::any visitProgram(TsilParser::ProgramContext* ctx) override;

    std::any visitAtom_nested(TsilParser::Atom_nestedContext* ctx) override;

    std::any visitAtom_subject(TsilParser::Atom_subjectContext* ctx) override;

    std::any visitAtom_section_get(
        TsilParser::Atom_section_getContext* ctx) override;

    std::any visitAtom_template_get(
        TsilParser::Atom_template_getContext* ctx) override;

    std::any visitAtom_get(TsilParser::Atom_getContext* ctx) override;

    std::any visitAtom_position_get(
        TsilParser::Atom_position_getContext* ctx) override;

    std::any visitAtom_call(TsilParser::Atom_callContext* ctx) override;

    std::any visitOperation_number(
        TsilParser::Operation_numberContext* ctx) override;

    std::any visitOperation_string(
        TsilParser::Operation_stringContext* ctx) override;

    std::any visitOperation_atom(
        TsilParser::Operation_atomContext* ctx) override;

    std::any visitOperation_mul(TsilParser::Operation_mulContext* ctx) override;

    std::any visitOperation_div(TsilParser::Operation_divContext* ctx) override;

    std::any visitOperation_mod(TsilParser::Operation_modContext* ctx) override;

    std::any visitOperation_add(TsilParser::Operation_addContext* ctx) override;

    std::any visitOperation_sub(TsilParser::Operation_subContext* ctx) override;

    std::any visitOperation_lshift(
        TsilParser::Operation_lshiftContext* ctx) override;

    std::any visitOperation_rshift(
        TsilParser::Operation_rshiftContext* ctx) override;

    std::any visitOperation_urshift(
        TsilParser::Operation_urshiftContext* ctx) override;

    std::any visitOperation_lt(TsilParser::Operation_ltContext* ctx) override;

    std::any visitOperation_lte(TsilParser::Operation_lteContext* ctx) override;

    std::any visitOperation_gt(TsilParser::Operation_gtContext* ctx) override;

    std::any visitOperation_gte(TsilParser::Operation_gteContext* ctx) override;

    std::any visitOperation_eq(TsilParser::Operation_eqContext* ctx) override;

    std::any visitOperation_neq(TsilParser::Operation_neqContext* ctx) override;

    std::any visitOperation_and(TsilParser::Operation_andContext* ctx) override;

    std::any visitOperation_xor(TsilParser::Operation_xorContext* ctx) override;

    std::any visitOperation_or(TsilParser::Operation_orContext* ctx) override;

    std::any visitOperation_land(
        TsilParser::Operation_landContext* ctx) override;

    std::any visitOperation_lor(TsilParser::Operation_lorContext* ctx) override;

    std::any visitOperation_ternary(
        TsilParser::Operation_ternaryContext* ctx) override;

    std::any visitExpr_operation(
        TsilParser::Expr_operationContext* ctx) override;

    std::any visitStructure_declare(
        TsilParser::Structure_declareContext* ctx) override;

    std::any visitStructure_define(
        TsilParser::Structure_defineContext* ctx) override;

    std::any visitDiia_declare(TsilParser::Diia_declareContext* ctx) override;

    std::any visitDiia_define(TsilParser::Diia_defineContext* ctx) override;

    std::any visitTsil_declare(TsilParser::Tsil_declareContext* ctx) override;

    std::any visitTsil_define(TsilParser::Tsil_defineContext* ctx) override;

    std::any visitSynonym(TsilParser::SynonymContext* ctx) override;

    std::any visitSection_declare(
        TsilParser::Section_declareContext* ctx) override;

    std::any visitSection_define(
        TsilParser::Section_defineContext* ctx) override;

    std::any visitSet(TsilParser::SetContext* ctx) override;

    std::any visitPosition_set(TsilParser::Position_setContext* ctx) override;

    std::any visitSection_set(TsilParser::Section_setContext* ctx) override;

    std::any visitIf(TsilParser::IfContext* ctx) override;

    std::any visitWhile(TsilParser::WhileContext* ctx) override;

    std::any visitBody(TsilParser::BodyContext* ctx) override;

    std::any visitBody_element(TsilParser::Body_elementContext* ctx) override;

    std::any visitType_nested(TsilParser::Type_nestedContext* ctx) override;

    std::any visitType_subject(TsilParser::Type_subjectContext* ctx) override;

    std::any visitType_section_get(
        TsilParser::Type_section_getContext* ctx) override;

    std::any visitType_template_get(
        TsilParser::Type_template_getContext* ctx) override;

    std::any visitType_get(TsilParser::Type_getContext* ctx) override;

    std::any visitType_array(TsilParser::Type_arrayContext* ctx) override;

    std::any visitType_fn_simple(
        TsilParser::Type_fn_simpleContext* ctx) override;

    std::any visitType_fn_complex(
        TsilParser::Type_fn_complexContext* ctx) override;

    std::any visitType_fn_complex_named(
        TsilParser::Type_fn_complex_namedContext* ctx) override;

    std::any visitParam(TsilParser::ParamContext* ctx) override;
  };

  class TsilParserErrorListener final : public antlr4::BaseErrorListener {
   public:
    std::vector<ПомилкаРозборуЦілі*> errors;
    ТекстКоду* текст_коду = nullptr;

    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override;

    void reportAmbiguity(antlr4::Parser* recognizer,
                         const antlr4::dfa::DFA& dfa,
                         size_t startIndex,
                         size_t stopIndex,
                         bool exact,
                         const antlrcpp::BitSet& ambigAlts,
                         antlr4::atn::ATNConfigSet* configs) override;

    void reportAttemptingFullContext(
        antlr4::Parser* recognizer,
        const antlr4::dfa::DFA& dfa,
        size_t startIndex,
        size_t stopIndex,
        const antlrcpp::BitSet& conflictingAlts,
        antlr4::atn::ATNConfigSet* configs) override;

    void reportContextSensitivity(antlr4::Parser* recognizer,
                                  const antlr4::dfa::DFA& dfa,
                                  size_t startIndex,
                                  size_t stopIndex,
                                  size_t prediction,
                                  antlr4::atn::ATNConfigSet* configs) override;
  };
} // namespace tsil::parser
#endif // TSIL_PARSER_H
