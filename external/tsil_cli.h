#pragma once

// TODO: переписати на Ціль!

#include <functional>
#include <string>
#include <variant>

struct TsilCliConfig {
  void (*println)(char* message);
};

struct TsilCliWriter {
  void (*write)(TsilCliConfig config, unsigned char* data, void* options);
  void* options;
};

enum TsilCliCompileCommandOutputFormat {
  TsilCliCompileCommandOutputFormatLLVM,
  TsilCliCompileCommandOutputFormatASM,
  TsilCliCompileCommandOutputFormatOBJ,
  TsilCliCompileCommandOutputFormatARCHIVE,
};

struct TsilCliCompileCommandOutput {
  char* path;
  TsilCliCompileCommandOutputFormat format;
};

struct TsilCliCompileCommandInput {
  char* path;
};

struct TsilCliCompileCommandOptions {
  std::string libraryPath;
};

struct TsilCliCompileCommand {
  size_t outputsSize;
  TsilCliCompileCommandOutput* outputs;
  TsilCliCompileCommandOptions options;
  TsilCliCompileCommandInput input;
};

enum TsilCliFuseCommandOutputFormat {
  TsilCliCompileCommandOutputFormatELF,
};

struct TsilCliFuseCommandOptions {
  TsilCliFuseCommandOutputFormat outFormat;
  std::string libraryPath;
};

struct TsilCliFuseCommand {
  char* outputPath;
  TsilCliFuseCommandOptions options;
  unsigned long inputPathsSize;
  char** inputPaths;
};

struct TsilCliFuseHelp {
  bool someDummyField;
};

enum TsilCliParsedCommandType {
  TsilCliParsedCommandTypeHelp,
  TsilCliParsedCommandTypeCompile,
  TsilCliParsedCommandTypeFuse,
};

struct TsilCliParsedCommand {
  TsilCliParsedCommandType type;
  std::variant<TsilCliFuseHelp, TsilCliCompileCommand, TsilCliFuseCommand> c;
};

extern "C" int tsil_cli_parse(TsilCliConfig config,
                              size_t argsSize,
                              char** args,
                              TsilCliParsedCommand* parsedCommandPtr);

extern "C" int tsil_cli_run_compile_command(TsilCliConfig config,
                                            TsilCliCompileCommand command);

extern "C" int tsil_cli_do_compile(
    TsilCliConfig config,
    TsilCliWriter outputWriter,
    TsilCliCompileCommandOutputFormat outputFormat,
    TsilCliCompileCommandOptions options,
    char* inputPath,
    char* inputSource);