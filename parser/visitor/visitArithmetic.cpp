#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitArithmetic_add(
      TsilParser::Arithmetic_addContext* context) {
    const auto binary_node = new ast::BinaryNode();
    binary_node->left = AAV(visitContext(context->a_left));
    binary_node->right = AAV(visitContext(context->a_right));
    const auto op = context->a_operation->getText();
    if (op == "+") {
      binary_node->op = ast::ARITHMETIC_ADD;
    } else if (op == "-") {
      binary_node->op = ast::ARITHMETIC_SUB;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(context, ast::KindBinaryNode, binary_node);
  }

  std::any TsilASTVisitor::visitArithmetic_mul(
      TsilParser::Arithmetic_mulContext* context) {
    const auto binary_node = new ast::BinaryNode();
    binary_node->left = AAV(visitContext(context->a_left));
    binary_node->right = AAV(visitContext(context->a_right));
    const auto op = context->a_operation->getText();
    if (op == "*") {
      binary_node->op = ast::ARITHMETIC_MUL;
    } else if (op == "/") {
      binary_node->op = ast::ARITHMETIC_DIV;
    } else if (op == "%") {
      binary_node->op = ast::ARITHMETIC_MOD;
    } else if (op == "//") {
      binary_node->op = ast::ARITHMETIC_DIVDIV;
    } else if (op == "**") {
      binary_node->op = ast::ARITHMETIC_POW;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(context, ast::KindBinaryNode, binary_node);
  }
} // namespace tsil::parser