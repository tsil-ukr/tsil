#include "tsil_toc.h"
#include <iostream>

// програма [--опції-програми]... [(вихід) [--опції-виходу]...]... (команда) [--опції-команди]... [(вхід) [--опції-входу]...]...
std::variant<TargetOrientedCommand, std::string> parseTOC(
    std::vector<std::string> args,
    std::set<std::string> commands) {
  std::map<std::string, std::optional<std::string>> programOptions;
  std::vector<TargetOrientedCommandOutput> outputs;
  std::optional<std::string> command = std::nullopt;
  std::map<std::string, std::optional<std::string>> commandOptions;
  std::vector<TargetOrientedCommandInput> inputs;

  size_t i = 0;

  // programOptions
  while (i < args.size()) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      programOptions.insert_or_assign(key, value);
    } else {
      break;
    }
    i = i + 1;
  }

  // outputs and command
  while (i < args.size()) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      outputs.back().options.insert_or_assign(key, value);
    } else {
      if (commands.contains(arg)) {
        command = arg;
        i = i + 1;
        break;
      } else {
        outputs.push_back({.path = arg, .options = {}});
      }
    }
    i = i + 1;
  }
  if (!command.has_value()) {
    return "Не вказано команду";
  }

  // command options
  while (i < args.size()) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      commandOptions.insert_or_assign(key, value);
    } else {
      break;
    }
    i = i + 1;
  }

  // inputs
  while (i < args.size()) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      inputs.back().options.insert_or_assign(key, value);
    } else {
      inputs.push_back({.path = arg, .options = {}});
    }
    i = i + 1;
  }

  return TargetOrientedCommand{
      .programOptions = programOptions,
      .outputs = outputs,
      .command = command,
      .commandOptions = commandOptions,
      .inputs = inputs,
  };
}

void printTOC(const TargetOrientedCommand& toc) {
  for (auto [key, value] : toc.programOptions) {
    std::cout << "--" << key;
    if (value.has_value()) {
      std::cout << "=" << value.value();
    }
    std::cout << " ";
  }
  for (auto output : toc.outputs) {
    std::cout << output.path << " ";
    for (auto [key, value] : output.options) {
      std::cout << "--" << key;
      if (value.has_value()) {
        std::cout << "=" << value.value();
      }
      std::cout << " ";
    }
  }
  std::cout << toc.command.value() << " ";
  for (auto [key, value] : toc.commandOptions) {
    std::cout << "--" << key;
    if (value.has_value()) {
      std::cout << "=" << value.value();
    }
    std::cout << " ";
  }
  for (auto input : toc.inputs) {
    std::cout << input.path << " ";
    for (auto [key, value] : input.options) {
      std::cout << "--" << key;
      if (value.has_value()) {
        std::cout << "=" << value.value();
      }
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}