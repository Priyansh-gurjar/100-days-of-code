// Q97: Print the initials of a name.
#include <stdio.h>

int main(void) {
    char name[500];
    int i = 0, atWordStart = 1;

    printf("Enter your full name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) return 1;

    printf("Initials = ");
    while (name[i] != '\0' && name[i] != '\n') {
        if (name[i] != ' ' && name[i] != '\\t') {
            if (atWordStart) {
                printf("%c", name[i]);
                atWordStart = 0;
            }
        } else {
            atWordStart = 1;
        }
        i++;
    }
    printf("\\n");
    return 0;
}
