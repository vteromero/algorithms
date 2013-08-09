// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "sort-stats.h"

#include <stdio.h>
#include <cmath>

void InitSortStats(SortStats *stats)
{
    stats->array_length = 0;
    stats->iterations = 0;
    stats->comparisons = 0;
    stats->swaps = 0;
    stats->extra_memory = 0;
}

void PrintSortStats(const SortStats& stats)
{
    double one_n = 1.0 / (double)stats.array_length;
    double iter_n = stats.iterations * one_n;
    double comp_n = stats.comparisons * one_n;
    double swaps_n = stats.swaps * one_n;

    double log2n = log2(stats.array_length);
    long long square_n = stats.array_length * stats.array_length;

    printf("\n** Stats **\n\n");
    printf("%-20s%20d\n", "Array length (N):", stats.array_length);
    printf("%-20s%20llu%10.1f*N\n", "Iterations:", stats.iterations, iter_n);
    printf("%-20s%20llu%10.1f*N\n", "Comparisons:", stats.comparisons, comp_n);
    printf("%-20s%20llu%10.1f*N\n", "Swaps:", stats.swaps, swaps_n);
    printf("%-20s%20llu bytes\n", "Extra memory:", stats.extra_memory);
    printf("\nReference metrics:\n");
    printf("    log2(N) = %.1f\n", log2n);
    printf("    N^2 = %lld\n", square_n);
}
