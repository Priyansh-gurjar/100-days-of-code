// Q92: Find the first repeating lowercase alphabet in a string.
// "First" means the first character encountered while scanning left to right
// whose lowercase letter has already appeared earlier.
#include <stdio.h>

int main(void) {
    char str[1000];
    int seen[26] = {0};
    int i = 0, found = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int index = str[i] - 'a';

            if (seen[index]) {
                printf("First repeating lowercase alphabet = %c\n", str[i]);
                found = 1;
                break;
            }
            seen[index] = 1;
        }
        i++;
    }

    if (!found) {
        printf("No repeating lowercase alphabet found.\n");
    }

    return 0;
}
