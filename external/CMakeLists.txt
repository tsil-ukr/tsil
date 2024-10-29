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
        ${TSIL_FUSE_PATH}/скомпільоване/біб.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/Обʼєкт.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктГрупиДій.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктДії.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктЗначення.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктНезавантаженогоЗначення.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктСекції.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктСирогоЗначення.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктТипу.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/ОбʼєктШаблону.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/Помилка.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/Середовище.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/Тип.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/Ц.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/К.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КВернути.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КВзяти.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КВиконати.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КВиконатиШаблон.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЗвернутись.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЗмінити.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЗмінитиВСекції.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЗмінитиЗаПозицією.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КОбʼєкт.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КТекст.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЧисло.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЗначенняЯкщо.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КОперація.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КОтримати.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КОтриматиЗаПозицією.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КОтриматиЗіСекції.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КПеревизначити.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КПоки.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КСамоОперація.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КДія.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КСекція.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КСинонім.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КСтруктура.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КТип.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЦіль.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КШаблон.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЯк.ц.o
        ${TSIL_FUSE_PATH}/скомпільоване/К/КЯкщо.ц.o
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PUBLIC tsil_parser tsil_llvm tsil_toc)
if (DEFINED TSIL_STATIC)
    target_link_options(tsil PUBLIC -static)
else ()
    target_link_options(tsil PUBLIC)
endif ()
target_compile_options(tsil PUBLIC -fexceptions -DTSIL_VERSION="${TSIL_VERSION}")
set_target_properties(tsil PROPERTIES OUTPUT_NAME "${TSIL_EXECNAME}")
