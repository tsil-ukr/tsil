#!/usr/bin/env sh
set -e

Target="linux-x86_64"
Mode="$1"

if [ -z "$TSIL" ]
then
  TSIL="ціль"
fi
Version="$(cat Версія)"
OutDir="out/$Version/$Target"
BuildDir="build/$Version/$Target"
CompilationFiles="$(cat ФайлиКомпіляції)"
CompiledFiles=""
ClangOptions="-DTSIL_VERSION=\"$Version\""
if [ "$Mode" = "release" ]
then
  ClangOptions="$ClangOptions -static -O3 -flto"
else
  ClangOptions="$ClangOptions -g -O0"
fi

mkdir -p "$OutDir"
mkdir -p "$BuildDir/source/ЛЛВМ"
mkdir -p "$BuildDir/source/external"
mkdir -p "$BuildDir/source/біб/турбо"

while IFS='' read -r CompilationFile
do
  case "$CompilationFile" in
    *".ц")
      LLCompilationFile="$CompilationFile.ll"
      mkdir -p "$(dirname "$BuildDir/source/$LLCompilationFile")"
      Command="$TSIL $BuildDir/source/$LLCompilationFile --формат=ллвмір --архітектура=ікс86_64 --система=лінукс скомпілювати $CompilationFile --біб=./БЦ"
      echo "$Command"
      $Command
      if [ -z "$CompiledFiles" ]; then
        CompiledFiles=$(printf "%s" "$BuildDir/source/$LLCompilationFile")
      else
        CompiledFiles=$(printf "$CompiledFiles %s" "$BuildDir/source/$LLCompilationFile")
      fi
      ;;
    *".c")
      LLCompilationFile="$CompilationFile.o"
      mkdir -p "$(dirname "$BuildDir/source/$LLCompilationFile")"
      Command="clang $ClangOptions -c -o $BuildDir/source/$LLCompilationFile $CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$CompiledFiles" ]; then
        CompiledFiles=$(printf "%s" "$BuildDir/source/$LLCompilationFile")
      else
        CompiledFiles=$(printf "$CompiledFiles %s" "$BuildDir/source/$LLCompilationFile")
      fi
      ;;
    *)
      mkdir -p "$(dirname "$BuildDir/source/$LLCompilationFile")"
      Command="cp $CompilationFile $BuildDir/source/$CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$CompiledFiles" ]; then
        CompiledFiles=$(printf "%s" "$BuildDir/source/$CompilationFile")
      else
        CompiledFiles=$(printf "$CompiledFiles %s" "$BuildDir/source/$CompilationFile")
      fi
      ;;
  esac
done <<CompilationFiles_HEREDOC_INPUT
$CompilationFiles
CompilationFiles_HEREDOC_INPUT

LlvmConfig="llvm-config"

if [ -f "./.llvm-source-and-build/llvm-project-20.1.6.build/llvm/bin/llvm-config" ];
then
  LlvmConfig="./.llvm-source-and-build/llvm-project-20.1.6.build/llvm/bin/llvm-config"
fi

Command="clang++ $ClangOptions -o $OutDir/ціль $CompiledFiles `$LlvmConfig --cxxflags --ldflags --system-libs --libs`"
echo "$Command"
$Command