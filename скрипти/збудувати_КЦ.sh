#!/usr/bin/env bash

set -e

TSIL="$1"
if [ -z "$TSIL" ]; then
  TSIL="ціль"
fi
TSIL_EXECNAME="ціль"
# check if build/ціль exist
if [ -f "build/ціль" ]; then
  cp -r "build/ціль" "build/ціль-$(date +%s)"
fi

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"

KTS_FILES=(
  "біб.ц"
  "Обʼєкт.ц"
  "ОбʼєктГрупиДій.ц"
  "ОбʼєктДії.ц"
  "ОбʼєктЗначення.ц"
  "ОбʼєктНезавантаженогоЗначення.ц"
  "ОбʼєктСекції.ц"
  "ОбʼєктСирогоЗначення.ц"
  "ОбʼєктТипу.ц"
  "ОбʼєктШаблону.ц"
  "Помилка.ц"
  "Середовище.ц"
  "Тип.ц"
  "Ц.ц"
  "К/К.ц"
  "К/КВернути.ц"
  "К/КВзяти.ц"
  "К/КВиконати.ц"
  "К/КВиконатиШаблон.ц"
  "К/КЗвернутись.ц"
  "К/КЗмінити.ц"
  "К/КЗмінитиВСекції.ц"
  "К/КЗмінитиЗаПозицією.ц"
  "К/КОбʼєкт.ц"
  "К/КТекст.ц"
  "К/КЧисло.ц"
  "К/КЗначенняЯкщо.ц"
  "К/КОперація.ц"
  "К/КОтримати.ц"
  "К/КОтриматиЗаПозицією.ц"
  "К/КОтриматиЗіСекції.ц"
  "К/КПерезаписати.ц"
  "К/КПерелік.ц"
  "К/КПоки.ц"
  "К/КСамоОперація.ц"
  "К/КДія.ц"
  "К/КСекція.ц"
  "К/КСинонім.ц"
  "К/КСтруктура.ц"
  "К/КТип.ц"
  "К/КЦіль.ц"
  "К/КШаблон.ц"
  "К/КЯк.ц"
  "К/КЯкщо.ц"
  "К/КЄ.ц"
)

PWDR="$(pwd)"

cd КЦ
for KTS_FILE in "${KTS_FILES[@]}"; do
  CHANGED_AT=$(stat -c %y $KTS_FILE)
  CHANGED_AT_OLD=$(cat "../.плавлення-КЦ/скомпільоване/$KTS_FILE.ll.changed_at" 2>/dev/null || echo "")
  if [ ! -f "../.плавлення-КЦ/скомпільоване/$KTS_FILE.ll" ] || [ "$CHANGED_AT" != "$CHANGED_AT_OLD" ]; then
    echo "$TSIL ../.плавлення-КЦ/скомпільоване/$KTS_FILE.ll скомпілювати --бібліотека=$PWDR/.плавлення-бібліотеки/бібліотека $KTS_FILE"
    $TSIL "../.плавлення-КЦ/скомпільоване/"$KTS_FILE".ll" скомпілювати --бібліотека="$PWDR/.плавлення-бібліотеки/бібліотека" "$KTS_FILE"

    echo "$CXX -c -o ../.плавлення-КЦ/скомпільоване/$KTS_FILE.o ../.плавлення-КЦ/скомпільоване/$KTS_FILE.ll -Wno-override-module"
    $CXX -c -o "../.плавлення-КЦ/скомпільоване/"$KTS_FILE".o" "../.плавлення-КЦ/скомпільоване/"$KTS_FILE".ll" -Wno-override-module

    echo "$CHANGED_AT" > "../.плавлення-КЦ/скомпільоване/$KTS_FILE.ll.changed_at"
  fi
done
cd ..

mkdir -p build
cd build
cmake ../external/ -G Ninja \
  -DCMAKE_CXX_FLAGS=-fdiagnostics-color=always \
  -DTSIL_STATIC="ON" \
  -DTSIL_LLVM_PATH="../../.llvm-source-and-build/llvm-project-19.1.0.build/llvm" \
  -DTSIL_EXECNAME="$TSIL_EXECNAME"
ninja
cd ..
