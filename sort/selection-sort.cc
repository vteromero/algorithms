// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "selection-sort.h"

#include <stddef.h>

SelectionSort::SelectionSort()
{
#ifdef SORTSTATS
    stats_ = new SortStats;
    InitSortStats(stats_);
#else
    stats_ = NULL;
#endif
}

SelectionSort::~SelectionSort()
{
    if(stats_ != NULL)
        delete stats_;
}

void SelectionSort::Sort(int *array, int length)
{
#ifdef SORTSTATS
    stats_->array_length = length;
#endif

    for(int i=0; i<length-1; ++i)
    {
        int min = i;

        for(int j=i+1; j<length; ++j)
        {
#ifdef SORTSTATS
            ++(stats_->iterations);
            ++(stats_->comparisons);
#endif

            if(array[j] < array[min])
                min = j;
        }

#ifdef SORTSTATS
        ++(stats_->comparisons);
#endif
        if(min != i)
        {
#ifdef SORTSTATS
            ++(stats_->swaps);
#endif

            // swap
            int aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }
}

SortStats *SelectionSort::Statistics()
{
    return stats_;
}
