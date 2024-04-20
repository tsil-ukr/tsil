#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitDiia(TsilParser::DiiaContext* context) {
    const auto diia_node = new ast::DiiaNode();
    const auto diia_head_node = new ast::DiiaHeadNode();
    diia_head_node->is_extern = context->d_extern != nullptr;
    diia_head_node->id = context->d_head->d_name->getText();
    if (context->d_head->d_generics) {
      for (const auto& diia_generic :
           context->d_head->d_generics->diia_generic()) {
        diia_head_node->generic_definitions.push_back(
            diia_generic->identifier()->getText());
      }
    }
    if (context->d_head->d_params) {
      diia_head_node->params = AAVec(visitParams(context->d_head->d_params));
    }
    diia_head_node->is_variadic = context->d_head->d_variadic != nullptr;
    if (context->d_head->d_type) {
      diia_head_node->type = AAV(visitFullType(context->d_head->d_type));
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
    diia_head_node->is_extern = context->d_extern != nullptr;
    diia_head_node->id = context->d_head->d_name->getText();
    if (context->d_head->d_generics) {
      for (const auto& diia_generic :
           context->d_head->d_generics->diia_generic()) {
        diia_head_node->generic_definitions.push_back(
            diia_generic->identifier()->getText());
      }
    }
    if (context->d_head->d_params) {
      diia_head_node->params = AAVec(visitParams(context->d_head->d_params));
    }
    diia_head_node->is_variadic = context->d_head->d_variadic != nullptr;
    if (context->d_head->d_type) {
      diia_head_node->type = AAV(visitFullType(context->d_head->d_type));
    }
    if (context->d_as) {
      diia_declaration_node->as = context->d_as->getText();
    }
    diia_declaration_node->head = diia_head_node;
    return AV(context, ast::KindDiiaDeclarationNode, diia_declaration_node);
  }
} // namespace tsil::parser