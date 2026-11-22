#include <stdio.h>
#include <stdlib.h>

// Find the previous greater element for each element using brute force (nested loop) - O(n^2)
void printPreviousGreaterElements(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int prevGreater = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                prevGreater = arr[j];
                break;
            }
        }
        if (i > 0) {
            printf(", ");
        }
        printf("%d", prevGreater);
    }
    printf("\n");
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

    printPreviousGreaterElements(arr, n);

    free(arr);
    return 0;
}
