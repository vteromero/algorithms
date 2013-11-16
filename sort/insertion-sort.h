// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Insertion sort algorithm.

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "isort.h"

class InsertionSort: public ISort
{
public:
    InsertionSort();
    ~InsertionSort();
    void Sort(int *array, int length);
    SortStats *Statistics();

private:
    SortStats *stats_;
};

#endif // INSERTION_SORT_H_
