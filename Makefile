all:
	g++ -Isrc/Include -Lsrc/lib -o out $(src) -lmingw32 -lSDL2main -lSDL2

