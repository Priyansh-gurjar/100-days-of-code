/* Q78: Find the sum of main diagonal elements for a square matrix */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long sum = 0;

    printf("Enter order of square matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *matrix = (int *)malloc((size_t)n * n * sizeof(int));
    if (matrix == NULL) return 1;

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i * n + j]) != 1) {
                free(matrix);
                return 1;
            }
            if (i == j) sum += matrix[i * n + j];
        }
    }

    printf("Sum of main diagonal elements = %lld\n", sum);
    free(matrix);
    return 0;
}
