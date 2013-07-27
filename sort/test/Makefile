CC=g++
CFLAGS=-c -Wall -I../../

all: bubble-sort_test merge-sort_test selection-sort_test

bubble-sort_test: bubble-sort.o bubble-sort_test.o
	$(CC) bubble-sort.o bubble-sort_test.o -o bubble-sort_test

merge-sort_test: merge-sort_test.o merge-sort.o
	$(CC) merge-sort.o merge-sort_test.o -o merge-sort_test

selection-sort_test: selection-sort.o selection-sort_test.o
	$(CC) selection-sort.o selection-sort_test.o -o selection-sort_test

bubble-sort_test.o: bubble-sort_test.cc
	$(CC) $(CFLAGS) bubble-sort_test.cc

merge-sort_test.o: merge-sort_test.cc
	$(CC) $(CFLAGS) merge-sort_test.cc

selection-sort_test.o: selection-sort_test.cc
	$(CC) $(CFLAGS) selection-sort_test.cc

bubble-sort.o: ../bubble-sort.cc
	$(CC) $(CFLAGS) ../bubble-sort.cc

merge-sort.o: ../merge-sort.cc
	$(CC) $(CFLAGS) ../merge-sort.cc

selection-sort.o: ../selection-sort.cc
	$(CC) $(CFLAGS) ../selection-sort.cc

clean:
	rm -f *.o bubble-sort_test merge-sort_test selection-sort_test
