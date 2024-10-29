#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitBitwise_not(
      TsilParser::Bitwise_notContext* context) {
    const auto unary_node = new ast::UnaryNode(ast::UNARY_BITWISE_NOT);
    unary_node->value = AAV(visitContext(context->bn_value));
    return AV(context, ast::KindUnaryNode, unary_node);
  }
} // namespace tsil::parser