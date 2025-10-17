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

static std::unique_ptr<llvm::LLVMContext> llvmContext;

typedef llvm::Module Модуль;
typedef llvm::Function Функція;
typedef llvm::Value Значення;
typedef llvm::Type Тип;
typedef llvm::BasicBlock БазовийБлок;
typedef llvm::BranchInst ІнструкціяРозгалуження;

extern "C" {
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define н8 uint8_t
#define н16 uint16_t
#define н32 uint32_t
#define н64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define р32 float
#define р64 double
#define логічне uint8_t
#define натуральне н64
#define ціле ц64
#define дійсне р64
#define ніщо void
#define невідома_адреса void*
#define невідома_памʼять void*
typedef struct т8 {
  натуральне розмір;
  н8* дані;
} т8;
typedef struct ю8 {
  натуральне розмір;
  н8* дані;
} ю8;
#define памʼять_т8 т8*
#define памʼять_ю8 ю8*

#define ВИДИМІСТЬ_ВНУТРІШНЯ 1
#define ВИДИМІСТЬ_МІСЦЕВА 2
#define ВИДИМІСТЬ_ЗОВНІШНЯ 3

#define АРХІТЕКТУРА_ІКС86_64 1
#define АРХІТЕКТУРА_АРМ64 2

#define ПОСТАЧАЛЬНИК_ЗАГАЛЬНИЙ 1

#define СИСТЕМА_ЛІНУКС 1

void __ЛЛВМ__ініціалізувати() {
  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargets();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmParsers();
  llvm::InitializeAllAsmPrinters();

  llvmContext = std::make_unique<llvm::LLVMContext>();
}

void __ЛЛВМ__деініціалізувати() {
  // llvmContext.reset();

  // llvm::llvm_shutdown();
}

Тип* __ЛЛВМ__тип_войд() {
  return llvm::Type::getVoidTy(*llvmContext);
}

Тип* __ЛЛВМ__тип_пойнтер() {
  return llvm::PointerType::get(*llvmContext, 0);
}

Тип* __ЛЛВМ__тип_і1() {
  return llvm::Type::getInt1Ty(*llvmContext);
}

Тип* __ЛЛВМ__тип_і8() {
  return llvm::Type::getInt8Ty(*llvmContext);
}

Тип* __ЛЛВМ__тип_і16() {
  return llvm::Type::getInt16Ty(*llvmContext);
}

Тип* __ЛЛВМ__тип_і32() {
  return llvm::Type::getInt32Ty(*llvmContext);
}

Тип* __ЛЛВМ__тип_і64() {
  return llvm::Type::getInt64Ty(*llvmContext);
}

Тип* __ЛЛВМ__тип_флоат() {
  return llvm::Type::getFloatTy(*llvmContext);
}

Тип* __ЛЛВМ__тип_даубл() {
  return llvm::Type::getDoubleTy(*llvmContext);
}

Тип* __ЛЛВМ__тип_функція(натуральне кількість_параметрів,
                         Тип** параметри,
                         Тип* тип_результату) {
  return llvm::FunctionType::get(
      тип_результату == nullptr ? llvm::Type::getVoidTy(*llvmContext)
                                : тип_результату,
      llvm::ArrayRef<llvm::Type*>(параметри, кількість_параметрів), false);
}

Тип* __ЛЛВМ__тип_аррай(Тип* тип_елемента, натуральне розмір) {
  return llvm::ArrayType::get(тип_елемента, розмір);
}

Тип* __ЛЛВМ__тип(ю8* назва, натуральне кількість_параметрів, Тип** параметри) {
  std::string name((char*)назва->дані, назва->розмір);

  auto structType = llvm::StructType::create(*llvmContext, name);

  std::vector<llvm::Type*> llvmFields(кількість_параметрів);
  for (int i = 0; i < кількість_параметрів; i++) {
    llvmFields[i] = параметри[i];
  }

  structType->setBody(llvmFields);

  return structType;
}

Значення* __ЛЛВМ__нулл() {
  return llvm::ConstantPointerNull::get(
      llvm::PointerType::get(llvm::Type::getVoidTy(*llvmContext), 0));
}

Значення* __ЛЛВМ__і1(н8 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(1, значення));
}

Значення* __ЛЛВМ__і8(н8 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(8, значення));
}

Значення* __ЛЛВМ__і16(н16 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(1, значення));
}

Значення* __ЛЛВМ__і32(н32 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(32, значення));
}

Значення* __ЛЛВМ__і64(н64 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(64, значення));
}

Значення* __ЛЛВМ__і8ц(ц8 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(8, значення, true));
}

Значення* __ЛЛВМ__і16ц(ц16 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(16, значення, true));
}

Значення* __ЛЛВМ__і32ц(ц32 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(32, значення, true));
}

Значення* __ЛЛВМ__і64ц(ц64 значення) {
  return llvm::ConstantInt::get(*llvmContext, llvm::APInt(64, значення, true));
}

Значення* __ЛЛВМ__флоат(р32 значення) {
  return llvm::ConstantFP::get(*llvmContext, llvm::APFloat(значення));
}

Значення* __ЛЛВМ__даубл(р64 значення) {
  return llvm::ConstantFP::get(*llvmContext, llvm::APFloat(значення));
}

Модуль* __ЛЛВМ__створити_модуль(ю8* назва,
                                натуральне архітектура,
                                натуральне система) {
  std::string name((char*)назва->дані, назва->розмір);

  auto llvmModule = new llvm::Module(name, *llvmContext);

  std::string targetTriple;

  if (архітектура) {
    if (архітектура == АРХІТЕКТУРА_ІКС86_64) {
      targetTriple = "x86_64";
    } else if (архітектура == АРХІТЕКТУРА_АРМ64) {
      targetTriple = "arm64";
    } else {
      return nullptr;
    }
    targetTriple += "-pc";
    if (система == СИСТЕМА_ЛІНУКС) {
      targetTriple += "-linux-gnu";
    } else {
      return nullptr;
    }
  } else {
    targetTriple = llvm::sys::getDefaultTargetTriple();
  }

  llvmModule->setTargetTriple(targetTriple);

  std::string Error;
  auto Target = llvm::TargetRegistry::lookupTarget(targetTriple, Error);
  if (!Error.empty()) {
    std::cout << Error << std::endl;
    return nullptr;
  }

  auto CPU = "generic";
  auto Features = "";

  llvm::TargetOptions opt;

  auto llvmTargetMachine = Target->createTargetMachine(
      targetTriple, CPU, Features, opt, llvm::Reloc::PIC_);

  llvmModule->setDataLayout(llvmTargetMachine->createDataLayout());

  return llvmModule;
}

void __ЛЛВМ__знищити_модуль(Модуль* модуль) {
  // delete модуль;
}

Функція* __ЛЛВМ__створити_функцію(Модуль* модуль,
                                  натуральне видимість,
                                  ю8* назва,
                                  натуральне кількість_параметрів,
                                  Тип** параметри,
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

  std::vector<llvm::Type*> llvmParams(кількість_параметрів);
  for (int i = 0; i < кількість_параметрів; i++) {
    llvmParams[i] = параметри[i];
  }

  auto functionType = llvm::FunctionType::get(
      тип_результату == nullptr ? llvm::Type::getVoidTy(*llvmContext)
                                : тип_результату,
      llvmParams, false);

  auto function =
      llvm::Function::Create(functionType, linkageType, name, модуль);

  if (видимість == ВИДИМІСТЬ_МІСЦЕВА) {
    function->setDSOLocal(true);
  }

  return function;
}

Значення* __ЛЛВМ__отримати_аргумент_функції(Функція* функція,
                                            натуральне позиція) {
  return функція->getArg(позиція);
}

Значення* __ЛЛВМ__створити_базовий_блок(Функція* функція, ю8* назва) {
  std::string name((char*)назва->дані, назва->розмір);

  return llvm::BasicBlock::Create(*llvmContext, name, функція);
}

Значення* __ЛЛВМ__інст_аллока(БазовийБлок* базовий_блок, Тип* тип) {
  llvm::IRBuilder<> builder(базовий_блок);
  return builder.CreateAlloca(тип, nullptr, "alloca");
}

логічне __ЛЛВМ__отримати_ір(Модуль* модуль,
                            натуральне* вихід_розміру,
                            н8** вихід_даних) {
  llvm::SmallVector<char, 0> buffer;
  llvm::raw_svector_ostream os(buffer);

  модуль->print(os, nullptr);

  if (buffer.empty()) {
    *вихід_розміру = 0;
    *вихід_даних = nullptr;

    return false;
  } else {
    *вихід_розміру = buffer.size();
    *вихід_даних = (н8*)malloc(buffer.size());
    memcpy(*вихід_даних, buffer.data(), buffer.size());

    return true;
  }
}
}