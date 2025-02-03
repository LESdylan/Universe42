/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:54:24 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 12:50:11 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
int test_ft_strlen_random(const char *input)
{
    for (int i = 0; i < NUM_TEST_REPEATS; i++) {
        // Generate a random length for the string
        size_t length = generate_random_number(1, 100);
        
        // Allocate memory for the string
        char *random_str = malloc(length + 1);  // +1 for null-terminator
        if (!random_str) {
            printf("Memory allocation failed\n");
            return 0;
        }

        // Generate a random string of that length
        generate_random_string(random_str, length);
        
        // Calculate the expected and actual results
        size_t expected = strlen(random_str);
        size_t actual = ft_strlen(random_str);

        // Decide on the level of explanation
        if (strcmp(input, "short") == 0) {
            // Short explanation: just print basic details
            printf("Testing string length: '%s' (Length: %zu)\n", random_str, length);
            printf("Expected: %zu, Actual: %zu\n", expected, actual);
        } else if (strcmp(input, "detailed") == 0) {
            // Detailed explanation: print more descriptive information
            printf("Testing string: '%s' (ASCII values and length: %zu)\n", random_str, length);
            printf("Expected length (strlen): %zu, Actual length (ft_strlen): %zu\n", expected, actual);
            // Show each character's ASCII value for more clarity
            printf("String details (ASCII): ");
            for (size_t j = 0; j < length; j++) {
                printf("'%c'(%d) ", random_str[j], random_str[j]);
            }
            printf("\n");
        }
        
        // Validate the result and output success/failure
        if (expected != actual) {
            printf("Test failed for string: '%s' (Length: %zu)\n", random_str, length);
            TEST_FAIL("test_ft_strlen_random");
            free(random_str);  // Don't forget to free the memory if the test fails
            return 0;
        }
        
        free(random_str);  // Free memory after test
    }
    TEST_PASS("test_ft_strlen_random");
    return 1;
}
