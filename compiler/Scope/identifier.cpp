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
} // namespace tsil::tk