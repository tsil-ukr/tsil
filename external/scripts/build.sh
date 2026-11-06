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

mkdir -p "$BuildOutDir"
mkdir -p "$BuildOutDir/програми"
mkdir -p "$BuildSourceDir"
mkdir -p "$BuildSourceDir/external"

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
      compile_as_obj "$CompilationFile"
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

Command="clang++ $ClangOptions $ClangExeOptions -o $BuildOutDir/програми/ціль $CCompiledFiles"
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