#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* clear input buffer */
    }

    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create students.txt\n");
        return 1;
    }

    char name[256];
    int roll;
    float marks;

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        if (fgets(name, sizeof(name), stdin) == NULL) {
            fclose(fp);
            return 1;
        }
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }

        printf("Enter roll number: ");
        if (scanf("%d", &roll) != 1) {
            fclose(fp);
            return 1;
        }

        printf("Enter marks: ");
        if (scanf("%f", &marks) != 1) {
            fclose(fp);
            return 1;
        }

        while ((c = getchar()) != '\n' && c != EOF) {
            /* clear input buffer */
        }

        fprintf(fp, "%s\t%d\t%.2f\n", name, roll, marks);
    }

    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open students.txt for reading\n");
        return 1;
    }

    printf("\nStudent Records:\n");
    while (fscanf(fp, " %255[^\t]\t%d\t%f", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %.2f\n", name, roll, marks);
    }

    fclose(fp);
    return 0;
}
