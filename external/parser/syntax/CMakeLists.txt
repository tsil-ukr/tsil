set(TSIL_SYNTAX tsil_syntax CACHE INTERNAL "")
set(TSIL_SYNTAX_SRC
        TsilLexer.cpp
        TsilLexer.h
        TsilParser.cpp
        TsilParser.h
        TsilParserBaseListener.cpp
        TsilParserBaseListener.h
        TsilParserListener.cpp
        TsilParserListener.h
)

add_subdirectory(antlr4-cpp-runtime)

add_library(${TSIL_SYNTAX} ${TSIL_SYNTAX_SRC})

target_include_directories(${TSIL_SYNTAX} PUBLIC
        .
)
target_link_libraries(${TSIL_SYNTAX} antlr4_cpp_runtime)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
    target_compile_options(${TSIL_SYNTAX} PRIVATE
            -g -Wall -O0
    )
else ()
    target_compile_options(${TSIL_SYNTAX} PRIVATE
            -w -O3
    )
    target_compile_options(${TSIL_SYNTAX} PUBLIC
            -Wno-attributes
    )
endif ()
