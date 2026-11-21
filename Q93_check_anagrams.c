// Q93: Check whether two strings are anagrams.
// This program ignores letter case and spaces.
#include <stdio.h>

int main(void) {
    char first[1000], second[1000];
    int frequency[256] = {0};
    int i, isAnagram = 1;

    printf("Enter the first string: ");
    if (fgets(first, sizeof(first), stdin) == NULL) return 1;

    printf("Enter the second string: ");
    if (fgets(second, sizeof(second), stdin) == NULL) return 1;

    for (i = 0; first[i] != '\0' && first[i] != '\n'; i++) {
        unsigned char ch = (unsigned char)first[i];

        if (ch != ' ') {
            if (ch >= 'A' && ch <= 'Z') ch = (unsigned char)(ch + ('a' - 'A'));
            frequency[ch]++;
        }
    }

    for (i = 0; second[i] != '\0' && second[i] != '\n'; i++) {
        unsigned char ch = (unsigned char)second[i];

        if (ch != ' ') {
            if (ch >= 'A' && ch <= 'Z') ch = (unsigned char)(ch + ('a' - 'A'));
            frequency[ch]--;
        }
    }

    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
