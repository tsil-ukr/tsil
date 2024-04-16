#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitSet(TsilParser::SetContext* context) {
    const auto set_node = new ast::SetNode();
    const auto get_pointer_node = new ast::GetPointerNode();
    get_pointer_node->value = AAV(visitContext(context->s_left));
    set_node->left = AV(context, ast::KindGetPointerNode, get_pointer_node);
    set_node->id = context->s_id->getText();
    set_node->value = AAV(visitContext(context->s_value));
    return AV(context, ast::KindSetNode, set_node);
  }
} // namespace tsil::parser