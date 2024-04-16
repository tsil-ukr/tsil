#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitGet(TsilParser::GetContext* context) {
    const auto get_node = new ast::GetNode();
    const auto get_pointer_node = new ast::GetPointerNode();
    get_pointer_node->value = AAV(visitContext(context->g_left));
    get_node->left = AV(context, ast::KindGetPointerNode, get_pointer_node);
    get_node->id = context->g_id->getText();
    return AV(context, ast::KindGetNode, get_node);
  }
} // namespace tsil::parser