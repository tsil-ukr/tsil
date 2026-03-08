#!/usr/bin/env sh
set -e
set -x

TsilVersion="$(cat Версія)"
TsilTarget="лінукс-ікс86_64"
BuildDir="будування/$TsilVersion/$TsilTarget"
BuildSourceDir="$BuildDir/напівготове"
BuildOutDir="$BuildDir/готове"
BuildPackageDir="$BuildDir/пакування"

mkdir -p "$BuildPackageDir/ціль-$TsilVersion-$TsilTarget/програми"

cp "$BuildOutDir/ціль" "$BuildPackageDir/ціль-$TsilVersion-$TsilTarget/програми"
cd "$BuildPackageDir"
tar -cJvf "ціль-$TsilVersion-$TsilTarget.tar.xz" "ціль-$TsilVersion-$TsilTarget"
cd -