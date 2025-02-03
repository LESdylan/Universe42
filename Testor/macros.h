/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:30:26 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 15:52:25 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
} ResultType;


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

// Symbols for test results
#define CHECKMARK "✔"
#define CROSS "✘"

/**
 * @description: Introduces a delay of 0.2 seconds between each test for a smoother display.
 */
#define NUM_TEST_REPEATS 100    // times number each function will repeat
#define MAX_INPUT_LENGTH 25
#define DELAY() usleep(200000)  // 0.2 seconds in microseconds
#define SIZE_MAX

// Test output macros with extra style
#define TEST_PASS(test_name)     printf(GREEN BOLD "%s " CHECKMARK "\n" RESET, test_name)
#define TEST_FAIL(test_name)     printf(RED BOLD "%s " CROSS "\n" RESET, test_name)
#define TEST_RUN(test_name)      printf(CYAN UNDERLINE "Running test: %s...\n" RESET, test_name)

/**
 * @description: Runs the test function and prints whether it passed or failed
 * @param func function that needs to be tested
 * @return 1 | 0
 */
#define TEST(func,input) \
    do { \
        DELAY(); \
        printf("\n" CYAN "========================================\n" RESET); \
        printf("Running test: " UNDERLINE "%s\n" RESET, #func); \
        if (func(input)) { \
            TEST_PASS(#func); \
        } else { \
            TEST_FAIL(#func); \
        } \
        printf(CYAN "========================================\n" RESET); \
    } while(0)

/**
 * @description: Check if the condition is true
 * @param cond the condition that needs to be checked so the function will return truthy or not
 * @return 0 | 1
 */
#define ASSERT(cond) \
    do { \
        if (!(cond)) { \
            printf(RED BOLD "Test failed: %s\n" RESET, #cond); \
            return 0; \
        } \
    } while(0)

#endif