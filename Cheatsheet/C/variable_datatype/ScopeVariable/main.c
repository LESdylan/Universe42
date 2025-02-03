/**
 * function Prototype Scope
 * Block scope
 * File Scope || Global Scope
 * Function Scope
 */
#include <stdio.h>

// Function Prototype (function scope)
int sub(int num1, int num2);

// File scope (global variables)
int num1 = 10;
int global = 5;
const int intVal = 10;
const float floatVal = 4.14;
const char charVal = 'A';
const char StringVal[10] = "ABC";

// Function to demonstrate type conversion
void type_conversion() {
    int intVal = 9;
    float floatVal = 9.5;
    
    // Implicit conversion: int to float
    float result = intVal + floatVal;
    printf("Implicit conversion result: %f\n", result);
    
    // Explicit conversion: float to int
    int resultInt = (int) floatVal;
    printf("Explicit conversion result: %d\n", resultInt);
}

// Function to demonstrate literals usage
void literals() {
    // Integer literal
    int integerLiteral = 100;               
    // Float literal
    float floatLiteral = 10.5;              
    // Char literal
    char charLiteral = 'A';                 
    // String literal
    const char* stringLiteral = "Hello!";   

    // Displaying basic literals
    printf("Integer literal: %d\n", integerLiteral);
    printf("Float literal: %f\n", floatLiteral);
    printf("Char literal: %c\n", charLiteral);
    printf("String literal: %s\n", stringLiteral);

    // Numeric prefixes and suffixes:
    
    // Prefixes
    int decimal = 110;            // Decimal literal
    int octal = 0123;             // Octal literal (starts with 0)
    int hexadecimal = 0x10C;      // Hexadecimal literal (starts with 0x)
    int binary = 0b1101;          // Binary literal (C99 and beyond, starts with 0b)

    // Suffixes
    long long int lo = 14116545445442212LL;  // Long long integer literal with LL suffix
    float power = 12e10;                     // Scientific notation literal for float
    float floa = 1.141519f;                  // Float literal with f suffix

    // Displaying the numeric literals
    printf("Decimal literal: %d\n", decimal);
    printf("Octal literal (0123): %d\n", octal);
    printf("Hexadecimal literal (0x10C): %d\n", hexadecimal);
    printf("Binary literal (0b1101): %d\n", binary);
    
    // Displaying the literals with suffixes
    printf("Long long literal (14116545445442212LL): %lld\n", lo);
    printf("Scientific notation (12e10): %e\n", power);
    printf("Float literal (1.141519f): %f\n", floa);
}

// Function to subtract two numbers
int sub(int num1, int num2) {
    return (num1 - num2);
}

// Display function to print the value of the global variable
void display() {
    printf("Global value: %d\n", global);
}

// Function to demonstrate goto usage with labels
void func1() {
    int a = 5, b = 10;
    printf("Inside func1, before jump: a = %d, b = %d\n", a, b);

    // Jumping to label_exec
    goto label_exec;
    
    // This block will be skipped due to the jump above
    printf("This line will be skipped\n");

label_exec:
    printf("Inside func1, after jump: a = %d, b = %d\n", a, b);
}

// Another function to demonstrate goto usage in a different context
void func2() {
    int a = 20, b = 30;
    printf("Inside func2, before jump: a = %d, b = %d\n", a, b);

    // Jumping to label_exec_func2
    goto label_exec_func2;
    
    // This block will be skipped due to the jump above
    printf("This line will be skipped\n");

label_exec_func2:
    printf("Inside func2, after jump: a = %d, b = %d\n", a, b);
}

int main(void) {
    int num2 = 20; // Block scope variable
    
    puts("Before change within main:");
    display(); // Will print the value of the global variable

    puts("After change within main:");
    global = 10; // Modifying the global variable
    int x = sub(num1, num2); // Function call with global and local variables
    display(); // Will print the modified value of global

    {
        // Inner block scope
        printf("x = %d, global = %d\n", x, global); // Print values of x and global

        {
            // Nested block scope
            x++; // Increment x in this block
            global++; // Increment global in this block
            printf("x = %d && global = %d\n", x, global); // Print updated values of x and global
        }

        // Values of x and global after the inner block
        printf("x = %d, global = %d\n", x, global); // x was incremented in the inner block, global was also incremented
    }

    // Calling func1 to demonstrate goto
    func1();

    // Calling func2 to demonstrate goto
    func2();

    // Demonstrating type conversions
    type_conversion();

    // Demonstrating literals
    literals();

    return 0;
}
