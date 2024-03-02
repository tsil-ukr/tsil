#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitAssign(TsilParser::AssignContext* context) {
    const auto assign_node = new ast::AssignNode();
    assign_node->id = context->a_id->getText();
    assign_node->value = AAV(visitContext(context->a_value));
    return AV(context, ast::KindAssignNode, assign_node);
  }
} // namespace tsil::parser