#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Could not create output.txt\n");
        fclose(in);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(toupper((unsigned char)ch), out);
    }

    fclose(in);
    fclose(out);

    printf("Converted text written to output.txt\n");
    return 0;
}
