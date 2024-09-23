extern "C" {
#ifndef XL_MODULE_TYPE
#define XL_MODULE_TYPE void
#endif
#ifndef XL_TYPE_TYPE
#define XL_TYPE_TYPE void
#endif
#ifndef XL_FUNCTION_TYPE_TYPE
#define XL_FUNCTION_TYPE_TYPE void
#endif
#ifndef XL_VALUE_TYPE
#define XL_VALUE_TYPE void
#endif
#ifndef XL_BASIC_BLOCK_TYPE
#define XL_BASIC_BLOCK_TYPE void
#endif

typedef XL_MODULE_TYPE XLModule;
typedef XL_TYPE_TYPE XLType;
typedef XL_FUNCTION_TYPE_TYPE XLFunctionType;
typedef XL_VALUE_TYPE XLValue;
typedef XL_BASIC_BLOCK_TYPE XLBasicBlock;
typedef struct XLFunction {
  void* llvm_function;
  XLBasicBlock* alloca_block;
  XLBasicBlock* entry_block;
  XLBasicBlock* exit_block;
  XLValue* return_alloca;
  XLType* result_type;
} XLFunction;

XLModule* tsil_xl_create_module(char* name);

XLType* tsil_xl_create_struct(XLModule* m, char* name);
XLType* tsil_xl_set_struct_fields(XLModule* m,
                                  XLType* st,
                                  int fields_size,
                                  XLType** fields);

XLFunction* tsil_xl_declare_function(XLModule* m,
                                     char* name,
                                     XLType* ret_type,
                                     int params_size,
                                     XLType** params,
                                     bool isVarArg);
XLBasicBlock* tsil_xl_create_function_block(XLModule* m,
                                            XLFunction* f,
                                            char* name);

XLValue* tsil_xl_inst_alloca(XLModule* m,
                             XLBasicBlock* block,
                             char* name,
                             XLType* type);
XLValue* tsil_xl_inst_getelementptr(XLModule* m,
                                    XLBasicBlock* block,
                                    XLType* type,
                                    XLValue* pointer,
                                    int indices_size,
                                    XLValue** indices);
void tsil_xl_inst_store(XLModule* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLValue* pointer);
XLValue* tsil_xl_inst_load(XLModule* m,
                           XLBasicBlock* block,
                           XLType* type,
                           XLValue* pointer);
XLValue* tsil_xl_inst_ret(XLModule* m, XLBasicBlock* block, XLValue* value);
XLValue* tsil_xl_inst_call_value(XLModule* m,
                                 XLBasicBlock* block,
                                 XLFunctionType* ft,
                                 XLValue* value,
                                 int arguments_size,
                                 XLValue** arguments);
XLValue* tsil_xl_inst_call_func(XLModule* m,
                                XLBasicBlock* block,
                                XLFunction* func,
                                int arguments_size,
                                XLValue** arguments);
void tsil_xl_inst_br(XLModule* m, XLBasicBlock* block, XLBasicBlock* target);
void tsil_xl_inst_br_if(XLModule* m,
                        XLBasicBlock* block,
                        XLValue* condition,
                        XLBasicBlock* target_true,
                        XLBasicBlock* target_false);
XLValue* tsil_xl_inst_icmp(XLModule* m,
                           XLBasicBlock* block,
                           char* op,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_fcmp(XLModule* m,
                           XLBasicBlock* block,
                           char* op,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_add(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_fadd(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_sub(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_fsub(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_mul(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_fmul(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_udiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_sdiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_fdiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_mod(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_fmod(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_and(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_or(XLModule* m,
                         XLBasicBlock* block,
                         XLValue* left,
                         XLValue* right);
XLValue* tsil_xl_inst_xor(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_shl(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right);
XLValue* tsil_xl_inst_lshr(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_ashr(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_xl_inst_trunc(XLModule* m,
                            XLBasicBlock* block,
                            XLValue* value,
                            XLType* toType);
XLValue* tsil_xl_inst_zext(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* value,
                           XLType* toType);
XLValue* tsil_xl_inst_sext(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* value,
                           XLType* toType);
XLValue* tsil_xl_inst_fptrunc(XLModule* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType);
XLValue* tsil_xl_inst_fpext(XLModule* m,
                            XLBasicBlock* block,
                            XLValue* value,
                            XLType* toType);
XLValue* tsil_xl_inst_fptoui(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_xl_inst_fptosi(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_xl_inst_uitofp(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_xl_inst_sitofp(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_xl_inst_ptrtoint(XLModule* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_xl_inst_inttoptr(XLModule* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_xl_inst_bitcast(XLModule* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType);

XLType* tsil_xl_type_get_pointer_to(XLModule* m, XLType* type);
XLType* tsil_xl_type_get_array_of(XLModule* m, XLType* type, int size);

XLType* tsil_xl_get_void_type(XLModule* m);
XLType* tsil_xl_get_pointer_type(XLModule* m);
XLType* tsil_xl_get_int1_type(XLModule* m);
XLType* tsil_xl_get_int8_type(XLModule* m);
XLType* tsil_xl_get_int16_type(XLModule* m);
XLType* tsil_xl_get_int32_type(XLModule* m);
XLType* tsil_xl_get_int64_type(XLModule* m);
XLType* tsil_xl_get_float32_type(XLModule* m);
XLType* tsil_xl_get_float64_type(XLModule* m);

XLValue* tsil_xl_create_int32(XLModule* m, int value);
XLValue* tsil_xl_create_int64(XLModule* m, long value);
XLValue* tsil_xl_create_double(XLModule* m, double value);
XLValue* tsil_xl_create_string(XLModule* m, char* value);

XLType* tsil_xl_get_type(XLModule* m, XLValue* value);
XLFunctionType* tsil_xl_get_as_function_type(XLModule* m, XLValue* value);

XLValue* tsil_xl_get_function_arg_value(XLModule* m, XLFunction* f, int index);

XLType* tsil_xl_create_function_type(XLModule* m,
                                     XLType* ret_type,
                                     int params_size,
                                     XLType** params,
                                     bool isVarArg);

XLValue* tsil_xl_get_null(XLModule* m);

char* dumpLL(XLModule* m);
}