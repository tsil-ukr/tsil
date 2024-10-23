; ModuleID = './xx.c'
source_filename = "./xx.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.C = type { %struct.B }
%struct.B = type { %struct.A }
%struct.A = type { i32 }

@cx2 = external global %struct.C, align 4
@cx3 = internal global %struct.C { %struct.B { %struct.A { i32 1 } } }, align 4
@cx = global %struct.C zeroinitializer, align 4

; Function Attrs: noinline nounwind optnone
define dso_local void @test() #0 {
entry:
  %c = alloca %struct.C, align 4
  %c2 = alloca %struct.C, align 4
  %m = alloca i32, align 4
  call void @llvm.memcpy.p0.p0.i64(ptr align 4 %c, ptr align 4 @cx2, i64 4, i1 false)
  call void @llvm.memcpy.p0.p0.i64(ptr align 4 %c2, ptr align 4 @cx3, i64 4, i1 false)
  %b = getelementptr inbounds %struct.C, ptr %c, i32 0, i32 0
  %a = getelementptr inbounds %struct.B, ptr %b, i32 0, i32 0
  %x = getelementptr inbounds %struct.A, ptr %a, i32 0, i32 0
  %0 = load i32, ptr %x, align 4
  store i32 %0, ptr %m, align 4
  ret void
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #1

attributes #0 = { noinline nounwind optnone "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" }
attributes #1 = { nocallback nofree nounwind willreturn memory(argmem: readwrite) }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 18.1.8"}
