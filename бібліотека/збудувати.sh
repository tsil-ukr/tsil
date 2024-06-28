#!/usr/bin/env bash

set -e

if [ -z "$CC" ]; then
  export CC="clang"
fi
if [ -z "$CXX" ]; then
  export CXX="clang++"
fi
if [ -z "$AR" ]; then
  export AR="llvm-ar"
fi
if [ -z "$RANLIB" ]; then
  export RANLIB="llvm-ranlib"
fi
if [ -z "$TSIL" ]; then
  export TSIL="ціль"
fi

INDIR="$1"
OUTDIR="$2"

rm -rf "$OUTDIR"
mkdir -p "$OUTDIR/бібліотека/"
cp -a "$INDIR/визначення" "$OUTDIR/бібліотека/"

echo "> Компіляція $INDIR/втілення/біб/друк/друк.ц"
$TSIL "$OUTDIR/скомпільоване/друк/друк.ц.ll" скомпілювати --бібліотека="$OUTDIR/бібліотека/" "$INDIR/втілення/біб/друк/друк.ц"
echo "> Компіляція $INDIR/втілення/біб/друк/друк.c"
$CC -c -o "$OUTDIR/скомпільоване/друк/друк.c.o" "$INDIR/втілення/біб/друк/друк.c"
echo "> Компіляція $INDIR/втілення/біб/юнікод/юнікод.ц"
$TSIL "$OUTDIR/скомпільоване/юнікод/юнікод.ц.ll" скомпілювати --бібліотека="$OUTDIR/бібліотека/" "$INDIR/втілення/біб/юнікод/юнікод.ц"

echo "> Компіляція $OUTDIR/скомпільоване/друк/друк.ц.ll"
$CXX -c -o "$OUTDIR/скомпільоване/друк/друк.ц.o" "$OUTDIR/скомпільоване/друк/друк.ц.ll"
echo "> Компіляція $OUTDIR/скомпільоване/юнікод/юнікод.ц.ll"
$CXX -c -o "$OUTDIR/скомпільоване/юнікод/юнікод.ц.o" "$OUTDIR/скомпільоване/юнікод/юнікод.ц.ll"

echo "> Створення архіву $OUTDIR/бібліотека/біб.a"
$AR rcs "$OUTDIR/бібліотека/біб.a" "$OUTDIR/скомпільоване/друк/друк.ц.o" "$OUTDIR/скомпільоване/друк/друк.c.o" "$OUTDIR/скомпільоване/юнікод/юнікод.ц.o"