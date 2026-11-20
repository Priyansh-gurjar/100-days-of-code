/* Q76: Check if a matrix is symmetric */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int symmetric = 1;

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
        }
    }

    for (int i = 0; i < n && symmetric; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i * n + j] != matrix[j * n + i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if (symmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    free(matrix);
    return 0;
}
