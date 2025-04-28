#!/usr/bin/env bash

set -e

VERSION="$(cat ВЕРСІЯ)"

TSIL="$1"
if [ -z "$TSIL" ]; then
  TSIL="ціль"
fi

bash скрипти/збудувати_КЦ.sh "$TSIL"

mkdir -p випуски/"$VERSION"/ціль-"$VERSION"-x86_64-linux-gnu/bin
cp "build/ціль" випуски/"$VERSION"/ціль-"$VERSION"-x86_64-linux-gnu/bin/ціль
cd випуски/"$VERSION"
zip -r -9 ціль-"$VERSION"-x86_64-linux-gnu.zip ціль-"$VERSION"-x86_64-linux-gnu