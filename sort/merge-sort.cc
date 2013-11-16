// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "merge-sort.h"

#include <assert.h>
#include <algorithm>
#include <limits>

MergeSort::MergeSort()
{
#ifdef SORTSTATS
    stats_ = new SortStats;
    InitSortStats(stats_);
#else
    stats_ = NULL;
#endif
}

MergeSort::~MergeSort()
{
    if(stats_ != NULL)
        delete stats_;
}

void MergeSort::Sort(int *array, int length)
{
    assert(array != NULL);
    assert(length > 0);

#ifdef SORTSTATS
    InitSortStats(stats_);
    stats_->array_length = length;
#endif

    SortRange(array, 0, length);
}

SortStats *MergeSort::Statistics()
{
    return stats_;
}

// Recursively, sorts the left and right halves and then merges them
// into a unique array.
void MergeSort::SortRange(int *array, int start, int length)
{
    if(length < 2)
        return;

    int mid = length / 2;
    int left_start = start;
    int left_length = mid;
    int right_start = start + mid;
    int right_length = length - mid;

    SortRange(array, left_start, left_length);
    SortRange(array, right_start, right_length);

    Merge(array, left_start, left_length, right_start, right_length);
}

void MergeSort::Merge(int *array, int start1, int length1, int start2, int length2)
{
    int *left = new int[length1 + 1];
    int *right = new int[length2 + 1];

    std::copy(&(array[start1]), &(array[start1 + length1]), left);
    std::copy(&(array[start2]), &(array[start2 + length2]), right);

#ifdef SORTSTATS
    stats_->extra_memory += (length1 + length2) * sizeof(int);
#endif

    left[length1] = std::numeric_limits<int>::max();
    right[length2] = std::numeric_limits<int>::max();

    int start = start1;
    int end = start1 + length1 + length2;

    for(int i=0, j=0, k=start; k<end; ++k)
    {
#ifdef SORTSTATS
        ++(stats_->iterations);
#endif

        if(left[i] < right[j])
        {
#ifdef SORTSTATS
            ++(stats_->comparisons);
#endif

            array[k] = left[i];
            ++i;
        }
        else if(right[j] < left[i])
        {
#ifdef SORTSTATS
            stats_->comparisons += 2;
#endif

            array[k] = right[j];
            ++j;
        }
        else
        {
#ifdef SORTSTATS
            stats_->comparisons += 2;
#endif

            array[k] = left[i];
            ++i;
            ++k;

            array[k] = right[j];
            ++j;
        }
    }

    delete [] left;
    delete [] right;
}
