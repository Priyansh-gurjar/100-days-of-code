#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[100];
    int id;
    struct Date joining_date;
};

int main(void) {
    struct Employee emp;

    printf("Enter employee name: ");
    if (fgets(emp.name, sizeof(emp.name), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(emp.name);
    if (len > 0 && emp.name[len - 1] == '\n') {
        emp.name[len - 1] = '\0';
    }

    printf("Enter employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        return 1;
    }

    printf("Enter joining date (DD MM YYYY): ");
    if (scanf("%d %d %d", &emp.joining_date.day, &emp.joining_date.month, &emp.joining_date.year) != 3) {
        return 1;
    }

    printf("\nEmployee Details:\n");
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           emp.name,
           emp.id,
           emp.joining_date.day,
           emp.joining_date.month,
           emp.joining_date.year);

    return 0;
}
