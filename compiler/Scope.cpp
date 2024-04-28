#include "tk.h"

namespace tsil::tk {
  bool Scope::hasSubject(const std::string& name) const {
    if (this->variables.contains(name)) {
      return true;
    }
    if (this->rawTypes.contains(name)) {
      return true;
    }
    if (this->bakedTypes.contains({name, {}})) {
      return true;
    }
    if (this->rawDiias.contains(name)) {
      return true;
    }
    if (this->bakedDiias.contains({name, {}})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasSubject(name);
    }
    return false;
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

  bool Scope::hasRawType(const std::string& name) const {
    if (this->rawTypes.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasRawType(name);
    }
    return false;
  }

  ast::ASTValue* Scope::getRawType(const std::string& name) {
    if (this->rawTypes.contains(name)) {
      return this->rawTypes[name];
    }
    if (this->parent) {
      return this->parent->getRawType(name);
    }
    return nullptr;
  }

  bool Scope::hasBakedType(const std::string& name,
                           const std::vector<Type*>& genericValues) const {
    if (this->bakedTypes.contains({name, genericValues})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasBakedType(name, genericValues);
    }
    return false;
  }

  Type* Scope::getBakedType(const std::string& name,
                            const std::vector<Type*>& genericValues) {
    if (this->bakedTypes.contains({name, genericValues})) {
      return this->bakedTypes[{name, genericValues}];
    }
    if (this->parent) {
      return this->parent->getBakedType(name, genericValues);
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

  CompilerSubjectResult Scope::getSubjectByName(
      ast::ASTValue* contextAstValue,
      const std::string& name,
      const std::vector<Type*>& genericValues) {
    if (this->hasVariable(name)) {
      const auto& [variableType, variableXValue] = this->getVariable(name);
      return {{SubjectKindVariable, variableType, variableXValue}, nullptr};
    }
    if (this->hasBakedDiia(name, genericValues)) {
      const auto bakedDiia = this->getBakedDiia(name, genericValues);
      return {{SubjectKindDiia, bakedDiia.first, bakedDiia.second}, nullptr};
    }
    if (this->hasRawDiia(name)) {
      const auto rawDiia = this->getRawDiia(name);
      const auto bakeDiiaResult =
          this->bakeDiia(contextAstValue, rawDiia, genericValues);
      if (bakeDiiaResult.error) {
        return {{SubjectKindNone, nullptr, nullptr}, bakeDiiaResult.error};
      }
      return {{SubjectKindDiia, bakeDiiaResult.type, bakeDiiaResult.xValue},
              nullptr};
    }
    // todo: handle types, structs etc
    return {{SubjectKindNone, nullptr, nullptr},
            CompilerError::subjectNotDefined(contextAstValue)};
  }

  CompilerValueResult Scope::compileValue(
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      ast::ASTValue* astValue,
      const std::vector<Type*>& genericValues) {
    if (astValue->kind == ast::KindNumberNode) {
      return this->compileNumber(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindStringNode) {
      return this->compileString(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindIdentifierNode) {
      return this->compileLoad(xFunction, xBlock, astValue, genericValues);
    }
    if (astValue->kind == ast::KindGetNode) {
      return this->compileGet(xFunction, xBlock, astValue, true);
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
      return this->compileConstructor(xFunction, xBlock, astValue);
    }
    if (astValue->kind == ast::KindAccessNode) {
      return this->compileAccess(xFunction, xBlock, astValue, true);
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED VALUE")};
  }

  x::Value* Scope::compileSoftCast(tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   Type* type,
                                   x::Value* xValue,
                                   Type* targetType) {
    if (type->equals(targetType)) {
      return xValue;
    }
    if (type->type == TypeTypePointer && targetType->type == TypeTypePointer) {
      // todo: cast pointer?
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
    if ((type == this->compiler->int64Type &&
         targetType == this->compiler->uint64Type) ||
        (type == this->compiler->uint64Type &&
         targetType == this->compiler->int64Type)) {
      return xValue;
    }
    // (char -> int/long/uint/ulong) | (int -> long/ulong) = sext
    if (((type == this->compiler->int8Type) &&
         (targetType == this->compiler->int32Type ||
          targetType == this->compiler->int64Type ||
          targetType == this->compiler->uint32Type ||
          targetType == this->compiler->uint64Type)) ||
        ((type == this->compiler->int32Type) &&
         (targetType == this->compiler->int64Type ||
          targetType == this->compiler->uint64Type))) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockSextInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (uchar -> int/long/uint/ulong) | (uint -> long/ulong) = zext
    if (((type == this->compiler->uint8Type) &&
         (targetType == this->compiler->int32Type ||
          targetType == this->compiler->int64Type ||
          targetType == this->compiler->uint32Type ||
          targetType == this->compiler->uint64Type)) ||
        ((type == this->compiler->uint32Type) &&
         (targetType == this->compiler->int64Type ||
          targetType == this->compiler->uint64Type))) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockZextInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (int/long -> char/uchar) | (uint/ulong -> char/uchar) | (long|ulong -> int|uint) = trunc
    if (((type == this->compiler->int32Type ||
          type == this->compiler->int64Type) &&
         (targetType == this->compiler->int8Type ||
          targetType == this->compiler->uint8Type)) ||
        ((type == this->compiler->uint32Type ||
          type == this->compiler->uint64Type) &&
         (targetType == this->compiler->int8Type ||
          targetType == this->compiler->uint8Type)) ||
        ((type == this->compiler->int64Type ||
          type == this->compiler->uint64Type) &&
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
         targetType == this->compiler->int64Type)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockFptosiInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (float/double -> uchar/uint/ulong) = fptoui
    if ((type == this->compiler->d32Type || type == this->compiler->d64Type ||
         type == this->compiler->doubleType) &&
        (targetType == this->compiler->uint8Type ||
         targetType == this->compiler->uint32Type ||
         targetType == this->compiler->uint64Type)) {
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
         type == this->compiler->int64Type) &&
        (targetType == this->compiler->d32Type ||
         targetType == this->compiler->d64Type ||
         targetType == this->compiler->doubleType)) {
      const auto newXValue =
          this->compiler->xModule->pushFunctionBlockSitofpInstruction(
              xBlock, type->xType, xValue, targetType->xType);
      return newXValue;
    }
    // (uchar/uint/ulong -> float/double) = uitofp
    if ((type == this->compiler->uint8Type ||
         type == this->compiler->uint32Type ||
         type == this->compiler->uint64Type) &&
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
} // namespace tsil::tk