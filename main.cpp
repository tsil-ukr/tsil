#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
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
#include "parser/parser.h"

using namespace llvm;

static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;
static std::map<std::string, Value*> NamedValues;
//
// Value* LogErrorV(const char* Str) {
//  LogError(Str);
//  return nullptr;
//}
//
// Value* NumberExprAST::codegen() {
//  return ConstantFP::get(*TheContext, APFloat(Val));
//}
//
// Value* VariableExprAST::codegen() {
//  // Look this variable up in the function.
//  Value* V = NamedValues[Name];
//  if (!V)
//    return LogErrorV("Unknown variable name");
//  return V;
//}
//
// Value* BinaryExprAST::codegen() {
//  Value* L = LHS->codegen();
//  Value* R = RHS->codegen();
//  if (!L || !R)
//    return nullptr;
//
//  switch (Op) {
//    case '+':
//      return Builder->CreateFAdd(L, R, "addtmp");
//    case '-':
//      return Builder->CreateFSub(L, R, "subtmp");
//    case '*':
//      return Builder->CreateFMul(L, R, "multmp");
//    case '<':
//      L = Builder->CreateFCmpULT(L, R, "cmptmp");
//      // Convert bool 0/1 to double 0.0 or 1.0
//      return Builder->CreateUIToFP(L, Type::getDoubleTy(*TheContext),
//                                   "booltmp");
//    default:
//      return LogErrorV("invalid binary operator");
//  }
//}
//
// Value* CallExprAST::codegen() {
//  // Look up the name in the global module table.
//  Function* CalleeF = TheModule->getFunction(Callee);
//  if (!CalleeF)
//    return LogErrorV("Unknown function referenced");
//
//  // If argument mismatch error.
//  if (CalleeF->arg_size() != Args.size())
//    return LogErrorV("Incorrect # arguments passed");
//
//  std::vector<Value*> ArgsV;
//  for (unsigned i = 0, e = Args.size(); i != e; ++i) {
//    ArgsV.push_back(Args[i]->codegen());
//    if (!ArgsV.back())
//      return nullptr;
//  }
//
//  return Builder->CreateCall(CalleeF, ArgsV, "calltmp");
//}
//
// Function* PrototypeAST::codegen() {
//  // Make the function type:  double(double,double) etc.
//  std::vector<Type*> Doubles(Args.size(), Type::getDoubleTy(*TheContext));
//  FunctionType* FT =
//      FunctionType::get(Type::getDoubleTy(*TheContext), Doubles, false);
//
//  Function* F =
//      Function::Create(FT, Function::ExternalLinkage, Name, TheModule.get());
//
//  // Set names for all arguments.
//  unsigned Idx = 0;
//  for (auto& Arg : F->args())
//    Arg.setName(Args[Idx++]);
//
//  return F;
//}
//
// Function* FunctionAST::codegen() {
//  // First, check for an existing function from a previous 'extern'
//  declaration. Function* TheFunction =
//  TheModule->getFunction(Proto->getName());
//
//  if (!TheFunction)
//    TheFunction = Proto->codegen();
//
//  if (!TheFunction)
//    return nullptr;
//
//  // Create a new basic block to start insertion into.
//  BasicBlock* BB = BasicBlock::Create(*TheContext, "entry", TheFunction);
//  Builder->SetInsertPoint(BB);
//
//  // Record the function arguments in the NamedValues map.
//  NamedValues.clear();
//  for (auto& Arg : TheFunction->args())
//    NamedValues[std::string(Arg.getName())] = &Arg;
//
//  if (Value* RetVal = Body->codegen()) {
//    // Finish off the function.
//    Builder->CreateRet(RetVal);
//
//    // Validate the generated code, checking for consistency.
//    verifyFunction(*TheFunction);
//
//    return TheFunction;
//  }
//
//  // Error reading body, remove function.
//  TheFunction->eraseFromParent();
//  return nullptr;
//}
//

static void InitializeModule() {
  TheContext = std::make_unique<LLVMContext>();
  TheModule = std::make_unique<Module>("tsil module", *TheContext);
  Builder = std::make_unique<IRBuilder<>>(*TheContext);
}

struct CompilationScope {
  std::map<std::string, Value*> variables;

  inline bool has_variable(const std::string& name) {
    return variables.find(name) != variables.end();
  }

  inline Value* get_variable(const std::string& name) {
    return variables.at(name);
  }

  inline void set_variable(const std::string& name, Value* value) {
    variables.insert_or_assign(name, value);
  }
};

struct CompilerError {
  std::string message;
};

struct CompilerResult {
  Value* result;
  CompilerError* error;
};

CompilerResult ok(Value* result) {
  return {result, nullptr};
}

CompilerResult error(const std::string& message) {
  return {nullptr, new CompilerError{message}};
}

CompilerResult compile_ast_value(CompilationScope* scope,
                                 const tsil::ast::ASTValue* ast_value) {
  if (ast_value->kind == tsil::ast::KindDefineNode) {
    const auto define_node = ast_value->data.DefineNode;
    if (scope->has_variable(define_node->id)) {
      return error("Variable already defined");
    }
    auto value_result = compile_ast_value(scope, define_node->value);
    if (value_result.error) {
      return value_result;
    }
    scope->set_variable(define_node->id, value_result.result);
    return ok(nullptr);
  }
  if (ast_value->kind == tsil::ast::KindAssignNode) {
    const auto diia_node = ast_value->data.DiiaNode;
    return error("Not implemented");
  }
  if (ast_value->kind == tsil::ast::KindNumberNode) {
    const auto number_node = ast_value->data.NumberNode;
    return ok(
        ConstantFP::get(*TheContext, APFloat(std::stod(number_node->value))));
  }
  if (ast_value->kind == tsil::ast::KindStringNode) {
    const auto string_node = ast_value->data.StringNode;
    return ok(Builder->CreateGlobalStringPtr(string_node->value));
  }
  if (ast_value->kind == tsil::ast::KindIdentifierNode) {
    const auto identifier_node = ast_value->data.IdentifierNode;
    if (!scope->has_variable(identifier_node->name)) {
      return error("Variable not defined");
    }
    return ok(scope->get_variable(identifier_node->name));
  }
  if (ast_value->kind == tsil::ast::KindDiiaNode) {
    const auto diia_node = ast_value->data.DiiaNode;
    FunctionType* FT = FunctionType::get(Type::getVoidTy(*TheContext), false);
    Function* F = Function::Create(FT, Function::ExternalLinkage, diia_node->id,
                                   TheModule.get());
    BasicBlock* BB = BasicBlock::Create(*TheContext, "entry", F);
    Builder->SetInsertPoint(BB);

    for (const auto& body : diia_node->body) {
      auto result = compile_ast_value(scope, body);
      if (result.error) {
        return result;
      }
    }
    Builder->CreateRet(nullptr);
    return ok(nullptr);
  }
  if (ast_value->kind == tsil::ast::KindCallNode) {
    const auto call_node = ast_value->data.CallNode;
    const auto name = call_node->value->data.IdentifierNode->name;
    Function* F = TheModule->getFunction(name);
    if (!F) {
      return error("Unknown function referenced");
    }
    if (!F->isVarArg()) {
      if (F->arg_size() != call_node->args.size()) {
        return error("Incorrect # arguments passed");
      }
    }
    std::vector<Value*> ArgsV;
    for (const auto& arg : call_node->args) {
      auto arg_result = compile_ast_value(scope, arg);
      if (arg_result.error) {
        return arg_result;
      }
      ArgsV.push_back(arg_result.result);
    }
    if (F->getReturnType() == Type::getVoidTy(*TheContext)) {
      return ok(Builder->CreateCall(F, ArgsV));
    }
    return ok(Builder->CreateCall(F, ArgsV, "calltmp"));
  }
  if (ast_value->kind == tsil::ast::KindIfNode) {
    const auto if_node = ast_value->data.IfNode;
    return error("Not implemented");
  }
  if (ast_value->kind == tsil::ast::KindStructureNode) {
    const auto structure_node = ast_value->data.StructureNode;
    return error("Not implemented");
  }
  return error("Unknown ASTValue kind: " +
               ast_value_kind_to_string(ast_value->kind));
}

void path_to_object_name(const std::string& path, std::string& object_name) {
  const auto canonical_path = std::filesystem::canonical(path).string();

  const auto fs_path = std::filesystem::path(canonical_path);
  if (!fs_path.has_filename()) {
    return;
  }

  const auto name = fs_path.stem().string();

  object_name = name + ".o";
}

int main(int argc, char** argv) {
  InitializeModule();

  const auto args = std::vector<std::string>(argv, argv + argc);
  const auto& path = args[1];

  std::string code;

  std::ifstream file(path);
  std::string line;
  while (std::getline(file, line)) {
    code += line + "\n";
  }

  FunctionType* FT = FunctionType::get(Type::getInt32Ty(*TheContext),
                                       {Type::getInt8PtrTy(*TheContext)}, true);
  Function* F = Function::Create(FT, Function::ExternalLinkage, "printf",
                                 TheModule.get());

  FunctionType* pFT = FunctionType::get(
      Type::getVoidTy(*TheContext), {Type::getInt8PtrTy(*TheContext)}, false);
  Function* pF =
      Function::Create(FT, Function::ExternalLinkage, "друк", TheModule.get());

  const auto parser_result = tsil::parser::parse(code);
  if (parser_result.program_node) {
    const auto scope = new CompilationScope();
    for (const auto& ast_value : parser_result.program_node->body) {
      if (ast_value == nullptr) {
        continue;
      }
      if (ast_value->kind == tsil::ast::KindNone) {
        continue;
      }
      const auto result = compile_ast_value(scope, ast_value);
      if (result.error) {
        std::cerr << "Failed to compile: " << result.error->message
                  << std::endl;
        return 1;
      }
    }
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    TheModule->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    if (!Target) {
      errs() << Error;
      return 1;
    }

    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto TheTargetMachine = Target->createTargetMachine(
        TargetTriple, CPU, Features, opt, Reloc::PIC_);

    TheModule->setDataLayout(TheTargetMachine->createDataLayout());

    std::string name;
    path_to_object_name(path, name);

    std::error_code EC;
    raw_fd_ostream dest(name, EC, sys::fs::OF_None);

    if (EC) {
      errs() << "Could not open file: " << EC.message();
      return 1;
    }

    legacy::PassManager pass;
    auto FileType = CodeGenFileType::CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
      errs() << "TheTargetMachine can't emit a file of this type";
      return 1;
    }

    pass.run(*TheModule);
    dest.flush();
  } else {
    std::cerr << "Failed to parse: " << parser_result.errors[0].message
              << std::endl;
    return 1;
  }

  return 0;
}