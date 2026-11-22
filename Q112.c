#include <stdio.h>
#include <stdlib.h>

// Find the maximum sum of any contiguous subarray using Kadane's algorithm - O(n)
// Handles all-negative arrays by returning the largest (least negative) element
long long kadaneMaxSubarraySum(const int arr[], int n) {
    long long currentSum = arr[0];
    long long maxSum = arr[0];

    for (int i = 1; i < n; i++) {
        if (currentSum + arr[i] > arr[i]) {
            currentSum += arr[i];
        } else {
            currentSum = arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main(void) {
    int n;
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

    long long maxSum = kadaneMaxSubarraySum(arr, n);
    printf("%lld\n", maxSum);

    free(arr);
    return 0;
}
