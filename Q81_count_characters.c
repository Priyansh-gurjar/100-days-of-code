// Q81: Count characters in a string without using built-in length functions.
#include <stdio.h>

int main(void) {
    char str[1000];
    int count = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[count] != '\0' && str[count] != '\n') {
        count++;
    }

    printf("Number of characters = %d\n", count);
    return 0;
}
