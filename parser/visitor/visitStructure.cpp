#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitStructure(
      TsilParser::StructureContext* context) {
    const std::string name = context->s_name->getText();
    std::vector<ast::ASTValue*> generics;
    const auto structure_node = new ast::StructureNode();
    structure_node->name = name;
    if (context->s_params) {
      structure_node->params = AAVec(visitStructure_params(context->s_params));
    }
    return AV(context, ast::KindStructureNode, structure_node);
  }

  std::any TsilASTVisitor::visitStructure_params(
      TsilParser::Structure_paramsContext* ctx) {
    std::vector<ast::ASTValue*> params;
    for (const auto param : ctx->structure_param()) {
      params.push_back(AAV(visitStructure_param(param)));
    }
    return params;
  }

  std::any TsilASTVisitor::visitStructure_param(
      TsilParser::Structure_paramContext* ctx) {
    const auto param_node = new ast::ParamNode();
    param_node->id = ctx->sp_name->getText();
    if (ctx->sp_type) {
      param_node->type = AAV(visitType(ctx->sp_type));
    }
    return AV(ctx, ast::KindParamNode, param_node);
  }
} // namespace tsil::parser