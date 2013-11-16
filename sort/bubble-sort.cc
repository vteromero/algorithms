// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "bubble-sort.h"

#include <assert.h>
#include <stddef.h>

BubbleSort::BubbleSort()
{
#ifdef SORTSTATS
    stats_ = new SortStats;
    InitSortStats(stats_);
#else
    stats_ = NULL;
#endif
}

BubbleSort::~BubbleSort()
{
    if(stats_ != NULL)
        delete stats_;
}

void BubbleSort::Sort(int *array, int length)
{
    assert(array != NULL);
    assert(length > 0);

#ifdef SORTSTATS
    InitSortStats(stats_);
    stats_->array_length = length;
#endif

    int n = length;

    while(n > 0)
    {
        int newn = 0;

        for(int i=1; i<n; ++i)
        {
#ifdef SORTSTATS
            ++(stats_->iterations);
            ++(stats_->comparisons);
#endif

            if(array[i - 1] > array[i])
            {
#ifdef SORTSTATS
                ++(stats_->swaps);
#endif

                // swap
                int aux = array[i - 1];
                array[i - 1] = array[i];
                array[i] = aux;

                newn = i;
            }
        }

        n = newn;
    }
}

SortStats *BubbleSort::Statistics()
{
    return stats_;
}
