#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitNot(TsilParser::NotContext* context) {
    const auto unary_node = new ast::UnaryNode(ast::UNARY_NOT);
    unary_node->value = AAV(visitContext(context->n_value));
    return AV(context, ast::KindUnaryNode, unary_node);
  }
} // namespace tsil::parser