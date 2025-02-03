#include <stdio.h>
#include <stdlib.h>

// Fonction pour extraire une sous-chaîne donnée les indices de début et fin
char *substring(char *str, int start, int end) {
    int len = end - start + 1;
    char *sub = (char *)malloc((len + 1) * sizeof(char)); // Allocation mémoire
    char *ptr = sub;

    for (char *s = str + start; s <= str + end; s++) {
        *ptr++ = *s; // Copie les caractères dans la sous-chaîne
    }
    *ptr = '\0'; // Terminaison de la chaîne
    return sub;
}
void extract_substrings(char *str) {
    char *start = NULL, *end = NULL;

    while (*str != '\0') {
        if (*str == '[') {
            start = str + 1; // Début après '['
        } else if (*str == ']' && start != NULL) {
            end = str; // Fin à ']'

            // Calculer la longueur de la sous-chaîne
            int len = end - start;
            char *sub = (char *)malloc((len + 1) * sizeof(char));
            strncpy(sub, start, len);
            sub[len] = '\0'; // Terminaison de la chaîne

            printf("Sous-chaîne : %s\n", sub);
            free(sub);

            start = NULL; // Réinitialiser pour trouver la prochaine sous-chaîne
        }
        str++; // Avancer au prochain caractère
    }
}

char *extract_letters(char *str) {
    char *start = NULL, *end = NULL;

    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (isalpha(*ptr)) {
            if (start == NULL) start = ptr; // Début de la sous-chaîne
            end = ptr;                     // Mise à jour de la fin
        } else if (start != NULL) {
            break; // Fin de la sous-chaîne trouvée
        }
    }

    if (start == NULL) return NULL; // Pas de lettres trouvées

    // Calculer la longueur et allouer de la mémoire
    int len = end - start + 1;
    char *sub = (char *)malloc((len + 1) * sizeof(char));
    char *ptr = sub;

    while (start <= end) {
        *ptr++ = *start++;
    }
    *ptr = '\0'; // Terminaison de la chaîne
    return sub;
}

int main() {
    char *str = "Hello, World!";
    int start = 7, end = 11; // Indices pour "World"
    char *result = substring(str, start, end);
    printf("Sous-chaîne: %s\n", result);

    free(result); // Libérer la mémoire

        char *str = "123!Hello, 456!";
    char *result = extract_letters(str);

    if (result) {
        printf("Sous-chaîne extraite: %s\n", result);
        free(result); // Libérer la mémoire
    } else {
        printf("Aucune sous-chaîne trouvée.\n");
    }
    char *str = "Voici [une] chaîne avec [plusieurs] sous-chaînes.";
    extract_substrings(str);

    return 0;
}
