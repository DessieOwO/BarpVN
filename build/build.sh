cd $(dirname ${BASH_SOURCE[0]})/..
mkdir -p out
g++ -o out/BarpVN src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
echo "Build complete! :3"