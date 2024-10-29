cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)

file(READ "../ВЕРСІЯ" TSIL_VERSION)

add_subdirectory(tsil_parser)
add_subdirectory(tsil_llvm)
add_subdirectory(tsil_toc)

set(TSIL_SRC
        main.cpp
        tsil_cli.cpp
        bib.c
        ../.плавлення-use-original/скомпільоване/біб.ц.o
        ../.плавлення-use-original/скомпільоване/Обʼєкт.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктГрупиДій.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктДії.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктЗначення.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктНезавантаженогоЗначення.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктСекції.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктСирогоЗначення.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктТипу.ц.o
        ../.плавлення-use-original/скомпільоване/ОбʼєктШаблону.ц.o
        ../.плавлення-use-original/скомпільоване/Помилка.ц.o
        ../.плавлення-use-original/скомпільоване/Середовище.ц.o
        ../.плавлення-use-original/скомпільоване/Тип.ц.o
        ../.плавлення-use-original/скомпільоване/Ц.ц.o
        ../.плавлення-use-original/скомпільоване/К/К.ц.o
        ../.плавлення-use-original/скомпільоване/К/КВернути.ц.o
        ../.плавлення-use-original/скомпільоване/К/КВзяти.ц.o
        ../.плавлення-use-original/скомпільоване/К/КВиконати.ц.o
        ../.плавлення-use-original/скомпільоване/К/КВиконатиШаблон.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЗвернутись.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЗмінити.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЗмінитиВСекції.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЗмінитиЗаПозицією.ц.o
        ../.плавлення-use-original/скомпільоване/К/КОбʼєкт.ц.o
        ../.плавлення-use-original/скомпільоване/К/КТекст.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЧисло.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЗначенняЯкщо.ц.o
        ../.плавлення-use-original/скомпільоване/К/КОперація.ц.o
        ../.плавлення-use-original/скомпільоване/К/КОтримати.ц.o
        ../.плавлення-use-original/скомпільоване/К/КОтриматиЗаПозицією.ц.o
        ../.плавлення-use-original/скомпільоване/К/КОтриматиЗіСекції.ц.o
        ../.плавлення-use-original/скомпільоване/К/КПеревизначити.ц.o
        ../.плавлення-use-original/скомпільоване/К/КПоки.ц.o
        ../.плавлення-use-original/скомпільоване/К/КСамоОперація.ц.o
        ../.плавлення-use-original/скомпільоване/К/КДія.ц.o
        ../.плавлення-use-original/скомпільоване/К/КСекція.ц.o
        ../.плавлення-use-original/скомпільоване/К/КСинонім.ц.o
        ../.плавлення-use-original/скомпільоване/К/КСтруктура.ц.o
        ../.плавлення-use-original/скомпільоване/К/КТип.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЦіль.ц.o
        ../.плавлення-use-original/скомпільоване/К/КШаблон.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЯк.ц.o
        ../.плавлення-use-original/скомпільоване/К/КЯкщо.ц.o
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PUBLIC tsil_parser tsil_llvm tsil_toc)
if (DEFINED TSIL_STATIC)
    target_link_options(tsil PUBLIC -static)
else ()
    target_link_options(tsil PUBLIC)
endif ()
target_compile_options(tsil PUBLIC -fexceptions -DTSIL_VERSION="${TSIL_VERSION}")
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
