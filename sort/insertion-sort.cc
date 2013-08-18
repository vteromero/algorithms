// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "insertion-sort.h"

#include <stddef.h>

InsertionSort::InsertionSort()
{
#ifdef SORTSTATS
    stats_ = new SortStats;
    InitSortStats(stats_);
#else
    stats_ = NULL;
#endif
}

InsertionSort::~InsertionSort()
{
    if(stats_ != NULL)
        delete stats_;
}

void InsertionSort::Sort(int *array, int length)
{
#ifdef SORTSTATS
    stats_->array_length = length;
#endif

    for(int i=1; i<length; ++i)
    {
        int current = array[i];

        int j = i - 1;
        while((j >= 0) && (array[j] > current))
        {
#ifdef SORTSTATS
            ++(stats_->iterations);
            ++(stats_->comparisons);
#endif

            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = current;
    }
}

SortStats *InsertionSort::Statistics()
{
    return stats_;
}
