#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

KTS_FILES=("Ц.ц" "Тип.ц" "К/К.ц" "К/КЗвернутись.ц" "К/КВиконати.ц" "К/КВиконатиШаблон.ц" "К/КПеревизначити.ц" "К/КЗмінити.ц" "К/КОперація.ц" "К/КЗмінити.ц" "К/КОтримати.ц" "К/КСтворитиЦіль.ц")

cd КЦ
for KTS_FILE in "${KTS_FILES[@]}"; do
  echo "ціль ../.плавлення/скомпільоване/$KTS_FILE.ll скомпілювати $KTS_FILE"
  ціль ../.плавлення/скомпільоване/"$KTS_FILE".ll скомпілювати "$KTS_FILE"
  echo "$CXX -c -o ../.плавлення/скомпільоване/$KTS_FILE.o ../.плавлення/скомпільоване/$KTS_FILE.ll -Wno-override-module"
  $CXX -c -o ../.плавлення/скомпільоване/"$KTS_FILE".o ../.плавлення/скомпільоване/"$KTS_FILE".ll -Wno-override-module
done
cd ..

mkdir -p build
cd build
cmake ../external/ -G Ninja -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always
ninja
cd ..
