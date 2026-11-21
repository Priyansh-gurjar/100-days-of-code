// Q99: Change date format from dd/04/yyyy to dd-Apr-yyyy.
// This program accepts a date in dd/mm/yyyy format and converts
// the month number to its three-letter abbreviation.
#include <stdio.h>

int main(void) {
    int day, month, year;
    const char *months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("Enter date (dd/mm/yyyy): ");
    if (scanf("%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid date format.\\n");
        return 1;
    }

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Invalid date.\\n");
        return 1;
    }

    printf("Formatted date = %02d-%s-%04d\\n", day, months[month - 1], year);
    return 0;
}
