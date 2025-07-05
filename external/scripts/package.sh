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
tar -czvf "ціль-$TsilVersion-$TsilTarget.tar.gz" "ціль-$TsilVersion-$TsilTarget"
cd -