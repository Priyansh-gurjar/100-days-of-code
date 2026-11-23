#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1024];

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    int capitalize_next = 1;
    for (size_t i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (isalpha(ch)) {
            if (capitalize_next) {
                str[i] = (char)toupper(ch);
                capitalize_next = 0;
            } else {
                str[i] = (char)tolower(ch);
            }
        } else if (ch == '.' || ch == '!' || ch == '?') {
            capitalize_next = 1;
        }
    }

    printf("%s\n", str);
    return 0;
}
