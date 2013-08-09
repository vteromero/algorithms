// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// This file tests the MergeSort class

#include <stdio.h>

#include "sort/merge-sort.h"
#include "sort/sort-stats.h"
#include "util/int-array.h"

int main()
{
    MergeSort msort;
    int array[] = {22, 4, 3, 7, 11, 34, 9, 1, 6, 2, 2, 66, 6, 4, 88, 83};
    int length = NELEMS(array);

    msort.Sort(array, length);

    printf("Values:");
    for(int i=0; i<length; ++i)
        printf(" %d", array[i]);
    printf("\n");

    SortStats *stats = msort.Statistics();
    if(stats != NULL)
        PrintSortStats(*stats);

    return 0;
}
