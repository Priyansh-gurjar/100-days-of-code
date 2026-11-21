// Q95: Check if one string is a rotation of another.
#include <stdio.h>

int main(void) {
    char first[500], second[500], doubled[1000];
    int len1 = 0, len2 = 0, i, j, found = 0;

    printf("Enter the first string: ");
    if (fgets(first, sizeof(first), stdin) == NULL) return 1;

    printf("Enter the second string: ");
    if (fgets(second, sizeof(second), stdin) == NULL) return 1;

    while (first[len1] != '\0' && first[len1] != '\n') len1++;
    while (second[len2] != '\0' && second[len2] != '\n') len2++;
    first[len1] = '\0';
    second[len2] = '\0';

    if (len1 == len2) {
        for (i = 0; i < len1; i++) doubled[i] = first[i];
        for (i = 0; i < len1; i++) doubled[len1 + i] = first[i];
        doubled[2 * len1] = '\0';

        if (len1 == 0) {
            found = 1;
        } else {
            for (i = 0; i <= len1 && !found; i++) {
                for (j = 0; j < len2; j++) {
                    if (doubled[i + j] != second[j]) break;
                }
                if (j == len2) found = 1;
            }
        }
    }

    if (found) {
        printf("The second string is a rotation of the first string.\\n");
    } else {
        printf("The second string is not a rotation of the first string.\\n");
    }

    return 0;
}
