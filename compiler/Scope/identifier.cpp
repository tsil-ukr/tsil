#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileIdentifier(
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      ast::ASTValue* astValue,
      const std::vector<Type*>& genericValues,
      bool load) {
    const auto identifierNode = astValue->data.IdentifierNode;
    if (this->hasVariable(identifierNode->name)) {
      const auto& [variableType, variableXValue] =
          this->getVariable(identifierNode->name);
      if (load) {
        const auto loadXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, variableType->xType, variableXValue);
        return {variableType, loadXValue, nullptr};
      } else {
        return {variableType, variableXValue, nullptr};
      }
    }
    if (this->hasBakedDiia(identifierNode->name, genericValues)) {
      const auto bakedDiia =
          this->getBakedDiia(identifierNode->name, genericValues);
      return {bakedDiia.first, bakedDiia.second, nullptr};
    }
    if (this->hasRawDiia(identifierNode->name)) {
      const auto rawDiia = this->getRawDiia(identifierNode->name);
      const auto bakeDiiaResult =
          this->bakeDiia(astValue, rawDiia, genericValues);
      if (bakeDiiaResult.error) {
        return {nullptr, nullptr, bakeDiiaResult.error};
      }
      return {bakeDiiaResult.type, bakeDiiaResult.xValue, nullptr};
    }
    if (this->hasNonVariableAndNonDiiaSubject(identifierNode->name)) {
      return {nullptr, nullptr,
              CompilerError::subjectIsNotRuntimeValue(astValue)};
    }
    return {nullptr, nullptr, CompilerError::subjectNotDefined(astValue)};
  }
} // namespace tsil::tk