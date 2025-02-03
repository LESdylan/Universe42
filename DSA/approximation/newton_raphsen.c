#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Iterative Newton-Raphson method
 * @param alpha: The value to find the square root of
 * @param x: Initial guess
 * @param i: Number of iterations
 * @return: Approximated root after i iterations
 */
double newton(double alpha, double x, int i) {
    double result = x;

    for (int k = 0; k < i; k++) {
        result = 0.5 * (result + (alpha / result));
        printf("Iteration %d: %f\n", k + 1, result);
    }

    return result;
}

/**
 * Recursive Newton-Raphson method with fixed iterations
 * @param alpha: The value to find the square root of
 * @param x: Initial guess
 * @param i: Remaining number of iterations
 * @return: Approximated root
 */
double newton_recursive(double alpha, double x, int i) {
    if (i == 0) {
        return x; // Base case: return the current approximation
    }

    double next_x = 0.5 * (x + (alpha / x));
    printf("Iteration %d: %f\n", i, next_x);

    return newton_recursive(alpha, next_x, i - 1);
}

/**
 * Recursive Newton-Raphson method with a convergence condition
 * @param alpha: The value to find the square root of
 * @param x: Initial guess
 * @param tolerance: Convergence tolerance
 * @return: Approximated root
 */
double newton_recursive_approximation(double alpha, double x, double tolerance) {
    double next_x = 0.5 * (x + (alpha / x));

    // Check for convergence (stop if the change is below the tolerance)
    if (fabs(next_x - x) < tolerance) {
        printf("Converged to %.6f\n", next_x);
        return next_x;
    }

    // Print current approximation
    printf("x = %.6f, next_x = %.6f\n", x, next_x);

    // Recursive call with the updated approximation
    return newton_recursive_approximation(alpha, next_x, tolerance);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <alpha> <initial_guess> <iterations>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    double alpha = atof(argv[1]);
    double x = atof(argv[2]);
    int i = atoi(argv[3]);
    double tolerance = 1e-3;

    printf("\nIterative Newton-Raphson method:\n");
    double iterative_result = newton(alpha, x, i);
    printf("Final result (Iterative): %.6f\n\n", iterative_result);

    printf("Recursive Newton-Raphson method (fixed iterations):\n");
    double recursive_result = newton_recursive(alpha, x, i);
    printf("Final result (Recursive, fixed iterations): %.6f\n\n", recursive_result);

    printf("Recursive Newton-Raphson method (convergence tolerance):\n");
    double recursive_approx_result = newton_recursive_approximation(alpha, x, tolerance);
    printf("Final result (Recursive, with tolerance): %.6f\n", recursive_approx_result);

    return 0;
}
