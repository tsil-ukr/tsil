#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitAccess(TsilParser::AccessContext* context) {
    const auto access_node = new ast::AccessNode();
    access_node->value = AAV(visitContext(context->a_value));
    access_node->index = AAV(visitContext(context->a_index));
    return AV(context, ast::KindAccessNode, access_node);
  }
} // namespace tsil::parser