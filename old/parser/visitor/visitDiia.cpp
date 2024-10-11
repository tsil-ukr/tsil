#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitDiia(TsilParser::DiiaContext* context) {
    const auto diia_node = new ast::DiiaNode();
    const auto diia_head_node = new ast::DiiaHeadNode();
    if (context->d_extern) {
      diia_head_node->linkage = ast::DiiaLinkageExtern;
    } else if (context->d_local) {
      diia_head_node->linkage = ast::DiiaLinkageLocal;
    } else {
      diia_head_node->linkage = ast::DiiaLinkageStatic;
    }
    diia_head_node->id = context->d_head->d_name->getText();
    if (context->d_head->d_generics) {
      for (const auto& diia_generic :
           context->d_head->d_generics->diia_generic()) {
        diia_head_node->generic_definitions.push_back(
            diia_generic->ID()->getText());
      }
    }
    if (context->d_head->d_params) {
      for (const auto& param : context->d_head->d_params->param()) {
        const auto param_node = new ast::ParamNode();
        param_node->id = param->p_name->getText();
        if (param->p_type) {
          param_node->type = AAV(visitContext(param->p_type));
        }
        diia_head_node->params.push_back(
            AV(param, ast::KindParamNode, param_node));
      }
    }
    diia_head_node->is_variadic = context->d_head->d_variadic != nullptr;
    if (context->d_head->d_type) {
      diia_head_node->type = AAV(visitContext(context->d_head->d_type));
    }
    diia_node->head = diia_head_node;
    if (context->d_body) {
      diia_node->body = AAVec(visitBody(context->d_body));
    }
    return AV(context, ast::KindDiiaNode, diia_node);
  }

  std::any TsilASTVisitor::visitDiia_declaration(
      TsilParser::Diia_declarationContext* context) {
    const auto diia_declaration_node = new ast::DiiaDeclarationNode();
    const auto diia_head_node = new ast::DiiaHeadNode();
    if (context->d_extern) {
      diia_head_node->linkage = ast::DiiaLinkageExtern;
    } else if (context->d_local) {
      diia_head_node->linkage = ast::DiiaLinkageLocal;
    } else {
      diia_head_node->linkage = ast::DiiaLinkageStatic;
    }
    diia_head_node->id = context->d_head->d_name->getText();
    if (context->d_head->d_generics) {
      for (const auto& diia_generic :
           context->d_head->d_generics->diia_generic()) {
        diia_head_node->generic_definitions.push_back(
            diia_generic->ID()->getText());
      }
    }
    if (context->d_head->d_params) {
      for (const auto& param : context->d_head->d_params->param()) {
        const auto param_node = new ast::ParamNode();
        param_node->id = param->p_name->getText();
        if (param->p_type) {
          param_node->type = AAV(visitContext(param->p_type));
        }
        diia_head_node->params.push_back(
            AV(param, ast::KindParamNode, param_node));
      }
    }
    diia_head_node->is_variadic = context->d_head->d_variadic != nullptr;
    if (context->d_head->d_type) {
      diia_head_node->type = AAV(visitContext(context->d_head->d_type));
    }
    if (context->d_as) {
      diia_declaration_node->as = context->d_as->getText();
    }
    diia_declaration_node->head = diia_head_node;
    return AV(context, ast::KindDiiaDeclarationNode, diia_declaration_node);
  }
} // namespace tsil::parser