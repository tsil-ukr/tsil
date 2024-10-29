#pragma once

#include <map>
#include <optional>
#include <set>
#include <string>
#include <variant>
#include <vector>

struct TargetOrientedCommandOutput {
  std::string path;
  std::map<std::string, std::optional<std::string>> options;
};
struct TargetOrientedCommandInput {
  std::string path;
  std::map<std::string, std::optional<std::string>> options;
};

struct TargetOrientedCommand {
  std::map<std::string, std::optional<std::string>> programOptions;
  std::vector<TargetOrientedCommandOutput> outputs;
  std::optional<std::string> command;
  std::map<std::string, std::optional<std::string>> commandOptions;
  std::vector<TargetOrientedCommandInput> inputs;
};

std::variant<TargetOrientedCommand, std::string> parseTOC(
    std::vector<std::string> args,
    std::set<std::string> commands);

void printTOC(const TargetOrientedCommand& toc);