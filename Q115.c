#include <stdio.h>
#include <string.h>

#define MAX_LEN 100005

// Determine if two lowercase strings s and t are valid anagrams - O(n)
int isAnagram(const char *s, const char *t) {
    size_t lenS = strlen(s);
    size_t lenT = strlen(t);

    if (lenS != lenT) {
        return 0;
    }

    int freq[26] = {0};
    for (size_t i = 0; i < lenS; i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    char s[MAX_LEN], t[MAX_LEN];

    printf("Enter first string s: ");
    if (scanf("%100004s", s) != 1) {
        return 1;
    }

    printf("Enter second string t: ");
    if (scanf("%100004s", t) != 1) {
        return 1;
    }

    if (isAnagram(s, t)) {
        printf("Anagram\n");
    } else {
        printf("Not Anagram\n");
    }

    return 0;
}
