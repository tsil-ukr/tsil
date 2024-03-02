#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "parser/parser.h"
// #include "llvm/ADT/APFloat.h"
// #include "llvm/ADT/STLExtras.h"
// #include "llvm/IR/BasicBlock.h"
// #include "llvm/IR/Constants.h"
// #include "llvm/IR/DerivedTypes.h"
// #include "llvm/IR/Function.h"
// #include "llvm/IR/IRBuilder.h"
// #include "llvm/IR/LLVMContext.h"
// #include "llvm/IR/Module.h"
// #include "llvm/IR/Type.h"
// #include "llvm/IR/Verifier.h"
//
// using namespace llvm;
//
// void LogError(const char* Str) {
//  fprintf(stderr, "Error: %s\n", Str);
//}
//
// void LogErrorP(const char* Str) {
//  LogError(Str);
//}
//
////===----------------------------------------------------------------------===//
//// Code Generation
////===----------------------------------------------------------------------===//
//
// static std::unique_ptr<LLVMContext> TheContext;
// static std::unique_ptr<Module> TheModule;
// static std::unique_ptr<IRBuilder<>> Builder;
// static std::map<std::string, Value*> NamedValues;
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
////===----------------------------------------------------------------------===//
//// Top-Level parsing and JIT Driver
////===----------------------------------------------------------------------===//
//
// static void InitializeModule() {
//  // Open a new context and module.
//  TheContext = std::make_unique<LLVMContext>();
//  TheModule = std::make_unique<Module>("my cool jit", *TheContext);
//
//  // Create a new builder for the module.
//  Builder = std::make_unique<IRBuilder<>>(*TheContext);
//}
//
// static void HandleDefinition() {
//  if (auto FnAST = ParseDefinition()) {
//    if (auto* FnIR = FnAST->codegen()) {
//      fprintf(stderr, "Read function definition:");
//      FnIR->print(errs());
//      fprintf(stderr, "\n");
//    }
//  } else {
//    // Skip token for error recovery.
//    getNextToken();
//  }
//}
//
// static void HandleExtern() {
//  if (auto ProtoAST = ParseExtern()) {
//    if (auto* FnIR = ProtoAST->codegen()) {
//      fprintf(stderr, "Read extern: ");
//      FnIR->print(errs());
//      fprintf(stderr, "\n");
//    }
//  } else {
//    // Skip token for error recovery.
//    getNextToken();
//  }
//}
//
// static void HandleTopLevelExpression() {
//  // Evaluate a top-level expression into an anonymous function.
//  if (auto FnAST = ParseTopLevelExpr()) {
//    if (auto* FnIR = FnAST->codegen()) {
//      fprintf(stderr, "Read top-level expression:");
//      FnIR->print(errs());
//      fprintf(stderr, "\n");
//
//      // Remove the anonymous expression.
//      FnIR->eraseFromParent();
//    }
//  } else {
//    // Skip token for error recovery.
//    getNextToken();
//  }
//}
//
///// top ::= definition | external | expression | ';'
// static void MainLoop() {
//   while (true) {
//     fprintf(stderr, "ready> ");
//     switch (CurTok) {
//       case tok_eof:
//         return;
//       case ';': // ignore top-level semicolons.
//         getNextToken();
//         break;
//       case tok_def:
//         HandleDefinition();
//         break;
//       case tok_extern:
//         HandleExtern();
//         break;
//       default:
//         HandleTopLevelExpression();
//         break;
//     }
//   }
// }

int main() {
  //  // Install standard binary operators.
  //  // 1 is lowest precedence.
  //  BinopPrecedence['<'] = 10;
  //  BinopPrecedence['+'] = 20;
  //  BinopPrecedence['-'] = 20;
  //  BinopPrecedence['*'] = 40; // highest.
  //
  //  // Prime the first token.
  //  fprintf(stderr, "ready> ");
  //  getNextToken();
  //
  //  // Make the module, which holds all the code.
  //  InitializeModule();
  //
  //  // Run the main "interpreter loop" now.
  //  MainLoop();
  //
  //  // Print out all of the generated code.
  //  TheModule->print(errs(), nullptr);

  std::string code = R"(
дія а()
  вернути 1
кінець
)";

  const auto parser_result = tsil::parser::parse(code);
  if (parser_result.ast_value) {
    std::cout << "Parsed successfully" << std::endl;
  } else {
    std::cout << "Failed to parse" << std::endl;
  }

  std::cout << "Hello, World!" << std::endl;

  return 0;
}