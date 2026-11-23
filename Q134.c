#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

void print_status_message(enum Status s) {
    switch (s) {
        case SUCCESS:
            printf("SUCCESS: Operation completed successfully.\n");
            break;
        case FAILURE:
            printf("FAILURE: Operation failed.\n");
            break;
        case TIMEOUT:
            printf("TIMEOUT: Operation timed out.\n");
            break;
    }
}

int main(void) {
    char input[32];

    if (scanf("%31s", input) != 1) {
        for (enum Status s = SUCCESS; s <= TIMEOUT; s++) {
            print_status_message(s);
        }
        return 0;
    }

    for (size_t i = 0; input[i] != '\0'; i++) {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    if (strcmp(input, "SUCCESS") == 0 || strcmp(input, "0") == 0) {
        print_status_message(SUCCESS);
    } else if (strcmp(input, "FAILURE") == 0 || strcmp(input, "1") == 0) {
        print_status_message(FAILURE);
    } else if (strcmp(input, "TIMEOUT") == 0 || strcmp(input, "2") == 0) {
        print_status_message(TIMEOUT);
    } else {
        printf("Invalid status.\n");
        return 1;
    }

    return 0;
}
