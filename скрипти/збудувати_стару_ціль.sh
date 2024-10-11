#!/usr/bin/env bash

set -e

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

mkdir -p build-old
cd build-old
cmake -DTSIL_X_EXPANDED_NAMES=1 ../old/
make -j4 tsil_release
mv ціль_випуск ціль
cd ..

export TSIL="$(pwd)/build-old/ціль"

bash ./old/бібліотека/збудувати.sh ./old/бібліотека ./.плавлення-бібліотеки
cp ./.плавлення-бібліотеки/бібліотека/біб.a ./.плавлення-бібліотеки/бібліотека/libbib.a