#include <stdio.h>

int main()
{
    float costPrice, sellingPrice, difference, percentage;

    printf("Enter cost price: ");
    scanf("%f", &costPrice);

    printf("Enter selling price: ");
    scanf("%f", &sellingPrice);

    if (costPrice <= 0)
    {
        printf("Cost price must be greater than zero.\n");
    }
    else if (sellingPrice > costPrice)
    {
        difference = sellingPrice - costPrice;
        percentage = (difference / costPrice) * 100;

        printf("Profit = %.2f\n", difference);
        printf("Profit percentage = %.2f%%\n", percentage);
    }
    else if (sellingPrice < costPrice)
    {
        difference = costPrice - sellingPrice;
        percentage = (difference / costPrice) * 100;

        printf("Loss = %.2f\n", difference);
        printf("Loss percentage = %.2f%%\n", percentage);
    }
    else
    {
        printf("No profit, no loss.\n");
    }

    return 0;
}
