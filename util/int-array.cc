// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "int-array.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

int LoadArrayFromFile(const char* filename, int **array, int *length)
{
    *array = NULL;
    *length = 0;

    FILE *f = fopen(filename, "r");
    if(f == NULL)
        return 0;

    if(fscanf(f, "%d", length) <= 0)
    {
        fclose(f);
        return 0;
    }

    *array = new int[*length];

    for(int i=0; i<*length; ++i)
    {
        if(fscanf(f, "%d", &((*array)[i])) <= 0)
        {
            fclose(f);
            return 0;
        }
    }

    fclose(f);

    return 1;
}

int SaveArrayToFile(const char* filename, int *array, int length)
{
    FILE *file = fopen(filename, "w");
    if(file == NULL)
        return 0;

    if(fprintf(file, "%d\n", length) <= 0)
    {
        fclose(file);
        return 0;
    }

    for(int i=0; i<length; ++i)
    {
        if(fprintf(file, "%d ", array[i]) <= 0)
        {
            fclose(file);
            return 0;
        }
    }

    fclose(file);

    return 1;
}

int *CreateSparseRandomArray(int n)
{
    srand(time(NULL));

    int *result = new int[n];

    for(int i=0; i<n; ++i)
        result[i] = rand();

    return result;
}

int *CreateContinuousRandomArray(int n)
{
    std::vector<int> vint;

    for(int i=0; i<n; ++i)
        vint.push_back(i);

    srand(time(NULL));

    int *result = new int[n];

    int elements = n;
    int i = 0;
    while(elements > 0)
    {
        int ind = rand() % elements;

        result[i] = vint[ind];

        vint.erase(vint.begin() + ind);

        ++i;
        --elements;
    }

    return result;
}
