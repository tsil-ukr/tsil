#!/usr/bin/env sh
set -x
set -e

mkdir -p out
mkdir -p build/ПМ
mkdir -p build/КЦ
mkdir -p build/КЦ/розбирач
mkdir -p build/КЦ/перекладач
mkdir -p build/біб
mkdir -p build/біб/КД

COMPILED_C_FILES=""
CXX_OPTIONS="-g -O0"
#CXX_OPTIONS="-O3"

doCompile() {
#  ./out/старт "$1" > build/"$1".ll
  ціль build/"$1".ll скомпілювати "$1"
  COMPILED_C_FILES="$COMPILED_C_FILES build/$1.ll"
}

doCompile "КЦ/ОбʼєктТипу.ю8.ц"
doCompile "КЦ/перекладач/Текст.ю8.ц"
doCompile "КЦ/перекладач/Ціль.ю8.ц"
doCompile "КЦ/ОбʼєктНезавантаженогоЗначення.ю8.ц"
doCompile "старт.ю8.ц"
doCompile "КЦ/перекладач/Шаблон.ю8.ц"
doCompile "КЦ/перекладач/Структура.ю8.ц"
doCompile "КЦ/перекладач/Дія.ю8.ц"
doCompile "КЦ/розбирач/розбирач.ю8.ц"
doCompile "КЦ/перекладач/Взяти.ю8.ц"
doCompile "КЦ/перекладач/ВиконатиШаблон.ю8.ц"
doCompile "КЦ/ОбʼєктШаблону.ю8.ц"
doCompile "КЦ/КЦ.ю8.ц"
doCompile "КЦ/перекладач/Тіло.ю8.ц"
doCompile "КЦ/Помилка.ю8.ц"
doCompile "КЦ/перекладач/ВаріативнийТип.ю8.ц"
doCompile "КЦ/перекладач/Вернути.ю8.ц"
doCompile "КЦ/перекладач/Крок.ю8.ц"
doCompile "КЦ/перекладач/Стрибнути.ю8.ц"
doCompile "КЦ/перекладач/Обʼєкт.ю8.ц"
doCompile "ПМ/ПМ.ю8.ц"
doCompile "КЦ/Обʼєкт.ю8.ц"
doCompile "КЦ/ОбʼєктДії.ю8.ц"
doCompile "КЦ/ОбʼєктСекції.ю8.ц"
doCompile "КЦ/ОбʼєктСирогоЗначення.ю8.ц"
doCompile "КЦ/ОбʼєктЗначення.ю8.ц"
doCompile "КЦ/перекладач/ВиконатиДію.ю8.ц"
doCompile "КЦ/перекладач/ЗмінитиВСередовищі.ю8.ц"
doCompile "КЦ/перекладач/Значення.ю8.ц"
doCompile "КЦ/перекладач/Операція.ю8.ц"
doCompile "КЦ/перекладач/ОтриматиЗСередовища.ю8.ц"
doCompile "КЦ/перекладач/ОтриматиВластивість.ю8.ц"
doCompile "КЦ/перекладач/ОтриматиЕлемент.ю8.ц"
doCompile "КЦ/перекладач/ОтриматиСекційнуВластивість.ю8.ц"
doCompile "КЦ/перекладач/ЗмінитиВластивість.ю8.ц"
doCompile "КЦ/перекладач/ЗмінитиСекційнуВластивість.ю8.ц"
doCompile "КЦ/перекладач/ЗмінитиЕлемент.ю8.ц"
doCompile "КЦ/перекладач/Поки.ю8.ц"
doCompile "КЦ/перекладач/Якщо.ю8.ц"
doCompile "КЦ/перекладач/Секція.ю8.ц"
doCompile "КЦ/перекладач/Синонім.ю8.ц"
doCompile "КЦ/перекладач/Однооперація.ю8.ц"
doCompile "КЦ/перекладач/Число.ю8.ц"
doCompile "КЦ/перекладач/ТипДії.ю8.ц"
doCompile "біб/КД/КД.ю8.ц"

clang $CXX_OPTIONS -c -o build/біб/bib.o біб/bib.c
clang $CXX_OPTIONS -c -o build/ext.o ext.c

clang++ $CXX_OPTIONS -o out/старт \
  $COMPILED_C_FILES \
  build/ext.o \
  build/біб/bib.o \
  інструкція_llvm.cpp \
  `llvm-config --cxxflags --ldflags --system-libs --libs`