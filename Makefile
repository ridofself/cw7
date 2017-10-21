# -*- MakeFile -*-

# target: dependencies
# 	command

CC=clang
CFLAGS= -std=c89 -Wall -Wextra -Werror -Wpedantic

all: run

run: src/test.o src/name.o
	$(CC) src/test.o src/name.o -o run $(CFLAGS)

src/test.o: src/test.c src/name.h
	$(CC) -c src/test.c -o src/test.o $(CFLAGS)

src/name.o: src/name.c
	$(CC) -c src/name.c -o src/name.o $(CFLAGS)

clean:
	rm -f src/*.o run
