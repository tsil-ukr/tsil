#pragma once

// TODO: переписати на Ціль!

#include <functional>
#include <string>
#include <variant>

struct TsilCliConfig {
  char* path;
  void (*println)(char* message);
};

struct TsilCliWriter {
  void (*write)(TsilCliConfig config,
                size_t size,
                unsigned char* data,
                void* options);
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
  TsilCliFuseCommandOutputFormatELF,
};

struct TsilCliFuseCommandOutput {
  char* path;
  TsilCliFuseCommandOutputFormat format;
};

struct TsilCliFuseCommandInput {
  char* path;
};

struct TsilCliFuseCommandOptions {
  std::string clangOptions;
  std::string libraryPath;
};

struct TsilCliFuseCommand {
  size_t outputsSize;
  TsilCliFuseCommandOutput* outputs;
  TsilCliFuseCommandOptions options;
  size_t inputsSize;
  TsilCliFuseCommandInput* inputs;
};

struct TsilCliHelpCommand {
  bool someDummyField;
};

struct TsilCliVersionCommand {
  bool someDummyField;
};

struct TsilCliLLDCommand {
  size_t argc;
  char** argv;
};

struct TsilCliClangCommand {
  char* path;
  char* prependArg;
  size_t argsSize;
  char** args;
};

enum TsilCliParsedCommandType {
  TsilCliParsedCommandTypeHelp,
  TsilCliParsedCommandTypeVersion,
  TsilCliParsedCommandTypeCompile,
  TsilCliParsedCommandTypeFuse,
};

struct TsilCliParsedCommand {
  TsilCliParsedCommandType type;
  std::variant<TsilCliHelpCommand,
               TsilCliVersionCommand,
               TsilCliCompileCommand,
               TsilCliFuseCommand>
      c;
};

extern "C" int tsil_cli_parse(TsilCliConfig config,
                              size_t argsSize,
                              char** args,
                              TsilCliParsedCommand* parsedCommandPtr);

extern "C" int tsil_cli_run_compile_command(TsilCliConfig config,
                                            TsilCliCompileCommand command);
extern "C" int tsil_cli_run_fuse_command(TsilCliConfig config,
                                         TsilCliFuseCommand command);

extern "C" int tsil_cli_do_compile(
    TsilCliConfig config,
    TsilCliWriter outputWriter,
    TsilCliCompileCommandOutputFormat outputFormat,
    TsilCliCompileCommandOptions options,
    char* inputPath,
    char* inputSource);

extern "C" int tsil_cli_do_fuse(TsilCliConfig config,
                                char* outputPath,
                                TsilCliFuseCommandOutputFormat outputFormat,
                                TsilCliFuseCommandOptions options,
                                unsigned long inputsSize,
                                TsilCliFuseCommandInput* inputs);