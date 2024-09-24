#include "parser.h"
#include "xl.h"

#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

struct Type;
struct Parameter;
struct Native;
struct Structure;
struct Diia;
struct Section;
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

struct Section {
  std::string name;
};

struct Tsil {
  std::string name;
  Type type;
};

enum SubjectKind {
  SubjectKindNative,
  SubjectKindStructure,
  SubjectKindDiia,
  SubjectKindSection,
  SubjectKindTsil,
};

struct Subject {
  SubjectKind kind;
  union {
    Native* native;
    Structure* structure;
    Diia* diia;
    Section* section;
    Tsil* tsil;
  } d;
};

struct Scope {
  Scope* parent;
  std::unordered_map<std::string, Subject> subjects;
};

Scope* createScope(Scope* parent);
std::optional<Subject> findSubject(Scope* scope, const std::string& name);
void setSubject(Scope* scope, const std::string& name, Subject subject);

CompilationResult compile(Compiler* compiler,
                          Scope* scope,
                          АСДЗначення* astValue);
CompilationTypeResult compileAndReturnType(Compiler* compiler,
                                           Scope* scope,
                                           АСДЗначення* astValue);
CompilationError* compileSectionBody(Compiler* compiler,
                                     Scope* scope,
                                     Section* section,
                                     СписокАСДЗначень тіло);
CompilationError* compileDiiaBody(Compiler* compiler,
                                  Scope* scope,
                                  Diia* diia,
                                  СписокАСДЗначень тіло);

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
