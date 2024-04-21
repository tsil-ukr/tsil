#include "tk.h"

namespace tsil::tk {
  std::string Type::getFullName() {
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
    type->xType = scope->compiler->xModule->pointerType;
    this->cachedPointerType = type;
    return type;
  }

  bool Type::isComparable(Scope* scope) {
    return this == scope->compiler->int1Type ||
           this == scope->compiler->int8Type ||
           this == scope->compiler->int32Type ||
           this == scope->compiler->int64Type ||
           this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type ||
           this == scope->compiler->floatType ||
           this == scope->compiler->doubleType;
  }

  bool Type::isUnsigned(tsil::tk::Scope* scope) {
    return this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type;
  }

  bool Type::isFloating(tsil::tk::Scope* scope) {
    return this == scope->compiler->floatType ||
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
           this == scope->compiler->uint64Type;
  }
} // namespace tsil::tk