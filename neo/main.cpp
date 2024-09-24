#include "parser.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/TargetParser/Host.h"

#include "xl.h"

struct Type;
struct Parameter;
struct Native;
struct Structure;
struct Diia;
struct Tsil;
struct Subject;
struct Scope;
struct Compiler;
struct CompilationError;
struct CompilationResult;
struct CompilationTypeResult;

enum TypeKind {
  TypeKindNative,
  TypeKindStructure,
};

struct Type {
  TypeKind kind;
  union {
    Native* native;
    Structure* structure;
  } d;
};

XLType* getXlType(Type type);

struct Parameter {
  std::string name;
  Type type;
};

struct Native {
  std::string name;
  XLType* xlType;
};

struct Structure {
  std::string name;
  std::vector<Parameter*> parameters;
  XLType* xlType;
};

struct Diia {
  std::string name;
  std::vector<Parameter*> parameters;
  Type returnType;
  XLFunction* xlFunction;
};

struct Tsil {
  std::string name;
  Type type;
};

enum SubjectKind {
  SubjectKindNative,
  SubjectKindStructure,
  SubjectKindDiia,
  SubjectKindTsil,
};

struct Subject {
  SubjectKind kind;
  union {
    Native* native;
    Structure* structure;
    Diia* diia;
    Tsil* tsil;
  } d;
};

struct Scope {
  Compiler* compiler;
  Scope* parent;
  std::unordered_map<std::string, Subject> subjects;
};

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

CompilationResult compile(Scope* scope, АСДЗначення* astValue);
CompilationTypeResult compileReturnType(Scope* scope, АСДЗначення* astValue);

struct Compiler {
  Scope* globalScope;
  XLM* m;
};

struct CompilationError {
  std::string message;
  Місцезнаходження* location;
};

struct CompilationResult {
  Subject subject;
  CompilationError* error;
};

struct CompilationTypeResult {
  Type type;
  CompilationError* error;
};

int main() {
  std::string filename = "тест.ц";
  std::ifstream file(filename);
  std::string code((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  auto текстКоду = new ТекстКоду((char*)"...", (char*)code.c_str());
  auto parseResult = розібрати_ціль(текстКоду);
  if (parseResult.успіх) {
    const auto compiler = new Compiler();
    const auto globalScope = new Scope();
    globalScope->compiler = compiler;
    globalScope->parent = nullptr;
    compiler->globalScope = globalScope;
    compiler->m = xlm_create(strdup(filename.c_str()));

    const auto scope = new Scope();
    scope->compiler = compiler;
    scope->parent = globalScope;

    const auto nativeInt32 = new Native();
    nativeInt32->name = "ц32";
    nativeInt32->xlType = xl_get_int32_type(compiler->m);
    globalScope->subjects.insert_or_assign(
        "ц32", Subject{SubjectKindNative, {.native = nativeInt32}});

    for (int i = 0; i < parseResult.тіло->довжина; ++i) {
      const auto& astValue = parseResult.тіло->елементи[i];
      const auto result = compile(scope, astValue);
      if (result.error) {
        std::cout << "Failed" << std::endl;
        std::cout << result.error->message << std::endl;
        return 1;
      }
    }
    std::cout << dumpLL(compiler->m) << std::endl;
  } else {
    std::cout << "Failed" << std::endl;
    std::cout << parseResult.помилка->повідомлення << std::endl;
  }
  return 0;
}

CompilationResult compile(Scope* scope, АСДЗначення* astValue) {
  if (astValue->вид == АСДВидСтворитиСтруктуру) {
    const auto data = static_cast<АСДДаніСтворитиСтруктуру*>(astValue->дані);

    const auto structure = new Structure();
    structure->name = data->ідентифікатор->значення;
    structure->xlType =
        xl_create_struct(scope->compiler->m, data->ідентифікатор->значення);
    scope->subjects.insert_or_assign(
        data->ідентифікатор->значення,
        Subject{SubjectKindStructure, {.structure = structure}});

    for (int j = 0; j < data->кількість_параметрів; ++j) {
      const auto параметр = data->параметри[j];
      const auto typeResult = compileReturnType(scope, параметр->тип);
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
    xl_set_struct_fields(scope->compiler->m, structure->xlType, fields.size(),
                         fields.data());

    return {Subject{SubjectKindStructure, {.structure = structure}}, nullptr};
  } else if (astValue->вид == АСДВидСтворитиДію) {
    const auto data = static_cast<АСДДаніСтворитиДію*>(astValue->дані);

    const auto diia = new Diia();
    diia->name = data->ідентифікатор->значення;

    for (int j = 0; j < data->кількість_параметрів; ++j) {
      const auto параметр = data->параметри[j];
      const auto typeResult = compileReturnType(scope, параметр->тип);
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
          compileReturnType(scope, data->тип_результату);
      if (returnTypeResult.error) {
        return {{}, returnTypeResult.error};
      }
      diia->returnType = returnTypeResult.type;

      diia->xlFunction = xl_declare_function(
          scope->compiler->m, data->ідентифікатор->значення,
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

CompilationTypeResult compileReturnType(Scope* scope, АСДЗначення* astValue) {
  const auto result = compile(scope, astValue);
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