#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int roll_no;
    float marks;
};

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

    struct Student *students = (struct Student *)malloc((size_t)n * sizeof(struct Student));
    if (students == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
            free(students);
            return 1;
        }
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }

        printf("Enter roll number: ");
        if (scanf("%d", &students[i].roll_no) != 1) {
            free(students);
            return 1;
        }

        printf("Enter marks: ");
        if (scanf("%f", &students[i].marks) != 1) {
            free(students);
            return 1;
        }

        while ((c = getchar()) != '\n' && c != EOF) {
            /* clear input buffer */
        }
    }

    int top_idx = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[top_idx].marks) {
            top_idx = i;
        }
    }

    printf("\nTopper: %s (Roll: %d, Marks: %.2f)\n",
           students[top_idx].name,
           students[top_idx].roll_no,
           students[top_idx].marks);

    free(students);
    return 0;
}
