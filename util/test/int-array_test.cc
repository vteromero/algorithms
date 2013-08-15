// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// This file tests the functions defined in int-array.h

#include <stdio.h>
#include <string.h>

#include "util/int-array.h"

void Usage(const char *name)
{
    printf("Usage:\n");
    printf("  %s load <filename>\n", name);
    printf("  %s save <n> <type> <filename>\n", name);
    printf("\nParams:\n");
    printf("  <filename>: File name to be loaded or saved\n");
    printf("  <n>: Array size (positive integer)\n");
    printf("  <type>: sparse | continuous\n");
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        Usage(argv[0]);
        return 1;
    }

    int *array = NULL;
    int length = 0;

    if(strcmp(argv[1], "load") == 0)
    {
        if(argc < 3)
        {
            Usage(argv[0]);
            return 1;
        }

        if(LoadArrayFromFile(argv[2], &array, &length))
        {
            printf("Loaded successfully!\n");

            PrintArray(array, length);

            delete [] array;
        }
        else
        {
            printf("Error loading the file '%s'\n", argv[2]);

            if(array != NULL)
                delete [] array;

            return 1;
        }
    }
    else if(strcmp(argv[1], "save") == 0)
    {
        if(argc < 5)
        {
            Usage(argv[0]);
            return 1;
        }

        sscanf(argv[2], "%d", &length);
        if(length <= 0)
        {
            Usage(argv[0]);
            return 1;
        }

        if(strcmp(argv[3], "continuous") == 0)
        {
            array = CreateContinuousRandomArray(length);
        }
        else if(strcmp(argv[3], "sparse") == 0)
        {
            array = CreateSparseRandomArray(length);
        }
        else
        {
            Usage(argv[0]);
            return 1;
        }

        if(SaveArrayToFile(argv[4], array, length))
        {
            printf("Saved successfully!\n");

            PrintArray(array, length);

            delete [] array;
        }
        else
        {
            printf("Error saving the file '%s'\n", argv[4]);

            if(array != NULL)
                delete [] array;

            return 1;
        }
    }
    else
    {
        Usage(argv[0]);
        return 1;
    }

    return 0;
}
