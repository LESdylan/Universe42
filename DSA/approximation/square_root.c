#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction pour calculer x^n
float powers(float x, float n)
{
    if (n == 0)
        return 1.0;  // x^0 = 1
    else if (n > 0)
        return x * powers(x, n - 1);  // Exposant entier positif
    else
        return 1.0 / powers(x, -n);  // Exposant négatif
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    float x = atof(argv[1]);

    // Calcul de la puissance x^0.5 (racine carrée de x)
    printf("Result: %.6f\n", powers(x, 0.5));  // Calcul x^0.5 (racine carrée de x)
    
    return 0;
}
