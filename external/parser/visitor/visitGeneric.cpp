#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitGeneric(TsilParser::GenericContext* context) {
    const auto generic_node = new ast::GenericNode();
    generic_node->left = AAV(visitContext(context->particle()));
    for (const auto value : context->full_type()) {
      generic_node->values.push_back(AAV(visitContext(value)));
    }
    return AV(context, ast::KindGenericNode, generic_node);
  }
} // namespace tsil::parser