#include <stdio.h>
#include <math.h>
double F1(double x) {
    // Remplacez cette fonction par la fonction appropriée
    return (*pow(x,3)+pow(x,2)-2*x+(3.0/5.0)) ; // Exemple : f(x) = x^2 - 2
}

int main() {
    int n, k;
    double a = -2.0, b = -1.0;
    char message[100];

    printf("Entrez le nombre d'itérations: ");
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        double mid = (a + b) / 2;
        if (F1(a) * F1(mid) < 0) {
            b = mid;
        } else {
            a = mid;
        }
        sprintf(message, "itérations %d: %f AND %f\n", k, a, b);
        printf("%s", message);
    }

    return 0;
}