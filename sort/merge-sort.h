// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Merge sort algorithm.

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

class MergeSort
{
public:
    MergeSort();
    ~MergeSort();

    // Sorts an integer array into ascending order.
    void Sort(int *array, int length);

private:
    // Sorts array from start to start+length recursively.
    void SortRange(int *array, int start, int length);

    // Merges two pieces (halves) into one.
    void Merge(int *array, int start1, int length1, int start2, int length2);
};

#endif // MERGE_SORT_H_
