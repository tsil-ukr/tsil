#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitProgram(TsilParser::ProgramContext* context) {
    std::vector<ast::ASTValue*> body;
    for (const auto program_element : context->program_element()) {
      body.push_back(AAV(visitProgram_element(program_element)));
    }
    processASTBody(body);
    const auto program_node = new ast::ProgramNode();
    program_node->body = body;
    return AV(ast::KindProgramNode, program_node);
  }

  std::any TsilASTVisitor::visitProgram_element(
      TsilParser::Program_elementContext* context) {
    if (context->structure()) {
      return visitStructure(context->structure());
    }
    if (context->diia()) {
      return visitDiia(context->diia());
    }
    if (context->if_()) {
      return visitIf(context->if_());
    }
    if (context->while_()) {
      return visitWhile(context->while_());
    }
    if (context->expr()) {
      return visitContext(context->expr());
    }
    if (context->define()) {
      return visitDefine(context->define());
    }
    if (context->assign()) {
      return visitAssign(context->assign());
    }
    if (context->set()) {
      return visitSet(context->set());
    }
    return new ast::ASTValue();
  }
} // namespace tsil::parser