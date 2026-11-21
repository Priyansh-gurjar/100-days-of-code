// Q100: Print all substrings of a string.
#include <stdio.h>

int main(void) {
    char str[500];
    int length = 0, start, end, i;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }

    printf("All substrings:\\n");
    for (start = 0; start < length; start++) {
        for (end = start; end < length; end++) {
            for (i = start; i <= end; i++) {
                putchar(str[i]);
            }
            putchar('\\n');
        }
    }

    return 0;
}
