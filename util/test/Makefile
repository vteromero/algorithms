CC=g++
CFLAGS=-c -Wall -I../../

all: int-array_test

int-array_test: int-array.o int-array_test.o
	$(CC) int-array.o int-array_test.o -o int-array_test

int-array_test.o: int-array_test.cc
	$(CC) $(CFLAGS) int-array_test.cc

int-array.o: ../int-array.cc
	$(CC) $(CFLAGS) ../int-array.cc

clean:
	rm -f *.o int-array_test
