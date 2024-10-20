// TODO: переписати на Ціль!

#include <functional>
#include <string>

struct TsilCliWriter {
  void (*write)(unsigned char* data, void* options);
  void* options;
};

struct TsilCliConfig {
  void (*println)(char* message);
};

enum TsilCliCompileOutFormat {
  TsilCliCompileOutFormatLLVM,
  TsilCliCompileOutFormatASM,
  TsilCliCompileOutFormatOBJ,
  TsilCliCompileOutFormatARCHIVE,
};

struct TsilCliCompileOptions {
  TsilCliCompileOutFormat outFormat;
  std::string libraryPath;
};

extern "C" int tsil_cli_compile_single(TsilCliConfig config,
                                       TsilCliWriter outputWriter,
                                       TsilCliCompileOptions options,
                                       char* inputPath,
                                       char* inputSource);