#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitNumber(TsilParser::NumberContext* context) {
    const auto number_node = new ast::NumberNode();
    number_node->value = context->NUMBER()->getText();
    if (context->id != nullptr) {
      number_node->type = context->id->getText();
    }
    return AV(context, ast::KindNumberNode, number_node);
  }
} // namespace tsil::parser