#ifndef HELPERS_H
#define HELPERS_H

    void        generateRandomArray(int arr[], int size);
    void        measureTime(int (*func)(int[], int), int arr[], int n, const char *algorithm);
    int         maxCrossingSum(int nums[], int left, int mid, int right);
    void        loadingEffect(int total);
    void        *threadFunc(void *arg);
    void        printFooter();
    void        printHeader();

#endif