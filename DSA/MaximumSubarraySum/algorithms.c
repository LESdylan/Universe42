
#include "algorithms.h"

// Define the global variables here (do NOT define them in the header file)
int threadsCompleted = 0;  // Initialize the global counter
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // Initialize the mutex

int maxSubArrayCumulatedSum(int nums[], int n) {
    int prefixSum[n + 1];
    prefixSum[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int currentSum = prefixSum[j] - prefixSum[i];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

int maxSubArrayBruteForce(int nums[], int n) {
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}



int maxSubArrayDivideConquer(int nums[], int left, int right) {
    if (left == right) {
        return nums[left]; // Base case: un seul élément
    }

    int mid = (left + right) / 2;

    // Appels récursifs pour les sous-tableaux gauche et droit
    int leftMax = maxSubArrayDivideConquer(nums, left, mid);
    int rightMax = maxSubArrayDivideConquer(nums, mid + 1, right);

    // Calcul de la somme maximale traversant le centre
    int crossMax = maxCrossingSum(nums, left, mid, right);

    // Retourner le maximum parmi les trois options
    return (leftMax > rightMax ? (leftMax > crossMax ? leftMax : crossMax) : (rightMax > crossMax ? rightMax : crossMax));
}

int maxSubArrayKadane(int nums[], int n) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) {
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : currentSum + nums[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}
