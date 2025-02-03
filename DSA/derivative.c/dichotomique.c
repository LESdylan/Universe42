#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to evaluate a polynomial expression for a given x
float evaluate_polynomial(const char *expression, float x) {
    char command[512];
    char buffer[256];
    snprintf(command, sizeof(command), "echo \"%s\" | sed 's/x/%f/g' | bc -l", expression, x);

    FILE *fp = popen(command, "r");
    if (!fp) {
        fprintf(stderr, "Failed to evaluate expression.\n");
        exit(1);
    }

    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        fprintf(stderr, "Error reading output from bc.\n");
        exit(1);
    }
    pclose(fp);

    return strtof(buffer, NULL);
}

int find_valid_interval(const char *expression, float *a, float *b, float step, float max_range) {
    float start = *a;
    float end = *b;

    while (fabs(end - start) <= max_range) {
        float current = start;
        while (current < end) {
            float f1 = evaluate_polynomial(expression, current);
            float f2 = evaluate_polynomial(expression, current + step);

            if (f1 * f2 < 0) {
                *a = current;
                *b = current + step;
                return 1;
            }
            current += step;
        }

        // Expand the search range
        start -= step;
        end += step;
    }
    return 0;
}

float dichotomique(const char *expression, float a, float b, float precision) {
    float mid;

    while ((b - a) > precision) {
        mid = (a + b) / 2.0;
        float f_mid = evaluate_polynomial(expression, mid);

        if (fabs(f_mid) < precision) {
            return mid;
        }

        if (evaluate_polynomial(expression, a) * f_mid < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
    return (a + b) / 2.0;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <polynomial> <a> <b> <precision>\n", argv[0]);
        return 1;
    }

    const char *expression = argv[1];
    float a = strtof(argv[2], NULL);
    float b = strtof(argv[3], NULL);
    float precision = strtof(argv[4], NULL);
    float step = 0.1;       // Step size for searching intervals
    float max_range = 10.0; // Maximum range for interval expansion

    // Find a valid interval if necessary
    if (evaluate_polynomial(expression, a) * evaluate_polynomial(expression, b) > 0) {
        printf("Searching for a valid interval where f(a) and f(b) have opposite signs...\n");
        if (!find_valid_interval(expression, &a, &b, step, max_range)) {
            fprintf(stderr, "No valid interval found after expanding the search range to %.1f.\n", max_range);
            return 1;
        }
        printf("Valid interval found: [%f, %f]\n", a, b);
    }

    float result = dichotomique(expression, a, b, precision);
    printf("Approximate root: %.10f\n", result);

    return 0;
}
