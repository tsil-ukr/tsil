#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compileDefine(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto defineNode = astValue->data.DefineNode;
    if (this->state->types.contains(defineNode->id)) {
      return {CompilerError::fromASTValue(
          astValue, "Субʼєкт \"" + defineNode->id + "\" вже визначено")};
    }
    if (this->state->structures.contains(defineNode->id)) {
      return {CompilerError::fromASTValue(
          astValue, "Субʼєкт \"" + defineNode->id + "\" вже визначено")};
    }
    if (this->has_variable(defineNode->id)) {
      return {CompilerError::fromASTValue(
          astValue, "Субʼєкт \"" + defineNode->id + "\" вже визначено")};
    }
    Type* type = nullptr;
    if (defineNode->type) {
      const auto typeResult =
          this->makeTypeFromTypeNodeASTValue(defineNode->type);
      if (!typeResult.type) {
        return {
            CompilerError::fromASTValue(defineNode->type, typeResult.error)};
      }
      type = typeResult.type;
    }
    if (defineNode->value) {
      const auto valueResult =
          this->compileValue(function, block, defineNode->value);
      if (valueResult.error) {
        return {valueResult.error};
      }
      if (type) {
        if (valueResult.type != type) {
          return {CompilerError::fromASTValue(
              defineNode->value, "Тип \"" + valueResult.type->getFullName() +
                                     "\" не сумісний з типом \"" +
                                     type->getFullName() + "\"")};
        }
      } else {
        type = valueResult.type;
      }
      const auto allocaXValue =
          this->state->Module->pushFunctionBlockAllocaInstruction(block,
                                                                  type->LT);
      this->state->Module->pushFunctionBlockStoreInstruction(
          block, valueResult.type->LT, valueResult.LV, allocaXValue);
      this->set_variable(defineNode->id, {type, allocaXValue});
    } else {
      const auto allocaXValue =
          this->state->Module->pushFunctionBlockAllocaInstruction(block,
                                                                  type->LT);
      this->set_variable(defineNode->id, {type, allocaXValue});
    }
    return {nullptr};
  }
} // namespace tsil::compiler