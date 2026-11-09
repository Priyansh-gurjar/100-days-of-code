#include <stdio.h>

int main()
{
    char op;
    float num1, num2;

    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &op);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (op)
    {
        case '+':
            printf("Result = %.2f", num1 + num2);
            break;

        case '-':
            printf("Result = %.2f", num1 - num2);
            break;

        case '*':
            printf("Result = %.2f", num1 * num2);
            break;

        case '/':
            if (num2 != 0)
                printf("Result = %.2f", num1 / num2);
            else
                printf("Division by zero is not allowed.");
            break;

        case '%':
            if (num2 != 0)
                printf("Result = %d", (int)num1 % (int)num2);
            else
                printf("Modulo by zero is not allowed.");
            break;

        default:
            printf("Invalid operator.");
    }

    return 0;
}
