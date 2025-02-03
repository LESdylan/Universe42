/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_fn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:28:43 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/15 11:10:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "implement.h"
void log_error(const char *message) {
    FILE *logFile = fopen("error_log.txt", "a"); // Open in append mode
    if (logFile == NULL) {
        fprintf(stderr, "Unable to open log file for writing.\n");
        return;
    }

    // Get current timestamp
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp != NULL) {
        timestamp[strcspn(timestamp, "\n")] = '\0'; // Remove newline from ctime output
    }

    // Write error message and timestamp to the log file
    fprintf(logFile, "[%s] %s\n", timestamp, message);
    fclose(logFile);
}
// Display results (common for short and detailed modes)
void display_result(const char *func_name, void *input, void *expected, void *actual, ResultType type, bool detailed) {
    // Display the function name
    if (detailed) {
        printf("[DETAILED] Function: %s\n", func_name);
        printf("  Input Pointer: %p\n", input);
    } else {
        printf("[%s] Input: %p | ", func_name, input);
    }

    // Display the input value based on type
    printf("Input Value: ");
    switch (type) {
        case TYPE_INT:
            printf("%d\n", *(int *)input);
            break;
        case TYPE_FLOAT:
            printf("%.2f\n", *(float *)input);
            break;
        case TYPE_STRING:
            printf("%s\n", (char *)input);
            break;
        case TYPE_CHAR:
            printf("'%c'\n", *(char *)input);
            break;
    }

    // Display expected and actual results
    printf("  Expected: ");
    switch (type) {
        case TYPE_INT:
            printf("%d, ", *(int *)expected);
            break;
        case TYPE_FLOAT:
            printf("%.2f, ", *(float *)expected);
            break;
        case TYPE_STRING:
            printf("%s, ", (char *)expected);
            break;
        case TYPE_CHAR:
            printf("'%c', ", *(char *)expected);
            break;
    }

    printf("Actual: ");
    switch (type) {
        case TYPE_INT:
            printf("%d\n", *(int *)actual);
            break;
        case TYPE_FLOAT:
            printf("%.2f\n", *(float *)actual);
            break;
        case TYPE_STRING:
            printf("%s\n", (char *)actual);
            break;
        case TYPE_CHAR:
            printf("'%c'\n", *(char *)actual);
            break;
    }

    // Perform detailed comparison and display error if needed
    bool match = false;
    switch (type) {
        case TYPE_INT:
            match = (*(int *)expected == *(int *)actual);
            break;
        case TYPE_FLOAT:
            match = (*(float *)expected == *(float *)actual);
            break;
        case TYPE_STRING:
            match = (strcmp((char *)expected, (char *)actual) == 0);
            break;
        case TYPE_CHAR:
            match = (*(char *)expected == *(char *)actual);
            break;
    }

    if (!match) {
        if (detailed) {
            printf("  [ERROR] Results do not match!\n");
            printf("  Input Address: %p\n", input);
            printf("  Expected Address: %p, Actual Address: %p\n", expected, actual);
            if (type == TYPE_STRING) {
                printf("  String Lengths: Expected = %zu, Actual = %zu\n",
                       strlen((char *)expected), strlen((char *)actual));
            }
        } else {
            printf("  [ERROR] Mismatch in results.\n");
        }
    } else if (detailed) {
        printf("  [INFO] Results match.\n");
    }
}
// Helper to compare expected and actual results
bool compare_results(void *expected, void *actual, ResultType type, bool debug, const char *log_file) {
    bool match = false;

    // Open the log file if log_file is not NULL
    FILE *log = NULL;
    if (log_file != NULL) {
        log = fopen(log_file, "a");
        if (!log) {
            fprintf(stderr, "[ERROR] Failed to open log file: %s\n", log_file);
            return false;
        }
    }

    // Null pointer checks
    if (!expected || !actual) {
        if (debug) {
            fprintf(stderr, "[ERROR] Null pointer detected in comparison.\n");
        }
        if (log) {
            fprintf(log, "[ERROR] Null pointer detected in comparison.\n");
        }
        return false;
    }

    switch (type) {
        case TYPE_INT:
            if (debug) {
                fprintf(stderr, "Comparing integers: Expected = %d, Actual = %d\n",
                        *(int *)expected, *(int *)actual);
            }
            match = *(int *)expected == *(int *)actual;
            break;

        case TYPE_FLOAT:
            {
                const float epsilon = 1e-6; // Precision tolerance
                if (debug) {
                    fprintf(stderr, "Comparing floats: Expected = %.6f, Actual = %.6f\n",
                            *(float *)expected, *(float *)actual);
                }
                match = fabs(*(float *)expected - *(float *)actual) <= epsilon;
            }
            break;

        case TYPE_STRING:
            if (debug) {
                fprintf(stderr, "Comparing strings: Expected = \"%s\", Actual = \"%s\"\n",
                        (char *)expected, (char *)actual);
            }
            match = strcmp((char *)expected, (char *)actual) == 0;
            break;

        case TYPE_CHAR:
            if (debug) {
                fprintf(stderr, "Comparing chars: Expected = '%c', Actual = '%c'\n",
                        *(char *)expected, *(char *)actual);
            }
            match = *(char *)expected == *(char *)actual;
            break;

        default:
            if (debug) {
                fprintf(stderr, "[ERROR] Invalid type for comparison: %d\n", type);
            }
            if (log) {
                fprintf(log, "[ERROR] Invalid type for comparison: %d\n", type);
            }
            return false;
    }

    // Log the mismatch if there is a failure
    if (!match) {
        if (debug) {
            fprintf(stderr, "[ERROR] Values do not match.\n");
        }
        if (log) {
            fprintf(log, "[ERROR] Type: %d, Expected: ", type);
            switch (type) {
                case TYPE_INT:
                    fprintf(log, "%d, Actual: %d\n", *(int *)expected, *(int *)actual);
                    break;
                case TYPE_FLOAT:
                    fprintf(log, "%.6f, Actual: %.6f\n", *(float *)expected, *(float *)actual);
                    break;
                case TYPE_STRING:
                    fprintf(log, "\"%s\", Actual: \"%s\"\n", (char *)expected, (char *)actual);
                    break;
                case TYPE_CHAR:
                    fprintf(log, "'%c', Actual: '%c'\n", *(char *)expected, *(char *)actual);
                    break;
            }
        }
    }

    // Close the log file if it was opened
    if (log) {
        fclose(log);
    }

    return match;
}
// General test function
int test_function(const char *func_name, const char *mode, FuncWithVoidPtr func, void *test_input, void *expected_output, ResultType type) {
    // Allocate space for the actual result based on type
    void *actual_output;
    size_t size = 0;
    switch (type) {
        case TYPE_INT:
            size = sizeof(int);
            break;
        case TYPE_FLOAT:
            size = sizeof(float);
            break;
        case TYPE_STRING:
            size = strlen((char *)expected_output) + 1;
            break;
        case TYPE_CHAR:
            size = sizeof(char);
            break;
    }
    actual_output = malloc(size);
    if (!actual_output) {
        perror("Failed to allocate memory for actual_output");
        return 0;
    }

    // Call the function to test
    func(test_input, actual_output);

    // Display results
    bool detailed = strcmp(mode, "detailed") == 0;
    display_result(func_name, test_input, expected_output, actual_output, type, detailed);

    // Compare results
    bool match = compare_results(expected_output, actual_output, type, true, NULL);
    free(actual_output);

    if (!match) {
        TEST_FAIL(func_name);
        return 0;
    }

    TEST_PASS(func_name);
    return 1;
}