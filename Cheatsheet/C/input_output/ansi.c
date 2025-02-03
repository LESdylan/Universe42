#include <stdio.h>

int main() {
    // Color codes and styles using ANSI escape sequences
    printf("\e[1;31mThis is red text (Bold)\e[0m\n");          // Bold red text
    printf("\e[0;32mThis is green text (Normal)\e[0m\n");       // Normal green text
    printf("\e[1;34mThis is blue text (Bold)\e[0m\n");          // Bold blue text
    printf("\e[0;33mThis is yellow text (Normal)\e[0m\n");      // Normal yellow text
    printf("\e[1;35mThis is magenta text (Bold)\e[0m\n");       // Bold magenta text
    printf("\e[0;36mThis is cyan text (Normal)\e[0m\n");        // Normal cyan text
    printf("\e[1;37mThis is white text (Bold)\e[0m\n");         // Bold white text
    printf("\e[0;30mThis is black text (Normal)\e[0m\n");       // Normal black text (Foreground)

    // Background colors
    printf("\e[41mThis is red background\e[0m\n");              // Red background
    printf("\e[42mThis is green background\e[0m\n");            // Green background
    printf("\e[43mThis is yellow background\e[0m\n");           // Yellow background
    printf("\e[44mThis is blue background\e[0m\n");             // Blue background

    // Style combinations
    printf("\e[1;33m\e[44mThis is bold yellow text with blue background\e[0m\n");

    // Text effects
    printf("\e[3mThis is italic text\e[0m\n");                  // Italic text
    printf("\e[4mThis is underlined text\e[0m\n");               // Underlined text
    printf("\e[9mThis is crossed-out text\e[0m\n");              // Strikethrough text

    // Moving the cursor around
    printf("\e[H\e[2J");  // Clear screen
    printf("\e[10;10HThis text appears at row 10, column 10!\n");

    // Blinking text (might not work on all terminals)
    printf("\e[5mThis is blinking text\e[0m\n");

    // Resetting everything to default
    printf("\e[0mThis is normal text again.\n");

    return 0;
}
