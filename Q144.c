#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int roll_no;
    float marks;
};

void printStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %.2f\n", s.name, s.roll_no, s.marks);
}

int main(void) {
    struct Student s;

    printf("Enter name: ");
    if (fgets(s.name, sizeof(s.name), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(s.name);
    if (len > 0 && s.name[len - 1] == '\n') {
        s.name[len - 1] = '\0';
    }

    printf("Enter roll number: ");
    if (scanf("%d", &s.roll_no) != 1) {
        return 1;
    }

    printf("Enter marks: ");
    if (scanf("%f", &s.marks) != 1) {
        return 1;
    }

    printf("\nStudent Details:\n");
    printStudent(s);

    return 0;
}
