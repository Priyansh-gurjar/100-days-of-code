#include <stdio.h>
#include <stdlib.h>

// Find the first occurrence of target using Binary Search - O(log n)
int findFirst(const int nums[], int n, int target) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1; // Keep searching in the left half
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Find the last occurrence of target using Binary Search - O(log n)
int findLast(const int nums[], int n, int target) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1; // Keep searching in the right half
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int *nums = (int *)malloc((size_t)(n > 0 ? n : 1) * sizeof(int));
    if (!nums) {
        return 1;
    }

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int first = findFirst(nums, n, target);
    int last = (first == -1) ? -1 : findLast(nums, n, target);

    printf("%d, %d\n", first, last);

    free(nums);
    return 0;
}
