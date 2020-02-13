CC = gcc
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -pedantic -std=c11
DEPS = gol.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
libgol.so: gol.o
	$(CC) -o $@ $^ -fPIC -shared $(CFLAGS)
	
gameoflife: gameoflife.o libgol.so
	$(CC) -o $@ $< -l:libgol.so $(CFLAGS)