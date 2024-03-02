cmake_minimum_required(VERSION 3.26)
project(tsil_parser)

set(CMAKE_CXX_STANDARD 20)

set(TSIL_PARSER tsil_parser CACHE INTERNAL "")
set(TSIL_PARSER_SRC
        visitor/visitArgs.cpp
        visitor/visitArithmetic.cpp
        visitor/visitAssign.cpp
        visitor/visitBitwise.cpp
        visitor/visitBitwise_not.cpp
        visitor/visitBody.cpp
        visitor/visitCall.cpp
        visitor/visitComparison.cpp
        visitor/visitDefine.cpp
        visitor/visitDiia.cpp
        visitor/visitFile.cpp
        visitor/visitIdentifier.cpp
        visitor/visitIf.cpp
        visitor/visitNegative.cpp
        visitor/visitNested.cpp
        visitor/visitNot.cpp
        visitor/visitNumber.cpp
        visitor/visitParams.cpp
        visitor/visitPositive.cpp
        visitor/visitProgram.cpp
        visitor/visitString.cpp
        visitor/visitStructure.cpp
        visitor/visitLogical.cpp
        visitor/visitType.cpp
        visitor/visitWhile.cpp
        ast.h
        parser.cpp
        parser.h
        tools.cpp
        tools.h
        main.cpp
)

add_subdirectory(syntax)

add_library(${TSIL_PARSER} ${TSIL_PARSER_SRC})

target_include_directories(${TSIL_PARSER} PUBLIC .)
target_link_libraries(${TSIL_PARSER} tsil_syntax)