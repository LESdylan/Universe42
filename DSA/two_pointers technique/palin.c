#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Pour les constantes true/false (facultatif)

int main(void) {
    char *str = "oohoo"; // Chaîne à vérifier
    char *left, *right; // Pointeurs pour le début et la fin de la chaîne
    int len = strlen(str);

    // Initialisation des pointeurs
    left = str;         // Pointeur au début de la chaîne
    right = str + len - 1; // Pointeur à la fin de la chaîne

    // Boucle pour comparer les caractères
    while (left < right) {
        if (*left != *right) { // Comparaison des caractères pointés
            printf("La chaîne n'est PAS un palindrome.\n");
            return 0; // Sortie : pas un palindrome
        }
        left++;  // Avance le pointeur gauche
        right--; // Recule le pointeur droit
    }

    printf("La chaîne EST un palindrome.\n");
    return 0; // Sortie : succès
}
