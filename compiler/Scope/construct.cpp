#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileConstructor(tsil::x::Function* xFunction,
                                                tsil::x::FunctionBlock* xBlock,
                                                ast::ASTValue* astValue) {
    const auto constructorNode = astValue->data.ConstructorNode;
    const auto typeResult = this->bakeType(constructorNode->type);
    if (!typeResult.type) {
      return {
          nullptr, nullptr,
          CompilerError::fromASTValue(constructorNode->type, typeResult.error)};
    }
    if (typeResult.type->type != TypeTypeStructureInstance) {
      return {nullptr, nullptr,
              CompilerError::typeIsNotConstructable(constructorNode->type,
                                                    typeResult.type)};
    }
    const auto xAllocValue =
        this->compiler->xModule->pushFunctionBlockAllocaInstruction(
            xBlock, "construct", typeResult.type->xType);
    int argIndex = 0;
    for (const auto argAstValue : constructorNode->args) {
      const auto constructorArgNode = argAstValue->data.ConstructorArgNode;
      TypeStructureField field{};
      if (constructorArgNode->id.empty()) {
        if (argIndex >= typeResult.type->structureInstanceFields.size()) {
          return {nullptr, nullptr,
                  CompilerError::tooManyConstructorArguments(argAstValue)};
        }
        for (const auto& [id, field_] :
             typeResult.type->structureInstanceFields) {
          if (field_.index == argIndex) {
            field = field_;
            break;
          }
        }
      } else {
        if (!typeResult.type->structureInstanceFields.contains(
                constructorArgNode->id)) {
          return {nullptr, nullptr,
                  CompilerError::typeHasNoProperty(argAstValue, typeResult.type,
                                                   constructorArgNode->id)};
        }
        field =
            typeResult.type->structureInstanceFields[constructorArgNode->id];
      }
      auto argValueResult =
          this->compileValue(xFunction, xBlock, constructorArgNode->value, {});
      if (argValueResult.error) {
        return {nullptr, nullptr, argValueResult.error};
      }
      const auto castedXValue =
          this->compileSoftCast(xFunction, xBlock, argValueResult.type,
                                argValueResult.xValue, field.type);
      if (castedXValue) {
        argValueResult.type = field.type;
        argValueResult.xValue = castedXValue;
      } else {
        return {nullptr, nullptr,
                CompilerError::invalidArgumentType(constructorArgNode->value,
                                                   field.name, field.type,
                                                   argValueResult.type)};
      }
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, typeResult.type->xType, xAllocValue,
              {new x::Value(this->compiler->int32Type->xType, "0"),
               new x::Value(this->compiler->int32Type->xType,
                            std::to_string(field.index))});
      this->compiler->xModule->pushFunctionBlockStoreInstruction(
          xBlock, argValueResult.type->xType, argValueResult.xValue, xGepValue);
      argIndex++;
    }
    x::Value* xLoadValue =
        this->compiler->xModule->pushFunctionBlockLoadInstruction(
            xBlock, typeResult.type->xType, xAllocValue);
    return {typeResult.type, xLoadValue, nullptr};
  }
} // namespace tsil::tk