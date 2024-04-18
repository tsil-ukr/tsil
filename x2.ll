@const.8 = constant [13 x i8] c"привіт\00"
%struct.7 = type { i64, ptr }
define i32 @"main"() {
entry:
  br label %while
while:
  br i1 1, label %while_body, label %while_exit
while_body:
  %call.9 = call ptr @"printf"(ptr @const.8)
  br label %while
while_exit:
  ret i32 0
}
declare void @"printf"(ptr)
