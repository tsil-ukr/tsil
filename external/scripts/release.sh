#!/usr/bin/env sh
set -e
set -x

RunDir="$PWD"

Version="$(cat Версія)"
TsilTarget="linux-x86_64"
ReleaseFiles=$(cat ФайлиВипуску)

if [ -d "releases/$Version" ]; then
  echo "Випуск $Version вже існує"
  exit 1
fi

sh external/scripts/build.sh release
sh external/scripts/package.sh

mkdir -p "releases/$Version"

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

cd "releases/$Version"

PRIVATE_KEY_FILE="$RunDir/.releasegpgkey"

FINGERPRINT=$(gpg --with-colons --import-options show-only --import "$PRIVATE_KEY_FILE" 2>/dev/null \
  | awk -F: '/^fpr:/ {print $10; exit}')

if [ -z "$FINGERPRINT" ]; then
  echo "Failed to get fingerprint"
  exit 1
fi

echo "Using fingerprint: $FINGERPRINT"

for file in мавка-$Version-linux-x86_64.tar.gz мавка-$Version-linux-x86_64-prepared.tar.gz мавка-$Version.tar.gz; do
  sha256sum "$file" > "$file.sha256"

  gpg --local-user "$FINGERPRINT" --clearsign --output "$file".sha256.signed "$file".sha256
done

gpg --batch --yes --delete-secret-keys "$FINGERPRINT"
gpg --batch --yes --delete-keys "$FINGERPRINT"

cd -
