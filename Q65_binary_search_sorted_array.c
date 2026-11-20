/* Q65: Search in a sorted array using binary search */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, key;

    printf("Enter size of sorted array: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    int *a = (int *)malloc((size_t)(n ? n : 1) * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) { free(a); return 1; }

    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            found = mid;
            break;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d (position %d).\n", found, found + 1);

    free(a);
    return 0;
}
