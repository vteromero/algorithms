#include "bubble-sort.h"

BubbleSort::BubbleSort() {}

BubbleSort::~BubbleSort() {}

void BubbleSort::Sort(int *array, int length)
{
    int n = length;

    while(n > 0)
    {
        int newn = 0;

        for(int i=1; i<n; ++i)
        {
            if(array[i - 1] > array[i])
            {
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
