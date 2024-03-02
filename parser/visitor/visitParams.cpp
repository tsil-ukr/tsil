#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitParams(TsilParser::ParamsContext* context) {
    std::vector<ast::ASTValue*> params;
    for (int i = 0; i < context->param().size(); ++i) {
      const auto param = AAV(visitParam(context->param()[i]));
      params.push_back(param);
    }
    return params;
  }

  std::any TsilASTVisitor::visitParam(TsilParser::ParamContext* context) {
    const auto param_node = new ast::ParamNode();
    param_node->id = context->p_name->getText();
    if (context->p_type) {
      param_node->type = AAV(visitType(context->p_type));
    }
    return AV(context, ast::KindParamNode, param_node);
  }
} // namespace tsil::parser