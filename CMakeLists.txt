cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(parser)

set(TSIL_SRC
        compiler/nodes/compile_ast_value.cpp
        compiler/nodes/compile_call_node.cpp
        compiler/nodes/compile_define_node.cpp
        compiler/nodes/compile_diia_node.cpp
        compiler/nodes/compile_identifier_node.cpp
        compiler/nodes/compile_number_node.cpp
        compiler/nodes/compile_string_node.cpp
        compiler/compiler.cpp
        compiler/compiler.h
        main.cpp
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil tsil_parser LLVM)
target_compile_options(tsil PRIVATE -fexceptions)
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
