SRC_DIR=../..

CC=g++
CFLAGS=-c -Wall -I$(SRC_DIR) -DSORTSTATS

all: bubble-sort_test insertion-sort_test merge-sort_test selection-sort_test

bubble-sort_test: int-array.o sort-stats.o bubble-sort.o bubble-sort_test.o
	$(CC) int-array.o sort-stats.o bubble-sort.o bubble-sort_test.o -o bubble-sort_test

insertion-sort_test: int-array.o sort-stats.o insertion-sort.o insertion-sort_test.o
	$(CC) int-array.o sort-stats.o insertion-sort.o insertion-sort_test.o -o insertion-sort_test

merge-sort_test: int-array.o sort-stats.o merge-sort_test.o merge-sort.o
	$(CC) int-array.o sort-stats.o merge-sort.o merge-sort_test.o -o merge-sort_test

selection-sort_test: int-array.o sort-stats.o selection-sort.o selection-sort_test.o
	$(CC) int-array.o sort-stats.o selection-sort.o selection-sort_test.o -o selection-sort_test

bubble-sort_test.o: bubble-sort_test.cc
	$(CC) $(CFLAGS) bubble-sort_test.cc

insertion-sort_test.o: insertion-sort_test.cc
	$(CC) $(CFLAGS) insertion-sort_test.cc

merge-sort_test.o: merge-sort_test.cc
	$(CC) $(CFLAGS) merge-sort_test.cc

selection-sort_test.o: selection-sort_test.cc
	$(CC) $(CFLAGS) selection-sort_test.cc

bubble-sort.o: $(SRC_DIR)/sort/bubble-sort.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/sort/bubble-sort.cc

insertion-sort.o: $(SRC_DIR)/sort/insertion-sort.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/sort/insertion-sort.cc

merge-sort.o: $(SRC_DIR)/sort/merge-sort.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/sort/merge-sort.cc

selection-sort.o: $(SRC_DIR)/sort/selection-sort.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/sort/selection-sort.cc

sort-stats.o: $(SRC_DIR)/sort/sort-stats.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/sort/sort-stats.cc

int-array.o: $(SRC_DIR)/util/int-array.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/util/int-array.cc

clean:
	rm -f *.o bubble-sort_test insertion-sort_test merge-sort_test selection-sort_test
