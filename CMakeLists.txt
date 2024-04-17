cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Release")

add_subdirectory(parser)

set(TSIL_SRC
        compiler/nodes/compile_as_node.cpp
        compiler/nodes/compile_ast_value.cpp
        compiler/nodes/compile_assign_node.cpp
        compiler/nodes/compile_call_node.cpp
        compiler/nodes/compile_constructor_node.cpp
        compiler/nodes/compile_define_node.cpp
        compiler/nodes/compile_diia_node.cpp
        compiler/nodes/compile_get_node.cpp
        compiler/nodes/compile_get_pointer_node.cpp
        compiler/nodes/compile_identifier_node.cpp
        compiler/nodes/compile_number_node.cpp
        compiler/nodes/compile_set_node.cpp
        compiler/nodes/compile_sizeof_node.cpp
        compiler/nodes/compile_string_node.cpp
        compiler/nodes/compile_structure_node.cpp
        compiler/compiler.cpp
        compiler/compiler.h
        compiler/x.cpp
        compiler/x.h
        main.cpp
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PRIVATE tsil_parser)
target_compile_options(tsil PRIVATE -fexceptions)
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
