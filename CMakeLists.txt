cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Release")

add_subdirectory(parser)

set(TSIL_SRC
        compiler/nodes/compileAs.cpp
        compiler/nodes/compileAssign.cpp
        compiler/nodes/compileValue.cpp
        compiler/nodes/compileBinary.cpp
        compiler/nodes/compileCall.cpp
        compiler/nodes/compileConstruct.cpp
        compiler/nodes/compileDefine.cpp
        compiler/nodes/compileDiia.cpp
        compiler/nodes/compileGet.cpp
        compiler/nodes/compileGep.cpp
        compiler/nodes/compileLoad.cpp
        compiler/nodes/compileNumber.cpp
        compiler/nodes/compileSet.cpp
        compiler/nodes/compileSizeof.cpp
        compiler/nodes/compileString.cpp
        compiler/nodes/compileStructure.cpp
        compiler/compiler.cpp
        compiler/compiler.h
        compiler/x.cpp
        compiler/x.h
        main.cpp
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PRIVATE tsil_parser)
target_link_options(tsil PRIVATE -static-libgcc -static-libstdc++)
target_compile_options(tsil PRIVATE -fexceptions)
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")
