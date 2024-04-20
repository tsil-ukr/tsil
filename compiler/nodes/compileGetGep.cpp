#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileGetGep(
      x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::ast::ASTValue* astValue) {
    const auto getPointerNode = astValue->data.GetPointerNode;
    if (getPointerNode->value->kind == ast::KindIdentifierNode) {
      const auto identifierNode = getPointerNode->value->data.IdentifierNode;
      if (this->hasVariable(identifierNode->name)) {
        const auto variable = this->getVariable(identifierNode->name);
        return {variable.first, variable.second, nullptr};
      }
      if (this->hasNonVariableSubject(identifierNode->name)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    getPointerNode->value,
                    "Субʼєкт \"" + identifierNode->name +
                        "\" не можна використовувати як значення")};
      }
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  getPointerNode->value,
                  "Субʼєкт \"" + identifierNode->name + "\" не визначено")};
    } else if (getPointerNode->value->kind == ast::KindGetNode) {
      const auto getNode = getPointerNode->value->data.GetNode;
      CompilerValueResult leftResult =
          this->compileValue(xFunction, xBlock, getNode->left);
      if (leftResult.error) {
        return leftResult;
      }
      if (leftResult.type->type != TypeTypeStructureInstance) {
        return {
            nullptr, nullptr,
            CompilerError::fromASTValue(getNode->left, "Тип не є структурою")};
      }
      if (!leftResult.type->structure_instance_fields.contains(getNode->id)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    getPointerNode->value,
                    "Властивість \"" + getNode->id + "\" не знайдено")};
      }
      const auto field =
          leftResult.type->structure_instance_fields[getNode->id];
      const auto gepXValue =
          this->state->Module->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftResult.type->LT, leftResult.LV,
              {0, static_cast<unsigned long>(field.index)});
      return {field.type, gepXValue, nullptr};

    } else {
      return this->compileValue(xFunction, xBlock, getPointerNode->value);
    }
  }
} // namespace tsil::compiler