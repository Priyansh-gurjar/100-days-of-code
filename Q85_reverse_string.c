// Q85: Reverse a string.
#include <stdio.h>

int main(void) {
    char str[1000], temp;
    int length = 0, i;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    str[length] = '\0';

    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    printf("Reversed string = %s\n", str);
    return 0;
}
