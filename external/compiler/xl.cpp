#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

#include <iostream>

struct XLModuleStruct {
  llvm::LLVMContext* llvmContext;
  llvm::Module* llvmModule;
  llvm::IRBuilder<>* llvmBuilder;
};
#define XL_MODULE_TYPE XLModuleStruct
#define XL_FUNCTION_TYPE_TYPE llvm::FunctionType
#define XL_TYPE_TYPE llvm::Type
#define XL_VALUE_TYPE llvm::Value
#define XL_BASIC_BLOCK_TYPE llvm::BasicBlock
#include "xl.h"

extern "C" {
XLModule* tsil_xl_create_module(char* name) {
  const auto llvmContext = new llvm::LLVMContext();
  const auto llvmModule = new llvm::Module(name, *llvmContext);
  const auto xlModule = new XLModule();
  xlModule->llvmContext = llvmContext;
  xlModule->llvmModule = llvmModule;
  const auto entry =
      llvm::BasicBlock::Create(*xlModule->llvmContext, "entrypoint");
  xlModule->llvmBuilder = new llvm::IRBuilder(entry);
  return xlModule;
}

XLType* tsil_xl_create_struct(XLModule* m, char* name) {
  return llvm::StructType::create(*m->llvmContext, name);
}

XLType* tsil_xl_set_struct_fields(XLModule* m,
                                  XLType* st,
                                  int fields_size,
                                  XLType** fields) {
  std::vector<llvm::Type*> llvmFields(fields_size);
  for (int i = 0; i < fields_size; i++) {
    llvmFields[i] = fields[i];
  }
  static_cast<llvm::StructType*>(st)->setBody(llvmFields);
  return st;
}

XLFunction* tsil_xl_declare_function(XLModule* m,
                                     char* name,
                                     XLType* ret_type,
                                     int params_size,
                                     XLType** params,
                                     bool isVarArg) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  auto llvmFunction = llvm::Function::Create(
      llvm::FunctionType::get(ret_type, llvmParams, isVarArg),
      llvm::Function::ExternalLinkage, name, m->llvmModule);
  auto xlFunction = new XLFunction();
  xlFunction->llvm_function = llvmFunction;
  xlFunction->result_type = ret_type;
  return xlFunction;
}

XLBasicBlock* tsil_xl_create_function_block(XLModule* m,
                                            XLFunction* f,
                                            char* name) {
  return llvm::BasicBlock::Create(
      *m->llvmContext, name, static_cast<llvm::Function*>(f->llvm_function));
}

XLValue* tsil_xl_inst_alloca(XLModule* m,
                             XLBasicBlock* block,
                             char* name,
                             XLType* type) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAlloca(type, nullptr, name);
}

XLValue* tsil_xl_inst_getelementptr(XLModule* m,
                                    XLBasicBlock* block,
                                    XLType* type,
                                    XLValue* pointer,
                                    int indices_size,
                                    XLValue** indices) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmIndices(indices_size);
  for (int i = 0; i < indices_size; i++) {
    llvmIndices[i] = indices[i];
  }
  return builder.CreateGEP(type, pointer, llvmIndices);
}

void tsil_xl_inst_store(XLModule* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  builder.CreateStore(value, pointer);
}

size_t loadIndex = 0;

XLValue* tsil_xl_inst_load(XLModule* m,
                           XLBasicBlock* block,
                           XLType* type,
                           XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  loadIndex++;
  auto name = "load" + std::to_string(loadIndex);
  return builder.CreateLoad(type, pointer, name);
}

XLValue* tsil_xl_inst_ret(XLModule* m, XLBasicBlock* block, XLValue* value) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateRet(value);
}

XLValue* tsil_xl_inst_call_value(XLModule* m,
                                 XLBasicBlock* block,
                                 XLFunctionType* ft,
                                 XLValue* value,
                                 int arguments_size,
                                 XLValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(ft, value, llvmArguments);
}

XLValue* tsil_xl_inst_call_func(XLModule* m,
                                XLBasicBlock* block,
                                XLFunction* func,
                                int arguments_size,
                                XLValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(static_cast<llvm::Function*>(func->llvm_function),
                            llvmArguments);
}

void tsil_xl_inst_br(XLModule* m, XLBasicBlock* block, XLBasicBlock* target) {
  llvm::IRBuilder<> builder(block);
  builder.CreateBr(target);
}

void tsil_xl_inst_br_if(XLModule* m,
                        XLBasicBlock* block,
                        XLValue* condition,
                        XLBasicBlock* target_true,
                        XLBasicBlock* target_false) {
  llvm::IRBuilder<> builder(block);
  builder.CreateCondBr(condition, target_true, target_false);
}

XLValue* tsil_xl_inst_icmp(XLModule* m,
                           XLBasicBlock* block,
                           char* op,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_EQ, left, right);
}

XLValue* tsil_xl_inst_fcmp(XLModule* m,
                           XLBasicBlock* block,
                           char* op,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, left, right);
}

XLValue* tsil_xl_inst_add(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAdd(left, right);
}

XLValue* tsil_xl_inst_fadd(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFAdd(left, right);
}

XLValue* tsil_xl_inst_sub(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSub(left, right);
}

XLValue* tsil_xl_inst_fsub(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFSub(left, right);
}

XLValue* tsil_xl_inst_mul(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateMul(left, right);
}

XLValue* tsil_xl_inst_fmul(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFMul(left, right);
}

XLValue* tsil_xl_inst_udiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUDiv(left, right);
}

XLValue* tsil_xl_inst_sdiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSDiv(left, right);
}

XLValue* tsil_xl_inst_fdiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFDiv(left, right);
}

XLValue* tsil_xl_inst_mod(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateURem(left, right);
}

XLValue* tsil_xl_inst_fmod(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFRem(left, right);
}

XLValue* tsil_xl_inst_and(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAnd(left, right);
}

XLValue* tsil_xl_inst_or(XLModule* m,
                         XLBasicBlock* block,
                         XLValue* left,
                         XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateOr(left, right);
}

XLValue* tsil_xl_inst_xor(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateXor(left, right);
}

XLValue* tsil_xl_inst_shl(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateShl(left, right);
}

XLValue* tsil_xl_inst_lshr(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateLShr(left, right);
}

XLValue* tsil_xl_inst_ashr(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAShr(left, right);
}

XLValue* tsil_xl_inst_trunc(XLModule* m,
                            XLBasicBlock* block,
                            XLValue* value,
                            XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateTrunc(value, toType);
}

XLValue* tsil_xl_inst_zext(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* value,
                           XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateZExt(value, toType);
}

XLValue* tsil_xl_inst_sext(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* value,
                           XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSExt(value, toType);
}

XLValue* tsil_xl_inst_fptrunc(XLModule* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPTrunc(value, toType);
}

XLValue* tsil_xl_inst_fpext(XLModule* m,
                            XLBasicBlock* block,
                            XLValue* value,
                            XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPExt(value, toType);
}

XLValue* tsil_xl_inst_fptoui(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToUI(value, toType);
}

XLValue* tsil_xl_inst_fptosi(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToSI(value, toType);
}

XLValue* tsil_xl_inst_uitofp(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUIToFP(value, toType);
}

XLValue* tsil_xl_inst_sitofp(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSIToFP(value, toType);
}

XLValue* tsil_xl_inst_ptrtoint(XLModule* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreatePtrToInt(value, toType);
}

XLValue* tsil_xl_inst_inttoptr(XLModule* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateIntToPtr(value, toType);
}

XLValue* tsil_xl_inst_bitcast(XLModule* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateBitCast(value, toType);
}

XLType* tsil_xl_type_get_pointer_to(XLModule* m, XLType* type) {
  return llvm::PointerType::get(type, 0);
}

XLType* tsil_xl_type_get_array_of(XLModule* m, XLType* type, int size) {
  return llvm::ArrayType::get(type, size);
}

XLType* tsil_xl_get_void_type(XLModule* m) {
  return llvm::Type::getVoidTy(*m->llvmContext);
}

XLType* tsil_xl_get_pointer_type(XLModule* m) {
  return tsil_xl_type_get_pointer_to(m, tsil_xl_get_void_type(m));
}

XLType* tsil_xl_get_int1_type(XLModule* m) {
  return llvm::Type::getInt1Ty(*m->llvmContext);
}

XLType* tsil_xl_get_int8_type(XLModule* m) {
  return llvm::Type::getInt8Ty(*m->llvmContext);
}

XLType* tsil_xl_get_int16_type(XLModule* m) {
  return llvm::Type::getInt8Ty(*m->llvmContext);
}

XLType* tsil_xl_get_int32_type(XLModule* m) {
  return llvm::Type::getInt32Ty(*m->llvmContext);
}

XLType* tsil_xl_get_int64_type(XLModule* m) {
  return llvm::Type::getInt64Ty(*m->llvmContext);
}

XLType* tsil_xl_get_float32_type(XLModule* m) {
  return llvm::Type::getFloatTy(*m->llvmContext);
}

XLType* tsil_xl_get_float64_type(XLModule* m) {
  return llvm::Type::getDoubleTy(*m->llvmContext);
}

XLValue* tsil_xl_create_int32(XLModule* m, int value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(32, value));
}

XLValue* tsil_xl_create_int64(XLModule* m, long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(64, value));
}

XLValue* tsil_xl_create_double(XLModule* m, double value) {
  return llvm::ConstantFP::get(*m->llvmContext, llvm::APFloat(value));
}

XLValue* tsil_xl_create_string(XLModule* m, char* value) {
  return new llvm::GlobalVariable(
      *m->llvmModule,
      llvm::ArrayType::get(llvm::Type::getInt8Ty(*m->llvmContext),
                           strlen(value) + 1),
      true, llvm::GlobalValue::LinkageTypes::PrivateLinkage,
      llvm::ConstantDataArray::getString(*m->llvmContext, value));
}

XLType* tsil_xl_get_type(XLModule* m, XLValue* value) {
  return value->getType();
}

XLFunctionType* tsil_xl_get_as_function_type(XLModule* m, XLValue* value) {
  return static_cast<llvm::FunctionType*>(value->getType());
}

XLValue* tsil_xl_get_function_arg_value(XLModule* m, XLFunction* f, int index) {
  return static_cast<llvm::Function*>(f->llvm_function)->getArg(index);
}

XLType* tsil_xl_create_function_type(XLModule* m,
                                     XLType* ret_type,
                                     int params_size,
                                     XLType** params,
                                     bool isVarArg) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  return llvm::FunctionType::get(ret_type, llvmParams, isVarArg);
}

char* dumpLL(XLModule* m) {
  std::string str;
  llvm::raw_string_ostream os(str);
  m->llvmModule->print(os, nullptr);
  return strdup(os.str().c_str());
}
}