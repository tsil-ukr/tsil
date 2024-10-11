#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitVariation(
      TsilParser::VariationContext* context) {
    const std::string name = context->v_name->getText();
    const auto variation_node = new ast::VariationNode();
    variation_node->name = name;
    if (context->v_type) {
      variation_node->type = AAV(visitContext(context->v_type));
    } else {
      variation_node->type = nullptr;
    }
    if (context->v_params) {
      for (const auto& param : context->v_params->variation_param()) {
        const auto param_node = new ast::ParamNode();
        param_node->id = param->vp_name->getText();
        param_node->type = AAV(visitContext(param->vp_type));
        variation_node->params.push_back(
            AV(param, ast::KindParamNode, param_node));
      }
    }
    return AV(context, ast::KindVariationNode, variation_node);
  }
} // namespace tsil::parser