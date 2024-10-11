#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitStructure(
      TsilParser::StructureContext* context) {
    const std::string name = context->s_name->getText();
    const auto structure_node = new ast::StructureNode();
    structure_node->name = name;
    if (context->s_generics) {
      for (const auto& structure_generic :
           context->s_generics->structure_generic()) {
        structure_node->generic_definitions.push_back(
            structure_generic->sg_name->getText());
      }
    }
    if (context->s_params) {
      for (const auto& param : context->s_params->structure_param()) {
        const auto param_node = new ast::ParamNode();
        param_node->id = param->sp_name->getText();
        param_node->type = AAV(visitContext(param->sp_type));
        structure_node->params.push_back(
            AV(param, ast::KindParamNode, param_node));
      }
    }
    return AV(context, ast::KindStructureNode, structure_node);
  }
} // namespace tsil::parser