#include <map>
#include "../../parser/parser.h"
#include "../x.h"

namespace tsil::tk {
  struct Compiler;
  struct CompilerError;
  struct CompilerResult;
  struct Scope;
  struct Type;

  struct Compiler {
    x::Module* xModule = nullptr;
    Scope* globalScope = nullptr;

    Type* voidType = nullptr;
    Type* pointerType = nullptr;
    Type* int8Type = nullptr;
    Type* int32Type = nullptr;
    Type* int64Type = nullptr;
    Type* floatType = nullptr;
    Type* doubleType = nullptr;
    Type* uint8Type = nullptr;
    Type* uint32Type = nullptr;
    Type* uint64Type = nullptr;
    Type* textType = nullptr;
  };

  struct SecondCompilerError {
    size_t line;
    size_t column;
  };

  struct CompilerError {
    size_t line;
    size_t column;
    std::string message;
    SecondCompilerError* secondError = nullptr;

    static CompilerError* fromASTValue(tsil::ast::ASTValue* ast_value,
                                       const std::string& message);
    static CompilerError* subjectAlreadyDefined(tsil::ast::ASTValue* ast_value);
    static CompilerError* subjectNotDefined(tsil::ast::ASTValue* ast_value);
    static CompilerError* subjectIsNotCallable(tsil::ast::ASTValue* ast_value);
    static CompilerError* typesAreNotCompatible(tsil::ast::ASTValue* ast_value,
                                                Type* left,
                                                Type* right);
    static CompilerError* cannotRedefineSubject(tsil::ast::ASTValue* ast_value,
                                                const std::string& name);
    static CompilerError* typeIsNotConstructable(tsil::ast::ASTValue* ast_value,
                                                 Type* type);
    static CompilerError* typeHasNoProperty(tsil::ast::ASTValue* ast_value,
                                            Type* type,
                                            const std::string& name);
  };

  struct CompilerResult {
    CompilerError* error;
  };

  struct CompilerValueResult {
    Type* type;
    x::Value* xValue;
    CompilerError* error;
  };

  struct BakedDiiaResult {
    Type* type;
    x::Value* xValue;
    CompilerError* error;
  };

  struct BakedTypeResult {
    Type* type;
    std::string error;
  };

  struct Scope {
    Compiler* compiler;
    Scope* parent;

    std::map<std::string, ast::ASTValue*> rawDiias; // name => astValue
    std::map<std::pair<std::string, std::vector<Type*>>,
             std::pair<Type*, x::Value*>>
        bakedDiias; // (name, genericValues) => (type, xValue)

    std::map<std::string, ast::ASTValue*> rawTypes; // name => astValue
    std::map<std::pair<std::string, std::vector<Type*>>, Type*>
        bakedTypes; // (name, genericValues) => type

    std::map<std::string, std::pair<Type*, x::Value*>>
        variables; // name => (type, xValue)

    bool hasSubject(const std::string& name) const;

    bool hasRawDiia(const std::string& name) const;
    ast::ASTValue* getRawDiia(const std::string& name);
    bool hasBakedDiia(const std::string& name,
                      const std::vector<Type*>& genericValues) const;
    std::pair<Type*, x::Value*> getBakedDiia(
        const std::string& name,
        const std::vector<Type*>& genericValues);

    bool hasRawType(const std::string& name) const;
    ast::ASTValue* getRawType(const std::string& name);
    bool hasBakedType(const std::string& name,
                      const std::vector<Type*>& genericValues) const;
    Type* getBakedType(const std::string& name,
                       const std::vector<Type*>& genericValues);

    bool hasVariable(const std::string& name) const;
    std::pair<Type*, x::Value*> getVariable(const std::string& name);

    CompilerValueResult compileValueGet(tsil::x::Function* xFunction,
                                        tsil::x::FunctionBlock* xBlock,
                                        ast::ASTValue* astValue,
                                        bool load);
    CompilerValueResult compileValue(x::Function* xFunction,
                                     tsil::x::FunctionBlock* xBlock,
                                     ast::ASTValue* astValue);
    CompilerResult compileDiiaBody(Type* diiaType,
                                   tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   tsil::x::FunctionBlock* xExitBlock,
                                   const std::vector<ast::ASTValue*>& body);
    BakedDiiaResult bakeDiia(ast::ASTValue* fromAstValue,
                             ast::ASTValue* diiaAstValue,
                             const std::vector<Type*>& genericValues);
    BakedTypeResult bakeType(ast::ASTValue* astValue);
  };

  enum TypeType {
    TypeTypeNative,
    TypeTypePointer,
    TypeTypeStructureInstance,
    TypeTypeDiia,
  };

  struct TypeStructureField {
    int index;
    Type* type;
  };

  struct TypeDiiaParameter {
    std::string name;
    Type* type;
    x::Value* xValue;
  };

  struct Type {
    TypeType type;
    std::string name;
    Type* cachedPointerType = nullptr;
    std::vector<Type*> genericValues;
    // pointer
    Type* pointerTo = nullptr;
    // structure
    std::unordered_map<std::string, TypeStructureField> structureInstanceFields;
    // diia
    bool diiaIsExtern;
    std::vector<TypeDiiaParameter> diiaParameters;
    bool diiaIsVariadic;
    Type* diiaReturnType = nullptr;
    // x
    x::Type* xType = nullptr;

    std::string getFullName();
    Type* getPointerType(Scope* scope);
  };
} // namespace tsil::tk