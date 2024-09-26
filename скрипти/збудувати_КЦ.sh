#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

cd КЦ
ціль ../.плавлення/скомпільоване/Ц.ц.ll скомпілювати Ц.ц
$CXX -c -o ../.плавлення/скомпільоване/Ц.ц.o ../.плавлення/скомпільоване/Ц.ц.ll
cd ..

mkdir -p build
cd build
cmake ../external/ -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always
ninja
cd ..
