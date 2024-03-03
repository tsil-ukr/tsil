#pragma once

#ifndef TSIL_PARSER_H
#define TSIL_PARSER_H

#include <string>
#include <vector>

#include "ast.h"
#include "syntax/TsilLexer.h"
#include "syntax/TsilParser.h"
#include "syntax/TsilParserBaseVisitor.h"
#include "syntax/antlr4-cpp-runtime/runtime/src/antlr4-runtime.h"
#include "tools.h"

#define AAV(any) std::any_cast<ast::ASTValue*>(any)
#define AAVec(any) (std::any_cast<std::vector<ast::ASTValue*>>(any))

namespace tsil::parser {
  void FILL(ast::ASTValue* node, antlr4::ParserRuleContext* context);

  ast::ASTValue* AV(ast::ASTValueKind kind, void* data);

  ast::ASTValue* AV(antlr4::ParserRuleContext* context,
                    ast::ASTValueKind kind,
                    void* data);

  void processASTBody(std::vector<ast::ASTValue*>& body);

  class TsilASTVisitor final : public TsilParserBaseVisitor {
   public:
    antlr4::CommonTokenStream* tokens = nullptr;

    std::any visitContext(antlr4::ParserRuleContext* context);

    std::any visitFile(TsilParser::FileContext* ctx) override;

    std::any visitProgram(TsilParser::ProgramContext* context) override;

    std::any visitProgram_element(
        TsilParser::Program_elementContext* context) override;

    std::any visitStructure(TsilParser::StructureContext* ctx) override;

    std::any visitStructure_params(
        TsilParser::Structure_paramsContext* ctx) override;

    std::any visitStructure_param(
        TsilParser::Structure_paramContext* ctx) override;

    std::any visitDiia(TsilParser::DiiaContext* ctx) override;

    std::any visitDiia_declaration(TsilParser::Diia_declarationContext *ctx) override;

    std::any visitIf(TsilParser::IfContext* ctx) override;

    std::any visitWhile(TsilParser::WhileContext* ctx) override;

    std::any visitDefine(TsilParser::DefineContext* ctx) override;

    std::any visitAssign(TsilParser::AssignContext* ctx) override;

    std::any visitSet(TsilParser::SetContext* ctx) override;

    std::any visitNumber(TsilParser::NumberContext* ctx) override;

    std::any visitAtom_number(TsilParser::Atom_numberContext* ctx) override;

    std::any visitString(TsilParser::StringContext* ctx) override;

    std::any visitAtom_string(TsilParser::Atom_stringContext* ctx) override;

    std::any visitIdentifier(TsilParser::IdentifierContext* ctx) override;

    std::any visitAtom_identifier(
        TsilParser::Atom_identifierContext* ctx) override;

    std::any visitGet(TsilParser::GetContext* ctx) override;

    std::any visitCall(TsilParser::CallContext* ctx) override;

    std::any visitPositive(TsilParser::PositiveContext* ctx) override;

    std::any visitNegative(TsilParser::NegativeContext* ctx) override;

    std::any visitNot(TsilParser::NotContext* ctx) override;

    std::any visitBitwise_not(TsilParser::Bitwise_notContext* ctx) override;

    std::any visitNested(TsilParser::NestedContext* ctx) override;

    std::any visitValue_atom(TsilParser::Value_atomContext* ctx) override;

    std::any visitArithmetic_mul(
        TsilParser::Arithmetic_mulContext* ctx) override;

    std::any visitArithmetic_add(
        TsilParser::Arithmetic_addContext* ctx) override;

    std::any visitBitwise(TsilParser::BitwiseContext* ctx) override;

    std::any visitBitwise_op(TsilParser::Bitwise_opContext* ctx) override;

    std::any visitComparison(TsilParser::ComparisonContext* ctx) override;

    std::any visitComparison_op(TsilParser::Comparison_opContext* ctx) override;

    std::any visitLogical(TsilParser::LogicalContext* ctx) override;

    std::any visitLogical_op(TsilParser::Logical_opContext* ctx) override;

    std::any visitIdentifiers_chain(
        TsilParser::Identifiers_chainContext* ctx) override;

    std::any visitType(TsilParser::TypeContext* ctx) override;

    std::any visitArgs(TsilParser::ArgsContext* ctx) override;

    std::any visitParams(TsilParser::ParamsContext* ctx) override;

    std::any visitParam(TsilParser::ParamContext* ctx) override;

    std::any visitBody(TsilParser::BodyContext* ctx) override;

    std::any visitBody_element_or_return(
        TsilParser::Body_element_or_returnContext* ctx) override;

    std::any visitBody_element(TsilParser::Body_elementContext* ctx) override;

    std::any visitReturn_body_element(
        TsilParser::Return_body_elementContext* ctx) override;
  };

  struct TsilParserError {
    size_t line = 0;
    size_t column = 0;
    std::string message;
  };

  class TsilParserResult {
   public:
    std::vector<TsilParserError> errors;
    tsil::ast::ProgramNode* program_node;
  };

  class TsilParserErrorListener final : public antlr4::BaseErrorListener {
   public:
    std::vector<TsilParserError> errors;

    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override;
  };

  TsilParserResult parse(const std::string& code);
} // namespace tsil::parser
#endif // TSIL_PARSER_H
