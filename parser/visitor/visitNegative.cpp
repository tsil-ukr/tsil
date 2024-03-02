#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitNegative(TsilParser::NegativeContext* context) {
    const auto unary_node = new ast::UnaryNode(ast::UNARY_NEGATIVE);
    unary_node->value = AAV(visitContext(context->n_value));
    return AV(context, ast::KindUnaryNode, unary_node);
  }
} // namespace tsil::parser