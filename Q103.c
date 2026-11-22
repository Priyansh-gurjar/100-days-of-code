#include <stdio.h>
#include <stdlib.h>

// Find the leftmost pivot index where left sum == right sum - O(n)
int findPivotIndex(const int arr[], int n) {
    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    long long leftSum = 0;
    for (int i = 0; i < n; i++) {
        long long rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum) {
            return i;
        }
        leftSum += arr[i];
    }

    return -1;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int *arr = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    if (!arr) {
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pivot = findPivotIndex(arr, n);
    printf("%d\n", pivot);

    free(arr);
    return 0;
}
