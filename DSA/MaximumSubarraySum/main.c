#include "algorithms.h"


int main() {
    int n = 100000;  // Size of the array
    int *arr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation failed
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    generateRandomArray(arr, n);  // Generate the random array

    pthread_t threads[4];  // Array to store threads
    ThreadArgs args[4];    // Array to store arguments for each thread

    // Initialize arguments for each algorithm
    args[0].func2 = maxSubArrayBruteForce;  // Function with 2 arguments
    args[0].arr = arr;
    args[0].n = n;
    args[0].algorithm = "Brute Force";
    args[0].left = 0;
    args[0].right = n - 1;
    args[0].isThreeArgs = 0;

    args[1].func2 = maxSubArrayCumulatedSum;  // Function with 2 arguments
    args[1].arr = arr;
    args[1].n = n;
    args[1].algorithm = "Cumulated Sum";
    args[1].left = 0;
    args[1].right = n - 1;
    args[1].isThreeArgs = 0;

    args[2].func3 = maxSubArrayDivideConquer;  // Function with 3 arguments
    args[2].arr = arr;
    args[2].n = n;
    args[2].algorithm = "Divide & Conquer";
    args[2].left = 0;
    args[2].right = n - 1;
    args[2].isThreeArgs = 1;

    args[3].func2 = maxSubArrayKadane;  // Function with 2 arguments
    args[3].arr = arr;
    args[3].n = n;
    args[3].algorithm = "Kadane's Algorithm";
    args[3].left = 0;
    args[3].right = n - 1;
    args[3].isThreeArgs = 0;

    // Print the starting message
    printf("Starting computation with 4 different algorithms...\n\n");

    // Create the threads asynchronously
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, threadFunc, (void*)&args[i]);
    }

    // Display progress dynamically while the threads are running
    while (threadsCompleted < 4) {
        loadingEffect(4);  // Update the loading effect with total 4 threads
        usleep(100000);  // Sleep for a short period to update progress
    }

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);  // Join each thread
    }

    // Print the result table
    printHeader();
    for (int i = 0; i < 4; i++) {
        printf("%-25s | %-15.6f | %-6d\n", args[i].algorithm, args[i].timeTaken, args[i].result);
    }
    printFooter();

    // Free the allocated memory
    free(arr);

    return 0;
}
