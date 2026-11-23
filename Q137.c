#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum UserRole {
    ADMIN,
    USER,
    GUEST
};

void display_role_message(enum UserRole role) {
    switch (role) {
        case ADMIN:
            printf("Welcome Admin! You have full access.\n");
            break;
        case USER:
            printf("Welcome User! You have standard access.\n");
            break;
        case GUEST:
            printf("Welcome Guest! You have limited access.\n");
            break;
    }
}

int main(void) {
    char input[32];

    if (scanf("%31s", input) != 1) {
        for (enum UserRole r = ADMIN; r <= GUEST; r++) {
            display_role_message(r);
        }
        return 0;
    }

    for (size_t i = 0; input[i] != '\0'; i++) {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    if (strcmp(input, "ADMIN") == 0 || strcmp(input, "0") == 0) {
        display_role_message(ADMIN);
    } else if (strcmp(input, "USER") == 0 || strcmp(input, "1") == 0) {
        display_role_message(USER);
    } else if (strcmp(input, "GUEST") == 0 || strcmp(input, "2") == 0) {
        display_role_message(GUEST);
    } else {
        printf("Invalid role.\n");
        return 1;
    }

    return 0;
}
