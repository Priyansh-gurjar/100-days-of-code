// Q94: Find the longest word in a sentence.
#include <stdio.h>

int main(void) {
    char sentence[1000];
    int i = 0, start = 0, currentLength = 0;
    int longestStart = 0, longestLength = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) return 1;

    while (1) {
        if (sentence[i] != ' ' && sentence[i] != '\t' &&
            sentence[i] != '\n' && sentence[i] != '\0') {
            if (currentLength == 0) {
                start = i;
            }
            currentLength++;
        } else {
            if (currentLength > longestLength) {
                longestLength = currentLength;
                longestStart = start;
            }
            currentLength = 0;

            if (sentence[i] == '\0' || sentence[i] == '\n') {
                break;
            }
        }
        i++;
    }

    if (longestLength == 0) {
        printf("No word found.\n");
    } else {
        printf("Longest word = ");
        for (i = longestStart; i < longestStart + longestLength; i++) {
            putchar(sentence[i]);
        }
        printf("\nLength = %d\n", longestLength);
    }

    return 0;
}
