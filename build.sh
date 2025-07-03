#!/usr/bin/env sh
set -x
set -e

mkdir -p out
mkdir -p build/ПМ
mkdir -p build/КЦ
mkdir -p build/КЦ/розбирач
mkdir -p build/КЦ/перекладач
mkdir -p build/КЦ/значення
mkdir -p build/біб
mkdir -p build/біб/КД

COMPILED_C_FILES=""
CXX_OPTIONS="-g -O0"
#CXX_OPTIONS="-O3"

#TSIL="./out/старт"
TSIL="ціль"

doCompile() {
  $TSIL build/"$1".ll скомпілювати "$1"
  COMPILED_C_FILES="$COMPILED_C_FILES build/$1.ll"
}

doCompile "старт.ю8.ц"
doCompile "КЦ/Компілятор.ю8.ц"
doCompile "КЦ/Середовище.ю8.ц"
doCompile "КЦ/ТекстКоду.ю8.ц"
doCompile "КЦ/КЦ.ю8.ц"
doCompile "КЦ/ГотовіАргументиШаблону.ю8.ц"
doCompile "КЦ/значення/ОбʼєктТипу.ю8.ц"
doCompile "КЦ/перекладач/Текст.ю8.ц"
doCompile "КЦ/перекладач/Ціль.ю8.ц"
doCompile "КЦ/перекладач/Змінна.ю8.ц"
doCompile "КЦ/перекладач/Стала.ю8.ц"
doCompile "КЦ/значення/ОбʼєктНезавантаженогоЗначення.ю8.ц"
doCompile "КЦ/перекладач/Шаблон.ю8.ц"
doCompile "КЦ/перекладач/Структура.ю8.ц"
doCompile "КЦ/перекладач/Дія.ю8.ц"
doCompile "КЦ/розбирач/розбирач.ю8.ц"
doCompile "КЦ/перекладач/Взяти.ю8.ц"
doCompile "КЦ/перекладач/ВиконатиШаблон.ю8.ц"
doCompile "КЦ/значення/ОбʼєктШаблону.ю8.ц"
doCompile "КЦ/перекладач/Тіло.ю8.ц"
doCompile "КЦ/Помилка.ю8.ц"
doCompile "КЦ/перекладач/ВаріативнийТип.ю8.ц"
doCompile "КЦ/перекладач/Вернути.ю8.ц"
doCompile "КЦ/перекладач/Крок.ю8.ц"
doCompile "КЦ/перекладач/Стрибнути.ю8.ц"
doCompile "КЦ/перекладач/Обʼєкт.ю8.ц"
doCompile "КЦ/значення/Обʼєкт.ю8.ц"
doCompile "КЦ/значення/ОбʼєктДії.ю8.ц"
doCompile "КЦ/значення/ОбʼєктСекції.ю8.ц"
doCompile "КЦ/значення/ОбʼєктСирогоЗначення.ю8.ц"
doCompile "КЦ/значення/ОбʼєктЗначення.ю8.ц"
doCompile "КЦ/Шлях.ю8.ц"
doCompile "КЦ/Назва.ю8.ц"
doCompile "КЦ/Параметр.ю8.ц"
doCompile "КЦ/Параметри.ю8.ц"
doCompile "КЦ/Крок.ю8.ц"
doCompile "КЦ/Кроки.ю8.ц"
doCompile "КЦ/Стрибок.ю8.ц"
doCompile "КЦ/Стрибки.ю8.ц"
doCompile "КЦ/ВзятіФайли.ю8.ц"
doCompile "КЦ/РозібранийТекст.ю8.ц"
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
doCompile "ПМ/ПМ.ю8.ц"
#doCompile "ПМ/ПМ2.ю8.ц"

clang $CXX_OPTIONS -c -o build/біб/bib.o біб/bib.c
clang $CXX_OPTIONS -c -o build/ext.o ext.c

clang++ $CXX_OPTIONS -o out/старт \
  $COMPILED_C_FILES \
  build/ext.o \
  build/біб/bib.o \
  інструкція_llvm.cpp \
  `llvm-config --cxxflags --ldflags --system-libs --libs`

#clang++ $CXX_OPTIONS -o out/старт \
#  $COMPILED_C_FILES \
#  build/ext.o \
#  build/біб/bib.o