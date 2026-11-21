// Q83: Count vowels and consonants in a string.
#include <stdio.h>

int main(void) {
    char str[1000];
    int i = 0, vowels = 0, consonants = 0;
    char ch;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[i] != '\0' && str[i] != '\n') {
        ch = str[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        i++;
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    return 0;
}
