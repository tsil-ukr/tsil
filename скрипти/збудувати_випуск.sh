#!/usr/bin/env bash

set -e

VERSION="$(cat ВЕРСІЯ)"

TSIL="$1"
if [ -z "$TSIL" ]; then
  TSIL="ціль"
fi

bash скрипти/збудувати_КЦ.sh "$TSIL"

mkdir -p випуски/"$VERSION"/ціль-0.24.0-linux-gnu
cp "build/ціль" випуски/"$VERSION"/ціль-0.24.0-linux-gnu/ціль
cd випуски/"$VERSION"
zip -r -9 ціль-0.24.0-linux-gnu.zip ціль-0.24.0-linux-gnu