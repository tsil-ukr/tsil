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

    code += "\n\nекстерн ц32 main() { вернути старт(); }";

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
      state->globalScope->types["комірка"] = voidType;

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

      const auto uint8Type = new tsil::compiler::Type();
      uint8Type->lltype = Type::getInt8Ty(*state->Context);
      state->globalScope->types["б8"] = uint8Type;

      const auto uint16Type = new tsil::compiler::Type();
      uint16Type->lltype = Type::getInt16Ty(*state->Context);
      state->globalScope->types["б16"] = uint16Type;

      const auto uint32Type = new tsil::compiler::Type();
      uint32Type->lltype = Type::getInt32Ty(*state->Context);
      state->globalScope->types["б32"] = uint32Type;

      const auto uint64Type = new tsil::compiler::Type();
      uint64Type->lltype = Type::getInt64Ty(*state->Context);
      state->globalScope->types["б64"] = uint64Type;

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

      mkdir("./сплав", 0777);

      std::ofstream buda;
      buda.open("./сплав/буда");
      buda << "пакувальник=clang++\n";
      buda << "вихід=./сплав/" + exec_name + "\n";
      buda << "обʼєкти=./сплав/" + splav_name;
      if (args.size() > 4) {
        auto begin = args.begin() + 4;
        auto end = args.end();
        buda << " ";
        for (auto it = begin; it != end; ++it) {
          buda << *it;
          if (it + 1 != end) {
            buda << " ";
          }
        }
      }
      buda << "\n";
      buda.close();

      std::error_code EC;
      raw_fd_ostream dest("./сплав/" + splav_name, EC, sys::fs::OF_None);

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

      pass.run(*state->Module);
      dest.flush();
    } else {
      std::cerr << "Failed to parse: " << parser_result.errors[0].message
                << std::endl;
      return 1;
    }
  } else if (command == "збудувати") {
    const auto buda_path = "./сплав/буда";
    std::ifstream buda_file(buda_path);
    if (!buda_file.is_open()) {
      std::cerr << "Не вдалось прочитати файл: " << buda_path << std::endl;
      return 1;
    }
    std::string buda_data;
    std::string line;
    while (std::getline(buda_file, line)) {
      buda_data += line + "\n";
    }
    std::unordered_map<std::string, std::string> buda;
    parse_buda(buda_data, buda);
    const auto compiler = buda["пакувальник"];
    const auto exec_name = buda["вихід"];
    const auto objects = buda["обʼєкти"];
    FILE* pipe = popen(
        std::string(compiler + " -o " + exec_name + " " + objects).c_str(),
        "r");
    if (pipe) {
      char buffer[128];
      while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
          // Process output line by line (here, printing)
          printf("%s", buffer);
        }
      }
      pclose(pipe);
    }
  }

  return 0;
}