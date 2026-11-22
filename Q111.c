#include <stdio.h>
#include <stdlib.h>

// Find the first negative integer in each subarray (window) of size k using a queue - O(n)
void printFirstNegativeInWindows(const int arr[], int n, int k) {
    int *queue = (int *)malloc((size_t)n * sizeof(int));
    if (!queue) {
        return;
    }

    int front = 0, back = -1;
    int printed = 0;

    for (int i = 0; i < n; i++) {
        // Store index if the current element is negative
        if (arr[i] < 0) {
            queue[++back] = i;
        }

        // Remove indices that are out of the current window
        while (front <= back && queue[front] <= i - k) {
            front++;
        }

        // Output the first negative integer once the first window of size k is formed
        if (i >= k - 1) {
            if (printed > 0) {
                printf(" ");
            }
            if (front <= back) {
                printf("%d", arr[queue[front]]);
            } else {
                printf("0");
            }
            printed++;
        }
    }
    printf("\n");

    free(queue);
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

    printFirstNegativeInWindows(arr, n, k);

    free(arr);
    return 0;
}
