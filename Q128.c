#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[256];

    printf("Enter filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", filename);
        return 1;
    }

    int ch;
    long vowels = 0;
    long consonants = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha((unsigned char)ch)) {
            int lower = tolower((unsigned char)ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    fclose(fp);

    printf("Vowels: %ld\n", vowels);
    printf("Consonants: %ld\n", consonants);
    return 0;
}
