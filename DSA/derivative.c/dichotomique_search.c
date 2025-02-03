#include <stdio.h>

// Fonction pour la recherche dichotomique
int recherche_dichotomique(int tableau[], int taille, int cible) {
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2; // Éviter le dépassement d'entiers

        // Vérifier si l'élément du milieu est la cible
        if (tableau[milieu] == cible) {
            return milieu; // Retourne l'indice de l'élément trouvé
        }

        // Si la cible est plus grande, ignorer la moitié gauche
        if (tableau[milieu] < cible) {
            debut = milieu + 1;
        } else { // Sinon, ignorer la moitié droite
            fin = milieu - 1;
        }
    }

    return -1; // Retourne -1 si l'élément n'est pas trouvé
}

int main() {
    // Exemple de tableau trié
    int tableau[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int cible;

    printf("Entrez l'élément à rechercher : ");
    scanf("%d", &cible);

    int resultat = recherche_dichotomique(tableau, taille, cible);

    if (resultat != -1) {
        printf("L'élément %d se trouve à l'indice %d.\n", cible, resultat);
    } else {
        printf("L'élément %d n'est pas présent dans le tableau.\n", cible);
    }

    return 0;
}