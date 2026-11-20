/* Q80: Multiply two matrices */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0)
        return 1;

    printf("Enter rows and columns of second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0)
        return 1;

    if (c1 != r2) {
        printf("Matrix multiplication is not possible: columns of first "
               "matrix must equal rows of second matrix.\n");
        return 1;
    }

    size_t n1 = (size_t)r1 * c1;
    size_t n2 = (size_t)r2 * c2;
    size_t n3 = (size_t)r1 * c2;

    int *a = (int *)malloc(n1 * sizeof(int));
    int *b = (int *)malloc(n2 * sizeof(int));
    long long *product = (long long *)calloc(n3, sizeof(long long));

    if (a == NULL || b == NULL || product == NULL) {
        free(a); free(b); free(product);
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (size_t i = 0; i < n1; i++) {
        if (scanf("%d", &a[i]) != 1) {
            free(a); free(b); free(product);
            return 1;
        }
    }

    printf("Enter elements of second matrix:\n");
    for (size_t i = 0; i < n2; i++) {
        if (scanf("%d", &b[i]) != 1) {
            free(a); free(b); free(product);
            return 1;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                product[i * c2 + j] +=
                    (long long)a[i * c1 + k] * b[k * c2 + j];
            }
        }
    }

    printf("Product of the matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%lld\\t", product[i * c2 + j]);
        printf("\n");
    }

    free(a);
    free(b);
    free(product);
    return 0;
}
