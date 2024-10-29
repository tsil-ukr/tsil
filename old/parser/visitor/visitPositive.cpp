#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitPositive(TsilParser::PositiveContext* context) {
    const auto unary_node = new ast::UnaryNode(ast::UNARY_POSITIVE);
    unary_node->value = AAV(visitContext(context->p_value));
    return AV(context, ast::KindUnaryNode, unary_node);
  }
} // namespace tsil::parser