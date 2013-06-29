#include "merge-sort.h"

#include <algorithm>
#include <limits.h>

MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

void MergeSort::Sort(int *array, int length)
{
    SortRange(array, 0, length);
}

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

    left[length1] = INT_MAX;
    right[length2] = INT_MAX;

    int start = start1;
    int end = start1 + length1 + length2;

    for(int i=0, j=0, k=start; k<end; ++k)
    {
        if(left[i] < right[j])
        {
            array[k] = left[i];
            ++i;
        }
        else if(right[j] < left[i])
        {
            array[k] = right[j];
            ++j;
        }
        else
        {
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
