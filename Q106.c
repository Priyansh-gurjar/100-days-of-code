#include <stdio.h>
#include <stdlib.h>

// Find the next greater element for each element using brute force (nested loop) - O(n^2)
void printNextGreaterElements(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int nextGreater = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nextGreater = arr[j];
                break;
            }
        }
        if (i > 0) {
            printf(", ");
        }
        printf("%d", nextGreater);
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

    printNextGreaterElements(arr, n);

    free(arr);
    return 0;
}
