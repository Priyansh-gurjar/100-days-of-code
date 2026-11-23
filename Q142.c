#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 5

struct Student {
    char name[100];
    int roll_no;
    float marks;
};

int main(void) {
    struct Student students[NUM_STUDENTS];
    int c;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
            return 1;
        }
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }

        printf("Enter roll number: ");
        if (scanf("%d", &students[i].roll_no) != 1) {
            return 1;
        }

        printf("Enter marks: ");
        if (scanf("%f", &students[i].marks) != 1) {
            return 1;
        }

        while ((c = getchar()) != '\n' && c != EOF) {
            /* clear input buffer */
        }
    }

    printf("\nStudent Details:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Roll No", "Marks");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}
