// Q86: Check whether a string is a palindrome.
// This version compares characters exactly, including case and spaces.
#include <stdio.h>

int main(void) {
    char str[1000];
    int length = 0, left, right, isPalindrome = 1;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }

    left = 0;
    right = length - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
