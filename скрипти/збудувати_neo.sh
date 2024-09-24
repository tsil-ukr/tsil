#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

mkdir -p build-neo
cd build-neo
cmake ../neo/ -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always -DCMAKE_EXE_LINKER_FLAGS="-fuse-ld=/usr/bin/mold" -DCMAKE_SHARED_LINKER_FLAGS="-fuse-ld=/usr/bin/mold"
ninja
cd ..