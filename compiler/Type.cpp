#include "tk.h"

namespace tsil::tk {
  bool Type::equals(Type* other) {
    if (this == other) {
      return true;
    }
    if (this->type != other->type) {
      return false;
    }
    if (this->type == TypeTypeDiia) {
      if (this->diiaParameters.size() != other->diiaParameters.size()) {
        return false;
      }
      for (size_t i = 0; i < this->diiaParameters.size(); i++) {
        if (!this->diiaParameters[i].type->equals(
                other->diiaParameters[i].type)) {
          return false;
        }
      }
      return this->diiaReturnType->equals(other->diiaReturnType);
    }
    if (this->type == TypeTypePointer) {
      if (other->pointerTo) {
        if (this->pointerTo) {
          return this->pointerTo->equals(other->pointerTo);
        }
      } else {
        return true;
      }
      return false;
    }
    return false;
  }

  bool Type::isPointer() {
    return this->type == TypeTypePointer;
  }

  bool Type::isArray() {
    return this->type == TypeTypeArray;
  }

  std::string Type::getFullName() {
    if (this->type == TypeTypeDiia) {
      std::string result = "";
      if (!this->diiaParameters.empty()) {
        if (this->diiaParameters.size() == 1) {
          result += this->diiaParameters[0].type->getFullName();
        } else {
          result += "(";
          bool first = true;
          for (const auto& diia_parameter : this->diiaParameters) {
            if (!first) {
              result += ", ";
            }
            first = false;
            result += diia_parameter.type->getFullName();
          }
          result += ")";
        }
      }
      const auto resultFullName = this->diiaReturnType->getFullName();
      result += " -> " + (this->diiaReturnType->type == TypeTypeDiia
                              ? "(" + resultFullName + ")"
                              : resultFullName);
      return result;
    }
    if (this->type == TypeTypePointer) {
      if (this->pointerTo) {
        return "комірка<" + this->pointerTo->getFullName() + ">";
      } else {
        return "невідома_комірка";
      }
    }
    if (this->type == TypeTypeArray) {
      return this->arrayOf->getFullName() + "[" +
             std::to_string(this->arraySize) + "]";
    }
    std::string result = this->name;
    if (!this->genericValues.empty()) {
      result += "<";
      bool first = true;
      for (const auto& generic_value_type : this->genericValues) {
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

  Type* Type::getPointerType(Scope* scope) {
    if (this->cachedPointerType) {
      return this->cachedPointerType;
    }
    const auto type = new Type();
    type->type = TypeTypePointer;
    type->name = "комірка";
    type->pointerTo = this;
    type->genericValues.push_back(this);
    type->xType = this->xType->getPointerType(scope->compiler->xModule);
    this->cachedPointerType = type;
    return type;
  }

  Type* Type::getArrayType(tsil::tk::Scope* scope, size_t size) {
    const auto type = new Type();
    type->type = TypeTypeArray;
    type->name = "";
    type->arraySize = size;
    type->arrayOf = this;
    type->xType = this->xType->getArrayType(scope->compiler->xModule, size);
    return type;
  }

  size_t Type::getBytesSize(tsil::tk::Scope* scope) {
    if (this->type == TypeTypePointer) {
      return 8;
    }
    if (this->type == TypeTypeDiia) {
      return 8;
    }
    if (this == scope->compiler->int1Type) {
      return 1;
    }
    if (this == scope->compiler->int8Type) {
      return 1;
    }
    if (this == scope->compiler->int32Type) {
      return 4;
    }
    if (this == scope->compiler->int64Type) {
      return 8;
    }
    if (this == scope->compiler->uint8Type) {
      return 1;
    }
    if (this == scope->compiler->uint32Type) {
      return 4;
    }
    if (this == scope->compiler->uint64Type) {
      return 8;
    }
    if (this == scope->compiler->d32Type) {
      return 4;
    }
    if (this == scope->compiler->d64Type) {
      return 8;
    }
    if (this == scope->compiler->doubleType) {
      return 8;
    }
    if (this->type == TypeTypeStructureInstance) {
      size_t result = 0;
      for (const auto& field : this->structureInstanceFields) {
        result += field.second.type->getBytesSize(scope);
      }
      return result;
    }
    return 0;
  }

  bool Type::isComparable(Scope* scope) {
    return this == scope->compiler->int1Type ||
           this == scope->compiler->int8Type ||
           this == scope->compiler->int32Type ||
           this == scope->compiler->int64Type ||
           this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type ||
           this == scope->compiler->d32Type ||
           this == scope->compiler->d64Type ||
           this == scope->compiler->doubleType || this->type == TypeTypePointer;
  }

  bool Type::isUnsigned(tsil::tk::Scope* scope) {
    return this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type || this->type == TypeTypePointer;
  }

  bool Type::isFloating(tsil::tk::Scope* scope) {
    return this == scope->compiler->d32Type ||
           this == scope->compiler->d64Type ||
           this == scope->compiler->doubleType;
  }

  bool Type::isArithmetical(tsil::tk::Scope* scope) {
    return this->isComparable(scope);
  }

  bool Type::isBitwisible(tsil::tk::Scope* scope) {
    return this == scope->compiler->int8Type ||
           this == scope->compiler->int32Type ||
           this == scope->compiler->int64Type ||
           this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type || this->type == TypeTypePointer;
  }
} // namespace tsil::tk