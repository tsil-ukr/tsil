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

  void FILL(ast::ASTValue* node, antlr4::Token* token);

  ast::ASTValue* AV(ast::ASTValueKind kind, void* data);

  ast::ASTValue* AV(antlr4::ParserRuleContext* context,
                    ast::ASTValueKind kind,
                    void* data);

  ast::ASTValue* AV(antlr4::Token* token, ast::ASTValueKind kind, void* data);

  class TsilASTVisitor final : public TsilParserBaseVisitor {
   public:
    antlr4::CommonTokenStream* tokens = nullptr;

    std::any visitContext(antlr4::ParserRuleContext* context);

    std::any visitFile(TsilParser::FileContext* ctx) override;

    std::any visitProgram(TsilParser::ProgramContext* context) override;

    std::any visitSection(TsilParser::SectionContext* context) override;

    std::any visitStructure(TsilParser::StructureContext* ctx) override;

    std::any visitVariation(TsilParser::VariationContext* ctx) override;

    std::any visitDiia(TsilParser::DiiaContext* ctx) override;

    std::any visitDiia_declaration(
        TsilParser::Diia_declarationContext* ctx) override;

    std::any visitBody(TsilParser::BodyContext* ctx) override;

    std::any visitIf(TsilParser::IfContext* ctx) override;

    std::any visitWhile(TsilParser::WhileContext* ctx) override;

    std::any visitDeclare(TsilParser::DeclareContext* ctx) override;

    std::any visitDefine(TsilParser::DefineContext* ctx) override;

    std::any visitAssign(TsilParser::AssignContext* ctx) override;

    std::any visitSet(TsilParser::SetContext* ctx) override;

    std::any visitIdentifier(TsilParser::IdentifierContext* ctx) override;

    std::any visitGet(TsilParser::GetContext* ctx) override;

    std::any visitAccess(TsilParser::AccessContext* ctx) override;

    std::any visitCall(TsilParser::CallContext* ctx) override;

    std::any visitNested(TsilParser::NestedContext* ctx) override;

    std::any visitNumber(TsilParser::NumberContext* ctx) override;

    std::any visitString(TsilParser::StringContext* ctx) override;

    std::any visitNot(TsilParser::NotContext* ctx) override;

    std::any visitPositive(TsilParser::PositiveContext* ctx) override;

    std::any visitNegative(TsilParser::NegativeContext* ctx) override;

    std::any visitBitwise_not(TsilParser::Bitwise_notContext* ctx) override;

    std::any visitAs(TsilParser::AsContext* ctx) override;

    std::any visitMul(TsilParser::MulContext* ctx) override;

    std::any visitAdd(TsilParser::AddContext* ctx) override;

    std::any visitBitwise(TsilParser::BitwiseContext* ctx) override;

    std::any visitComparison(TsilParser::ComparisonContext* ctx) override;

    std::any visitLogical(TsilParser::LogicalContext* ctx) override;

    std::any visitConstruct(TsilParser::ConstructContext* ctx) override;

    std::any visitSimple_type(TsilParser::Simple_typeContext* ctx) override;

    std::any visitArray_type(TsilParser::Array_typeContext* context) override;

    std::any visitComplex_function_type(
        TsilParser::Complex_function_typeContext* ctx) override;

    std::any visitSimple_function_type(
        TsilParser::Simple_function_typeContext* ctx) override;

    std::any visitVariation_type(
        TsilParser::Variation_typeContext* ctx) override;

    std::any visitFull_type_nested(
        TsilParser::Full_type_nestedContext* ctx) override;

    std::any visitBasic_type_real_basic(
        TsilParser::Basic_type_real_basicContext* ctx) override;

    std::any visitTake(TsilParser::TakeContext* context) override;

    std::any visitReal_section_access(
        TsilParser::Real_section_accessContext* context) override;

    std::any visitGeneric(TsilParser::GenericContext* ctx) override;

    std::any visitBlock(TsilParser::BlockContext* ctx) override;

    std::any visitSynonym(TsilParser::SynonymContext* ctx) override;

    std::any visitDefer(TsilParser::DeferContext* ctx) override;
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

  TsilParserResult parse(const std::string& code);
} // namespace tsil::parser
#endif // TSIL_PARSER_H
