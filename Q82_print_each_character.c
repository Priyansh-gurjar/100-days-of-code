// Q82: Print each character of a string on a new line.
#include <stdio.h>

int main(void) {
    char str[1000];
    int i = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        printf("%c\n", str[i]);
        i++;
    }

    return 0;
}
