/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:54:38 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 14:38:12 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <ctype.h>

int test_ft_isalnum_random(const char *input) {
    for (int i = 0; i < NUM_TEST_REPEATS; i++) {
        char random_char = generate_random_char();

        // Decide on the level of explanation
        if (strcmp(input, "short") == 0) {
            // Short explanation: print basic information
            printf("Generated character: '%c' (ASCII: %d)\n", random_char, random_char);
            printf("Expected (isalnum): %d, Actual (ft_isalnum): %d\n", 
                isalnum((unsigned char)random_char) != 0, ft_isalnum(random_char));
        } else if (strcmp(input, "detailed") == 0) {
            // Detailed explanation: print more information
            printf("Generated character: '%c' (ASCII: %d)\n", random_char, random_char);
            printf("Expected result based on isalnum: %d\n", 
                isalnum((unsigned char)random_char) != 0);
            printf("Actual result from ft_isalnum: %d\n", ft_isalnum(random_char));
            printf("Comparing if '%c' is alphanumeric (expecting 1 for alphanumeric, 0 for non-alphanumeric)\n", random_char);
        }

        // Normalize the expected result to 0 or 1
        int expected = isalnum((unsigned char)random_char) != 0;
        int actual = ft_isalnum(random_char);

        // Check if expected and actual results match
        if (expected != actual) {
            // If they differ, the test fails
            printf("Test failed for character: '%c' (ASCII: %d)\n", random_char, random_char);
            TEST_FAIL("test_ft_isalnum_random");
            return 0; // Return immediately on failure
        }
    }

    // If all checks pass
    TEST_PASS("test_ft_isalnum_random");
    return 1;
}