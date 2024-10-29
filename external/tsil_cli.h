#pragma once

// TODO: переписати на Ціль!

#include <functional>
#include <string>
#include <variant>

struct TsilCliConfig {
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
  TsilCliCompileCommandOutputFormatELF,
};

struct TsilCliFuseCommandOutput {
  char* path;
  TsilCliFuseCommandOutputFormat format;
};

struct TsilCliFuseCommandInput {
  char* path;
};

struct TsilCliFuseCommandOptions {
  std::string libraryPath;
};

struct TsilCliFuseCommand {
  size_t outputsSize;
  TsilCliFuseCommandOutput* outputs;
  TsilCliFuseCommandOptions options;
  TsilCliFuseCommandInput input;
};

struct TsilCliHelpCommand {
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
  TsilCliParsedCommandTypeCompile,
  TsilCliParsedCommandTypeFuse,
  TsilCliParsedCommandTypeLLD,
  TsilCliParsedCommandTypeClang,
};

struct TsilCliParsedCommand {
  TsilCliParsedCommandType type;
  std::variant<TsilCliHelpCommand,
               TsilCliCompileCommand,
               TsilCliFuseCommand,
               TsilCliLLDCommand,
               TsilCliClangCommand>
      c;
};

extern "C" int tsil_cli_parse(TsilCliConfig config,
                              char* firstArg,
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
                                TsilCliWriter outputWriter,
                                TsilCliFuseCommandOutputFormat outputFormat,
                                TsilCliFuseCommandOptions options,
                                char* outputPath,
                                unsigned long inputPathsSize,
                                char** inputPaths);

extern "C" int tsil_cli_do_lld(TsilCliConfig config, TsilCliLLDCommand command);
extern "C" int tsil_cli_do_clang(TsilCliConfig config,
                                 TsilCliClangCommand command);