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

cd neo
ціль ../.плавлення/скомпільоване/Ц.ц.ll скомпілювати Ц.ц
cd ..

clang++ -o build-neo/tsil \
  neo/main.cpp \
  .плавлення/скомпільоване/Ц.ц.ll \
  build-neo/libxl.a \
  .llvm-source-and-build/llvm-project-19.1.0.build/llvm/lib/*.a \
  /usr/local/lib/ціль/бібліотека/біб.a \
  -fuse-ld=/usr/bin/mold