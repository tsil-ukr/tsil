#!/usr/bin/env sh
set -x
set -e

./out/старт тест.ю8.ц
./out/старт тест.ю8.ц > тест.ю8.ll
clang -o тест тест.ю8.ll test.c
./тест