// Q91: Remove all vowels from a string.
#include <stdio.h>

int main(void) {
    char str[1000];
    int i = 0, j = 0;
    char ch;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        ch = str[i];

        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            str[j] = str[i];
            j++;
        }
        i++;
    }

    str[j] = '\0';
    printf("String without vowels = %s\n", str);
    return 0;
}
