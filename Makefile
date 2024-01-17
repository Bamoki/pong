all: 
	g++ -std=c++11 -o main main.cpp -Isrc/include -Lsrc/lib -Lsrc/TTF_SDL/lib -lSDL2main -lSDL2 -lSDL2_ttf

