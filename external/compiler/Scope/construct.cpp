#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileConstructor(XLFunction* xFunction,
                                                XLBasicBlock* xBlock,
                                                ast::ASTValue* astValue,
                                                bool load) {
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
        tsil_xl_inst_alloca(this->compiler->xModule, xFunction->alloca_block,
                            "construct", typeResult.type->xType);
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
      auto argValueResult = this->compileValueNoVariation(
          xFunction, xBlock, constructorArgNode->value);
      if (argValueResult.error) {
        return {nullptr, nullptr, argValueResult.error};
      }
      auto fieldType = field.type;
      if (fieldType->type == TypeTypeVariationInstance) {
        for (const auto& variationType : fieldType->variationTypes) {
          if (variationType == argValueResult.type) {
            fieldType = variationType;
            break;
          }
        }
      }
      const auto castedXValue =
          this->compileSoftCast(xFunction, xBlock, argValueResult.type,
                                argValueResult.xValue, fieldType);
      if (castedXValue) {
        argValueResult.type = fieldType;
        argValueResult.xValue = castedXValue;
      } else {
        return {nullptr, nullptr,
                CompilerError::invalidArgumentType(constructorArgNode->value,
                                                   field.name, fieldType,
                                                   argValueResult.type)};
      }
      const auto xGepValue = tsil_xl_inst_getelementptr(
          this->compiler->xModule, xBlock, typeResult.type->xType, xAllocValue,
          2,
          std::vector(
              {tsil_xl_create_int32(this->compiler->xModule, 0),
               tsil_xl_create_int32(this->compiler->xModule, field.index)})
              .data());
      tsil_xl_inst_store(this->compiler->xModule, xBlock, argValueResult.xValue,
                         xGepValue);
      argIndex++;
    }
    if (load) {
      XLValue* xLoadValue = tsil_xl_inst_load(
          this->compiler->xModule, xBlock, typeResult.type->xType, xAllocValue);
      return {typeResult.type, xLoadValue, nullptr};
    } else {
      return {typeResult.type, xAllocValue, nullptr};
    }
  }
} // namespace tsil::tk