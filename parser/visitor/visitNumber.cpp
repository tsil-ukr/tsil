#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitNumber(TsilParser::NumberContext* context) {
    const auto number_node = new ast::NumberNode();
    number_node->value = context->getText();
    return AV(context, ast::KindNumberNode, number_node);
  }

  std::any TsilASTVisitor::visitAtom_number(
      TsilParser::Atom_numberContext* ctx) {
    return visitNumber(ctx->number());
  }
} // namespace tsil::parser