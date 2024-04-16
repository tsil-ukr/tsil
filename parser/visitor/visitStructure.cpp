#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitStructure(
      TsilParser::StructureContext* context) {
    const std::string name = context->s_name->getText();
    const auto structure_node = new ast::StructureNode();
    structure_node->name = name;
    if (context->s_generics) {
      for (const auto structure_generic_context :
           context->s_generics->structure_generic()) {
        structure_node->generic_definitions.push_back(
            structure_generic_context->sg_name->getText());
      }
    }
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

  std::any TsilASTVisitor::visitStructure_generics(
      TsilParser::Structure_genericsContext* ctx) {
    std::vector<ast::ASTValue*> generics;
    for (const auto generic : ctx->structure_generic()) {
      generics.push_back(AAV(visitStructure_generic(generic)));
    }
    return generics;
  }

  std::any TsilASTVisitor::visitStructure_generic(
      TsilParser::Structure_genericContext* ctx) {
    const auto identifier_node = new ast::IdentifierNode();
    identifier_node->name = ctx->sg_name->getText();
    return AV(ctx, ast::KindIdentifierNode, identifier_node);
  }
} // namespace tsil::parser