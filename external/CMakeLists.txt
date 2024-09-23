cmake_minimum_required(VERSION 3.26)
project(tsil)

set(CMAKE_CXX_STANDARD 20)

include_directories(../.llvm-source-and-build/llvm-project-19.1.0.build/llvm/include)

find_package(LLVM REQUIRED CONFIG PATHS ../.llvm-source-and-build/llvm-project-19.1.0.build/llvm NO_DEFAULT_PATH)

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

file(READ "../ВЕРСІЯ" TSIL_VERSION)

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
        compiler/Scope/synonym.cpp
        compiler/Scope/type.cpp
        compiler/Compiler.cpp
        compiler/CompilerError.cpp
        compiler/Scope.cpp
        compiler/tk.cpp
        compiler/Type.cpp
        compiler/xl.cpp
        main.cpp
)

llvm_map_components_to_libnames(llvm_libs
        #        aarch64asmparser
        #        aarch64codegen
        #        aarch64desc
        #        aarch64disassembler
        #        aarch64info
        #        aarch64utils
        #        aggressiveinstcombine
        #        amdgpuasmparser
        #        amdgpucodegen
        #        amdgpudesc
        #        amdgpudisassembler
        #        amdgpuinfo
        #        amdgputargetmca
        #        amdgpuutils
        #        analysis
        #        armasmparser
        #        armcodegen
        #        armdesc
        #        armdisassembler
        #        arminfo
        #        armutils
        #        asmparser
        #        asmprinter
        #        avrasmparser
        #        avrcodegen
        #        avrdesc
        #        avrdisassembler
        #        avrinfo
        #        binaryformat
        #        bitreader
        #        bitstreamreader
        #        bitwriter
        #        bpfasmparser
        #        bpfcodegen
        #        bpfdesc
        #        bpfdisassembler
        #        bpfinfo
        #        cfguard
        #        cfiverify
        #        codegen
        #        codegendata
        #        codegentypes
        core
        #        coroutines
        #        coverage
        #        debuginfobtf
        #        debuginfocodeview
        #        debuginfod
        #        debuginfodwarf
        #        debuginfogsym
        #        debuginfologicalview
        #        debuginfomsf
        #        debuginfopdb
        #        demangle
        #        diff
        #        dlltooldriver
        #        dwarflinker
        #        dwarflinkerclassic
        #        dwarflinkerparallel
        #        dwp
        #        executionengine
        #        exegesis
        #        exegesisaarch64
        #        exegesismips
        #        exegesispowerpc
        #        exegesisx86
        #        extensions
        #        filecheck
        #        frontenddriver
        #        frontendhlsl
        #        frontendoffloading
        #        frontendopenacc
        #        frontendopenmp
        #        fuzzercli
        #        fuzzmutate
        #        globalisel
        #        hexagonasmparser
        #        hexagoncodegen
        #        hexagondesc
        #        hexagondisassembler
        #        hexagoninfo
        #        hipstdpar
        #        instcombine
        #        instrumentation
        #        interfacestub
        #        interpreter
        #        ipo
        #        irprinter
        #        irreader
        #        jitlink
        #        lanaiasmparser
        #        lanaicodegen
        #        lanaidesc
        #        lanaidisassembler
        #        lanaiinfo
        #        libdriver
        #        lineeditor
        #        linker
        #        loongarchasmparser
        #        loongarchcodegen
        #        loongarchdesc
        #        loongarchdisassembler
        #        loongarchinfo
        #        lto
        #        mc
        #        mca
        #        mcdisassembler
        #        mcjit
        #        mcparser
        #        mipsasmparser
        #        mipscodegen
        #        mipsdesc
        #        mipsdisassembler
        #        mipsinfo
        #        mirparser
        #        msp430asmparser
        #        msp430codegen
        #        msp430desc
        #        msp430disassembler
        #        msp430info
        #        nvptxcodegen
        #        nvptxdesc
        #        nvptxinfo
        #        objcarcopts
        #        objcopy
        #        object
        #        objectyaml
        optdriver
        #        option
        #        orcdebugging
        #        orcjit
        #        orcshared
        #        orctargetprocess
        #        passes
        #        powerpcasmparser
        #        powerpccodegen
        #        powerpcdesc
        #        powerpcdisassembler
        #        powerpcinfo
        #        profiledata
        #        remarks
        #        riscvasmparser
        #        riscvcodegen
        #        riscvdesc
        #        riscvdisassembler
        #        riscvinfo
        #        riscvtargetmca
        #        runtimedyld
        #        sandboxir
        #        scalaropts
        #        selectiondag
        #        sparcasmparser
        #        sparccodegen
        #        sparcdesc
        #        sparcdisassembler
        #        sparcinfo
        support
        #        symbolize
        #        systemzasmparser
        #        systemzcodegen
        #        systemzdesc
        #        systemzdisassembler
        #        systemzinfo
        #        tablegen
        #        tablegenbasic
        #        tablegencommon
        #        target
        #        targetparser
        #        textapi
        #        textapibinaryreader
        #        transformutils
        #        veasmparser
        #        vecodegen
        #        vectorize
        #        vedesc
        #        vedisassembler
        #        veinfo
        #        webassemblyasmparser
        #        webassemblycodegen
        #        webassemblydesc
        #        webassemblydisassembler
        #        webassemblyinfo
        #        webassemblyutils
        #        windowsdriver
        #        windowsmanifest
        #        x86asmparser
        #        x86codegen
        #        x86desc
        #        x86disassembler
        #        x86info
        #        x86targetmca
        #        xcorecodegen
        #        xcoredesc
        #        xcoredisassembler
        #        xcoreinfo
        #        xray
)

add_executable(tsil ${TSIL_SRC})
target_link_libraries(tsil PUBLIC tsil_parser ${llvm_libs})
target_link_options(tsil PUBLIC)
target_compile_options(tsil PUBLIC -fexceptions -DTSIL_VERSION="${TSIL_VERSION}" -DTSIL_X_EXPANDED_NAMES="${TSIL_X_EXPANDED_NAMES}")
set_target_properties(tsil PROPERTIES OUTPUT_NAME "ціль")

add_executable(tsil_release ${TSIL_SRC})
target_link_libraries(tsil_release PUBLIC tsil_parser ${llvm_libs})
target_link_options(tsil_release PUBLIC -static -flto)
target_compile_options(tsil_release PUBLIC -O3 -DTSIL_VERSION="${TSIL_VERSION}" -DTSIL_X_EXPANDED_NAMES="${TSIL_X_EXPANDED_NAMES}")
set_target_properties(tsil_release PROPERTIES OUTPUT_NAME "ціль_випуск")