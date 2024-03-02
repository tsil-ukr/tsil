#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitLogical(TsilParser::LogicalContext* context) {
    const auto logical_node = new ast::LogicalNode();
    logical_node->left = AAV(visitContext(context->t_left));
    logical_node->right = AAV(visitContext(context->t_right));
    const auto op = context->t_operation->getText();
    if (op == "&&") {
      logical_node->op = ast::TEST_AND;
    } else if (op == "||") {
      logical_node->op = ast::TEST_OR;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(context, ast::KindLogicalNode, logical_node);
  }

  std::any TsilASTVisitor::visitLogical_op(TsilParser::Logical_opContext* ctx) {
    return nullptr;
  }
} // namespace tsil::parser