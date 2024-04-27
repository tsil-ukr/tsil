#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitBody(TsilParser::BodyContext* context) {
    std::vector<ast::ASTValue*> body;
    for (const auto body_element : context->body_element()) {
      if (body_element->if_()) {
        body.push_back(AAV(visitIf(body_element->if_())));
      }
      if (body_element->while_()) {
        body.push_back(AAV(visitWhile(body_element->while_())));
      }
      if (body_element->declare()) {
        body.push_back(AAV(visitDeclare(body_element->declare())));
      }
      if (body_element->define()) {
        body.push_back(AAV(visitDefine(body_element->define())));
      }
      if (body_element->assign()) {
        body.push_back(AAV(visitAssign(body_element->assign())));
      }
      if (body_element->set()) {
        body.push_back(AAV(visitSet(body_element->set())));
      }
      if (body_element->expr()) {
        body.push_back(AAV(visitContext(body_element->expr())));
      }
      if (body_element->return_body_element()) {
        const auto return_node = new ast::ReturnNode();
        if (body_element->return_body_element()->rbl_value) {
          return_node->value =
              AAV(visitContext(body_element->return_body_element()->rbl_value));
        }
        body.push_back(AV(context, ast::KindReturnNode, return_node));
      }
    }
    return body;
  }
} // namespace tsil::parser