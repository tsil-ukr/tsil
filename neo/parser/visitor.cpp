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
} // namespace tsil::parser