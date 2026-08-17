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

cp "$BuildOutDir/програми/ціль" "$BuildPackageDir/ціль-$TsilVersion-$TsilTarget/програми"
cp "$BuildOutDir/основа.в.ц" "$BuildPackageDir/ціль-$TsilVersion-$TsilTarget"
cp "$BuildOutDir/main.c" "$BuildPackageDir/ціль-$TsilVersion-$TsilTarget"
cp -a "$BuildOutDir/біб" "$BuildPackageDir/ціль-$TsilVersion-$TsilTarget"
cd "$BuildPackageDir"f
tar -cJvf "ціль-$TsilVersion-$TsilTarget.tar.xz" "ціль-$TsilVersion-$TsilTarget"
cd -