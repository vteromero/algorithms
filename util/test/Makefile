SRC_DIR=../..

CC=g++
CFLAGS=-c -Wall -I$(SRC_DIR)

all: int-array_test color-text_test

int-array_test: int-array.o int-array_test.o
	$(CC) int-array.o int-array_test.o -o int-array_test

color-text_test: color-text.o color-text_test.o
	$(CC) color-text.o color-text_test.o -o color-text_test

int-array_test.o: int-array_test.cc
	$(CC) $(CFLAGS) int-array_test.cc

color-text_test.o: color-text_test.cc
	$(CC) $(CFLAGS) color-text_test.cc

int-array.o: $(SRC_DIR)/util/int-array.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/util/int-array.cc

color-text.o: $(SRC_DIR)/util/color-text.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/util/color-text.cc

clean:
	rm -f *.o int-array_test color-text_test
