// Q89: Count frequency of a given character in a string.
#include <stdio.h>

int main(void) {
    char str[1000], target;
    int i = 0, count = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    printf("Enter the character to count: ");
    if (scanf(" %c", &target) != 1) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == target) {
            count++;
        }
        i++;
    }

    printf("Frequency of '%c' = %d\n", target, count);
    return 0;
}
