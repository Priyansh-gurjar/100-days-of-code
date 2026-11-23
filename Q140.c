#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    char name[100];
    enum Gender gender;
};

void print_gender(enum Gender g) {
    switch (g) {
        case MALE:
            printf("Male\n");
            break;
        case FEMALE:
            printf("Female\n");
            break;
        case OTHER:
            printf("Other\n");
            break;
    }
}

int main(void) {
    struct Person p;
    char gender_input[32];

    printf("Enter gender (MALE, FEMALE, OTHER or 0, 1, 2): ");
    if (scanf("%31s", gender_input) != 1) {
        strcpy(p.name, "Alex");
        p.gender = MALE;
        printf("Gender: ");
        print_gender(p.gender);
        return 0;
    }

    for (size_t i = 0; gender_input[i] != '\0'; i++) {
        gender_input[i] = (char)toupper((unsigned char)gender_input[i]);
    }

    if (strcmp(gender_input, "MALE") == 0 || strcmp(gender_input, "0") == 0) {
        p.gender = MALE;
    } else if (strcmp(gender_input, "FEMALE") == 0 || strcmp(gender_input, "1") == 0) {
        p.gender = FEMALE;
    } else if (strcmp(gender_input, "OTHER") == 0 || strcmp(gender_input, "2") == 0) {
        p.gender = OTHER;
    } else {
        printf("Invalid gender.\n");
        return 1;
    }

    printf("Gender: ");
    print_gender(p.gender);

    return 0;
}
