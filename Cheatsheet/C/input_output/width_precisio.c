#include <stdio.h>

int main() {
    int number = 42;
    float pi = 3.14159;

    // Using width
    printf("Number with width: [%5d]\n", number);  // Output: "   42"

    // Using precision for floating-point
    printf("Pi with precision: [%.2f]\n", pi);  // Output: "3.14"

    // Using width and precision together for floating-point
    printf("Pi with width and precision: [%8.3f]\n", pi);  // Output: "   3.142"

    // Using width and precision together for integer
    printf("Number with width and precision: [%8.5d]\n", number);  // Output: "00042   "

    return 0;
}