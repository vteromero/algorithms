SRC_DIR=../..

CC=g++
CFLAGS=-c -Wall -I$(SRC_DIR)

all: int-array_test

int-array_test: int-array.o int-array_test.o
	$(CC) int-array.o int-array_test.o -o int-array_test

int-array_test.o: int-array_test.cc
	$(CC) $(CFLAGS) int-array_test.cc

int-array.o: $(SRC_DIR)/util/int-array.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/util/int-array.cc

clean:
	rm -f *.o int-array_test
