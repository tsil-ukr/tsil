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
ClangOptions="-DTSIL_VERSION=\"$Version\""
if [ "$Mode" = "release" ]
then
  ClangOptions="$ClangOptions -static -O3 -flto"
else
  ClangOptions="$ClangOptions -g -O0"
fi

mkdir -p "$BuildOutDir"
mkdir -p "$BuildSourceDir"
mkdir -p "$BuildSourceDir/ЛЛВМ"
mkdir -p "$BuildSourceDir/external"
mkdir -p "$BuildSourceDir/біб/турбо"

while IFS='' read -r CompilationFile
do
  case "$CompilationFile" in
    *".ц")
      LLCompilationFile="$CompilationFile.ллвмір"
      mkdir -p "$(dirname "$BuildSourceDir/$LLCompilationFile")"
      Command="$TSIL $BuildSourceDir/$LLCompilationFile --формат=ллвмір --платформа=лінукс-ікс86_64 скомпілювати $CompilationFile --біб=./БЦ"
      echo "$Command"
      $Command
      if [ -z "$LLCompiledFiles" ]; then
        LLCompiledFiles=$(printf "%s" "$BuildSourceDir/$LLCompilationFile")
      else
        LLCompiledFiles=$(printf "$LLCompiledFiles %s" "$BuildSourceDir/$LLCompilationFile")
      fi
      ;;
    *".c")
      LLCompilationFile="$CompilationFile.o"
      mkdir -p "$(dirname "$BuildSourceDir/$LLCompilationFile")"
      Command="clang $ClangOptions -c -o $BuildSourceDir/$LLCompilationFile $CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$CCompiledFiles" ]; then
        CCompiledFiles=$(printf "%s" "$BuildSourceDir/$LLCompilationFile")
      else
        CCompiledFiles=$(printf "$CCompiledFiles %s" "$BuildSourceDir/$LLCompilationFile")
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

if [ -f "./.llvm-source-and-build/llvm-project-20.1.6.build/llvm/bin/llvm-config" ];
then
  LlvmConfig="./.llvm-source-and-build/llvm-project-20.1.6.build/llvm/bin/llvm-config"
fi

Command="clang++ $ClangOptions -o $BuildOutDir/ціль $CCompiledFiles -x ir $LLCompiledFiles `$LlvmConfig --cxxflags --ldflags --system-libs --libs`"
echo "$Command"
$Command