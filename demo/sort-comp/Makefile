SRC_DIR=../..

CC=g++
CFLAGS=-c -Wall -I$(SRC_DIR)
OBJS=sort-comp.o color-text.o int-array.o sort-stats.o bubble-sort.o \
	insertion-sort.o merge-sort.o selection-sort.o

all: install

install: sort-comp
	mkdir -p data

sort-comp: $(OBJS)
	$(CC) $(OBJS) -o sort-comp

sort-comp.o: sort-comp.cc
	$(CC) $(CFLAGS) sort-comp.cc

bubble-sort.o: $(SRC_DIR)/sort/bubble-sort.cc
	$(CC) $(CFLAGS) -DSORTSTATS $(SRC_DIR)/sort/bubble-sort.cc

insertion-sort.o: $(SRC_DIR)/sort/insertion-sort.cc
	$(CC) $(CFLAGS) -DSORTSTATS $(SRC_DIR)/sort/insertion-sort.cc

merge-sort.o: $(SRC_DIR)/sort/merge-sort.cc
	$(CC) $(CFLAGS) -DSORTSTATS $(SRC_DIR)/sort/merge-sort.cc

selection-sort.o: $(SRC_DIR)/sort/selection-sort.cc
	$(CC) $(CFLAGS) -DSORTSTATS $(SRC_DIR)/sort/selection-sort.cc

sort-stats.o: $(SRC_DIR)/sort/sort-stats.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/sort/sort-stats.cc

color-text.o: $(SRC_DIR)/util/color-text.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/util/color-text.cc

int-array.o: $(SRC_DIR)/util/int-array.cc
	$(CC) $(CFLAGS) $(SRC_DIR)/util/int-array.cc

clean:
	rm -f *.o sort-comp
