extern "C" {
#ifndef TL_TYPE
#define TL_TYPE void
#endif
#ifndef TSIL_LLVM_TYPE_TYPE
#define TSIL_LLVM_TYPE_TYPE void
#endif
#ifndef TSIL_LLVM_FUNCTION_TYPE
#define TSIL_LLVM_FUNCTION_TYPE void
#endif
#ifndef TSIL_LLVM_FUNCTION_TYPE_TYPE
#define TSIL_LLVM_FUNCTION_TYPE_TYPE void
#endif
#ifndef TSIL_LLVM_VALUE_TYPE
#define TSIL_LLVM_VALUE_TYPE void
#endif
#ifndef TSIL_LLVM_BASIC_BLOCK_TYPE
#define TSIL_LLVM_BASIC_BLOCK_TYPE void
#endif
#ifndef TSIL_LLVM_BRANCH_INST_TYPE
#define TSIL_LLVM_BRANCH_INST_TYPE void
#endif

typedef TL_TYPE TL;
typedef TSIL_LLVM_TYPE_TYPE LLVMType;
typedef TSIL_LLVM_FUNCTION_TYPE LLVMFunction;
typedef TSIL_LLVM_FUNCTION_TYPE_TYPE LLVMFunctionType;
typedef TSIL_LLVM_VALUE_TYPE LLVMValue;
typedef TSIL_LLVM_BASIC_BLOCK_TYPE LLVMBasicBlock;
typedef TSIL_LLVM_BRANCH_INST_TYPE LLVMBranchInst;

#define tsil_llvm_LINKAGE_EXTERNAL 0
#define tsil_llvm_LINKAGE_DSO_LOCAL 1
#define tsil_llvm_LINKAGE_INTERNAL 2

TL* tsil_llvm_create_tl(char* name);

LLVMType* tsil_llvm_create_struct(TL* m, char* name);
LLVMType* tsil_llvm_set_struct_fields(TL* m,
                                      LLVMType* st,
                                      unsigned long fields_size,
                                      LLVMType** fields);

LLVMFunction* tsil_llvm_declare_function(TL* m,
                                         size_t linkage,
                                         char* name,
                                         LLVMType* ret_type,
                                         unsigned long params_size,
                                         LLVMType** params,
                                         unsigned long isVarArg);
LLVMBasicBlock* tsil_llvm_create_function_block(TL* m,
                                                LLVMFunction* f,
                                                char* name);

LLVMValue* tsil_llvm_inst_alloca(TL* m,
                                 LLVMBasicBlock* block,
                                 char* name,
                                 LLVMType* type);
LLVMValue* tsil_llvm_inst_getelementptr(TL* m,
                                        LLVMBasicBlock* block,
                                        LLVMType* type,
                                        LLVMValue* pointer,
                                        unsigned long indices_size,
                                        LLVMValue** indices);
void tsil_llvm_inst_store(TL* m,
                          LLVMBasicBlock* block,
                          LLVMValue* value,
                          LLVMValue* pointer);
LLVMValue* tsil_llvm_inst_load(TL* m,
                               LLVMBasicBlock* block,
                               LLVMType* type,
                               LLVMValue* pointer);
LLVMValue* tsil_llvm_inst_ret(TL* m, LLVMBasicBlock* block, LLVMValue* value);
LLVMValue* tsil_llvm_inst_call_value(TL* m,
                                     LLVMBasicBlock* block,
                                     LLVMFunctionType* ft,
                                     LLVMValue* value,
                                     unsigned long arguments_size,
                                     LLVMValue** arguments);
LLVMValue* tsil_llvm_inst_call_func(TL* m,
                                    LLVMBasicBlock* block,
                                    LLVMFunction* func,
                                    unsigned long arguments_size,
                                    LLVMValue** arguments);
LLVMBranchInst* tsil_llvm_inst_br(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMBasicBlock* target);
void tsil_llvm_set_br_successor(TL* m,
                                LLVMBranchInst* branch_inst,
                                LLVMBasicBlock* target);
void tsil_llvm_inst_brif(TL* m,
                         LLVMBasicBlock* block,
                         LLVMValue* condition,
                         LLVMBasicBlock* target_true,
                         LLVMBasicBlock* target_false);
LLVMValue* tsil_llvm_inst_icmp(TL* m,
                               LLVMBasicBlock* block,
                               char* op,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp(TL* m,
                               LLVMBasicBlock* block,
                               char* op,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_add(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right);
LLVMValue* tsil_llvm_inst_fadd(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_sub(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right);
LLVMValue* tsil_llvm_inst_fsub(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_mul(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right);
LLVMValue* tsil_llvm_inst_fmul(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_udiv(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_sdiv(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_fdiv(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_urem(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_srem(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_frem(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_sgt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_ugt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_ogt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_ugt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_sge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_uge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_oge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_uge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_slt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_ult(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_olt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_ult(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_sle(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_ule(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_ole(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_ule(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_eq(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMValue* left,
                                  LLVMValue* right);
LLVMValue* tsil_llvm_inst_icmp_ne(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMValue* left,
                                  LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_oeq(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_one(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_ueq(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_fcmp_une(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right);
LLVMValue* tsil_llvm_inst_and(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right);
LLVMValue* tsil_llvm_inst_or(TL* m,
                             LLVMBasicBlock* block,
                             LLVMValue* left,
                             LLVMValue* right);
LLVMValue* tsil_llvm_inst_xor(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right);
LLVMValue* tsil_llvm_inst_shl(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right);
LLVMValue* tsil_llvm_inst_lshr(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_ashr(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right);
LLVMValue* tsil_llvm_inst_trunc(TL* m,
                                LLVMBasicBlock* block,
                                LLVMValue* value,
                                LLVMType* toType);
LLVMValue* tsil_llvm_inst_zext(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* value,
                               LLVMType* toType);
LLVMValue* tsil_llvm_inst_sext(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* value,
                               LLVMType* toType);
LLVMValue* tsil_llvm_inst_fptrunc(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMValue* value,
                                  LLVMType* toType);
LLVMValue* tsil_llvm_inst_fpext(TL* m,
                                LLVMBasicBlock* block,
                                LLVMValue* value,
                                LLVMType* toType);
LLVMValue* tsil_llvm_inst_fptoui(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType);
LLVMValue* tsil_llvm_inst_fptosi(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType);
LLVMValue* tsil_llvm_inst_uitofp(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType);
LLVMValue* tsil_llvm_inst_sitofp(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType);
LLVMValue* tsil_llvm_inst_ptrtoint(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* value,
                                   LLVMType* toType);
LLVMValue* tsil_llvm_inst_inttoptr(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* value,
                                   LLVMType* toType);
LLVMValue* tsil_llvm_inst_bitcast(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMValue* value,
                                  LLVMType* toType);

LLVMType* tsil_llvm_type_get_pointer_to(TL* m, LLVMType* type);
LLVMType* tsil_llvm_type_get_array_of(TL* m,
                                      LLVMType* type,
                                      unsigned long size);

LLVMType* tsil_llvm_get_void_type(TL* m);
LLVMType* tsil_llvm_get_pointer_type(TL* m);
LLVMType* tsil_llvm_get_int1_type(TL* m);
LLVMType* tsil_llvm_get_int8_type(TL* m);
LLVMType* tsil_llvm_get_int16_type(TL* m);
LLVMType* tsil_llvm_get_int32_type(TL* m);
LLVMType* tsil_llvm_get_int64_type(TL* m);
LLVMType* tsil_llvm_get_float32_type(TL* m);
LLVMType* tsil_llvm_get_float64_type(TL* m);

LLVMValue* tsil_llvm_create_int8(TL* m, char value);
LLVMValue* tsil_llvm_create_int16(TL* m, short value);
LLVMValue* tsil_llvm_create_int32(TL* m, int value);
LLVMValue* tsil_llvm_create_int64(TL* m, long value);
LLVMValue* tsil_llvm_create_uint1(TL* m, unsigned char value);
LLVMValue* tsil_llvm_create_uint8(TL* m, unsigned char value);
LLVMValue* tsil_llvm_create_uint16(TL* m, unsigned short value);
LLVMValue* tsil_llvm_create_uint32(TL* m, unsigned int value);
LLVMValue* tsil_llvm_create_uint64(TL* m, unsigned long value);
LLVMValue* tsil_llvm_create_float(TL* m, float value);
LLVMValue* tsil_llvm_create_double(TL* m, double value);
LLVMValue* tsil_llvm_create_string(TL* m, char* value);

LLVMType* tsil_llvm_get_type(TL* m, LLVMValue* value);
LLVMFunctionType* tsil_llvm_get_as_function_type(TL* m, LLVMValue* value);
LLVMFunctionType* tsil_llvm_get_function_type(TL* m, LLVMFunction* f);
LLVMFunctionType* tsil_llvm_make_function_type(TL* m,
                                               LLVMType* ret_type,
                                               unsigned long params_size,
                                               LLVMType** params,
                                               unsigned long isVarArg);

LLVMValue* tsil_llvm_get_function_arg_value(TL* m,
                                            LLVMFunction* f,
                                            unsigned long index);

LLVMType* tsil_llvm_create_function_type(TL* m,
                                         LLVMType* ret_type,
                                         unsigned long params_size,
                                         LLVMType** params,
                                         unsigned long isVarArg);

LLVMValue* tsil_llvm_get_null(TL* m);

LLVMValue* tsil_llvm_make_external_global(TL* m, char* name, LLVMType* type);
LLVMValue* tsil_llvm_make_local_global(TL* m, char* name, LLVMType* type);
LLVMValue* tsil_llvm_make_internal_global(TL* m, char* name, LLVMType* type);

char* dumpLL(TL* m);
void dumpOBJ(TL* m, std::vector<unsigned char>& out);
}