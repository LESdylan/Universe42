#include <stdio.h>

int main() {
    // Déclaration des variables
    int entier;
    float flottant;
    char caractere;
    char chaine[100]; // tableau pour stocker une chaîne

    // Utilisation de printf pour afficher des messages et des variables
    printf("Exemple d'utilisation de printf et scanf en C\n");

    // Affichage d'un entier, d'un flottant, d'un caractère et d'une chaîne
    printf("Affichage d'un entier : %d\n", 10);
    printf("Affichage d'un flottant : %.2f\n", 3.14);
    printf("Affichage d'un caractère : %c\n", 'A');
    printf("Affichage d'une chaîne : %s\n", "Bonjour tout le monde");

    // Demander à l'utilisateur de saisir un entier
    printf("\nEntrez un entier : ");
    scanf("%d", &entier); // Lecture d'un entier
    printf("Vous avez entré l'entier : %d\n", entier);

    // Demander à l'utilisateur de saisir un flottant
    printf("\nEntrez un nombre flottant : ");
    scanf("%f", &flottant); // Lecture d'un flottant
    printf("Vous avez entré le nombre flottant : %.2f\n", flottant);

    // Demander à l'utilisateur de saisir un caractère
    printf("\nEntrez un caractère : ");
    scanf(" %c", &caractere); // Le " " avant %c permet de gérer les retours à la ligne
    printf("Vous avez entré le caractère : %c\n", caractere);

    // Demander à l'utilisateur de saisir une chaîne de caractères
    printf("\nEntrez une chaîne de caractères : ");
    scanf("%s", chaine); // Lecture d'une chaîne (sans espaces)
    printf("Vous avez entré la chaîne : %s\n", chaine);

    // Lecture d'une chaîne avec espaces (utilisation de fgets)
    char chaineAvecEspaces[100];
    printf("\nEntrez une chaîne avec des espaces : ");
    fgets(chaineAvecEspaces, sizeof(chaineAvecEspaces), stdin); // Lecture avec espaces
    printf("Vous avez entré la chaîne avec espaces : %s\n", chaineAvecEspaces);

    // Affichage avec formatage avancé
    printf("\nAffichage avancé avec formatage :\n");
    printf("Entier aligné à gauche sur 10 caractères : %-10d\n", 123);
    printf("Flottant arrondi à 2 décimales : %.2f\n", 123.456);
    printf("Caractère en majuscule : %c\n", 'a');
    printf("Chaîne en majuscule : %.5s\n", "HelloWorld");

    // Affichage de valeurs sur plusieurs lignes
    printf("\nAffichage sur plusieurs lignes avec différentes options :\n");
    printf("Entier : %d\nFlottant : %.2f\nCaractère : %c\nChaîne : %s\n", entier, flottant, caractere, chaine);

    return 0;
}
