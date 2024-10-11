#!/usr/bin/env bash

set -e

TSIL_PATH="$1"

TESTS=(
  "тестування/тести/структура/тест_структури_0.ц"
)

for TEST in "${TESTS[@]}"; do
  echo "Тестуємо $TEST"
  $TSIL_PATH ".тестування/скомпільоване/$TEST.ll" скомпілювати "$TEST"
done