#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

TARGET=$1

if [ "$TARGET" = "" ]; then
    echo "Usage: build.sh <bin|Obin>"
    exit 1
fi

if [ "$TARGET" = "bin" ] || [ "$TARGET" = "all" ]; then
    mkdir -p build-bin
    cd build-bin
    cmake -DTSIL_X_EXPANDED_NAMES=1 ..
    make -j4 tsil
    cd ..
fi

if [ "$TARGET" = "Obin" ] || [ "$TARGET" = "Oall" ]; then
    mkdir -p build-Obin
    cd build-Obin
    cmake -DTSIL_X_EXPANDED_NAMES=0 ..
    make -j4 tsil_release
    cd ..
fi