set -e

VERSION=$(cat VERSION)
PLATFORM="x86_64-linux-gnu"
DIRNAME="ціль-$VERSION-$PLATFORM"
ZIPNAME="tsil-$VERSION-$PLATFORM.zip"

export CXX="clang++"
export CC="clang"
export AR="llvm-ar"
export RANLIB="llvm-ranlib"
export TSIL="ціль"

echo "Пакуємо Ціль $VERSION для $PLATFORM"

bash scripts/build.sh Obin "$PLATFORM"
bash бібліотека/збудувати.sh ./бібліотека ./.плавлення-бібліотеки

rm -rf release
mkdir -p release
cd release
mkdir -p "$DIRNAME"
cp ../build-Obin/ціль_випуск "$DIRNAME"/ціль
cp ../Ліцензія "$DIRNAME"/Ліцензія
cp -a ../.плавлення-бібліотеки/бібліотека "$DIRNAME"
echo -en "Документація тут: https://ціль.укр" >"$DIRNAME"/Прочитайка
zip -r -9 "$ZIPNAME" "$DIRNAME"
cd ..

if [ "$1" = "install" ]; then
    echo "Встановлюємо Ціль $VERSION"
    sudo cp -r release/"$DIRNAME"/ціль /usr/local/bin/ціль
    echo "Ціль $VERSION встановлено в /usr/local/bin/ціль"
    echo "Встановлюємо Бібліотеку Цілі"
    sudo cp -a .плавлення-бібліотеки/бібліотека /usr/local/lib/ціль
    echo "Бібліотеку Цілі встановлено в /usr/local/lib/ціль/бібліотека"
fi