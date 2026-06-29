cd $(dirname ${BASH_SOURCE[0]})/..
mkdir -p out
echo "packaging images..."
xxd -i src/assets/icon.png | sed 's/unsigned/static unsigned/g' > src/assets/icon.h
xxd -i src/assets/logo.png | sed 's/unsigned/static unsigned/g' > src/assets/logo.h
echo "packaging fonts..."
xxd -i src/assets/Merriweather.ttf | sed 's/unsigned/static unsigned/g' > src/assets/Merriweather.h
xxd -i src/assets/FiraCode.ttf | sed 's/unsigned/static unsigned/g' > src/assets/FiraCode.h
echo "compiling..."
g++ -o out/BarpVN $(find src -name "*.cpp") -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio