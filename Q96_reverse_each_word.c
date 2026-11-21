// Q96: Reverse each word in a sentence without changing word order.
#include <stdio.h>

int main(void) {
    char sentence[1000];
    int i = 0, start = 0, j;
    char temp;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) return 1;

    while (sentence[i] != '\0' && sentence[i] != '\n') {
        if (sentence[i] == ' ' || sentence[i] == '\\t') {
            int left = start;
            int right = i - 1;

            while (left < right) {
                temp = sentence[left];
                sentence[left] = sentence[right];
                sentence[right] = temp;
                left++;
                right--;
            }
            start = i + 1;
        }
        i++;
    }

    {
        int left = start;
        int right = i - 1;
        while (left < right) {
            temp = sentence[left];
            sentence[left] = sentence[right];
            sentence[right] = temp;
            left++;
            right--;
        }
    }

    sentence[i] = '\0';
    printf("Result = %s\\n", sentence);
    return 0;
}
