#include <sys/stat.h>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "compiler/compiler.h"

void path_to_splav_name(const std::string& path,
                        std::string& exec_name,
                        std::string& object_name,
                        std::string& danis_name) {
  const auto canonical_path = std::filesystem::canonical(path).string();

  const auto fs_path = std::filesystem::path(canonical_path);
  if (!fs_path.has_filename()) {
    return;
  }

  const auto name = fs_path.stem().string();

  exec_name = name;
  object_name = name + ".o";
  danis_name = name + ".даніс";
}

void parse_buda(const std::string& data,
                std::unordered_map<std::string, std::string>& buda) {
  std::istringstream iss(data);
  std::string line;
  while (std::getline(iss, line)) {
    const auto pos = line.find('=');
    if (pos == std::string::npos) {
      continue;
    }
    const auto key = line.substr(0, pos);
    const auto value = line.substr(pos + 1);
    buda[key] = value;
  }
}

int main(int argc, char** argv) {
  auto args = std::vector<std::string>(argv, argv + argc);
  const auto& command = args[1];

  if (command == "сплавити") {
    if (args.size() < 3) {
      std::cerr << "Не вказано модуль!" << std::endl;
      return 1;
    }

    const auto& path = args[2];

    std::ifstream file(path);
    if (!file.is_open()) {
      std::cerr << path << std::endl;
      return 1;
    }

    std::string exec_name;
    std::string splav_name;
    std::string danis_name;
    path_to_splav_name(path, exec_name, splav_name, danis_name);

    std::string code;

    std::string line;
    while (std::getline(file, line)) {
      code += line + "\n";
    }

    const auto parser_result = tsil::parser::parse(code);
    if (parser_result.program_node) {
      const auto state = new tsil::compiler::CompilationState();

      state->Module = new tsil::x::Module();

      state->Module->int8Type = state->Module->defineNativeType("i8");
      state->Module->int32Type = state->Module->defineNativeType("i32");
      state->Module->int64Type = state->Module->defineNativeType("i64");
      state->Module->floatType = state->Module->defineNativeType("float");
      state->Module->doubleType = state->Module->defineNativeType("double");
      state->Module->pointerType = state->Module->defineNativeType("ptr");
      state->Module->voidType = state->Module->defineNativeType("void");

      state->globalScope = new tsil::compiler::CompilationScope();
      state->globalScope->state = state;

      const auto voidPointerType = new tsil::compiler::Type();
      voidPointerType->type = tsil::compiler::TypeTypeNative;
      voidPointerType->name = "невідома_комірка";
      voidPointerType->LT = state->Module->pointerType;
      state->types["невідома_комірка"] = voidPointerType;
      state->voidPointerType = voidPointerType;

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
        std::cerr << "Не вдалось створити тип: " << textTypeResult.error
                  << std::endl;
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
        if (ast_value->kind == tsil::ast::KindDiiaNode) {
          const auto result = state->globalScope->compile_diia_node(ast_value);
          if (result.error) {
            std::cerr << "Не вдалось скомпілювати: " << result.error->message
                      << std::endl;
            return 1;
          }
        } else if (ast_value->kind == tsil::ast::KindDiiaDeclarationNode) {
          const auto result =
              state->globalScope->compile_diia_declaration_node(ast_value);
          if (result.error) {
            std::cerr << "Не вдалось скомпілювати: " << result.error->message
                      << std::endl;
            return 1;
          }
        } else if (ast_value->kind == tsil::ast::KindStructureNode) {
          const auto result =
              state->globalScope->compile_structure_node(ast_value);
          if (result.error) {
            std::cerr << "Не вдалось скомпілювати: " << result.error->message
                      << std::endl;
            return 1;
          }
        } else {
          std::cerr << "Невідомий тип вказівки: " << ast_value->kind
                    << std::endl;
          return 1;
        }
      }

      std::cout << state->Module->dumpLL() << std::endl;
    } else {
      std::cerr << "Failed to parse: " << parser_result.errors[0].message
                << std::endl;
      return 1;
    }
  }

  return 0;
}