#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to evaluate the expression (x^2 - 2)
double expression(double x) {
    return pow(x, 2) - 2.0;
}

/**
 * Iterative Dichotomy (Bisection) Method
 * @param init_a: Initial lower bound of the interval
 * @param init_b: Initial upper bound of the interval
 * @param iterations: Number of iterations to perform
 * @param F1: Function pointer to evaluate the function
 */
void dichotomie(double init_a, double init_b, int iterations, double (*F1)(double)) {
    double median;

    for (int k = 0; k < iterations; k++) {
        median = (init_a + init_b) / 2.0;

        printf("Iteration %d: a = %f, b = %f\n", k + 1, init_a, init_b);

        if (F1(init_a) * F1(median) < 0) {
            init_b = median; // Root is in the lower half
        } else {
            init_a = median; // Root is in the upper half
        }
    }

    median = (init_a + init_b) / 2.0;
    printf("Approximated root (Iterative): %.6f\n", median);
}

/**
 * Recursive Dichotomy (Bisection) Method with fixed iterations
 * @param init_a: Initial lower bound of the interval
 * @param init_b: Initial upper bound of the interval
 * @param iterations: Remaining number of iterations
 * @param F1: Function pointer to evaluate the function
 * @return: Approximated root
 */
double dichotomie_recursive_with_iterations(double init_a, double init_b, int iterations, double (*F1)(double)) {
    if (iterations == 0) {
        double median = (init_a + init_b) / 2.0;
        printf("Final approximated root (Recursive, fixed iterations): %.6f\n", median);
        return median;
    }

    double median = (init_a + init_b) / 2.0;
    printf("Iteration %d: a = %f, b = %f\n", iterations, init_a, init_b);

    if (F1(init_a) * F1(median) < 0) {
        return dichotomie_recursive_with_iterations(init_a, median, iterations - 1, F1);
    } else {
        return dichotomie_recursive_with_iterations(median, init_b, iterations - 1, F1);
    }
}

/**
 * Recursive Dichotomy (Bisection) Method with convergence tolerance
 * @param init_a: Initial lower bound of the interval
 * @param init_b: Initial upper bound of the interval
 * @param F1: Function pointer to evaluate the function
 * @param tolerance: Convergence tolerance
 * @return: Approximated root
 */
double dichotomie_recursive(double init_a, double init_b, double (*F1)(double), double tolerance) {
    double median = (init_a + init_b) / 2.0;

    if (fabs(F1(median)) < tolerance) { // Stop if function value is close to 0
        printf("Converged to %.6f\n", median);
        return median;
    }

    printf("a = %f, b = %f, median = %f\n", init_a, init_b, median);

    if (F1(init_a) * F1(median) < 0) {
        return dichotomie_recursive(init_a, median, F1, tolerance);
    } else {
        return dichotomie_recursive(median, init_b, F1, tolerance);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <a> <b> <iterations>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    int iterations = atoi(argv[3]);
    double tolerance = 1e-6;

    printf("\nIterative Dichotomy Method:\n");
    dichotomie(a, b, iterations, expression);

    printf("\nRecursive Dichotomy Method (fixed iterations):\n");
    dichotomie_recursive_with_iterations(a, b, iterations, expression);

    printf("\nRecursive Dichotomy Method (convergence tolerance):\n");
    double root = dichotomie_recursive(a, b, expression, tolerance);
    printf("Final approximated root (Recursive, with tolerance): %.6f\n", root);

    return 0;
}