CC = gcc
override CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -pedantic -std=c11
DEPS = gol.h

gameoflife: gameoflife.o libgol.so
	$(CC) -o $@ $< -L. -lgol $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gol.o: gol.c $(DEPS)
	$(CC) -c -o $@ $< -fPIC $(CFLAGS)
	
libgol.so: gol.o
	$(CC) -o $@ $^ -shared $(CFLAGS)
	
.PHONY: clean
clean:
	rm -rf gameoflife *.o *.so