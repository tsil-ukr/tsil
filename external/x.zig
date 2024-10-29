const std = @import("std");
const builtin = @import("builtin");
const assert = std.debug.assert;
const io = std.io;
const fs = std.fs;
const mem = std.mem;
const process = std.process;
const Allocator = mem.Allocator;
const ArrayList = std.ArrayList;
const Ast = std.zig.Ast;
const Color = std.zig.Color;
const warn = std.log.warn;
const ThreadPool = std.Thread.Pool;
const cleanExit = std.process.cleanExit;
const native_os = builtin.os.tag;

const tracy = @import("tracy.zig");
const Compilation = @import("Compilation.zig");
const link = @import("link.zig");
const Package = @import("Package.zig");
const build_options = @import("build_options");
const introspect = @import("introspect.zig");
const EnvVar = std.zig.EnvVar;
const LibCInstallation = std.zig.LibCInstallation;
const wasi_libc = @import("wasi_libc.zig");
const Cache = std.Build.Cache;
const target_util = @import("target.zig");
const crash_report = @import("crash_report.zig");
const Zcu = @import("Zcu.zig");
const AstGen = std.zig.AstGen;
const mingw = @import("mingw.zig");
const Server = std.zig.Server;
const dev = @import("dev.zig");

pub const std_options = .{
    .wasiCwd = wasi_cwd,
    .logFn = log,
    .enable_segfault_handler = false,

    .log_level = switch (builtin.mode) {
        .Debug => .debug,
        .ReleaseSafe, .ReleaseFast => .info,
        .ReleaseSmall => .err,
    },
};

// Crash report needs to override the panic handler
pub const panic = crash_report.panic;

var wasi_preopens: fs.wasi.Preopens = undefined;
pub fn wasi_cwd() std.os.wasi.fd_t {
    // Expect the first preopen to be current working directory.
    const cwd_fd: std.posix.fd_t = 3;
    assert(mem.eql(u8, wasi_preopens.names[cwd_fd], "."));
    return cwd_fd;
}

fn getWasiPreopen(name: []const u8) Compilation.Directory {
    return .{
        .path = name,
        .handle = .{
            .fd = wasi_preopens.find(name) orelse fatal("WASI preopen not found: '{s}'", .{name}),
        },
    };
}

pub fn fatal(comptime format: []const u8, args: anytype) noreturn {
    std.log.err(format, args);
    process.exit(1);
}

const normal_usage =
    \\Usage: zig [command] [options]
    \\
    \\Commands:
    \\
    \\  build            Build project from build.zig
    \\  fetch            Copy a package into global cache and print its hash
    \\  init             Initialize a Zig package in the current directory
    \\
    \\  build-exe        Create executable from source or object files
    \\  build-lib        Create library from source or object files
    \\  build-obj        Create object from source or object files
    \\  test             Perform unit testing
    \\  run              Create executable and run immediately
    \\
    \\  ast-check        Look for simple compile errors in any set of files
    \\  fmt              Reformat Zig source into canonical form
    \\  reduce           Minimize a bug report
    \\  translate-c      Convert C code to Zig code
    \\
    \\  ar               Use Zig as a drop-in archiver
    \\  cc               Use Zig as a drop-in C compiler
    \\  c++              Use Zig as a drop-in C++ compiler
    \\  dlltool          Use Zig as a drop-in dlltool.exe
    \\  lib              Use Zig as a drop-in lib.exe
    \\  ranlib           Use Zig as a drop-in ranlib
    \\  objcopy          Use Zig as a drop-in objcopy
    \\  rc               Use Zig as a drop-in rc.exe
    \\
    \\  env              Print lib path, std path, cache directory, and version
    \\  help             Print this help and exit
    \\  std              View standard library documentation in a browser
    \\  libc             Display native libc paths file or validate one
    \\  targets          List available compilation targets
    \\  version          Print version number and exit
    \\  zen              Print Zen of Zig and exit
    \\
    \\General Options:
    \\
    \\  -h, --help       Print command-specific usage
    \\
;

const debug_usage = normal_usage ++
    \\
    \\Debug Commands:
    \\
    \\  changelist       Compute mappings from old ZIR to new ZIR
    \\  dump-zir         Dump a file containing cached ZIR
    \\  detect-cpu       Compare Zig's CPU feature detection vs LLVM
    \\  llvm-ints        Dump a list of LLVMABIAlignmentOfType for all integers
    \\
;

const usage = if (build_options.enable_debug_extensions) debug_usage else normal_usage;
const default_local_zig_cache_basename = ".zig-cache";

var log_scopes: std.ArrayListUnmanaged([]const u8) = .empty;

pub fn log(
    comptime level: std.log.Level,
    comptime scope: @Type(.enum_literal),
    comptime format: []const u8,
    args: anytype,
) void {
    // Hide debug messages unless:
    // * logging enabled with `-Dlog`.
    // * the --debug-log arg for the scope has been provided
    if (@intFromEnum(level) > @intFromEnum(std.options.log_level) or
        @intFromEnum(level) > @intFromEnum(std.log.Level.info))
    {
        if (!build_options.enable_logging) return;

        const scope_name = @tagName(scope);
        for (log_scopes.items) |log_scope| {
            if (mem.eql(u8, log_scope, scope_name))
                break;
        } else return;
    }

    const prefix1 = comptime level.asText();
    const prefix2 = if (scope == .default) ": " else "(" ++ @tagName(scope) ++ "): ";

    // Print the message to stderr, silently ignoring any errors
    std.debug.print(prefix1 ++ prefix2 ++ format ++ "\n", args);
}

var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{
    .stack_trace_frames = build_options.mem_leak_frames,
}){};

pub fn main() anyerror!void {
    crash_report.initialize();

    const use_gpa = (build_options.force_gpa or !builtin.link_libc) and native_os != .wasi;
    const gpa = gpa: {
        if (native_os == .wasi) {
            break :gpa std.heap.wasm_allocator;
        }
        if (use_gpa) {
            break :gpa general_purpose_allocator.allocator();
        }
        // We would prefer to use raw libc allocator here, but cannot
        // use it if it won't support the alignment we need.
        if (@alignOf(std.c.max_align_t) < @max(@alignOf(i128), std.atomic.cache_line)) {
            break :gpa std.heap.c_allocator;
        }
        break :gpa std.heap.raw_c_allocator;
    };
    defer if (use_gpa) {
        _ = general_purpose_allocator.deinit();
    };
    var arena_instance = std.heap.ArenaAllocator.init(gpa);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    const args = try process.argsAlloc(arena);

    if (tracy.enable_allocation) {
        var gpa_tracy = tracy.tracyAllocator(gpa);
        return mainArgs(gpa_tracy.allocator(), arena, args);
    }

    if (native_os == .wasi) {
        wasi_preopens = try fs.wasi.preopensAlloc(arena);
    }

    return mainArgs(gpa, arena, args);
}

/// Check that LLVM and Clang have been linked properly so that they are using the same
/// libc++ and can safely share objects with pointers to static variables in libc++
fn verifyLibcxxCorrectlyLinked() void {
    if (build_options.have_llvm and ZigClangIsLLVMUsingSeparateLibcxx()) {
        fatal(
            \\Zig was built/linked incorrectly: LLVM and Clang have separate copies of libc++
            \\       If you are dynamically linking LLVM, make sure you dynamically link libc++ too
        , .{});
    }
}

fn mainArgs(gpa: Allocator, arena: Allocator, args: []const []const u8) !void {
    const tr = tracy.trace(@src());
    defer tr.end();

    if (args.len <= 1) {
        std.log.info("{s}", .{usage});
        fatal("expected command argument", .{});
    }

    if (process.can_execv and std.posix.getenvZ("ZIG_IS_DETECTING_LIBC_PATHS") != null) {
        dev.check(.cc_command);
        // In this case we have accidentally invoked ourselves as "the system C compiler"
        // to figure out where libc is installed. This is essentially infinite recursion
        // via child process execution due to the CC environment variable pointing to Zig.
        // Here we ignore the CC environment variable and exec `cc` as a child process.
        // However it's possible Zig is installed as *that* C compiler as well, which is
        // why we have this additional environment variable here to check.
        var env_map = try process.getEnvMap(arena);

        const inf_loop_env_key = "ZIG_IS_TRYING_TO_NOT_CALL_ITSELF";
        if (env_map.get(inf_loop_env_key) != null) {
            fatal("The compilation links against libc, but Zig is unable to provide a libc " ++
                "for this operating system, and no --libc " ++
                "parameter was provided, so Zig attempted to invoke the system C compiler " ++
                "in order to determine where libc is installed. However the system C " ++
                "compiler is `zig cc`, so no libc installation was found.", .{});
        }
        try env_map.put(inf_loop_env_key, "1");

        // Some programs such as CMake will strip the `cc` and subsequent args from the
        // CC environment variable. We detect and support this scenario here because of
        // the ZIG_IS_DETECTING_LIBC_PATHS environment variable.
        if (mem.eql(u8, args[1], "cc")) {
            return process.execve(arena, args[1..], &env_map);
        } else {
            const modified_args = try arena.dupe([]const u8, args);
            modified_args[0] = "cc";
            return process.execve(arena, modified_args, &env_map);
        }
    }

    const cmd = args[1];
    const cmd_args = args[2..];
    if (mem.eql(u8, cmd, "build-exe")) {
        dev.check(.build_exe_command);
        return buildOutputType(gpa, arena, args, .{ .build = .Exe });
    } else if (mem.eql(u8, cmd, "build-lib")) {
        dev.check(.build_lib_command);
        return buildOutputType(gpa, arena, args, .{ .build = .Lib });
    } else if (mem.eql(u8, cmd, "build-obj")) {
        dev.check(.build_obj_command);
        return buildOutputType(gpa, arena, args, .{ .build = .Obj });
    } else if (mem.eql(u8, cmd, "test")) {
        dev.check(.test_command);
        return buildOutputType(gpa, arena, args, .zig_test);
    } else if (mem.eql(u8, cmd, "run")) {
        dev.check(.run_command);
        return buildOutputType(gpa, arena, args, .run);
    } else if (mem.eql(u8, cmd, "dlltool") or
        mem.eql(u8, cmd, "ranlib") or
        mem.eql(u8, cmd, "lib") or
        mem.eql(u8, cmd, "ar"))
    {
        dev.check(.ar_command);
        return process.exit(try llvmArMain(arena, args));
    } else if (mem.eql(u8, cmd, "build")) {
        dev.check(.build_command);
        return cmdBuild(gpa, arena, cmd_args);
    } else if (mem.eql(u8, cmd, "clang") or
        mem.eql(u8, cmd, "-cc1") or mem.eql(u8, cmd, "-cc1as"))
    {
        dev.check(.clang_command);
        return process.exit(try clangMain(arena, args));
    } else if (mem.eql(u8, cmd, "ld.lld") or
        mem.eql(u8, cmd, "lld-link") or
        mem.eql(u8, cmd, "wasm-ld"))
    {
        dev.check(.lld_linker);
        return process.exit(try lldMain(arena, args, true));
    } else if (mem.eql(u8, cmd, "cc")) {
        dev.check(.cc_command);
        return buildOutputType(gpa, arena, args, .cc);
    } else if (mem.eql(u8, cmd, "c++")) {
        dev.check(.cc_command);
        return buildOutputType(gpa, arena, args, .cpp);
    } else if (mem.eql(u8, cmd, "translate-c")) {
        dev.check(.translate_c_command);
        return buildOutputType(gpa, arena, args, .translate_c);
    } else if (mem.eql(u8, cmd, "rc")) {
        const use_server = cmd_args.len > 0 and std.mem.eql(u8, cmd_args[0], "--zig-integration");
        return jitCmd(gpa, arena, cmd_args, .{
            .cmd_name = "resinator",
            .root_src_path = "resinator/main.zig",
            .depend_on_aro = true,
            .prepend_zig_lib_dir_path = true,
            .server = use_server,
        });
    } else if (mem.eql(u8, cmd, "fmt")) {
        return jitCmd(gpa, arena, cmd_args, .{
            .cmd_name = "fmt",
            .root_src_path = "fmt.zig",
        });
    } else if (mem.eql(u8, cmd, "objcopy")) {
        return jitCmd(gpa, arena, cmd_args, .{
            .cmd_name = "objcopy",
            .root_src_path = "objcopy.zig",
        });
    } else if (mem.eql(u8, cmd, "fetch")) {
        return cmdFetch(gpa, arena, cmd_args);
    } else if (mem.eql(u8, cmd, "libc")) {
        return jitCmd(gpa, arena, cmd_args, .{
            .cmd_name = "libc",
            .root_src_path = "libc.zig",
            .prepend_zig_lib_dir_path = true,
        });
    } else if (mem.eql(u8, cmd, "std")) {
        return jitCmd(gpa, arena, cmd_args, .{
            .cmd_name = "std",
            .root_src_path = "std-docs.zig",
            .prepend_zig_lib_dir_path = true,
            .prepend_zig_exe_path = true,
            .prepend_global_cache_path = true,
        });
    } else if (mem.eql(u8, cmd, "init")) {
        return cmdInit(gpa, arena, cmd_args);
    } else if (mem.eql(u8, cmd, "targets")) {
        dev.check(.targets_command);
        const host = std.zig.resolveTargetQueryOrFatal(.{});
        const stdout = io.getStdOut().writer();
        return @import("print_targets.zig").cmdTargets(arena, cmd_args, stdout, host);
    } else if (mem.eql(u8, cmd, "version")) {
        dev.check(.version_command);
        try std.io.getStdOut().writeAll(build_options.version ++ "\n");
        // Check libc++ linkage to make sure Zig was built correctly, but only
        // for "env" and "version" to avoid affecting the startup time for
        // build-critical commands (check takes about ~10 μs)
        return verifyLibcxxCorrectlyLinked();
    } else if (mem.eql(u8, cmd, "env")) {
        dev.check(.env_command);
        verifyLibcxxCorrectlyLinked();
        return @import("print_env.zig").cmdEnv(arena, cmd_args, io.getStdOut().writer());
    } else if (mem.eql(u8, cmd, "reduce")) {
        return jitCmd(gpa, arena, cmd_args, .{
            .cmd_name = "reduce",
            .root_src_path = "reduce.zig",
        });
    } else if (mem.eql(u8, cmd, "zen")) {
        dev.check(.zen_command);
        return io.getStdOut().writeAll(info_zen);
    } else if (mem.eql(u8, cmd, "help") or mem.eql(u8, cmd, "-h") or mem.eql(u8, cmd, "--help")) {
        dev.check(.help_command);
        return io.getStdOut().writeAll(usage);
    } else if (mem.eql(u8, cmd, "ast-check")) {
        return cmdAstCheck(gpa, arena, cmd_args);
    } else if (mem.eql(u8, cmd, "detect-cpu")) {
        return cmdDetectCpu(gpa, arena, cmd_args);
    } else if (build_options.enable_debug_extensions and mem.eql(u8, cmd, "changelist")) {
        return cmdChangelist(gpa, arena, cmd_args);
    } else if (build_options.enable_debug_extensions and mem.eql(u8, cmd, "dump-zir")) {
        return cmdDumpZir(gpa, arena, cmd_args);
    } else if (build_options.enable_debug_extensions and mem.eql(u8, cmd, "llvm-ints")) {
        return cmdDumpLlvmInts(gpa, arena, cmd_args);
    } else {
        std.log.info("{s}", .{usage});
        fatal("unknown command: {s}", .{args[1]});
    }
}

const usage_build_generic =
    \\Usage: zig build-exe   [options] [files]
    \\       zig build-lib   [options] [files]
    \\       zig build-obj   [options] [files]
    \\       zig test        [options] [files]
    \\       zig run         [options] [files] [-- [args]]
    \\       zig translate-c [options] [file]
    \\
    \\Supported file types:
    \\                         .zig    Zig source code
    \\                           .o    ELF object file
    \\                           .o    Mach-O (macOS) object file
    \\                           .o    WebAssembly object file
    \\                         .obj    COFF (Windows) object file
    \\                         .lib    COFF (Windows) static library
    \\                           .a    ELF static library
    \\                           .a    Mach-O (macOS) static library
    \\                           .a    WebAssembly static library
    \\                          .so    ELF shared object (dynamic link)
    \\                         .dll    Windows Dynamic Link Library
    \\                       .dylib    Mach-O (macOS) dynamic library
    \\                         .tbd    (macOS) text-based dylib definition
    \\                           .s    Target-specific assembly source code
    \\                           .S    Assembly with C preprocessor (requires LLVM extensions)
    \\                           .c    C source code (requires LLVM extensions)
    \\  .cxx .cc .C .cpp .c++ .stub    C++ source code (requires LLVM extensions)
    \\                           .m    Objective-C source code (requires LLVM extensions)
    \\                          .mm    Objective-C++ source code (requires LLVM extensions)
    \\                          .bc    LLVM IR Module (requires LLVM extensions)
    \\                          .cu    Cuda source code (requires LLVM extensions)
    \\
    \\General Options:
    \\  -h, --help                Print this help and exit
    \\  --color [auto|off|on]     Enable or disable colored error messages
    \\  -j<N>                     Limit concurrent jobs (default is to use all CPU cores)
    \\  -fincremental             Enable incremental compilation
    \\  -fno-incremental          Disable incremental compilation
    \\  -femit-bin[=path]         (default) Output machine code
    \\  -fno-emit-bin             Do not output machine code
    \\  -femit-asm[=path]         Output .s (assembly code)
    \\  -fno-emit-asm             (default) Do not output .s (assembly code)
    \\  -femit-llvm-ir[=path]     Produce a .ll file with optimized LLVM IR (requires LLVM extensions)
    \\  -fno-emit-llvm-ir         (default) Do not produce a .ll file with optimized LLVM IR
    \\  -femit-llvm-bc[=path]     Produce an optimized LLVM module as a .bc file (requires LLVM extensions)
    \\  -fno-emit-llvm-bc         (default) Do not produce an optimized LLVM module as a .bc file
    \\  -femit-h[=path]           Generate a C header file (.h)
    \\  -fno-emit-h               (default) Do not generate a C header file (.h)
    \\  -femit-docs[=path]        Create a docs/ dir with html documentation
    \\  -fno-emit-docs            (default) Do not produce docs/ dir with html documentation
    \\  -femit-implib[=path]      (default) Produce an import .lib when building a Windows DLL
    \\  -fno-emit-implib          Do not produce an import .lib when building a Windows DLL
    \\  --show-builtin            Output the source of @import("builtin") then exit
    \\  --cache-dir [path]        Override the local cache directory
    \\  --global-cache-dir [path] Override the global cache directory
    \\  --zig-lib-dir [path]      Override path to Zig installation lib directory
    \\
    \\Global Compile Options:
    \\  --name [name]             Compilation unit name (not a file path)
    \\  --libc [file]             Provide a file which specifies libc paths
    \\  -x language               Treat subsequent input files as having type <language>
    \\  --dep [[import=]name]     Add an entry to the next module's import table
    \\  -M[name][=src]            Create a module based on the current per-module settings.
    \\                            The first module is the main module.
    \\                            "std" can be configured by omitting src
    \\                            After a -M argument, per-module settings are reset.
    \\  --error-limit [num]       Set the maximum amount of distinct error values
    \\  -fllvm                    Force using LLVM as the codegen backend
    \\  -fno-llvm                 Prevent using LLVM as the codegen backend
    \\  -flibllvm                 Force using the LLVM API in the codegen backend
    \\  -fno-libllvm              Prevent using the LLVM API in the codegen backend
    \\  -fclang                   Force using Clang as the C/C++ compilation backend
    \\  -fno-clang                Prevent using Clang as the C/C++ compilation backend
    \\  -fPIE                     Force-enable Position Independent Executable
    \\  -fno-PIE                  Force-disable Position Independent Executable
    \\  -flto                     Force-enable Link Time Optimization (requires LLVM extensions)
    \\  -fno-lto                  Force-disable Link Time Optimization
    \\  -fdll-export-fns          Mark exported functions as DLL exports (Windows)
    \\  -fno-dll-export-fns       Force-disable marking exported functions as DLL exports
    \\  -freference-trace[=num]   Show num lines of reference trace per compile error
    \\  -fno-reference-trace      Disable reference trace
    \\  -fbuiltin                 Enable implicit builtin knowledge of functions
    \\  -fno-builtin              Disable implicit builtin knowledge of functions
    \\  -ffunction-sections       Places each function in a separate section
    \\  -fno-function-sections    All functions go into same section
    \\  -fdata-sections           Places each data in a separate section
    \\  -fno-data-sections        All data go into same section
    \\  -fformatted-panics        Enable formatted safety panics
    \\  -fno-formatted-panics     Disable formatted safety panics
    \\  -fstructured-cfg          (SPIR-V) force SPIR-V kernels to use structured control flow
    \\  -fno-structured-cfg       (SPIR-V) force SPIR-V kernels to not use structured control flow
    \\  -mexec-model=[value]      (WASI) Execution model
    \\  -municode                 (Windows) Use wmain/wWinMain as entry point
    \\
    \\Per-Module Compile Options:
    \\  -target [name]            <arch><sub>-<os>-<abi> see the targets command
    \\  -O [mode]                 Choose what to optimize for
    \\    Debug                   (default) Optimizations off, safety on
    \\    ReleaseFast             Optimize for performance, safety off
    \\    ReleaseSafe             Optimize for performance, safety on
    \\    ReleaseSmall            Optimize for small binary, safety off
    \\  -ofmt=[fmt]               Override target object format
    \\    elf                     Executable and Linking Format
    \\    c                       C source code
    \\    wasm                    WebAssembly
    \\    coff                    Common Object File Format (Windows)
    \\    macho                   macOS relocatables
    \\    spirv                   Standard, Portable Intermediate Representation V (SPIR-V)
    \\    plan9                   Plan 9 from Bell Labs object format
    \\    hex  (planned feature)  Intel IHEX
    \\    raw  (planned feature)  Dump machine code directly
    \\  -mcpu [cpu]               Specify target CPU and feature set
    \\  -mcmodel=[default|tiny|   Limit range of code and data virtual addresses
    \\            small|kernel|
    \\            medium|large]
    \\  -mred-zone                Force-enable the "red-zone"
    \\  -mno-red-zone             Force-disable the "red-zone"
    \\  -fomit-frame-pointer      Omit the stack frame pointer
    \\  -fno-omit-frame-pointer   Store the stack frame pointer
    \\  -fPIC                     Force-enable Position Independent Code
    \\  -fno-PIC                  Force-disable Position Independent Code
    \\  -fstack-check             Enable stack probing in unsafe builds
    \\  -fno-stack-check          Disable stack probing in safe builds
    \\  -fstack-protector         Enable stack protection in unsafe builds
    \\  -fno-stack-protector      Disable stack protection in safe builds
    \\  -fvalgrind                Include valgrind client requests in release builds
    \\  -fno-valgrind             Omit valgrind client requests in debug builds
    \\  -fsanitize-c              Enable C undefined behavior detection in unsafe builds
    \\  -fno-sanitize-c           Disable C undefined behavior detection in safe builds
    \\  -fsanitize-thread         Enable Thread Sanitizer
    \\  -fno-sanitize-thread      Disable Thread Sanitizer
    \\  -ffuzz                    Enable fuzz testing instrumentation
    \\  -fno-fuzz                 Disable fuzz testing instrumentation
    \\  -funwind-tables           Always produce unwind table entries for all functions
    \\  -fno-unwind-tables        Never produce unwind table entries
    \\  -ferror-tracing           Enable error tracing in ReleaseFast mode
    \\  -fno-error-tracing        Disable error tracing in Debug and ReleaseSafe mode
    \\  -fsingle-threaded         Code assumes there is only one thread
    \\  -fno-single-threaded      Code may not assume there is only one thread
    \\  -fstrip                   Omit debug symbols
    \\  -fno-strip                Keep debug symbols
    \\  -idirafter [dir]          Add directory to AFTER include search path
    \\  -isystem  [dir]           Add directory to SYSTEM include search path
    \\  -I[dir]                   Add directory to include search path
    \\  -D[macro]=[value]         Define C [macro] to [value] (1 if [value] omitted)
    \\  -cflags [flags] --        Set extra flags for the next positional C source files
    \\  -rcflags [flags] --       Set extra flags for the next positional .rc source files
    \\  -rcincludes=[type]        Set the type of includes to use when compiling .rc source files
    \\    any                     (default) Use msvc if available, fall back to gnu
    \\    msvc                    Use msvc include paths (must be present on the system)
    \\    gnu                     Use mingw include paths (distributed with Zig)
    \\    none                    Do not use any autodetected include paths
    \\
    \\Global Link Options:
    \\  -T[script], --script [script]  Use a custom linker script
    \\  --version-script [path]        Provide a version .map file
    \\  --undefined-version            Allow version scripts to refer to undefined symbols
    \\  --no-undefined-version         (default) Disallow version scripts from referring to undefined symbols
    \\  --enable-new-dtags             Use the new behavior for dynamic tags (RUNPATH)
    \\  --disable-new-dtags            Use the old behavior for dynamic tags (RPATH)
    \\  --dynamic-linker [path]        Set the dynamic interpreter path (usually ld.so)
    \\  --sysroot [path]               Set the system root directory (usually /)
    \\  --version [ver]                Dynamic library semver
    \\  -fentry                        Enable entry point with default symbol name
    \\  -fentry=[name]                 Override the entry point symbol name
    \\  -fno-entry                     Do not output any entry point
    \\  --force_undefined [name]       Specify the symbol must be defined for the link to succeed
    \\  -fsoname[=name]                Override the default SONAME value
    \\  -fno-soname                    Disable emitting a SONAME
    \\  -flld                          Force using LLD as the linker
    \\  -fno-lld                       Prevent using LLD as the linker
    \\  -fcompiler-rt                  Always include compiler-rt symbols in output
    \\  -fno-compiler-rt               Prevent including compiler-rt symbols in output
    \\  -rdynamic                      Add all symbols to the dynamic symbol table
    \\  -feach-lib-rpath               Ensure adding rpath for each used dynamic library
    \\  -fno-each-lib-rpath            Prevent adding rpath for each used dynamic library
    \\  -fallow-shlib-undefined        Allows undefined symbols in shared libraries
    \\  -fno-allow-shlib-undefined     Disallows undefined symbols in shared libraries
    \\  --build-id[=style]             At a minor link-time expense, coordinates stripped binaries
    \\      fast, uuid, sha1, md5      with debug symbols via a '.note.gnu.build-id' section
    \\      0x[hexstring]              Maximum 32 bytes
    \\      none                       (default) Disable build-id
    \\  --eh-frame-hdr                 Enable C++ exception handling by passing --eh-frame-hdr to linker
    \\  --emit-relocs                  Enable output of relocation sections for post build tools
    \\  -z [arg]                       Set linker extension flags
    \\    nodelete                     Indicate that the object cannot be deleted from a process
    \\    notext                       Permit read-only relocations in read-only segments
    \\    defs                         Force a fatal error if any undefined symbols remain
    \\    undefs                       Reverse of -z defs
    \\    origin                       Indicate that the object must have its origin processed
    \\    nocopyreloc                  Disable the creation of copy relocations
    \\    now                          (default) Force all relocations to be processed on load
    \\    lazy                         Don't force all relocations to be processed on load
    \\    relro                        (default) Force all relocations to be read-only after processing
    \\    norelro                      Don't force all relocations to be read-only after processing
    \\    common-page-size=[bytes]     Set the common page size for ELF binaries
    \\    max-page-size=[bytes]        Set the max page size for ELF binaries
    \\  -dynamic                       Force output to be dynamically linked
    \\  -static                        Force output to be statically linked
    \\  -Bsymbolic                     Bind global references locally
    \\  --compress-debug-sections=[e]  Debug section compression settings
    \\      none                       No compression
    \\      zlib                       Compression with deflate/inflate
    \\      zstd                       Compression with zstandard
    \\  --gc-sections                  Force removal of functions and data that are unreachable by the entry point or exported symbols
    \\  --no-gc-sections               Don't force removal of unreachable functions and data
    \\  --sort-section=[value]         Sort wildcard section patterns by 'name' or 'alignment'
    \\  --subsystem [subsystem]        (Windows) /SUBSYSTEM:<subsystem> to the linker
    \\  --stack [size]                 Override default stack size
    \\  --image-base [addr]            Set base address for executable image
    \\  -install_name=[value]          (Darwin) add dylib's install name
    \\  --entitlements [path]          (Darwin) add path to entitlements file for embedding in code signature
    \\  -pagezero_size [value]         (Darwin) size of the __PAGEZERO segment in hexadecimal notation
    \\  -headerpad [value]             (Darwin) set minimum space for future expansion of the load commands in hexadecimal notation
    \\  -headerpad_max_install_names   (Darwin) set enough space as if all paths were MAXPATHLEN
    \\  -dead_strip                    (Darwin) remove functions and data that are unreachable by the entry point or exported symbols
    \\  -dead_strip_dylibs             (Darwin) remove dylibs that are unreachable by the entry point or exported symbols
    \\  -ObjC                          (Darwin) force load all members of static archives that implement an Objective-C class or category
    \\  --import-memory                (WebAssembly) import memory from the environment
    \\  --export-memory                (WebAssembly) export memory to the host (Default unless --import-memory used)
    \\  --import-symbols               (WebAssembly) import missing symbols from the host environment
    \\  --import-table                 (WebAssembly) import function table from the host environment
    \\  --export-table                 (WebAssembly) export function table to the host environment
    \\  --initial-memory=[bytes]       (WebAssembly) initial size of the linear memory
    \\  --max-memory=[bytes]           (WebAssembly) maximum size of the linear memory
    \\  --shared-memory                (WebAssembly) use shared linear memory
    \\  --global-base=[addr]           (WebAssembly) where to start to place global data
    \\
    \\Per-Module Link Options:
    \\  -l[lib], --library [lib]       Link against system library (only if actually used)
    \\  -needed-l[lib],                Link against system library (even if unused)
    \\    --needed-library [lib]
    \\  -weak-l[lib]                   link against system library marking it and all
    \\    -weak_library [lib]          referenced symbols as weak
    \\  -L[d], --library-directory [d] Add a directory to the library search path
    \\  -search_paths_first            For each library search path, check for dynamic
    \\                                 lib then static lib before proceeding to next path.
    \\  -search_paths_first_static     For each library search path, check for static
    \\                                 lib then dynamic lib before proceeding to next path.
    \\  -search_dylibs_first           Search for dynamic libs in all library search
    \\                                 paths, then static libs.
    \\  -search_static_first           Search for static libs in all library search
    \\                                 paths, then dynamic libs.
    \\  -search_dylibs_only            Only search for dynamic libs.
    \\  -search_static_only            Only search for static libs.
    \\  -rpath [path]                  Add directory to the runtime library search path
    \\  -framework [name]              (Darwin) link against framework
    \\  -needed_framework [name]       (Darwin) link against framework (even if unused)
    \\  -needed_library [lib]          (Darwin) link against system library (even if unused)
    \\  -weak_framework [name]         (Darwin) link against framework and mark it and all referenced symbols as weak
    \\  -F[dir]                        (Darwin) add search path for frameworks
    \\  --export=[value]               (WebAssembly) Force a symbol to be exported
    \\
    \\Test Options:
    \\  --test-filter [text]           Skip tests that do not match any filter
    \\  --test-name-prefix [text]      Add prefix to all tests
    \\  --test-cmd [arg]               Specify test execution command one arg at a time
    \\  --test-cmd-bin                 Appends test binary path to test cmd args
    \\  --test-evented-io              Runs the test in evented I/O mode
    \\  --test-no-exec                 Compiles test binary without running it
    \\  --test-runner [path]           Specify a custom test runner
    \\
    \\Debug Options (Zig Compiler Development):
    \\  -fopt-bisect-limit=[limit]   Only run [limit] first LLVM optimization passes
    \\  -ftime-report                Print timing diagnostics
    \\  -fstack-report               Print stack size diagnostics
    \\  --verbose-link               Display linker invocations
    \\  --verbose-cc                 Display C compiler invocations
    \\  --verbose-air                Enable compiler debug output for Zig AIR
    \\  --verbose-intern-pool        Enable compiler debug output for InternPool
    \\  --verbose-generic-instances  Enable compiler debug output for generic instance generation
    \\  --verbose-llvm-ir[=path]     Enable compiler debug output for unoptimized LLVM IR
    \\  --verbose-llvm-bc=[path]     Enable compiler debug output for unoptimized LLVM BC
    \\  --verbose-cimport            Enable compiler debug output for C imports
    \\  --verbose-llvm-cpu-features  Enable compiler debug output for LLVM CPU features
    \\  --debug-log [scope]          Enable printing debug/info log messages for scope
    \\  --debug-compile-errors       Crash with helpful diagnostics at the first compile error
    \\  --debug-link-snapshot        Enable dumping of the linker's state in JSON format
    \\  --debug-rt                   Debug compiler runtime libraries
    \\
;

const SOName = union(enum) {
    no,
    yes_default_value,
    yes: []const u8,
};

const EmitBin = union(enum) {
    no,
    yes_default_path,
    yes: []const u8,
    yes_a_out,
};

const Emit = union(enum) {
    no,
    yes_default_path,
    yes: []const u8,

    const Resolved = struct {
        data: ?Compilation.EmitLoc,
        dir: ?fs.Dir,

        fn deinit(self: *Resolved) void {
            if (self.dir) |*dir| {
                dir.close();
            }
        }
    };

    fn resolve(emit: Emit, default_basename: []const u8, output_to_cache: bool) !Resolved {
        var resolved: Resolved = .{ .data = null, .dir = null };
        errdefer resolved.deinit();

        switch (emit) {
            .no => {},
            .yes_default_path => {
                resolved.data = Compilation.EmitLoc{
                    .directory = if (output_to_cache) null else .{
                        .path = null,
                        .handle = fs.cwd(),
                    },
                    .basename = default_basename,
                };
            },
            .yes => |full_path| {
                const basename = fs.path.basename(full_path);
                if (fs.path.dirname(full_path)) |dirname| {
                    const handle = try fs.cwd().openDir(dirname, .{});
                    resolved = .{
                        .dir = handle,
                        .data = Compilation.EmitLoc{
                            .basename = basename,
                            .directory = .{
                                .path = dirname,
                                .handle = handle,
                            },
                        },
                    };
                } else {
                    resolved.data = Compilation.EmitLoc{
                        .basename = basename,
                        .directory = .{ .path = null, .handle = fs.cwd() },
                    };
                }
            },
        }
        return resolved;
    }
};

const ArgMode = union(enum) {
    build: std.builtin.OutputMode,
    cc,
    cpp,
    translate_c,
    zig_test,
    run,
};

const Listen = union(enum) {
    none,
    stdio: if (dev.env.supports(.stdio_listen)) void else noreturn,
    ip4: if (dev.env.supports(.network_listen)) std.net.Ip4Address else noreturn,
};

const ArgsIterator = struct {
    resp_file: ?ArgIteratorResponseFile = null,
    args: []const []const u8,
    i: usize = 0,
    fn next(it: *@This()) ?[]const u8 {
        if (it.i >= it.args.len) {
            if (it.resp_file) |*resp| return resp.next();
            return null;
        }
        defer it.i += 1;
        return it.args[it.i];
    }
    fn nextOrFatal(it: *@This()) []const u8 {
        if (it.i >= it.args.len) {
            if (it.resp_file) |*resp| if (resp.next()) |ret| return ret;
            fatal("expected parameter after {s}", .{it.args[it.i - 1]});
        }
        defer it.i += 1;
        return it.args[it.i];
    }
};

/// In contrast to `link.SystemLib`, this stores arguments that may need to be
/// resolved into static libraries so that we can pass only dynamic libraries
/// as system libs to `Compilation`.
const SystemLib = struct {
    needed: bool,
    weak: bool,

    preferred_mode: std.builtin.LinkMode,
    search_strategy: SearchStrategy,

    const SearchStrategy = enum { paths_first, mode_first, no_fallback };

    fn fallbackMode(this: SystemLib) std.builtin.LinkMode {
        assert(this.search_strategy != .no_fallback);
        return switch (this.preferred_mode) {
            .dynamic => .static,
            .static => .dynamic,
        };
    }
};

/// Similar to `link.Framework` except it doesn't store yet unresolved
/// path to the framework.
const Framework = struct {
    needed: bool = false,
    weak: bool = false,
};

const CliModule = struct {
    paths: Package.Module.CreateOptions.Paths,
    cc_argv: []const []const u8,
    inherited: Package.Module.CreateOptions.Inherited,
    target_arch_os_abi: ?[]const u8,
    target_mcpu: ?[]const u8,

    deps: []const Dep,
    resolved: ?*Package.Module,

    c_source_files_start: usize,
    c_source_files_end: usize,
    rc_source_files_start: usize,
    rc_source_files_end: usize,

    const Dep = struct {
        key: []const u8,
        value: []const u8,
    };
};

// fn buildOutputType

const CreateModule = struct {
    global_cache_directory: Cache.Directory,
    modules: std.StringArrayHashMapUnmanaged(CliModule),
    opts: Compilation.Config.Options,
    dynamic_linker: ?[]const u8,
    object_format: ?[]const u8,
    /// undefined until createModule() for the root module is called.
    resolved_options: Compilation.Config,

    /// This one is used while collecting CLI options. The set of libs is used
    /// directly after computing the target and used to compute link_libc,
    /// link_libcpp, and then the libraries are filtered into
    /// `external_system_libs` and `resolved_system_libs`.
    system_libs: std.StringArrayHashMapUnmanaged(SystemLib),
    resolved_system_libs: std.MultiArrayList(struct {
        name: []const u8,
        lib: Compilation.SystemLib,
    }),
    wasi_emulated_libs: std.ArrayListUnmanaged(wasi_libc.CRTFile),

    c_source_files: std.ArrayListUnmanaged(Compilation.CSourceFile),
    rc_source_files: std.ArrayListUnmanaged(Compilation.RcSourceFile),

    /// e.g. -m3dnow or -mno-outline-atomics. They correspond to std.Target llvm cpu feature names.
    /// This array is populated by zig cc frontend and then has to be converted to zig-style
    /// CPU features.
    llvm_m_args: std.ArrayListUnmanaged([]const u8),
    sysroot: ?[]const u8,
    lib_dirs: std.ArrayListUnmanaged([]const u8),
    lib_dir_args: std.ArrayListUnmanaged([]const u8),
    libc_installation: ?LibCInstallation,
    want_native_include_dirs: bool,
    frameworks: std.StringArrayHashMapUnmanaged(Framework),
    native_system_include_paths: []const []const u8,
    framework_dirs: std.ArrayListUnmanaged([]const u8),
    rpath_list: std.ArrayListUnmanaged([]const u8),
    each_lib_rpath: ?bool,
    libc_paths_file: ?[]const u8,
    link_objects: std.ArrayListUnmanaged(Compilation.LinkObject),
};

fn createModule(
    gpa: Allocator,
    arena: Allocator,
    create_module: *CreateModule,
    index: usize,
    parent: ?*Package.Module,
    zig_lib_directory: Cache.Directory,
    builtin_modules: *std.StringHashMapUnmanaged(*Package.Module),
) Allocator.Error!*Package.Module {
    const cli_mod = &create_module.modules.values()[index];
    if (cli_mod.resolved) |m| return m;

    const name = create_module.modules.keys()[index];

    cli_mod.inherited.resolved_target = t: {
        // If the target is not overridden, use the parent's target. Of course,
        // if this is the root module then we need to proceed to resolve the
        // target.
        if (cli_mod.target_arch_os_abi == null and cli_mod.target_mcpu == null) {
            if (parent) |p| break :t p.resolved_target;
        }

        var target_parse_options: std.Target.Query.ParseOptions = .{
            .arch_os_abi = cli_mod.target_arch_os_abi orelse "native",
            .cpu_features = cli_mod.target_mcpu,
            .dynamic_linker = create_module.dynamic_linker,
            .object_format = create_module.object_format,
        };

        // Before passing the mcpu string in for parsing, we convert any -m flags that were
        // passed in via zig cc to zig-style.
        if (create_module.llvm_m_args.items.len != 0) {
            // If this returns null, we let it fall through to the case below which will
            // run the full parse function and do proper error handling.
            if (std.Target.Query.parseCpuArch(target_parse_options)) |cpu_arch| {
                var llvm_to_zig_name = std.StringHashMap([]const u8).init(gpa);
                defer llvm_to_zig_name.deinit();

                for (cpu_arch.allFeaturesList()) |feature| {
                    const llvm_name = feature.llvm_name orelse continue;
                    try llvm_to_zig_name.put(llvm_name, feature.name);
                }

                var mcpu_buffer = std.ArrayList(u8).init(gpa);
                defer mcpu_buffer.deinit();

                try mcpu_buffer.appendSlice(cli_mod.target_mcpu orelse "baseline");

                for (create_module.llvm_m_args.items) |llvm_m_arg| {
                    if (mem.startsWith(u8, llvm_m_arg, "mno-")) {
                        const llvm_name = llvm_m_arg["mno-".len..];
                        const zig_name = llvm_to_zig_name.get(llvm_name) orelse {
                            fatal("target architecture {s} has no LLVM CPU feature named '{s}'", .{
                                @tagName(cpu_arch), llvm_name,
                            });
                        };
                        try mcpu_buffer.append('-');
                        try mcpu_buffer.appendSlice(zig_name);
                    } else if (mem.startsWith(u8, llvm_m_arg, "m")) {
                        const llvm_name = llvm_m_arg["m".len..];
                        const zig_name = llvm_to_zig_name.get(llvm_name) orelse {
                            fatal("target architecture {s} has no LLVM CPU feature named '{s}'", .{
                                @tagName(cpu_arch), llvm_name,
                            });
                        };
                        try mcpu_buffer.append('+');
                        try mcpu_buffer.appendSlice(zig_name);
                    } else {
                        unreachable;
                    }
                }

                const adjusted_target_mcpu = try arena.dupe(u8, mcpu_buffer.items);
                std.log.debug("adjusted target_mcpu: {s}", .{adjusted_target_mcpu});
                target_parse_options.cpu_features = adjusted_target_mcpu;
            }
        }

        const target_query = std.zig.parseTargetQueryOrReportFatalError(arena, target_parse_options);
        const target = std.zig.resolveTargetQueryOrFatal(target_query);
        break :t .{
            .result = target,
            .is_native_os = target_query.isNativeOs(),
            .is_native_abi = target_query.isNativeAbi(),
        };
    };

    if (parent == null) {
        // This block is for initializing the fields of
        // `Compilation.Config.Options` that require knowledge of the
        // target (which was just now resolved for the root module above).
        const resolved_target = cli_mod.inherited.resolved_target.?;
        create_module.opts.resolved_target = resolved_target;
        create_module.opts.root_optimize_mode = cli_mod.inherited.optimize_mode;
        create_module.opts.root_strip = cli_mod.inherited.strip;
        create_module.opts.root_error_tracing = cli_mod.inherited.error_tracing;
        const target = resolved_target.result;

        // First, remove libc, libc++, and compiler_rt libraries from the system libraries list.
        // We need to know whether the set of system libraries contains anything besides these
        // to decide whether to trigger native path detection logic.
        var external_system_libs: std.MultiArrayList(struct {
            name: []const u8,
            info: SystemLib,
        }) = .{};
        for (create_module.system_libs.keys(), create_module.system_libs.values()) |lib_name, info| {
            if (target.is_libc_lib_name(lib_name)) {
                create_module.opts.link_libc = true;
                continue;
            }
            if (target.is_libcpp_lib_name(lib_name)) {
                create_module.opts.link_libcpp = true;
                continue;
            }
            switch (target_util.classifyCompilerRtLibName(target, lib_name)) {
                .none => {},
                .only_libunwind, .both => {
                    create_module.opts.link_libunwind = true;
                    continue;
                },
                .only_compiler_rt => {
                    warn("ignoring superfluous library '{s}': this dependency is fulfilled instead by compiler-rt which zig unconditionally provides", .{lib_name});
                    continue;
                },
            }

            if (target.isMinGW()) {
                const exists = mingw.libExists(arena, target, zig_lib_directory, lib_name) catch |err| {
                    fatal("failed to check zig installation for DLL import libs: {s}", .{
                        @errorName(err),
                    });
                };
                if (exists) {
                    try create_module.resolved_system_libs.append(arena, .{
                        .name = lib_name,
                        .lib = .{
                            .needed = true,
                            .weak = false,
                            .path = null,
                        },
                    });
                    continue;
                }
            }

            if (fs.path.isAbsolute(lib_name)) {
                fatal("cannot use absolute path as a system library: {s}", .{lib_name});
            }

            if (target.os.tag == .wasi) {
                if (wasi_libc.getEmulatedLibCRTFile(lib_name)) |crt_file| {
                    try create_module.wasi_emulated_libs.append(arena, crt_file);
                    continue;
                }
            }

            try external_system_libs.append(arena, .{
                .name = lib_name,
                .info = info,
            });
        }
        // After this point, external_system_libs is used instead of system_libs.
        if (external_system_libs.len != 0)
            create_module.want_native_include_dirs = true;

        // Resolve the library path arguments with respect to sysroot.
        if (create_module.sysroot) |root| {
            try create_module.lib_dirs.ensureUnusedCapacity(arena, create_module.lib_dir_args.items.len * 2);
            for (create_module.lib_dir_args.items) |dir| {
                if (fs.path.isAbsolute(dir)) {
                    const stripped_dir = dir[fs.path.diskDesignator(dir).len..];
                    const full_path = try fs.path.join(arena, &[_][]const u8{ root, stripped_dir });
                    create_module.lib_dirs.appendAssumeCapacity(full_path);
                }
                create_module.lib_dirs.appendAssumeCapacity(dir);
            }
        } else {
            create_module.lib_dirs = create_module.lib_dir_args;
        }
        create_module.lib_dir_args = undefined; // From here we use lib_dirs instead.

        if (resolved_target.is_native_os and target.isDarwin()) {
            // If we want to link against frameworks, we need system headers.
            if (create_module.frameworks.count() > 0)
                create_module.want_native_include_dirs = true;
        }

        if (create_module.each_lib_rpath orelse resolved_target.is_native_os) {
            try create_module.rpath_list.appendSlice(arena, create_module.lib_dirs.items);
        }

        // Trigger native system library path detection if necessary.
        if (create_module.sysroot == null and
            resolved_target.is_native_os and resolved_target.is_native_abi and
            create_module.want_native_include_dirs)
        {
            var paths = std.zig.system.NativePaths.detect(arena, target) catch |err| {
                fatal("unable to detect native system paths: {s}", .{@errorName(err)});
            };
            for (paths.warnings.items) |warning| {
                warn("{s}", .{warning});
            }

            create_module.native_system_include_paths = try paths.include_dirs.toOwnedSlice(arena);

            try create_module.framework_dirs.appendSlice(arena, paths.framework_dirs.items);
            try create_module.lib_dirs.appendSlice(arena, paths.lib_dirs.items);
            try create_module.rpath_list.appendSlice(arena, paths.rpaths.items);
        }

        if (create_module.libc_paths_file) |paths_file| {
            create_module.libc_installation = LibCInstallation.parse(arena, paths_file, target) catch |err| {
                fatal("unable to parse libc paths file at path {s}: {s}", .{
                    paths_file, @errorName(err),
                });
            };
        }

        if (builtin.target.os.tag == .windows and target.abi == .msvc and
            external_system_libs.len != 0)
        {
            if (create_module.libc_installation == null) {
                create_module.libc_installation = LibCInstallation.findNative(.{
                    .allocator = arena,
                    .verbose = true,
                    .target = target,
                }) catch |err| {
                    fatal("unable to find native libc installation: {s}", .{@errorName(err)});
                };

                try create_module.lib_dirs.appendSlice(arena, &.{
                    create_module.libc_installation.?.msvc_lib_dir.?,
                    create_module.libc_installation.?.kernel32_lib_dir.?,
                });
            }
        }

        // If any libs in this list are statically provided, we omit them from the
        // resolved list and populate the link_objects array instead.
        {
            var test_path = std.ArrayList(u8).init(gpa);
            defer test_path.deinit();

            var checked_paths = std.ArrayList(u8).init(gpa);
            defer checked_paths.deinit();

            var failed_libs = std.ArrayList(struct {
                name: []const u8,
                strategy: SystemLib.SearchStrategy,
                checked_paths: []const u8,
                preferred_mode: std.builtin.LinkMode,
            }).init(arena);

            syslib: for (external_system_libs.items(.name), external_system_libs.items(.info)) |lib_name, info| {
                // Checked in the first pass above while looking for libc libraries.
                assert(!fs.path.isAbsolute(lib_name));

                checked_paths.clearRetainingCapacity();

                switch (info.search_strategy) {
                    .mode_first, .no_fallback => {
                        // check for preferred mode
                        for (create_module.lib_dirs.items) |lib_dir_path| {
                            if (try accessLibPath(
                                &test_path,
                                &checked_paths,
                                lib_dir_path,
                                lib_name,
                                target,
                                info.preferred_mode,
                            )) {
                                const path = try arena.dupe(u8, test_path.items);
                                switch (info.preferred_mode) {
                                    .static => try create_module.link_objects.append(arena, .{ .path = path }),
                                    .dynamic => try create_module.resolved_system_libs.append(arena, .{
                                        .name = lib_name,
                                        .lib = .{
                                            .needed = info.needed,
                                            .weak = info.weak,
                                            .path = path,
                                        },
                                    }),
                                }
                                continue :syslib;
                            }
                        }
                        // check for fallback mode
                        if (info.search_strategy == .no_fallback) {
                            try failed_libs.append(.{
                                .name = lib_name,
                                .strategy = info.search_strategy,
                                .checked_paths = try arena.dupe(u8, checked_paths.items),
                                .preferred_mode = info.preferred_mode,
                            });
                            continue :syslib;
                        }
                        for (create_module.lib_dirs.items) |lib_dir_path| {
                            if (try accessLibPath(
                                &test_path,
                                &checked_paths,
                                lib_dir_path,
                                lib_name,
                                target,
                                info.fallbackMode(),
                            )) {
                                const path = try arena.dupe(u8, test_path.items);
                                switch (info.fallbackMode()) {
                                    .static => try create_module.link_objects.append(arena, .{ .path = path }),
                                    .dynamic => try create_module.resolved_system_libs.append(arena, .{
                                        .name = lib_name,
                                        .lib = .{
                                            .needed = info.needed,
                                            .weak = info.weak,
                                            .path = path,
                                        },
                                    }),
                                }
                                continue :syslib;
                            }
                        }
                        try failed_libs.append(.{
                            .name = lib_name,
                            .strategy = info.search_strategy,
                            .checked_paths = try arena.dupe(u8, checked_paths.items),
                            .preferred_mode = info.preferred_mode,
                        });
                        continue :syslib;
                    },
                    .paths_first => {
                        for (create_module.lib_dirs.items) |lib_dir_path| {
                            // check for preferred mode
                            if (try accessLibPath(
                                &test_path,
                                &checked_paths,
                                lib_dir_path,
                                lib_name,
                                target,
                                info.preferred_mode,
                            )) {
                                const path = try arena.dupe(u8, test_path.items);
                                switch (info.preferred_mode) {
                                    .static => try create_module.link_objects.append(arena, .{ .path = path }),
                                    .dynamic => try create_module.resolved_system_libs.append(arena, .{
                                        .name = lib_name,
                                        .lib = .{
                                            .needed = info.needed,
                                            .weak = info.weak,
                                            .path = path,
                                        },
                                    }),
                                }
                                continue :syslib;
                            }

                            // check for fallback mode
                            if (try accessLibPath(
                                &test_path,
                                &checked_paths,
                                lib_dir_path,
                                lib_name,
                                target,
                                info.fallbackMode(),
                            )) {
                                const path = try arena.dupe(u8, test_path.items);
                                switch (info.fallbackMode()) {
                                    .static => try create_module.link_objects.append(arena, .{ .path = path }),
                                    .dynamic => try create_module.resolved_system_libs.append(arena, .{
                                        .name = lib_name,
                                        .lib = .{
                                            .needed = info.needed,
                                            .weak = info.weak,
                                            .path = path,
                                        },
                                    }),
                                }
                                continue :syslib;
                            }
                        }
                        try failed_libs.append(.{
                            .name = lib_name,
                            .strategy = info.search_strategy,
                            .checked_paths = try arena.dupe(u8, checked_paths.items),
                            .preferred_mode = info.preferred_mode,
                        });
                        continue :syslib;
                    },
                }
                @compileError("unreachable");
            }

            if (failed_libs.items.len > 0) {
                for (failed_libs.items) |f| {
                    const searched_paths = if (f.checked_paths.len == 0) " none" else f.checked_paths;
                    std.log.err("unable to find {s} system library '{s}' using strategy '{s}'. searched paths:{s}", .{
                        @tagName(f.preferred_mode), f.name, @tagName(f.strategy), searched_paths,
                    });
                }
                process.exit(1);
            }
        }
        // After this point, create_module.resolved_system_libs is used instead of
        // create_module.external_system_libs.

        if (create_module.resolved_system_libs.len != 0)
            create_module.opts.any_dyn_libs = true;

        create_module.resolved_options = Compilation.Config.resolve(create_module.opts) catch |err| switch (err) {
            error.WasiExecModelRequiresWasi => fatal("only WASI OS targets support execution model", .{}),
            error.SharedMemoryIsWasmOnly => fatal("only WebAssembly CPU targets support shared memory", .{}),
            error.ObjectFilesCannotShareMemory => fatal("object files cannot share memory", .{}),
            error.SharedMemoryRequiresAtomicsAndBulkMemory => fatal("shared memory requires atomics and bulk_memory CPU features", .{}),
            error.ThreadsRequireSharedMemory => fatal("threads require shared memory", .{}),
            error.EmittingLlvmModuleRequiresLlvmBackend => fatal("emitting an LLVM module requires using the LLVM backend", .{}),
            error.LlvmLacksTargetSupport => fatal("LLVM lacks support for the specified target", .{}),
            error.ZigLacksTargetSupport => fatal("compiler backend unavailable for the specified target", .{}),
            error.EmittingBinaryRequiresLlvmLibrary => fatal("producing machine code via LLVM requires using the LLVM library", .{}),
            error.LldIncompatibleObjectFormat => fatal("using LLD to link {s} files is unsupported", .{@tagName(target.ofmt)}),
            error.LldCannotIncrementallyLink => fatal("self-hosted backends do not support linking with LLD", .{}),
            error.LtoRequiresLld => fatal("LTO requires using LLD", .{}),
            error.SanitizeThreadRequiresLibCpp => fatal("thread sanitization is (for now) implemented in C++, so it requires linking libc++", .{}),
            error.LibCppRequiresLibUnwind => fatal("libc++ requires linking libunwind", .{}),
            error.OsRequiresLibC => fatal("the target OS requires using libc as the stable syscall interface", .{}),
            error.LibCppRequiresLibC => fatal("libc++ requires linking libc", .{}),
            error.LibUnwindRequiresLibC => fatal("libunwind requires linking libc", .{}),
            error.TargetCannotDynamicLink => fatal("dynamic linking unavailable on the specified target", .{}),
            error.LibCRequiresDynamicLinking => fatal("libc of the specified target requires dynamic linking", .{}),
            error.SharedLibrariesRequireDynamicLinking => fatal("using shared libraries requires dynamic linking", .{}),
            error.ExportMemoryAndDynamicIncompatible => fatal("exporting memory is incompatible with dynamic linking", .{}),
            error.DynamicLibraryPrecludesPie => fatal("dynamic libraries cannot be position independent executables", .{}),
            error.TargetRequiresPie => fatal("the specified target requires position independent executables", .{}),
            error.SanitizeThreadRequiresPie => fatal("thread sanitization requires position independent executables", .{}),
            error.BackendLacksErrorTracing => fatal("the selected backend has not yet implemented error return tracing", .{}),
            error.LlvmLibraryUnavailable => fatal("zig was compiled without LLVM libraries", .{}),
            error.LldUnavailable => fatal("zig was compiled without LLD libraries", .{}),
            error.ClangUnavailable => fatal("zig was compiled without Clang libraries", .{}),
            error.DllExportFnsRequiresWindows => fatal("only Windows OS targets support DLLs", .{}),
        };
    }

    const mod = Package.Module.create(arena, .{
        .global_cache_directory = create_module.global_cache_directory,
        .paths = cli_mod.paths,
        .fully_qualified_name = name,

        .cc_argv = cli_mod.cc_argv,
        .inherited = cli_mod.inherited,
        .global = create_module.resolved_options,
        .parent = parent,
        .builtin_mod = null,
        .builtin_modules = builtin_modules,
    }) catch |err| switch (err) {
        error.ValgrindUnsupportedOnTarget => fatal("unable to create module '{s}': valgrind does not support the selected target CPU architecture", .{name}),
        error.TargetRequiresSingleThreaded => fatal("unable to create module '{s}': the selected target does not support multithreading", .{name}),
        error.BackendRequiresSingleThreaded => fatal("unable to create module '{s}': the selected machine code backend is limited to single-threaded applications", .{name}),
        error.TargetRequiresPic => fatal("unable to create module '{s}': the selected target requires position independent code", .{name}),
        error.PieRequiresPic => fatal("unable to create module '{s}': making a Position Independent Executable requires enabling Position Independent Code", .{name}),
        error.DynamicLinkingRequiresPic => fatal("unable to create module '{s}': dynamic linking requires enabling Position Independent Code", .{name}),
        error.TargetHasNoRedZone => fatal("unable to create module '{s}': the selected target does not have a red zone", .{name}),
        error.StackCheckUnsupportedByTarget => fatal("unable to create module '{s}': the selected target does not support stack checking", .{name}),
        error.StackProtectorUnsupportedByTarget => fatal("unable to create module '{s}': the selected target does not support stack protection", .{name}),
        error.StackProtectorUnavailableWithoutLibC => fatal("unable to create module '{s}': enabling stack protection requires libc", .{name}),
        error.OutOfMemory => return error.OutOfMemory,
    };
    cli_mod.resolved = mod;

    for (create_module.c_source_files.items[cli_mod.c_source_files_start..cli_mod.c_source_files_end]) |*item| item.owner = mod;

    for (create_module.rc_source_files.items[cli_mod.rc_source_files_start..cli_mod.rc_source_files_end]) |*item| item.owner = mod;

    for (cli_mod.deps) |dep| {
        const dep_index = create_module.modules.getIndex(dep.value) orelse
            fatal("module '{s}' depends on non-existent module '{s}'", .{ name, dep.key });
        const dep_mod = try createModule(gpa, arena, create_module, dep_index, mod, zig_lib_directory, builtin_modules);
        try mod.deps.put(arena, dep.key, dep_mod);
    }

    return mod;
}

fn saveState(comp: *Compilation, incremental: bool) void {
    if (incremental) {
        comp.saveState() catch |err| {
            warn("unable to save incremental compilation state: {s}", .{@errorName(err)});
        };
    }
}

fn serve(
    comp: *Compilation,
    in: fs.File,
    out: fs.File,
    test_exec_args: []const ?[]const u8,
    self_exe_path: ?[]const u8,
    arg_mode: ArgMode,
    all_args: []const []const u8,
    runtime_args_start: ?usize,
) !void {
    const gpa = comp.gpa;

    var server = try Server.init(.{
        .gpa = gpa,
        .in = in,
        .out = out,
        .zig_version = build_options.version,
    });
    defer server.deinit();

    var child_pid: ?std.process.Child.Id = null;

    const main_progress_node = std.Progress.start(.{});
    const file_system_inputs = comp.file_system_inputs.?;

    while (true) {
        const hdr = try server.receiveMessage();

        switch (hdr.tag) {
            .exit => return cleanExit(),
            .update => {
                tracy.frameMark();
                file_system_inputs.clearRetainingCapacity();

                if (arg_mode == .translate_c) {
                    var arena_instance = std.heap.ArenaAllocator.init(gpa);
                    defer arena_instance.deinit();
                    const arena = arena_instance.allocator();
                    var output: Compilation.CImportResult = undefined;
                    try cmdTranslateC(comp, arena, &output, file_system_inputs, main_progress_node);
                    defer output.deinit(gpa);
                    try server.serveStringMessage(.file_system_inputs, file_system_inputs.items);
                    if (output.errors.errorMessageCount() != 0) {
                        try server.serveErrorBundle(output.errors);
                    } else {
                        try server.serveEmitDigest(&output.digest, .{
                            .flags = .{ .cache_hit = output.cache_hit },
                        });
                    }
                    continue;
                }

                if (comp.config.output_mode == .Exe) {
                    try comp.makeBinFileWritable();
                }

                try comp.update(main_progress_node);

                try comp.makeBinFileExecutable();
                try serveUpdateResults(&server, comp);
            },
            .run => {
                if (child_pid != null) {
                    @panic("TODO block until the child exits");
                }
                @panic("TODO call runOrTest");
                //try runOrTest(
                //    comp,
                //    gpa,
                //    arena,
                //    test_exec_args,
                //    self_exe_path.?,
                //    arg_mode,
                //    target,
                //    true,
                //    &comp_destroyed,
                //    all_args,
                //    runtime_args_start,
                //    link_libc,
                //);
            },
            .hot_update => {
                tracy.frameMark();
                file_system_inputs.clearRetainingCapacity();
                if (child_pid) |pid| {
                    try comp.hotCodeSwap(main_progress_node, pid);
                    try serveUpdateResults(&server, comp);
                } else {
                    if (comp.config.output_mode == .Exe) {
                        try comp.makeBinFileWritable();
                    }
                    try comp.update(main_progress_node);
                    try comp.makeBinFileExecutable();
                    try serveUpdateResults(&server, comp);

                    child_pid = try runOrTestHotSwap(
                        comp,
                        gpa,
                        test_exec_args,
                        self_exe_path.?,
                        arg_mode,
                        all_args,
                        runtime_args_start,
                    );
                }
            },
            else => {
                fatal("unrecognized message from client: 0x{x}", .{@intFromEnum(hdr.tag)});
            },
        }
    }
}

fn serveUpdateResults(s: *Server, comp: *Compilation) !void {
    const gpa = comp.gpa;

    var error_bundle = try comp.getAllErrorsAlloc();
    defer error_bundle.deinit(gpa);

    if (comp.file_system_inputs) |file_system_inputs| {
        if (file_system_inputs.items.len == 0) {
            assert(error_bundle.errorMessageCount() > 0);
        } else {
            try s.serveStringMessage(.file_system_inputs, file_system_inputs.items);
        }
    }

    if (error_bundle.errorMessageCount() > 0) {
        try s.serveErrorBundle(error_bundle);
        return;
    }

    if (comp.digest) |digest| {
        try s.serveEmitDigest(&digest, .{
            .flags = .{ .cache_hit = comp.last_update_was_cache_hit },
        });
    }

    // Serve empty error bundle to indicate the update is done.
    try s.serveErrorBundle(std.zig.ErrorBundle.empty);
}

fn runOrTest(
    comp: *Compilation,
    gpa: Allocator,
    arena: Allocator,
    test_exec_args: []const ?[]const u8,
    self_exe_path: []const u8,
    arg_mode: ArgMode,
    target: *const std.Target,
    comp_destroyed: *bool,
    all_args: []const []const u8,
    runtime_args_start: ?usize,
    link_libc: bool,
) !void {
    const lf = comp.bin_file orelse return;
    // A naive `directory.join` here will indeed get the correct path to the binary,
    // however, in the case of cwd, we actually want `./foo` so that the path can be executed.
    const exe_path = try fs.path.join(arena, &[_][]const u8{
        lf.emit.root_dir.path orelse ".", lf.emit.sub_path,
    });

    var argv = std.ArrayList([]const u8).init(gpa);
    defer argv.deinit();

    if (test_exec_args.len == 0) {
        try argv.append(exe_path);
        if (arg_mode == .zig_test) {
            try argv.append(
                try std.fmt.allocPrint(arena, "--seed=0x{x}", .{std.crypto.random.int(u32)}),
            );
        }
    } else {
        for (test_exec_args) |arg| {
            try argv.append(arg orelse exe_path);
        }
    }
    if (runtime_args_start) |i| {
        try argv.appendSlice(all_args[i..]);
    }
    var env_map = try process.getEnvMap(arena);
    try env_map.put("ZIG_EXE", self_exe_path);

    // We do not execve for tests because if the test fails we want to print
    // the error message and invocation below.
    if (process.can_execv and arg_mode == .run) {
        // execv releases the locks; no need to destroy the Compilation here.
        std.debug.lockStdErr();
        const err = process.execve(gpa, argv.items, &env_map);
        std.debug.unlockStdErr();
        try warnAboutForeignBinaries(arena, arg_mode, target, link_libc);
        const cmd = try std.mem.join(arena, " ", argv.items);
        fatal("the following command failed to execve with '{s}':\n{s}", .{ @errorName(err), cmd });
    } else if (process.can_spawn) {
        var child = std.process.Child.init(argv.items, gpa);
        child.env_map = &env_map;
        child.stdin_behavior = .Inherit;
        child.stdout_behavior = .Inherit;
        child.stderr_behavior = .Inherit;

        // Here we release all the locks associated with the Compilation so
        // that whatever this child process wants to do won't deadlock.
        comp.destroy();
        comp_destroyed.* = true;

        const term_result = t: {
            std.debug.lockStdErr();
            defer std.debug.unlockStdErr();
            break :t child.spawnAndWait();
        };
        const term = term_result catch |err| {
            try warnAboutForeignBinaries(arena, arg_mode, target, link_libc);
            const cmd = try std.mem.join(arena, " ", argv.items);
            fatal("the following command failed with '{s}':\n{s}", .{ @errorName(err), cmd });
        };
        switch (arg_mode) {
            .run, .build => {
                switch (term) {
                    .Exited => |code| {
                        if (code == 0) {
                            return cleanExit();
                        } else {
                            process.exit(code);
                        }
                    },
                    else => {
                        process.exit(1);
                    },
                }
            },
            .zig_test => {
                switch (term) {
                    .Exited => |code| {
                        if (code == 0) {
                            return cleanExit();
                        } else {
                            const cmd = try std.mem.join(arena, " ", argv.items);
                            fatal("the following test command failed with exit code {d}:\n{s}", .{ code, cmd });
                        }
                    },
                    else => {
                        const cmd = try std.mem.join(arena, " ", argv.items);
                        fatal("the following test command crashed:\n{s}", .{cmd});
                    },
                }
            },
            else => unreachable,
        }
    } else {
        const cmd = try std.mem.join(arena, " ", argv.items);
        fatal("the following command cannot be executed ({s} does not support spawning a child process):\n{s}", .{ @tagName(native_os), cmd });
    }
}

fn runOrTestHotSwap(
    comp: *Compilation,
    gpa: Allocator,
    test_exec_args: []const ?[]const u8,
    self_exe_path: []const u8,
    arg_mode: ArgMode,
    all_args: []const []const u8,
    runtime_args_start: ?usize,
) !std.process.Child.Id {
    const lf = comp.bin_file.?;

    const exe_path = switch (builtin.target.os.tag) {
        // On Windows it seems impossible to perform an atomic rename of a file that is currently
        // running in a process. Therefore, we do the opposite. We create a copy of the file in
        // tmp zig-cache and use it to spawn the child process. This way we are free to update
        // the binary with each requested hot update.
        .windows => blk: {
            try lf.emit.root_dir.handle.copyFile(lf.emit.sub_path, comp.local_cache_directory.handle, lf.emit.sub_path, .{});
            break :blk try fs.path.join(gpa, &[_][]const u8{
                comp.local_cache_directory.path orelse ".", lf.emit.sub_path,
            });
        },

        // A naive `directory.join` here will indeed get the correct path to the binary,
        // however, in the case of cwd, we actually want `./foo` so that the path can be executed.
        else => try fs.path.join(gpa, &[_][]const u8{
            lf.emit.root_dir.path orelse ".", lf.emit.sub_path,
        }),
    };
    defer gpa.free(exe_path);

    var argv = std.ArrayList([]const u8).init(gpa);
    defer argv.deinit();

    if (test_exec_args.len == 0) {
        // when testing pass the zig_exe_path to argv
        if (arg_mode == .zig_test)
            try argv.appendSlice(&[_][]const u8{
                exe_path, self_exe_path,
            })
            // when running just pass the current exe
        else
            try argv.appendSlice(&[_][]const u8{
                exe_path,
            });
    } else {
        for (test_exec_args) |arg| {
            if (arg) |a| {
                try argv.append(a);
            } else {
                try argv.appendSlice(&[_][]const u8{
                    exe_path, self_exe_path,
                });
            }
        }
    }
    if (runtime_args_start) |i| {
        try argv.appendSlice(all_args[i..]);
    }

    switch (builtin.target.os.tag) {
        .macos, .ios, .tvos, .watchos, .visionos => {
            const PosixSpawn = @import("DarwinPosixSpawn.zig");

            var attr = try PosixSpawn.Attr.init();
            defer attr.deinit();

            // ASLR is probably a good default for better debugging experience/programming
            // with hot-code updates in mind. However, we can also make it work with ASLR on.
            const flags: u16 = std.c.POSIX_SPAWN.SETSIGDEF |
                std.c.POSIX_SPAWN.SETSIGMASK |
                std.c.POSIX_SPAWN.DISABLE_ASLR;
            try attr.set(flags);

            var arena_allocator = std.heap.ArenaAllocator.init(gpa);
            defer arena_allocator.deinit();
            const arena = arena_allocator.allocator();

            const argv_buf = try arena.allocSentinel(?[*:0]u8, argv.items.len, null);
            for (argv.items, 0..) |arg, i| argv_buf[i] = (try arena.dupeZ(u8, arg)).ptr;

            const pid = try PosixSpawn.spawn(argv.items[0], null, attr, argv_buf, std.c.environ);
            return pid;
        },
        else => {
            var child = std.process.Child.init(argv.items, gpa);

            child.stdin_behavior = .Inherit;
            child.stdout_behavior = .Inherit;
            child.stderr_behavior = .Inherit;

            try child.spawn();

            return child.id;
        },
    }
}

fn updateModule(comp: *Compilation, color: Color, prog_node: std.Progress.Node) !void {
    try comp.update(prog_node);

    var errors = try comp.getAllErrorsAlloc();
    defer errors.deinit(comp.gpa);

    if (errors.errorMessageCount() > 0) {
        errors.renderToStdErr(color.renderOptions());
        return error.SemanticAnalyzeFail;
    }
}

fn cmdTranslateC(
    comp: *Compilation,
    arena: Allocator,
    fancy_output: ?*Compilation.CImportResult,
    file_system_inputs: ?*std.ArrayListUnmanaged(u8),
    prog_node: std.Progress.Node,
) !void {
    dev.check(.translate_c_command);

    const color: Color = .auto;
    assert(comp.c_source_files.len == 1);
    const c_source_file = comp.c_source_files[0];

    const translated_zig_basename = try std.fmt.allocPrint(arena, "{s}.zig", .{comp.root_name});

    var man: Cache.Manifest = comp.obtainCObjectCacheManifest(comp.root_mod);
    man.want_shared_lock = false;
    defer man.deinit();

    man.hash.add(@as(u16, 0xb945)); // Random number to distinguish translate-c from compiling C objects
    man.hash.add(comp.config.c_frontend);
    Compilation.cache_helpers.hashCSource(&man, c_source_file) catch |err| {
        fatal("unable to process '{s}': {s}", .{ c_source_file.src_path, @errorName(err) });
    };

    if (fancy_output) |p| p.cache_hit = true;
    const bin_digest, const hex_digest = if (try man.hit()) digest: {
        if (file_system_inputs) |buf| try man.populateFileSystemInputs(buf);
        const bin_digest = man.finalBin();
        const hex_digest = Cache.binToHex(bin_digest);
        break :digest .{ bin_digest, hex_digest };
    } else digest: {
        if (fancy_output) |p| p.cache_hit = false;
        var argv = std.ArrayList([]const u8).init(arena);
        switch (comp.config.c_frontend) {
            .aro => {},
            .clang => {
                // argv[0] is program name, actual args start at [1]
                try argv.append(@tagName(comp.config.c_frontend));
            },
        }

        var zig_cache_tmp_dir = try comp.local_cache_directory.handle.makeOpenPath("tmp", .{});
        defer zig_cache_tmp_dir.close();

        const ext = Compilation.classifyFileExt(c_source_file.src_path);
        const out_dep_path: ?[]const u8 = blk: {
            if (comp.config.c_frontend == .aro or comp.disable_c_depfile or !ext.clangSupportsDepFile())
                break :blk null;

            const c_src_basename = fs.path.basename(c_source_file.src_path);
            const dep_basename = try std.fmt.allocPrint(arena, "{s}.d", .{c_src_basename});
            const out_dep_path = try comp.tmpFilePath(arena, dep_basename);
            break :blk out_dep_path;
        };

        // TODO
        if (comp.config.c_frontend != .aro)
            try comp.addTranslateCCArgs(arena, &argv, ext, out_dep_path, comp.root_mod);
        try argv.append(c_source_file.src_path);

        if (comp.verbose_cc) {
            Compilation.dump_argv(argv.items);
        }

        const Result = union(enum) {
            success: []const u8,
            error_bundle: std.zig.ErrorBundle,
        };

        const result: Result = switch (comp.config.c_frontend) {
            .aro => f: {
                var stdout: []u8 = undefined;
                try jitCmd(comp.gpa, arena, argv.items, .{
                    .cmd_name = "aro_translate_c",
                    .root_src_path = "aro_translate_c.zig",
                    .depend_on_aro = true,
                    .capture = &stdout,
                    .progress_node = prog_node,
                });
                break :f .{ .success = stdout };
            },
            .clang => f: {
                if (!build_options.have_llvm) unreachable;
                const translate_c = @import("translate_c.zig");

                // Convert to null terminated args.
                const clang_args_len = argv.items.len + c_source_file.extra_flags.len;
                const new_argv_with_sentinel = try arena.alloc(?[*:0]const u8, clang_args_len + 1);
                new_argv_with_sentinel[clang_args_len] = null;
                const new_argv = new_argv_with_sentinel[0..clang_args_len :null];
                for (argv.items, 0..) |arg, i| {
                    new_argv[i] = try arena.dupeZ(u8, arg);
                }
                for (c_source_file.extra_flags, 0..) |arg, i| {
                    new_argv[argv.items.len + i] = try arena.dupeZ(u8, arg);
                }

                const c_headers_dir_path_z = try comp.zig_lib_directory.joinZ(arena, &[_][]const u8{"include"});
                var errors = std.zig.ErrorBundle.empty;
                var tree = translate_c.translate(
                    comp.gpa,
                    new_argv.ptr,
                    new_argv.ptr + new_argv.len,
                    &errors,
                    c_headers_dir_path_z,
                ) catch |err| switch (err) {
                    error.OutOfMemory => return error.OutOfMemory,
                    error.SemanticAnalyzeFail => break :f .{ .error_bundle = errors },
                };
                defer tree.deinit(comp.gpa);
                break :f .{ .success = try tree.render(arena) };
            },
        };

        if (out_dep_path) |dep_file_path| add_deps: {
            const dep_basename = fs.path.basename(dep_file_path);
            // Add the files depended on to the cache system.
            man.addDepFilePost(zig_cache_tmp_dir, dep_basename) catch |err| switch (err) {
                error.FileNotFound => {
                    // Clang didn't emit the dep file; nothing to add to the manifest.
                    break :add_deps;
                },
                else => |e| return e,
            };
            // Just to save disk space, we delete the file because it is never needed again.
            zig_cache_tmp_dir.deleteFile(dep_basename) catch |err| {
                warn("failed to delete '{s}': {s}", .{ dep_file_path, @errorName(err) });
            };
        }

        const formatted = switch (result) {
            .success => |formatted| formatted,
            .error_bundle => |eb| {
                if (file_system_inputs) |buf| try man.populateFileSystemInputs(buf);
                if (fancy_output) |p| {
                    p.errors = eb;
                    return;
                } else {
                    eb.renderToStdErr(color.renderOptions());
                    process.exit(1);
                }
            },
        };

        const bin_digest = man.finalBin();
        const hex_digest = Cache.binToHex(bin_digest);

        const o_sub_path = try fs.path.join(arena, &[_][]const u8{ "o", &hex_digest });

        var o_dir = try comp.local_cache_directory.handle.makeOpenPath(o_sub_path, .{});
        defer o_dir.close();

        var zig_file = try o_dir.createFile(translated_zig_basename, .{});
        defer zig_file.close();

        try zig_file.writeAll(formatted);

        man.writeManifest() catch |err| warn("failed to write cache manifest: {s}", .{
            @errorName(err),
        });

        if (file_system_inputs) |buf| try man.populateFileSystemInputs(buf);

        break :digest .{ bin_digest, hex_digest };
    };

    if (fancy_output) |p| {
        p.digest = bin_digest;
        p.errors = std.zig.ErrorBundle.empty;
    } else {
        const out_zig_path = try fs.path.join(arena, &[_][]const u8{ "o", &hex_digest, translated_zig_basename });
        const zig_file = comp.local_cache_directory.handle.openFile(out_zig_path, .{}) catch |err| {
            const path = comp.local_cache_directory.path orelse ".";
            fatal("unable to open cached translated zig file '{s}{s}{s}': {s}", .{ path, fs.path.sep_str, out_zig_path, @errorName(err) });
        };
        defer zig_file.close();
        try io.getStdOut().writeFileAll(zig_file, .{});
        return cleanExit();
    }
}

const usage_init =
    \\Usage: zig init
    \\
    \\   Initializes a `zig build` project in the current working
    \\   directory.
    \\
    \\Options:
    \\  -h, --help             Print this help and exit
    \\
    \\
;

fn cmdInit(gpa: Allocator, arena: Allocator, args: []const []const u8) !void {
    dev.check(.init_command);

    {
        var i: usize = 0;
        while (i < args.len) : (i += 1) {
            const arg = args[i];
            if (mem.startsWith(u8, arg, "-")) {
                if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                    try io.getStdOut().writeAll(usage_init);
                    return cleanExit();
                } else {
                    fatal("unrecognized parameter: '{s}'", .{arg});
                }
            } else {
                fatal("unexpected extra parameter: '{s}'", .{arg});
            }
        }
    }

    var templates = findTemplates(gpa, arena);
    defer templates.deinit();

    const cwd_path = try process.getCwdAlloc(arena);
    const cwd_basename = fs.path.basename(cwd_path);

    const s = fs.path.sep_str;
    const template_paths = [_][]const u8{
        Package.build_zig_basename,
        Package.Manifest.basename,
        "src" ++ s ++ "main.zig",
        "src" ++ s ++ "root.zig",
    };
    var ok_count: usize = 0;

    for (template_paths) |template_path| {
        if (templates.write(arena, fs.cwd(), cwd_basename, template_path)) |_| {
            std.log.info("created {s}", .{template_path});
            ok_count += 1;
        } else |err| switch (err) {
            error.PathAlreadyExists => std.log.info("preserving already existing file: {s}", .{
                template_path,
            }),
            else => std.log.err("unable to write {s}: {s}\n", .{ template_path, @errorName(err) }),
        }
    }

    if (ok_count == template_paths.len) {
        std.log.info("see `zig build --help` for a menu of options", .{});
    }
    return cleanExit();
}

fn cmdBuild(gpa: Allocator, arena: Allocator, args: []const []const u8) !void {
    dev.check(.build_command);

    var build_file: ?[]const u8 = null;
    var override_lib_dir: ?[]const u8 = try EnvVar.ZIG_LIB_DIR.get(arena);
    var override_global_cache_dir: ?[]const u8 = try EnvVar.ZIG_GLOBAL_CACHE_DIR.get(arena);
    var override_local_cache_dir: ?[]const u8 = try EnvVar.ZIG_LOCAL_CACHE_DIR.get(arena);
    var override_build_runner: ?[]const u8 = try EnvVar.ZIG_BUILD_RUNNER.get(arena);
    var child_argv = std.ArrayList([]const u8).init(arena);
    var reference_trace: ?u32 = null;
    var debug_compile_errors = false;
    var verbose_link = (native_os != .wasi or builtin.link_libc) and
        EnvVar.ZIG_VERBOSE_LINK.isSet();
    var verbose_cc = (native_os != .wasi or builtin.link_libc) and
        EnvVar.ZIG_VERBOSE_CC.isSet();
    var verbose_air = false;
    var verbose_intern_pool = false;
    var verbose_generic_instances = false;
    var verbose_llvm_ir: ?[]const u8 = null;
    var verbose_llvm_bc: ?[]const u8 = null;
    var verbose_cimport = false;
    var verbose_llvm_cpu_features = false;
    var fetch_only = false;
    var system_pkg_dir_path: ?[]const u8 = null;
    var debug_target: ?[]const u8 = null;

    const argv_index_exe = child_argv.items.len;
    _ = try child_argv.addOne();

    const self_exe_path = try introspect.findZigExePath(arena);
    try child_argv.append(self_exe_path);

    const argv_index_zig_lib_dir = child_argv.items.len;
    _ = try child_argv.addOne();

    const argv_index_build_file = child_argv.items.len;
    _ = try child_argv.addOne();

    const argv_index_cache_dir = child_argv.items.len;
    _ = try child_argv.addOne();

    const argv_index_global_cache_dir = child_argv.items.len;
    _ = try child_argv.addOne();

    try child_argv.appendSlice(&.{
        "--seed",
        try std.fmt.allocPrint(arena, "0x{x}", .{std.crypto.random.int(u32)}),
    });
    const argv_index_seed = child_argv.items.len - 1;

    // This parent process needs a way to obtain results from the configuration
    // phase of the child process. In the future, the make phase will be
    // executed in a separate process than the configure phase, and we can then
    // use stdout from the configuration phase for this purpose.
    //
    // However, currently, both phases are in the same process, and Run Step
    // provides API for making the runned subprocesses inherit stdout and stderr
    // which means these streams are not available for passing metadata back
    // to the parent.
    //
    // Until make and configure phases are separated into different processes,
    // the strategy is to choose a temporary file name ahead of time, and then
    // read this file in the parent to obtain the results, in the case the child
    // exits with code 3.
    const results_tmp_file_nonce = std.fmt.hex(std.crypto.random.int(u64));
    try child_argv.append("-Z" ++ results_tmp_file_nonce);

    var color: Color = .auto;
    var n_jobs: ?u32 = null;

    {
        var i: usize = 0;
        while (i < args.len) : (i += 1) {
            const arg = args[i];
            if (mem.startsWith(u8, arg, "-")) {
                if (mem.eql(u8, arg, "--build-file")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    build_file = args[i];
                    continue;
                } else if (mem.eql(u8, arg, "--zig-lib-dir")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    override_lib_dir = args[i];
                    continue;
                } else if (mem.eql(u8, arg, "--build-runner")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    override_build_runner = args[i];
                    continue;
                } else if (mem.eql(u8, arg, "--cache-dir")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    override_local_cache_dir = args[i];
                    continue;
                } else if (mem.eql(u8, arg, "--global-cache-dir")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    override_global_cache_dir = args[i];
                    continue;
                } else if (mem.eql(u8, arg, "-freference-trace")) {
                    reference_trace = 256;
                } else if (mem.eql(u8, arg, "--fetch")) {
                    fetch_only = true;
                } else if (mem.eql(u8, arg, "--system")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    system_pkg_dir_path = args[i];
                    try child_argv.append("--system");
                    continue;
                } else if (mem.startsWith(u8, arg, "-freference-trace=")) {
                    const num = arg["-freference-trace=".len..];
                    reference_trace = std.fmt.parseUnsigned(u32, num, 10) catch |err| {
                        fatal("unable to parse reference_trace count '{s}': {s}", .{ num, @errorName(err) });
                    };
                } else if (mem.eql(u8, arg, "-fno-reference-trace")) {
                    reference_trace = null;
                } else if (mem.eql(u8, arg, "--debug-log")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    try child_argv.appendSlice(args[i .. i + 2]);
                    i += 1;
                    if (!build_options.enable_logging) {
                        warn("Zig was compiled without logging enabled (-Dlog). --debug-log has no effect.", .{});
                    } else {
                        try log_scopes.append(arena, args[i]);
                    }
                    continue;
                } else if (mem.eql(u8, arg, "--debug-compile-errors")) {
                    if (build_options.enable_debug_extensions) {
                        debug_compile_errors = true;
                    } else {
                        warn("Zig was compiled without debug extensions. --debug-compile-errors has no effect.", .{});
                    }
                } else if (mem.eql(u8, arg, "--debug-target")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    if (build_options.enable_debug_extensions) {
                        debug_target = args[i];
                    } else {
                        warn("Zig was compiled without debug extensions. --debug-target has no effect.", .{});
                    }
                } else if (mem.eql(u8, arg, "--verbose-link")) {
                    verbose_link = true;
                } else if (mem.eql(u8, arg, "--verbose-cc")) {
                    verbose_cc = true;
                } else if (mem.eql(u8, arg, "--verbose-air")) {
                    verbose_air = true;
                } else if (mem.eql(u8, arg, "--verbose-intern-pool")) {
                    verbose_intern_pool = true;
                } else if (mem.eql(u8, arg, "--verbose-generic-instances")) {
                    verbose_generic_instances = true;
                } else if (mem.eql(u8, arg, "--verbose-llvm-ir")) {
                    verbose_llvm_ir = "-";
                } else if (mem.startsWith(u8, arg, "--verbose-llvm-ir=")) {
                    verbose_llvm_ir = arg["--verbose-llvm-ir=".len..];
                } else if (mem.startsWith(u8, arg, "--verbose-llvm-bc=")) {
                    verbose_llvm_bc = arg["--verbose-llvm-bc=".len..];
                } else if (mem.eql(u8, arg, "--verbose-cimport")) {
                    verbose_cimport = true;
                } else if (mem.eql(u8, arg, "--verbose-llvm-cpu-features")) {
                    verbose_llvm_cpu_features = true;
                } else if (mem.eql(u8, arg, "--color")) {
                    if (i + 1 >= args.len) fatal("expected [auto|on|off] after {s}", .{arg});
                    i += 1;
                    color = std.meta.stringToEnum(Color, args[i]) orelse {
                        fatal("expected [auto|on|off] after {s}, found '{s}'", .{ arg, args[i] });
                    };
                    try child_argv.appendSlice(&.{ arg, args[i] });
                    continue;
                } else if (mem.startsWith(u8, arg, "-j")) {
                    const str = arg["-j".len..];
                    const num = std.fmt.parseUnsigned(u32, str, 10) catch |err| {
                        fatal("unable to parse jobs count '{s}': {s}", .{
                            str, @errorName(err),
                        });
                    };
                    if (num < 1) {
                        fatal("number of jobs must be at least 1\n", .{});
                    }
                    n_jobs = num;
                } else if (mem.eql(u8, arg, "--seed")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    child_argv.items[argv_index_seed] = args[i];
                    continue;
                } else if (mem.eql(u8, arg, "--")) {
                    // The rest of the args are supposed to get passed onto
                    // build runner's `build.args`
                    try child_argv.appendSlice(args[i..]);
                    break;
                }
            }
            try child_argv.append(arg);
        }
    }

    const work_around_btrfs_bug = native_os == .linux and
        EnvVar.ZIG_BTRFS_WORKAROUND.isSet();
    const root_prog_node = std.Progress.start(.{
        .disable_printing = (color == .off),
        .root_name = "Compile Build Script",
    });
    defer root_prog_node.end();

    // Normally the build runner is compiled for the host target but here is
    // some code to help when debugging edits to the build runner so that you
    // can make sure it compiles successfully on other targets.
    const resolved_target: Package.Module.ResolvedTarget = t: {
        if (build_options.enable_debug_extensions) {
            if (debug_target) |triple| {
                const target_query = try std.Target.Query.parse(.{
                    .arch_os_abi = triple,
                });
                break :t .{
                    .result = std.zig.resolveTargetQueryOrFatal(target_query),
                    .is_native_os = false,
                    .is_native_abi = false,
                };
            }
        }
        break :t .{
            .result = std.zig.resolveTargetQueryOrFatal(.{}),
            .is_native_os = true,
            .is_native_abi = true,
        };
    };

    const exe_basename = try std.zig.binNameAlloc(arena, .{
        .root_name = "build",
        .target = resolved_target.result,
        .output_mode = .Exe,
    });
    const emit_bin: Compilation.EmitLoc = .{
        .directory = null, // Use the local zig-cache.
        .basename = exe_basename,
    };

    process.raiseFileDescriptorLimit();

    var zig_lib_directory: Compilation.Directory = if (override_lib_dir) |lib_dir| .{
        .path = lib_dir,
        .handle = fs.cwd().openDir(lib_dir, .{}) catch |err| {
            fatal("unable to open zig lib directory from 'zig-lib-dir' argument: '{s}': {s}", .{ lib_dir, @errorName(err) });
        },
    } else introspect.findZigLibDirFromSelfExe(arena, self_exe_path) catch |err| {
        fatal("unable to find zig installation directory '{s}': {s}", .{ self_exe_path, @errorName(err) });
    };
    defer zig_lib_directory.handle.close();

    const cwd_path = try process.getCwdAlloc(arena);
    child_argv.items[argv_index_zig_lib_dir] = zig_lib_directory.path orelse cwd_path;

    const build_root = try findBuildRoot(arena, .{
        .cwd_path = cwd_path,
        .build_file = build_file,
    });
    child_argv.items[argv_index_build_file] = build_root.directory.path orelse cwd_path;

    var global_cache_directory: Compilation.Directory = l: {
        const p = override_global_cache_dir orelse try introspect.resolveGlobalCacheDir(arena);
        break :l .{
            .handle = try fs.cwd().makeOpenPath(p, .{}),
            .path = p,
        };
    };
    defer global_cache_directory.handle.close();

    child_argv.items[argv_index_global_cache_dir] = global_cache_directory.path orelse cwd_path;

    var local_cache_directory: Compilation.Directory = l: {
        if (override_local_cache_dir) |local_cache_dir_path| {
            break :l .{
                .handle = try fs.cwd().makeOpenPath(local_cache_dir_path, .{}),
                .path = local_cache_dir_path,
            };
        }
        const cache_dir_path = try build_root.directory.join(arena, &.{default_local_zig_cache_basename});
        break :l .{
            .handle = try build_root.directory.handle.makeOpenPath(default_local_zig_cache_basename, .{}),
            .path = cache_dir_path,
        };
    };
    defer local_cache_directory.handle.close();

    child_argv.items[argv_index_cache_dir] = local_cache_directory.path orelse cwd_path;

    var thread_pool: ThreadPool = undefined;
    try thread_pool.init(.{
        .allocator = gpa,
        .n_jobs = @min(@max(n_jobs orelse std.Thread.getCpuCount() catch 1, 1), std.math.maxInt(Zcu.PerThread.IdBacking)),
        .track_ids = true,
    });
    defer thread_pool.deinit();

    // Dummy http client that is not actually used when fetch_command is unsupported.
    // Prevents bootstrap from depending on a bunch of unnecessary stuff.
    var http_client: if (dev.env.supports(.fetch_command)) std.http.Client else struct {
        allocator: Allocator,
        fn deinit(_: @This()) void {}
    } = .{ .allocator = gpa };
    defer http_client.deinit();

    var unlazy_set: Package.Fetch.JobQueue.UnlazySet = .{};

    // This loop is re-evaluated when the build script exits with an indication that it
    // could not continue due to missing lazy dependencies.
    while (true) {
        // We want to release all the locks before executing the child process, so we make a nice
        // big block here to ensure the cleanup gets run when we extract out our argv.
        {
            const main_mod_paths: Package.Module.CreateOptions.Paths = if (override_build_runner) |runner| .{
                .root = .{
                    .root_dir = Cache.Directory.cwd(),
                    .sub_path = fs.path.dirname(runner) orelse "",
                },
                .root_src_path = fs.path.basename(runner),
            } else .{
                .root = .{
                    .root_dir = zig_lib_directory,
                    .sub_path = "compiler",
                },
                .root_src_path = "build_runner.zig",
            };

            const config = try Compilation.Config.resolve(.{
                .output_mode = .Exe,
                .resolved_target = resolved_target,
                .have_zcu = true,
                .emit_bin = true,
                .is_test = false,
            });

            const root_mod = try Package.Module.create(arena, .{
                .global_cache_directory = global_cache_directory,
                .paths = main_mod_paths,
                .fully_qualified_name = "root",
                .cc_argv = &.{},
                .inherited = .{
                    .resolved_target = resolved_target,
                },
                .global = config,
                .parent = null,
                .builtin_mod = null,
                .builtin_modules = null, // all modules will inherit this one's builtin
            });

            const builtin_mod = root_mod.getBuiltinDependency();

            const build_mod = try Package.Module.create(arena, .{
                .global_cache_directory = global_cache_directory,
                .paths = .{
                    .root = .{ .root_dir = build_root.directory },
                    .root_src_path = build_root.build_zig_basename,
                },
                .fully_qualified_name = "root.@build",
                .cc_argv = &.{},
                .inherited = .{},
                .global = config,
                .parent = root_mod,
                .builtin_mod = builtin_mod,
                .builtin_modules = null, // `builtin_mod` is specified
            });

            var cleanup_build_dir: ?fs.Dir = null;
            defer if (cleanup_build_dir) |*dir| dir.close();

            if (dev.env.supports(.fetch_command)) {
                const fetch_prog_node = root_prog_node.start("Fetch Packages", 0);
                defer fetch_prog_node.end();

                var job_queue: Package.Fetch.JobQueue = .{
                    .http_client = &http_client,
                    .thread_pool = &thread_pool,
                    .global_cache = global_cache_directory,
                    .read_only = false,
                    .recursive = true,
                    .debug_hash = false,
                    .work_around_btrfs_bug = work_around_btrfs_bug,
                    .unlazy_set = unlazy_set,
                };
                defer job_queue.deinit();

                if (system_pkg_dir_path) |p| {
                    job_queue.global_cache = .{
                        .path = p,
                        .handle = fs.cwd().openDir(p, .{}) catch |err| {
                            fatal("unable to open system package directory '{s}': {s}", .{
                                p, @errorName(err),
                            });
                        },
                    };
                    job_queue.read_only = true;
                    cleanup_build_dir = job_queue.global_cache.handle;
                } else {
                    try http_client.initDefaultProxies(arena);
                }

                try job_queue.all_fetches.ensureUnusedCapacity(gpa, 1);
                try job_queue.table.ensureUnusedCapacity(gpa, 1);

                var fetch: Package.Fetch = .{
                    .arena = std.heap.ArenaAllocator.init(gpa),
                    .location = .{ .relative_path = build_mod.root },
                    .location_tok = 0,
                    .hash_tok = 0,
                    .name_tok = 0,
                    .lazy_status = .eager,
                    .parent_package_root = build_mod.root,
                    .parent_manifest_ast = null,
                    .prog_node = fetch_prog_node,
                    .job_queue = &job_queue,
                    .omit_missing_hash_error = true,
                    .allow_missing_paths_field = false,
                    .use_latest_commit = false,

                    .package_root = undefined,
                    .error_bundle = undefined,
                    .manifest = null,
                    .manifest_ast = undefined,
                    .actual_hash = undefined,
                    .has_build_zig = true,
                    .oom_flag = false,
                    .latest_commit = null,

                    .module = build_mod,
                };
                job_queue.all_fetches.appendAssumeCapacity(&fetch);

                job_queue.table.putAssumeCapacityNoClobber(
                    Package.Fetch.relativePathDigest(build_mod.root, global_cache_directory),
                    &fetch,
                );

                job_queue.thread_pool.spawnWg(&job_queue.wait_group, Package.Fetch.workerRun, .{
                    &fetch, "root",
                });
                job_queue.wait_group.wait();

                try job_queue.consolidateErrors();

                if (fetch.error_bundle.root_list.items.len > 0) {
                    var errors = try fetch.error_bundle.toOwnedBundle("");
                    errors.renderToStdErr(color.renderOptions());
                    process.exit(1);
                }

                if (fetch_only) return cleanExit();

                var source_buf = std.ArrayList(u8).init(gpa);
                defer source_buf.deinit();
                try job_queue.createDependenciesSource(&source_buf);
                const deps_mod = try createDependenciesModule(
                    arena,
                    source_buf.items,
                    root_mod,
                    global_cache_directory,
                    local_cache_directory,
                    builtin_mod,
                    config,
                );

                {
                    // We need a Module for each package's build.zig.
                    const hashes = job_queue.table.keys();
                    const fetches = job_queue.table.values();
                    try deps_mod.deps.ensureUnusedCapacity(arena, @intCast(hashes.len));
                    for (hashes, fetches) |hash, f| {
                        if (f == &fetch) {
                            // The first one is a dummy package for the current project.
                            continue;
                        }
                        if (!f.has_build_zig)
                            continue;
                        const m = try Package.Module.create(arena, .{
                            .global_cache_directory = global_cache_directory,
                            .paths = .{
                                .root = try f.package_root.clone(arena),
                                .root_src_path = Package.build_zig_basename,
                            },
                            .fully_qualified_name = try std.fmt.allocPrint(
                                arena,
                                "root.@dependencies.{s}",
                                .{&hash},
                            ),
                            .cc_argv = &.{},
                            .inherited = .{},
                            .global = config,
                            .parent = root_mod,
                            .builtin_mod = builtin_mod,
                            .builtin_modules = null, // `builtin_mod` is specified
                        });
                        const hash_cloned = try arena.dupe(u8, &hash);
                        deps_mod.deps.putAssumeCapacityNoClobber(hash_cloned, m);
                        f.module = m;
                    }

                    // Each build.zig module needs access to each of its
                    // dependencies' build.zig modules by name.
                    for (fetches) |f| {
                        const mod = f.module orelse continue;
                        const man = f.manifest orelse continue;
                        const dep_names = man.dependencies.keys();
                        try mod.deps.ensureUnusedCapacity(arena, @intCast(dep_names.len));
                        for (dep_names, man.dependencies.values()) |name, dep| {
                            const dep_digest = Package.Fetch.depDigest(
                                f.package_root,
                                global_cache_directory,
                                dep,
                            ) orelse continue;
                            const dep_mod = job_queue.table.get(dep_digest).?.module orelse continue;
                            const name_cloned = try arena.dupe(u8, name);
                            mod.deps.putAssumeCapacityNoClobber(name_cloned, dep_mod);
                        }
                    }
                }
            } else try createEmptyDependenciesModule(
                arena,
                root_mod,
                global_cache_directory,
                local_cache_directory,
                builtin_mod,
                config,
            );

            try root_mod.deps.put(arena, "@build", build_mod);

            const comp = Compilation.create(gpa, arena, .{
                .zig_lib_directory = zig_lib_directory,
                .local_cache_directory = local_cache_directory,
                .global_cache_directory = global_cache_directory,
                .root_name = "build",
                .config = config,
                .root_mod = root_mod,
                .main_mod = build_mod,
                .emit_bin = emit_bin,
                .emit_h = null,
                .self_exe_path = self_exe_path,
                .thread_pool = &thread_pool,
                .verbose_cc = verbose_cc,
                .verbose_link = verbose_link,
                .verbose_air = verbose_air,
                .verbose_intern_pool = verbose_intern_pool,
                .verbose_generic_instances = verbose_generic_instances,
                .verbose_llvm_ir = verbose_llvm_ir,
                .verbose_llvm_bc = verbose_llvm_bc,
                .verbose_cimport = verbose_cimport,
                .verbose_llvm_cpu_features = verbose_llvm_cpu_features,
                .cache_mode = .whole,
                .reference_trace = reference_trace,
                .debug_compile_errors = debug_compile_errors,
            }) catch |err| {
                fatal("unable to create compilation: {s}", .{@errorName(err)});
            };
            defer comp.destroy();

            updateModule(comp, color, root_prog_node) catch |err| switch (err) {
                error.SemanticAnalyzeFail => process.exit(2),
                else => |e| return e,
            };

            // Since incremental compilation isn't done yet, we use cache_mode = whole
            // above, and thus the output file is already closed.
            //try comp.makeBinFileExecutable();
            child_argv.items[argv_index_exe] =
                try local_cache_directory.join(arena, &.{comp.cache_use.whole.bin_sub_path.?});
        }

        if (process.can_spawn) {
            var child = std.process.Child.init(child_argv.items, gpa);
            child.stdin_behavior = .Inherit;
            child.stdout_behavior = .Inherit;
            child.stderr_behavior = .Inherit;

            const term = t: {
                std.debug.lockStdErr();
                defer std.debug.unlockStdErr();
                break :t child.spawnAndWait() catch |err| {
                    fatal("unable to spawn {s}: {s}", .{ child_argv.items[0], @errorName(err) });
                };
            };

            switch (term) {
                .Exited => |code| {
                    if (code == 0) return cleanExit();
                    // Indicates that the build runner has reported compile errors
                    // and this parent process does not need to report any further
                    // diagnostics.
                    if (code == 2) process.exit(2);

                    if (code == 3) {
                        if (!dev.env.supports(.fetch_command)) process.exit(3);
                        // Indicates the configure phase failed due to missing lazy
                        // dependencies and stdout contains the hashes of the ones
                        // that are missing.
                        const s = fs.path.sep_str;
                        const tmp_sub_path = "tmp" ++ s ++ results_tmp_file_nonce;
                        const stdout = local_cache_directory.handle.readFileAlloc(arena, tmp_sub_path, 50 * 1024 * 1024) catch |err| {
                            fatal("unable to read results of configure phase from '{}{s}': {s}", .{
                                local_cache_directory, tmp_sub_path, @errorName(err),
                            });
                        };
                        local_cache_directory.handle.deleteFile(tmp_sub_path) catch {};

                        var it = mem.splitScalar(u8, stdout, '\n');
                        var any_errors = false;
                        while (it.next()) |hash| {
                            if (hash.len == 0) continue;
                            const digest_len = @typeInfo(Package.Manifest.MultiHashHexDigest).array.len;
                            if (hash.len != digest_len) {
                                std.log.err("invalid digest (length {d} instead of {d}): '{s}'", .{
                                    hash.len, digest_len, hash,
                                });
                                any_errors = true;
                                continue;
                            }
                            try unlazy_set.put(arena, hash[0..digest_len].*, {});
                        }
                        if (any_errors) process.exit(3);
                        if (system_pkg_dir_path) |p| {
                            // In this mode, the system needs to provide these packages; they
                            // cannot be fetched by Zig.
                            for (unlazy_set.keys()) |hash| {
                                std.log.err("lazy dependency package not found: {s}" ++ s ++ "{s}", .{
                                    p, hash,
                                });
                            }
                            std.log.info("remote package fetching disabled due to --system mode", .{});
                            std.log.info("dependencies might be avoidable depending on build configuration", .{});
                            process.exit(3);
                        }
                        continue;
                    }

                    const cmd = try std.mem.join(arena, " ", child_argv.items);
                    fatal("the following build command failed with exit code {d}:\n{s}", .{ code, cmd });
                },
                else => {
                    const cmd = try std.mem.join(arena, " ", child_argv.items);
                    fatal("the following build command crashed:\n{s}", .{cmd});
                },
            }
        } else {
            const cmd = try std.mem.join(arena, " ", child_argv.items);
            fatal("the following command cannot be executed ({s} does not support spawning a child process):\n{s}", .{ @tagName(native_os), cmd });
        }
    }
}

const JitCmdOptions = struct {
    cmd_name: []const u8,
    root_src_path: []const u8,
    prepend_zig_lib_dir_path: bool = false,
    prepend_global_cache_path: bool = false,
    prepend_zig_exe_path: bool = false,
    depend_on_aro: bool = false,
    capture: ?*[]u8 = null,
    /// Send error bundles via std.zig.Server over stdout
    server: bool = false,
    progress_node: ?std.Progress.Node = null,
};

fn jitCmd(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
    options: JitCmdOptions,
) !void {
    dev.check(.jit_command);

    const color: Color = .auto;
    const root_prog_node = if (options.progress_node) |node| node else std.Progress.start(.{
        .disable_printing = (color == .off),
    });

    const target_query: std.Target.Query = .{};
    const resolved_target: Package.Module.ResolvedTarget = .{
        .result = std.zig.resolveTargetQueryOrFatal(target_query),
        .is_native_os = true,
        .is_native_abi = true,
    };

    const exe_basename = try std.zig.binNameAlloc(arena, .{
        .root_name = options.cmd_name,
        .target = resolved_target.result,
        .output_mode = .Exe,
    });
    const emit_bin: Compilation.EmitLoc = .{
        .directory = null, // Use the global zig-cache.
        .basename = exe_basename,
    };

    const self_exe_path = introspect.findZigExePath(arena) catch |err| {
        fatal("unable to find self exe path: {s}", .{@errorName(err)});
    };

    const optimize_mode: std.builtin.OptimizeMode = if (EnvVar.ZIG_DEBUG_CMD.isSet())
        .Debug
    else
        .ReleaseFast;
    const strip = optimize_mode != .Debug;
    const override_lib_dir: ?[]const u8 = try EnvVar.ZIG_LIB_DIR.get(arena);
    const override_global_cache_dir: ?[]const u8 = try EnvVar.ZIG_GLOBAL_CACHE_DIR.get(arena);

    var zig_lib_directory: Compilation.Directory = if (override_lib_dir) |lib_dir| .{
        .path = lib_dir,
        .handle = fs.cwd().openDir(lib_dir, .{}) catch |err| {
            fatal("unable to open zig lib directory from 'zig-lib-dir' argument: '{s}': {s}", .{ lib_dir, @errorName(err) });
        },
    } else introspect.findZigLibDirFromSelfExe(arena, self_exe_path) catch |err| {
        fatal("unable to find zig installation directory '{s}': {s}", .{ self_exe_path, @errorName(err) });
    };
    defer zig_lib_directory.handle.close();

    var global_cache_directory: Compilation.Directory = l: {
        const p = override_global_cache_dir orelse try introspect.resolveGlobalCacheDir(arena);
        break :l .{
            .handle = try fs.cwd().makeOpenPath(p, .{}),
            .path = p,
        };
    };
    defer global_cache_directory.handle.close();

    var thread_pool: ThreadPool = undefined;
    try thread_pool.init(.{
        .allocator = gpa,
        .n_jobs = @min(@max(std.Thread.getCpuCount() catch 1, 1), std.math.maxInt(Zcu.PerThread.IdBacking)),
        .track_ids = true,
    });
    defer thread_pool.deinit();

    var child_argv: std.ArrayListUnmanaged([]const u8) = .empty;
    try child_argv.ensureUnusedCapacity(arena, args.len + 4);

    // We want to release all the locks before executing the child process, so we make a nice
    // big block here to ensure the cleanup gets run when we extract out our argv.
    {
        const main_mod_paths: Package.Module.CreateOptions.Paths = .{
            .root = .{
                .root_dir = zig_lib_directory,
                .sub_path = "compiler",
            },
            .root_src_path = options.root_src_path,
        };

        const config = try Compilation.Config.resolve(.{
            .output_mode = .Exe,
            .root_strip = strip,
            .root_optimize_mode = optimize_mode,
            .resolved_target = resolved_target,
            .have_zcu = true,
            .emit_bin = true,
            .is_test = false,
        });

        const root_mod = try Package.Module.create(arena, .{
            .global_cache_directory = global_cache_directory,
            .paths = main_mod_paths,
            .fully_qualified_name = "root",
            .cc_argv = &.{},
            .inherited = .{
                .resolved_target = resolved_target,
                .optimize_mode = optimize_mode,
                .strip = strip,
            },
            .global = config,
            .parent = null,
            .builtin_mod = null,
            .builtin_modules = null, // all modules will inherit this one's builtin
        });

        if (options.depend_on_aro) {
            const aro_mod = try Package.Module.create(arena, .{
                .global_cache_directory = global_cache_directory,
                .paths = .{
                    .root = .{
                        .root_dir = zig_lib_directory,
                        .sub_path = "compiler/aro",
                    },
                    .root_src_path = "aro.zig",
                },
                .fully_qualified_name = "aro",
                .cc_argv = &.{},
                .inherited = .{
                    .resolved_target = resolved_target,
                    .optimize_mode = optimize_mode,
                    .strip = strip,
                },
                .global = config,
                .parent = null,
                .builtin_mod = root_mod.getBuiltinDependency(),
                .builtin_modules = null, // `builtin_mod` is specified
            });
            try root_mod.deps.put(arena, "aro", aro_mod);
        }

        const comp = Compilation.create(gpa, arena, .{
            .zig_lib_directory = zig_lib_directory,
            .local_cache_directory = global_cache_directory,
            .global_cache_directory = global_cache_directory,
            .root_name = options.cmd_name,
            .config = config,
            .root_mod = root_mod,
            .main_mod = root_mod,
            .emit_bin = emit_bin,
            .emit_h = null,
            .self_exe_path = self_exe_path,
            .thread_pool = &thread_pool,
            .cache_mode = .whole,
        }) catch |err| {
            fatal("unable to create compilation: {s}", .{@errorName(err)});
        };
        defer comp.destroy();

        if (options.server) {
            var server = std.zig.Server{
                .out = std.io.getStdOut(),
                .in = undefined, // won't be receiving messages
                .receive_fifo = undefined, // won't be receiving messages
            };

            try comp.update(root_prog_node);

            var error_bundle = try comp.getAllErrorsAlloc();
            defer error_bundle.deinit(comp.gpa);
            if (error_bundle.errorMessageCount() > 0) {
                try server.serveErrorBundle(error_bundle);
                process.exit(2);
            }
        } else {
            updateModule(comp, color, root_prog_node) catch |err| switch (err) {
                error.SemanticAnalyzeFail => process.exit(2),
                else => |e| return e,
            };
        }

        const exe_path = try global_cache_directory.join(arena, &.{comp.cache_use.whole.bin_sub_path.?});
        child_argv.appendAssumeCapacity(exe_path);
    }

    if (options.prepend_zig_lib_dir_path)
        child_argv.appendAssumeCapacity(zig_lib_directory.path.?);
    if (options.prepend_zig_exe_path)
        child_argv.appendAssumeCapacity(self_exe_path);
    if (options.prepend_global_cache_path)
        child_argv.appendAssumeCapacity(global_cache_directory.path.?);

    child_argv.appendSliceAssumeCapacity(args);

    if (process.can_execv and options.capture == null) {
        const err = process.execv(gpa, child_argv.items);
        const cmd = try std.mem.join(arena, " ", child_argv.items);
        fatal("the following command failed to execve with '{s}':\n{s}", .{
            @errorName(err),
            cmd,
        });
    }

    if (!process.can_spawn) {
        const cmd = try std.mem.join(arena, " ", child_argv.items);
        fatal("the following command cannot be executed ({s} does not support spawning a child process):\n{s}", .{
            @tagName(native_os), cmd,
        });
    }

    var child = std.process.Child.init(child_argv.items, gpa);
    child.stdin_behavior = .Inherit;
    child.stdout_behavior = if (options.capture == null) .Inherit else .Pipe;
    child.stderr_behavior = .Inherit;

    try child.spawn();

    if (options.capture) |ptr| {
        ptr.* = try child.stdout.?.readToEndAlloc(arena, std.math.maxInt(u32));
    }

    const term = try child.wait();
    switch (term) {
        .Exited => |code| {
            if (code == 0) {
                if (options.capture != null) return;
                return cleanExit();
            }
            const cmd = try std.mem.join(arena, " ", child_argv.items);
            fatal("the following build command failed with exit code {d}:\n{s}", .{ code, cmd });
        },
        else => {
            const cmd = try std.mem.join(arena, " ", child_argv.items);
            fatal("the following build command crashed:\n{s}", .{cmd});
        },
    }
}

const info_zen =
    \\
    \\ * Communicate intent precisely.
    \\ * Edge cases matter.
    \\ * Favor reading code over writing code.
    \\ * Only one obvious way to do things.
    \\ * Runtime crashes are better than bugs.
    \\ * Compile errors are better than runtime crashes.
    \\ * Incremental improvements.
    \\ * Avoid local maximums.
    \\ * Reduce the amount one must remember.
    \\ * Focus on code rather than style.
    \\ * Resource allocation may fail; resource deallocation must succeed.
    \\ * Memory is a resource.
    \\ * Together we serve the users.
    \\
    \\
;

extern fn ZigClangIsLLVMUsingSeparateLibcxx() bool;

extern "c" fn ZigClang_main(argc: c_int, argv: [*:null]?[*:0]u8) c_int;
extern "c" fn ZigLlvmAr_main(argc: c_int, argv: [*:null]?[*:0]u8) c_int;

fn argsCopyZ(alloc: Allocator, args: []const []const u8) ![:null]?[*:0]u8 {
    var argv = try alloc.allocSentinel(?[*:0]u8, args.len, null);
    for (args, 0..) |arg, i| {
        argv[i] = try alloc.dupeZ(u8, arg); // TODO If there was an argsAllocZ we could avoid this allocation.
    }
    return argv;
}

pub fn clangMain(alloc: Allocator, args: []const []const u8) error{OutOfMemory}!u8 {
    if (!build_options.have_llvm)
        fatal("`zig cc` and `zig c++` unavailable: compiler built without LLVM extensions", .{});

    var arena_instance = std.heap.ArenaAllocator.init(alloc);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    // Convert the args to the null-terminated format Clang expects.
    const argv = try argsCopyZ(arena, args);
    const exit_code = ZigClang_main(@as(c_int, @intCast(argv.len)), argv.ptr);
    return @as(u8, @bitCast(@as(i8, @truncate(exit_code))));
}

pub fn llvmArMain(alloc: Allocator, args: []const []const u8) error{OutOfMemory}!u8 {
    if (!build_options.have_llvm)
        fatal("`zig ar`, `zig dlltool`, `zig ranlib', and `zig lib` unavailable: compiler built without LLVM extensions", .{});

    var arena_instance = std.heap.ArenaAllocator.init(alloc);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    // Convert the args to the format llvm-ar expects.
    // We intentionally shave off the zig binary at args[0].
    const argv = try argsCopyZ(arena, args[1..]);
    const exit_code = ZigLlvmAr_main(@as(c_int, @intCast(argv.len)), argv.ptr);
    return @as(u8, @bitCast(@as(i8, @truncate(exit_code))));
}

/// The first argument determines which backend is invoked. The options are:
/// * `ld.lld` - ELF
/// * `lld-link` - COFF
/// * `wasm-ld` - WebAssembly
pub fn lldMain(
    alloc: Allocator,
    args: []const []const u8,
    can_exit_early: bool,
) error{OutOfMemory}!u8 {
    if (!build_options.have_llvm)
        fatal("`zig {s}` unavailable: compiler built without LLVM extensions", .{args[0]});

    // Print a warning if lld is called multiple times in the same process,
    // since it may misbehave
    // https://github.com/ziglang/zig/issues/3825
    const CallCounter = struct {
        var count: usize = 0;
    };
    if (CallCounter.count == 1) { // Issue the warning on the first repeat call
        warn("invoking LLD for the second time within the same process because the host OS ({s}) does not support spawning child processes. This sometimes activates LLD bugs", .{@tagName(native_os)});
    }
    CallCounter.count += 1;

    var arena_instance = std.heap.ArenaAllocator.init(alloc);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    // Convert the args to the format LLD expects.
    // We intentionally shave off the zig binary at args[0].
    const argv = try argsCopyZ(arena, args[1..]);
    // "If an error occurs, false will be returned."
    const ok = rc: {
        const llvm = @import("codegen/llvm/bindings.zig");
        const argc = @as(c_int, @intCast(argv.len));
        if (mem.eql(u8, args[1], "ld.lld")) {
            break :rc llvm.LinkELF(argc, argv.ptr, can_exit_early, false);
        } else if (mem.eql(u8, args[1], "lld-link")) {
            break :rc llvm.LinkCOFF(argc, argv.ptr, can_exit_early, false);
        } else if (mem.eql(u8, args[1], "wasm-ld")) {
            break :rc llvm.LinkWasm(argc, argv.ptr, can_exit_early, false);
        } else {
            unreachable;
        }
    };
    return @intFromBool(!ok);
}

const ArgIteratorResponseFile = process.ArgIteratorGeneral(.{ .comments = true, .single_quotes = true });

/// Initialize the arguments from a Response File. "*.rsp"
fn initArgIteratorResponseFile(allocator: Allocator, resp_file_path: []const u8) !ArgIteratorResponseFile {
    const max_bytes = 10 * 1024 * 1024; // 10 MiB of command line arguments is a reasonable limit
    const cmd_line = try fs.cwd().readFileAlloc(allocator, resp_file_path, max_bytes);
    errdefer allocator.free(cmd_line);

    return ArgIteratorResponseFile.initTakeOwnership(allocator, cmd_line);
}

const clang_args = @import("clang_options.zig").list;

pub const ClangArgIterator = struct {
    has_next: bool,
    zig_equivalent: ZigEquivalent,
    only_arg: []const u8,
    second_arg: []const u8,
    other_args: []const []const u8,
    argv: []const []const u8,
    next_index: usize,
    root_args: ?*Args,
    arg_iterator_response_file: ArgIteratorResponseFile,
    arena: Allocator,

    pub const ZigEquivalent = enum {
        target,
        o,
        c,
        r,
        m,
        x,
        other,
        positional,
        l,
        ignore,
        driver_punt,
        pic,
        no_pic,
        pie,
        no_pie,
        lto,
        no_lto,
        unwind_tables,
        no_unwind_tables,
        nostdlib,
        nostdlib_cpp,
        shared,
        rdynamic,
        wl,
        wp,
        preprocess_only,
        asm_only,
        optimize,
        debug,
        gdwarf32,
        gdwarf64,
        sanitize,
        linker_script,
        dry_run,
        verbose,
        for_linker,
        linker_input_z,
        lib_dir,
        mcpu,
        dep_file,
        dep_file_to_stdout,
        framework_dir,
        framework,
        nostdlibinc,
        red_zone,
        no_red_zone,
        omit_frame_pointer,
        no_omit_frame_pointer,
        function_sections,
        no_function_sections,
        data_sections,
        no_data_sections,
        builtin,
        no_builtin,
        color_diagnostics,
        no_color_diagnostics,
        stack_check,
        no_stack_check,
        stack_protector,
        no_stack_protector,
        strip,
        exec_model,
        emit_llvm,
        sysroot,
        entry,
        force_undefined_symbol,
        weak_library,
        weak_framework,
        headerpad_max_install_names,
        compress_debug_sections,
        install_name,
        undefined,
        force_load_objc,
        mingw_unicode_entry_point,
        san_cov_trace_pc_guard,
        san_cov,
        no_san_cov,
        rtlib,
    };

    const Args = struct {
        next_index: usize,
        argv: []const []const u8,
    };

    fn init(arena: Allocator, argv: []const []const u8) ClangArgIterator {
        return .{
            .next_index = 2, // `zig cc foo` this points to `foo`
            .has_next = argv.len > 2,
            .zig_equivalent = undefined,
            .only_arg = undefined,
            .second_arg = undefined,
            .other_args = undefined,
            .argv = argv,
            .root_args = null,
            .arg_iterator_response_file = undefined,
            .arena = arena,
        };
    }

    fn next(self: *ClangArgIterator) !void {
        assert(self.has_next);
        assert(self.next_index < self.argv.len);
        // In this state we know that the parameter we are looking at is a root parameter
        // rather than an argument to a parameter.
        // We adjust the len below when necessary.
        self.other_args = (self.argv.ptr + self.next_index)[0..1];
        var arg = self.argv[self.next_index];
        self.incrementArgIndex();

        if (mem.startsWith(u8, arg, "@")) {
            if (self.root_args != null) return error.NestedResponseFile;

            // This is a "compiler response file". We must parse the file and treat its
            // contents as command line parameters.
            const arena = self.arena;
            const resp_file_path = arg[1..];

            self.arg_iterator_response_file =
                initArgIteratorResponseFile(arena, resp_file_path) catch |err| {
                fatal("unable to read response file '{s}': {s}", .{ resp_file_path, @errorName(err) });
            };
            // NOTE: The ArgIteratorResponseFile returns tokens from next() that are slices of an
            // internal buffer. This internal buffer is arena allocated, so it is not cleaned up here.

            var resp_arg_list = std.ArrayList([]const u8).init(arena);
            defer resp_arg_list.deinit();
            {
                while (self.arg_iterator_response_file.next()) |token| {
                    try resp_arg_list.append(token);
                }

                const args = try arena.create(Args);
                errdefer arena.destroy(args);
                args.* = .{
                    .next_index = self.next_index,
                    .argv = self.argv,
                };
                self.root_args = args;
            }
            const resp_arg_slice = try resp_arg_list.toOwnedSlice();
            self.next_index = 0;
            self.argv = resp_arg_slice;

            if (resp_arg_slice.len == 0) {
                self.resolveRespFileArgs();
                return;
            }

            self.has_next = true;
            self.other_args = (self.argv.ptr + self.next_index)[0..1]; // We adjust len below when necessary.
            arg = self.argv[self.next_index];
            self.incrementArgIndex();
        }

        if (mem.eql(u8, arg, "-") or !mem.startsWith(u8, arg, "-")) {
            self.zig_equivalent = .positional;
            self.only_arg = arg;
            return;
        }

        find_clang_arg: for (clang_args) |clang_arg| switch (clang_arg.syntax) {
            .flag => {
                const prefix_len = clang_arg.matchEql(arg);
                if (prefix_len > 0) {
                    self.zig_equivalent = clang_arg.zig_equivalent;
                    self.only_arg = arg[prefix_len..];

                    break :find_clang_arg;
                }
            },
            .joined, .comma_joined => {
                // joined example: --target=foo
                // comma_joined example: -Wl,-soname,libsoundio.so.2
                const prefix_len = clang_arg.matchStartsWith(arg);
                if (prefix_len != 0) {
                    self.zig_equivalent = clang_arg.zig_equivalent;
                    self.only_arg = arg[prefix_len..]; // This will skip over the "--target=" part.

                    break :find_clang_arg;
                }
            },
            .joined_or_separate => {
                // Examples: `-lfoo`, `-l foo`
                const prefix_len = clang_arg.matchStartsWith(arg);
                if (prefix_len == arg.len) {
                    if (self.next_index >= self.argv.len) {
                        fatal("Expected parameter after '{s}'", .{arg});
                    }
                    self.only_arg = self.argv[self.next_index];
                    self.incrementArgIndex();
                    self.other_args.len += 1;
                    self.zig_equivalent = clang_arg.zig_equivalent;

                    break :find_clang_arg;
                } else if (prefix_len != 0) {
                    self.zig_equivalent = clang_arg.zig_equivalent;
                    self.only_arg = arg[prefix_len..];

                    break :find_clang_arg;
                }
            },
            .joined_and_separate => {
                // Example: `-Xopenmp-target=riscv64-linux-unknown foo`
                const prefix_len = clang_arg.matchStartsWith(arg);
                if (prefix_len != 0) {
                    self.only_arg = arg[prefix_len..];
                    if (self.next_index >= self.argv.len) {
                        fatal("Expected parameter after '{s}'", .{arg});
                    }
                    self.second_arg = self.argv[self.next_index];
                    self.incrementArgIndex();
                    self.other_args.len += 1;
                    self.zig_equivalent = clang_arg.zig_equivalent;
                    break :find_clang_arg;
                }
            },
            .separate => if (clang_arg.matchEql(arg) > 0) {
                if (self.next_index >= self.argv.len) {
                    fatal("Expected parameter after '{s}'", .{arg});
                }
                self.only_arg = self.argv[self.next_index];
                self.incrementArgIndex();
                self.other_args.len += 1;
                self.zig_equivalent = clang_arg.zig_equivalent;
                break :find_clang_arg;
            },
            .remaining_args_joined => {
                const prefix_len = clang_arg.matchStartsWith(arg);
                if (prefix_len != 0) {
                    @panic("TODO");
                }
            },
            .multi_arg => |num_args| if (clang_arg.matchEql(arg) > 0) {
                // Example `-sectcreate <arg1> <arg2> <arg3>`.
                var i: usize = 0;
                while (i < num_args) : (i += 1) {
                    self.incrementArgIndex();
                    self.other_args.len += 1;
                }
                self.zig_equivalent = clang_arg.zig_equivalent;
                break :find_clang_arg;
            },
        } else {
            fatal("Unknown Clang option: '{s}'", .{arg});
        }
    }

    fn incrementArgIndex(self: *ClangArgIterator) void {
        self.next_index += 1;
        self.resolveRespFileArgs();
    }

    fn resolveRespFileArgs(self: *ClangArgIterator) void {
        const arena = self.arena;
        if (self.next_index >= self.argv.len) {
            if (self.root_args) |root_args| {
                self.next_index = root_args.next_index;
                self.argv = root_args.argv;

                arena.destroy(root_args);
                self.root_args = null;
            }
            if (self.next_index >= self.argv.len) {
                self.has_next = false;
            }
        }
    }
};

fn parseCodeModel(arg: []const u8) std.builtin.CodeModel {
    return std.meta.stringToEnum(std.builtin.CodeModel, arg) orelse
        fatal("unsupported machine code model: '{s}'", .{arg});
}

const usage_ast_check =
    \\Usage: zig ast-check [file]
    \\
    \\    Given a .zig source file, reports any compile errors that can be
    \\    ascertained on the basis of the source code alone, without target
    \\    information or type checking.
    \\
    \\    If [file] is omitted, stdin is used.
    \\
    \\Options:
    \\  -h, --help            Print this help and exit
    \\  --color [auto|off|on] Enable or disable colored error messages
    \\  -t                    (debug option) Output ZIR in text form to stdout
    \\
    \\
;

fn cmdAstCheck(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
) !void {
    dev.check(.ast_check_command);

    const Zir = std.zig.Zir;

    var color: Color = .auto;
    var want_output_text = false;
    var zig_source_file: ?[]const u8 = null;

    var i: usize = 0;
    while (i < args.len) : (i += 1) {
        const arg = args[i];
        if (mem.startsWith(u8, arg, "-")) {
            if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                try io.getStdOut().writeAll(usage_ast_check);
                return cleanExit();
            } else if (mem.eql(u8, arg, "-t")) {
                want_output_text = true;
            } else if (mem.eql(u8, arg, "--color")) {
                if (i + 1 >= args.len) {
                    fatal("expected [auto|on|off] after --color", .{});
                }
                i += 1;
                const next_arg = args[i];
                color = std.meta.stringToEnum(Color, next_arg) orelse {
                    fatal("expected [auto|on|off] after --color, found '{s}'", .{next_arg});
                };
            } else {
                fatal("unrecognized parameter: '{s}'", .{arg});
            }
        } else if (zig_source_file == null) {
            zig_source_file = arg;
        } else {
            fatal("extra positional parameter: '{s}'", .{arg});
        }
    }

    var file: Zcu.File = .{
        .status = .never_loaded,
        .source_loaded = false,
        .tree_loaded = false,
        .zir_loaded = false,
        .sub_file_path = undefined,
        .source = undefined,
        .stat = undefined,
        .tree = undefined,
        .zir = undefined,
        .mod = undefined,
    };
    if (zig_source_file) |file_name| {
        var f = fs.cwd().openFile(file_name, .{}) catch |err| {
            fatal("unable to open file for ast-check '{s}': {s}", .{ file_name, @errorName(err) });
        };
        defer f.close();

        const stat = try f.stat();

        if (stat.size > std.zig.max_src_size)
            return error.FileTooBig;

        const source = try arena.allocSentinel(u8, @as(usize, @intCast(stat.size)), 0);
        const amt = try f.readAll(source);
        if (amt != stat.size)
            return error.UnexpectedEndOfFile;

        file.sub_file_path = file_name;
        file.source = source;
        file.source_loaded = true;
        file.stat = .{
            .size = stat.size,
            .inode = stat.inode,
            .mtime = stat.mtime,
        };
    } else {
        const stdin = io.getStdIn();
        const source = std.zig.readSourceFileToEndAlloc(arena, stdin, null) catch |err| {
            fatal("unable to read stdin: {}", .{err});
        };
        file.sub_file_path = "<stdin>";
        file.source = source;
        file.source_loaded = true;
        file.stat.size = source.len;
    }

    file.mod = try Package.Module.createLimited(arena, .{
        .root = Cache.Path.cwd(),
        .root_src_path = file.sub_file_path,
        .fully_qualified_name = "root",
    });

    file.tree = try Ast.parse(gpa, file.source, .zig);
    file.tree_loaded = true;
    defer file.tree.deinit(gpa);

    file.zir = try AstGen.generate(gpa, file.tree);
    file.zir_loaded = true;
    defer file.zir.deinit(gpa);

    if (file.zir.hasCompileErrors()) {
        var wip_errors: std.zig.ErrorBundle.Wip = undefined;
        try wip_errors.init(gpa);
        defer wip_errors.deinit();
        try Compilation.addZirErrorMessages(&wip_errors, &file);
        var error_bundle = try wip_errors.toOwnedBundle("");
        defer error_bundle.deinit(gpa);
        error_bundle.renderToStdErr(color.renderOptions());
        process.exit(1);
    }

    if (!want_output_text) {
        return cleanExit();
    }
    if (!build_options.enable_debug_extensions) {
        fatal("-t option only available in builds of zig with debug extensions", .{});
    }

    {
        const token_bytes = @sizeOf(Ast.TokenList) +
            file.tree.tokens.len * (@sizeOf(std.zig.Token.Tag) + @sizeOf(Ast.ByteOffset));
        const tree_bytes = @sizeOf(Ast) + file.tree.nodes.len *
            (@sizeOf(Ast.Node.Tag) +
            @sizeOf(Ast.Node.Data) +
            @sizeOf(Ast.TokenIndex));
        const instruction_bytes = file.zir.instructions.len *
            // Here we don't use @sizeOf(Zir.Inst.Data) because it would include
            // the debug safety tag but we want to measure release size.
            (@sizeOf(Zir.Inst.Tag) + 8);
        const extra_bytes = file.zir.extra.len * @sizeOf(u32);
        const total_bytes = @sizeOf(Zir) + instruction_bytes + extra_bytes +
            file.zir.string_bytes.len * @sizeOf(u8);
        const stdout = io.getStdOut();
        const fmtIntSizeBin = std.fmt.fmtIntSizeBin;
        // zig fmt: off
        try stdout.writer().print(
            \\# Source bytes:       {}
            \\# Tokens:             {} ({})
            \\# AST Nodes:          {} ({})
            \\# Total ZIR bytes:    {}
            \\# Instructions:       {d} ({})
            \\# String Table Bytes: {}
            \\# Extra Data Items:   {d} ({})
            \\
        , .{
            fmtIntSizeBin(file.source.len),
            file.tree.tokens.len, fmtIntSizeBin(token_bytes),
            file.tree.nodes.len, fmtIntSizeBin(tree_bytes),
            fmtIntSizeBin(total_bytes),
            file.zir.instructions.len, fmtIntSizeBin(instruction_bytes),
            fmtIntSizeBin(file.zir.string_bytes.len),
            file.zir.extra.len, fmtIntSizeBin(extra_bytes),
        });
        // zig fmt: on
    }

    return @import("print_zir.zig").renderAsTextToFile(gpa, &file, io.getStdOut());
}

fn cmdDetectCpu(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
) !void {
    dev.check(.detect_cpu_command);

    _ = gpa;
    _ = arena;

    const detect_cpu_usage =
        \\Usage: zig detect-cpu [--llvm]
        \\
        \\    Print the host CPU name and feature set to stdout.
        \\
        \\Options:
        \\  -h, --help                    Print this help and exit
        \\  --llvm                        Detect using LLVM API
        \\
    ;

    var use_llvm = false;

    {
        var i: usize = 0;
        while (i < args.len) : (i += 1) {
            const arg = args[i];
            if (mem.startsWith(u8, arg, "-")) {
                if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                    const stdout = io.getStdOut().writer();
                    try stdout.writeAll(detect_cpu_usage);
                    return cleanExit();
                } else if (mem.eql(u8, arg, "--llvm")) {
                    use_llvm = true;
                } else {
                    fatal("unrecognized parameter: '{s}'", .{arg});
                }
            } else {
                fatal("unexpected extra parameter: '{s}'", .{arg});
            }
        }
    }

    if (use_llvm) {
        if (!build_options.have_llvm)
            fatal("compiler does not use LLVM; cannot compare CPU features with LLVM", .{});

        const llvm = @import("codegen/llvm/bindings.zig");
        const name = llvm.GetHostCPUName() orelse fatal("LLVM could not figure out the host cpu name", .{});
        const features = llvm.GetHostCPUFeatures() orelse fatal("LLVM could not figure out the host cpu feature set", .{});
        const cpu = try detectNativeCpuWithLLVM(builtin.cpu.arch, name, features);
        try printCpu(cpu);
    } else {
        const host_target = std.zig.resolveTargetQueryOrFatal(.{});
        try printCpu(host_target.cpu);
    }
}

fn detectNativeCpuWithLLVM(
    arch: std.Target.Cpu.Arch,
    llvm_cpu_name_z: ?[*:0]const u8,
    llvm_cpu_features_opt: ?[*:0]const u8,
) !std.Target.Cpu {
    var result = std.Target.Cpu.baseline(arch);

    if (llvm_cpu_name_z) |cpu_name_z| {
        const llvm_cpu_name = mem.span(cpu_name_z);

        for (arch.allCpuModels()) |model| {
            const this_llvm_name = model.llvm_name orelse continue;
            if (mem.eql(u8, this_llvm_name, llvm_cpu_name)) {
                // Here we use the non-dependencies-populated set,
                // so that subtracting features later in this function
                // affect the prepopulated set.
                result = std.Target.Cpu{
                    .arch = arch,
                    .model = model,
                    .features = model.features,
                };
                break;
            }
        }
    }

    const all_features = arch.allFeaturesList();

    if (llvm_cpu_features_opt) |llvm_cpu_features| {
        var it = mem.tokenizeScalar(u8, mem.span(llvm_cpu_features), ',');
        while (it.next()) |decorated_llvm_feat| {
            var op: enum {
                add,
                sub,
            } = undefined;
            var llvm_feat: []const u8 = undefined;
            if (mem.startsWith(u8, decorated_llvm_feat, "+")) {
                op = .add;
                llvm_feat = decorated_llvm_feat[1..];
            } else if (mem.startsWith(u8, decorated_llvm_feat, "-")) {
                op = .sub;
                llvm_feat = decorated_llvm_feat[1..];
            } else {
                return error.InvalidLlvmCpuFeaturesFormat;
            }
            for (all_features, 0..) |feature, index_usize| {
                const this_llvm_name = feature.llvm_name orelse continue;
                if (mem.eql(u8, llvm_feat, this_llvm_name)) {
                    const index: std.Target.Cpu.Feature.Set.Index = @intCast(index_usize);
                    switch (op) {
                        .add => result.features.addFeature(index),
                        .sub => result.features.removeFeature(index),
                    }
                    break;
                }
            }
        }
    }

    result.features.populateDependencies(all_features);
    return result;
}

fn printCpu(cpu: std.Target.Cpu) !void {
    var bw = io.bufferedWriter(io.getStdOut().writer());
    const stdout = bw.writer();

    if (cpu.model.llvm_name) |llvm_name| {
        try stdout.print("{s}\n", .{llvm_name});
    }

    const all_features = cpu.arch.allFeaturesList();
    for (all_features, 0..) |feature, index_usize| {
        const llvm_name = feature.llvm_name orelse continue;
        const index: std.Target.Cpu.Feature.Set.Index = @intCast(index_usize);
        const is_enabled = cpu.features.isEnabled(index);
        const plus_or_minus = "-+"[@intFromBool(is_enabled)];
        try stdout.print("{c}{s}\n", .{ plus_or_minus, llvm_name });
    }

    try bw.flush();
}

fn cmdDumpLlvmInts(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
) !void {
    dev.check(.llvm_ints_command);

    _ = gpa;

    if (!build_options.have_llvm)
        fatal("compiler does not use LLVM; cannot dump LLVM integer sizes", .{});

    const triple = try arena.dupeZ(u8, args[0]);

    const llvm = @import("codegen/llvm/bindings.zig");

    for ([_]std.Target.Cpu.Arch{ .aarch64, .x86 }) |arch| {
        @import("codegen/llvm.zig").initializeLLVMTarget(arch);
    }

    const target: *llvm.Target = t: {
        var target: *llvm.Target = undefined;
        var error_message: [*:0]const u8 = undefined;
        if (llvm.Target.getFromTriple(triple, &target, &error_message) != .False) @panic("bad");
        break :t target;
    };
    const tm = llvm.TargetMachine.create(target, triple, null, null, .None, .Default, .Default, false, false, .Default, null);
    const dl = tm.createTargetDataLayout();
    const context = llvm.Context.create();

    var bw = io.bufferedWriter(io.getStdOut().writer());
    const stdout = bw.writer();

    for ([_]u16{ 1, 8, 16, 32, 64, 128, 256 }) |bits| {
        const int_type = context.intType(bits);
        const alignment = dl.abiAlignmentOfType(int_type);
        try stdout.print("LLVMABIAlignmentOfType(i{d}) == {d}\n", .{ bits, alignment });
    }

    try bw.flush();

    return cleanExit();
}

/// This is only enabled for debug builds.
fn cmdDumpZir(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
) !void {
    dev.check(.dump_zir_command);

    _ = arena;
    const Zir = std.zig.Zir;

    const cache_file = args[0];

    var f = fs.cwd().openFile(cache_file, .{}) catch |err| {
        fatal("unable to open zir cache file for dumping '{s}': {s}", .{ cache_file, @errorName(err) });
    };
    defer f.close();

    var file: Zcu.File = .{
        .status = .never_loaded,
        .source_loaded = false,
        .tree_loaded = false,
        .zir_loaded = true,
        .sub_file_path = undefined,
        .source = undefined,
        .stat = undefined,
        .tree = undefined,
        .zir = try Zcu.loadZirCache(gpa, f),
        .mod = undefined,
    };
    defer file.zir.deinit(gpa);

    {
        const instruction_bytes = file.zir.instructions.len *
            // Here we don't use @sizeOf(Zir.Inst.Data) because it would include
            // the debug safety tag but we want to measure release size.
            (@sizeOf(Zir.Inst.Tag) + 8);
        const extra_bytes = file.zir.extra.len * @sizeOf(u32);
        const total_bytes = @sizeOf(Zir) + instruction_bytes + extra_bytes +
            file.zir.string_bytes.len * @sizeOf(u8);
        const stdout = io.getStdOut();
        const fmtIntSizeBin = std.fmt.fmtIntSizeBin;
        // zig fmt: off
        try stdout.writer().print(
            \\# Total ZIR bytes:    {}
            \\# Instructions:       {d} ({})
            \\# String Table Bytes: {}
            \\# Extra Data Items:   {d} ({})
            \\
        , .{
            fmtIntSizeBin(total_bytes),
            file.zir.instructions.len, fmtIntSizeBin(instruction_bytes),
            fmtIntSizeBin(file.zir.string_bytes.len),
            file.zir.extra.len, fmtIntSizeBin(extra_bytes),
        });
        // zig fmt: on
    }

    return @import("print_zir.zig").renderAsTextToFile(gpa, &file, io.getStdOut());
}

/// This is only enabled for debug builds.
fn cmdChangelist(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
) !void {
    dev.check(.changelist_command);

    const color: Color = .auto;
    const Zir = std.zig.Zir;

    const old_source_file = args[0];
    const new_source_file = args[1];

    var f = fs.cwd().openFile(old_source_file, .{}) catch |err| {
        fatal("unable to open old source file for comparison '{s}': {s}", .{ old_source_file, @errorName(err) });
    };
    defer f.close();

    const stat = try f.stat();

    if (stat.size > std.zig.max_src_size)
        return error.FileTooBig;

    var file: Zcu.File = .{
        .status = .never_loaded,
        .source_loaded = false,
        .tree_loaded = false,
        .zir_loaded = false,
        .sub_file_path = old_source_file,
        .source = undefined,
        .stat = .{
            .size = stat.size,
            .inode = stat.inode,
            .mtime = stat.mtime,
        },
        .tree = undefined,
        .zir = undefined,
        .mod = undefined,
    };

    file.mod = try Package.Module.createLimited(arena, .{
        .root = Cache.Path.cwd(),
        .root_src_path = file.sub_file_path,
        .fully_qualified_name = "root",
    });

    const source = try arena.allocSentinel(u8, @as(usize, @intCast(stat.size)), 0);
    const amt = try f.readAll(source);
    if (amt != stat.size)
        return error.UnexpectedEndOfFile;
    file.source = source;
    file.source_loaded = true;

    file.tree = try Ast.parse(gpa, file.source, .zig);
    file.tree_loaded = true;
    defer file.tree.deinit(gpa);

    file.zir = try AstGen.generate(gpa, file.tree);
    file.zir_loaded = true;
    defer file.zir.deinit(gpa);

    if (file.zir.hasCompileErrors()) {
        var wip_errors: std.zig.ErrorBundle.Wip = undefined;
        try wip_errors.init(gpa);
        defer wip_errors.deinit();
        try Compilation.addZirErrorMessages(&wip_errors, &file);
        var error_bundle = try wip_errors.toOwnedBundle("");
        defer error_bundle.deinit(gpa);
        error_bundle.renderToStdErr(color.renderOptions());
        process.exit(1);
    }

    var new_f = fs.cwd().openFile(new_source_file, .{}) catch |err| {
        fatal("unable to open new source file for comparison '{s}': {s}", .{ new_source_file, @errorName(err) });
    };
    defer new_f.close();

    const new_stat = try new_f.stat();

    if (new_stat.size > std.zig.max_src_size)
        return error.FileTooBig;

    const new_source = try arena.allocSentinel(u8, @as(usize, @intCast(new_stat.size)), 0);
    const new_amt = try new_f.readAll(new_source);
    if (new_amt != new_stat.size)
        return error.UnexpectedEndOfFile;

    var new_tree = try Ast.parse(gpa, new_source, .zig);
    defer new_tree.deinit(gpa);

    var old_zir = file.zir;
    defer old_zir.deinit(gpa);
    file.zir_loaded = false;
    file.zir = try AstGen.generate(gpa, new_tree);
    file.zir_loaded = true;

    if (file.zir.hasCompileErrors()) {
        var wip_errors: std.zig.ErrorBundle.Wip = undefined;
        try wip_errors.init(gpa);
        defer wip_errors.deinit();
        try Compilation.addZirErrorMessages(&wip_errors, &file);
        var error_bundle = try wip_errors.toOwnedBundle("");
        defer error_bundle.deinit(gpa);
        error_bundle.renderToStdErr(color.renderOptions());
        process.exit(1);
    }

    var inst_map: std.AutoHashMapUnmanaged(Zir.Inst.Index, Zir.Inst.Index) = .empty;
    defer inst_map.deinit(gpa);

    try Zcu.mapOldZirToNew(gpa, old_zir, file.zir, &inst_map);

    var bw = io.bufferedWriter(io.getStdOut().writer());
    const stdout = bw.writer();
    {
        try stdout.print("Instruction mappings:\n", .{});
        var it = inst_map.iterator();
        while (it.next()) |entry| {
            try stdout.print(" %{d} => %{d}\n", .{
                @intFromEnum(entry.key_ptr.*),
                @intFromEnum(entry.value_ptr.*),
            });
        }
    }
    try bw.flush();
}

fn eatIntPrefix(arg: []const u8, base: u8) []const u8 {
    if (arg.len > 2 and arg[0] == '0') {
        switch (std.ascii.toLower(arg[1])) {
            'b' => if (base == 2) return arg[2..],
            'o' => if (base == 8) return arg[2..],
            'x' => if (base == 16) return arg[2..],
            else => {},
        }
    }
    return arg;
}

fn parseIntSuffix(arg: []const u8, prefix_len: usize) u64 {
    return std.fmt.parseUnsigned(u64, arg[prefix_len..], 0) catch |err| {
        fatal("unable to parse '{s}': {s}", .{ arg, @errorName(err) });
    };
}

fn warnAboutForeignBinaries(
    arena: Allocator,
    arg_mode: ArgMode,
    target: *const std.Target,
    link_libc: bool,
) !void {
    const host_query: std.Target.Query = .{};
    const host_target = std.zig.resolveTargetQueryOrFatal(host_query);

    switch (std.zig.system.getExternalExecutor(host_target, target, .{ .link_libc = link_libc })) {
        .native => return,
        .rosetta => {
            const host_name = try host_target.zigTriple(arena);
            const foreign_name = try target.zigTriple(arena);
            warn("the host system ({s}) does not appear to be capable of executing binaries from the target ({s}). Consider installing Rosetta.", .{
                host_name, foreign_name,
            });
        },
        .qemu => |qemu| {
            const host_name = try host_target.zigTriple(arena);
            const foreign_name = try target.zigTriple(arena);
            switch (arg_mode) {
                .zig_test => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '--test-cmd {s} --test-cmd-bin' " ++
                        "to run the tests",
                    .{ host_name, foreign_name, qemu },
                ),
                else => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '{s}' to run the binary",
                    .{ host_name, foreign_name, qemu },
                ),
            }
        },
        .wine => |wine| {
            const host_name = try host_target.zigTriple(arena);
            const foreign_name = try target.zigTriple(arena);
            switch (arg_mode) {
                .zig_test => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '--test-cmd {s} --test-cmd-bin' " ++
                        "to run the tests",
                    .{ host_name, foreign_name, wine },
                ),
                else => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '{s}' to run the binary",
                    .{ host_name, foreign_name, wine },
                ),
            }
        },
        .wasmtime => |wasmtime| {
            const host_name = try host_target.zigTriple(arena);
            const foreign_name = try target.zigTriple(arena);
            switch (arg_mode) {
                .zig_test => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '--test-cmd {s} --test-cmd-bin' " ++
                        "to run the tests",
                    .{ host_name, foreign_name, wasmtime },
                ),
                else => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '{s}' to run the binary",
                    .{ host_name, foreign_name, wasmtime },
                ),
            }
        },
        .darling => |darling| {
            const host_name = try host_target.zigTriple(arena);
            const foreign_name = try target.zigTriple(arena);
            switch (arg_mode) {
                .zig_test => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '--test-cmd {s} --test-cmd-bin' " ++
                        "to run the tests",
                    .{ host_name, foreign_name, darling },
                ),
                else => warn(
                    "the host system ({s}) does not appear to be capable of executing binaries " ++
                        "from the target ({s}). Consider using '{s}' to run the binary",
                    .{ host_name, foreign_name, darling },
                ),
            }
        },
        .bad_dl => |foreign_dl| {
            const host_dl = host_target.dynamic_linker.get() orelse "(none)";
            const tip_suffix = switch (arg_mode) {
                .zig_test => ", '--test-no-exec', or '--test-cmd'",
                else => "",
            };
            warn("the host system does not appear to be capable of executing binaries from the target because the host dynamic linker is '{s}', while the target dynamic linker is '{s}'. Consider using '--dynamic-linker'{s}", .{
                host_dl, foreign_dl, tip_suffix,
            });
        },
        .bad_os_or_cpu => {
            const host_name = try host_target.zigTriple(arena);
            const foreign_name = try target.zigTriple(arena);
            const tip_suffix = switch (arg_mode) {
                .zig_test => ". Consider using '--test-no-exec' or '--test-cmd'",
                else => "",
            };
            warn("the host system ({s}) does not appear to be capable of executing binaries from the target ({s}){s}", .{
                host_name, foreign_name, tip_suffix,
            });
        },
    }
}

fn parseSubSystem(next_arg: []const u8) !std.Target.SubSystem {
    if (mem.eql(u8, next_arg, "console")) {
        return .Console;
    } else if (mem.eql(u8, next_arg, "windows")) {
        return .Windows;
    } else if (mem.eql(u8, next_arg, "posix")) {
        return .Posix;
    } else if (mem.eql(u8, next_arg, "native")) {
        return .Native;
    } else if (mem.eql(u8, next_arg, "efi_application")) {
        return .EfiApplication;
    } else if (mem.eql(u8, next_arg, "efi_boot_service_driver")) {
        return .EfiBootServiceDriver;
    } else if (mem.eql(u8, next_arg, "efi_rom")) {
        return .EfiRom;
    } else if (mem.eql(u8, next_arg, "efi_runtime_driver")) {
        return .EfiRuntimeDriver;
    } else {
        fatal("invalid: --subsystem: '{s}'. Options are:\n{s}", .{
            next_arg,
            \\  console
            \\  windows
            \\  posix
            \\  native
            \\  efi_application
            \\  efi_boot_service_driver
            \\  efi_rom
            \\  efi_runtime_driver
            \\
        });
    }
}

/// Model a header searchlist as a group.
/// Silently ignore superfluous search dirs.
/// Warn when a dir is added to multiple searchlists.
const ClangSearchSanitizer = struct {
    map: std.StringHashMapUnmanaged(Membership) = .empty,

    fn reset(self: *@This()) void {
        self.map.clearRetainingCapacity();
    }

    fn addIncludePath(
        self: *@This(),
        ally: Allocator,
        argv: *std.ArrayListUnmanaged([]const u8),
        group: Group,
        arg: []const u8,
        dir: []const u8,
        joined: bool,
    ) !void {
        const gopr = try self.map.getOrPut(ally, dir);
        const m = gopr.value_ptr;
        if (!gopr.found_existing) {
            // init empty membership
            m.* = .{};
        }
        const wtxt = "add '{s}' to header searchlist '-{s}' conflicts with '-{s}'";
        switch (group) {
            .I => {
                if (m.I) return;
                m.I = true;
                if (m.isystem) warn(wtxt, .{ dir, "I", "isystem" });
                if (m.idirafter) warn(wtxt, .{ dir, "I", "idirafter" });
                if (m.iframework) warn(wtxt, .{ dir, "I", "iframework" });
            },
            .isystem => {
                if (m.isystem) return;
                m.isystem = true;
                if (m.I) warn(wtxt, .{ dir, "isystem", "I" });
                if (m.idirafter) warn(wtxt, .{ dir, "isystem", "idirafter" });
                if (m.iframework) warn(wtxt, .{ dir, "isystem", "iframework" });
            },
            .iwithsysroot => {
                if (m.iwithsysroot) return;
                m.iwithsysroot = true;
                if (m.iframeworkwithsysroot) warn(wtxt, .{ dir, "iwithsysroot", "iframeworkwithsysroot" });
            },
            .idirafter => {
                if (m.idirafter) return;
                m.idirafter = true;
                if (m.I) warn(wtxt, .{ dir, "idirafter", "I" });
                if (m.isystem) warn(wtxt, .{ dir, "idirafter", "isystem" });
                if (m.iframework) warn(wtxt, .{ dir, "idirafter", "iframework" });
            },
            .iframework => {
                if (m.iframework) return;
                m.iframework = true;
                if (m.I) warn(wtxt, .{ dir, "iframework", "I" });
                if (m.isystem) warn(wtxt, .{ dir, "iframework", "isystem" });
                if (m.idirafter) warn(wtxt, .{ dir, "iframework", "idirafter" });
            },
            .iframeworkwithsysroot => {
                if (m.iframeworkwithsysroot) return;
                m.iframeworkwithsysroot = true;
                if (m.iwithsysroot) warn(wtxt, .{ dir, "iframeworkwithsysroot", "iwithsysroot" });
            },
        }
        try argv.ensureUnusedCapacity(ally, 2);
        argv.appendAssumeCapacity(arg);
        if (!joined) argv.appendAssumeCapacity(dir);
    }

    const Group = enum { I, isystem, iwithsysroot, idirafter, iframework, iframeworkwithsysroot };

    const Membership = packed struct {
        I: bool = false,
        isystem: bool = false,
        iwithsysroot: bool = false,
        idirafter: bool = false,
        iframework: bool = false,
        iframeworkwithsysroot: bool = false,
    };
};

fn accessLibPath(
    test_path: *std.ArrayList(u8),
    checked_paths: *std.ArrayList(u8),
    lib_dir_path: []const u8,
    lib_name: []const u8,
    target: std.Target,
    link_mode: std.builtin.LinkMode,
) !bool {
    const sep = fs.path.sep_str;

    if (target.isDarwin() and link_mode == .dynamic) tbd: {
        // Prefer .tbd over .dylib.
        test_path.clearRetainingCapacity();
        try test_path.writer().print("{s}" ++ sep ++ "lib{s}.tbd", .{ lib_dir_path, lib_name });
        try checked_paths.writer().print("\n  {s}", .{test_path.items});
        fs.cwd().access(test_path.items, .{}) catch |err| switch (err) {
            error.FileNotFound => break :tbd,
            else => |e| fatal("unable to search for tbd library '{s}': {s}", .{
                test_path.items, @errorName(e),
            }),
        };
        return true;
    }

    main_check: {
        test_path.clearRetainingCapacity();
        try test_path.writer().print("{s}" ++ sep ++ "{s}{s}{s}", .{
            lib_dir_path,
            target.libPrefix(),
            lib_name,
            switch (link_mode) {
                .static => target.staticLibSuffix(),
                .dynamic => target.dynamicLibSuffix(),
            },
        });
        try checked_paths.writer().print("\n  {s}", .{test_path.items});
        fs.cwd().access(test_path.items, .{}) catch |err| switch (err) {
            error.FileNotFound => break :main_check,
            else => |e| fatal("unable to search for {s} library '{s}': {s}", .{
                @tagName(link_mode), test_path.items, @errorName(e),
            }),
        };
        return true;
    }

    // In the case of Darwin, the main check will be .dylib, so here we
    // additionally check for .so files.
    if (target.isDarwin() and link_mode == .dynamic) so: {
        test_path.clearRetainingCapacity();
        try test_path.writer().print("{s}" ++ sep ++ "lib{s}.so", .{ lib_dir_path, lib_name });
        try checked_paths.writer().print("\n  {s}", .{test_path.items});
        fs.cwd().access(test_path.items, .{}) catch |err| switch (err) {
            error.FileNotFound => break :so,
            else => |e| fatal("unable to search for so library '{s}': {s}", .{
                test_path.items, @errorName(e),
            }),
        };
        return true;
    }

    // In the case of MinGW, the main check will be .lib but we also need to
    // look for `libfoo.a`.
    if (target.isMinGW() and link_mode == .static) mingw: {
        test_path.clearRetainingCapacity();
        try test_path.writer().print("{s}" ++ sep ++ "lib{s}.a", .{
            lib_dir_path, lib_name,
        });
        try checked_paths.writer().print("\n  {s}", .{test_path.items});
        fs.cwd().access(test_path.items, .{}) catch |err| switch (err) {
            error.FileNotFound => break :mingw,
            else => |e| fatal("unable to search for static library '{s}': {s}", .{
                test_path.items, @errorName(e),
            }),
        };
        return true;
    }

    return false;
}

fn accessFrameworkPath(
    test_path: *std.ArrayList(u8),
    checked_paths: *std.ArrayList(u8),
    framework_dir_path: []const u8,
    framework_name: []const u8,
) !bool {
    const sep = fs.path.sep_str;

    for (&[_][]const u8{ ".tbd", ".dylib", "" }) |ext| {
        test_path.clearRetainingCapacity();
        try test_path.writer().print("{s}" ++ sep ++ "{s}.framework" ++ sep ++ "{s}{s}", .{
            framework_dir_path,
            framework_name,
            framework_name,
            ext,
        });
        try checked_paths.writer().print("\n {s}", .{test_path.items});
        fs.cwd().access(test_path.items, .{}) catch |err| switch (err) {
            error.FileNotFound => continue,
            else => |e| fatal("unable to search for {s} framework '{s}': {s}", .{
                ext, test_path.items, @errorName(e),
            }),
        };
        return true;
    }

    return false;
}

fn parseRcIncludes(arg: []const u8) Compilation.RcIncludes {
    return std.meta.stringToEnum(Compilation.RcIncludes, arg) orelse
        fatal("unsupported rc includes type: '{s}'", .{arg});
}

const usage_fetch =
    \\Usage: zig fetch [options] <url>
    \\Usage: zig fetch [options] <path>
    \\
    \\    Copy a package into the global cache and print its hash.
    \\
    \\Options:
    \\  -h, --help                    Print this help and exit
    \\  --global-cache-dir [path]     Override path to global Zig cache directory
    \\  --debug-hash                  Print verbose hash information to stdout
    \\  --save                        Add the fetched package to build.zig.zon
    \\  --save=[name]                 Add the fetched package to build.zig.zon as name
    \\  --save-exact                  Add the fetched package to build.zig.zon, storing the URL verbatim
    \\  --save-exact=[name]           Add the fetched package to build.zig.zon as name, storing the URL verbatim
    \\
;

fn cmdFetch(
    gpa: Allocator,
    arena: Allocator,
    args: []const []const u8,
) !void {
    dev.check(.fetch_command);

    const color: Color = .auto;
    const work_around_btrfs_bug = native_os == .linux and
        EnvVar.ZIG_BTRFS_WORKAROUND.isSet();
    var opt_path_or_url: ?[]const u8 = null;
    var override_global_cache_dir: ?[]const u8 = try EnvVar.ZIG_GLOBAL_CACHE_DIR.get(arena);
    var debug_hash: bool = false;
    var save: union(enum) {
        no,
        yes: ?[]const u8,
        exact: ?[]const u8,
    } = .no;

    {
        var i: usize = 0;
        while (i < args.len) : (i += 1) {
            const arg = args[i];
            if (mem.startsWith(u8, arg, "-")) {
                if (mem.eql(u8, arg, "-h") or mem.eql(u8, arg, "--help")) {
                    const stdout = io.getStdOut().writer();
                    try stdout.writeAll(usage_fetch);
                    return cleanExit();
                } else if (mem.eql(u8, arg, "--global-cache-dir")) {
                    if (i + 1 >= args.len) fatal("expected argument after '{s}'", .{arg});
                    i += 1;
                    override_global_cache_dir = args[i];
                } else if (mem.eql(u8, arg, "--debug-hash")) {
                    debug_hash = true;
                } else if (mem.eql(u8, arg, "--save")) {
                    save = .{ .yes = null };
                } else if (mem.startsWith(u8, arg, "--save=")) {
                    save = .{ .yes = arg["--save=".len..] };
                } else if (mem.eql(u8, arg, "--save-exact")) {
                    save = .{ .exact = null };
                } else if (mem.startsWith(u8, arg, "--save-exact=")) {
                    save = .{ .exact = arg["--save-exact=".len..] };
                } else {
                    fatal("unrecognized parameter: '{s}'", .{arg});
                }
            } else if (opt_path_or_url != null) {
                fatal("unexpected extra parameter: '{s}'", .{arg});
            } else {
                opt_path_or_url = arg;
            }
        }
    }

    const path_or_url = opt_path_or_url orelse fatal("missing url or path parameter", .{});

    var thread_pool: ThreadPool = undefined;
    try thread_pool.init(.{ .allocator = gpa });
    defer thread_pool.deinit();

    var http_client: std.http.Client = .{ .allocator = gpa };
    defer http_client.deinit();

    try http_client.initDefaultProxies(arena);

    var root_prog_node = std.Progress.start(.{
        .root_name = "Fetch",
    });
    defer root_prog_node.end();

    var global_cache_directory: Compilation.Directory = l: {
        const p = override_global_cache_dir orelse try introspect.resolveGlobalCacheDir(arena);
        break :l .{
            .handle = try fs.cwd().makeOpenPath(p, .{}),
            .path = p,
        };
    };
    defer global_cache_directory.handle.close();

    var job_queue: Package.Fetch.JobQueue = .{
        .http_client = &http_client,
        .thread_pool = &thread_pool,
        .global_cache = global_cache_directory,
        .recursive = false,
        .read_only = false,
        .debug_hash = debug_hash,
        .work_around_btrfs_bug = work_around_btrfs_bug,
    };
    defer job_queue.deinit();

    var fetch: Package.Fetch = .{
        .arena = std.heap.ArenaAllocator.init(gpa),
        .location = .{ .path_or_url = path_or_url },
        .location_tok = 0,
        .hash_tok = 0,
        .name_tok = 0,
        .lazy_status = .eager,
        .parent_package_root = undefined,
        .parent_manifest_ast = null,
        .prog_node = root_prog_node,
        .job_queue = &job_queue,
        .omit_missing_hash_error = true,
        .allow_missing_paths_field = false,
        .use_latest_commit = true,

        .package_root = undefined,
        .error_bundle = undefined,
        .manifest = null,
        .manifest_ast = undefined,
        .actual_hash = undefined,
        .has_build_zig = false,
        .oom_flag = false,
        .latest_commit = null,

        .module = null,
    };
    defer fetch.deinit();

    fetch.run() catch |err| switch (err) {
        error.OutOfMemory => fatal("out of memory", .{}),
        error.FetchFailed => {}, // error bundle checked below
    };

    if (fetch.error_bundle.root_list.items.len > 0) {
        var errors = try fetch.error_bundle.toOwnedBundle("");
        errors.renderToStdErr(color.renderOptions());
        process.exit(1);
    }

    const hex_digest = Package.Manifest.hexDigest(fetch.actual_hash);

    root_prog_node.end();
    root_prog_node = .{ .index = .none };

    const name = switch (save) {
        .no => {
            try io.getStdOut().writeAll(hex_digest ++ "\n");
            return cleanExit();
        },
        .yes, .exact => |name| name: {
            if (name) |n| break :name n;
            const fetched_manifest = fetch.manifest orelse
                fatal("unable to determine name; fetched package has no build.zig.zon file", .{});
            break :name fetched_manifest.name;
        },
    };

    const cwd_path = try process.getCwdAlloc(arena);

    var build_root = try findBuildRoot(arena, .{
        .cwd_path = cwd_path,
    });
    defer build_root.deinit();

    // The name to use in case the manifest file needs to be created now.
    const init_root_name = fs.path.basename(build_root.directory.path orelse cwd_path);
    var manifest, var ast = try loadManifest(gpa, arena, .{
        .root_name = init_root_name,
        .dir = build_root.directory.handle,
        .color = color,
    });
    defer {
        manifest.deinit(gpa);
        ast.deinit(gpa);
    }

    var fixups: Ast.Fixups = .{};
    defer fixups.deinit(gpa);

    var saved_path_or_url = path_or_url;

    if (fetch.latest_commit) |*latest_commit| resolved: {
        const latest_commit_hex = try std.fmt.allocPrint(arena, "{}", .{std.fmt.fmtSliceHexLower(latest_commit)});

        var uri = try std.Uri.parse(path_or_url);

        if (uri.fragment) |fragment| {
            const target_ref = try fragment.toRawMaybeAlloc(arena);

            // the refspec may already be fully resolved
            if (std.mem.eql(u8, target_ref, latest_commit_hex)) break :resolved;

            std.log.info("resolved ref '{s}' to commit {s}", .{ target_ref, latest_commit_hex });

            // include the original refspec in a query parameter, could be used to check for updates
            uri.query = .{ .percent_encoded = try std.fmt.allocPrint(arena, "ref={%}", .{fragment}) };
        } else {
            std.log.info("resolved to commit {s}", .{latest_commit_hex});
        }

        // replace the refspec with the resolved commit SHA
        uri.fragment = .{ .raw = latest_commit_hex };

        switch (save) {
            .yes => saved_path_or_url = try std.fmt.allocPrint(arena, "{}", .{uri}),
            .no, .exact => {}, // keep the original URL
        }
    }

    const new_node_init = try std.fmt.allocPrint(arena,
        \\.{{
        \\            .url = "{}",
        \\            .hash = "{}",
        \\        }}
    , .{
        std.zig.fmtEscapes(saved_path_or_url),
        std.zig.fmtEscapes(&hex_digest),
    });

    const new_node_text = try std.fmt.allocPrint(arena, ".{p_} = {s},\n", .{
        std.zig.fmtId(name), new_node_init,
    });

    const dependencies_init = try std.fmt.allocPrint(arena, ".{{\n        {s}    }}", .{
        new_node_text,
    });

    const dependencies_text = try std.fmt.allocPrint(arena, ".dependencies = {s},\n", .{
        dependencies_init,
    });

    if (manifest.dependencies.get(name)) |dep| {
        if (dep.hash) |h| {
            switch (dep.location) {
                .url => |u| {
                    if (mem.eql(u8, h, &hex_digest) and mem.eql(u8, u, saved_path_or_url)) {
                        std.log.info("existing dependency named '{s}' is up-to-date", .{name});
                        process.exit(0);
                    }
                },
                .path => {},
            }
        }
        warn("overwriting existing dependency named '{s}'", .{name});
        try fixups.replace_nodes_with_string.put(gpa, dep.node, new_node_init);
    } else if (manifest.dependencies.count() > 0) {
        // Add fixup for adding another dependency.
        const deps = manifest.dependencies.values();
        const last_dep_node = deps[deps.len - 1].node;
        try fixups.append_string_after_node.put(gpa, last_dep_node, new_node_text);
    } else if (manifest.dependencies_node != 0) {
        // Add fixup for replacing the entire dependencies struct.
        try fixups.replace_nodes_with_string.put(gpa, manifest.dependencies_node, dependencies_init);
    } else {
        // Add fixup for adding dependencies struct.
        try fixups.append_string_after_node.put(gpa, manifest.version_node, dependencies_text);
    }

    var rendered = std.ArrayList(u8).init(gpa);
    defer rendered.deinit();
    try ast.renderToArrayList(&rendered, fixups);

    build_root.directory.handle.writeFile(.{ .sub_path = Package.Manifest.basename, .data = rendered.items }) catch |err| {
        fatal("unable to write {s} file: {s}", .{ Package.Manifest.basename, @errorName(err) });
    };

    return cleanExit();
}

fn createEmptyDependenciesModule(
    arena: Allocator,
    main_mod: *Package.Module,
    global_cache_directory: Cache.Directory,
    local_cache_directory: Cache.Directory,
    builtin_mod: *Package.Module,
    global_options: Compilation.Config,
) !void {
    var source = std.ArrayList(u8).init(arena);
    try Package.Fetch.JobQueue.createEmptyDependenciesSource(&source);
    _ = try createDependenciesModule(
        arena,
        source.items,
        main_mod,
        global_cache_directory,
        local_cache_directory,
        builtin_mod,
        global_options,
    );
}

/// Creates the dependencies.zig file and corresponding `Package.Module` for the
/// build runner to obtain via `@import("@dependencies")`.
fn createDependenciesModule(
    arena: Allocator,
    source: []const u8,
    main_mod: *Package.Module,
    global_cache_directory: Cache.Directory,
    local_cache_directory: Cache.Directory,
    builtin_mod: *Package.Module,
    global_options: Compilation.Config,
) !*Package.Module {
    // Atomically create the file in a directory named after the hash of its contents.
    const basename = "dependencies.zig";
    const rand_int = std.crypto.random.int(u64);
    const tmp_dir_sub_path = "tmp" ++ fs.path.sep_str ++ std.fmt.hex(rand_int);
    {
        var tmp_dir = try local_cache_directory.handle.makeOpenPath(tmp_dir_sub_path, .{});
        defer tmp_dir.close();
        try tmp_dir.writeFile(.{ .sub_path = basename, .data = source });
    }

    var hh: Cache.HashHelper = .{};
    hh.addBytes(build_options.version);
    hh.addBytes(source);
    const hex_digest = hh.final();

    const o_dir_sub_path = try arena.dupe(u8, "o" ++ fs.path.sep_str ++ hex_digest);
    try Package.Fetch.renameTmpIntoCache(
        local_cache_directory.handle,
        tmp_dir_sub_path,
        o_dir_sub_path,
    );

    const deps_mod = try Package.Module.create(arena, .{
        .global_cache_directory = global_cache_directory,
        .paths = .{
            .root = .{
                .root_dir = local_cache_directory,
                .sub_path = o_dir_sub_path,
            },
            .root_src_path = basename,
        },
        .fully_qualified_name = "root.@dependencies",
        .parent = main_mod,
        .cc_argv = &.{},
        .inherited = .{},
        .global = global_options,
        .builtin_mod = builtin_mod,
        .builtin_modules = null, // `builtin_mod` is specified
    });
    try main_mod.deps.put(arena, "@dependencies", deps_mod);
    return deps_mod;
}

const BuildRoot = struct {
    directory: Cache.Directory,
    build_zig_basename: []const u8,
    cleanup_build_dir: ?fs.Dir,

    fn deinit(br: *BuildRoot) void {
        if (br.cleanup_build_dir) |*dir| dir.close();
        br.* = undefined;
    }
};

const FindBuildRootOptions = struct {
    build_file: ?[]const u8 = null,
    cwd_path: ?[]const u8 = null,
};

fn findBuildRoot(arena: Allocator, options: FindBuildRootOptions) !BuildRoot {
    const cwd_path = options.cwd_path orelse try process.getCwdAlloc(arena);
    const build_zig_basename = if (options.build_file) |bf|
        fs.path.basename(bf)
    else
        Package.build_zig_basename;

    if (options.build_file) |bf| {
        if (fs.path.dirname(bf)) |dirname| {
            const dir = fs.cwd().openDir(dirname, .{}) catch |err| {
                fatal("unable to open directory to build file from argument 'build-file', '{s}': {s}", .{ dirname, @errorName(err) });
            };
            return .{
                .build_zig_basename = build_zig_basename,
                .directory = .{ .path = dirname, .handle = dir },
                .cleanup_build_dir = dir,
            };
        }

        return .{
            .build_zig_basename = build_zig_basename,
            .directory = .{ .path = null, .handle = fs.cwd() },
            .cleanup_build_dir = null,
        };
    }
    // Search up parent directories until we find build.zig.
    var dirname: []const u8 = cwd_path;
    while (true) {
        const joined_path = try fs.path.join(arena, &[_][]const u8{ dirname, build_zig_basename });
        if (fs.cwd().access(joined_path, .{})) |_| {
            const dir = fs.cwd().openDir(dirname, .{}) catch |err| {
                fatal("unable to open directory while searching for build.zig file, '{s}': {s}", .{ dirname, @errorName(err) });
            };
            return .{
                .build_zig_basename = build_zig_basename,
                .directory = .{
                    .path = dirname,
                    .handle = dir,
                },
                .cleanup_build_dir = dir,
            };
        } else |err| switch (err) {
            error.FileNotFound => {
                dirname = fs.path.dirname(dirname) orelse {
                    std.log.info("initialize {s} template file with 'zig init'", .{
                        Package.build_zig_basename,
                    });
                    std.log.info("see 'zig --help' for more options", .{});
                    fatal("no build.zig file found, in the current directory or any parent directories", .{});
                };
                continue;
            },
            else => |e| return e,
        }
    }
}

const LoadManifestOptions = struct {
    root_name: []const u8,
    dir: fs.Dir,
    color: Color,
};

fn loadManifest(
    gpa: Allocator,
    arena: Allocator,
    options: LoadManifestOptions,
) !struct { Package.Manifest, Ast } {
    const manifest_bytes = while (true) {
        break options.dir.readFileAllocOptions(
            arena,
            Package.Manifest.basename,
            Package.Manifest.max_bytes,
            null,
            1,
            0,
        ) catch |err| switch (err) {
            error.FileNotFound => {
                var templates = findTemplates(gpa, arena);
                defer templates.deinit();

                templates.write(arena, options.dir, options.root_name, Package.Manifest.basename) catch |e| {
                    fatal("unable to write {s}: {s}", .{
                        Package.Manifest.basename, @errorName(e),
                    });
                };
                continue;
            },
            else => |e| fatal("unable to load {s}: {s}", .{
                Package.Manifest.basename, @errorName(e),
            }),
        };
    };
    var ast = try Ast.parse(gpa, manifest_bytes, .zon);
    errdefer ast.deinit(gpa);

    if (ast.errors.len > 0) {
        try std.zig.printAstErrorsToStderr(gpa, ast, Package.Manifest.basename, options.color);
        process.exit(2);
    }

    var manifest = try Package.Manifest.parse(gpa, ast, .{});
    errdefer manifest.deinit(gpa);

    if (manifest.errors.len > 0) {
        var wip_errors: std.zig.ErrorBundle.Wip = undefined;
        try wip_errors.init(gpa);
        defer wip_errors.deinit();

        const src_path = try wip_errors.addString(Package.Manifest.basename);
        try manifest.copyErrorsIntoBundle(ast, src_path, &wip_errors);

        var error_bundle = try wip_errors.toOwnedBundle("");
        defer error_bundle.deinit(gpa);
        error_bundle.renderToStdErr(options.color.renderOptions());

        process.exit(2);
    }
    return .{ manifest, ast };
}

const Templates = struct {
    zig_lib_directory: Cache.Directory,
    dir: fs.Dir,
    buffer: std.ArrayList(u8),

    fn deinit(templates: *Templates) void {
        templates.zig_lib_directory.handle.close();
        templates.dir.close();
        templates.buffer.deinit();
        templates.* = undefined;
    }

    fn write(
        templates: *Templates,
        arena: Allocator,
        out_dir: fs.Dir,
        root_name: []const u8,
        template_path: []const u8,
    ) !void {
        if (fs.path.dirname(template_path)) |dirname| {
            out_dir.makePath(dirname) catch |err| {
                fatal("unable to make path '{s}': {s}", .{ dirname, @errorName(err) });
            };
        }

        const max_bytes = 10 * 1024 * 1024;
        const contents = templates.dir.readFileAlloc(arena, template_path, max_bytes) catch |err| {
            fatal("unable to read template file '{s}': {s}", .{ template_path, @errorName(err) });
        };
        templates.buffer.clearRetainingCapacity();
        try templates.buffer.ensureUnusedCapacity(contents.len);
        for (contents) |c| {
            if (c == '$') {
                try templates.buffer.appendSlice(root_name);
            } else {
                try templates.buffer.append(c);
            }
        }

        return out_dir.writeFile(.{
            .sub_path = template_path,
            .data = templates.buffer.items,
            .flags = .{ .exclusive = true },
        });
    }
};

fn findTemplates(gpa: Allocator, arena: Allocator) Templates {
    const self_exe_path = introspect.findZigExePath(arena) catch |err| {
        fatal("unable to find self exe path: {s}", .{@errorName(err)});
    };
    var zig_lib_directory = introspect.findZigLibDirFromSelfExe(arena, self_exe_path) catch |err| {
        fatal("unable to find zig installation directory '{s}': {s}", .{ self_exe_path, @errorName(err) });
    };

    const s = fs.path.sep_str;
    const template_sub_path = "init";
    const template_dir = zig_lib_directory.handle.openDir(template_sub_path, .{}) catch |err| {
        const path = zig_lib_directory.path orelse ".";
        fatal("unable to open zig project template directory '{s}{s}{s}': {s}", .{
            path, s, template_sub_path, @errorName(err),
        });
    };

    return .{
        .zig_lib_directory = zig_lib_directory,
        .dir = template_dir,
        .buffer = std.ArrayList(u8).init(gpa),
    };
}

fn parseOptimizeMode(s: []const u8) std.builtin.OptimizeMode {
    return std.meta.stringToEnum(std.builtin.OptimizeMode, s) orelse
        fatal("unrecognized optimization mode: '{s}'", .{s});
}

fn parseWasiExecModel(s: []const u8) std.builtin.WasiExecModel {
    return std.meta.stringToEnum(std.builtin.WasiExecModel, s) orelse
        fatal("expected [command|reactor] for -mexec-mode=[value], found '{s}'", .{s});
}

fn parseStackSize(s: []const u8) u64 {
    return std.fmt.parseUnsigned(u64, s, 0) catch |err|
        fatal("unable to parse stack size '{s}': {s}", .{ s, @errorName(err) });
}

fn parseImageBase(s: []const u8) u64 {
    return std.fmt.parseUnsigned(u64, s, 0) catch |err|
        fatal("unable to parse image base '{s}': {s}", .{ s, @errorName(err) });
}

fn handleModArg(
    arena: Allocator,
    mod_name: []const u8,
    opt_root_src_orig: ?[]const u8,
    create_module: *CreateModule,
    mod_opts: *Package.Module.CreateOptions.Inherited,
    cc_argv: *std.ArrayListUnmanaged([]const u8),
    target_arch_os_abi: *?[]const u8,
    target_mcpu: *?[]const u8,
    deps: *std.ArrayListUnmanaged(CliModule.Dep),
    c_source_files_owner_index: *usize,
    rc_source_files_owner_index: *usize,
    cssan: *ClangSearchSanitizer,
) !void {
    const gop = try create_module.modules.getOrPut(arena, mod_name);

    if (gop.found_existing) {
        fatal("unable to add module '{s}': already exists as '{s}'", .{
            mod_name, gop.value_ptr.paths.root_src_path,
        });
    }

    // See duplicate logic: ModCreationGlobalFlags
    if (mod_opts.single_threaded == false)
        create_module.opts.any_non_single_threaded = true;
    if (mod_opts.sanitize_thread == true)
        create_module.opts.any_sanitize_thread = true;
    if (mod_opts.fuzz == true)
        create_module.opts.any_fuzz = true;
    if (mod_opts.unwind_tables == true)
        create_module.opts.any_unwind_tables = true;
    if (mod_opts.strip == false)
        create_module.opts.any_non_stripped = true;
    if (mod_opts.error_tracing == true)
        create_module.opts.any_error_tracing = true;

    gop.value_ptr.* = .{
        .paths = p: {
            if (opt_root_src_orig) |root_src_orig| {
                create_module.opts.have_zcu = true;
                const root_src = try introspect.resolvePath(arena, root_src_orig);
                break :p .{
                    .root = .{
                        .root_dir = Cache.Directory.cwd(),
                        .sub_path = fs.path.dirname(root_src) orelse "",
                    },
                    .root_src_path = fs.path.basename(root_src),
                };
            }
            break :p .{
                .root = .{ .root_dir = Cache.Directory.cwd() },
                .root_src_path = "",
            };
        },
        .cc_argv = try cc_argv.toOwnedSlice(arena),
        .inherited = mod_opts.*,
        .target_arch_os_abi = target_arch_os_abi.*,
        .target_mcpu = target_mcpu.*,
        .deps = try deps.toOwnedSlice(arena),
        .resolved = null,
        .c_source_files_start = c_source_files_owner_index.*,
        .c_source_files_end = create_module.c_source_files.items.len,
        .rc_source_files_start = rc_source_files_owner_index.*,
        .rc_source_files_end = create_module.rc_source_files.items.len,
    };
    cssan.reset();
    mod_opts.* = .{};
    target_arch_os_abi.* = null;
    target_mcpu.* = null;
    c_source_files_owner_index.* = create_module.c_source_files.items.len;
    rc_source_files_owner_index.* = create_module.rc_source_files.items.len;
}