#include <stdio.h>
#include <string.h>

int main(void) {
    char src_name[256];
    char dest_name[256];

    printf("Enter source filename: ");
    if (fgets(src_name, sizeof(src_name), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(src_name);
    if (len > 0 && src_name[len - 1] == '\n') {
        src_name[len - 1] = '\0';
    }

    printf("Enter destination filename: ");
    if (fgets(dest_name, sizeof(dest_name), stdin) == NULL) {
        return 1;
    }
    len = strlen(dest_name);
    if (len > 0 && dest_name[len - 1] == '\n') {
        dest_name[len - 1] = '\0';
    }

    FILE *src = fopen(src_name, "r");
    if (src == NULL) {
        printf("Error: Could not open source file %s\n", src_name);
        return 1;
    }

    FILE *dest = fopen(dest_name, "w");
    if (dest == NULL) {
        printf("Error: Could not open destination file %s\n", dest_name);
        fclose(src);
        return 1;
    }

    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully from %s to %s\n", src_name, dest_name);
    return 0;
}
