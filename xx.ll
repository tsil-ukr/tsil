; ModuleID = './xx.c'
source_filename = "./xx.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@x = global i32 0, align 4
@y = global i32 0, align 4

; Function Attrs: noinline nounwind optnone
define dso_local void @test() #0 {
entry:
  %d = alloca i32, align 4
  store i32 8, ptr %d, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 18.1.8"}
