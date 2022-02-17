//1+(2^2/2!)+(3^2/3!)+......+(n^2/n!).
#include<stdio.h>
int main()
{
    float n,i,multi,fact=1,result=0;

    printf("Enter the value of n: ");
    scanf("%f",&n);

    for(i=1;i<=n;i++)
    {
        multi = i*i;
        fact = fact*i;
        result = result+(multi/fact);
    }
    printf("Result: %f\n",result);

    return 0;
}