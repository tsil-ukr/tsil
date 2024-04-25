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
    if (subjectResult.what == CompilerSubjectResultWhatVariable) {
      const auto loadXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, subjectResult.type->xType, subjectResult.xValue);
      return {subjectResult.type, loadXValue, nullptr};
    }
    if (subjectResult.what == CompilerSubjectResultWhatDiia) {
      return {subjectResult.type, subjectResult.xValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::subjectIsNotRuntimeValue(astValue)};
  }
} // namespace tsil::tk