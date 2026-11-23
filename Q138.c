#include <stdio.h>

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    COLOR_COUNT
};

int main(void) {
    const char *color_names[] = {
        "RED",
        "GREEN",
        "BLUE",
        "YELLOW"
    };

    for (enum Color c = RED; c < COLOR_COUNT; c++) {
        printf("%s = %d\n", color_names[c], c);
    }

    return 0;
}
