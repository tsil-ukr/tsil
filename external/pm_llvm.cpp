#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/TargetParser/Host.h>
#include <iostream>

extern "C" {
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define п8 uint8_t
#define п16 uint16_t
#define п32 uint32_t
#define п64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define д32 float
#define д64 double
#define логічне uint8_t
#define позитивне п64
#define ціле ц64
#define дійсне д64
#define ніщо void
#define невідома_адреса void*
#define невідома_памʼять void*
#define памʼять_п8 п8*
#define адреса_памʼять_п8 п8**
#define памʼять_памʼять_п8 п8**
#define адреса_позитивне позитивне*
typedef struct т8 {
  позитивне розмір;
  памʼять_п8 дані;
} т8;
typedef struct ю8 {
  позитивне розмір;
  памʼять_п8 дані;
} ю8;
#define памʼять_т8 т8*
#define памʼять_ю8 ю8*

#define ВИДИМІСТЬ_ВНУТРІШНЯ 1
#define ВИДИМІСТЬ_МІСЦЕВА 2
#define ВИДИМІСТЬ_ЗОВНІШНЯ 3

#define ПРОЦЕСОР_Х86_64 1
#define ПРОЦЕСОР_АРМ64 2

#define СИСТЕМА_ЛІНУКС_ГНУ 1

typedef struct Модуль Модуль;
typedef struct Параметр Параметр;
typedef struct Параметри Параметри;
typedef llvm::Function Інструкція;
typedef llvm::Value Значення;
typedef llvm::Type Тип;
typedef llvm::BasicBlock Крок;
typedef llvm::BranchInst Стрибок;

struct Модуль {
  llvm::LLVMContext* llvmContext;
  llvm::Module* llvmModule;
  llvm::IRBuilder<>* llvmBuilder;
  llvm::TargetMachine* llvmTargetMachine;
};

struct Параметр {
  Тип* тип;
};

struct Параметри {
  позитивне розмір;
  Параметр* дані;
  позитивне вмісткість;
};

void __ПМЛЛВМ__покласти_параметр(Модуль* модуль,
                                 Параметри* параметри,
                                 Параметр* параметр) {
  if (параметри->розмір == параметри->вмісткість) {
    параметри->вмісткість += 1;
    параметри->дані = (Параметр*)realloc(
        параметри->дані, sizeof(Параметр) * параметри->вмісткість);
  }
  параметри->дані[параметри->розмір] = *параметр;
  параметри->розмір += 1;
}

Модуль* __ПМЛЛВМ__створити_модуль(ю8* назва,
                                  позитивне процесор,
                                  позитивне система) {
  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargets();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmParsers();
  llvm::InitializeAllAsmPrinters();

  std::string name((char*)назва->дані, назва->розмір);

  auto модуль = new Модуль();
  модуль->llvmContext = new llvm::LLVMContext();
  модуль->llvmModule = new llvm::Module(name, *модуль->llvmContext);
  модуль->llvmBuilder = new llvm::IRBuilder<>(*модуль->llvmContext);

  std::string targetTriple;

  if (процесор) {
    if (процесор == ПРОЦЕСОР_Х86_64) {
      targetTriple = "x86_64-unknown";
    } else if (процесор == ПРОЦЕСОР_АРМ64) {
      targetTriple = "arm64-unknown";
    } else {
      return nullptr;
    }
    if (система == СИСТЕМА_ЛІНУКС_ГНУ) {
      targetTriple += "-linux-gnu";
    } else {
      return nullptr;
    }
  } else {
    targetTriple = llvm::sys::getDefaultTargetTriple();
  }

  модуль->llvmModule->setTargetTriple(targetTriple);

  std::string Error;
  auto Target = llvm::TargetRegistry::lookupTarget(targetTriple, Error);
  if (!Error.empty()) {
    std::cout << Error << std::endl;
    return nullptr;
  }

  auto CPU = "generic";
  auto Features = "";
  llvm::TargetOptions opt;
  модуль->llvmTargetMachine = Target->createTargetMachine(
      targetTriple, CPU, Features, opt, llvm::Reloc::PIC_);
  модуль->llvmModule->setDataLayout(
      модуль->llvmTargetMachine->createDataLayout());

  return модуль;
}

Інструкція* __ПМЛЛВМ__створити_інструкцію(Модуль* модуль,
                                          позитивне видимість,
                                          ю8* назва,
                                          Параметри* параметри,
                                          Тип* тип_результату) {
  llvm::Function::LinkageTypes linkageType;
  if (видимість == ВИДИМІСТЬ_ЗОВНІШНЯ) {
    linkageType = llvm::Function::ExternalLinkage;
  } else if (видимість == ВИДИМІСТЬ_МІСЦЕВА) {
    linkageType = llvm::Function::ExternalLinkage;
  } else {
    linkageType = llvm::Function::PrivateLinkage;
  }

  std::string name((char*)назва->дані, назва->розмір);

  std::vector<llvm::Type*> llvmParams(параметри->розмір);
  for (int i = 0; i < параметри->розмір; i++) {
    llvmParams[i] = параметри->дані[i].тип;
  }

  auto function = llvm::Function::Create(
      llvm::FunctionType::get(тип_результату == nullptr
                                  ? llvm::Type::getVoidTy(*модуль->llvmContext)
                                  : тип_результату,
                              llvmParams, false),
      linkageType, name, *модуль->llvmModule);

  if (видимість == ВИДИМІСТЬ_МІСЦЕВА) {
    function->setDSOLocal(true);
  }

  return function;
}

Тип* __ПМЛЛВМ__отримати_тип_інструкції(Інструкція* інструкція) {
  return інструкція->getFunctionType();
}

Тип* __ПМЛЛВМ__створити_тип_інструкції(Модуль* модуль,
                                       Параметри* параметри,
                                       Тип* тип_результату) {
  std::vector<llvm::Type*> llvmParams(параметри->розмір);
  for (int i = 0; i < параметри->розмір; i++) {
    llvmParams[i] = параметри->дані[i].тип;
  }

  return llvm::FunctionType::get(тип_результату, llvmParams, false);
}

Значення* __ПМЛЛВМ__отримати_значення_аргумента_інструкції(
    Інструкція* інструкція,
    позитивне позиція) {
  return інструкція->getArg(позиція);
}

Крок* __ПМЛЛВМ__створити_крок(Інструкція* інструкція, ю8* назва) {
  std::string name((char*)назва->дані, назва->розмір);

  return llvm::BasicBlock::Create(інструкція->getContext(), "b", інструкція);
}

логічне __ПМЛЛВМ__перевірити_чи_крок_закінчується_стрибком(Крок* крок) {
  llvm::Instruction* term = крок->getTerminator();

  if (term == nullptr) {
    return false;
  }

  if (llvm::isa<llvm::BranchInst>(term)) {
    return true;
  } else {
    return false;
  }
}

Тип* __ПМЛЛВМ__створити_структуру(Модуль* модуль,
                                  ю8* назва,
                                  Параметри* параметри) {
  std::string name((char*)назва->дані, назва->розмір);

  auto structType = llvm::StructType::create(*модуль->llvmContext, name);

  std::vector<llvm::Type*> llvmFields(параметри->розмір);
  for (int i = 0; i < параметри->розмір; i++) {
    llvmFields[i] = параметри->дані[i].тип;
  }
  structType->setBody(llvmFields);

  return structType;
}

void __ПМЛЛВМ__заповнити_параметри_структури(Тип* тип, Параметри* параметри) {
  std::vector<llvm::Type*> llvmFields(параметри->розмір);
  for (int i = 0; i < параметри->розмір; i++) {
    llvmFields[i] = параметри->дані[i].тип;
  }
  reinterpret_cast<llvm::StructType*>(тип)->setBody(llvmFields);
}

Значення* __ПМЛЛВМ__виконати_дію(Крок* крок,
                                 Тип* тип,
                                 Значення* значення,
                                 позитивне кількість_аргументів,
                                 Значення** аргументи) {
  llvm::IRBuilder<> builder(крок);
  std::vector<llvm::Value*> llvmArguments(кількість_аргументів);
  for (int i = 0; i < кількість_аргументів; i++) {
    llvmArguments[i] = аргументи[i];
  }
  auto type = reinterpret_cast<llvm::FunctionType*>(тип);
  if (type->getReturnType()->isVoidTy()) {
    return builder.CreateCall(type, значення, llvmArguments);
  }
  return builder.CreateCall(type, значення, llvmArguments, "call");
}

позитивне __ПМЛЛВМ__отримати_розмір_типу_для_виділення(Модуль* модуль,
                                                       Тип* тип) {
  if (!тип->isSized()) {
    return 0;
  }

  return модуль->llvmModule->getDataLayout().getTypeAllocSize(тип);
}

Значення* __ПМЛЛВМ__створити_глобальну(Модуль* модуль,
                                       ю8* назва,
                                       позитивне видимість,
                                       Тип* тип) {
  std::string name((char*)назва->дані, назва->розмір);

  llvm::Function::LinkageTypes linkageType;
  if (видимість == ВИДИМІСТЬ_ЗОВНІШНЯ) {
    linkageType = llvm::Function::ExternalLinkage;
  } else if (видимість == ВИДИМІСТЬ_МІСЦЕВА) {
    linkageType = llvm::Function::ExternalLinkage;
  } else {
    linkageType = llvm::Function::PrivateLinkage;
  }

  auto value = new llvm::GlobalVariable(*модуль->llvmModule, тип, false,
                                        linkageType, nullptr, name);

  if (видимість == ВИДИМІСТЬ_МІСЦЕВА) {
    value->setDSOLocal(true);
  }

  return value;
}

Значення* __ПМЛЛВМ__отримати_значення_пусто(Модуль* модуль) {
  return llvm::ConstantPointerNull::get(
      llvm::PointerType::get(llvm::Type::getInt8Ty(*модуль->llvmContext), 0));
}

Тип* __ПМЛЛВМ__отримати_тип_ніщо(Модуль* модуль) {
  return llvm::Type::getVoidTy(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_адреса(Модуль* модуль) {
  return llvm::PointerType::get(llvm::Type::getVoidTy(*модуль->llvmContext), 0);
}

Тип* __ПМЛЛВМ__отримати_тип_б1(Модуль* модуль) {
  return llvm::Type::getInt1Ty(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_б8(Модуль* модуль) {
  return llvm::Type::getInt8Ty(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_б16(Модуль* модуль) {
  return llvm::Type::getInt16Ty(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_б32(Модуль* модуль) {
  return llvm::Type::getInt32Ty(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_б64(Модуль* модуль) {
  return llvm::Type::getInt64Ty(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_р32(Модуль* модуль) {
  return llvm::Type::getFloatTy(*модуль->llvmContext);
}

Тип* __ПМЛЛВМ__отримати_тип_р64(Модуль* модуль) {
  return llvm::Type::getDoubleTy(*модуль->llvmContext);
}

Значення* __ПМЛЛВМ__створити_логічне(Модуль* модуль, логічне значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext, llvm::APInt(1, значення));
}

Значення* __ПМЛЛВМ__створити_ц8(Модуль* модуль, ц8 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(8, значення, true));
}

Значення* __ПМЛЛВМ__створити_ц16(Модуль* модуль, ц16 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(16, значення, true));
}

Значення* __ПМЛЛВМ__створити_ц32(Модуль* модуль, ц32 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(32, значення, true));
}

Значення* __ПМЛЛВМ__створити_ц64(Модуль* модуль, ц64 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(64, значення, true));
}

Значення* __ПМЛЛВМ__створити_п8(Модуль* модуль, п8 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext, llvm::APInt(8, значення));
}

Значення* __ПМЛЛВМ__створити_п16(Модуль* модуль, п16 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(16, значення));
}

Значення* __ПМЛЛВМ__створити_п32(Модуль* модуль, п32 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(32, значення));
}

Значення* __ПМЛЛВМ__створити_п64(Модуль* модуль, п64 значення) {
  return llvm::ConstantInt::get(*модуль->llvmContext,
                                llvm::APInt(64, значення));
}

Значення* __ПМЛЛВМ__створити_д32(Модуль* модуль, д32 значення) {
  return llvm::ConstantFP::get(*модуль->llvmContext, llvm::APFloat(значення));
}

Значення* __ПМЛЛВМ__створити_д64(Модуль* модуль, д64 значення) {
  return llvm::ConstantFP::get(*модуль->llvmContext, llvm::APFloat(значення));
}

Значення* __ПМЛЛВМ__створити_т8(Модуль* модуль, т8* значення) {
  return nullptr;
}

Значення* __ПМЛЛВМ__створити_байти(Модуль* модуль,
                                   позитивне розмір,
                                   памʼять_п8 дані) {
  auto constantString = llvm::ConstantDataArray::getString(
      *модуль->llvmContext, std::string((char*)дані, розмір), false);

  return new llvm::GlobalVariable(
      *модуль->llvmModule,
      llvm::ArrayType::get(llvm::Type::getInt8Ty(*модуль->llvmContext), розмір),
      true, llvm::GlobalValue::LinkageTypes::PrivateLinkage, constantString);
}

Значення* __ПМЛЛВМ__створити_обʼєкт(Модуль* модуль,
                                    Тип* тип,
                                    позитивне кількість_аргументів,
                                    Значення** аргументи) {
  return llvm::ConstantStruct::get(
      (llvm::StructType*)тип,
      llvm::ArrayRef((llvm::Constant**)аргументи, кількість_аргументів));
}

Значення* __ПМЛЛВМ__вказівка_накопичити(Крок* крок, Тип* тип) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAlloca(тип, nullptr, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_логічне(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_ц8(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_ц16(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_ц32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_ц64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_п8(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_п16(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_п32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_п64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_д32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_додати_д64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFAdd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_логічне(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_ц8(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_ц16(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_ц32(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_ц64(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_п8(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_п16(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_п32(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_п64(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_д32(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_відняти_д64(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFSub(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_логічне(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_ц8(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_ц16(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_ц32(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_ц64(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_п8(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_п16(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_п32(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_п64(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_д32(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_помножити_д64(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFMul(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_логічне(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_ц8(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_ц16(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_ц32(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_ц64(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_п8(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_п16(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_п32(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_п64(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_д32(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_поділити_д64(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFDiv(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_логічне(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateURem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_ц8(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSRem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_ц16(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSRem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_ц32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSRem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_ц64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSRem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_п8(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateURem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_п16(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateURem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_п32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateURem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_п64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateURem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_д32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFRem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_остача_д64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFRem(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_логічне(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_ц8(Крок* крок,
                                      Значення* ліво,
                                      Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_ц16(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_ц32(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_ц64(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_п8(Крок* крок,
                                      Значення* ліво,
                                      Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_п16(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_п32(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_п64(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_д32(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_д64(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_рівно_адреса(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpEQ(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_логічне(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_ц8(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_ц16(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_ц32(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_ц64(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_п8(Крок* крок,
                                         Значення* ліво,
                                         Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_п16(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_п32(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_п64(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_д32(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_д64(Крок* крок,
                                          Значення* ліво,
                                          Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_не_рівно_адреса(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpNE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_логічне(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_ц8(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_ц16(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_ц32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_ц64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_п8(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_п16(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_п32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_п64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_д32(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_д64(Крок* крок,
                                        Значення* ліво,
                                        Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUGT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_логічне(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_ц8(Крок* крок,
                                      Значення* ліво,
                                      Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_ц16(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_ц32(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_ц64(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_п8(Крок* крок,
                                      Значення* ліво,
                                      Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_п16(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_п32(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_п64(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_д32(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_д64(Крок* крок,
                                       Значення* ліво,
                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpULT(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_логічне(Крок* крок,
                                                  Значення* ліво,
                                                  Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_ц8(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_ц16(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_ц32(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_ц64(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_п8(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_п16(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_п32(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_п64(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_д32(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_більше_рівно_д64(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpUGE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_логічне(Крок* крок,
                                                 Значення* ліво,
                                                 Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_ц8(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_ц16(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_ц32(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_ц64(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpSLE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_п8(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_п16(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_п32(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_п64(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateICmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_д32(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_менше_рівно_д64(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFCmpULE(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_логічне(Крок* крок,
                                                   Значення* ліво,
                                                   Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_ц8(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_ц16(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_ц32(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_ц64(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_п8(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_п16(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_п32(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вліво_п64(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateShl(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_логічне(Крок* крок,
                                                    Значення* ліво,
                                                    Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_ц8(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_ц16(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_ц32(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_ц64(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_п8(Крок* крок,
                                               Значення* ліво,
                                               Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateLShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_п16(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateLShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_п32(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateLShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_зсунути_вправо_п64(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateLShr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_логічне(Крок* крок,
                                                Значення* ліво,
                                                Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_ц8(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_ц16(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_ц32(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_ц64(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_п8(Крок* крок,
                                           Значення* ліво,
                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_п16(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_п32(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_і_п64(Крок* крок,
                                            Значення* ліво,
                                            Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateAnd(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_логічне(Крок* крок,
                                                  Значення* ліво,
                                                  Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_ц8(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_ц16(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_ц32(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_ц64(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_п8(Крок* крок,
                                             Значення* ліво,
                                             Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_п16(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_п32(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_або_п64(Крок* крок,
                                              Значення* ліво,
                                              Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateOr(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_логічне(Крок* крок,
                                                           Значення* ліво,
                                                           Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_ц8(Крок* крок,
                                                      Значення* ліво,
                                                      Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_ц16(Крок* крок,
                                                       Значення* ліво,
                                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_ц32(Крок* крок,
                                                       Значення* ліво,
                                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_ц64(Крок* крок,
                                                       Значення* ліво,
                                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_п8(Крок* крок,
                                                      Значення* ліво,
                                                      Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_п16(Крок* крок,
                                                       Значення* ліво,
                                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_п32(Крок* крок,
                                                       Значення* ліво,
                                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_двійкове_виключне_або_п64(Крок* крок,
                                                       Значення* ліво,
                                                       Значення* право) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateXor(ліво, право, "v");
}

Значення* __ПМЛЛВМ__вказівка_як(Крок* крок, Значення* значення, Тип* тип) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateBitCast(значення, тип, "v");
}

Значення* __ПМЛЛВМ__вказівка_отримати_адресу_елемента(
    Крок* крок,
    Тип* тип,
    Значення* значення,
    позитивне кількість_позицій,
    Значення** позиції) {
  llvm::IRBuilder<> builder(крок);

  std::vector<llvm::Value*> positions(кількість_позицій);
  for (int i = 0; i < кількість_позицій; i++) {
    positions[i] = позиції[i];
  }

  return builder.CreateGEP(тип, значення, positions, "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення, llvm::Type::getInt8Ty(крок->getContext()),
                            "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt8Ty(крок->getContext()));
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_логічне_на_адресу(Крок* крок,
                                                  Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_п8(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц8_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_п16(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц16_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_п32(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц32_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_п64(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateSIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_ц64_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_ц8(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_п8_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п8_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_ц16(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_п16_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п16_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_ц32(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_п32_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateZExt(значення,
                            llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п32_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_ц64(Крок* крок, Значення* значення) {
  return значення;
}

Значення* __ПМЛЛВМ__перетворити_п64_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateTrunc(значення,
                             llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateUIToFP(значення,
                              llvm::Type::getDoubleTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_п64_на_адресу(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateIntToPtr(
      значення,
      llvm::PointerType::get(llvm::Type::getVoidTy(крок->getContext()), 0),
      "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д32_на_д64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPExt(значення,
                             llvm::Type::getDoubleTy(крок->getContext()));
}

Значення* __ПМЛЛВМ__перетворити_д32_на_адресу(Крок* крок, Значення* значення) {
  return NULL;
}

Значення* __ПМЛЛВМ__перетворити_д64_на_логічне(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToSI(значення,
                              llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPToUI(значення,
                              llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_д32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateFPTrunc(значення,
                               llvm::Type::getFloatTy(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_д64_на_адресу(Крок* крок, Значення* значення) {
  // todo: wtf
  return NULL;
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_логічне(Крок* крок,
                                                  Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(значення,
                                llvm::Type::getInt1Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_ц8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(значення,
                                llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_ц16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(
      значення, llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_ц32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(
      значення, llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_ц64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(
      значення, llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_п8(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(значення,
                                llvm::Type::getInt8Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_п16(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(
      значення, llvm::Type::getInt16Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_п32(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(
      значення, llvm::Type::getInt32Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_п64(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreatePtrToInt(
      значення, llvm::Type::getInt64Ty(крок->getContext()), "v");
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_д32(Крок* крок, Значення* значення) {
  // todo: wtf
  return NULL;
}

Значення* __ПМЛЛВМ__перетворити_адресу_на_д64(Крок* крок, Значення* значення) {
  // todo: wtf
  return NULL;
}

Стрибок* __ПМЛЛВМ__вказівка_стрибнути(Крок* крок, Крок* куди) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateBr(куди);
}

void __ПМЛЛВМ__змінити_крок_стрибка(Стрибок* стрибок, Крок* куди) {
  стрибок->setSuccessor(0, куди);
}

Стрибок* __ПМЛЛВМ__вказівка_стрибнути_якщо(Крок* крок,
                                           Значення* значення,
                                           Крок* якщо_так,
                                           Крок* якщо_ні) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateCondBr(значення, якщо_так, якщо_ні);
}

void __ПМЛЛВМ__вказівка_записати(Крок* крок,
                                 Значення* значення,
                                 Значення* куди) {
  llvm::IRBuilder<> builder(крок);
  builder.CreateStore(значення, куди);
}

Значення* __ПМЛЛВМ__вказівка_прочитати(Крок* крок, Тип* тип, Значення* звідки) {
  llvm::IRBuilder<> builder(крок);
  return builder.CreateLoad(тип, звідки, "v");
}

void __ПМЛЛВМ__вказівка_вернути(Крок* крок) {
  llvm::IRBuilder<> builder(крок);
  builder.CreateRetVoid();
}

void __ПМЛЛВМ__вказівка_вернути_значення(Крок* крок, Значення* значення) {
  llvm::IRBuilder<> builder(крок);
  builder.CreateRet(значення);
}

логічне __ПМЛЛВМ__отримати_лл(Модуль* модуль,
                              позитивне* вихід_розміру,
                              памʼять_п8* вихід_даних) {
  llvm::SmallVector<char, 0> buffer;
  llvm::raw_svector_ostream os(buffer);
  модуль->llvmModule->print(os, nullptr);
  if (buffer.empty()) {
    *вихід_даних = nullptr;
    *вихід_розміру = 0;
    return true;
  } else {
    *вихід_даних = (памʼять_п8)malloc(buffer.size());
    memcpy(*вихід_даних, buffer.data(), buffer.size());
    *вихід_розміру = buffer.size();
    return true;
  }
}

логічне __ПМЛЛВМ__отримати_обджект(Модуль* модуль,
                                   позитивне* вихід_розміру,
                                   памʼять_п8* вихід_даних) {
  llvm::SmallVector<char, 0> buffer;
  llvm::raw_svector_ostream dest(buffer);

  llvm::legacy::PassManager pass;
  auto FileType = llvm::CodeGenFileType::ObjectFile;

  if (модуль->llvmTargetMachine->addPassesToEmitFile(pass, dest, nullptr,
                                                     FileType)) {
    llvm::errs() << "TheTargetMachine can't emit a file of this type";
    return false;
  }

  pass.run(*модуль->llvmModule);

  if (buffer.empty()) {
    *вихід_даних = nullptr;
    *вихід_розміру = 0;
    return true;
  } else {
    *вихід_даних = (памʼять_п8)malloc(buffer.size());
    memcpy(*вихід_даних, buffer.data(), buffer.size());
    *вихід_розміру = buffer.size();
    return true;
  }
}

void __ПМЛЛВМ__знищити_модуль(Модуль* модуль) {
  delete модуль->llvmTargetMachine;
  llvm::llvm_shutdown();
  delete модуль;
}
}