#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

mkdir -p build-neo
cd build-neo
cmake ../neo/ -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always
ninja
cd ..