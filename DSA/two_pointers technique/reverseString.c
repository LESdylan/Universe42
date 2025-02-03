#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // For performance measurement

char *reverseString(char *s, int sSize) {
    if (s == NULL || sSize <= 0) {
        fprintf(stderr, "Invalid input: String is NULL or size is non-positive.\n");
        return NULL;
    }

    char temp;
    char *left = s;
    char *right = s + sSize - 1;

    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }

    return s;
}

int main() {
    // Dynamically allocate or properly initialize a test string
    char s[] = "hello, world!"; // Mutable array
    int size = strlen(s);       // Calculate the length of the string

    printf("Original: %s\n", s);

    // Record the start time
    clock_t start = clock();

    // Reverse the string
    reverseString(s, size);

    // Record the end time
    clock_t end = clock();

    printf("Reversed: %s\n", s);

    // Calculate elapsed time in milliseconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    printf("Time taken to reverse the string: %.3f ms\n", time_taken);

    return 0;
}
