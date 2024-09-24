#include "compiler.h"

Scope* createScope(Scope* parent) {
  const auto scope = new Scope();
  scope->parent = parent;
  return scope;
}

std::optional<Subject> findSubject(Scope* scope, const std::string& name) {
  auto currentScope = scope;
  while (currentScope) {
    const auto subject = currentScope->subjects.find(name);
    if (subject != currentScope->subjects.end()) {
      return subject->second;
    }
    currentScope = currentScope->parent;
  }
  return std::nullopt;
}

void setSubject(Scope* scope, const std::string& name, Subject subject) {
  scope->subjects.insert_or_assign(name, subject);
}

CompilationResult compile(Compiler* compiler,
                          Scope* scope,
                          АСДЗначення* astValue) {
  if (astValue->вид == АСДВидСтворитиСтруктуру) {
    const auto data = static_cast<АСДДаніСтворитиСтруктуру*>(astValue->дані);

    const auto structScope = createScope(scope);

    const auto structure = new Structure();
    structure->name = data->ідентифікатор->значення;
    structure->xlType =
        xl_create_struct(compiler->m, data->ідентифікатор->значення);
    setSubject(structScope, data->ідентифікатор->значення,
               Subject{SubjectKindStructure, {.structure = structure}});

    for (int j = 0; j < data->кількість_параметрів; ++j) {
      const auto параметр = data->параметри[j];
      const auto typeResult =
          compileAndReturnType(compiler, structScope, параметр->тип);
      if (typeResult.error) {
        return {{}, typeResult.error};
      }
      const auto parameter = new Parameter();
      parameter->name = параметр->ідентифікатор->значення;
      parameter->type = typeResult.type;
      structure->parameters.push_back(parameter);
    }

    std::vector<XLType*> fields;
    for (const auto parameter : structure->parameters) {
      fields.push_back(getXlType(parameter->type));
    }
    xl_set_struct_fields(compiler->m, structure->xlType, fields.size(),
                         fields.data());

    return {Subject{SubjectKindStructure, {.structure = structure}}, nullptr};
  } else if (astValue->вид == АСДВидСтворитиДію) {
    const auto data = static_cast<АСДДаніСтворитиДію*>(astValue->дані);

    const auto diia = new Diia();
    diia->name = data->ідентифікатор->значення;

    for (int j = 0; j < data->кількість_параметрів; ++j) {
      const auto параметр = data->параметри[j];
      const auto typeResult =
          compileAndReturnType(compiler, scope, параметр->тип);
      if (typeResult.error) {
        return {{}, typeResult.error};
      }
      const auto parameter = new Parameter();
      parameter->name = параметр->ідентифікатор->значення;
      parameter->type = typeResult.type;
      diia->parameters.push_back(parameter);
    }

    if (data->тип_результату) {
      const auto returnTypeResult =
          compileAndReturnType(compiler, scope, data->тип_результату);
      if (returnTypeResult.error) {
        return {{}, returnTypeResult.error};
      }
      diia->returnType = returnTypeResult.type;

      diia->xlFunction = xl_declare_function(
          compiler->m, data->ідентифікатор->значення,
          getXlType(returnTypeResult.type), 0, nullptr, false);
    } else {
    }

    return {Subject{SubjectKindDiia, {.diia = diia}}, nullptr};
  } else if (astValue->вид == АСДВидЗвернутись) {
    const auto data = static_cast<АСДДаніЗвернутись*>(astValue->дані);
    const auto subject = findSubject(scope, data->ідентифікатор->значення);
    if (subject.has_value()) {
      return {subject.value(), nullptr};
    } else {
      return {
          {},
          new CompilationError{"Unknown subject", astValue->місцезнаходження}};
    }
  }
  std::cout << astValue->вид << std::endl;
  return {{},
          new CompilationError{"Unknown value", astValue->місцезнаходження}};
}

CompilationTypeResult compileAndReturnType(Compiler* compiler,
                                           Scope* scope,
                                           АСДЗначення* astValue) {
  const auto result = compile(compiler, scope, astValue);
  if (result.error) {
    return {{}, result.error};
  }
  if (result.subject.kind == SubjectKindStructure) {
    auto type = Type();
    type.kind = TypeKindStructure;
    type.d.structure = result.subject.d.structure;
    return {type, nullptr};
  }
  if (result.subject.kind == SubjectKindNative) {
    auto type = Type();
    type.kind = TypeKindNative;
    type.d.native = result.subject.d.native;
    return {type, nullptr};
  }
  return {{},
          new CompilationError{"Expected type", astValue->місцезнаходження}};
}

XLType* getXlType(Type type) {
  switch (type.kind) {
    case TypeKindStructure:
      return type.d.structure->xlType;
    case TypeKindNative:
      return type.d.native->xlType;
  }
  return nullptr;
}