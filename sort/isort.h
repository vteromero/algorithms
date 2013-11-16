// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Base class to implement a sorting algorithm.
// Defines the mandatory methods that they will be implemented.

#ifndef ISORT_H_
#define ISORT_H_

#include "sort-stats.h"

class ISort
{
public:
    virtual ~ISort() {}

    // Sorts an integer array into ascending order.
    virtual void Sort(int *array, int length) = 0;

    // Statistics of the sorting algorithm.
    virtual SortStats *Statistics() = 0;
};

#endif // ISORT_H_
