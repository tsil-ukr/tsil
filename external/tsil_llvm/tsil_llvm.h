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

typedef TL_TYPE XTL;
typedef TSIL_LLVM_TYPE_TYPE XLType;
typedef TSIL_LLVM_FUNCTION_TYPE XLFunction;
typedef TSIL_LLVM_FUNCTION_TYPE_TYPE XLFunctionType;
typedef TSIL_LLVM_VALUE_TYPE XLValue;
typedef TSIL_LLVM_BASIC_BLOCK_TYPE XLBasicBlock;

#define tsil_llvm_LINKAGE_EXTERNAL 0
#define tsil_llvm_LINKAGE_DSO_LOCAL 1
#define tsil_llvm_LINKAGE_INTERNAL 2

XTL* xlm_create(char* name);

XLType* tsil_llvm_create_struct(XTL* m, char* name);
XLType* tsil_llvm_set_struct_fields(XTL* m,
                                    XLType* st,
                                    unsigned long fields_size,
                                    XLType** fields);

XLFunction* tsil_llvm_declare_function(XTL* m,
                                       size_t linkage,
                                       char* name,
                                       XLType* ret_type,
                                       unsigned long params_size,
                                       XLType** params,
                                       unsigned long isVarArg);
XLBasicBlock* tsil_llvm_create_function_block(XTL* m,
                                              XLFunction* f,
                                              char* name);

XLValue* tsil_llvm_inst_alloca(XTL* m,
                               XLBasicBlock* block,
                               char* name,
                               XLType* type);
XLValue* tsil_llvm_inst_getelementptr(XTL* m,
                                      XLBasicBlock* block,
                                      XLType* type,
                                      XLValue* pointer,
                                      unsigned long indices_size,
                                      XLValue** indices);
void tsil_llvm_inst_store(XTL* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLValue* pointer);
XLValue* tsil_llvm_inst_load(XTL* m,
                             XLBasicBlock* block,
                             XLType* type,
                             XLValue* pointer);
XLValue* tsil_llvm_inst_ret(XTL* m, XLBasicBlock* block, XLValue* value);
XLValue* tsil_llvm_inst_call_value(XTL* m,
                                   XLBasicBlock* block,
                                   XLFunctionType* ft,
                                   XLValue* value,
                                   unsigned long arguments_size,
                                   XLValue** arguments);
XLValue* tsil_llvm_inst_call_func(XTL* m,
                                  XLBasicBlock* block,
                                  XLFunction* func,
                                  unsigned long arguments_size,
                                  XLValue** arguments);
void tsil_llvm_inst_br(XTL* m, XLBasicBlock* block, XLBasicBlock* target);
void tsil_llvm_inst_br_if(XTL* m,
                          XLBasicBlock* block,
                          XLValue* condition,
                          XLBasicBlock* target_true,
                          XLBasicBlock* target_false);
XLValue* tsil_llvm_inst_icmp(XTL* m,
                             XLBasicBlock* block,
                             char* op,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_fcmp(XTL* m,
                             XLBasicBlock* block,
                             char* op,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_add(XTL* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_fadd(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_sub(XTL* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_fsub(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_mul(XTL* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_fmul(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_udiv(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_sdiv(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_fdiv(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_urem(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_srem(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_frem(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_and(XTL* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_or(XTL* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_llvm_inst_xor(XTL* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_shl(XTL* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_lshr(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_ashr(XTL* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_trunc(XTL* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType);
XLValue* tsil_llvm_inst_zext(XTL* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_llvm_inst_sext(XTL* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_llvm_inst_fptrunc(XTL* m,
                                XLBasicBlock* block,
                                XLValue* value,
                                XLType* toType);
XLValue* tsil_llvm_inst_fpext(XTL* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType);
XLValue* tsil_llvm_inst_fptoui(XTL* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_fptosi(XTL* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_uitofp(XTL* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_sitofp(XTL* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_ptrtoint(XTL* m,
                                 XLBasicBlock* block,
                                 XLValue* value,
                                 XLType* toType);
XLValue* tsil_llvm_inst_inttoptr(XTL* m,
                                 XLBasicBlock* block,
                                 XLValue* value,
                                 XLType* toType);
XLValue* tsil_llvm_inst_bitcast(XTL* m,
                                XLBasicBlock* block,
                                XLValue* value,
                                XLType* toType);

XLType* tsil_llvm_type_get_pointer_to(XTL* m, XLType* type);
XLType* tsil_llvm_type_get_array_of(XTL* m, XLType* type, unsigned long size);

XLType* tsil_llvm_get_void_type(XTL* m);
XLType* tsil_llvm_get_pointer_type(XTL* m);
XLType* tsil_llvm_get_int1_type(XTL* m);
XLType* tsil_llvm_get_int8_type(XTL* m);
XLType* tsil_llvm_get_int16_type(XTL* m);
XLType* tsil_llvm_get_int32_type(XTL* m);
XLType* tsil_llvm_get_int64_type(XTL* m);
XLType* tsil_llvm_get_float32_type(XTL* m);
XLType* tsil_llvm_get_float64_type(XTL* m);

XLValue* tsil_llvm_create_int8(XTL* m, char value);
XLValue* tsil_llvm_create_int16(XTL* m, short value);
XLValue* tsil_llvm_create_int32(XTL* m, int value);
XLValue* tsil_llvm_create_int64(XTL* m, long value);
XLValue* tsil_llvm_create_uint8(XTL* m, unsigned char value);
XLValue* tsil_llvm_create_uint16(XTL* m, unsigned short value);
XLValue* tsil_llvm_create_uint32(XTL* m, unsigned int value);
XLValue* tsil_llvm_create_uint64(XTL* m, unsigned long value);
XLValue* tsil_llvm_create_float(XTL* m, float value);
XLValue* tsil_llvm_create_double(XTL* m, double value);
XLValue* tsil_llvm_create_string(XTL* m, char* value);

XLType* tsil_llvm_get_type(XTL* m, XLValue* value);
XLFunctionType* tsil_llvm_get_as_function_type(XTL* m, XLValue* value);
XLFunctionType* tsil_llvm_get_function_type(XTL* m, XLFunction* f);

XLValue* tsil_llvm_get_function_arg_value(XTL* m,
                                          XLFunction* f,
                                          unsigned long index);

XLType* tsil_llvm_create_function_type(XTL* m,
                                       XLType* ret_type,
                                       unsigned long params_size,
                                       XLType** params,
                                       unsigned long isVarArg);

XLValue* tsil_llvm_get_null(XTL* m);

char* dumpLL(XTL* m);
}