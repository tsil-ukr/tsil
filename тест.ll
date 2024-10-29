target triple = ""
%"список.1" = type { ptr }
define internal void @"x.0x"() {
alloca.0:
  %"s.2" = alloca ptr
  %"m.8" = alloca ptr
  br label %entry.1
entry.1:
  %"load.3" = load ptr, ptr %"s.2"
  %"getelementptr.4" = getelementptr inbounds %"список.1", ptr %"load.3", i32 0, i32 0
  %"load.5" = load ptr, ptr %"getelementptr.4"
  %"getelementptr.6" = getelementptr inbounds ptr, ptr %"load.5", i64 10
  %"load.7" = load ptr, ptr %"getelementptr.6"
  store ptr %"load.7", ptr %"m.8"
  br label %exit.2
exit.2:
  ret void
}