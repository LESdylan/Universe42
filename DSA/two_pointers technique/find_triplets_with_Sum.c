int findTriplets(int arr[], int n, int k) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int l = j + 1; l < n; l++) {
                if (arr[i] + arr[j] + arr[l] == k) return 1;
            }
        }
    }
    return 0;
}
// O(n^3)
int findTriplets(int arr[], int n, int k) {
    for (int i = 0; i < n - 2; i++) {
        int target = k - arr[i];
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) return 1;
            if (sum < target) left++;
            else right--;
        }
    }
    return 0;
}
// O(n^2) optimized with two while but also two pointers techniques