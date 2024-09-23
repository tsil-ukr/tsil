#include "parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitContext(antlr4::ParserRuleContext* context) {
    // todo: ...

    if (const auto body_context =
            dynamic_cast<TsilParser::BodyContext*>(context)) {
      return visitBody(body_context);
    }
    return nullptr;
  }

  std::any TsilASTVisitor::visitFile(TsilParser::FileContext* ctx) {
      return visitpro
  }

  std::any TsilASTVisitor::visitProgram(TsilParser::ProgramContext* ctx) {
    //
  }
} // namespace tsil::parser