#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitDiia(TsilParser::DiiaContext* context) {
    const auto diia_node = new ast::DiiaNode();
    diia_node->id = context->d_name->getText();
    if (context->d_params) {
      diia_node->params = AAVec(visitParams(context->d_params));
    }
    if (context->d_type) {
      diia_node->type = AAV(visitType(context->d_type));
    }
    if (context->d_body) {
      diia_node->body = AAVec(visitBody(context->d_body));
    }
    return AV(context, ast::KindDiiaNode, diia_node);
  }
} // namespace tsil::parser