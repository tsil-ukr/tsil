#include <sys/stat.h>
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
                        std::string& exec_name,
                        std::string& object_name,
                        std::string& danis_name) {
  const auto canonical_path = std::filesystem::canonical(path).string();

  const auto fs_path = std::filesystem::path(canonical_path);
  if (!fs_path.has_filename()) {
    return;
  }

  const auto name = fs_path.stem().string();

  exec_name = name;
  object_name = name + ".o";
  danis_name = name + ".даніс";
}

void parse_buda(const std::string& data,
                std::unordered_map<std::string, std::string>& buda) {
  std::istringstream iss(data);
  std::string line;
  while (std::getline(iss, line)) {
    const auto pos = line.find('=');
    if (pos == std::string::npos) {
      continue;
    }
    const auto key = line.substr(0, pos);
    const auto value = line.substr(pos + 1);
    buda[key] = value;
  }
}

int main(int argc, char** argv) {
  auto args = std::vector<std::string>(argv, argv + argc);
  const auto& command = args[1];

  if (command == "сплавити") {
    if (args.size() < 3) {
      std::cerr << "Не вказано модуль!" << std::endl;
      return 1;
    }

    const auto& path = args[2];

    std::ifstream file(path);
    if (!file.is_open()) {
      std::cerr << path << std::endl;
      return 1;
    }

    std::string exec_name;
    std::string splav_name;
    std::string danis_name;
    path_to_splav_name(path, exec_name, splav_name, danis_name);

    std::string code;

    std::string line;
    while (std::getline(file, line)) {
      code += line + "\n";
    }

    const auto parser_result = tsil::parser::parse(code);
    if (parser_result.program_node) {
      const auto state = new tsil::compiler::CompilationState();

      state->Context = new LLVMContext();
      state->Module = new Module(splav_name, *state->Context);
      state->Builder = new IRBuilder<>(*state->Context);

      state->globalScope = new tsil::compiler::CompilationScope();
      state->globalScope->state = state;

      const auto voidType = new tsil::compiler::Type();
      voidType->type = tsil::compiler::TypeTypeNative;
      voidType->name = "комірка";
      voidType->LT = Type::getVoidTy(*state->Context);
      state->types["комірка"] = voidType;
      state->voidType = voidType;

      const auto int8Type = new tsil::compiler::Type();
      int8Type->type = tsil::compiler::TypeTypeNative;
      int8Type->name = "ц8";
      int8Type->LT = Type::getInt8Ty(*state->Context);
      state->types["ц8"] = int8Type;
      state->int8Type = int8Type;

      const auto int16Type = new tsil::compiler::Type();
      int16Type->type = tsil::compiler::TypeTypeNative;
      int16Type->name = "ц16";
      int16Type->LT = Type::getInt16Ty(*state->Context);
      state->types["ц16"] = int16Type;
      state->int16Type = int16Type;

      const auto int32Type = new tsil::compiler::Type();
      int32Type->type = tsil::compiler::TypeTypeNative;
      int32Type->name = "ц32";
      int32Type->LT = Type::getInt32Ty(*state->Context);
      state->types["ц32"] = int32Type;
      state->int32Type = int32Type;

      const auto int64Type = new tsil::compiler::Type();
      int64Type->type = tsil::compiler::TypeTypeNative;
      int64Type->name = "ц64";
      int64Type->LT = Type::getInt64Ty(*state->Context);
      state->types["ц64"] = int64Type;
      state->int64Type = int64Type;

      const auto floatType = new tsil::compiler::Type();
      floatType->type = tsil::compiler::TypeTypeNative;
      floatType->name = "д32";
      floatType->LT = Type::getFloatTy(*state->Context);
      state->types["д32"] = floatType;
      state->floatType = floatType;

      const auto doubleType = new tsil::compiler::Type();
      doubleType->type = tsil::compiler::TypeTypeNative;
      doubleType->name = "д64";
      doubleType->LT = Type::getDoubleTy(*state->Context);
      state->types["д64"] = doubleType;
      state->doubleType = doubleType;

      const auto uint8Type = new tsil::compiler::Type();
      uint8Type->type = tsil::compiler::TypeTypeNative;
      uint8Type->name = "б8";
      uint8Type->LT = Type::getInt8Ty(*state->Context);
      state->types["б8"] = uint8Type;
      state->uint8Type = uint8Type;

      const auto uint16Type = new tsil::compiler::Type();
      uint16Type->type = tsil::compiler::TypeTypeNative;
      uint16Type->name = "б16";
      uint16Type->LT = Type::getInt16Ty(*state->Context);
      state->types["б16"] = uint16Type;
      state->uint16Type = uint16Type;

      const auto uint32Type = new tsil::compiler::Type();
      uint32Type->type = tsil::compiler::TypeTypeNative;
      uint32Type->name = "б32";
      uint32Type->LT = Type::getInt32Ty(*state->Context);
      state->types["б32"] = uint32Type;
      state->uint32Type = uint32Type;

      const auto uint64Type = new tsil::compiler::Type();
      uint64Type->type = tsil::compiler::TypeTypeNative;
      uint64Type->name = "б64";
      uint64Type->LT = Type::getInt64Ty(*state->Context);
      state->types["б64"] = uint64Type;
      state->uint64Type = uint64Type;

      for (const auto& ast_value : parser_result.program_node->body) {
        if (ast_value == nullptr) {
          continue;
        }
        if (ast_value->kind == tsil::ast::KindNone) {
          continue;
        }
        if (ast_value->kind == tsil::ast::KindDiiaNode) {
          const auto result = state->globalScope->compile_diia_node(ast_value);
          if (result.error) {
            std::cerr << "Не вдалось скомпілювати: " << result.error->message
                      << std::endl;
            return 1;
          }
        } else if (ast_value->kind == tsil::ast::KindDiiaDeclarationNode) {
          const auto result =
              state->globalScope->compile_diia_declaration_node(ast_value);
          if (result.error) {
            std::cerr << "Не вдалось скомпілювати: " << result.error->message
                      << std::endl;
            return 1;
          }
        } else if (ast_value->kind == tsil::ast::KindStructureNode) {
          const auto result =
              state->globalScope->compile_structure_node(ast_value);
          if (result.error) {
            std::cerr << "Не вдалось скомпілювати: " << result.error->message
                      << std::endl;
            return 1;
          }
        } else {
          std::cerr << "Невідомий тип вказівки: " << ast_value->kind
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
      raw_fd_ostream dest("./" + splav_name, EC, sys::fs::OF_None);

      if (EC) {
        errs() << "Could not open file: " << EC.message();
        return 1;
      }

      legacy::PassManager pass;
      auto FileType = CodeGenFileType::CGFT_ObjectFile;

      if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr,
                                                FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
      }

      state->Module->print(errs(), nullptr);

      pass.run(*state->Module);
      dest.flush();
    } else {
      std::cerr << "Failed to parse: " << parser_result.errors[0].message
                << std::endl;
      return 1;
    }
  }

  return 0;
}