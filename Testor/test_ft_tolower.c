/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:03:52 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 12:49:27 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <ctype.h>
#include <stdio.h>

int test_ft_tolower(const char *input)
{
    for (int i = 0; i < 5; i++) {
        char c = generate_random_char();  // Generate random character
        int expected = tolower(c);  // Expected result from the standard library
        int actual = ft_tolower(c);  // Result from the custom function

        // Decide on the level of explanation
        if (strcmp(input, "short") == 0) {
            printf("Testing character: '%c' (ASCII: %d)\n", c, c);
            printf("Expected: %d, Actual: %d\n", expected, actual);
        } else if (strcmp(input, "detailed") == 0) {
            printf("Testing character: '%c' (ASCII: %d)\n", c, c);
            printf("Expected (tolower): %d, Actual (ft_tolower): %d\n", expected, actual);
        }
        
        // Check if the function returned the correct result
        if (expected != actual) {
            printf("Test failed for character: %c (ASCII: %d)\n", c, c);
            TEST_FAIL("test_ft_tolower");
            return 0;
        }
    }
    
    // If the test passes
    TEST_PASS("test_ft_tolower");
    return 1;
}