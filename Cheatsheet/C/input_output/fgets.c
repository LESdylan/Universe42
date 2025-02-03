#include <stdio.h>

int main() {
    // Déclaration des variables
    int entier;
    float flottant;
    char caractere;
    char chaine[100]; // Tableau pour stocker une chaîne
    char chaineAvecEspaces[200]; // Pour la chaîne avec espaces

    // Demander à l'utilisateur de saisir un entier
    printf("Entrez un entier : ");
    scanf("%d", &entier); // Lecture d'un entier
    printf("Vous avez entré l'entier : %d\n", entier);

    // Vider le tampon d'entrée après un `scanf`
    while(getchar() != '\n'); // Consomme le caractère de nouvelle ligne

    // Demander à l'utilisateur de saisir un flottant
    printf("\nEntrez un nombre flottant : ");
    scanf("%f", &flottant); // Lecture d'un flottant
    printf("Vous avez entré le nombre flottant : %.2f\n", flottant);

    // Vider à nouveau le tampon d'entrée
    while(getchar() != '\n');

    // Demander à l'utilisateur de saisir un caractère
    printf("\nEntrez un caractère : ");
    scanf("%c", &caractere); // Lecture d'un caractère
    printf("Vous avez entré le caractère : %c\n", caractere);

    // Vider le tampon d'entrée après le `scanf` pour éviter les problèmes
    while(getchar() != '\n');

    // Demander à l'utilisateur de saisir une chaîne sans espaces (utilise scanf)
    printf("\nEntrez une chaîne sans espaces : ");
    scanf("%s", chaine); // Lecture d'une chaîne (sans espaces)
    printf("Vous avez entré la chaîne : %s\n", chaine);

    // Vider le tampon d'entrée après un `scanf`
    while(getchar() != '\n');

    // Demander à l'utilisateur de saisir une chaîne avec espaces (utilise fgets)
    printf("\nEntrez une chaîne avec espaces : ");
    fgets(chaineAvecEspaces, sizeof(chaineAvecEspaces), stdin); // Lecture avec espaces
    printf("Vous avez entré la chaîne avec espaces : %s\n", chaineAvecEspaces);

    // Demander à l'utilisateur de saisir une autre chaîne avec fgets, mais cette fois avec contrôle de taille
    char chaineAvecLimite[50];
    printf("\nEntrez une autre chaîne avec un nombre limité de caractères (max 50) : ");
    fgets(chaineAvecLimite, sizeof(chaineAvecLimite), stdin); // Lecture avec une taille limite
    printf("Vous avez entré la chaîne limitée : %s\n", chaineAvecLimite);

    return 0;
}
