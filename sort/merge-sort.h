// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Merge sort algorithm.

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include "sort-stats.h"

class MergeSort
{
public:
    MergeSort();
    ~MergeSort();

    // Sorts an integer array into ascending order.
    void Sort(int *array, int length);

    // Statistics of the sorting algorithm
    SortStats *Statistics();

private:
    // Sorts array from start to start+length recursively.
    void SortRange(int *array, int start, int length);

    // Merges two pieces (halves) into one.
    void Merge(int *array, int start1, int length1, int start2, int length2);

    SortStats *stats_;
};

#endif // MERGE_SORT_H_
