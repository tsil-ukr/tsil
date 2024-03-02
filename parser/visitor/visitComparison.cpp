#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitComparison(
      TsilParser::ComparisonContext* context) {
    const auto binary_node = new ast::BinaryNode();
    binary_node->left = AAV(visitContext(context->c_left));
    binary_node->right = AAV(visitContext(context->c_right));
    const auto op = context->c_operation->getText();
    if (op == ">") {
      binary_node->op = ast::COMPARISON_GT;
    } else if (op == "<") {
      binary_node->op = ast::COMPARISON_LT;
    } else if (op == ">=") {
      binary_node->op = ast::COMPARISON_GE;
    } else if (op == "<=") {
      binary_node->op = ast::COMPARISON_LE;
    } else if (op == "==") {
      binary_node->op = ast::COMPARISON_EQ;
    } else if (op == "!=") {
      binary_node->op = ast::COMPARISON_NE;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(context, ast::KindBinaryNode, binary_node);
  }

  std::any TsilASTVisitor::visitComparison_op(
      TsilParser::Comparison_opContext* ctx) {
    return nullptr;
  }
} // namespace tsil::parser