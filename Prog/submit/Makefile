CC = gcc
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -pedantic -std=c11
DEPS = gol.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gol.o: gol.c $(DEPS)
	$(CC) -c -o $@ $< -fPIC $(CFLAGS)
	
libgol.so: gol.o
	$(CC) -o $@ $^ -shared $(CFLAGS)
	
gameoflife: gameoflife.o libgol.so
	$(CC) -o $@ $< -L. -llibgol $(CFLAGS)