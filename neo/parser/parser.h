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
