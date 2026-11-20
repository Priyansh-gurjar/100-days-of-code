/* Q77: Check if the elements on the main diagonal are distinct */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, distinct = 1;

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

    for (int i = 0; i < n && distinct; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i * n + i] == matrix[j * n + j]) {
                distinct = 0;
                break;
            }
        }
    }

    if (distinct)
        printf("All main diagonal elements are distinct.\n");
    else
        printf("Main diagonal elements are not distinct.\n");

    free(matrix);
    return 0;
}
