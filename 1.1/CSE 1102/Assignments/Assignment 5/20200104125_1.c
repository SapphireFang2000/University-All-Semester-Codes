//Write a function that can generate the Sum of Natural Numbers Using Recursion.

#include<stdio.h>

int sum_natural(int);

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    printf("The sum of natural number ( 1 to %d ) is %d.\n",n,sum_natural(n));

    return 0;
}

int sum_natural(int x)
{
    if(x==1)
        return 1;

    else
        return x + sum_natural(x-1);
}

