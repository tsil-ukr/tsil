@const.8 = constant [11 x i8] c"Вікно\00"
%struct.7 = type { i64, ptr }
define i32 @"main"() {
entry:
  %call.9 = call ptr @"ВизначитиВікно"(i32 800, i32 600, ptr @const.8)
  ret i32 0
}
declare i8 @"ВікноМаєБутиВідкрито"()
declare i8 @"ВікноМаєБутиЗакрито"()
declare void @"ВизначитиВікно"(i32, i32, ptr)
