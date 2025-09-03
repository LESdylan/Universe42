#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // Integer types
    printf("Integer Data Types:\n");

    // int
    printf("int: %lu bytes, Range: %d to %d\n", sizeof(int), INT_MIN, INT_MAX);

    // short
    printf("short: %lu bytes, Range: %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);

    // long
    printf("long: %lu bytes, Range: %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);

    // long long
    printf("long long: %lu bytes, Range: %lld to %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);

    // Unsigned integer types
    printf("\nUnsigned Integer Data Types:\n");

    // unsigned int
    printf("unsigned int: %lu bytes, Range: 0 to %u\n", sizeof(unsigned int), UINT_MAX);

    // unsigned short
    printf("unsigned short: %lu bytes, Range: 0 to %hu\n", sizeof(unsigned short), USHRT_MAX);

    // unsigned long
    printf("unsigned long: %lu bytes, Range: 0 to %lu\n", sizeof(unsigned long), ULONG_MAX);

    // unsigned long long
    printf("unsigned long long: %lu bytes, Range: 0 to %llu\n", sizeof(unsigned long long), ULLONG_MAX);

    // Floating-point types
    printf("\nFloating-point Data Types:\n");

    // float
    printf("float: %lu bytes, Range: %e to %e\n", sizeof(float), FLT_MIN, FLT_MAX);

    // double
    printf("double: %lu bytes, Range: %e to %e\n", sizeof(double), DBL_MIN, DBL_MAX);

    // long double
    printf("long double: %lu bytes, Range: %Le to %Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // Character types
    printf("\nCharacter Data Types:\n");

    // char
    printf("char: %lu bytes, Range: %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);

    // signed char
    printf("signed char: %lu bytes, Range: %d to %d\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);

    // unsigned char
    printf("unsigned char: %lu bytes, Range: 0 to %u\n", sizeof(unsigned char), UCHAR_MAX);

    return 0;
}
