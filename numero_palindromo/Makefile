CC=gcc
CFLAGS=-Wall -Werror

all: lib_numero_palindromo.o

lib_numero_palindromo.o: lib_numero_palindromo.c numero_palindromo.h
	$(CC) $(CFLAGS) -c lib_numero_palindromo.c

librarytest: librarytest.c lib_numero_palindromo.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o librarytest