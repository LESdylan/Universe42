/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:55:55 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 14:25:54 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char generate_random_char() {
    int rand_val = rand() % 62;  // 62 possible values (0-9, a-z, A-Z)

    if (rand_val < 10) {
        return '0' + rand_val;  // Retourne un chiffre
    } else if (rand_val < 36) {
        return 'a' + (rand_val - 10);  // Retourne une lettre minuscule
    } else {
        return 'A' + (rand_val - 36);  // Retourne une lettre majuscule
    }
}
void generate_random_string(char *str, int length) {
    for (int i = 0; i < length; i++)
        str[i] = generate_random_char();
    str[length] = '\0';
}

// function to generate a randomm printable ASCI character(between 32 and 126)
char generate_random_ascii() {
    return (char)(rand() % 95 + 32); // 32 shift the random number into the printable ASCII
}

void display_short(void (*func1)(void *), void(*func2)(void *)), void (*func3)(void),)
{
    // show genereated literals
    // show the difference between expected with the name of the original function
    // and the expected result based about my functions
    // eventually just return  if the function worked or not
}

void display_detailed()
{
    
}

int test_ft_isalnum_random(const char *input) {
    for (int i = 0; i < NUM_TEST_REPEATS; i++) {
        char random_char = generate_random_char();

        // Decide on the level of explanation
        if (strcmp(input, "short") == 0) {
            // Short explanation: print basic information
            display_short()
        } else if (strcmp(input, "detailed") == 0) {
            // Detailed explanation: print more information
            display_detailed()
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