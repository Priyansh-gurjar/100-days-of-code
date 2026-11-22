#include <stdio.h>
#include <stdlib.h>

// Compute product of array except self in O(n) time without using division
void productExceptSelf(const int nums[], int answer[], int n) {
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int *nums = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    int *answer = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    if (!nums || !answer) {
        free(nums);
        free(answer);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    productExceptSelf(nums, answer, n);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", answer[i]);
    }
    printf("\n");

    free(nums);
    free(answer);
    return 0;
}
