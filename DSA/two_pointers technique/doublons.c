int removeDuplicates(int arr[], int n) {
    int i = 0; // Pointeur pour la position finale
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) { // Trouve un élément unique
            i++;
            arr[i] = arr[j]; // Mise à jour du tableau
        }
    }
    return i + 1; // Nouvelle taille du tableau
}