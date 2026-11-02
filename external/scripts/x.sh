Version="$(cat Версія)"
rm -rf будування/$Version
rm -rf випуски/$Version
sh external/scripts/release.sh
cp -r будування/$Version/лінукс-ікс86_64/готове/* /home/kohutd/.local/share/укр/встановлені/ціль/0.81.0/