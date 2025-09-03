#include <stdio.h>

int main() {
    int num = 42;
    float fnum = 3.14159;
    char str[] = "HelloWorld";

    // 1. Width 
    printf("Width examples:\n");
    printf("|%5d|\n", num);     // Right-align with spaces
    printf("|%-5d|\n", num);    // Left-align
    printf("|%10s|\n", str);   // String width
    printf("|%-10s|\n", str);  // Left-aligned string
    printf("\n");

    // 2. Precision 
    printf("Precision examples:\n");
    printf("|%.5d|\n", num);    // Leading zeros
    printf("|%.2f|\n", fnum);   // Two decimal places
    printf("|%.3s|\n", str);   // Truncate string to 3 chars
    printf("\n");

    // 3. Width + Precision
    printf("Width + Precision examples:\n");
    printf("|%6.4d|\n", num);    // Min 4 digits, total width 6
    printf("|%8.2f|\n", fnum);   // Width 8, 2 decimal places
    printf("|%10.3s|\n", str);  // Width 10, max 3 characters
    printf("\n");

    // 4. Left Justification
    printf("Left Justification examples:\n");
    printf("|%-8.2f|\n", fnum);  // Left-align float
    printf("|%-6.4d|\n", num);   // Left-align integer
    printf("\n");

    // 5. Zero Padding
    printf("Zero Padding examples:\n");
    printf("|%05d|\n", num);     // Leading zeros
    printf("|%08.2f|\n", fnum);  // Zero padding float
    printf("\n");

    // 6. Combining Flags
    printf("Combining Flags examples:\n");
    printf("|%-8.5d|\n", num);   // Left-align, min 5 digits
    printf("|%-8.2f|\n", fnum);  // Left-align float
    printf("|%08.2f|\n", fnum);  // Zero padding + precision
    printf("\n");

    return 0;
}