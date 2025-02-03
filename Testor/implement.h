/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:39:55 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2025/01/15 11:23:46 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLEMENT_H
#define IMPLEMENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define NUM_TEST_REPEATS 3
#define TEST_PASS(test_name) printf("[PASS] %s\n", test_name)
#define TEST_FAIL(test_name) printf("[FAIL] %s\n", test_name)

// Enum to define result types
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_CHAR,
} ResultType;
typedef void (*FuncWithVoidPtr)(void *input, void *output);

//utils
int generate_random_int();
char generate_random_char();
int generate_random_number(int min, int max);
char generate_random_ascii();
void generate_random_string(char *str, int length);
double fabs(double n);

//prototype of functions
void example_func(void *input, void *output);
int test_ft_isalnum_random(const char *mode);
int ft_isalnum(char c);
size_t ft_strlen(const char *s);
int test_ft_strlen_random(const char *input);

void log_error(const char *message);
void display_result(const char *func_name, void *input, void *expected, void *actual, ResultType type, bool detailed);
bool compare_results(void *expected, void *actual, ResultType type, bool debug, const char *log_file);
int test_function(const char *func_name, const char *mode, FuncWithVoidPtr func, void *test_input, void *expected_output, ResultType type);
#endif