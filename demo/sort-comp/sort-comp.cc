// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// SortComp demo

#include <cassert>
#include <cmath>
#include <cstdio>
#include <limits>

#include "sort/bubble-sort.h"
#include "sort/insertion-sort.h"
#include "sort/merge-sort.h"
#include "sort/selection-sort.h"
#include "sort/isort.h"
#include "util/color-text.h"
#include "util/int-array.h"

struct ArrayInfo
{
    const char *filename;
    const char *short_name;
    int length;
} arrays[] = {
    {"data/arr-10.txt", "10", 10},
    {"data/arr-20.txt", "20", 20},
    {"data/arr-50.txt", "50", 50},
    {"data/arr-100.txt", "100", 100},
    {"data/arr-200.txt", "200", 200},
    {"data/arr-500.txt", "500", 500},
    {"data/arr-1K.txt", "1K", 1000},
    {"data/arr-2K.txt", "2K", 2000},
    {"data/arr-5K.txt", "5K", 5000},
    {"data/arr-10K.txt", "10K", 10000},
    {"data/arr-20K.txt", "20K", 20000},
    {"data/arr-50K.txt", "50K", 50000}
};

struct SortMethod
{
    const char *name;
    const char *short_name;
    ISort *method;
} sort_methods[] = {
    {"Bubble sort", "BUB", new BubbleSort},
    {"Insertion sort", "INS", new InsertionSort},
    {"Merge sort", "MER", new MergeSort},
    {"Selection sort", "SEL", new SelectionSort}
};

const int kMaxLineSize = 200;
const int kArraysLen = NELEMS(arrays);
const int kSortMethodsLen = NELEMS(sort_methods);

void GenerateRandomArrays()
{
    int *array=NULL, len, result;

    for(int i=0; i<kArraysLen; ++i)
    {
        len = arrays[i].length;
        array = CreateSparseRandomArray(len);

        result = SaveArrayToFile(arrays[i].filename, array, len);

        assert(result == 1);

        delete [] array;
    }
}

void PrintHeader()
{
    printf(
"\n** SortComp **\n"
"==============\n\n"
"It compares several sorting algorithms in order to measure their efficiency.\n"
"Initially, the program will generate a few random arrays and then they will\n"
"be sorted by using different sorting algorithms.\n"
"The measured value is the number of iterations divided by the size of the\n"
"array (N).\n\n"
    );
}

void PrintTableHeader()
{
    char line[kMaxLineSize];

    sprintf(line, "%-5s%12s", "N", "log2(N)");

    for(int i=0; i<kSortMethodsLen; ++i)
        sprintf(line, "%s%12s", line, sort_methods[i].short_name);

    printf("%s\n", line);
}

void PrintTable()
{
    int *array=NULL, len, result;
    ISort *method;
    SortStats *stats;
    char line[kMaxLineSize], strvalue[15], color_strvalue[40];
    unsigned long long iterations[kSortMethodsLen], maxiter, miniter;
    double one_n, iter_n, log2n;

    PrintTableHeader();

    for(int i=0; i<kArraysLen; ++i)
    {
        maxiter = std::numeric_limits<unsigned long long>::min();
        miniter = std::numeric_limits<unsigned long long>::max();
        one_n = 1.0 / (double)arrays[i].length; // 1 / N
        log2n = log2(arrays[i].length); // log2(N)

        sprintf(line, "%-5s%12.1f", arrays[i].short_name, log2n);

        for(int j=0; j<kSortMethodsLen; ++j)
        {
            result = LoadArrayFromFile(arrays[i].filename, &array, &len);

            assert(result == 1);

            method = sort_methods[j].method;
            method->Sort(array, len);
            stats = method->Statistics();

            iterations[j] = stats->iterations;

            if(iterations[j] > maxiter)
                maxiter = iterations[j];

            if(iterations[j] < miniter)
                miniter = iterations[j];

            delete [] array;
        }

        for(int j=0; j<kSortMethodsLen; ++j)
        {
            iter_n = iterations[j] * one_n;
            sprintf(strvalue, "%12.1f", iter_n);

            if(iterations[j] == maxiter)
                ColorText(
                    strvalue,
                    CT_STYLE_RESET_ALL,
                    CT_FG_RED,
                    CT_BG_DEFAULT,
                    color_strvalue);
            else if(iterations[j] == miniter)
                ColorText(
                    strvalue,
                    CT_STYLE_RESET_ALL,
                    CT_FG_GREEN,
                    CT_BG_DEFAULT,
                    color_strvalue);
            else
                ColorText(
                    strvalue,
                    CT_STYLE_RESET_ALL,
                    CT_FG_DARK_GRAY,
                    CT_BG_DEFAULT,
                    color_strvalue);

            sprintf(line, "%s%s", line, color_strvalue);
        }

        printf("%s\n", line);
    }
}

void PrintFooter()
{
    printf("\nAlgorithms:\n");
    for(int i=0; i<kSortMethodsLen; ++i)
        printf("  %s: %s\n", sort_methods[i].short_name, sort_methods[i].name);

    printf("\n");
}

int main()
{
    GenerateRandomArrays();

    PrintHeader();

    PrintTable();

    PrintFooter();

    return 0;
}
