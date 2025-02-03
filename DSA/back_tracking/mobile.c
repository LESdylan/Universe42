#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapping des chiffres vers les lettres correspondantes
char *mapping[] = {
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// Fonction de backtracking
void backtrack(char **result, int *count, char *digits, char *current, int index) {
    if (digits[index] == '\0') { // Si on atteint la fin de la chaîne de chiffres
        result[*count] = strdup(current); // Ajouter la combinaison actuelle au résultat
        (*count)++;
        return;
    }

    int digit = digits[index] - '2'; // Obtenir l'indice dans le tableau `mapping`
    char *letters = mapping[digit];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i]; // Choisir une lettre
        backtrack(result, count, digits, current, index + 1); // Passer à la lettre suivante
    }
}

// Fonction principale pour générer les combinaisons
char **letterCombinations(char *digits, int *returnSize) {
    if (!digits || digits[0] == '\0') { // Si l'entrée est vide
        *returnSize = 0;
        return NULL;
    }

    int max_combinations = 256; // Estimation de la taille maximale
    char **result = malloc(max_combinations * sizeof(char *));
    if (!result) {
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }

    char current[5] = {0}; // Stock temporaire pour une combinaison (longueur max = 4)
    *returnSize = 0;

    // Appel de la fonction de backtracking
    backtrack(result, returnSize, digits, current, 0);

    return result; // Retourner les combinaisons générées
}

// Fonction pour libérer la mémoire
void freeResult(char **result, int size) {
    for (int i = 0; i < size; i++) {
        free(result[i]); // Libérer chaque chaîne
    }
    free(result); // Libérer le tableau principal
}

// Exemple d'utilisation
int main() {
    char digits[] = "23"; // Exemple d'entrée
    int returnSize = 0;

    // Appeler la fonction pour obtenir les combinaisons
    char **result = letterCombinations(digits, &returnSize);

    // Afficher les résultats
    printf("Number of combinations: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // Libérer la mémoire
    freeResult(result, returnSize);

    return 0;
}
