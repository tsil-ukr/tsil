cmake_minimum_required(VERSION 3.26)
project(tsil_llvm)

set(CMAKE_CXX_STANDARD 20)

if (DEFINED TSIL_LLVM_PATH)
    find_package(LLVM REQUIRED CONFIG PATHS ${TSIL_LLVM_PATH} NO_DEFAULT_PATH)
    include_directories(${LLVM_INCLUDE_DIRS})
    separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
    add_definitions(${LLVM_DEFINITIONS_LIST})
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
    message(STATUS "Include LLVM dirs: ${LLVM_INCLUDE_DIRS}")
else ()
    find_package(LLVM REQUIRED CONFIG)
    include_directories(${LLVM_INCLUDE_DIRS})
    separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
    add_definitions(${LLVM_DEFINITIONS_LIST})
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
    message(STATUS "Include LLVM dirs: ${LLVM_INCLUDE_DIRS}")
endif ()

set(llvm_libs
        LLVMWindowsManifest
        LLVMXRay
        LLVMLibDriver
        LLVMDlltoolDriver
        LLVMTextAPIBinaryReader
        LLVMCoverage
        LLVMLineEditor
        LLVMSandboxIR
        LLVMXCoreDisassembler
        LLVMXCoreCodeGen
        LLVMXCoreDesc
        LLVMXCoreInfo
        LLVMX86TargetMCA
        LLVMX86Disassembler
        LLVMX86AsmParser
        LLVMX86CodeGen
        LLVMX86Desc
        LLVMX86Info
        LLVMWebAssemblyDisassembler
        LLVMWebAssemblyAsmParser
        LLVMWebAssemblyCodeGen
        LLVMWebAssemblyUtils
        LLVMWebAssemblyDesc
        LLVMWebAssemblyInfo
        LLVMVEDisassembler
        LLVMVEAsmParser
        LLVMVECodeGen
        LLVMVEDesc
        LLVMVEInfo
        LLVMSystemZDisassembler
        LLVMSystemZAsmParser
        LLVMSystemZCodeGen
        LLVMSystemZDesc
        LLVMSystemZInfo
        LLVMSparcDisassembler
        LLVMSparcAsmParser
        LLVMSparcCodeGen
        LLVMSparcDesc
        LLVMSparcInfo
        LLVMRISCVTargetMCA
        LLVMRISCVDisassembler
        LLVMRISCVAsmParser
        LLVMRISCVCodeGen
        LLVMRISCVDesc
        LLVMRISCVInfo
        LLVMPowerPCDisassembler
        LLVMPowerPCAsmParser
        LLVMPowerPCCodeGen
        LLVMPowerPCDesc
        LLVMPowerPCInfo
        LLVMNVPTXCodeGen
        LLVMNVPTXDesc
        LLVMNVPTXInfo
        LLVMMSP430Disassembler
        LLVMMSP430AsmParser
        LLVMMSP430CodeGen
        LLVMMSP430Desc
        LLVMMSP430Info
        LLVMMipsDisassembler
        LLVMMipsAsmParser
        LLVMMipsCodeGen
        LLVMMipsDesc
        LLVMMipsInfo
        LLVMLoongArchDisassembler
        LLVMLoongArchAsmParser
        LLVMLoongArchCodeGen
        LLVMLoongArchDesc
        LLVMLoongArchInfo
        LLVMLanaiDisassembler
        LLVMLanaiCodeGen
        LLVMLanaiAsmParser
        LLVMLanaiDesc
        LLVMLanaiInfo
        LLVMHexagonDisassembler
        LLVMHexagonCodeGen
        LLVMHexagonAsmParser
        LLVMHexagonDesc
        LLVMHexagonInfo
        LLVMBPFDisassembler
        LLVMBPFAsmParser
        LLVMBPFCodeGen
        LLVMBPFDesc
        LLVMBPFInfo
        LLVMAVRDisassembler
        LLVMAVRAsmParser
        LLVMAVRCodeGen
        LLVMAVRDesc
        LLVMAVRInfo
        LLVMARMDisassembler
        LLVMARMAsmParser
        LLVMARMCodeGen
        LLVMARMDesc
        LLVMARMUtils
        LLVMARMInfo
        LLVMAMDGPUTargetMCA
        LLVMAMDGPUDisassembler
        LLVMAMDGPUAsmParser
        LLVMAMDGPUCodeGen
        LLVMAMDGPUDesc
        LLVMAMDGPUUtils
        LLVMAMDGPUInfo
        LLVMAArch64Disassembler
        LLVMAArch64AsmParser
        LLVMAArch64CodeGen
        LLVMAArch64Desc
        LLVMAArch64Utils
        LLVMAArch64Info
        LLVMOrcDebugging
        LLVMOrcJIT
        LLVMWindowsDriver
        LLVMMCJIT
        LLVMJITLink
        LLVMInterpreter
        LLVMExecutionEngine
        LLVMRuntimeDyld
        LLVMOrcTargetProcess
        LLVMOrcShared
        LLVMDWP
        LLVMDebugInfoLogicalView
        LLVMDebugInfoGSYM
        LLVMOption
        LLVMObjectYAML
        LLVMObjCopy
        LLVMMCA
        LLVMMCDisassembler
        LLVMLTO
        LLVMPasses
        LLVMHipStdPar
        LLVMCFGuard
        LLVMCoroutines
        LLVMipo
        LLVMVectorize
        LLVMLinker
        LLVMInstrumentation
        LLVMFrontendOpenMP
        LLVMFrontendOffloading
        LLVMFrontendOpenACC
        LLVMFrontendHLSL
        LLVMFrontendDriver
        LLVMExtensions
        LLVMDWARFLinkerParallel
        LLVMDWARFLinkerClassic
        LLVMDWARFLinker
        LLVMCodeGenData
        LLVMGlobalISel
        LLVMMIRParser
        LLVMAsmPrinter
        LLVMSelectionDAG
        LLVMCodeGen
        LLVMTarget
        LLVMObjCARCOpts
        LLVMCodeGenTypes
        LLVMIRPrinter
        LLVMInterfaceStub
        LLVMFileCheck
        LLVMFuzzMutate
        LLVMScalarOpts
        LLVMInstCombine
        LLVMAggressiveInstCombine
        LLVMTransformUtils
        LLVMBitWriter
        LLVMAnalysis
        LLVMProfileData
        LLVMSymbolize
        LLVMDebugInfoBTF
        LLVMDebugInfoPDB
        LLVMDebugInfoMSF
        LLVMDebugInfoDWARF
        LLVMObject
        LLVMTextAPI
        LLVMMCParser
        LLVMIRReader
        LLVMAsmParser
        LLVMMC
        LLVMDebugInfoCodeView
        LLVMBitReader
        LLVMFuzzerCLI
        LLVMCore
        LLVMRemarks
        LLVMBitstreamReader
        LLVMBinaryFormat
        LLVMTargetParser
        LLVMSupport
        LLVMDemangle
)

add_library(tsil_llvm STATIC tsil_llvm.cpp)
target_link_libraries(tsil_llvm PUBLIC ${llvm_libs})
