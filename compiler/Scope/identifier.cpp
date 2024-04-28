#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileLoad(
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      ast::ASTValue* astValue,
      const std::vector<Type*>& genericValues) {
    const auto identifierNode = astValue->data.IdentifierNode;
    const auto subjectResult =
        this->getSubjectByName(astValue, identifierNode->name, {});
    if (subjectResult.error) {
      return {nullptr, nullptr, subjectResult.error};
    }
    const auto subject = subjectResult.subject;
    if (subject.kind == SubjectKindVariable) {
      const auto loadXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, subject.type->xType, subject.xValue);
      return {subject.type, loadXValue, nullptr};
    }
    if (subject.kind == SubjectKindDiia) {
      return {subject.type, subject.xValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::subjectIsNotRuntimeValue(astValue)};
  }
} // namespace tsil::tk