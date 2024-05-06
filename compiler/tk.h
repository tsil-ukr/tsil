#include <map>
#include "parser.h"
#include "x.h"

#define BUG()                                                       \
  std::cout << "BUG: " << __FILE__ << ":" << __LINE__ << std::endl; \
  exit(1);
#define WTF() std::cout << "WTF: " << __FILE__ << ":" << __LINE__ << std::endl;

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

  struct TakeResult {
    std::string error;
    CompilerError* compilerError;
  };

  struct Compiler {
    x::Module* xModule = nullptr;
    Scope* globalScope = nullptr;

    Type* voidType = nullptr;
    Type* pointerType = nullptr;

    Type* int1Type = nullptr;

    Type* int8Type = nullptr;
    Type* int32Type = nullptr;
    Type* int64Type = nullptr;
    Type* integerType = nullptr;

    Type* d32Type = nullptr;
    Type* d64Type = nullptr;
    Type* doubleType = nullptr;

    Type* uint8Type = nullptr;
    Type* uint32Type = nullptr;
    Type* uint64Type = nullptr;
    Type* positiveType = nullptr;

    x::Value* callocXValue = nullptr;
    x::Value* mallocXValue = nullptr;
    x::Value* reallocXValue = nullptr;
    x::Value* freeXValue = nullptr;

    std::set<std::string> tookDefinitions;

    x::Value* ensureCallocConnected();
    x::Value* ensureMallocConnected();
    x::Value* ensureReallocConnected();
    x::Value* ensureFreeConnected();

    std::pair<std::string, bool> readFile(const std::string& path);
    bool fileExist(const std::string& path);
    TakeResult takeDefinitions(const std::string& path);
    CompilerError* compileProgramNode(tsil::ast::ProgramNode* programNode);
  };

  struct SecondCompilerError {
    size_t line;
    size_t column;
  };

  struct Location {
    size_t start_line;
    size_t start_column;
    size_t end_line;
    size_t end_column;
  };

  struct CompilerError {
    size_t line;
    size_t column;
    std::string message;
    SecondCompilerError* secondError = nullptr;

    static CompilerError* fromParserError(tsil::parser::TsilParserError* error);
    static CompilerError* fromASTValue(tsil::ast::ASTValue* ast_value,
                                       const std::string& message);
    static CompilerError* fromLocation(const Location& location,
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

  struct BodyCompilerResult {
    x::FunctionBlock* xBlock;
    x::FunctionBlock* xExitBlock;
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

  struct CompilerRuntimeSubjectResult {
    Type* type;
    x::Value* xValue;
    CompilerError* error;
  };

  struct StructureField {
    std::string name;
    ast::ASTValue* type;
  };

  struct Structure {
    std::string name;
    std::vector<std::string> genericDefinitions;
    std::vector<StructureField> fields;

    std::map<std::vector<Type*>, Type*> bakedTypes; // genericValues => type

    BakedTypeResult bakeType(Scope* scope,
                             const std::vector<Type*>& genericValues);
    std::string fillBakedTypesWithFields();
  };

  struct DiiaParameter {
    std::string name;
    ast::ASTValue* type;
  };

  struct BakedDiia {
    Type* type;
    x::Value* xValue;
    x::Function* xFunction;
  };

  struct Diia {
    bool isDeclaration;
    ast::DiiaLinkage linkage;
    std::string name;
    std::vector<std::string> genericDefinitions;
    std::vector<DiiaParameter> parameters;
    bool isVariadic;
    ast::ASTValue* returnType;
    std::vector<ast::ASTValue*> body;

    std::map<std::vector<Type*>, BakedDiia>
        bakedDiias; // genericValues => (type, xValue)

    BakedDiiaResult bakeDiia(Scope* scope,
                             const std::vector<Type*>& genericValues);
    CompilerError* fillBakedDiiasWithBodies();
  };

  struct Scope {
    Compiler* compiler;
    Scope* parent;

    std::map<std::string, Type*> predefinedTypes;
    std::map<std::string, Structure*> structures;
    std::map<std::string, Diia*> diias;

    std::map<std::string, std::pair<Type*, x::Value*>>
        variables; // name => (type, xValue)

    bool hasPredefinedType(const std::string& name) const;
    Type* getPredefinedType(const std::string& name);

    bool hasStructure(const std::string& name) const;
    Structure* getStructure(const std::string& name);

    bool hasDiia(const std::string& name) const;
    Diia* getDiia(const std::string& name);

    bool hasVariable(const std::string& name) const;
    std::pair<Type*, x::Value*> getVariable(const std::string& name);

    CompilerRuntimeSubjectResult getRuntimeSubjectByIdentifierNodeAstValue(
        ast::ASTValue* astValue);

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
    CompilerValueResult compileCall_Sizeof(tsil::x::Function* xFunction,
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
                                    ast::ASTValue* astValue);
    CompilerValueResult compileGeneric(tsil::x::Function* xFunction,
                                       tsil::x::FunctionBlock* xBlock,
                                       ast::ASTValue* astValue);
    CompilerValueResult compileAs(tsil::x::Function* xFunction,
                                  tsil::x::FunctionBlock* xBlock,
                                  ast::ASTValue* astValue);
    CompilerValueResult compileBinary(tsil::x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      ast::ASTValue* astValue);
    CompilerValueResult compileConstructor(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue,
                                           bool load);
    CompilerValueResult compileAccessGep(tsil::x::Function* xFunction,
                                         tsil::x::FunctionBlock* xBlock,
                                         ast::ASTValue* astValue);
    CompilerResult compileSet(tsil::x::Function* xFunction,
                              tsil::x::FunctionBlock* xBlock,
                              ast::ASTValue* astValue);
    CompilerResult compileSection(ast::ASTValue* astValue);
    CompilerResult compileBody(const std::vector<ast::ASTValue*>& body);

    CompilerValueResult compileGetGep(tsil::x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      ast::ASTValue* astValue);
    CompilerValueResult compileValue(x::Function* xFunction,
                                     tsil::x::FunctionBlock* xBlock,
                                     ast::ASTValue* astValue);
    CompilerValueResult compileLeft(x::Function* xFunction,
                                    tsil::x::FunctionBlock* xBlock,
                                    ast::ASTValue* astValue);

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

    BodyCompilerResult compileDiiaBody(Type* diiaType,
                                       tsil::x::Function* xFunction,
                                       tsil::x::FunctionBlock* xBlock,
                                       tsil::x::FunctionBlock* xExitBlock,
                                       const std::vector<ast::ASTValue*>& body);
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
    Scope* scopeWithGenerics = nullptr;
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