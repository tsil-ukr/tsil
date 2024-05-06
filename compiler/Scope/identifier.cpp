#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileLoad(tsil::x::Function* xFunction,
                                         tsil::x::FunctionBlock* xBlock,
                                         ast::ASTValue* astValue) {
    const auto identifierNode = astValue->data.IdentifierNode;
    if (this->hasSubject(identifierNode->name)) {
      const auto subject = this->getSubject(identifierNode->name);
      if (subject.kind == SubjectKindVariable) {
        const auto variable = subject.data.variable;
        const auto loadXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, variable->type->xType, variable->xValue);
        return {variable->type, loadXValue, nullptr};
      }
      if (subject.kind == SubjectKindDiia) {
        const auto diia = subject.data.diia;
        const auto bakedDiiaResult = diia->bakeDiia(this, {});
        if (bakedDiiaResult.error) {
          return {nullptr, nullptr, bakedDiiaResult.error};
        }
        return {bakedDiiaResult.type, bakedDiiaResult.xValue, nullptr};
      }
      return {nullptr, nullptr,
              CompilerError::subjectIsNotRuntimeValue(astValue)};
    } else {
      return {nullptr, nullptr, CompilerError::subjectNotDefined(astValue)};
    }
  }

  CompilerValueResult Scope::compileGeneric(tsil::x::Function* xFunction,
                                            tsil::x::FunctionBlock* xBlock,
                                            ast::ASTValue* astValue) {
    const auto genericNode = astValue->data.GenericNode;
    std::vector<Type*> genericValues;
    for (const auto& genericValue : genericNode->values) {
      const auto result = this->bakeType(genericValue);
      if (!result.type) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, result.error)};
      }
      genericValues.push_back(result.type);
    }
    if (genericNode->left->kind == ast::KindIdentifierNode) {
      const auto identifierNode = genericNode->left->data.IdentifierNode;
      if (this->hasSubject(identifierNode->name)) {
        const auto subject = this->getSubject(identifierNode->name);
        if (subject.kind == SubjectKindVariable) {
          const auto variable = subject.data.variable;
          const auto loadXValue =
              this->compiler->xModule->pushFunctionBlockLoadInstruction(
                  xBlock, variable->type->xType, variable->xValue);
          return {variable->type, loadXValue, nullptr};
        }
        if (subject.kind == SubjectKindDiia) {
          const auto diia = subject.data.diia;
          const auto bakedDiiaResult = diia->bakeDiia(this, genericValues);
          if (bakedDiiaResult.error) {
            return {nullptr, nullptr, bakedDiiaResult.error};
          }
          return {bakedDiiaResult.type, bakedDiiaResult.xValue, nullptr};
        }
        return {nullptr, nullptr,
                CompilerError::subjectIsNotRuntimeValue(astValue)};
      } else {
        return {nullptr, nullptr, CompilerError::subjectNotDefined(astValue)};
      }
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue->data.GenericNode->left,
                                        "NOT IMPLEMENTED GENERIC LEFT")};
  }
} // namespace tsil::tk