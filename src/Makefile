CC=gcc
CFLAGS= -g -std=c11 -Wall -Wextra -Wpedantic -O3 -Wshadow

all: clean build

clean:
	rm -f ../bin/*

../bin/%.o : %.c
	$(CC) -c $(CFLAGS) $< -o ../bin/$@

build: ../bin/main.o
	$(CC) -o ../bin/main ../bin/main.o

run: ../bin/main
	clear && ../bin/main

install: ../bin/main
	sudo ln -sf /home/beronthecolossus/Peki/C/Projects/ANSI/bin/main /usr/local/bin/notes

