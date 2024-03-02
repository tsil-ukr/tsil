cmake_minimum_required(VERSION 3.26)
project(tsvo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(parser)

add_executable(tsvo main.cpp)
target_link_libraries(tsvo tsil_parser LLVM)
target_compile_options(tsvo PRIVATE -fexceptions)
set_target_properties(tsvo PROPERTIES OUTPUT_NAME "цво")
