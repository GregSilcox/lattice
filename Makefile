CC=g++
CFLAGS=-lncurses -I.

lattice.game: main.obj virtex.obj
	$(CC) -o lattice.game main.obj virtex.obj $(CFLAGS)

main.obj: main.cpp
	$(CC) -c -o main.obj main.cpp

virtex.obj: virtex.cpp
	$(CC) -c -o virtex.obj virtex.cpp
