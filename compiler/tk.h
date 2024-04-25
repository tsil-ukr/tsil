#include <map>
#include "parser.h"
#include "x.h"

namespace tsil::tk {
  struct Compiler;
  struct CompilerError;
  struct CompilerResult;
  struct Scope;
  struct Type;

  void str_replace_all(std::string& str,
                       const std::string& from,
                       const std::string& to);
  bool str_contains(const std::string& str, const std::string& substr);

  std::string getTsilAstBinaryOpSymbol(tsil::ast::BinaryOp op);

  std::string tsilNumberToLLVMNumber(const std::string& value);

  std::string tsilStringToLLVMString(const std::string& value);

  struct Compiler {
    x::Module* xModule = nullptr;
    Scope* globalScope = nullptr;

    Type* voidType = nullptr;
    Type* pointerType = nullptr;
    Type* int1Type = nullptr;
    Type* int8Type = nullptr;
    Type* int32Type = nullptr;
    Type* int64Type = nullptr;
    Type* floatType = nullptr;
    Type* doubleType = nullptr;
    Type* uint8Type = nullptr;
    Type* uint32Type = nullptr;
    Type* uint64Type = nullptr;
    Type* textType = nullptr;

    x::Value* callocXValue = nullptr;
    x::Value* mallocXValue = nullptr;
    x::Value* reallocXValue = nullptr;
    x::Value* freeXValue = nullptr;

    x::Value* ensureCallocConnected();
    x::Value* ensureMallocConnected();
    x::Value* ensureReallocConnected();
    x::Value* ensureFreeConnected();
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
    static CompilerError* subjectIsNotRuntimeValue(
        tsil::ast::ASTValue* ast_value);
    static CompilerError* typesOfInstructionDifferent(
        tsil::ast::ASTValue* astValue,
        Type* leftType,
        Type* rightType);
    static CompilerError* typeIsNotComparable(tsil::ast::ASTValue* astValue,
                                              Type* type);
    static CompilerError* typeIsNotArithmetical(tsil::ast::ASTValue* astValue,
                                                Type* type);
    static CompilerError* typeIsNotBitwisible(tsil::ast::ASTValue* astValue,
                                              Type* type);
    static CompilerError* notEnoughCallArguments(tsil::ast::ASTValue* astValue);
    static CompilerError* tooManyCallArguments(tsil::ast::ASTValue* astValue);
    static CompilerError* notEnoughCallTemplateArguments(
        tsil::ast::ASTValue* astValue);
    static CompilerError* tooManyCallTemplateArguments(
        tsil::ast::ASTValue* astValue);
    static CompilerError* invalidArgumentType(tsil::ast::ASTValue* astValue,
                                              const std::string& name,
                                              Type* expected,
                                              Type* got);
    static CompilerError* invalidPropertyType(tsil::ast::ASTValue* astValue,
                                              const std::string& name,
                                              Type* expected,
                                              Type* got);
    static CompilerError* cannotAccessNonPointer(tsil::ast::ASTValue* astValue,
                                                 Type* type);
    static CompilerError* tooManyConstructorArguments(
        tsil::ast::ASTValue* astValue);
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

  enum CompilerSubjectResultWhat {
    CompilerSubjectResultWhatNone,
    CompilerSubjectResultWhatVariable,
    CompilerSubjectResultWhatDiia,
  };

  struct CompilerSubjectResult {
    CompilerSubjectResultWhat what;
    Type* type;
    x::Value* xValue;
    CompilerError* error;
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
    bool hasNonVariableAndNonDiiaSubject(const std::string& name) const;

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

    CompilerSubjectResult getSubjectByName(
        ast::ASTValue* contextAstValue,
        const std::string& name,
        const std::vector<Type*>& genericValues);

    CompilerValueResult compileCall(tsil::x::Function* xFunction,
                                    tsil::x::FunctionBlock* xBlock,
                                    ast::ASTValue* astValue);
    CompilerValueResult compileCall_Pointer(tsil::x::Function* xFunction,
                                            tsil::x::FunctionBlock* xBlock,
                                            ast::ASTValue* astValue);
    CompilerValueResult compileCall_Value(tsil::x::Function* xFunction,
                                          tsil::x::FunctionBlock* xBlock,
                                          ast::ASTValue* astValue);
    CompilerValueResult compileCall_Allocate(tsil::x::Function* xFunction,
                                             tsil::x::FunctionBlock* xBlock,
                                             ast::ASTValue* astValue);
    CompilerValueResult compileCall_Reallocate(tsil::x::Function* xFunction,
                                               tsil::x::FunctionBlock* xBlock,
                                               ast::ASTValue* astValue);
    CompilerValueResult compileCall_Free(tsil::x::Function* xFunction,
                                         tsil::x::FunctionBlock* xBlock,
                                         ast::ASTValue* astValue);

    CompilerValueResult compileNumber(tsil::x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      ast::ASTValue* astValue);
    CompilerValueResult compileString(tsil::x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      ast::ASTValue* astValue);
    CompilerValueResult compileLoad(tsil::x::Function* xFunction,
                                    tsil::x::FunctionBlock* xBlock,
                                    ast::ASTValue* astValue,
                                    const std::vector<Type*>& genericValues);
    CompilerValueResult compileAs(tsil::x::Function* xFunction,
                                  tsil::x::FunctionBlock* xBlock,
                                  ast::ASTValue* astValue);
    CompilerValueResult compileBinary(tsil::x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      ast::ASTValue* astValue);
    CompilerValueResult compileConstructor(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue);
    CompilerValueResult compileAccess(tsil::x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      ast::ASTValue* astValue,
                                      bool load);
    CompilerResult compileSet(tsil::x::Function* xFunction,
                              tsil::x::FunctionBlock* xBlock,
                              ast::ASTValue* astValue);

    CompilerValueResult compileGet(tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   ast::ASTValue* astValue,
                                   bool load);
    CompilerValueResult compileValue(x::Function* xFunction,
                                     tsil::x::FunctionBlock* xBlock,
                                     ast::ASTValue* astValue,
                                     const std::vector<Type*>& genericValues);

    x::Value* compileSoftCast(tsil::x::Function* xFunction,
                              tsil::x::FunctionBlock* xBlock,
                              Type* type,
                              x::Value* xValue,
                              Type* targetType);
    x::Value* compileHardCast(tsil::x::Function* xFunction,
                              tsil::x::FunctionBlock* xBlock,
                              Type* type,
                              x::Value* xValue,
                              Type* targetType);

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
    TypeTypeArray,
    TypeTypeStructureInstance,
    TypeTypeDiia,
  };

  struct TypeStructureField {
    int index;
    Type* type;
    std::string name;
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
    // array
    Type* arrayOf = nullptr;
    size_t arraySize;
    // pointer
    Type* pointerTo = nullptr;
    // structure
    std::unordered_map<std::string, TypeStructureField> structureInstanceFields;
    // diia
    ast::DiiaLinkage linkage;
    std::vector<TypeDiiaParameter> diiaParameters;
    bool diiaIsVariadic;
    Type* diiaReturnType = nullptr;
    // x
    x::Type* xType = nullptr;

    bool equals(Type* other);
    bool isPointer();
    bool isArray();
    std::string getFullName();
    Type* getPointerType(Scope* scope);
    Type* getArrayType(Scope* scope, size_t size);
    size_t getBytesSize(Scope* scope);
    bool isComparable(Scope* scope);
    bool isUnsigned(Scope* scope);
    bool isFloating(Scope* scope);
    bool isArithmetical(Scope* scope);
    bool isBitwisible(Scope* scope);
  };
} // namespace tsil::tk