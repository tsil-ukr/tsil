#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

KTS_FILES=(
  "Помилка.ц"
  "Середовище.ц"
  "Тип.ц"
  "Ц.ц"
  "К/К.ц"
  "К/КВиконати.ц"
  "К/КВиконатиШаблон.ц"
  "К/КЗвернутись.ц"
  "К/КЗмінити.ц"
  "К/КОперація.ц"
  "К/КОтримати.ц"
  "К/КПеревизначити.ц"
  "К/КСтворитиДію.ц"
  "К/КСтворитиСинонім.ц"
  "К/КСтворитиСтруктуру.ц"
  "К/КСтворитиЦіль.ц"
  "К/КСтворитиШаблон.ц"
)

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
