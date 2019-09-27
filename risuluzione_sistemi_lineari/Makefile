CC=gcc
CFLAGS=-Wall

all: librarytest

librarytest: librarytest.c ../riduzione_di_gauss/lib_riduzione_di_gauss.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o librarytest