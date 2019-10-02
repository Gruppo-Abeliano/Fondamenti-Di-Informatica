CC=gcc
CFLAGS=-Wall -Werror

all: librarytest

lib_riduzione_di_gauss.o: lib_riduzione_di_gauss.c riduzione_di_gauss.h
	$(CC) $(CFLAGS) -c lib_riduzione_di_gauss.c

librarytest: librarytest.c lib_riduzione_di_gauss.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o librarytest