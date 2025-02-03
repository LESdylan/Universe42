#include <stdio.h>
#include <math.h>

// Fonction générique f(x)
double f(double x) {
    return pow(x, 3) + pow(x, 2) + x - 2; // Exemple : x^3 + x^2 + x - 2
}

void dichotomie() {
    double a = 0.0; // Initialisation de a
    double b = 2.0; // Initialisation de b
    const double epsilon = 1e-5; // Précision souhaitée

    while (fabs(b - a) > epsilon) {
        double m = (a + b) / 2.0; // Calcul du milieu

        if (f(m) * f(a) <= 0) {
            b = m; // Le zéro est dans [a, m]
        } else {
            a = m; // Le zéro est dans [m, b]
        }
    }

    // Affichage du résultat
    printf("La racine se trouve dans l'intervalle [%.5f, %.5f]\n", a, b);
}

int main() {
    dichotomie();
    return 0;
}