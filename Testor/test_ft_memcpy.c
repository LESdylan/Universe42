/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:55:15 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 12:52:21 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
int test_ft_memcpy_random(const char *input) {
    for (int i = 0; i < NUM_TEST_REPEATS; i++) {
        int length = generate_random_number(1, 100); // Generate random length between 1 and 100
        char *src = malloc(length + 1); // +1 for the null terminator
        char *dest = malloc(length + 1);

        if (!src || !dest) {
            printf("Memory allocation failed\n");
            return 0;
        }

        generate_random_string(src, length);  // Fill the src string with random content

        // Decide on the level of explanation (short/detailed)
        if (strcmp(input, "short") == 0) {
            // Short explanation: just basic info about the test
            printf("Testing memcpy with source string: '%s' (Length: %d)\n", src, length);
            printf("Expected: source string copied correctly\n");
        } else if (strcmp(input, "detailed") == 0) {
            // Detailed explanation: more thorough info
            printf("Testing memcpy with source string: '%s' (Length: %d)\n", src, length);
            printf("Expected: source string copied correctly into destination\n");
            printf("Source (ASCII values): ");
            for (int j = 0; j < length; j++) {
                printf("'%c'(%d) ", src[j], src[j]);
            }
            printf("\nDestination (before memcpy): ");
            for (int j = 0; j < length; j++) {
                printf("'%c'(%d) ", dest[j], dest[j]);
            }
            printf("\n");
        }

        // Perform memcpy and validate
        ft_memcpy(dest, src, length + 1); // Copy the data from src to dest, including null terminator

        // Validate that the memory contents match using memcmp
        if (memcmp(src, dest, length + 1) != 0) {
            printf("Test failed: Memcpy did not copy the data correctly\n");
            TEST_FAIL("test_ft_memcpy_random");
            free(src);
            free(dest);
            return 0; // Return immediately on failure
        }
        free(src);
        free(dest);
    }

    TEST_PASS("test_ft_memcpy_random");
    return 1;
}