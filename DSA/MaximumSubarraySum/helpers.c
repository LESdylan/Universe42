#include "algorithms.h"
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 2001) - 1000; // Valeurs aléatoires entre -1000 et 1000
    }
}

int maxCrossingSum(int nums[], int left, int mid, int right) {
    int leftSum = -1000000000; // Valeur initiale très petite
    int rightSum = -1000000000;

    // Trouver la somme maximale à gauche de mid
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    // Trouver la somme maximale à droite de mid
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    // Retourner la somme maximale traversant le centre
    return leftSum + rightSum;
}
void* threadFunc(void *arg) {
    ThreadArgs *args = (ThreadArgs*)arg;

    // Start the thread computation
    clock_t start, end;
    start = clock();

    // Perform the computation based on the number of arguments
    if (args->isThreeArgs) {
        args->result = args->func3(args->arr, args->left, args->right);  // Function with 3 arguments
    } else {
        args->result = args->func2(args->arr, args->n);  // Function with 2 arguments
    }

    end = clock();
    args->timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Lock mutex before modifying the shared global counter
    pthread_mutex_lock(&mutex);
    threadsCompleted++;  // Increment the counter of completed threads
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void loadingEffect(int total) {
    // Dynamic update of progress bar
    printf("\rProgress: [");
    int progress = (int)((float)threadsCompleted / total * 100);  // Calculate percentage of progress
    int numHashes = progress / 2;  // Each hash represents 2% progress
    
    // Print the appropriate number of hashes
    for (int i = 0; i < numHashes; i++) {
        printf("#");
    }

    // Fill the remaining space with spaces
    for (int i = numHashes; i < 50; i++) {
        printf(" ");
    }

    // Print the percentage
    printf("] %d%%", progress);
    fflush(stdout);  // Ensure immediate output
}

void printHeader() {
    // Print the header for the result table
    printf("\n---------------------------------------------------------\n");
    printf("Algorithm                 | Time Taken (s) | Result\n");
    printf("---------------------------------------------------------\n");
}

void printFooter() {
    // Footer for the result table
    printf("---------------------------------------------------------\n");
}
