#!/usr/bin/env sh
set -e
set -x

Version="$(cat Версія)"
TsilTarget="linux-x86_64"
ReleaseFiles=$(cat ФайлиВипуску)

if [ -d "releases/$Version" ]; then
  echo "Випуск $Version вже існує"
  exit 1
fi


mkdir -p "releases/$Version"

sh external/scripts/build.sh
sh external/scripts/package.sh

cp "package/$Version/$TsilTarget/ціль-$Version-$TsilTarget.tar.gz" "releases/$Version"

mkdir -p "releases/$Version/ціль-$Version"

while IFS='' read -r ReleaseFile
do
  cp -r "$ReleaseFile" "releases/$Version/ціль-$Version"
done <<ReleaseFiles_HEREDOC_INPUT
$ReleaseFiles
ReleaseFiles_HEREDOC_INPUT

cd "releases/$Version"
tar -czvf "ціль-$Version.tar.gz" "ціль-$Version"
cd -

rm -rf "releases/$Version/ціль-$Version"