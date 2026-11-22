#include <stdio.h>
#include <string.h>

#define MAX_LEN 100005

// Find the length of the longest substring without repeating characters - O(n)
int lengthOfLongestSubstring(const char *s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1;
        }
        lastIndex[ch] = i;

        int currentLen = i - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

int main(void) {
    char s[MAX_LEN];
    printf("Enter string: ");
    if (!fgets(s, sizeof(s), stdin)) {
        return 1;
    }

    // Remove trailing newline / carriage return if present
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[--len] = '\0';
    }

    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
