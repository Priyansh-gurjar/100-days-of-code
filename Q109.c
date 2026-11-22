#include <stdio.h>
#include <stdlib.h>

// Find the maximum sum of all subarrays of size k using Sliding Window - O(n)
long long maxSubarraySumK(const int arr[], int n, int k) {
    long long windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    long long maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return maxSum;
}

int main(void) {
    int n, k;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) {
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid k\n");
        free(arr);
        return 1;
    }

    long long result = maxSubarraySumK(arr, n, k);
    printf("%lld\n", result);

    free(arr);
    return 0;
}
