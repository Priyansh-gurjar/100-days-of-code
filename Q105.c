#include <stdio.h>
#include <stdlib.h>

// Find the majority element (> n/2 times) using Boyer-Moore Voting Algorithm - O(n)
int findMajorityElement(const int nums[], int n) {
    if (n <= 0) {
        return -1;
    }

    int candidate = 0;
    int count = 0;

    // Phase 1: Find a candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate actually appears strictly more than n / 2 times
    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            freq++;
        }
    }

    if (freq > n / 2) {
        return candidate;
    }
    return -1;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int *nums = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    if (!nums) {
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int majority = findMajorityElement(nums, n);
    printf("%d\n", majority);

    free(nums);
    return 0;
}
