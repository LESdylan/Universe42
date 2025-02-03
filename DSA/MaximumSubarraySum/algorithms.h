#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include "helpers.h"

// Declare global variables as extern
extern int threadsCompleted;  // Global counter to track completed threads
extern pthread_mutex_t mutex;  // Mutex for thread safety

// Structure for thread arguments
typedef struct {
    int (*func2)(int[], int);       // Function for algorithms with 2 arguments
    int (*func3)(int[], int, int);  // Function for algorithms with 3 arguments
    int *arr;                       // Array of integers
    int n;                          // Size of the array
    int left;                       // Left index (for divide and conquer)
    int right;                      // Right index (for divide and conquer)
    const char *algorithm;          // Algorithm name
    int isThreeArgs;                // Indicator for whether the algorithm takes 3 arguments
    double timeTaken;               // Time taken for the calculation
    int result;                     // Result of the calculation
}           ThreadArgs;

int         maxSubArrayBruteForce(int nums[], int n);
int         maxSubArrayCumulatedSum(int nums[], int n);
int         maxSubArrayDivideConquer(int nums[], int left, int right);
int         maxSubArrayKadane(int nums[], int n);

#endif // ALGORITHMS_H
