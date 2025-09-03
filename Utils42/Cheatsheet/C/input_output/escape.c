#include <stdio.h>

int main() {
    // 1. Newline
    printf("Hello, World!\n");

    // 2. Horizontal tab
    printf("Column1\tColumn2\tColumn3\n");

    // 3. Carriage return
    printf("Hello\rWorld\n");

    // 4. Backspace (deletes the previous character)
    printf("Hello\bWorld\n");

    // 5. Form feed (moves to the next page in some environments, but may not be visible in many)
    printf("Hello\fWorld\n");

    // 6. Vertical tab (similar to form feed, but moves vertically)
    printf("Hello\vWorld\n");

    // 7. Backslash
    printf("This is a backslash: \\\n");

    // 8. Single quote
    printf("Single quote: \'\n");

    // 9. Double quote
    printf("Double quote: \"Hello!\"\n");

    // 10. Question mark (to avoid conflict with escape sequences)
    printf("What is this? \\?\n");

    // 11. Null character (will end the string if printed directly, but typically used internally in C)
    printf("Null character: Hello\0 World\n");

    // 12. Hexadecimal value (ASCII code for 'A')
    printf("Hexadecimal A: \x41\n");

    // 13. Octal value (ASCII code for newline)
    printf("Octal newline: \012End of line\n");

    return 0;
}
