; ModuleID = 'тест.ц'
source_filename = "\D1\82\D0\B5\D1\81\D1\82.\D1\86"

%S = type { i8, i16, i32 }
%STyped.0 = type { i64 }
%STyped = type { i32 }

declare internal %S @f(%S)

define internal %STyped.0 @ftyped(%STyped %0) {
alloca:
  %return = alloca %STyped.0, align 8
  %st = alloca %STyped, align 8
  store %STyped %0, ptr %st, align 4
  br label %entry

entry:                                            ; preds = %alloca
  br label %exit

exit:                                             ; preds = %entry
  %load1 = load %STyped.0, ptr %return, align 4
  ret %STyped.0 %load1
}
