#include "x.h"

namespace tsil::x {
  void implode(std::vector<std::string>& v,
               const std::string& sep,
               std::string& result) {
    for (size_t i = 0; i < v.size(); i++) {
      result += v[i];
      if (i < v.size() - 1) {
        result += sep;
      }
    }
  }

  std::string Module::computeNextName(const std::string& prefix) {
    if (TSIL_X_EXPANDED_NAMES == "1") {
      return "" + prefix + "." + std::to_string(this->variable_counter++) + "";
    }
    return "n." + std::to_string(this->variable_counter++);
  }

  std::string Module::computeNextVarName(const std::string& prefix) {
    if (TSIL_X_EXPANDED_NAMES == "1") {
      return "%\"" + prefix + "." + std::to_string(this->variable_counter++) +
             "\"";
    }
    return "%v." + std::to_string(this->variable_counter++);
  }

  std::string Module::computeNextGlobalName(const std::string& prefix) {
    if (TSIL_X_EXPANDED_NAMES == "1") {
      return "@\"" + prefix + "." + std::to_string(this->variable_counter++) +
             "\"";
    }
    return "@v." + std::to_string(this->variable_counter++);
  }

  Value* Module::putGlobal(const std::string& attributes,
                           tsil::x::Type* type,
                           tsil::x::Value* value) {
    auto global = new Global();
    global->attributes = attributes;
    global->name = this->computeNextGlobalName("global");
    global->type = type;
    global->value = value;
    this->globals[global->name] = global;
    return new Value(this->pointerType, global->name);
  }

  Value* Module::putStringConstant(const std::string& attributes,
                                   const std::string& value) {
    auto constant = new Constant();
    constant->attributes = attributes;
    constant->name = this->computeNextGlobalName("const");
    constant->type = this->pointerType;
    constant->value = value;
    this->constants[constant->name] = constant;
    return new Value(this->pointerType, constant->name);
  }

  Type* Module::defineNativeType(const std::string& name) {
    auto type = new Type();
    type->type = TypeTypeNative;
    type->name = name;
    this->types[name] = type;
    return type;
  }

  Type* Module::defineStructType(const std::string& name,
                                 std::vector<Type*> fields) {
    auto type = new Type();
    type->type = TypeTypeType;
    type->name = this->computeNextVarName(name);
    type->fields = fields;
    this->types[type->name] = type;
    return type;
  }

  std::pair<Function*, Value*> Module::declareFunction(
      const std::string& attributes,
      const std::string& name,
      Type* result_type,
      std::vector<Value*> parameters) {
    auto function = new Function();
    function->attributes = attributes;
    function->name = "@\"" + name + "\"";
    function->result_type = result_type;
    function->parameters = parameters;
    this->functions[name] = function;
    return {function, new Value(this->pointerType, function->name)};
  }

  Value* Module::defineFunction(const std::string& attributes,
                                const std::string& name,
                                Type* result_type,
                                std::vector<Value*> parameters) {
    auto function = new Function();
    function->attributes = attributes;
    function->name = "@" + name;
    function->result_type = result_type;
    function->parameters = parameters;
    const auto entryBlock = this->defineFunctionBlock(function, "entry");
    if (result_type) {
      if (result_type != this->voidType) {
        function->return_alloca = this->pushFunctionBlockAllocaInstruction(
            entryBlock, "return", result_type);
        const auto exitBlock = this->defineFunctionBlock(function, "exit");
        const auto loadedReturnValue = this->pushFunctionBlockLoadInstruction(
            exitBlock, result_type, function->return_alloca);
        this->pushFunctionBlockRetInstruction(exitBlock, result_type,
                                              loadedReturnValue);
      }
    }
    this->functions[name] = function;
    return new Value(this->pointerType, function->name);
  }

  FunctionBlock* Module::defineFunctionBlock(Function* function,
                                             const std::string& name) {
    auto block = new FunctionBlock();
    if (TSIL_X_EXPANDED_NAMES == "1") {
      block->name = name + "." + std::to_string(function->blocks.size());
    } else {
      block->name = "b." + std::to_string(this->variable_counter++);
    }
    function->blocks.push_back(block);
    return block;
  }

  FunctionBlock* Module::getFunctionBlock(Function* function,
                                          const std::string& name) {
    for (const auto& b : function->blocks) {
      if (b->name == name) {
        return b;
        break;
      }
    }
    return nullptr;
  }

  Value* Module::pushFunctionBlockAllocaInstruction(FunctionBlock* block,
                                                    const std::string& name,
                                                    tsil::x::Type* type) {
    const auto instruction = new FunctionInstruction();
    const auto alloca = new FunctionInstructionAlloca();
    alloca->type = type;
    instruction->name = this->computeNextVarName(name);
    instruction->alloca = alloca;
    block->instructions.push_back(instruction);
    return new Value(this->pointerType, instruction->name);
  }

  Value* Module::pushFunctionBlockGetElementPtrInstruction(
      FunctionBlock* block,
      Type* type,
      Value* pointer,
      const std::vector<Value*>& indexes) {
    const auto instruction = new FunctionInstruction();
    const auto getelementptr = new FunctionInstructionGetElementPtr();
    getelementptr->type = type;
    getelementptr->pointer = pointer;
    getelementptr->indexes = indexes;
    instruction->name = this->computeNextVarName("getelementptr");
    instruction->getelementptr = getelementptr;
    block->instructions.push_back(instruction);
    return new Value(this->pointerType, instruction->name);
  }

  FunctionInstruction* Module::pushFunctionBlockStoreInstruction(
      FunctionBlock* block,
      Type* type,
      Value* value,
      Value* pointer) {
    const auto instruction = new FunctionInstruction();
    const auto store = new FunctionInstructionStore();
    store->type = type;
    store->value = value;
    store->pointer = pointer;
    instruction->store = store;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockLoadInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* pointer) {
    const auto instruction = new FunctionInstruction();
    const auto load = new FunctionInstructionLoad();
    load->type = type;
    load->pointer = pointer;
    instruction->name = this->computeNextVarName("load");
    instruction->load = load;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  FunctionInstruction* Module::pushFunctionBlockRetInstruction(
      FunctionBlock* block,
      Type* type,
      Value* value) {
    const auto instruction = new FunctionInstruction();
    const auto ret = new FunctionInstructionRet();
    ret->type = type;
    ret->value = value;
    instruction->ret = ret;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockCallInstruction(
      FunctionBlock* block,
      Type* type,
      Value* value,
      std::vector<Value*> arguments) {
    const auto instruction = new FunctionInstruction();
    const auto call = new FunctionInstructionCall();
    call->type = type;
    call->value = value;
    call->arguments = arguments;
    instruction->name = this->computeNextVarName("call");
    instruction->call = call;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  FunctionInstruction* Module::pushFunctionBlockBrInstruction(
      FunctionBlock* block,
      FunctionBlock* target) {
    const auto instruction = new FunctionInstruction();
    const auto br = new FunctionInstructionBr();
    br->target = target;
    instruction->br = br;
    block->instructions.push_back(instruction);
    return instruction;
  }

  FunctionInstruction* Module::pushFunctionBlockBrIfInstruction(
      FunctionBlock* block,
      Value* condition,
      FunctionBlock* target_true,
      FunctionBlock* target_false) {
    const auto instruction = new FunctionInstruction();
    const auto brif = new FunctionInstructionBrIf();
    brif->condition = condition;
    brif->target_true = target_true;
    brif->target_false = target_false;
    instruction->brif = brif;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockICmpInstruction(FunctionBlock* block,
                                                  const std::string& op,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto icmp = new FunctionInstructionICmp();
    icmp->op = op;
    icmp->type = type;
    icmp->left = left;
    icmp->right = right;
    instruction->name = this->computeNextVarName("icmp");
    instruction->icmp = icmp;
    block->instructions.push_back(instruction);
    return new Value(this->int1Type, instruction->name);
  }

  Value* Module::pushFunctionBlockFCmpInstruction(FunctionBlock* block,
                                                  const std::string& op,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto fcmp = new FunctionInstructionFCmp();
    fcmp->op = op;
    fcmp->type = type;
    fcmp->left = left;
    fcmp->right = right;
    instruction->name = this->computeNextVarName("fcmp");
    instruction->fcmp = fcmp;
    block->instructions.push_back(instruction);
    return new Value(this->int1Type, instruction->name);
  }

  Value* Module::pushFunctionBlockAddInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto add = new FunctionInstructionAdd();
    add->type = type;
    add->left = left;
    add->right = right;
    instruction->name = this->computeNextVarName("add");
    instruction->add = add;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockFAddInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto fadd = new FunctionInstructionFAdd();
    fadd->type = type;
    fadd->left = left;
    fadd->right = right;
    instruction->name = this->computeNextVarName("fadd");
    instruction->fadd = fadd;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockSubInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto sub = new FunctionInstructionSub();
    sub->type = type;
    sub->left = left;
    sub->right = right;
    instruction->name = this->computeNextVarName("sub");
    instruction->sub = sub;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockFSubInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto fsub = new FunctionInstructionFSub();
    fsub->type = type;
    fsub->left = left;
    fsub->right = right;
    instruction->name = this->computeNextVarName("fsub");
    instruction->fsub = fsub;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockMulInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto mul = new FunctionInstructionMul();
    mul->type = type;
    mul->left = left;
    mul->right = right;
    instruction->name = this->computeNextVarName("mul");
    instruction->mul = mul;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockFMulInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto fmul = new FunctionInstructionFMul();
    fmul->type = type;
    fmul->left = left;
    fmul->right = right;
    instruction->name = this->computeNextVarName("fmul");
    instruction->fmul = fmul;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockDivInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto div = new FunctionInstructionDiv();
    div->type = type;
    div->left = left;
    div->right = right;
    instruction->name = this->computeNextVarName("div");
    instruction->div = div;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockFDivInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto fdiv = new FunctionInstructionFDiv();
    fdiv->type = type;
    fdiv->left = left;
    fdiv->right = right;
    instruction->name = this->computeNextVarName("fdiv");
    instruction->fdiv = fdiv;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockModInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto mod = new FunctionInstructionMod();
    mod->type = type;
    mod->left = left;
    mod->right = right;
    instruction->name = this->computeNextVarName("mod");
    instruction->mod = mod;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockFModInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto fmod = new FunctionInstructionFMod();
    fmod->type = type;
    fmod->left = left;
    fmod->right = right;
    instruction->name = this->computeNextVarName("fmod");
    instruction->fmod = fmod;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockAndInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto and_ = new FunctionInstructionAnd();
    and_->type = type;
    and_->left = left;
    and_->right = right;
    instruction->name = this->computeNextVarName("and");
    instruction->and_ = and_;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockOrInstruction(FunctionBlock* block,
                                                Type* type,
                                                Value* left,
                                                Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto or_ = new FunctionInstructionOr();
    or_->type = type;
    or_->left = left;
    or_->right = right;
    instruction->name = this->computeNextVarName("or");
    instruction->or_ = or_;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockXorInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto xor_ = new FunctionInstructionXor();
    xor_->type = type;
    xor_->left = left;
    xor_->right = right;
    instruction->name = this->computeNextVarName("xor");
    instruction->xor_ = xor_;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockShlInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto shl = new FunctionInstructionShl();
    shl->type = type;
    shl->left = left;
    shl->right = right;
    instruction->name = this->computeNextVarName("shl");
    instruction->shl = shl;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockLShrInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto lshr = new FunctionInstructionLShr();
    lshr->type = type;
    lshr->left = left;
    lshr->right = right;
    instruction->name = this->computeNextVarName("lshr");
    instruction->lshr = lshr;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockAShrInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto ashr = new FunctionInstructionAShr();
    ashr->type = type;
    ashr->left = left;
    ashr->right = right;
    instruction->name = this->computeNextVarName("ashr");
    instruction->ashr = ashr;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockTruncInstruction(FunctionBlock* block,
                                                   Type* type,
                                                   Value* value,
                                                   Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto trunc = new FunctionInstructionTrunc();
    trunc->type = type;
    trunc->value = value;
    trunc->toType = toType;
    instruction->name = this->computeNextVarName("trunc");
    instruction->trunc = trunc;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockZextInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* value,
                                                  Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto zext = new FunctionInstructionZext();
    zext->type = type;
    zext->value = value;
    zext->toType = toType;
    instruction->name = this->computeNextVarName("zext");
    instruction->zext = zext;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockSextInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* value,
                                                  Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto sext = new FunctionInstructionSext();
    sext->type = type;
    sext->value = value;
    sext->toType = toType;
    instruction->name = this->computeNextVarName("sext");
    instruction->sext = sext;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockFptruncInstruction(FunctionBlock* block,
                                                     Type* type,
                                                     Value* value,
                                                     Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto fptrunc = new FunctionInstructionFptrunc();
    fptrunc->type = type;
    fptrunc->value = value;
    fptrunc->toType = toType;
    instruction->name = this->computeNextVarName("fptrunc");
    instruction->fptrunc = fptrunc;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockFpextInstruction(FunctionBlock* block,
                                                   Type* type,
                                                   Value* value,
                                                   Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto fpext = new FunctionInstructionFpext();
    fpext->type = type;
    fpext->value = value;
    fpext->toType = toType;
    instruction->name = this->computeNextVarName("fpext");
    instruction->fpext = fpext;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockFptouiInstruction(FunctionBlock* block,
                                                    Type* type,
                                                    Value* value,
                                                    Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto fptoui = new FunctionInstructionFptoui();
    fptoui->type = type;
    fptoui->value = value;
    fptoui->toType = toType;
    instruction->name = this->computeNextVarName("fptoui");
    instruction->fptoui = fptoui;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockFptosiInstruction(FunctionBlock* block,
                                                    Type* type,
                                                    Value* value,
                                                    Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto fptosi = new FunctionInstructionFptosi();
    fptosi->type = type;
    fptosi->value = value;
    fptosi->toType = toType;
    instruction->name = this->computeNextVarName("fptosi");
    instruction->fptosi = fptosi;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockUitofpInstruction(FunctionBlock* block,
                                                    Type* type,
                                                    Value* value,
                                                    Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto uitofp = new FunctionInstructionUitofp();
    uitofp->type = type;
    uitofp->value = value;
    uitofp->toType = toType;
    instruction->name = this->computeNextVarName("uitofp");
    instruction->uitofp = uitofp;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockSitofpInstruction(FunctionBlock* block,
                                                    Type* type,
                                                    Value* value,
                                                    Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto sitofp = new FunctionInstructionSitofp();
    sitofp->type = type;
    sitofp->value = value;
    sitofp->toType = toType;
    instruction->name = this->computeNextVarName("sitofp");
    instruction->sitofp = sitofp;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockPtrtointInstruction(FunctionBlock* block,
                                                      Type* type,
                                                      Value* value,
                                                      Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto ptrtoint = new FunctionInstructionPtrtoint();
    ptrtoint->type = type;
    ptrtoint->value = value;
    ptrtoint->toType = toType;
    instruction->name = this->computeNextVarName("ptrtoint");
    instruction->ptrtoint = ptrtoint;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  Value* Module::pushFunctionBlockInttoptrInstruction(FunctionBlock* block,
                                                      Type* type,
                                                      Value* value,
                                                      Type* toType) {
    const auto instruction = new FunctionInstruction();
    const auto inttoptr = new FunctionInstructionInttoptr();
    inttoptr->type = type;
    inttoptr->value = value;
    inttoptr->toType = toType;
    instruction->name = this->computeNextVarName("inttoptr");
    instruction->inttoptr = inttoptr;
    block->instructions.push_back(instruction);
    return new Value(toType, instruction->name);
  }

  std::string Module::dumpLL() {
    std::vector<std::string> lines;

    lines.push_back("target triple = \"" + this->targetTriple + "\"");

    for (const auto& [name, constant] : this->constants) {
      lines.push_back(constant->dumpLL(this));
    }

    for (const auto& [name, global] : this->globals) {
      lines.push_back(global->dumpLL(this));
    }

    for (const auto& [name, type] : this->types) {
      if (type->type == TypeTypeType) {
        lines.push_back(type->dumpLL(this));
      }
    }

    for (const auto& [name, function] : this->functions) {
      lines.push_back(function->dumpLL(this));
    }

    std::string result;
    implode(lines, "\n", result);
    return result;
  }

  std::string Value::dumpLL(tsil::x::Module* module) {
    return this->type->name + " " + this->name;
  }

  std::string Constant::dumpLL(Module* module) {
    std::string result = this->name + " = ";
    if (!this->attributes.empty()) {
      result += this->attributes;
      result += " ";
    }
    if (this->type == module->int8Type) {
      result += "constant " + this->type->name + " " + this->value;
    } else if (this->type == module->int64Type) {
      result += "constant " + this->type->name + " " + this->value;
    } else {
      result += "constant [" + std::to_string(this->value.size() + 1) +
                " x i8] c\"" + this->value + "\\00\"";
    }
    return result;
  }

  std::string Global::dumpLL(tsil::x::Module* module) {
    std::string result = this->name + " = ";
    if (!this->attributes.empty()) {
      result += this->attributes;
      result += " ";
    }
    result += "global ";
    result += this->type->name;
    result += " ";
    result += this->value->name;
    return result;
  }

  Type* Type::getPointerType(tsil::x::Module* module) {
    if (this->cachedPointerType) {
      return this->cachedPointerType;
    }
    const auto type = new Type();
    type->type = TypeTypePointer;
    type->name = "ptr";
    //    type->name = this->name + "*";
    type->pointerTo = this;
    this->cachedPointerType = type;
    return type;
  }

  Type* Type::getArrayType(tsil::x::Module* module, size_t size) {
    const auto type = new Type();
    type->type = TypeTypeArray;
    type->name = "[";
    type->name += std::to_string(size);
    type->name += " x ";
    type->name += this->name;
    type->name += "]";
    type->arraySize = size;
    type->arrayOf = this;
    return type;
  }

  size_t Type::getAlign() {
    if (this->type == TypeTypeNative) {
      return 0;
    }
    if (this->type == TypeTypePointer) {
      return 8;
    }
    if (0 == 4) {
      return 4;
    }
    if (this->type == TypeTypeArray) {
      return this->arrayOf->getAlign();
    }
    size_t align = 4;
    for (const auto& field : this->fields) {
      size_t field_align = field->getAlign();
      if (field_align > align) {
        align = field_align;
      }
    }
    return align;
  }

  std::string Type::dumpLL(Module* module) {
    if (this->type == TypeTypeNative) {
      return this->name;
    } else if (this->type == TypeTypeArray) {
      return this->name;
    } else {
      std::vector<std::string> fields;
      for (const auto& field : this->fields) {
        fields.push_back(field->name);
      }
      std::string result = this->name + " = type { ";
      implode(fields, ", ", result);
      result += " }";
      return result;
    }
  }

  std::string Function::dumpLL(Module* module) {
    std::vector<std::string> parameters;
    for (const auto& parameter : this->parameters) {
      parameters.push_back(parameter->dumpLL(module));
    }
    if (this->blocks.empty()) {
      std::string result = "declare ";
      if (!this->attributes.empty()) {
        result += this->attributes;
        result += " ";
      }
      result += this->result_type->name;
      result += " ";
      result += this->name;
      result += "(";
      implode(parameters, ", ", result);
      result += ")";
      return result;
    } else {
      std::string result = "define ";
      if (!this->attributes.empty()) {
        result += this->attributes;
        result += " ";
      }
      result += this->result_type->name;
      result += " ";
      result += this->name;
      result += "(";
      implode(parameters, ", ", result);
      result += ") {\n";
      std::vector<std::string> blocks;
      for (const auto& block : this->blocks) {
        blocks.push_back(block->dumpLL(module));
      }
      implode(blocks, "\n", result);
      result += "\n}";
      return result;
    }
  }

  std::string FunctionBlock::dumpLL(Module* module) {
    std::string result = this->name + ":\n";
    std::vector<std::string> instructions;
    for (const auto& instruction : this->instructions) {
      instructions.push_back((TSIL_X_EXPANDED_NAMES ? "  " : "") +
                             instruction->dumpLL(module));
    }
    implode(instructions, "\n", result);
    return result;
  }

  std::string FunctionInstruction::dumpLL(Module* module) {
    if (this->alloca) {
      return this->name + " = alloca " + this->alloca->type->name;
    }
    if (this->getelementptr) {
      std::vector<std::string> indexes;
      for (const auto& index : this->getelementptr->indexes) {
        indexes.push_back(index->dumpLL(module));
      }
      std::string result = this->name + " = getelementptr inbounds ";
      result += this->getelementptr->type->name;
      result += ", ";
      result += this->getelementptr->pointer->dumpLL(module);
      result += ", ";
      implode(indexes, ", ", result);
      return result;
    }
    if (this->store) {
      return "store " + this->store->type->name + " " +
             this->store->value->name + ", " +
             this->store->pointer->dumpLL(module);
    }
    if (this->load) {
      return this->name + " = load " + this->load->type->name + ", " +
             this->load->pointer->dumpLL(module);
    }
    if (this->ret) {
      if (this->ret->value == nullptr) {
        return "ret void";
      }
      return "ret " + this->ret->value->dumpLL(module);
    }
    if (this->call) {
      std::vector<std::string> arguments;
      for (const auto& argument : this->call->arguments) {
        arguments.push_back(argument->dumpLL(module));
      }
      std::string result;
      if (this->call->type == module->voidType) {
        result = "call ";
      } else {
        result = this->name + " = call ";
      }
      result += this->call->type->name;
      result += " ";
      result += this->call->value->name;
      result += "(";
      implode(arguments, ", ", result);
      result += ")";
      return result;
    }
    if (this->br) {
      return "br label %" + this->br->target->name;
    }
    if (this->brif) {
      return "br i1 " + this->brif->condition->name + ", label %" +
             this->brif->target_true->name + ", label %" +
             this->brif->target_false->name;
    }
    if (this->icmp) {
      return this->name + " = icmp " + this->icmp->op + " " +
             this->icmp->type->name + " " + this->icmp->left->name + ", " +
             this->icmp->right->name;
    }
    if (this->fcmp) {
      return this->name + " = fcmp " + this->fcmp->op + " " +
             this->fcmp->type->name + " " + this->fcmp->left->name + ", " +
             this->fcmp->right->name;
    }
    if (this->add) {
      return this->name + " = add " + this->add->type->name + " " +
             this->add->left->name + ", " + this->add->right->name;
    }
    if (this->fadd) {
      return this->name + " = fadd " + this->fadd->type->name + " " +
             this->fadd->left->name + ", " + this->fadd->right->name;
    }
    if (this->sub) {
      return this->name + " = sub " + this->sub->type->name + " " +
             this->sub->left->name + ", " + this->sub->right->name;
    }
    if (this->fsub) {
      return this->name + " = fsub " + this->fsub->type->name + " " +
             this->fsub->left->name + ", " + this->fsub->right->name;
    }
    if (this->mul) {
      return this->name + " = mul " + this->mul->type->name + " " +
             this->mul->left->name + ", " + this->mul->right->name;
    }
    if (this->fmul) {
      return this->name + " = fmul " + this->fmul->type->name + " " +
             this->fmul->left->name + ", " + this->fmul->right->name;
    }
    if (this->div) {
      return this->name + " = div " + this->div->type->name + " " +
             this->div->left->name + ", " + this->div->right->name;
    }
    if (this->fdiv) {
      return this->name + " = fdiv " + this->fdiv->type->name + " " +
             this->fdiv->left->name + ", " + this->fdiv->right->name;
    }
    if (this->mod) {
      return this->name + " = srem " + this->mod->type->name + " " +
             this->mod->left->name + ", " + this->mod->right->name;
    }
    if (this->fmod) {
      return this->name + " = frem " + this->fmod->type->name + " " +
             this->fmod->left->name + ", " + this->fmod->right->name;
    }
    if (this->and_) {
      return this->name + " = and " + this->and_->type->name + " " +
             this->and_->left->name + ", " + this->and_->right->name;
    }
    if (this->or_) {
      return this->name + " = or " + this->or_->type->name + " " +
             this->or_->left->name + ", " + this->or_->right->name;
    }
    if (this->xor_) {
      return this->name + " = xor " + this->xor_->type->name + " " +
             this->xor_->left->name + ", " + this->xor_->right->name;
    }
    if (this->shl) {
      return this->name + " = shl " + this->shl->type->name + " " +
             this->shl->left->name + ", " + this->shl->right->name;
    }
    if (this->lshr) {
      return this->name + " = lshr " + this->lshr->type->name + " " +
             this->lshr->left->name + ", " + this->lshr->right->name;
    }
    if (this->ashr) {
      return this->name + " = ashr " + this->ashr->type->name + " " +
             this->ashr->left->name + ", " + this->ashr->right->name;
    }
    if (this->trunc) {
      return this->name + " = trunc " + this->trunc->type->name + " " +
             this->trunc->value->name + " to " + this->trunc->toType->name;
    }
    if (this->zext) {
      return this->name + " = zext " + this->zext->type->name + " " +
             this->zext->value->name + " to " + this->zext->toType->name;
    }
    if (this->sext) {
      return this->name + " = sext " + this->sext->type->name + " " +
             this->sext->value->name + " to " + this->sext->toType->name;
    }
    if (this->fptrunc) {
      return this->name + " = fptrunc " + this->fptrunc->type->name + " " +
             this->fptrunc->value->name + " to " + this->fptrunc->toType->name;
    }
    if (this->fpext) {
      return this->name + " = fpext " + this->fpext->type->name + " " +
             this->fpext->value->name + " to " + this->fpext->toType->name;
    }
    if (this->fptoui) {
      return this->name + " = fptoui " + this->fptoui->type->name + " " +
             this->fptoui->value->name + " to " + this->fptoui->toType->name;
    }
    if (this->fptosi) {
      return this->name + " = fptosi " + this->fptosi->type->name + " " +
             this->fptosi->value->name + " to " + this->fptosi->toType->name;
    }
    if (this->uitofp) {
      return this->name + " = uitofp " + this->uitofp->type->name + " " +
             this->uitofp->value->name + " to " + this->uitofp->toType->name;
    }
    if (this->sitofp) {
      return this->name + " = sitofp " + this->sitofp->type->name + " " +
             this->sitofp->value->name + " to " + this->sitofp->toType->name;
    }
    if (this->ptrtoint) {
      return this->name + " = ptrtoint " + this->ptrtoint->type->name + " " +
             this->ptrtoint->value->name + " to " +
             this->ptrtoint->toType->name;
    }
    if (this->inttoptr) {
      return this->name + " = inttoptr " + this->inttoptr->type->name + " " +
             this->inttoptr->value->name + " to " +
             this->inttoptr->toType->name;
    }
    return "";
  }
} // namespace tsil::x