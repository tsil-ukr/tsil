#!/usr/bin/env bash

set -e

LLVM_VERSION="19.1.0"

TARGET="x86_64-linux-gnu"
MCPU="native"

TARGET_OS_AND_ABI=${TARGET#*-}
TARGET_OS_CMAKE=${TARGET_OS_AND_ABI%-*} # Example: linux
case $TARGET_OS_CMAKE in
  macos) TARGET_OS_CMAKE="Darwin";;
  freebsd) TARGET_OS_CMAKE="FreeBSD";;
  windows) TARGET_OS_CMAKE="Windows";;
  linux) TARGET_OS_CMAKE="Linux";;
  native) TARGET_OS_CMAKE="";;
esac

mkdir -p .llvm-source-and-build
cd .llvm-source-and-build
if [ ! -d llvm-project-$LLVM_VERSION.src ]; then
  wget https://github.com/llvm/llvm-project/releases/download/llvmorg-$LLVM_VERSION/llvm-project-$LLVM_VERSION.src.tar.xz
  tar -xf llvm-project-$LLVM_VERSION.tar.xz
fi

mkdir -p llvm-project-$LLVM_VERSION.build/llvm
cd llvm-project-$LLVM_VERSION.build/llvm
cmake ../../llvm-project-$LLVM_VERSION.src/llvm \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CROSSCOMPILING=True \
  -DCMAKE_SYSTEM_NAME="$TARGET_OS_CMAKE" \
  -DCMAKE_C_COMPILER="/usr/bin/clang;-target;$TARGET;-mcpu=$MCPU" \
  -DCMAKE_CXX_COMPILER="/usr/bin/clang++;-target;$TARGET;-mcpu=$MCPU" \
  -DCMAKE_RC_COMPILER="/usr/bin/llvm-rc" \
  -DCMAKE_AR="/usr/bin/llvm-ar" \
  -DCMAKE_RANLIB="/usr/bin/llvm-ranlib" \
  -DLLVM_ENABLE_PROJECTS="clang;lld" \
  -DLLVM_ENABLE_LIBXML2=OFF \
  -DLLVM_ENABLE_ZSTD=OFF \
  -DLLVM_ENABLE_ZLIB=OFF \
  -DLLVM_INCLUDE_UTILS=ON \
  -DLLVM_BUILD_STATIC=ON \
  -DLLVM_INCLUDE_TESTS=OFF \
  -DLLVM_INCLUDE_EXAMPLES=OFF \
  -DLLVM_INCLUDE_BENCHMARKS=OFF \
  -DLLVM_INCLUDE_DOCS=OFF \
  -DLLVM_ENABLE_BINDINGS=OFF \
  -DLLVM_ENABLE_OCAMLDOC=OFF \
  -DLLVM_ENABLE_Z3_SOLVER=OFF \
  -DLLVM_TOOL_LLVM_LTO2_BUILD=ON \
  -DLLVM_TOOL_LLVM_LTO_BUILD=ON \
  -DLLVM_TOOL_LTO_BUILD=ON \
  -DLLVM_TOOL_REMARKS_SHLIB_BUILD=OFF \
  -DCLANG_TABLEGEN="./bin/clang-tblgen" \
  -DCLANG_BUILD_TOOLS=OFF \
  -DCLANG_INCLUDE_DOCS=OFF \
  -DCLANG_INCLUDE_TESTS=OFF \
  -DCLANG_ENABLE_ARCMT=ON \
  -DCLANG_TOOL_CLANG_IMPORT_TEST_BUILD=OFF \
  -DCLANG_TOOL_CLANG_LINKER_WRAPPER_BUILD=OFF \
  -DCLANG_TOOL_C_INDEX_TEST_BUILD=OFF \
  -DCLANG_TOOL_ARCMT_TEST_BUILD=OFF \
  -DCLANG_TOOL_C_ARCMT_TEST_BUILD=OFF \
  -DCLANG_TOOL_LIBCLANG_BUILD=OFF \
  -DLIBCLANG_BUILD_STATIC=ON \
  -DLLD_BUILD_TOOLS=OFF
cmake --build .
