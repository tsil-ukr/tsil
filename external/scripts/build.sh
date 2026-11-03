#!/usr/bin/env sh
set -e

Target="лінукс-ікс86_64"
Mode="$1"

if [ -z "$TSIL" ]
then
  TSIL="ціль"
fi
Version="$(cat Версія)"
BuildDir="будування/$Version/$Target"
BuildSourceDir="$BuildDir/напівготове"
BuildOutDir="$BuildDir/готове"
CompilationFiles="$(cat ФайлиКомпіляції)"
LLCompiledFiles=""
CCompiledFiles=""
ClangOptions="-DTSIL_VERSION=\"$Version\" --target=x86_64-pc-linux-gnu"
ClangExeOptions=""
if [ "$Mode" = "release" ]
then
  ClangOptions="$ClangOptions -O3"
  ClangExeOptions="$ClangExeOptions -static -flto"
else
  ClangOptions="$ClangOptions -g -O0"
fi

CompileAs="$2"
if [ -z "$CompileAs" ]
then
  CompileAs="ir"
fi

mkdir -p "$BuildOutDir"
mkdir -p "$BuildOutDir/програми"
mkdir -p "$BuildSourceDir"
mkdir -p "$BuildSourceDir/ЛЛВМ"
mkdir -p "$BuildSourceDir/external"

compile_as_llvmir() {
  CompilationFile="$1"
  LLCompilationFile="$CompilationFile.ллвмір"
  mkdir -p "$(dirname "$BuildSourceDir/$LLCompilationFile")"
  Command="$TSIL $BuildSourceDir/$LLCompilationFile --формат=ллвмір --платформа=ікс86_64-пк-лінукс-гну скомпілювати $CompilationFile --біб=./БЦ"
  echo "$Command"
  $Command
  if [ -z "$LLCompiledFiles" ]; then
    LLCompiledFiles=$(printf "%s" "$BuildSourceDir/$LLCompilationFile")
  else
    LLCompiledFiles=$(printf "$LLCompiledFiles %s" "$BuildSourceDir/$LLCompilationFile")
  fi
}

compile_as_obj() {
  CompilationFile="$1"
  CiangCompilationFile="$CompilationFile.сіанг"
  mkdir -p "$(dirname "$BuildSourceDir/$CiangCompilationFile")"
  Command="$TSIL $BuildSourceDir/$CiangCompilationFile --формат=сіанг --платформа=ікс86_64-пк-лінукс-гну скомпілювати $CompilationFile --біб=./БЦ"
  echo "$Command"
  $Command

  mv "$BuildSourceDir/$CiangCompilationFile" "$BuildSourceDir/$CiangCompilationFile.c"
  CCompilationFile="$CiangCompilationFile.c"
  Command="clang $ClangOptions -c -o $BuildSourceDir/$CCompilationFile.o $BuildSourceDir/$CCompilationFile"
  echo "$Command"
  $Command
  if [ -z "$CCompiledFiles" ]; then
    CCompiledFiles=$(printf "%s" "$BuildSourceDir/$CCompilationFile.o")
  else
    CCompiledFiles=$(printf "$CCompiledFiles %s" "$BuildSourceDir/$CCompilationFile.o")
  fi
}

while IFS='' read -r CompilationFile
do
  case "$CompilationFile" in
    *".ц")
      if [ "$CompileAs" = "ir" ]; then
        compile_as_llvmir "$CompilationFile"
      else
        compile_as_obj "$CompilationFile"
      fi
      ;;
    *".c")
      CCompilationFile="$CompilationFile.o"
      mkdir -p "$(dirname "$BuildSourceDir/$CCompilationFile")"
      Command="clang $ClangOptions -c -o $BuildSourceDir/$CCompilationFile $CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$CCompiledFiles" ]; then
        CCompiledFiles=$(printf "%s" "$BuildSourceDir/$CCompilationFile")
      else
        CCompiledFiles=$(printf "$CCompiledFiles %s" "$BuildSourceDir/$CCompilationFile")
      fi
      ;;
    *)
      mkdir -p "$(dirname "$BuildSourceDir/$LLCompilationFile")"
      Command="cp $CompilationFile $BuildSourceDir/$CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$CCompiledFiles" ]; then
        CCompiledFiles=$(printf "%s" "$BuildSourceDir/$CompilationFile")
      else
        CCompiledFiles=$(printf "$CCompiledFiles %s" "$BuildSourceDir/$CompilationFile")
      fi
      ;;
  esac
done <<CompilationFiles_HEREDOC_INPUT
$CompilationFiles
CompilationFiles_HEREDOC_INPUT

LlvmConfig="llvm-config"

if [ -f "./.llvm-source-and-build/llvm-project-22.1.5.build/llvm-linux-x86_64/bin/llvm-config" ];
then
  LlvmConfig="./.llvm-source-and-build/llvm-project-22.1.5.build/llvm-linux-x86_64/bin/llvm-config"
else
  echo "LLVM не знайдено, використовуємо системний LLVM. Щоб збудувати LLVM, запустіть ./external/scripts/llvm.sh"
fi

Command="clang++ $ClangOptions $ClangExeOptions -o $BuildOutDir/програми/ціль $CCompiledFiles -x ir $LLCompiledFiles `$LlvmConfig --cxxflags --ldflags --system-libs --libs`"
echo "$Command"
$Command

Command="cp основа.в.ц $BuildOutDir"
echo "$Command"
$Command

Command="rm -rf $BuildOutDir/біб"
echo "$Command"
$Command

Command="cp -a біб $BuildOutDir/біб"
echo "$Command"
$Command