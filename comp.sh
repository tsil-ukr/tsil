#!/usr/bin/env bash

set -e

./build/tsil старт.ц >старт.ll
llc --relocation-model=pic -filetype=obj старт.ll -o старт.o
clang старт.o -o старт