// Q98: Print initials of a name with the surname displayed in full.
#include <stdio.h>

int main(void) {
    char name[500];
    int start[100], end[100];
    int words = 0, i = 0, j;

    printf("Enter your full name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) return 1;

    while (name[i] != '\0' && name[i] != '\n') {
        while (name[i] == ' ' || name[i] == '\\t') i++;

        if (name[i] == '\0' || name[i] == '\n') break;

        if (words < 100) {
            start[words] = i;
            while (name[i] != '\0' && name[i] != '\n' &&
                   name[i] != ' ' && name[i] != '\\t') {
                i++;
            }
            end[words] = i;
            words++;
        } else {
            break;
        }
    }

    if (words == 0) {
        printf("No name entered.\\n");
    } else {
        printf("Formatted name = ");
        for (j = 0; j < words - 1; j++) {
            printf("%c. ", name[start[j]]);
        }
        for (i = start[words - 1]; i < end[words - 1]; i++) {
            putchar(name[i]);
        }
        printf("\\n");
    }

    return 0;
}
