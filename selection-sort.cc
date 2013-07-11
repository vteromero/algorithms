#include "selection-sort.h"

SelectionSort::SelectionSort() {}

SelectionSort::~SelectionSort() {}

void SelectionSort::Sort(int *array, int length)
{
    for(int i=0; i<length-1; ++i)
    {
        int min = i;

        for(int j=i+1; j<length; ++j)
        {
            if(array[j] < array[min])
                min = j;
        }

        if(min != i)
        {
            // swap
            int aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }
}
