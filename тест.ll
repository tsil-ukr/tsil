target triple = ""
declare i32 @"putchar"(i8 %"arg.4")
declare ptr @"malloc"(i32 %"arg.0")
define void @"x"() {
alloca.0:
  %"data.3" = alloca ptr
  br label %entry.1
entry.1:
  %"trunc.1" = trunc i64 32 to i32
  %"call.2" = call ptr @"malloc"(i32 %"trunc.1")
  store ptr %"call.2", ptr %"data.3"
  %"load.5" = load ptr, ptr %"data.3"
  %"getelementptr.6" = getelementptr inbounds i8, ptr %"load.5", i64 0
  %"load.7" = load i8, ptr %"getelementptr.6"
  %"call.8" = call i32 @"putchar"(i8 %"load.7")
  br label %exit.2
exit.2:
  ret void
}