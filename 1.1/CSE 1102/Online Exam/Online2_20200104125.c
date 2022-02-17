#include <stdio.h>

int main()
{
    int unit,metercharge= 100;
    float amount, total;

    printf("Enter unit: ");
    scanf("%d",&unit);


    if(unit <= 100)
    {
        amount = unit * 5;
    }
    else if(unit <= 250)
    {
        amount = 500 + ((unit-100) * 7.5);
    }
    else
    {
        amount = 1625 + ((unit-250) * 12.50);
    }

    total = amount + metercharge + (amount*0.10);

    printf("Electricity Bill = %.2f Taka.", total);

    return 0;
}
