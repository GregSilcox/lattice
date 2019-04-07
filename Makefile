CC=g++
CFLAGS=-lncurses

lattice.game: main.obj
	$(CC) -o lattice main.obj $(CFLAGS)

main.obj: main.cpp
	$(CC) -c -o main.obj main.cpp	
