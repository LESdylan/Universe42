#include <stdio.h>
#include <stdlib.h>

// Structure pour conserver la valeur originale et son index
typedef struct {
    int value;
    int index;
} IndexedValue;

// Fonction de comparaison pour qsort
int compare(const void *a, const void *b) {
    return ((IndexedValue *)a)->value - ((IndexedValue *)b)->value;
}

// Two Sum avec tri et deux pointeurs
void twoSum(int nums[], int size, int target, int result[]) {
    IndexedValue *indexedNums = malloc(size * sizeof(IndexedValue));

    // Associer chaque valeur à son index
    for (int i = 0; i < size; i++) {
        indexedNums[i].value = nums[i];
        indexedNums[i].index = i;
    }

    // Trier par valeur
    qsort(indexedNums, size, sizeof(IndexedValue), compare);

    // Deux pointeurs
    int left = 0, right = size - 1;
    while (left < right) {
        int sum = indexedNums[left].value + indexedNums[right].value;
        if (sum == target) {
            // Trouvé : on renvoie les indices originaux
            result[0] = indexedNums[left].index;
            result[1] = indexedNums[right].index;
            free(indexedNums);
            return;
        } else if (sum < target) {
            left++;  // Augmenter la somme
        } else {
            right--; // Réduire la somme
        }
    }

    // Pas trouvé (ce cas ne devrait pas arriver selon l'énoncé)
    result[0] = -1;
    result[1] = -1;
    free(indexedNums);
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int result[2];

    int size = sizeof(nums) / sizeof(nums[0]);
    twoSum(nums, size, target, result);

    if (result[0] != -1) {
        printf("Indices trouvés : [%d, %d]\n", result[0], result[1]);
    } else {
        printf("Aucune solution trouvée.\n");
    }

    return 0;
}
