#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitType(TsilParser::TypeContext* context) {
    const auto type_node = new ast::TypeNode();
    type_node->id = context->identifier()->getText();
    if (context->t_first_generic_type) {
      for (const auto generic : context->type()) {
        type_node->generics.push_back(AAV(visitType(generic)));
      }
    }
    return AV(context, ast::KindTypeNode, type_node);
  }
} // namespace tsil::parser