#include <stdio.h>

int main()
{
    int a, b, i, lcm;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a == 0 || b == 0)
    {
        lcm = 0;
    }
    else
    {
        if (a < 0)
        {
            a = -a;
        }

        if (b < 0)
        {
            b = -b;
        }

        lcm = a;

        while (lcm % b != 0)
        {
            lcm = lcm + a;
        }
    }

    printf("LCM = %d", lcm);

    return 0;
}
