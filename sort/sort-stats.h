// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Structures and functions for keeping execution stats of sorting algorithms.

#ifndef SORT_STATS_H_
#define SORT_STATS_H_

// Contains the main values to measure the execution performance
// in sorting algorithms.
struct SortStats
{
    int array_length;
    unsigned long long iterations;
    unsigned long long comparisons;
    unsigned long long swaps;
    unsigned long long extra_memory;
};

// Initializes 'stats'.
void InitSortStats(SortStats *stats);

// Prints 'stats' in a formatted way.
void PrintSortStats(const SortStats& stats);

#endif // SORT_STATS_H_
