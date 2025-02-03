#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // 1. Size of data types
    printf("Size of data types:\n");
    printf("Size of int: %zu bytes\n", sizeof(int));           // Integer type
    printf("Size of float: %zu bytes\n", sizeof(float));       // Floating point type
    printf("Size of double: %zu bytes\n", sizeof(double));     // Double type
    printf("Size of char: %zu bytes\n", sizeof(char));         // Char type
    printf("Size of long: %zu bytes\n", sizeof(long));         // Long type
    printf("Size of long long: %zu bytes\n", sizeof(long long)); // Long long type

    // 2. Size of variables
    int x = 10;
    double y = 3.14;
    char z = 'A';
    printf("\nSize of variables:\n");
    printf("Size of variable x (int): %zu bytes\n", sizeof(x));
    printf("Size of variable y (double): %zu bytes\n", sizeof(y));
    printf("Size of variable z (char): %zu bytes\n", sizeof(z));

    // 3. Size of arrays
    int arr[5] = {1, 2, 3, 4, 5};
    printf("\nSize of arrays:\n");
    printf("Size of array arr (int[5]): %zu bytes\n", sizeof(arr));        // Total size of array
    printf("Number of elements in arr: %zu\n", sizeof(arr) / sizeof(arr[0])); // Number of elements in array

    // 4. Size of pointers
    int *ptr = &x;
    double *ptr_double = &y;
    printf("\nSize of pointers:\n");
    printf("Size of pointer to int: %zu bytes\n", sizeof(ptr));            // Pointer to int
    printf("Size of pointer to double: %zu bytes\n", sizeof(ptr_double));  // Pointer to double

    // 5. Size of expressions
    printf("\nSize of expressions:\n");
    printf("Size of expression (x + 5): %zu bytes\n", sizeof(x + 5));        // Expression result type
    printf("Size of expression (x * y): %zu bytes\n", sizeof(x * y));        // Expression result type

    // 6. Size of struct (custom data type)
    struct Person {
        char name[50];
        int age;
        double height;
    };
    printf("\nSize of custom struct 'Person': %zu bytes\n", sizeof(struct Person));

    // 7. Size of union (custom data type)
    union Data {
        int i;
        float f;
        char str[20];
    };
    printf("\nSize of union 'Data': %zu bytes\n", sizeof(union Data));

    return 0;
}
