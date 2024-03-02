#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitDefine(TsilParser::DefineContext* context) {
    const auto define_node = new ast::DefineNode();
    if (context->d_type) {
      define_node->type = AAV(visitContext(context->d_type));
    }
    define_node->id = context->d_id->getText();
    define_node->value = AAV(visitContext(context->d_value));
    return AV(ast::KindDefineNode, define_node);
  }
} // namespace tsil::parser