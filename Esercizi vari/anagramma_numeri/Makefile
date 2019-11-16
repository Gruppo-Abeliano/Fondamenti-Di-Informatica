CC=gcc
CFLAGS=-Wall -Werror

all: lib_anagramma_numeri.o

lib_anagramma_numeri.o: lib_anagramma_numeri.c anagramma_numeri.h
	$(CC) $(CFLAGS) -c lib_anagramma_numeri.c

librarytest: librarytest.c lib_anagramma_numeri.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o librarytest