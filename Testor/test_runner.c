/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:10:45 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 13:09:47 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "tests.h"  // Include your test header
extern int test_ft_toupper(const char *input);
extern int test_ft_strlen_random(const char *input);
extern int test_ft_tolower(const char *input);
extern int test_ft_memcpy_random(const char *input);

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    srand(time(NULL)); // Seed the random number generator
    
    // Ask the user for input (short or detailed)
    printf("Enter 'short' for short explanations or 'detailed' for detailed explanations: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove the newline character from input if present
    input[strcspn(input, "\n")] = 0; 

    // Formatting for better output readability
    printf("\033[1;34m========================================\033[0m\n");
    printf("\033[1;34m  Running Tests - %d Repeats Each  \033[0m\n", NUM_TEST_REPEATS);
    printf("\033[1;34m========================================\033[0m\n\n");

    // Conditionally run tests based on user input
    if (strcmp(input, "short") == 0) {
        printf("Running tests with short explanations...\n");
        // Quick tests (a smaller subset of tests)
        TEST(test_ft_toupper, input);  // Pass the user input to each test
        TEST(test_ft_strlen_random, input);  // Example: 1 test function
    } else if (strcmp(input, "detailed") == 0) {
        printf("Running tests with detailed explanations...\n");
        // Detailed tests (all the tests)
        TEST(test_ft_toupper, input);  // Pass the user input to each test
        TEST(test_ft_strlen_random, input);
        TEST(test_ft_tolower, input);
        TEST(test_ft_memcpy_random, input);
        // Add more test functions as needed
    } else {
        printf("Invalid input! Please enter 'short' or 'detailed'.\n");
    }

    // Final message after tests are done
    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;34m     All Tests Completed!              \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n");

    return 0;
}
