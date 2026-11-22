#include <stdio.h>
#include <stdlib.h>

// Find the index of the smallest element >= x (ceil of x) - O(log n)
int findCeilIndex(const int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;      // Potential ceil found; look left for first occurrence
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(void) {
    int n, x;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int *arr = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    if (!arr) {
        return 1;
    }

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter x: ");
    scanf("%d", &x);

    int ceilIndex = findCeilIndex(arr, n, x);
    printf("%d\n", ceilIndex);

    free(arr);
    return 0;
}
