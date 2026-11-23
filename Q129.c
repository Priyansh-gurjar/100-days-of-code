#include <stdio.h>

int main(void) {
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open numbers.txt\n");
        return 1;
    }

    int num;
    long long sum = 0;
    long count = 0;

    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("Sum: 0\n");
        printf("Average: 0.00\n");
    } else {
        double average = (double)sum / count;
        printf("Sum: %lld\n", sum);
        printf("Average: %.2f\n", average);
    }

    return 0;
}
