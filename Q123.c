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
    int last_ch = EOF;
    long characters = 0;
    long words = 0;
    long lines = 0;
    int in_word = 0;

    while ((ch = fgetc(fp)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
        last_ch = ch;
    }

    if (characters > 0 && last_ch != '\n') {
        lines++;
    }

    fclose(fp);

    printf("Characters: %ld\n", characters);
    printf("Words: %ld\n", words);
    printf("Lines: %ld\n", lines);
    return 0;
}
