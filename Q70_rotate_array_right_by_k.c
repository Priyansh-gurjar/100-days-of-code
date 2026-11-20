/* Q70: Rotate an array to the right by k positions */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long k;

    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    int *a = (int *)malloc((size_t)(n ? n : 1) * sizeof(int));
    if (a == NULL) return 1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    printf("Enter number of right rotations (k): ");
    if (scanf("%lld", &k) != 1) { free(a); return 1; }

    if (n > 0) {
        int shift = (int)(k % n);
        if (shift < 0) shift += n;

        /* Reverse the whole array, then the first shift and remaining parts. */
        for (int left = 0, right = n - 1; left < right; left++, right--) {
            int temp = a[left]; a[left] = a[right]; a[right] = temp;
        }
        for (int left = 0, right = shift - 1; left < right; left++, right--) {
            int temp = a[left]; a[left] = a[right]; a[right] = temp;
        }
        for (int left = shift, right = n - 1; left < right; left++, right--) {
            int temp = a[left]; a[left] = a[right]; a[right] = temp;
        }
    }

    printf("Array after right rotation: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}
