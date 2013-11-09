SRC_DIR=../..
CC=g++
CFLAGS=-c -Wall -I$(SRC_DIR)

all: bst_test

bst_test: bst_test.o
	$(CC) bst_test.o -o bst_test

bst_test.o: bst_test.cc
	$(CC) $(CFLAGS) bst_test.cc

clean:
	rm -f *.o bst_test
