// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Bubble sort algorithm.

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "isort.h"

class BubbleSort: public ISort
{
public:
    BubbleSort();
    ~BubbleSort();
    void Sort(int *array, int length);
    SortStats *Statistics();

private:
    SortStats *stats_;
};

#endif // BUBBLE_SORT_H_
