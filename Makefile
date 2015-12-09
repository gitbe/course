CC=gcc
CFLAGS="-Wall"
CXXFLAGS="${CFLAGS}"

all: cardgame

cardgame: main.c
	gcc $(CFLAGS) -o cardgame main.c
