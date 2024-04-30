#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileCall(tsil::x::Function* xFunction,
                                         tsil::x::FunctionBlock* xBlock,
                                         ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    if (callNode->value->kind == ast::KindIdentifierNode) {
      const auto identifierNode = callNode->value->data.IdentifierNode;
      if (identifierNode->name == "комірка") {
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
      if (identifierNode->name == "розмір") {
        return this->compileCall_Sizeof(xFunction, xBlock, astValue);
      }
    } else if (callNode->value->kind == ast::KindGenericNode) {
      const auto genericNode = callNode->value->data.GenericNode;
      if (genericNode->left->kind == ast::KindIdentifierNode) {
        const auto identifierNode = genericNode->left->data.IdentifierNode;
        if (identifierNode->name == "комірка") {
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
        if (identifierNode->name == "розмір") {
          return this->compileCall_Sizeof(xFunction, xBlock, astValue);
        }
      }
    }
    Type* diiaType;
    x::Value* diiaXValue;
    const auto valueResult =
        this->compileValue(xFunction, xBlock, callNode->value);
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
    std::vector<x::Value*> xArgs;
    int argIndex = 0;
    for (const auto& argAstValue : callNode->args) {
      auto argResult = this->compileValue(xFunction, xBlock, argAstValue);
      if (argResult.error) {
        return argResult;
      }
      const auto& diiaParameter = diiaType->diiaParameters[argIndex];
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
      xArgs.push_back(argResult.xValue);
      argIndex++;
    }
    const auto xValue =
        this->compiler->xModule->pushFunctionBlockCallInstruction(
            xBlock, diiaType->diiaReturnType->xType, diiaXValue, xArgs);
    return {diiaType->diiaReturnType, xValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Pointer(tsil::x::Function* xFunction,
                                                 tsil::x::FunctionBlock* xBlock,
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
      const auto subjectResult = this->getSubjectByName(
          firstArgAstValue, firstArgAstValue->data.IdentifierNode->name, {});
      if (subjectResult.error) {
        return {nullptr, nullptr, subjectResult.error};
      }
      const auto subject = subjectResult.subject;
      if (subject.kind != SubjectKindVariable &&
          subject.kind != SubjectKindDiia) {
        return {nullptr, nullptr,
                CompilerError::subjectIsNotRuntimeValue(firstArgAstValue)};
      }
      firstArgResult = {subject.type, subject.xValue, nullptr};
    } else if (firstArgAstValue->kind == ast::KindGetNode) {
      firstArgResult = this->compileGetGep(xFunction, xBlock, firstArgAstValue);
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

  CompilerValueResult Scope::compileCall_Value(tsil::x::Function* xFunction,
                                               tsil::x::FunctionBlock* xBlock,
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
        this->compileValue(xFunction, xBlock, firstArgAstValue);
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
      const auto loadXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, firstArgResult.type->pointerTo->xType,
              firstArgResult.xValue);
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
    const auto loadXValue =
        this->compiler->xModule->pushFunctionBlockLoadInstruction(
            xBlock, firstArgResult.type->pointerTo->xType,
            firstArgResult.xValue);
    return {firstArgResult.type->pointerTo, loadXValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Allocate(
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
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
        this->compileValue(xFunction, xBlock, firstArgAstValue);
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
    const auto firstGenericValue = genericValues[0];
    const auto typeSizeXValue =
        new x::Value(this->compiler->uint64Type->xType,
                     std::to_string(firstGenericValue->getBytesSize(this)));
    const auto xValue =
        this->compiler->xModule->pushFunctionBlockCallInstruction(
            xBlock, this->compiler->pointerType->xType,
            this->compiler->ensureCallocConnected(),
            {firstArgResult.xValue, typeSizeXValue});
    return {firstGenericValue->getPointerType(this), xValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Reallocate(
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
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
        this->compileValue(xFunction, xBlock, firstArgAstValue);
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
        this->compileValue(xFunction, xBlock, secondArgAstValue);
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
    const auto typeSizeXValue =
        new x::Value(this->compiler->uint64Type->xType,
                     std::to_string(firstGenericValue->getBytesSize(this)));
    const auto addXValue =
        this->compiler->xModule->pushFunctionBlockMulInstruction(
            xBlock, this->compiler->uint64Type->xType, secondArgResult.xValue,
            typeSizeXValue);
    const auto xValue =
        this->compiler->xModule->pushFunctionBlockCallInstruction(
            xBlock, this->compiler->pointerType->xType,
            this->compiler->ensureReallocConnected(),
            {firstArgResult.xValue, addXValue});
    return {firstGenericValue->getPointerType(this), xValue, nullptr};
  }

  CompilerValueResult Scope::compileCall_Free(tsil::x::Function* xFunction,
                                              tsil::x::FunctionBlock* xBlock,
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
        this->compileValue(xFunction, xBlock, firstArgAstValue);
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
    this->compiler->xModule->pushFunctionBlockCallInstruction(
        xBlock, this->compiler->voidType->xType,
        this->compiler->ensureFreeConnected(), {firstArgResult.xValue});
    return {this->compiler->voidType, nullptr, nullptr};
  }

  CompilerValueResult Scope::compileCall_Sizeof(tsil::x::Function* xFunction,
                                                tsil::x::FunctionBlock* xBlock,
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
    const auto sizeOfXValue =
        new x::Value(this->compiler->uint64Type->xType,
                     std::to_string(firstGenericValue->getBytesSize(this)));
    return {this->compiler->uint64Type, sizeOfXValue, nullptr};
  }
} // namespace tsil::tk