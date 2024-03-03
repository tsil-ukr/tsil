cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(parser)

add_executable(tsil main.cpp)
target_link_libraries(tsil tsil_parser LLVM)
target_compile_options(tsil PRIVATE -fexceptions)
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
