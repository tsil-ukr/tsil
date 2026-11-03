Version="$(cat Версія)"
rm -rf будування/$Version
rm -rf випуски/$Version
sh external/scripts/build.sh release
mkdir -p /home/kohutd/.local/share/укр/встановлені/ціль/$Version/
cp -r будування/$Version/лінукс-ікс86_64/готове/* /home/kohutd/.local/share/укр/встановлені/ціль/$Version/