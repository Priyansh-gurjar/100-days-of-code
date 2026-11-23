#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;

    if (scanf("%d", &m) != 1 || m < 0) {
        return 1;
    }
    int *arr1 = (int *)malloc((size_t)(m > 0 ? m : 1) * sizeof(int));
    if (arr1 == NULL) {
        return 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    if (scanf("%d", &n) != 1 || n < 0) {
        free(arr1);
        return 1;
    }
    int *arr2 = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    if (arr2 == NULL) {
        free(arr1);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    int total = m + n;
    int *merged = (int *)malloc((size_t)(total > 0 ? total : 1) * sizeof(int));
    if (merged == NULL) {
        free(arr1);
        free(arr2);
        return 1;
    }

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < m) {
        merged[k++] = arr1[i++];
    }
    while (j < n) {
        merged[k++] = arr2[j++];
    }

    for (int idx = 0; idx < total; idx++) {
        if (idx > 0) {
            printf(" ");
        }
        printf("%d", merged[idx]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(merged);
    return 0;
}
