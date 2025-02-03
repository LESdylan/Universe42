#include <stdio.h>

void twoSum(int nums[], int size, int target, int result[]) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) { // Commence à i + 1 pour éviter d'utiliser le même élément deux fois
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return; // On retourne dès qu'on trouve une solution
            }
        }
    }
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int result[2] = {-1, -1};

    int size = sizeof(nums) / sizeof(nums[0]);
    twoSum(nums, size, target, result);

    if (result[0] != -1) {
        printf("Indices trouvés : [%d, %d]\n", result[0], result[1]);
    } else {
        printf("Aucune solution trouvée.\n");
    }

    return 0;
}
