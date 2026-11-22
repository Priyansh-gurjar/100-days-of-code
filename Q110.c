#include <stdio.h>
#include <stdlib.h>

// Find the maximum element in each subarray (window) of size k using a monotonic deque - O(n)
void printSlidingWindowMax(const int arr[], int n, int k) {
    int *deque = (int *)malloc((size_t)n * sizeof(int));
    if (!deque) {
        return;
    }

    int front = 0, back = -1;
    int printed = 0;

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of the current window
        while (front <= back && deque[front] <= i - k) {
            front++;
        }

        // Remove indices whose corresponding values are <= arr[i]
        while (front <= back && arr[deque[back]] <= arr[i]) {
            back--;
        }

        deque[++back] = i;

        // Output the maximum once the first window of size k is formed
        if (i >= k - 1) {
            if (printed > 0) {
                printf(" ");
            }
            printf("%d", arr[deque[front]]);
            printed++;
        }
    }
    printf("\n");

    free(deque);
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

    printSlidingWindowMax(arr, n, k);

    free(arr);
    return 0;
}
