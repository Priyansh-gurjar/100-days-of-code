#include <stdio.h>

enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main(void) {
    const char *month_names[] = {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    for (enum Month m = JANUARY; m <= DECEMBER; m++) {
        switch (m) {
            case JANUARY:
            case MARCH:
            case MAY:
            case JULY:
            case AUGUST:
            case OCTOBER:
            case DECEMBER:
                printf("%s: 31 days\n", month_names[m]);
                break;
            case APRIL:
            case JUNE:
            case SEPTEMBER:
            case NOVEMBER:
                printf("%s: 30 days\n", month_names[m]);
                break;
            case FEBRUARY:
                printf("%s: 28 or 29 days\n", month_names[m]);
                break;
        }
    }

    return 0;
}
