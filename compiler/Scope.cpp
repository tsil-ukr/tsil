#include "tk.h"

namespace tsil::tk {
  void Scope::setSubject(const std::string& name, Subject subject) {
    if (this->light) {
      this->parent->setSubject(name, subject);
    } else {
      this->subjects.insert_or_assign(name, subject);
    }
  }

  bool Scope::hasSubject(const std::string& name) const {
    if (this->subjects.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasSubject(name);
    }
    return false;
  }

  bool Scope::hasLocalSubject(const std::string& name) const {
    if (this->subjects.contains(name)) {
      return true;
    }
    if (this->light) {
      return this->parent->hasLocalSubject(name);
    }
    return false;
  }

  Subject Scope::getSubject(const std::string& name) {
    if (this->subjects.contains(name)) {
      return this->subjects[name];
    }
    if (this->parent) {
      return this->parent->getSubject(name);
    }
    return {SubjectKindNone};
  }

  Subject Scope::getLocalSubject(const std::string& name) {
    if (this->subjects.contains(name)) {
      return this->subjects[name];
    }
    if (this->light) {
      return this->parent->getLocalSubject(name);
    }
    return {SubjectKindNone};
  }

  std::string Scope::getSectionPrefixForName() {
    std::vector<std::string> sectionNames;
    Scope* scope = this;
    while (scope) {
      if (!scope->sectionName.empty()) {
        sectionNames.push_back(scope->sectionName);
      }
      scope = scope->parent;
    }
    std::reverse(sectionNames.begin(), sectionNames.end());
    const auto result = tsil::parser::tools::implode(sectionNames, "::");
    if (result.empty()) {
      return result;
    }
    return result + "::";
  }

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
    const auto scopeWithGenerics = new Scope(scope->compiler, scope, "", true);
    int genericIndex = 0;
    for (const auto& genericDefinition : this->genericDefinitions) {
      const auto genericType = genericValues[genericIndex];
      scopeWithGenerics->subjects.insert_or_assign(
          genericDefinition, Subject{SubjectKindType, {.type = genericType}});
      genericIndex++;
    }
    const auto type = new Type();
    type->type = TypeTypeStructureInstance;
    type->name = this->name;
    type->genericValues = genericValues;
    type->scopeWithGenerics = scopeWithGenerics;
    type->xType =
        scopeWithGenerics->compiler->xModule->defineStructType(this->name, {});
    this->bakedTypes.insert_or_assign(genericValues, type);
    type->xType->fields.resize(this->fields.size());
    int paramIndex = 0;
    for (const auto& structureField : this->fields) {
      const auto paramTypeResult =
          scopeWithGenerics->bakeType(structureField.type);
      if (!paramTypeResult.type) {
        return {nullptr, paramTypeResult.error};
      }
      if (paramTypeResult.type->type == TypeTypeStructureInstance &&
          paramTypeResult.type->structureInstanceFields.empty()) {
        return {nullptr, "Виявлено неповний тип"};
      }
      const auto field = TypeStructureField{
          .index = paramIndex,
          .type = paramTypeResult.type,
          .name = structureField.name,
      };
      type->structureInstanceFields[structureField.name] = field;
      type->xType->fields[paramIndex] = field.type->xType;
      paramIndex++;
    }
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
        if (paramTypeResult.type->type == TypeTypeStructureInstance &&
            paramTypeResult.type->structureInstanceFields.empty()) {
          return "Виявлено неповний тип";
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

  BakedDiiaResult Diia::bakeDiia(tsil::tk::Scope* scope,
                                 const std::vector<Type*>& genericValues) {
    if (this->bakedDiias.contains(genericValues)) {
      const auto bakedDiia = this->bakedDiias[genericValues];
      return {bakedDiia.type, bakedDiia.xValue, nullptr};
    }
    const auto diiaScope = new Scope(scope->compiler, scope);
    const auto compileDiiaHeadNode =
        [&genericValues, &diiaScope,
         this]() -> std::pair<Type*, CompilerError*> {
      if (genericValues.size() != this->genericDefinitions.size()) {
        const auto compilerError = CompilerError::fromLocation(
            {0, 0, 0, 0}, "Кількість параметрів шаблону дії не співпадає");
        return {nullptr, compilerError};
      }
      int genericIndex = 0;
      for (const auto& genericDefinition : this->genericDefinitions) {
        const auto genericType = genericValues[genericIndex];
        diiaScope->subjects.insert_or_assign(
            genericDefinition, Subject{SubjectKindType, {.type = genericType}});
        genericIndex++;
      }
      const auto diiaType = new Type();
      diiaType->type = TypeTypeDiia;
      diiaType->name = this->name;
      diiaType->xType = diiaScope->compiler->xModule->pointerType;
      diiaType->linkage = this->linkage;
      diiaType->diiaIsVariadic = this->isVariadic;
      diiaType->diiaReturnType = diiaScope->compiler->voidType;
      diiaType->scopeWithGenerics = diiaScope;
      for (const auto& parameter : this->parameters) {
        const auto paramTypeResult = diiaScope->bakeType(parameter.type);
        if (!paramTypeResult.type) {
          const auto compilerError = CompilerError::fromASTValue(
              parameter.type, paramTypeResult.error);
          return {nullptr, compilerError};
        }
        const auto paramXValue = new x::Value(
            paramTypeResult.type->xType,
            diiaScope->compiler->xModule->computeNextVarName("arg"));
        diiaType->diiaParameters.push_back(
            TypeDiiaParameter{.name = parameter.name,
                              .type = paramTypeResult.type,
                              .xValue = paramXValue});
        const auto variable = new Variable();
        variable->type = paramTypeResult.type;
        variable->xValue = paramXValue;
        diiaScope->setSubject(parameter.name, Subject{SubjectKindVariable,
                                                      {.variable = variable}});
      }
      if (this->returnType) {
        const auto diiaResultTypeResult = diiaScope->bakeType(this->returnType);
        if (!diiaResultTypeResult.type) {
          const auto compilerError = CompilerError::fromASTValue(
              this->returnType, diiaResultTypeResult.error);
          return {nullptr, compilerError};
        }
        diiaType->diiaReturnType = diiaResultTypeResult.type;
      }
      return {diiaType, nullptr};
    };
    if (this->name == "main") {
      return {
          nullptr, nullptr,
          CompilerError::fromLocation(
              {0, 0, 0, 0}, "Неможливо визначити субʼєкт з назвою \"main\"")};
    }
    const auto [diiaType, diiaHeadError] = compileDiiaHeadNode();
    if (diiaHeadError) {
      return {nullptr, nullptr, diiaHeadError};
    }
    std::vector<x::Value*> xParamTypes;
    for (const auto& diiaParameter : diiaType->diiaParameters) {
      xParamTypes.push_back(diiaParameter.xValue);
    }
    x::Type* xReturnType = diiaScope->compiler->xModule->voidType;
    if (diiaType->diiaReturnType) {
      xReturnType = diiaType->diiaReturnType->xType;
    }
    auto xFunctionName = diiaType->name == "старт" ? "main" : diiaType->name;
    auto xFunctionAttributes = "";
    if (diiaType->linkage == ast::DiiaLinkageExtern ||
        xFunctionName == "main") {
      xFunctionAttributes = "";
    } else if (diiaType->linkage == ast::DiiaLinkageStatic) {
      xFunctionName =
          diiaScope->compiler->xModule->computeNextName(diiaType->name);
      xFunctionAttributes = "internal";
    } else {
      xFunctionAttributes = "dso_local";
    }
    const auto& [xFunction, functionXValue] =
        diiaScope->compiler->xModule->declareFunction(
            xFunctionAttributes, xFunctionName, xReturnType, xParamTypes);
    this->bakedDiias.insert_or_assign(
        genericValues, BakedDiia{diiaType, functionXValue, xFunction});
    if (!this->isDeclaration) {
      xFunction->entry_block =
          diiaScope->compiler->xModule->defineFunctionBlock(xFunction, "entry");
      if (xFunction->result_type) {
        if (xFunction->result_type != diiaScope->compiler->xModule->voidType) {
          xFunction->return_alloca =
              diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xFunction->entry_block, "return", xFunction->result_type);
        }
      }
      xFunction->exit_block =
          diiaScope->compiler->xModule->defineFunctionBlock(xFunction, "exit");
      if (xFunction->return_alloca) {
        const auto returnLoadXValue =
            diiaScope->compiler->xModule->pushFunctionBlockLoadInstruction(
                xFunction->exit_block, xFunction->result_type,
                xFunction->return_alloca);
        diiaScope->compiler->xModule->pushFunctionBlockRetInstruction(
            xFunction->exit_block, xFunction->result_type, returnLoadXValue);
      } else {
        diiaScope->compiler->xModule->pushFunctionBlockRetInstruction(
            xFunction->exit_block, diiaScope->compiler->xModule->voidType,
            nullptr);
      }
      for (const auto& diiaParameter : diiaType->diiaParameters) {
        const auto allocXValue =
            diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                xFunction->entry_block, diiaParameter.name,
                diiaParameter.type->xType);
        diiaScope->compiler->xModule->pushFunctionBlockStoreInstruction(
            xFunction->entry_block, diiaParameter.type->xType,
            diiaParameter.xValue, allocXValue);
        const auto variable = new Variable();
        variable->type = diiaParameter.type;
        variable->xValue = allocXValue;
        diiaScope->setSubject(
            diiaParameter.name,
            Subject{SubjectKindVariable, {.variable = variable}});
      }
      const auto bodyResult = diiaScope->compileDiiaBody(
          diiaType, xFunction, xFunction->entry_block, xFunction->exit_block,
          this->body);
      if (bodyResult.error) {
        return {nullptr, nullptr, bodyResult.error};
      }
    }
    return {diiaType, functionXValue, nullptr};
  }

  CompilerError* Diia::fillBakedDiiasWithBodies() {
    for (const auto& [genericValues, bakedDiia] : this->bakedDiias) {
      const auto diiaType = bakedDiia.type;
      const auto xFunction = bakedDiia.xFunction;
      const auto diiaScope = diiaType->scopeWithGenerics;
      xFunction->entry_block =
          diiaScope->compiler->xModule->defineFunctionBlock(xFunction, "entry");
      if (xFunction->result_type) {
        if (xFunction->result_type != diiaScope->compiler->xModule->voidType) {
          xFunction->return_alloca =
              diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xFunction->entry_block, "return", xFunction->result_type);
        }
      }
      xFunction->exit_block =
          diiaScope->compiler->xModule->defineFunctionBlock(xFunction, "exit");
      if (xFunction->return_alloca) {
        const auto returnLoadXValue =
            diiaScope->compiler->xModule->pushFunctionBlockLoadInstruction(
                xFunction->exit_block, xFunction->result_type,
                xFunction->return_alloca);
        diiaScope->compiler->xModule->pushFunctionBlockRetInstruction(
            xFunction->exit_block, xFunction->result_type, returnLoadXValue);
      } else {
        diiaScope->compiler->xModule->pushFunctionBlockRetInstruction(
            xFunction->exit_block, diiaScope->compiler->xModule->voidType,
            nullptr);
      }
      for (const auto& diiaParameter : diiaType->diiaParameters) {
        const auto allocXValue =
            diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                xFunction->entry_block, diiaParameter.name,
                diiaParameter.type->xType);
        diiaScope->compiler->xModule->pushFunctionBlockStoreInstruction(
            xFunction->entry_block, diiaParameter.type->xType,
            diiaParameter.xValue, allocXValue);
        const auto variable = new Variable();
        variable->type = diiaParameter.type;
        variable->xValue = allocXValue;
        diiaScope->setSubject(
            diiaParameter.name,
            Subject{SubjectKindVariable, {.variable = variable}});
      }
      const auto bodyResult = diiaScope->compileDiiaBody(
          diiaType, xFunction, xFunction->entry_block, xFunction->exit_block,
          this->body);
      if (bodyResult.error) {
        return bodyResult.error;
      }
    }
    return nullptr;
  }

  CompilerRuntimeSubjectResult Scope::getRuntimeSubjectByIdentifierNodeAstValue(
      ast::ASTValue* astValue) {
    const auto identifierNode = astValue->data.IdentifierNode;
    if (this->hasSubject(identifierNode->name)) {
      const auto subject = this->getSubject(identifierNode->name);
      if (subject.kind == SubjectKindVariable) {
        const auto variable = subject.data.variable;
        return {variable->type, variable->xValue, nullptr};
      }
      if (subject.kind == SubjectKindDiia) {
        const auto diia = subject.data.diia;
        const auto bakedDiiaResult = diia->bakeDiia(this, {});
        if (bakedDiiaResult.error) {
          return {nullptr, nullptr, bakedDiiaResult.error};
        }
        return {bakedDiiaResult.type, bakedDiiaResult.xValue, nullptr};
      }
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
      if (leftResult.type->type == TypeTypeVariationInstance) {
        return {leftResult.type, leftResult.xValue, nullptr};
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
    if (astValue->kind == ast::KindSectionAccessNode) {
      const auto sectionAccessResult = this->resolveSectionAccess(astValue);
      if (sectionAccessResult.error) {
        return {nullptr, nullptr, sectionAccessResult.error};
      }
      return sectionAccessResult.scope->compileValueNoVariation(
          xFunction, xBlock, sectionAccessResult.lastPart);
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED VALUE")};
  }

  CompilerValueResult Scope::compileValueNoVariation(
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      ast::ASTValue* astValue) {
    const auto result = this->compileValue(xFunction, xBlock, astValue);
    if (result.error) {
      return result;
    }
    if (result.type->type == TypeTypeVariationInstance) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Неможливо отримати варіацію як значення")};
    }
    return result;
  }

  SectionAccessResult Scope::resolveSectionAccess(ast::ASTValue* astValue) {
    const auto sectionAccessNode = astValue->data.SectionAccessNode;
    const auto lastPart = sectionAccessNode->parts.back();
    std::vector<ast::ASTValue*> partsWithoutLast;
    for (size_t i = 0; i < sectionAccessNode->parts.size() - 1; i++) {
      partsWithoutLast.push_back(sectionAccessNode->parts[i]);
    }
    Scope* scope;
    for (const auto& partAstValue : partsWithoutLast) {
      const auto partName = partAstValue->data.IdentifierNode->name;
      if (this->hasSubject(partName)) {
        const auto subject = this->getSubject(partName);
        if (subject.kind == SubjectKindSection) {
          scope = subject.data.section;
        } else {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(
                      partAstValue, "Секція \"" + partName + "\" не знайдена")};
        }
      } else {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    partAstValue, "Секція \"" + partName + "\" не знайдена")};
      }
    }
    return {scope, lastPart, nullptr};
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
    } else if (astValue->kind == ast::KindSectionAccessNode) {
      const auto sectionAccessResult = this->resolveSectionAccess(astValue);
      if (sectionAccessResult.error) {
        return {nullptr, nullptr, sectionAccessResult.error};
      }
      return sectionAccessResult.scope->compileLeft(
          xFunction, xBlock, sectionAccessResult.lastPart);
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
    if (type->type == TypeTypePointer &&
        xValue == this->compiler->nullConstant->xValue) {
      return xValue;
    }
    if (type->type == TypeTypeDiia &&
        (targetType->isPointer() && targetType->pointerTo == nullptr)) {
      return xValue;
    }
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
    if ((type == this->compiler->logicalType &&
         targetType == this->compiler->uint8Type) ||
        (type == this->compiler->uint8Type &&
         targetType == this->compiler->logicalType)) {
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
    if ((((type == this->compiler->logicalType ||
           type == this->compiler->int8Type) ||
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
          (targetType == this->compiler->logicalType ||
           targetType == this->compiler->int8Type) ||
          targetType == this->compiler->uint8Type)) ||
        ((type == this->compiler->uint32Type ||
          type == this->compiler->uint64Type ||
          type == this->compiler->positiveType) &&
         (targetType == this->compiler->int1Type ||
          (targetType == this->compiler->logicalType ||
           targetType == this->compiler->int8Type) ||
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
        ((targetType == this->compiler->logicalType ||
          targetType == this->compiler->int8Type) ||
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
    if (((type == this->compiler->logicalType ||
          type == this->compiler->int8Type) ||
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
    if (type->isPointer() && targetType->isPointer()) {
      return new x::Value(targetType->xType, xValue->name);
    }
    if (type->isPointer() && targetType->type == TypeTypeDiia) {
      return new x::Value(targetType->xType, xValue->name);
    }
    if (type->type == TypeTypeDiia && targetType->type == TypeTypeDiia) {
      return new x::Value(targetType->xType, xValue->name);
    }
    return nullptr;
  }
} // namespace tsil::tk