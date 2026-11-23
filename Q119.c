#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    size_t cap = 8;
    while (cap < (size_t)n * 2) {
        cap <<= 1;
    }

    int *keys = (int *)malloc(cap * sizeof(int));
    unsigned char *used = (unsigned char *)calloc(cap, sizeof(unsigned char));
    if (keys == NULL || used == NULL) {
        free(keys);
        free(used);
        return 1;
    }

    int repeated = 0;
    int found = 0;

    /* Single iteration: read each element and check/insert in hash set */
    for (int i = 0; i < n; i++) {
        int val;
        if (scanf("%d", &val) != 1) {
            break;
        }
        if (found) {
            continue;
        }

        size_t idx = ((unsigned int)val * 2654435761u) & (cap - 1);
        while (used[idx]) {
            if (keys[idx] == val) {
                repeated = val;
                found = 1;
                break;
            }
            idx = (idx + 1) & (cap - 1);
        }

        if (!found) {
            used[idx] = 1;
            keys[idx] = val;
        }
    }

    if (found) {
        printf("%d\n", repeated);
    }

    free(keys);
    free(used);
    return 0;
}
