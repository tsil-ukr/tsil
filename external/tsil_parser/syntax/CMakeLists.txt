set(TSIL_SYNTAX tsil_syntax CACHE INTERNAL "")
set(TSIL_SYNTAX_SRC
        source/TsilLexer.cpp
        source/TsilParser.cpp
        source/TsilParserBaseListener.cpp
        source/TsilParserListener.cpp
        source/TsilParserListener.cpp
        source/TsilParserBaseVisitor.cpp
        source/TsilParserVisitor.cpp
)

cmake_minimum_required(VERSION 3.26)
project(${TSIL_SYNTAX})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(antlr4-cpp-runtime)

add_library(${TSIL_SYNTAX} ${TSIL_SYNTAX_SRC})

target_include_directories(${TSIL_SYNTAX} PUBLIC source)

target_link_libraries(${TSIL_SYNTAX} antlr4_cpp_runtime)

target_compile_options(${TSIL_SYNTAX} PRIVATE -w -O3)
target_compile_options(${TSIL_SYNTAX} PUBLIC -Wno-attributes)
