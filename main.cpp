#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "compiler/compiler.h"

std::pair<size_t, std::string> strtrim(const std::string& str) {
  size_t start = 0;
  size_t end = str.size();
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
      start = i;
      break;
    }
  }
  for (size_t i = str.size(); i > 0; i--) {
    if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n' &&
        str[i - 1] != '\r') {
      end = i;
      break;
    }
  }
  const auto res = str.substr(start, end - start);
  return {start, res};
}

std::string strgetline(const std::string& code, size_t line) {
  size_t current_line = 1;
  size_t start = 0;
  size_t end = 0;
  for (size_t i = 0; i < code.size(); i++) {
    if (code[i] == '\n') {
      if (current_line == line) {
        end = i;
        break;
      }
      start = i + 1;
      current_line++;
    }
  }
  return code.substr(start, end - start);
}

void printCompilerError(const std::string& path,
                        const std::string& code,
                        const tsil::compiler::CompilerError* error) {
  const auto line = std::to_string(error->line);
  const auto column = std::to_string(error->column);
  const auto message = error->message;
  std::cerr << path << ":" << line + ":" + column + ": " << message
            << std::endl;
  const auto [new_start, code_line] = strtrim(strgetline(code, error->line));
  std::string prefix = line + "| ";
  std::cerr << prefix << code_line << std::endl;
  for (size_t i = 0; i < (error->column - new_start) + prefix.size(); i++) {
    std::cerr << " ";
  }
  std::cerr << "^" << std::endl;
}

void printParserError(const std::string& path,
                      const std::string& code,
                      const tsil::parser::TsilParserError* error) {
  const auto line = std::to_string(error->line);
  const auto column = std::to_string(error->column);
  const auto message = error->message;
  std::cerr << path << ":" << line + ":" + column + ": " << message
            << std::endl;
  const auto [new_start, code_line] = strtrim(strgetline(code, error->line));
  std::string prefix = line + "| ";
  std::cerr << prefix << code_line << std::endl;
  for (size_t i = 0; i < (error->column - new_start) + prefix.size(); i++) {
    std::cerr << " ";
  }
  std::cerr << "^" << std::endl;
}

int main(int argc, char** argv) {
  auto args = std::vector<std::string>(argv, argv + argc);
  const auto& command = args[1];

  if (command == "сплавити") {
    if (args.size() < 3) {
      std::cerr << "ціль: не вказано вхідний файл" << std::endl;
      return 1;
    }
    if (args.size() < 4) {
      std::cerr << "ціль: не вказано вихідний файл" << std::endl;
      return 1;
    }

    const auto& input_path = args[2];
    const auto& output_path = args[3];

    if (!output_path.ends_with(".ll") && !output_path.ends_with(".bc")) {
      std::cerr << "ціль: вихідний файл повинен мати розширення .ll або .bc"
                << std::endl;
      return 1;
    }
    if (output_path.ends_with(".bc")) {
      std::cerr
          << "ціль: вихідний файл з розширенням .bc тимчасово не підтримується"
          << std::endl;
      return 1;
    }

    std::ifstream input_file(input_path);
    if (!input_file.is_open()) {
      std::cerr << "ціль: не вдалося відкрити вхідний файл" << std::endl;
      return 1;
    }
    std::string code;
    std::string line;
    while (std::getline(input_file, line)) {
      code += line + "\n";
    }
    input_file.close();

    const auto parser_result = tsil::parser::parse(code);
    if (parser_result.program_node) {
      const auto state = new tsil::compiler::CompilationState();

      state->Module = new tsil::x::Module();

      state->Module->int1Type = state->Module->defineNativeType("i1");
      state->Module->int8Type = state->Module->defineNativeType("i8");
      state->Module->int32Type = state->Module->defineNativeType("i32");
      state->Module->int64Type = state->Module->defineNativeType("i64");
      state->Module->floatType = state->Module->defineNativeType("float");
      state->Module->doubleType = state->Module->defineNativeType("double");
      state->Module->pointerType = state->Module->defineNativeType("ptr");
      state->Module->voidType = state->Module->defineNativeType("void");

      state->globalScope = new tsil::compiler::CompilationScope();
      state->globalScope->state = state;

      const auto voidType = new tsil::compiler::Type();
      voidType->type = tsil::compiler::TypeTypeNative;
      voidType->name = "void";
      voidType->LT = state->Module->voidType;
      state->types["void"] = voidType;
      state->voidType = voidType;

      const auto pointerType = new tsil::compiler::Type();
      pointerType->type = tsil::compiler::TypeTypeNative;
      pointerType->name = "невідома_комірка";
      pointerType->LT = state->Module->pointerType;
      state->types["невідома_комірка"] = pointerType;
      state->pointerType = pointerType;

      const auto int8Type = new tsil::compiler::Type();
      int8Type->type = tsil::compiler::TypeTypeNative;
      int8Type->name = "ц8";
      int8Type->LT = state->Module->int8Type;
      state->types["ц8"] = int8Type;
      state->int8Type = int8Type;

      const auto int32Type = new tsil::compiler::Type();
      int32Type->type = tsil::compiler::TypeTypeNative;
      int32Type->name = "ц32";
      int32Type->LT = state->Module->int32Type;
      state->types["ц32"] = int32Type;
      state->int32Type = int32Type;

      const auto int64Type = new tsil::compiler::Type();
      int64Type->type = tsil::compiler::TypeTypeNative;
      int64Type->name = "ціле";
      int64Type->LT = state->Module->int64Type;
      state->types["ціле"] = int64Type;
      state->int64Type = int64Type;

      const auto floatType = new tsil::compiler::Type();
      floatType->type = tsil::compiler::TypeTypeNative;
      floatType->name = "д32";
      floatType->LT = state->Module->floatType;
      state->types["д32"] = floatType;
      state->floatType = floatType;

      const auto doubleType = new tsil::compiler::Type();
      doubleType->type = tsil::compiler::TypeTypeNative;
      doubleType->name = "дійсне";
      doubleType->LT = state->Module->doubleType;
      state->types["дійсне"] = doubleType;
      state->doubleType = doubleType;

      const auto uint8Type = new tsil::compiler::Type();
      uint8Type->type = tsil::compiler::TypeTypeNative;
      uint8Type->name = "п8";
      uint8Type->LT = state->Module->int8Type;
      state->types["п8"] = uint8Type;
      state->uint8Type = uint8Type;

      const auto uint32Type = new tsil::compiler::Type();
      uint32Type->type = tsil::compiler::TypeTypeNative;
      uint32Type->name = "п32";
      uint32Type->LT = state->Module->int32Type;
      state->types["п32"] = uint32Type;
      state->uint32Type = uint32Type;

      const auto uint64Type = new tsil::compiler::Type();
      uint64Type->type = tsil::compiler::TypeTypeNative;
      uint64Type->name = "позитивне";
      uint64Type->LT = state->Module->int64Type;
      state->types["позитивне"] = uint64Type;
      state->uint64Type = uint64Type;

      /*
       * структура текст {
       *   розмір: ціле; // розмір даних мінус 1
       *   дані: комірка<ц8>; // останній байт завжди 0
       * }
       */
      const auto stringStructure = new tsil::compiler::Structure();
      stringStructure->name = "текст";
      stringStructure->fields.insert_or_assign(
          "розмір",
          tsil::compiler::StructureField{
              .index = 0, .type = int64Type, .generic_type_index = 0});
      stringStructure->fields.insert_or_assign(
          "дані", tsil::compiler::StructureField{
                      .index = 1,
                      .type = uint8Type->getPointerType(state->globalScope),
                      .generic_type_index = 0});
      state->structures.insert_or_assign("текст", stringStructure);

      const auto textTypeResult = state->globalScope->makeType("текст", {});
      if (!textTypeResult.type) {
        std::cerr << "INTERNAL BUG: " << textTypeResult.error << std::endl;
        return 1;
      }
      state->types["текст"] = textTypeResult.type;
      state->textType = textTypeResult.type;

      for (const auto& ast_value : parser_result.program_node->body) {
        if (ast_value == nullptr) {
          continue;
        }
        if (ast_value->kind == tsil::ast::KindNone) {
          continue;
        }
        if (ast_value->kind == tsil::ast::KindStructureNode) {
          const auto result = state->globalScope->compileStructure(ast_value);
          if (result.error) {
            printCompilerError(input_path, code, result.error);
            return 1;
          }
        } else if (ast_value->kind == tsil::ast::KindDiiaDeclarationNode) {
          const auto result =
              state->globalScope->compileDiiaDeclaration(ast_value);
          if (result.error) {
            printCompilerError(input_path, code, result.error);
            return 1;
          }
        } else if (ast_value->kind == tsil::ast::KindDiiaNode) {
          const auto result = state->globalScope->compileDiia(ast_value);
          if (result.error) {
            printCompilerError(input_path, code, result.error);
            return 1;
          }
        } else {
          printCompilerError(
              input_path, code,
              tsil::compiler::CompilerError::fromASTValue(
                  ast_value,
                  "В секції можна визначати лише секції, структури та дії"));
          return 1;
        }
      }

      std::ofstream out_file(output_path);
      if (!out_file.is_open()) {
        std::cerr << "ціль: не вдалося відкрити вихідний файл" << std::endl;
        return 1;
      }
      out_file << state->Module->dumpLL();
      out_file.close();
    } else {
      printParserError(input_path, code, &parser_result.errors[0]);
      return 1;
    }
  }

  return 0;
}