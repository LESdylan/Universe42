#include <stdio.h>
#include <ctype.h>
#include "../include/tests.h"

int main() {
    // Test pour un ensemble de caractères
    char test_chars[] = {'m', 'Z', '!', '5', ' '};
    
    for (int i = 0; i < 5; i++) {
        char c = test_chars[i];
        int expected = isalnum((unsigned char)c);  // Test isalnumç
        int expecte_s = ft_isalnum((unsigned char)c);
        printf("Character: '%c' (ASCII: %d) - Expected (isalnum): %d\n", c, c, expected);
        printf("\033[32m\nCharacter: '%c' (ASCII: %d) - Expected (ft_isalnum) :%d\033[0m\n", c, c, expecte_s);
    }
    
    return 0;
}