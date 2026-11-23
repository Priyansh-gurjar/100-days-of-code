#include <stdio.h>
#include <string.h>

int main(void) {
    char name[256];
    int age;

    printf("Enter name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("Enter age: ");
    if (scanf("%d", &age) != 1) {
        return 1;
    }

    FILE *fp = fopen("info.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create info.txt\n");
        return 1;
    }

    fprintf(fp, "Name: %s\nAge: %d\n", name, age);
    fclose(fp);

    printf("Data successfully saved to info.txt\n");
    return 0;
}
