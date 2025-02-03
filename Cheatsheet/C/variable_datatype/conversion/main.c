#include <stdio.h>

void implicit_conversion() {
    // Implicit Conversion Example
    int a = 5;
    double b = 10.5;
    
    // Implicit conversion of `a` (int) to `double` during addition
    double result = a + b;   // `a` is implicitly converted to `double`
    
    printf("Implicit Conversion:\n");
    printf("a = %d, b = %.2f\n", a, b);
    printf("a + b = %.2f\n", result);
}

void explicit_conversion() {
    // Explicit Conversion Example
    double x = 9.99;
    int y;

    // Explicit conversion (casting) of `x` (double) to `int`
    y = (int) x;  // This truncates the decimal part
    
    printf("\nExplicit Conversion:\n");
    printf("x = %.2f, y = %d (after explicit casting)\n", x, y);
}

int main() {
    // Demonstrate Implicit Conversion
    implicit_conversion();

    // Demonstrate Explicit Conversion
    explicit_conversion();

    return 0;
}
