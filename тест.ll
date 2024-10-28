; ModuleID = 'тест.ц'
source_filename = "\D1\82\D0\B5\D1\81\D1\82.\D1\86"

%"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA" = type { ptr, i32, i32 }

declare ptr @malloc(i32)

declare void @free(ptr)

declare ptr @realloc(ptr, i32)

declare i32 @putchar(i8)

define internal void @"\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B8\D1\82\D0\B8"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load51 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @free(ptr %load51)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @main() {
alloca:
  %"\D1\81\D0\B8\D0\BC\D0\B2\D0\BE\D0\BB\D0\B8" = alloca ptr, align 8
  %"\D1\85" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %0 = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA"()
  store ptr %0, ptr %"\D1\81\D0\B8\D0\BC\D0\B2\D0\BE\D0\BB\D0\B8", align 8
  store i64 32, ptr %"\D1\85", align 4
  br label %while_cond

return:                                           ; preds = %while_body_exit3
  ret void

while_cond:                                       ; preds = %while_body, %entry
  %load60 = load i64, ptr %"\D1\85", align 4
  %1 = icmp ult i64 %load60, 127
  br i1 %1, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load90 = load i64, ptr %"\D1\85", align 4
  %2 = trunc i64 %load90 to i8
  %load91 = load ptr, ptr %"\D1\81\D0\B8\D0\BC\D0\B2\D0\BE\D0\BB\D0\B8", align 8
  call void @"\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B4\D0\BE_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83"(ptr %load91, i8 %2)
  %load92 = load i64, ptr %"\D1\85", align 4
  %3 = add i64 %load92, 1
  store i64 %3, ptr %"\D1\85", align 4
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  store i64 0, ptr %"\D1\85", align 4
  br label %while_cond1

while_cond1:                                      ; preds = %while_body2, %while_body_exit
  %load93 = load i64, ptr %"\D1\85", align 4
  %load94 = load ptr, ptr %"\D1\81\D0\B8\D0\BC\D0\B2\D0\BE\D0\BB\D0\B8", align 8
  %4 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load94, i32 0, i32 1
  %load95 = load i32, ptr %4, align 4
  %5 = sext i32 %load95 to i64
  %6 = icmp ult i64 %load93, %5
  br i1 %6, label %while_body2, label %while_body_exit3

while_body2:                                      ; preds = %while_cond1
  %load96 = load ptr, ptr %"\D1\81\D0\B8\D0\BC\D0\B2\D0\BE\D0\BB\D0\B8", align 8
  %7 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load96, i32 0, i32 0
  %load97 = load ptr, ptr %7, align 8
  %load98 = load i64, ptr %"\D1\85", align 4
  %8 = getelementptr i8, ptr %load97, i64 %load98
  %load99 = load i8, ptr %8, align 1
  %9 = call i32 @putchar(i8 %load99)
  %load100 = load i64, ptr %"\D1\85", align 4
  %10 = add i64 %load100, 1
  store i64 %10, ptr %"\D1\85", align 4
  br label %while_cond1

while_body_exit3:                                 ; preds = %while_cond1
  %11 = call i32 @putchar(i8 10)
  br label %return
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA"() {
alloca:
  %return1 = alloca ptr, align 8
  %"\D1\81" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %0 = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"()
  store ptr %0, ptr %"\D1\81", align 8
  %load56 = load ptr, ptr %"\D1\81", align 8
  %1 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load56, i32 0, i32 0
  store ptr null, ptr %1, align 8
  %load57 = load ptr, ptr %"\D1\81", align 8
  %2 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load57, i32 0, i32 1
  store i32 0, ptr %2, align 4
  %load58 = load ptr, ptr %"\D1\81", align 8
  %3 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load58, i32 0, i32 2
  store i32 0, ptr %3, align 4
  %load59 = load ptr, ptr %"\D1\81", align 8
  store ptr %load59, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load52 = load ptr, ptr %return1, align 8
  ret ptr %load52
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %0 = call ptr @malloc(i32 16)
  store ptr %0, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load53 = load ptr, ptr %return1, align 8
  ret ptr %load53
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.1"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load55 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %1 = mul i32 %load55, 16
  %2 = call ptr @malloc(i32 %1)
  store ptr %2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load54 = load ptr, ptr %return1, align 8
  ret ptr %load54
}

define internal void @"\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B4\D0\BE_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83"(ptr %0, i8 %1) {
alloca:
  %"\D1\81" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D1\81", align 8
  store i8 %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  %load61 = load ptr, ptr %"\D1\81", align 8
  %2 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load61, i32 0, i32 1
  %load62 = load i32, ptr %2, align 4
  %load63 = load ptr, ptr %"\D1\81", align 8
  %3 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load63, i32 0, i32 2
  %load64 = load i32, ptr %3, align 4
  %4 = icmp eq i32 %load62, %load64
  br i1 %4, label %if_body, label %if_body_else

return:                                           ; preds = %if_body_exit
  ret void

if_body:                                          ; preds = %entry
  %load65 = load ptr, ptr %"\D1\81", align 8
  %5 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load65, i32 0, i32 2
  %load66 = load i32, ptr %5, align 4
  %6 = icmp eq i32 %load66, 0
  br i1 %6, label %if_body1, label %if_body_else2

if_body_else:                                     ; preds = %entry
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body_exit3
  %load82 = load ptr, ptr %"\D1\81", align 8
  %7 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load82, i32 0, i32 0
  %load83 = load ptr, ptr %"\D1\81", align 8
  %8 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load83, i32 0, i32 1
  %load84 = load ptr, ptr %7, align 8
  %load85 = load i32, ptr %8, align 4
  %9 = getelementptr i8, ptr %load84, i32 %load85
  %load86 = load i8, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  store i8 %load86, ptr %9, align 1
  %load87 = load ptr, ptr %"\D1\81", align 8
  %10 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load87, i32 0, i32 1
  %load88 = load i32, ptr %10, align 4
  %11 = add i32 %load88, 1
  %load89 = load ptr, ptr %"\D1\81", align 8
  %12 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load89, i32 0, i32 1
  store i32 %11, ptr %12, align 4
  br label %return

if_body1:                                         ; preds = %if_body
  %13 = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.3"(i32 1)
  %load70 = load ptr, ptr %"\D1\81", align 8
  %14 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load70, i32 0, i32 0
  store ptr %13, ptr %14, align 8
  br label %if_body_exit3

if_body_else2:                                    ; preds = %if_body
  %load74 = load ptr, ptr %"\D1\81", align 8
  %15 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load74, i32 0, i32 0
  %load75 = load ptr, ptr %"\D1\81", align 8
  %16 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load75, i32 0, i32 2
  %load76 = load i32, ptr %16, align 4
  %17 = add i32 %load76, 1
  %load77 = load ptr, ptr %15, align 8
  %18 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"(ptr %load77, i32 %17)
  %load78 = load ptr, ptr %"\D1\81", align 8
  %19 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load78, i32 0, i32 0
  store ptr %18, ptr %19, align 8
  br label %if_body_exit3

if_body_exit3:                                    ; preds = %if_body_else2, %if_body1
  %load79 = load ptr, ptr %"\D1\81", align 8
  %20 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load79, i32 0, i32 2
  %load80 = load i32, ptr %20, align 4
  %21 = add i32 %load80, 1
  %load81 = load ptr, ptr %"\D1\81", align 8
  %22 = getelementptr %"\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA", ptr %load81, i32 0, i32 2
  store i32 %21, ptr %22, align 4
  br label %if_body_exit
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.2"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %0 = call ptr @malloc(i32 1)
  store ptr %0, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load67 = load ptr, ptr %return1, align 8
  ret ptr %load67
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.3"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load69 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %1 = mul i32 %load69, 1
  %2 = call ptr @malloc(i32 %1)
  store ptr %2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load68 = load ptr, ptr %return1, align 8
  ret ptr %load68
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load72 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %2 = mul i32 %load72, 1
  %load73 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %3 = call ptr @realloc(ptr %load73, i32 %2)
  store ptr %3, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load71 = load ptr, ptr %return1, align 8
  ret ptr %load71
}
