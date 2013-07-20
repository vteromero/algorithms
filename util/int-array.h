// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// A bunch of functions for dealing with integer arrays.

#ifndef INT_ARRAY_H_
#define INT_ARRAY_H_

// Calculates the length of the array 'x'
#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

// Loads an integer array from a file name. The array is loaded
// in the 'array' output param and its length is returned in the
// 'length' output param.
int LoadArrayFromFile(const char* filename, int **array, int *length);

// Saves an integer array in a file.
int SaveArrayToFile(const char* filename, int *array, int length);

// Creates a sparse random array of integer numbers.
// A sparse array is an array which holds n random elements.
int *CreateSparseRandomArray(int n);

// Creates a continuous random array of integer numbers.
// A continuous random array is an array which holds all the integers
// from 0 to n-1 in a random way.
int *CreateContinuousRandomArray(int n);

#endif // INT_ARRAY_H_
