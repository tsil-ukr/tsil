#!/usr/bin/env bash

set -e

LLVM_VERSION="19.1.0"

mkdir -p .llvm-source-and-build
cd .llvm-source-and-build
if [ ! -d llvm-project-$LLVM_VERSION.src ]; then
  wget https://github.com/llvm/llvm-project/releases/download/llvmorg-$LLVM_VERSION/llvm-project-$LLVM_VERSION.src.tar.xz
  tar -xf llvm-project-$LLVM_VERSION.tar.xz
fi
mkdir -p llvm-project-$LLVM_VERSION.build/llvm
cd llvm-project-$LLVM_VERSION.build/llvm
cmake ../../llvm-project-$LLVM_VERSION.src/llvm -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -G Ninja
cmake --build .
