set -x
set -e

rm -rf будування
sh external/scripts/build.sh release ir
TSIL="./будування/0.82.0/лінукс-ікс86_64/готове/програми/ціль" sh external/scripts/build.sh release c
TSIL="./будування/0.82.0/лінукс-ікс86_64/готове/програми/ціль" sh external/scripts/build.sh release c