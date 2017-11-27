# -*- MakeFile -*-

# target: dependencies
# 	command

CC=gcc
CFLAGS= -std=c89 -Wall -Wextra -Werror -Wpedantic

all: test cgi-bin/main.cgi

cgi-bin/main.cgi: src/main_cgi.o src/user.o
	$(CC) src/main_cgi.o src/user.o -o cgi-bin/main.cgi $(CFLAGS)

src/main_cgi.o: src/main_cgi.c src/user.h
	$(CC) -c src/main_cgi.c -o src/main_cgi.o $(CFLAGS)

test: src/test.o src/user.o
	$(CC) src/test.o src/user.o -o test $(CFLAGS)

src/test.o: src/test.c src/user.h
	$(CC) -c src/test.c -o src/test.o $(CFLAGS)

src/user.o: src/user.c
	$(CC) -c src/user.c -o src/user.o $(CFLAGS)

clean:
	rm -f src/*.o test 
