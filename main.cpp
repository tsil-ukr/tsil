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
#include "compiler/compiler.h"
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

using namespace llvm;
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

void path_to_splav_name(const std::string& path,
                        std::string& object_name,
                        std::string& danis_name) {
  const auto canonical_path = std::filesystem::canonical(path).string();

  const auto fs_path = std::filesystem::path(canonical_path);
  if (!fs_path.has_filename()) {
    return;
  }

  const auto name = fs_path.stem().string();

  object_name = name + ".сплав";
  danis_name = name + ".даніс";
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);
  const auto& command = args[1];
  const auto& path = args[2];

  std::string splav_name;
  std::string danis_name;
  path_to_splav_name(path, splav_name, danis_name);

  std::string code;

  std::ifstream file(path);
  std::string line;
  while (std::getline(file, line)) {
    code += line + "\n";
  }

  code += "\n\nсплав ц32 main() { вернути старт(); }";

  const auto parser_result = tsil::parser::parse(code);
  if (parser_result.program_node) {
    const auto state = new tsil::compiler::CompilationState();

    state->Context = new LLVMContext();
    state->Module = new Module(splav_name, *state->Context);
    state->Builder = new IRBuilder<>(*state->Context);

    state->globalScope = new tsil::compiler::CompilationScope();
    state->globalScope->state = state;

    const auto voidType = new tsil::compiler::Type();
    voidType->lltype = Type::getVoidTy(*state->Context);
    state->globalScope->types["обʼєкт"] = voidType;

    const auto int8Type = new tsil::compiler::Type();
    int8Type->lltype = Type::getInt8Ty(*state->Context);
    state->globalScope->types["ц8"] = int8Type;

    const auto int16Type = new tsil::compiler::Type();
    int16Type->lltype = Type::getInt16Ty(*state->Context);
    state->globalScope->types["ц16"] = int16Type;

    const auto int32Type = new tsil::compiler::Type();
    int32Type->lltype = Type::getInt32Ty(*state->Context);
    state->globalScope->types["ц32"] = int32Type;

    const auto int64Type = new tsil::compiler::Type();
    int64Type->lltype = Type::getInt64Ty(*state->Context);
    state->globalScope->types["ц64"] = int64Type;

    const auto floatType = new tsil::compiler::Type();
    floatType->lltype = Type::getFloatTy(*state->Context);
    state->globalScope->types["д32"] = floatType;

    const auto doubleType = new tsil::compiler::Type();
    doubleType->lltype = Type::getDoubleTy(*state->Context);
    state->globalScope->types["д64"] = doubleType;

    for (const auto& ast_value : parser_result.program_node->body) {
      if (ast_value == nullptr) {
        continue;
      }
      if (ast_value->kind == tsil::ast::KindNone) {
        continue;
      }
      const auto result = state->globalScope->compile_ast_value(ast_value);
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
    state->Module->setTargetTriple(TargetTriple);

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

    state->Module->setDataLayout(TheTargetMachine->createDataLayout());

    std::error_code EC;
    raw_fd_ostream dest(splav_name, EC, sys::fs::OF_None);

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

    pass.run(*state->Module);
    dest.flush();
  } else {
    std::cerr << "Failed to parse: " << parser_result.errors[0].message
              << std::endl;
    return 1;
  }

  return 0;
}