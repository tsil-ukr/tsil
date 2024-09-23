#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileCall(XLFunction* xFunction,
                                         XLBasicBlock* xBlock,
                                         ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    if (callNode->value->kind == ast::KindIdentifierNode) {
      const auto identifierNode = callNode->value->data.IdentifierNode;
      if (identifierNode->name == "комірка" ||
          identifierNode->name == "памʼять") {
        return this->compileCall_Pointer(xFunction, xBlock, astValue);
      }
      if (identifierNode->name == "вміст") {
        return this->compileCall_Value(xFunction, xBlock, astValue);
      }
      if (identifierNode->name == "виділити") {
        return this->compileCall_Allocate(xFunction, xBlock, astValue);
      }
      if (identifierNode->name == "перевиділити") {
        return this->compileCall_Reallocate(xFunction, xBlock, astValue);
      }
      if (identifierNode->name == "звільнити") {
        return this->compileCall_Free(xFunction, xBlock, astValue);
      }
      if (identifierNode->name == "дізнатись_розмір") {
        return this->compileCall_Sizeof(xFunction, xBlock, astValue);
      }
      if (identifierNode->name == "ц8" || identifierNode->name == "ц16" ||
          identifierNode->name == "ц32" || identifierNode->name == "ц64" ||
          identifierNode->name == "п1" || identifierNode->name == "п8" ||
          identifierNode->name == "п16" || identifierNode->name == "п32" ||
          identifierNode->name == "п64" || identifierNode->name == "д32" ||
          identifierNode->name == "д64" || identifierNode->name == "логічне" ||
          identifierNode->name == "ціле" ||
          identifierNode->name == "позитивне" ||
          identifierNode->name == "дійсне") {
        return this->compileCallCast(xFunction, xBlock, identifierNode->name,
                                     astValue);
      }
    } else if (callNode->value->kind == ast::KindGenericNode) {
      const auto genericNode = callNode->value->data.GenericNode;
      if (genericNode->left->kind == ast::KindIdentifierNode) {
        const auto identifierNode = genericNode->left->data.IdentifierNode;
        if (identifierNode->name == "комірка" ||
            identifierNode->name == "памʼять") {
          return this->compileCall_Pointer(xFunction, xBlock, astValue);
        }
        if (identifierNode->name == "вміст") {
          return this->compileCall_Value(xFunction, xBlock, astValue);
        }
        if (identifierNode->name == "виділити") {
          return this->compileCall_Allocate(xFunction, xBlock, astValue);
        }
        if (identifierNode->name == "перевиділити") {
          return this->compileCall_Reallocate(xFunction, xBlock, astValue);
        }
        if (identifierNode->name == "звільнити") {
          return this->compileCall_Free(xFunction, xBlock, astValue);
        }
        if (identifierNode->name == "дізнатись_розмір") {
          return this->compileCall_Sizeof(xFunction, xBlock, astValue);
        }
      }
    }
    Type* diiaType;
    XLValue* diiaXValue;
    const auto valueResult =
        this->compileValueNoVariation(xFunction, xBlock, callNode->value);
    if (valueResult.error) {
      return {nullptr, nullptr, valueResult.error};
    }
    diiaType = valueResult.type;
    diiaXValue = valueResult.xValue;
    if (callNode->args.size() < diiaType->diiaParameters.size()) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallArguments(astValue)};
    }
    if (callNode->args.size() > diiaType->diiaParameters.size()) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    std::vector<XLValue*> xArgs;
    int argIndex = 0;
    size_t xArgsVecSize = 0;
    for (const auto& argAstValue : callNode->args) {
      const auto& diiaParameter = diiaType->diiaParameters[argIndex];
      auto argResult =
          this->compileValueNoVariation(xFunction, xBlock, argAstValue);
      if (argResult.error) {
        return argResult;
      }
      const auto castedXValue =
          this->compileSoftCast(xFunction, xBlock, argResult.type,
                                argResult.xValue, diiaParameter.type);
      if (castedXValue) {
        argResult.type = diiaParameter.type;
        argResult.xValue = castedXValue;
      } else {
        return {nullptr, nullptr,
                CompilerError::invalidArgumentType(
                    argAstValue, diiaParameter.name, diiaParameter.type,
                    argResult.type)};
      }
      if ((argIndex + 1) > xArgsVecSize) {
        xArgs.resize(argIndex + 1);
        xArgsVecSize = argIndex + 1;
      }
      xArgs[argIndex] = argResult.xValue;
      argIndex++;
    }
    const auto xValue = tsil_xl_inst_call_value(this->compiler->xModule, xBlock,
                                                diiaType->xType, diiaXValue,
                                                xArgs.size(), xArgs.data());
    return {diiaType->diiaReturnType, xValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Pointer(XLFunction* xFunction,
                                                 XLBasicBlock* xBlock,
                                                 ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    std::vector<Type*> genericValues;
    if (callNode->value->kind == ast::KindGenericNode) {
      for (const auto& genericAstValue :
           callNode->value->data.GenericNode->values) {
        const auto bakedTypeResult = this->bakeType(genericAstValue);
        if (!bakedTypeResult.type) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(genericAstValue,
                                              bakedTypeResult.error)};
        }
        genericValues.push_back(bakedTypeResult.type);
      }
    }
    if (callNode->args.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallArguments(astValue)};
    }
    if (callNode->args.size() > 1) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    if (genericValues.size() > 1) {
      return {nullptr, nullptr,
              CompilerError::tooManyCallTemplateArguments(astValue)};
    }
    const auto firstArgAstValue = callNode->args[0];
    CompilerValueResult firstArgResult;
    if (firstArgAstValue->kind == ast::KindIdentifierNode) {
      const auto subjectResult =
          this->getRuntimeSubjectByIdentifierNodeAstValue(firstArgAstValue);
      if (subjectResult.error) {
        return {nullptr, nullptr, subjectResult.error};
      }
      firstArgResult = {subjectResult.type, subjectResult.xValue, nullptr};
    } else if (firstArgAstValue->kind == ast::KindSectionAccessNode) {
      const auto sectionAccessResult =
          this->resolveSectionAccess(firstArgAstValue);
      if (sectionAccessResult.error) {
        return {nullptr, nullptr, sectionAccessResult.error};
      }
      const auto subjectResult =
          sectionAccessResult.scope->getRuntimeSubjectByIdentifierNodeAstValue(
              sectionAccessResult.lastPart);
      if (subjectResult.error) {
        return {nullptr, nullptr, subjectResult.error};
      }
      firstArgResult = {subjectResult.type, subjectResult.xValue, nullptr};
    } else if (firstArgAstValue->kind == ast::KindGetNode) {
      const auto getResult =
          this->compileGetGep(xFunction, xBlock, firstArgAstValue);
      if (getResult.error) {
        return getResult;
      }
      firstArgResult = {getResult.type, getResult.xValue, nullptr};
    } else if (firstArgAstValue->kind == ast::KindAccessNode) {
      firstArgResult =
          this->compileAccessGep(xFunction, xBlock, firstArgAstValue);
    } else {
      return {
          nullptr, nullptr,
          CompilerError::fromASTValue(
              firstArgAstValue, "Неможливо отримати комірку на це значення.")};
    }
    if (firstArgResult.error) {
      return firstArgResult;
    }
    if (genericValues.empty()) {
      return {firstArgResult.type->getPointerType(this), firstArgResult.xValue,
              nullptr};
    }
    const auto genericValue = genericValues[0];
    const auto castedXValue =
        this->compileSoftCast(xFunction, xBlock, firstArgResult.type,
                              firstArgResult.xValue, genericValue);
    if (castedXValue) {
      firstArgResult.type = genericValue;
      firstArgResult.xValue = castedXValue;
    } else {
      return {
          nullptr, nullptr,
          CompilerError::invalidArgumentType(
              firstArgAstValue, "значення", genericValue, firstArgResult.type)};
    }
    return {firstArgResult.type->getPointerType(this), firstArgResult.xValue,
            nullptr};
  }

  CompilerValueResult Scope::compileCall_Value(XLFunction* xFunction,
                                               XLBasicBlock* xBlock,
                                               ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    std::vector<Type*> genericValues;
    if (callNode->value->kind == ast::KindGenericNode) {
      for (const auto& genericAstValue :
           callNode->value->data.GenericNode->values) {
        const auto bakedTypeResult = this->bakeType(genericAstValue);
        if (!bakedTypeResult.type) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(genericAstValue,
                                              bakedTypeResult.error)};
        }
        genericValues.push_back(bakedTypeResult.type);
      }
    }
    if (callNode->args.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallArguments(astValue)};
    }
    if (callNode->args.size() > 1) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    if (genericValues.size() > 1) {
      return {nullptr, nullptr,
              CompilerError::tooManyCallTemplateArguments(astValue)};
    }
    const auto firstArgAstValue = callNode->args[0];
    auto firstArgResult =
        this->compileValueNoVariation(xFunction, xBlock, firstArgAstValue);
    if (firstArgResult.error) {
      return firstArgResult;
    }
    if (firstArgResult.type->type != TypeTypePointer) {
      return {nullptr, nullptr,
              CompilerError::invalidArgumentType(firstArgAstValue, "значення",
                                                 this->compiler->pointerType,
                                                 firstArgResult.type)};
    }
    if (genericValues.empty()) {
      const auto loadXValue = tsil_xl_inst_load(
          this->compiler->xModule, xBlock,
          firstArgResult.type->pointerTo->xType, firstArgResult.xValue);
      return {firstArgResult.type->pointerTo, loadXValue, nullptr};
    }
    const auto genericValue = genericValues[0];
    const auto castedXValue =
        this->compileSoftCast(xFunction, xBlock, firstArgResult.type->pointerTo,
                              firstArgResult.xValue, genericValue);
    if (castedXValue) {
      firstArgResult.type = genericValue->getPointerType(this);
      firstArgResult.xValue = castedXValue;
    } else {
      return {
          nullptr, nullptr,
          CompilerError::invalidArgumentType(
              firstArgAstValue, "значення", genericValue, firstArgResult.type)};
    }
    const auto loadXValue = tsil_xl_inst_load(
        this->compiler->xModule, xBlock, firstArgResult.type->pointerTo->xType,
        firstArgResult.xValue);
    return {firstArgResult.type->pointerTo, loadXValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Allocate(XLFunction* xFunction,
                                                  XLBasicBlock* xBlock,
                                                  ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    std::vector<Type*> genericValues;
    if (callNode->value->kind == ast::KindGenericNode) {
      for (const auto& genericAstValue :
           callNode->value->data.GenericNode->values) {
        const auto bakedTypeResult = this->bakeType(genericAstValue);
        if (!bakedTypeResult.type) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(genericAstValue,
                                              bakedTypeResult.error)};
        }
        genericValues.push_back(bakedTypeResult.type);
      }
    }
    if (callNode->args.size() > 1) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    if (genericValues.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallTemplateArguments(astValue)};
    }
    if (genericValues.size() > 1) {
      return {nullptr, nullptr,
              CompilerError::tooManyCallTemplateArguments(astValue)};
    }
    CompilerValueResult firstArgResult{nullptr, nullptr, nullptr};
    if (callNode->args.empty()) {
      firstArgResult.type = this->compiler->uint64Type;
      firstArgResult.xValue = tsil_xl_create_int64(this->compiler->xModule, 1);
    } else {
      const auto firstArgAstValue = callNode->args[0];
      firstArgResult =
          this->compileValueNoVariation(xFunction, xBlock, firstArgAstValue);
      if (firstArgResult.error) {
        return firstArgResult;
      }
      const auto castedXValue = this->compileSoftCast(
          xFunction, xBlock, firstArgResult.type, firstArgResult.xValue,
          this->compiler->uint64Type);
      if (castedXValue) {
        firstArgResult.type = this->compiler->uint64Type;
        firstArgResult.xValue = castedXValue;
      } else {
        return {nullptr, nullptr,
                CompilerError::invalidArgumentType(firstArgAstValue, "розмір",
                                                   this->compiler->uint64Type,
                                                   firstArgResult.type)};
      }
    }
    const auto firstGenericValue = genericValues[0];
    const auto typeSizeXValue = tsil_xl_create_int64(
        this->compiler->xModule, firstGenericValue->getBytesSize(this));
    const auto addXValue = tsil_xl_inst_mul(
        this->compiler->xModule, xBlock, firstArgResult.xValue, typeSizeXValue);

    const auto mallocXValue = this->compiler->ensureMallocConnected();
    const auto xValue = tsil_xl_inst_call_value(
        this->compiler->xModule, xBlock,
        tsil_xl_get_as_function_type(this->compiler->xModule, mallocXValue),
        mallocXValue, 1, std::vector({addXValue}).data());
    return {firstGenericValue->getPointerType(this), xValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Reallocate(XLFunction* xFunction,
                                                    XLBasicBlock* xBlock,
                                                    ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    std::vector<Type*> genericValues;
    if (callNode->value->kind == ast::KindGenericNode) {
      for (const auto& genericAstValue :
           callNode->value->data.GenericNode->values) {
        const auto bakedTypeResult = this->bakeType(genericAstValue);
        if (!bakedTypeResult.type) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(genericAstValue,
                                              bakedTypeResult.error)};
        }
        genericValues.push_back(bakedTypeResult.type);
      }
    }
    if (callNode->args.size() < 2) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallArguments(astValue)};
    }
    if (callNode->args.size() > 2) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    if (genericValues.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallTemplateArguments(astValue)};
    }
    if (genericValues.size() > 1) {
      return {nullptr, nullptr,
              CompilerError::tooManyCallTemplateArguments(astValue)};
    }
    const auto firstArgAstValue = callNode->args[0];
    auto firstArgResult =
        this->compileValueNoVariation(xFunction, xBlock, firstArgAstValue);
    if (firstArgResult.error) {
      return firstArgResult;
    }
    const auto firstGenericValue = genericValues[0];
    const auto castedXValue = this->compileSoftCast(
        xFunction, xBlock, firstArgResult.type, firstArgResult.xValue,
        firstGenericValue->getPointerType(this));
    if (castedXValue) {
      firstArgResult.type = firstGenericValue->getPointerType(this);
      firstArgResult.xValue = castedXValue;
    } else {
      return {
          nullptr, nullptr,
          CompilerError::invalidArgumentType(
              firstArgAstValue, "значення",
              firstGenericValue->getPointerType(this), firstArgResult.type)};
    }
    const auto secondArgAstValue = callNode->args[1];
    auto secondArgResult =
        this->compileValueNoVariation(xFunction, xBlock, secondArgAstValue);
    if (secondArgResult.error) {
      return secondArgResult;
    }
    const auto secondCastedXValue = this->compileSoftCast(
        xFunction, xBlock, secondArgResult.type, secondArgResult.xValue,
        this->compiler->uint64Type);
    if (secondCastedXValue) {
      secondArgResult.type = this->compiler->uint64Type;
      secondArgResult.xValue = secondCastedXValue;
    } else {
      return {nullptr, nullptr,
              CompilerError::invalidArgumentType(secondArgAstValue, "кількість",
                                                 this->compiler->uint64Type,
                                                 secondArgResult.type)};
    }
    const auto typeSizeXValue = tsil_xl_create_int64(
        this->compiler->xModule, firstGenericValue->getBytesSize(this));
    const auto addXValue =
        tsil_xl_inst_mul(this->compiler->xModule, xBlock,
                         secondArgResult.xValue, typeSizeXValue);
    const auto reallocXValue = this->compiler->ensureReallocConnected();
    const auto xValue = tsil_xl_inst_call_value(
        this->compiler->xModule, xBlock,
        tsil_xl_get_as_function_type(this->compiler->xModule, reallocXValue),
        reallocXValue, 2,
        std::vector({firstArgResult.xValue, addXValue}).data());
    return {firstGenericValue->getPointerType(this), xValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Free(XLFunction* xFunction,
                                              XLBasicBlock* xBlock,
                                              ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    if (callNode->args.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallArguments(astValue)};
    }
    if (callNode->args.size() > 1) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    auto firstArgAstValue = callNode->args[0];
    auto firstArgResult =
        this->compileValueNoVariation(xFunction, xBlock, firstArgAstValue);
    if (firstArgResult.error) {
      return firstArgResult;
    }
    const auto castedXValue = this->compileSoftCast(
        xFunction, xBlock, firstArgResult.type, firstArgResult.xValue,
        this->compiler->pointerType);
    if (castedXValue) {
      firstArgResult.type = this->compiler->pointerType;
      firstArgResult.xValue = castedXValue;
    } else {
      return {nullptr, nullptr,
              CompilerError::invalidArgumentType(firstArgAstValue, "значення",
                                                 this->compiler->pointerType,
                                                 firstArgResult.type)};
    }
    const auto freeXValue = this->compiler->ensureFreeConnected();
    tsil_xl_inst_call_value(
        this->compiler->xModule, xBlock,
        tsil_xl_get_as_function_type(this->compiler->xModule, freeXValue),
        freeXValue, 1, std::vector({firstArgResult.xValue}).data());
    return {this->compiler->voidType, nullptr, nullptr};
  }

  CompilerValueResult Scope::compileCall_Sizeof(XLFunction* xFunction,
                                                XLBasicBlock* xBlock,
                                                ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    std::vector<Type*> genericValues;
    if (callNode->value->kind == ast::KindGenericNode) {
      for (const auto& genericAstValue :
           callNode->value->data.GenericNode->values) {
        const auto bakedTypeResult = this->bakeType(genericAstValue);
        if (!bakedTypeResult.type) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(genericAstValue,
                                              bakedTypeResult.error)};
        }
        genericValues.push_back(bakedTypeResult.type);
      }
    }
    if (callNode->args.size() > 0) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    if (genericValues.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallTemplateArguments(astValue)};
    }
    if (genericValues.size() > 1) {
      return {nullptr, nullptr,
              CompilerError::tooManyCallTemplateArguments(astValue)};
    }
    const auto firstGenericValue = genericValues[0];
    const auto sizeOfXValue = tsil_xl_create_int64(
        this->compiler->xModule, firstGenericValue->getBytesSize(this));
    return {this->compiler->uint64Type, sizeOfXValue, nullptr};
  }

  CompilerValueResult Scope::compileCallCast(XLFunction* xFunction,
                                             XLBasicBlock* xBlock,
                                             const std::string& name,
                                             ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    if (callNode->args.size() < 1) {
      return {nullptr, nullptr,
              CompilerError::notEnoughCallArguments(astValue)};
    }
    if (callNode->args.size() > 1) {
      return {nullptr, nullptr, CompilerError::tooManyCallArguments(astValue)};
    }
    Type* type = nullptr;
    if (name == "ц8") {
      type = this->compiler->int8Type;
    } else if (name == "ц16") {
      type = this->compiler->int16Type;
    } else if (name == "ц32") {
      type = this->compiler->int32Type;
    } else if (name == "ц64") {
      type = this->compiler->int64Type;
    } else if (name == "п1") {
      type = this->compiler->uint1Type;
    } else if (name == "п8") {
      type = this->compiler->uint8Type;
    } else if (name == "п16") {
      type = this->compiler->uint16Type;
    } else if (name == "п32") {
      type = this->compiler->uint32Type;
    } else if (name == "п64") {
      type = this->compiler->uint64Type;
    } else if (name == "д32") {
      type = this->compiler->f32Type;
    } else if (name == "д64") {
      type = this->compiler->f64Type;
    } else if (name == "логічне") {
      type = this->compiler->uint8Type;
    } else if (name == "ціле") {
      type = this->compiler->int64Type;
    } else if (name == "позитивне") {
      type = this->compiler->uint64Type;
    } else if (name == "дійсне") {
      type = this->compiler->f64Type;
    } else {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED")};
    }
    const auto valueResult =
        this->compileValueNoVariation(xFunction, xBlock, callNode->args[0]);
    if (valueResult.error) {
      return valueResult;
    }
    auto newXValue = this->compileSoftCast(xFunction, xBlock, valueResult.type,
                                           valueResult.xValue, type);
    if (newXValue == nullptr) {
      newXValue = this->compileHardCast(xFunction, xBlock, valueResult.type,
                                        valueResult.xValue, type);
      if (newXValue == nullptr) {
        return {nullptr, nullptr,
                CompilerError::cannotCast(astValue, valueResult.type, type)};
      }
    }
    return {type, newXValue, nullptr};
  }
} // namespace tsil::tk