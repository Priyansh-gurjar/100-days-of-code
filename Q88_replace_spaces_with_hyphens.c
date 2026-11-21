// Q88: Replace spaces with hyphens in a string.
#include <stdio.h>

int main(void) {
    char str[1000];
    int i = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == ' ') {
            str[i] = '-';
        }
        i++;
    }

    printf("Modified string = %s\n", str);
    return 0;
}
