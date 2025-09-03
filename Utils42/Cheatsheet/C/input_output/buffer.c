#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 20

void demonstrate_buffer_usage() {
    char buffer[MAX_BUFFER_SIZE];

    // 1. Reading input into the buffer with scanf (Unsafe - potential overflow)
    printf("Enter a string (up to 20 characters): ");
    scanf("%s", buffer); // This will not check the size of the input, so buffer overflow can occur if the input is too long.
    
    printf("You entered (scanf): %s\n", buffer);
}

void demonstrate_safe_buffer_usage() {
    char buffer[MAX_BUFFER_SIZE];

    // 2. Using fgets (Safe - with buffer size check)
    printf("Enter a string (up to 20 characters): ");
    fgets(buffer, sizeof(buffer), stdin); // fgets takes care of the buffer size limit
    
    // Remove trailing newline character that fgets may leave behind
    buffer[strcspn(buffer, "\n")] = '\0'; // This removes the newline character if present
    
    printf("You entered (fgets): %s\n", buffer);
}

void buffer_overflow_demo() {
    char buffer[10];  // Small buffer of size 10
    printf("Enter a string (buffer overflow demo): ");
    scanf("%s", buffer); // Unsafe: this doesn't check input size, and can cause buffer overflow
    
    printf("You entered: %s\n", buffer); // This could cause unexpected behavior if input exceeds the buffer size
}

int main() {
    // Demonstrate buffer usage with unsafe method (scanf)
    demonstrate_buffer_usage();

    // Demonstrate buffer usage with safe method (fgets)
    demonstrate_safe_buffer_usage();

    // Demonstrate buffer overflow risk
    buffer_overflow_demo();

    return 0;
}
