; ModuleID = 'біб.ц'
source_filename = "\D0\B1\D1\96\D0\B1.\D1\86"

declare ptr @malloc(i32)

declare void @free(ptr)

declare ptr @realloc(ptr, i32)

define internal void @"\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B8\D1\82\D0\B8"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load1 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @free(ptr %load1)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\8E8"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load2 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8E8___"(ptr %load2)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\8E16"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load3 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8E16___"(ptr %load3)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\8E32"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load4 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8E32___"(ptr %load4)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\BF8"(i8 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store i8 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  %load5 = load i8, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF8___"(i8 %load5)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\BF16"(i16 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i16, align 2
  br label %entry

entry:                                            ; preds = %alloca
  store i16 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 2
  %load6 = load i16, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 2
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF16___"(i16 %load6)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\BF32"(i32 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load7 = load i32, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF32___"(i32 %load7)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\BF64"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load8 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF64___"(i64 %load8)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\BF\D0\BE\D0\B7\D0\B8\D1\82\D0\B8\D0\B2\D0\BD\D0\B5"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load9 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF\D0\BE\D0\B7\D0\B8\D1\82\D0\B8\D0\B2\D0\BD\D0\B5___"(i64 %load9)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\868"(i8 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store i8 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  %load10 = load i8, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\868___"(i8 %load10)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\8632"(i32 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load11 = load i32, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8632___"(i32 %load11)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\8664"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load12 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8664___"(i64 %load12)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D1\86\D1\96\D0\BB\D0\B5"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load13 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\86\D1\96\D0\BB\D0\B5___"(i64 %load13)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\B432"(float %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca float, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store float %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load14 = load float, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\B432___"(float %load14)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\B464"(double %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load15 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\B464___"(double %load15)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\B4\D1\96\D0\B9\D1\81\D0\BD\D0\B5"(double %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load16 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\B4\D1\96\D0\B9\D1\81\D0\BD\D0\B5___"(double %load16)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B4\D1\80\D1\83\D0\BA_\D0\BA\D0\BE\D0\BC\D1\96\D1\80\D0\BA\D1\83"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load17 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BA\D0\BE\D0\BC\D1\96\D1\80\D0\BA\D1\83___"(ptr %load17)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E8"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load18 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E8___"(ptr %load18)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E16"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load19 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E16___"(ptr %load19)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF8"(i8 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store i8 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  %load20 = load i8, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF8___"(i8 %load20)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF32"(i32 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load21 = load i32, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF32___"(i32 %load21)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF64"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load22 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF64___"(i64 %load22)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF\D0\BE\D0\B7\D0\B8\D1\82\D0\B8\D0\B2\D0\BD\D0\B5"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load23 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF\D0\BE\D0\B7\D0\B8\D1\82\D0\B8\D0\B2\D0\BD\D0\B5___"(i64 %load23)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\868"(i8 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store i8 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  %load24 = load i8, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 1
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\868___"(i8 %load24)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8632"(i32 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load25 = load i32, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8632___"(i32 %load25)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8664"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load26 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8664___"(i64 %load26)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\86\D1\96\D0\BB\D0\B5"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load27 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\86\D1\96\D0\BB\D0\B5___"(i64 %load27)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B432"(float %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca float, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store float %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load28 = load float, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B432___"(float %load28)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B464"(double %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load29 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B464___"(double %load29)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B4\D1\96\D0\B9\D1\81\D0\BD\D0\B5"(double %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load30 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B4\D1\96\D0\B9\D1\81\D0\BD\D0\B5___"(double %load30)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define dso_local void @"\D0\B1\D1\96\D0\B1::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BA\D0\BE\D0\BC\D1\96\D1\80\D0\BA\D1\83"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load31 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BA\D0\BE\D0\BC\D1\96\D1\80\D0\BA\D1\83___"(ptr %load31)
  br label %return

return:                                           ; preds = %entry
  ret void
}

declare dso_local i8 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80_\D1\81\D0\B8\D0\BC\D0\B2\D0\BE\D0\BB\D0\B0_\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4\D1\83"(i8)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80_\D1\8E8_\D1\81\D1\96"(ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80_\D1\8E16_\D1\81\D1\96"(ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80_\D1\8E32_\D1\81\D1\96"(ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D1\83_\D1\8E8"(ptr, i64)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D1\83_\D1\8E16"(ptr, i64)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D1\83_\D1\8E8_\D1\81\D1\96"(ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D0\B4\D1\96\D0\B7\D0\BD\D0\B0\D1\82\D0\B8\D1\81\D1\8C_\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D1\83_\D1\8E16_\D1\81\D1\96"(ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D1\8E8_\D0\B2_\D1\8E16"(ptr, i64, ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D1\8E8_\D0\B2_\D1\8E32"(ptr, i64, ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D1\8E16_\D0\B2_\D1\8E8"(ptr, i64, ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D1\8E16_\D0\B2_\D1\8E32"(ptr, i64, ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D1\8E32_\D0\B2_\D1\8E8"(ptr, i64, ptr)

declare dso_local i64 @"\D0\B1\D1\96\D0\B1::\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4::\D1\8E32_\D0\B2_\D1\8E16"(ptr, i64, ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8E8___"(ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8E16___"(ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8E32___"(ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF8___"(i8)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF16___"(i16)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF32___"(i32)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF64___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BF\D0\BE\D0\B7\D0\B8\D1\82\D0\B8\D0\B2\D0\BD\D0\B5___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\868___"(i8)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8632___"(i32)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\8664___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D1\86\D1\96\D0\BB\D0\B5___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\B432___"(float)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\B464___"(double)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\B4\D1\96\D0\B9\D1\81\D0\BD\D0\B5___"(double)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B4\D1\80\D1\83\D0\BA_\D0\BA\D0\BE\D0\BC\D1\96\D1\80\D0\BA\D1\83___"(ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E8___"(ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E16___"(ptr)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF8___"(i8)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF32___"(i32)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF64___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BF\D0\BE\D0\B7\D0\B8\D1\82\D0\B8\D0\B2\D0\BD\D0\B5___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\868___"(i8)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8632___"(i32)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8664___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\86\D1\96\D0\BB\D0\B5___"(i64)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B432___"(float)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B464___"(double)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\B4\D1\96\D0\B9\D1\81\D0\BD\D0\B5___"(double)

declare void @"___\D0\B1\D1\96\D0\B1__\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D0\BA\D0\BE\D0\BC\D1\96\D1\80\D0\BA\D1\83___"(ptr)
