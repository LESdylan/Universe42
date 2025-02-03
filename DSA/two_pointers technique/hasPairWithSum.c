int hasPairWithSum(int arr[], int n, int k) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) return 1; // Pair trouvé
        if (sum < k) left++;
        else right--;
    }
    return 0; // Pas de pair trouvé
}
