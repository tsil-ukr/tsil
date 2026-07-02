#!/usr/bin/env bash

set -e

LLVM_VERSION="22.1.5"
TARGET_OS_CMAKE="Linux"
TARGET="x86_64-unknown-none"

mkdir -p .llvm-source-and-build
cd .llvm-source-and-build
if [ ! -d llvm-project-$LLVM_VERSION.src ]; then
  wget https://github.com/llvm/llvm-project/releases/download/llvmorg-$LLVM_VERSION/llvm-project-$LLVM_VERSION.src.tar.xz
  tar -xf llvm-project-$LLVM_VERSION.src.tar.xz
fi

mkdir -p llvm-project-$LLVM_VERSION.build/llvm-linux-x86_64
cd llvm-project-$LLVM_VERSION.build/llvm-linux-x86_64

cmake ../../llvm-project-$LLVM_VERSION.src/llvm \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CROSSCOMPILING=True \
  -DCMAKE_SYSTEM_NAME="$TARGET_OS_CMAKE" \
  -DCMAKE_C_COMPILER="/usr/bin/clang" \
  -DCMAKE_CXX_COMPILER="/usr/bin/clang++" \
  -DCMAKE_AR="/usr/bin/llvm-ar" \
  -DCMAKE_RANLIB="/usr/bin/llvm-ranlib" \
  -DLLVM_DEFAULT_TARGET_TRIPLE="$TARGET" \
  -DLLVM_TARGETS_TO_BUILD="all" \
  -DLLVM_ENABLE_PROJECTS="" \
  -DLLVM_BUILD_STATIC=ON \
  -DLLVM_ENABLE_THREADS=OFF \
  -DLLVM_ENABLE_BACKTRACES=OFF \
  -DLLVM_ENABLE_EH=OFF \
  -DLLVM_ENABLE_RTTI=OFF \
  -DLLVM_ENABLE_PLUGINS=OFF \
  -DLLVM_ENABLE_TERMINFO=OFF \
  -DLLVM_BUILD_TOOLS=ON \
  -DLLVM_BUILD_UTILS=OFF \
  -DLLVM_BUILD_RUNTIMES=OFF \
  -DLLVM_ENABLE_LIBXML2=OFF \
  -DLLVM_ENABLE_ZSTD=OFF \
  -DLLVM_ENABLE_ZLIB=OFF \
  -DLLVM_ENABLE_Z3_SOLVER=OFF \
  -DLLVM_INCLUDE_UTILS=OFF \
  -DLLVM_INCLUDE_TESTS=OFF \
  -DLLVM_INCLUDE_EXAMPLES=OFF \
  -DLLVM_INCLUDE_BENCHMARKS=OFF \
  -DLLVM_INCLUDE_DOCS=OFF \
  -DLLVM_ENABLE_BINDINGS=OFF

cmake --build . --target llvm-libraries llvm-config