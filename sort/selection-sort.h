// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Selection sort algorithm.

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include "sort-stats.h"

class SelectionSort
{
public:
    SelectionSort();
    ~SelectionSort();

    // Sorts an integer array into ascending order.
    void Sort(int *array, int length);

    // Statistics of the sorting algorithm
    SortStats *Statistics();

private:
    SortStats *stats_;
};

#endif // SELECTION_SORT_H_
