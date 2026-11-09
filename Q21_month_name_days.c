#include <stdio.h>

int main()
{
    int month, year, days;

    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    switch (month)
    {
        case 1:
            printf("January has 31 days.\n");
            break;
        case 2:
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            {
                days = 29;
            }
            else
            {
                days = 28;
            }
            printf("February has %d days.\n", days);
            break;
        case 3:
            printf("March has 31 days.\n");
            break;
        case 4:
            printf("April has 30 days.\n");
            break;
        case 5:
            printf("May has 31 days.\n");
            break;
        case 6:
            printf("June has 30 days.\n");
            break;
        case 7:
            printf("July has 31 days.\n");
            break;
        case 8:
            printf("August has 31 days.\n");
            break;
        case 9:
            printf("September has 30 days.\n");
            break;
        case 10:
            printf("October has 31 days.\n");
            break;
        case 11:
            printf("November has 30 days.\n");
            break;
        case 12:
            printf("December has 31 days.\n");
            break;
        default:
            printf("Invalid month number.\n");
    }

    return 0;
}
