#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[256];
    char line[1024];

    printf("Enter filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Could not open %s\n", filename);
        return 1;
    }

    printf("Enter text to append: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fclose(fp);
        return 1;
    }
    len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    fprintf(fp, "%s\n", line);
    fclose(fp);

    printf("Text appended successfully to %s\n", filename);
    return 0;
}
