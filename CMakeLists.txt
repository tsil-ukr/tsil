cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_SYSTEM_NAME Linux)
#set(CMAKE_SYSTEM_PROCESSOR x86_64)
#set(triple x86_64-linux-gnu)
#set(CMAKE_C_COMPILER /usr/bin/clang)
#set(CMAKE_C_COMPILER_TARGET ${triple})
#set(CMAKE_CXX_COMPILER /usr/bin/clang++)
#set(CMAKE_CXX_COMPILER_TARGET ${triple})

file(READ "VERSION" TSIL_VERSION)

add_subdirectory(parser)

set(TSIL_SRC
        compiler/Scope/access.cpp
        compiler/Scope/as.cpp
        compiler/Scope/binary.cpp
        compiler/Scope/call.cpp
        compiler/Scope/construct.cpp
        compiler/Scope/diia.cpp
        compiler/Scope/get.cpp
        compiler/Scope/identifier.cpp
        compiler/Scope/number.cpp
        compiler/Scope/section.cpp
        compiler/Scope/set.cpp
        compiler/Scope/string.cpp
        compiler/Scope/type.cpp
        compiler/Compiler.cpp
        compiler/CompilerError.cpp
        compiler/Scope.cpp
        compiler/tk.cpp
        compiler/Type.cpp
        compiler/x.cpp
        main.cpp
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PUBLIC tsil_parser)
target_link_options(tsil PUBLIC)
target_compile_options(tsil PUBLIC -fexceptions -DTSIL_VERSION="${TSIL_VERSION}" -DTSIL_X_EXPANDED_NAMES="${TSIL_X_EXPANDED_NAMES}")
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")

add_executable(tsil_release ${TSIL_SRC})
target_link_libraries(tsil_release PUBLIC tsil_parser)
target_link_options(tsil_release PUBLIC -static -flto)
target_compile_options(tsil_release PUBLIC -O3 -DTSIL_VERSION="${TSIL_VERSION}" -DTSIL_X_EXPANDED_NAMES="${TSIL_X_EXPANDED_NAMES}")
set_target_properties(tsil_release PROPERTIES OUTPUT_NAME "ціль_випуск")