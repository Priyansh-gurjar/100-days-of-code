// Q84: Convert a lowercase string to uppercase without built-in functions.
#include <stdio.h>

int main(void) {
    char str[1000];
    int i = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }

    printf("Uppercase string = %s\n", str);
    return 0;
}
