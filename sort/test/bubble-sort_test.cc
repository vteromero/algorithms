// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// This file tests the BubbleSort class

#include <stdio.h>

#include "sort/bubble-sort.h"
#include "sort/sort-stats.h"
#include "util/int-array.h"

int main()
{
    int array[] = {
        -2569, 17, 1, -5789, 986, 42, -170, -87, -136, -20,
        428, 15, 64, 8983, 1424, -627, 53, -13, 95, 20,
        -37, 1086, 136, -322, 179, 38, -1, 16, -135, 975,
        -103, -5045, 10, 1722, 16, 406, 591, -879, 33, 6,
        -867, 99, -139, -166, -15, -199, -3952, -1734, 174, 217
    };
    int length = NELEMS(array);

    printf("\nInitial array:\n");
    PrintArray(array, length);

    BubbleSort bsort;
    bsort.Sort(array, length);

    printf("\nSorted array:\n");
    PrintArray(array, length);

    bool sorted = CheckSortedArray(array, length, ASC_SORT);
    if(sorted)
        printf("\nChecking array... The array is sorted.\n");
    else
        printf("\nChecking array... The array is NOT sorted.\n");



    SortStats *stats = bsort.Statistics();
    if(stats != NULL)
        PrintSortStats(*stats);

    return 0;
}
