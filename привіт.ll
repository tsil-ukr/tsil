%struct.8 = type { i64, ptr }
define i64 @"main"() {
entry.0:
  %alloca.20 = alloca i64
  %call.22 = call i64 @"сума"(i64 2, i64 2)
  store i64 0, ptr %alloca.20
  br label %exit.1
exit.1:
  %load.21 = load i64, ptr %alloca.20
  ret i64 %load.21
}
define i64 @"сума"(i64 %arg.11, i64 %arg.12) {
entry.0:
  %alloca.13 = alloca i64
  %alloca.15 = alloca i64
  store i64 %arg.11, ptr %alloca.15
  %alloca.16 = alloca i64
  store i64 %arg.12, ptr %alloca.16
  %load.17 = load i64, ptr %alloca.15
  %load.18 = load i64, ptr %alloca.16
  %add.19 = add i64 %load.17, %load.18
  store i64 %add.19, ptr %alloca.13
  br label %exit.1
exit.1:
  %load.14 = load i64, ptr %alloca.13
  ret i64 %load.14
}
declare void @"друк_ціле"(i64 %arg.10)
declare void @"printf"(ptr %arg.9)