#include <stdio.h>
#include "myfile.h" 	// Inclusion de l'en-tête externe pour la variable z

int x = 20;	// Variable globale

// Fonction qui utilise une variable locale
void use_local(void)
{
    int x = 10;	// Variable locale
    // La variable locale masque la variable globale avec le même nom
    printf("Local x = %d\n", x);  // Affiche la variable locale
}

// Fonction qui utilise la variable globale
void use_global(void)
{
    // Affiche la valeur de la variable globale
    printf("Global x = %d\n", x);
}

// Fonction qui utilise une variable statique
void use_static(void)
{
    static int x = 15; // Variable statique, sa valeur persiste entre les appels
    x++; // Incrémentation de la variable statique
    printf("Static x = %d\n", x);
}

// Fonction qui utilise des variables automatiques
void use_auto(void)
{
    int x = 10;   // Variable automatique (par défaut en C)
    auto int y = 20;  // Le mot-clé 'auto' est optionnel, donc c'est équivalent à 'int y = 20'
    // Ces variables ne persistent pas après la fin de la fonction
    printf("Auto x = %d, y = %d\n", x, y);
}

// Fonction pour afficher la variable externe
void print_external()
{
    // Affiche la variable externe déclarée dans myfile.h
    printf("External variable z = %d\n", z);
}

int main(void)
{
    int b = 17, c = 18; // Variables locales à main()
    char a1 = 'J';  // Variable locale de type char
    
    // Affichage d'une valeur de caractère
    printf("Character value : %c\n", a1);
    
    // Affichage de deux valeurs entières
    printf("Integer values: b = %d, c = %d\n", b, c);
    
    // Appel des différentes fonctions
    use_local();     // Utilisation de la variable locale
    use_global();    // Utilisation de la variable globale
    use_static();    // Utilisation de la variable statique
    use_static();    // La variable statique conserve sa valeur
    use_static();    // Encore un appel pour voir l'effet
    use_auto();      // Utilisation des variables automatiques
    print_external(); // Affichage de la variable externe
    
    return 0;
}
