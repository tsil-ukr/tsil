cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Release")

add_subdirectory(parser)

set(TSIL_SRC
        compiler/x.cpp
        compiler/Compiler.cpp
        compiler/CompilerError.cpp
        compiler/Scope.cpp
        compiler/tk.cpp
        compiler/Type.cpp
        main.cpp
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PRIVATE tsil_parser)
target_link_options(tsil PRIVATE -static-libgcc -static-libstdc++)
target_compile_options(tsil PRIVATE -fexceptions)
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
