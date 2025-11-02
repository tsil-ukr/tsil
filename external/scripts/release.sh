#!/usr/bin/env sh
set -e
set -x

RunDir="$PWD"

Version="$(cat Версія)"
TsilTarget="лінукс-ікс86_64"
ReleaseFiles=$(cat ФайлиВипуску)
BuildDir="будування/$Version/$TsilTarget"
BuildSourceDir="$BuildDir/напівготове"
BuildOutDir="$BuildDir/готове"
BuildPackageDir="$BuildDir/пакування"

if [ -d "випуски/$Version" ]; then
  echo "Випуск $Version вже існує"
  exit 1
fi

sh external/scripts/build.sh release
sh external/scripts/package.sh

mkdir -p "випуски/$Version"

cp "$BuildPackageDir/ціль-$Version-$TsilTarget.tar.xz" "випуски/$Version"

mkdir -p "випуски/$Version/ціль-$Version"

while IFS='' read -r ReleaseFile
do
  cp -r "$ReleaseFile" "випуски/$Version/ціль-$Version"
done <<ReleaseFiles_HEREDOC_INPUT
$ReleaseFiles
ReleaseFiles_HEREDOC_INPUT

cd "випуски/$Version"
tar -cJvf "ціль-$Version.tar.xz" "ціль-$Version"
cd -

rm -rf "випуски/$Version/ціль-$Version"

cd "випуски/$Version"

PRIVATE_KEY_FILE="$RunDir/.releasegpgkey"
PRIVATE_KEY_FILE_PASSPHRASE="$RunDir/.releasegpgkeypassphrase"
TMP_GPG_HOME=$(mktemp -d)

export GNUPGHOME="$TMP_GPG_HOME"

# Import the private key into temporary keyring
gpg --batch --yes --import "$PRIVATE_KEY_FILE" >/dev/null 2>&1

# Get fingerprint from this keyring
FINGERPRINT=$(gpg --with-colons --list-secret-keys --fingerprint \
  | awk -F: '/^fpr:/ {print $10; exit}')

if [ -z "$FINGERPRINT" ]; then
  echo "Failed to get fingerprint (no secret key found)"
  exit 1
fi

echo "Using fingerprint: $FINGERPRINT"

# Read passphrase from file (trim spaces/newlines)
PASSPHRASE=$(<"$PRIVATE_KEY_FILE_PASSPHRASE")

for file in ціль-"$Version"-лінукс-ікс86_64.tar.xz ціль-"$Version".tar.xz; do
  if [ ! -f "$file" ]; then
    echo "File not found: $file"
    continue
  fi

  sha256sum "$file" > "$file.sha256"

  # Sign using the imported key ONLY inside this GNUPGHOME
  gpg --batch --yes --pinentry-mode loopback --passphrase "$PASSPHRASE" \
    --local-user "$FINGERPRINT" --clearsign --output "$file.sha256.signed" "$file.sha256"
done

# Clean up the temporary keyring
rm -rf "$TMP_GPG_HOME"

cd -