#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitGet(TsilParser::GetContext* context) {
    const auto get_node = new ast::GetNode();
    get_node->left = AAV(visitContext(context->g_left));
    get_node->id = context->g_id->getText();
    return AV(context, ast::KindGetNode, get_node);
  }
} // namespace tsil::parser