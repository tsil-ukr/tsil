#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitDefine(TsilParser::DefineContext* context) {
    const auto define_node = new ast::DefineNode();
    define_node->id = context->d_id->getText();
    if (context->d_type) {
      define_node->type = AAV(visitContext(context->d_type));
    }
    define_node->value = AAV(visitContext(context->d_value));
    return AV(context, ast::KindDefineNode, define_node);
  }
} // namespace tsil::parser