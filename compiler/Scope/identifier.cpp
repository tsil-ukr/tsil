#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileLoad(tsil::x::Function* xFunction,
                                         tsil::x::FunctionBlock* xBlock,
                                         ast::ASTValue* astValue) {
    const auto identifierNode = astValue->data.IdentifierNode;
    if (this->hasVariable(identifierNode->name)) {
      const auto [variableType, variableXValue] =
          this->getVariable(identifierNode->name);
      const auto loadXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, variableType->xType, variableXValue);
      return {variableType, loadXValue, nullptr};
    } else if (this->hasBakedDiia(identifierNode->name, {})) {
      const auto [diiaType, diiaXValue] =
          this->getBakedDiia(identifierNode->name, {});
      return {diiaType, diiaXValue, nullptr};
    } else if (this->hasRawDiia(identifierNode->name)) {
      const auto rawDiiaAstValue = this->getRawDiia(identifierNode->name);
      const auto bakedDiiaResult =
          this->bakeDiia(astValue, rawDiiaAstValue, {});
      if (bakedDiiaResult.error) {
        return {nullptr, nullptr, bakedDiiaResult.error};
      }
      return {bakedDiiaResult.type, bakedDiiaResult.xValue, nullptr};
    } else if (this->hasRawType(identifierNode->name)) {
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
      if (this->hasVariable(identifierNode->name)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED")};
      } else if (this->hasBakedDiia(identifierNode->name, {})) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED")};
      } else if (this->hasRawDiia(identifierNode->name)) {
        const auto rawDiiaAstValue = this->getRawDiia(identifierNode->name);
        const auto bakedDiiaResult =
            this->bakeDiia(astValue, rawDiiaAstValue, genericValues);
        if (bakedDiiaResult.error) {
          return {nullptr, nullptr, bakedDiiaResult.error};
        }
        return {bakedDiiaResult.type, bakedDiiaResult.xValue, nullptr};
      } else if (this->hasRawType(identifierNode->name)) {
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