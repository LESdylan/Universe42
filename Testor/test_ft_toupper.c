/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:31:21 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 12:53:56 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
int test_ft_toupper(const char *input)
{
    // Generate a random character for testing
    char random_character = generate_random_char();
    int expected = toupper(random_character); // Standard library version
    int result = ft_toupper(random_character); // Your custom implementation

    // Short or detailed explanation based on input
    if (strcmp(input, "detailed") == 0) {
        // Detailed explanation: show character, ASCII value, expected and actual results
        printf("\033[1;34mTesting character: '%c' (ASCII: %d)\033[0m\n", random_character, random_character);
        printf("Expected (toupper): %d, Actual (ft_toupper): %d\n", expected, result);

        // Compare results
        if (expected != result) {
            // If results don't match, show detailed failure message
            fprintf(stderr, "\033[31mTest failed for character '%c' (ASCII: %d) because the uppercase conversion didn't match.\033[0m\n", random_character, random_character);
            TEST_FAIL("test_ft_toupper");
            return 0; // Return early on failure
        }

        // Success message for detailed output
        printf("\033[32mTest passed for character '%c' (ASCII: %d) – the result matches the expected uppercase conversion.\033[0m\n", random_character, random_character);
    } else {
        // Short explanation: just a quick summary
        if (expected != result) {
            printf("\033[31mTest failed for character '%c'.\033[0m\n", random_character);
            TEST_FAIL("test_ft_toupper");
            return 0; // Return early on failure
        }
        printf("\033[32mTest passed for character '%c'.\033[0m\n", random_character);
    }

    // Final success message for the test function
    TEST_PASS("test_ft_toupper");
    return 1; // Return success if the test passed
}
