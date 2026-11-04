set -x
set -e

Version="$(cat Версія)"

rm -rf будування
sh external/scripts/build.sh release ir
TSIL="./будування/$Version/лінукс-ікс86_64/готове/програми/ціль" sh external/scripts/build.sh release c
TSIL="./будування/$Version/лінукс-ікс86_64/готове/програми/ціль" sh external/scripts/build.sh release c
TSIL="./будування/$Version/лінукс-ікс86_64/готове/програми/ціль" sh external/scripts/build.sh release c