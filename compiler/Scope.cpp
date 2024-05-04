#include "tk.h"

namespace tsil::tk {
  BakedTypeResult Structure::bakeType(Scope* scope,
                                      const std::vector<Type*>& genericValues) {
    if (this->bakedTypes.contains(genericValues)) {
      return {this->bakedTypes[genericValues], ""};
    }
    if (this->genericDefinitions.size() != genericValues.size()) {
      return {nullptr,
              "Кількість параметрів шаблону структури не "
              "співпадає з кількістю переданих параметрів"};
    }
    const auto scopeWithGenerics = new Scope(scope->compiler, scope);
    int genericIndex = 0;
    for (const auto& genericDefinition : this->genericDefinitions) {
      const auto genericType = genericValues[genericIndex];
      scopeWithGenerics->predefinedTypes[genericDefinition] = genericType;
      genericIndex++;
    }
    const auto type = new Type();
    type->type = TypeTypeStructureInstance;
    type->name = this->name;
    type->genericValues = genericValues;
    type->scopeWithGenerics = scopeWithGenerics;
    this->bakedTypes[genericValues] = type;
    std::vector<x::Type*> xFields(this->fields.size());
    int paramIndex = 0;
    for (const auto& structureField : this->fields) {
      const auto paramTypeResult =
          scopeWithGenerics->bakeType(structureField.type);
      if (!paramTypeResult.type) {
        return {nullptr, paramTypeResult.error};
      }
      const auto field = TypeStructureField{
          .index = paramIndex,
          .type = paramTypeResult.type,
          .name = structureField.name,
      };
      type->structureInstanceFields[structureField.name] = field;
      xFields[paramIndex] = field.type->xType;
      paramIndex++;
    }
    type->xType = scopeWithGenerics->compiler->xModule->defineStructType(
        this->name, xFields);
    return {type, ""};
  }

  std::string Structure::fillBakedTypesWithFields() {
    for (const auto& [bakedTypeGenerics, bakedType] : this->bakedTypes) {
      bakedType->xType->fields.resize(this->fields.size());
      int paramIndex = 0;
      for (const auto& structureField : this->fields) {
        const auto paramTypeResult =
            bakedType->scopeWithGenerics->bakeType(structureField.type);
        if (!paramTypeResult.type) {
          return paramTypeResult.error;
        }
        const auto field = TypeStructureField{
            .index = paramIndex,
            .type = paramTypeResult.type,
            .name = structureField.name,
        };
        bakedType->structureInstanceFields[structureField.name] = field;
        bakedType->xType->fields[paramIndex] = field.type->xType;
        paramIndex++;
      }
    }
    return "";
  }

  bool Scope::hasRawDiia(const std::string& name) const {
    if (this->rawDiias.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasRawDiia(name);
    }
    return false;
  }

  ast::ASTValue* Scope::getRawDiia(const std::string& name) {
    if (this->rawDiias.contains(name)) {
      return this->rawDiias[name];
    }
    if (this->parent) {
      return this->parent->getRawDiia(name);
    }
    return nullptr;
  }

  bool Scope::hasBakedDiia(const std::string& name,
                           const std::vector<Type*>& genericValues) const {
    if (this->bakedDiias.contains({name, genericValues})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasBakedDiia(name, genericValues);
    }
    return false;
  }

  std::pair<Type*, x::Value*> Scope::getBakedDiia(
      const std::string& name,
      const std::vector<Type*>& genericValues) {
    if (this->bakedDiias.contains({name, genericValues})) {
      return this->bakedDiias[{name, genericValues}];
    }
    if (this->parent) {
      return this->parent->getBakedDiia(name, genericValues);
    }
    return {nullptr, nullptr};
  }

  bool Scope::hasStructure(const std::string& name) const {
    if (this->structures.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasStructure(name);
    }
    return false;
  }

  Structure* Scope::getStructure(const std::string& name) {
    if (this->structures.contains(name)) {
      return this->structures[name];
    }
    if (this->parent) {
      return this->parent->getStructure(name);
    }
    return nullptr;
  }

  bool Scope::hasPredefinedType(const std::string& name) const {
    if (this->predefinedTypes.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasPredefinedType(name);
    }
    return false;
  }

  Type* Scope::getPredefinedType(const std::string& name) {
    if (this->predefinedTypes.contains(name)) {
      return this->predefinedTypes[name];
    }
    if (this->parent) {
      return this->parent->getPredefinedType(name);
    }
    return nullptr;
  }

  bool Scope::hasVariable(const std::string& name) const {
    if (this->variables.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasVariable(name);
    }
    return false;
  }

  std::pair<Type*, x::Value*> Scope::getVariable(const std::string& name) {
    if (this->variables.contains(name)) {
      return this->variables[name];
    }
    if (this->parent) {
      return this->parent->getVariable(name);
    }
    return {nullptr, nullptr};
  }

  CompilerRuntimeSubjectResult Scope::getRuntimeSubjectByIdentifierNodeAstValue(
      ast::ASTValue* astValue) {
    const auto identifierNode = astValue->data.IdentifierNode;
    if (this->hasVariable(identifierNode->name)) {
      const auto [variableType, variableXValue] =
          this->getVariable(identifierNode->name);
      return {variableType, variableXValue, nullptr};
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
    } else if (this->hasStructure(identifierNode->name)) {
      return {nullptr, nullptr,
              CompilerError::subjectIsNotRuntimeValue(astValue)};
    } else {
      return {nullptr, nullptr, CompilerError::subjectNotDefined(astValue)};
    }
  }

  CompilerValueResult Scope::compileValue(tsil::x::Function* xFunction,
                                          tsil::x::FunctionBlock* xBlock,
                                          ast::ASTValue* astValue) {
    if (astValue->kind == ast::KindNumberNode) {
      return this->compileNumber(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindStringNode) {
      return this->compileString(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindIdentifierNode) {
      return this->compileLoad(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindGetNode) {
      const auto leftResult = this->compileGetGep(xFunction, xBlock, astValue);
      if (leftResult.error) {
        return leftResult;
      }
      const auto loadXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue);
      return {leftResult.type, loadXValue, nullptr};
    }
    if (astValue->kind == ast::KindAsNode) {
      return this->compileAs(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindBinaryNode) {
      return this->compileBinary(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindCallNode) {
      return this->compileCall(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindConstructorNode) {
      return this->compileConstructor(xFunction, xBlock, astValue, true);
    }
    if (astValue->kind == ast::KindAccessNode) {
      const auto accessResult =
          this->compileAccessGep(xFunction, xBlock, astValue);
      if (accessResult.error) {
        return accessResult;
      }
      const auto loadXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, accessResult.type->xType, accessResult.xValue);
      return {accessResult.type, loadXValue, nullptr};
    }
    if (astValue->kind == ast::KindGenericNode) {
      return this->compileGeneric(xFunction, xBlock, astValue);
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED VALUE")};
  }

  CompilerValueResult Scope::compileLeft(x::Function* xFunction,
                                         tsil::x::FunctionBlock* xBlock,
                                         ast::ASTValue* astValue) {
    if (astValue->kind == ast::KindIdentifierNode) {
      const auto subjectResult =
          this->getRuntimeSubjectByIdentifierNodeAstValue(astValue);
      if (subjectResult.error) {
        return {nullptr, nullptr, subjectResult.error};
      }
      return {subjectResult.type, subjectResult.xValue, nullptr};
    } else if (astValue->kind == ast::KindGetNode) {
      const auto getResult = this->compileGetGep(xFunction, xBlock, astValue);
      if (getResult.error) {
        return getResult;
      }
      return getResult;
    } else if (astValue->kind == ast::KindAccessNode) {
      const auto accessResult =
          this->compileAccessGep(xFunction, xBlock, astValue);
      if (accessResult.error) {
        return accessResult;
      }
      return accessResult;
    } else if (astValue->kind == ast::KindConstructorNode) {
      return this->compileConstructor(xFunction, xBlock, astValue, false);
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED LEFT")};
  }

  x::Value* Scope::compileSoftCast(tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   Type* type,
                                   x::Value* xValue,
                                   Type* targetType) {
    if (type->equals(targetType)) {
      return xValue;
    }
    //    if (type->type == TypeTypePointer && targetType->type == TypeTypePointer) {
    //      // todo: cast pointer?
    //      return xValue;
    //    }
    if (type == this->compiler->uint64Type &&
        targetType == this->compiler->positiveType) {
      return xValue;
    }
    if (type == this->compiler->positiveType &&
        targetType == this->compiler->uint64Type) {
      return xValue;
    }
    if (type == this->compiler->int64Type &&
        targetType == this->compiler->integerType) {
      return xValue;
    }
    if (type == this->compiler->integerType &&
        targetType == this->compiler->int64Type) {
      return xValue;
    }
    if (type == this->compiler->int1Type &&
        targetType == this->compiler->int1Type) {
      return xValue;
    }
    if ((type == this->compiler->int8Type &&
         targetType == this->compiler->uint8Type) ||
        (type == this->compiler->uint8Type &&
         targetType == this->compiler->int8Type)) {
      return xValue;
    }
    if ((type == this->compiler->int32Type &&
         targetType == this->compiler->uint32Type) ||
        (type == this->compiler->uint32Type &&
         targetType == this->compiler->int32Type)) {
      return xValue;
    }
    if (((type == this->compiler->int64Type ||
          type == this->compiler->integerType) &&
         (targetType == this->compiler->uint64Type ||
          targetType == this->compiler->positiveType)) ||
        ((type == this->compiler->uint64Type ||
          type == this->compiler->positiveType) &&
         (targetType == this->compiler->int64Type ||
          targetType == this->compiler->integerType))) {
      return xValue;
    }
    // (char -> int/long/uint/ulong) | (int -> long/ulong) = sext
    if ((((type == this->compiler->int8Type) ||
          (type == this->compiler->int1Type)) &&
         (targetType == this->compiler->int32Type ||
          targetType == this->compiler->int64Type ||
          targetType == this->compiler->integerType ||
          targetType == this->compiler->uint32Type ||
          targetType == this->compiler->uint64Type ||
          targetType == this->compiler->positiveType)) ||
        ((type == this->compiler->int32Type) &&
         (targetType == this->compiler->int64Type ||
          targetType == this->compiler->integerType ||
          targetType == this->compiler->uint64Type ||
          targetType == this->compiler->positiveType))) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockSextInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (uchar -> int/long/uint/ulong) | (uint -> long/ulong) = zext
    if (((type == this->compiler->uint8Type) &&
         (targetType == this->compiler->int32Type ||
          targetType == this->compiler->int64Type ||
          targetType == this->compiler->integerType ||
          targetType == this->compiler->uint32Type ||
          targetType == this->compiler->uint64Type ||
          targetType == this->compiler->positiveType)) ||
        ((type == this->compiler->uint32Type) &&
         (targetType == this->compiler->int64Type ||
          targetType == this->compiler->integerType ||
          targetType == this->compiler->uint64Type ||
          targetType == this->compiler->positiveType))) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockZextInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (int/long -> char/uchar) | (uint/ulong -> char/uchar) | (long|ulong -> int|uint) = trunc
    if (((type == this->compiler->int32Type ||
          type == this->compiler->int64Type ||
          type == this->compiler->integerType) &&
         (targetType == this->compiler->int1Type ||
          targetType == this->compiler->int8Type ||
          targetType == this->compiler->uint8Type)) ||
        ((type == this->compiler->uint32Type ||
          type == this->compiler->uint64Type ||
          type == this->compiler->positiveType) &&
         (targetType == this->compiler->int1Type ||
          targetType == this->compiler->int8Type ||
          targetType == this->compiler->uint8Type)) ||
        ((type == this->compiler->int64Type ||
          type == this->compiler->uint64Type ||
          type == this->compiler->integerType ||
          type == this->compiler->positiveType) &&
         (targetType == this->compiler->int32Type ||
          targetType == this->compiler->uint32Type))) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockTruncInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (float -> double) = fpext
    if (type == this->compiler->d32Type &&
        (targetType == this->compiler->d64Type ||
         targetType == this->compiler->doubleType)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockFpextInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (float/double -> char/int/long) = fptosi
    if ((type == this->compiler->d32Type || type == this->compiler->d64Type ||
         type == this->compiler->doubleType) &&
        (targetType == this->compiler->int8Type ||
         targetType == this->compiler->int32Type ||
         targetType == this->compiler->int64Type ||
         targetType == this->compiler->integerType)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockFptosiInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (float/double -> uchar/uint/ulong) = fptoui
    if ((type == this->compiler->d32Type || type == this->compiler->d64Type ||
         type == this->compiler->doubleType) &&
        (targetType == this->compiler->int1Type ||
         targetType == this->compiler->uint8Type ||
         targetType == this->compiler->uint32Type ||
         targetType == this->compiler->uint64Type ||
         targetType == this->compiler->positiveType)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockFptouiInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (double -> float) = fptrunc
    if ((type == this->compiler->d64Type ||
         type == this->compiler->doubleType) &&
        targetType == this->compiler->d32Type) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockFptruncInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (char/int/long -> float/double) = sitofp
    if ((type == this->compiler->int8Type ||
         type == this->compiler->int32Type ||
         type == this->compiler->int64Type ||
         type == this->compiler->integerType) &&
        (targetType == this->compiler->d32Type ||
         targetType == this->compiler->d64Type ||
         targetType == this->compiler->doubleType)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockSitofpInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (uchar/uint/ulong -> float/double) = uitofp
    if ((type == this->compiler->int1Type ||
         type == this->compiler->uint8Type ||
         type == this->compiler->uint32Type ||
         type == this->compiler->uint64Type ||
         type == this->compiler->positiveType) &&
        (targetType == this->compiler->d32Type ||
         targetType == this->compiler->d64Type ||
         targetType == this->compiler->doubleType)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockUitofpInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    return nullptr;
  }

  x::Value* Scope::compileHardCast(tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   Type* type,
                                   x::Value* xValue,
                                   Type* targetType) {
    return nullptr;
  }
} // namespace tsil::tk