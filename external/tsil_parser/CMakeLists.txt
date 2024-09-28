set(TSIL_PARSER tsil_parser CACHE INTERNAL "")
set(TSIL_PARSER_SRC
        tools.cpp
        parser.cpp
        visitor.cpp
)

cmake_minimum_required(VERSION 3.26)
project(${TSIL_PARSER})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(syntax)

add_library(${TSIL_PARSER} ${TSIL_PARSER_SRC})

target_include_directories(${TSIL_PARSER} PUBLIC .)
target_link_libraries(${TSIL_PARSER} tsil_syntax)