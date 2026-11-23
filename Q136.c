#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum MenuChoice {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main(void) {
    char choice_input[32];
    int a, b;

    printf("Menu:\n");
    printf("1. ADD\n");
    printf("2. SUBTRACT\n");
    printf("3. MULTIPLY\n");
    printf("Enter your choice (1-3 or ADD/SUBTRACT/MULTIPLY): ");

    if (scanf("%31s", choice_input) != 1) {
        return 1;
    }

    for (size_t i = 0; choice_input[i] != '\0'; i++) {
        choice_input[i] = (char)toupper((unsigned char)choice_input[i]);
    }

    enum MenuChoice choice;
    if (strcmp(choice_input, "1") == 0 || strcmp(choice_input, "ADD") == 0) {
        choice = ADD;
    } else if (strcmp(choice_input, "2") == 0 || strcmp(choice_input, "SUBTRACT") == 0) {
        choice = SUBTRACT;
    } else if (strcmp(choice_input, "3") == 0 || strcmp(choice_input, "MULTIPLY") == 0) {
        choice = MULTIPLY;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }

    switch (choice) {
        case ADD:
            printf("Result: %d\n", a + b);
            break;
        case SUBTRACT:
            printf("Result: %d\n", a - b);
            break;
        case MULTIPLY:
            printf("Result: %d\n", a * b);
            break;
    }

    return 0;
}
