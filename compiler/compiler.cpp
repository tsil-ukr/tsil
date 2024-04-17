#include "compiler.h"

namespace tsil::compiler {
  bool CompilationScope::has_variable(const std::string& name) const {
    if (this->variables.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->has_variable(name);
    }
    return false;
  }

  std::pair<Type*, llvm::Value*> CompilationScope::get_variable(
      const std::string& name) {
    if (this->variables.contains(name)) {
      return this->variables[name];
    }
    if (this->parent) {
      return this->parent->get_variable(name);
    }
    return {nullptr, nullptr};
  }

  void CompilationScope::set_variable(const std::string& name,
                                      std::pair<Type*, llvm::Value*> value) {
    this->variables.insert_or_assign(name, value);
  }

  llvm::AllocaInst* CompilationScope::createEntryBlockAlloca(
      llvm::Type* T,
      llvm::Function* F) {
    llvm::IRBuilder<> TmpB(&F->getEntryBlock(), F->getEntryBlock().begin());
    return TmpB.CreateAlloca(T, nullptr, "var");
  }

  MakeTypeResult CompilationScope::makeType(const std::string& name,
                                            std::vector<Type*> generic_values) {
    if (name == "комірка") {
      if (generic_values.empty()) {
        return {this->state->voidPointerType};
      }
      const auto type = generic_values[0]->getPointerType();
      return {type, ""};
    }
    if (this->state->types.contains(name)) {
      if (!generic_values.empty()) {
        return {nullptr, "Тип \"" + name + "\" не є шаблонним"};
      }
      return {this->state->types[name], ""};
    }
    if (this->state->structures.contains(name)) {
      const auto structure = this->state->structures[name];
      if (this->state->types_cache.contains({structure, generic_values})) {
        return {this->state->types_cache[{structure, generic_values}], ""};
      }
      if (structure->generic_definitions.size() != generic_values.size()) {
        return {nullptr, "Невірна кількість параметрів шаблону"};
      }
      const auto type = new Type();
      type->type = TypeTypeStructureInstance;
      type->name = name;
      type->generic_values = generic_values;
      state->types_cache.insert_or_assign({structure, generic_values}, type);
      std::vector<llvm::Type*> LSElements;
      for (const auto& [structure_field_name, structure_field] :
           structure->fields) {
        if (structure_field.type) {
          type->structure_instance_fields.insert_or_assign(
              structure_field_name,
              TypeStructureField{.index = structure_field.index,
                                 .type = structure_field.type});
          LSElements.push_back(structure_field.type->LT);
        } else {
          const auto generic_type =
              generic_values[structure_field.generic_type_index];
          type->structure_instance_fields.insert_or_assign(
              structure_field_name,
              TypeStructureField{.index = structure_field.index,
                                 .type = generic_type});
          LSElements.push_back(generic_type->LT);
        }
      }
      type->LT =
          llvm::StructType::create(*this->state->Context, LSElements, "ST");
      return {type, ""};
    }
    return {nullptr, "Структуру \"" + name + "\" не знайдено"};
  }

  MakeTypeResult CompilationScope::makeTypeFromTypeNodeASTValue(
      tsil::ast::ASTValue* ast_value) {
    const auto type_node = ast_value->data.TypeNode;
    const auto type_name = type_node->id;
    std::vector<Type*> generic_values;
    for (const auto& generic_ast_value : type_node->generics) {
      const auto generic_type_node = generic_ast_value->data.TypeNode;
      const auto generic_type_result = this->makeType(
          generic_type_node->id, {}); // todo: handle inner generics
      if (!generic_type_result.type) {
        return {nullptr, generic_type_result.error};
      }
      generic_values.push_back(generic_type_result.type);
    }
    const auto type_result = this->makeType(type_name, generic_values);
    if (!type_result.type) {
      return {nullptr, type_result.error};
    }
    return {type_result.type, ""};
  }

  Structure* CompilationScope::createStructure(
      const std::string& name,
      const std::vector<std::string>& generic_definitions,
      const std::map<std::string, StructureField>& fields) {
    const auto structure = new Structure();
    structure->name = name;
    structure->generic_definitions = generic_definitions;
    structure->fields = fields;
    return structure;
  }

  llvm::Value* Type::castToLV(CompilationScope* scope,
                              Type* target_type,
                              llvm::Value* LV) {
    if (this == target_type) {
      return LV;
    }
    if (this->type == TypeTypePointer && target_type->type == TypeTypePointer) {
      return scope->state->Builder->CreatePointerCast(LV, target_type->LT);
    }
    if (this == scope->state->voidPointerType &&
        target_type->type == TypeTypePointer) {
      return scope->state->Builder->CreatePointerCast(LV, target_type->LT);
    }
    if (this->type == TypeTypePointer &&
        target_type == scope->state->voidPointerType) {
      return scope->state->Builder->CreatePointerCast(LV, target_type->LT);
    }
    if (this == scope->state->int8Type &&
        target_type == scope->state->int16Type) {
      return scope->state->Builder->CreateSExt(LV, target_type->LT);
    }
    if (this == scope->state->int8Type &&
        target_type == scope->state->int32Type) {
      return scope->state->Builder->CreateSExt(LV, target_type->LT);
    }
    if (this == scope->state->int8Type &&
        target_type == scope->state->int64Type) {
      return scope->state->Builder->CreateSExt(LV, target_type->LT);
    }
    if (this == scope->state->int16Type &&
        target_type == scope->state->int32Type) {
      return scope->state->Builder->CreateSExt(LV, target_type->LT);
    }
    if (this == scope->state->int16Type &&
        target_type == scope->state->int64Type) {
      return scope->state->Builder->CreateSExt(LV, target_type->LT);
    }
    if (this == scope->state->int32Type &&
        target_type == scope->state->int64Type) {
      return scope->state->Builder->CreateSExt(LV, target_type->LT);
    }
    if (this == scope->state->int16Type &&
        target_type == scope->state->int8Type) {
      return scope->state->Builder->CreateTrunc(LV, target_type->LT);
    }
    if (this == scope->state->int32Type &&
        target_type == scope->state->int8Type) {
      return scope->state->Builder->CreateTrunc(LV, target_type->LT);
    }
    if (this == scope->state->int32Type &&
        target_type == scope->state->int16Type) {
      return scope->state->Builder->CreateTrunc(LV, target_type->LT);
    }
    if (this == scope->state->int64Type &&
        target_type == scope->state->int8Type) {
      return scope->state->Builder->CreateTrunc(LV, target_type->LT);
    }
    if (this == scope->state->int64Type &&
        target_type == scope->state->int16Type) {
      return scope->state->Builder->CreateTrunc(LV, target_type->LT);
    }
    if (this == scope->state->int64Type &&
        target_type == scope->state->int32Type) {
      return scope->state->Builder->CreateTrunc(LV, target_type->LT);
    }
    if (this == scope->state->floatType &&
        target_type == scope->state->int8Type) {
      return scope->state->Builder->CreateFPToSI(LV, target_type->LT);
    }
    if (this == scope->state->floatType &&
        target_type == scope->state->int16Type) {
      return scope->state->Builder->CreateFPToSI(LV, target_type->LT);
    }
    if (this == scope->state->floatType &&
        target_type == scope->state->int32Type) {
      return scope->state->Builder->CreateFPToSI(LV, target_type->LT);
    }
    if (this == scope->state->floatType &&
        target_type == scope->state->int64Type) {
      return scope->state->Builder->CreateFPToSI(LV, target_type->LT);
    }
    if (this == scope->state->int8Type &&
        target_type == scope->state->floatType) {
      return scope->state->Builder->CreateSIToFP(LV, target_type->LT);
    }
    if (this == scope->state->int16Type &&
        target_type == scope->state->floatType) {
      return scope->state->Builder->CreateSIToFP(LV, target_type->LT);
    }
    if (this == scope->state->int32Type &&
        target_type == scope->state->floatType) {
      return scope->state->Builder->CreateSIToFP(LV, target_type->LT);
    }
    if (this == scope->state->int64Type &&
        target_type == scope->state->floatType) {
      return scope->state->Builder->CreateSIToFP(LV, target_type->LT);
    }
    return nullptr;
  }

  std::string Type::getFullName() {
    std::string result = this->name;
    if (!this->generic_values.empty()) {
      result += "<";
      bool first = true;
      for (const auto& generic_value_type : this->generic_values) {
        if (!first) {
          result += ", ";
        }
        first = false;
        result += generic_value_type->getFullName();
      }
      result += ">";
    }
    return result;
  }

  Type* Type::getPointerType() {
    if (this->cached_pointer_type) {
      return this->cached_pointer_type;
    }
    const auto type = new Type();
    type->type = TypeTypePointer;
    type->name = "комірка";
    type->pointer_to = this;
    type->generic_values.push_back(this);
    type->LT = llvm::PointerType::get(this->LT, 0);
    this->cached_pointer_type = type;
    return type;
  }

  size_t Type::getSizeOf(CompilationScope* scope) {
    return 0; // todo
  }
} // namespace tsil::compiler