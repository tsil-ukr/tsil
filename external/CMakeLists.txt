cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)

file(READ "../ВЕРСІЯ" TSIL_VERSION)

add_subdirectory(parser)
add_subdirectory(xl)

set(TSIL_SRC
        main.cpp
        ../.плавлення/скомпільоване/Ц.ц.o
        ../.плавлення/скомпільоване/К/К.ц.o
        ../.плавлення/скомпільоване/К/КЗвернутись.ц.o
        ../.плавлення/скомпільоване/К/КВиконати.ц.o
        ../.плавлення/скомпільоване/К/КПеревизначити.ц.o
        ../.плавлення/скомпільоване/К/КЗмінити.ц.o
        ../.плавлення/скомпільоване/К/КОтримати.ц.o
        ../.плавлення/скомпільоване/К/КСтворитиЦіль.ц.o
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PUBLIC tsil_parser xl bib)
target_link_options(tsil PUBLIC -L/usr/local/lib/ціль/бібліотека)
target_compile_options(tsil PUBLIC -fexceptions -DTSIL_VERSION="${TSIL_VERSION}")
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
