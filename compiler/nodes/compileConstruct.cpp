#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileConstruct(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto constructorNode = astValue->data.ConstructorNode;
    const auto typeResult =
        this->makeTypeFromTypeNodeASTValue(constructorNode->type);
    if (!typeResult.type) {
      return {
          nullptr, nullptr,
          CompilerError::fromASTValue(constructorNode->type, typeResult.error)};
    }
    if (typeResult.type->type != TypeTypeStructureInstance) {
      return {
          nullptr, nullptr,
          CompilerError::fromASTValue(
              constructorNode->type, "Тип \"" + typeResult.type->getFullName() +
                                         "\" не є структурою")};
    }
    const auto xAllocValue =
        this->state->Module->pushFunctionBlockAllocaInstruction(
            block, typeResult.type->LT);
    for (const auto argAstValue : constructorNode->args) {
      const auto constructorArgNode = argAstValue->data.ConstructorArgNode;
      if (!typeResult.type->structure_instance_fields.contains(
              constructorArgNode->id)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    argAstValue, "Властивість \"" + constructorArgNode->id +
                                     "\" не знайдено в типі \"" +
                                     typeResult.type->getFullName() + "\"")};
      }
      const auto field =
          typeResult.type->structure_instance_fields[constructorArgNode->id];
      const auto argValueResult =
          this->compileValue(function, block, constructorArgNode->value);
      if (argValueResult.error) {
        return {nullptr, nullptr, argValueResult.error};
      }
      if (argValueResult.type != field.type) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    constructorArgNode->value,
                    "Невірний тип властивості \"" + constructorArgNode->id +
                        "\": очікується \"" + field.type->getFullName() +
                        "\", отримано \"" + argValueResult.type->getFullName() +
                        "\"")};
      }
      const auto xGepValue =
          this->state->Module->pushFunctionBlockGetElementPtrInstruction(
              block, typeResult.type->LT, xAllocValue,
              {0, static_cast<unsigned long>(field.index)});
      this->state->Module->pushFunctionBlockStoreInstruction(
          block, argValueResult.type->LT, argValueResult.LV, xGepValue);
    }
    x::Value* xLoadValue =
        this->state->Module->pushFunctionBlockLoadInstruction(
            block, typeResult.type->LT, xAllocValue);
    return {typeResult.type, xLoadValue, nullptr};
  }
} // namespace tsil::compiler