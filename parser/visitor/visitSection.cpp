#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitSection(TsilParser::SectionContext* context) {
    const auto section_node = new ast::SectionNode();
    for (const auto section_element : context->section_element()) {
      if (section_element->declare()) {
        section_node->body.push_back(
            AAV(visitDeclare(section_element->declare())));
      }
      if (section_element->define()) {
        section_node->body.push_back(
            AAV(visitDefine(section_element->define())));
      }
      if (section_element->section()) {
        section_node->body.push_back(
            AAV(visitSection(section_element->section())));
      }
      if (section_element->structure()) {
        section_node->body.push_back(
            AAV(visitStructure(section_element->structure())));
      }
      if (section_element->diia_declaration()) {
        section_node->body.push_back(
            AAV(visitDiia_declaration(section_element->diia_declaration())));
      }
      if (section_element->diia()) {
        section_node->body.push_back(AAV(visitDiia(section_element->diia())));
      }
    }
    return AV(ast::KindSectionNode, section_node);
  }
} // namespace tsil::parser