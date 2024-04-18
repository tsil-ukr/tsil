%struct.8 = type { i64, ptr }
define i64 @"main"() {
entry.0:
  %alloca.9 = alloca i64
  %alloca.11 = alloca i64
  store i64 100, ptr %alloca.11
  br label %while.2
exit.1:
  %load.10 = load i64, ptr %alloca.9
  ret i64 %load.10
while.2:
  %load.12 = load i64, ptr %alloca.11
  %icmp.13 = icmp ne i64 %load.12, 10
  br i1 %icmp.13, label %while_body.3, label %while_exit.4
while_body.3:
  %load.14 = load i64, ptr %alloca.11
  call void @"друк_ціле"(i64 %load.14)
  %load.16 = load i64, ptr %alloca.11
  %add.17 = add i64 %load.16, 1
  store i64 %add.17, ptr %alloca.11
  br label %while.2
while_exit.4:
  store i64 0, ptr %alloca.9
  br label %exit.1
}
declare void @"друк_ціле"(i64)
declare void @"printf"(ptr)