cmake_minimum_required(VERSION 3.26)
project(ozts)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(parser)

add_executable(ozts main.cpp)
target_link_libraries(ozts tsil_parser LLVM)
target_compile_options(ozts PRIVATE -fexceptions)
set_target_properties(ozts PROPERTIES OUTPUT_NAME "озц")
