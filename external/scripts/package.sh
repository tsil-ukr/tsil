#!/usr/bin/env sh
set -e
set -x

TsilVersion="$(cat Версія)"
TsilTarget="linux-x86_64"

PackageDir="package/$TsilVersion/$TsilTarget"
OutDir="out/$TsilVersion/$TsilTarget"

mkdir -p "$PackageDir/ціль-$TsilVersion-$TsilTarget/bin"

cp "$OutDir/ціль" "$PackageDir/ціль-$TsilVersion-$TsilTarget/bin"
cd "$PackageDir"
tar -cJvf "ціль-$TsilVersion-$TsilTarget.tar.xz" "ціль-$TsilVersion-$TsilTarget"
cd -