all: 
	g++ -std=c++11 -o main main.cpp -Isrc/include -Lsrc/lib -lSDL2main -lSDL2

