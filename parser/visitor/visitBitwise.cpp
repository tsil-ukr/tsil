#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitBitwise(TsilParser::BitwiseContext* context) {
    const auto binary_node = new ast::BinaryNode();
    binary_node->left = AAV(visitContext(context->b_left));
    binary_node->right = AAV(visitContext(context->b_right));
    const auto op = context->b_operation->getText();
    if (op == "&") {
      binary_node->op = ast::BITWISE_AND;
    } else if (op == "|") {
      binary_node->op = ast::BITWISE_OR;
    } else if (op == "^") {
      binary_node->op = ast::BITWISE_XOR;
    } else if (op == "<<") {
      binary_node->op = ast::BITWISE_SHIFT_LEFT;
    } else if (op == ">>") {
      binary_node->op = ast::BITWISE_SHIFT_RIGHT;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(context, ast::KindBinaryNode, binary_node);
  }

  std::any TsilASTVisitor::visitBitwise_op(
      TsilParser::Bitwise_opContext* context) {
    return nullptr;
  }
} // namespace tsil::parser