// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Bubble sort algorithm.

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

class BubbleSort
{
public:
    BubbleSort();
    ~BubbleSort();

    // Sorts an integer array into ascending order.
    void Sort(int *array, int length);
};

#endif // BUBBLE_SORT_H_
