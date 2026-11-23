#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main(void) {
    char input[32];

    printf("Enter traffic light (RED, YELLOW, GREEN or 0, 1, 2): ");
    if (scanf("%31s", input) != 1) {
        return 1;
    }

    for (size_t i = 0; input[i] != '\0'; i++) {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    enum TrafficLight light;
    if (strcmp(input, "RED") == 0 || strcmp(input, "0") == 0) {
        light = RED;
    } else if (strcmp(input, "YELLOW") == 0 || strcmp(input, "1") == 0) {
        light = YELLOW;
    } else if (strcmp(input, "GREEN") == 0 || strcmp(input, "2") == 0) {
        light = GREEN;
    } else {
        printf("Invalid traffic light value.\n");
        return 1;
    }

    switch (light) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
    }

    return 0;
}
