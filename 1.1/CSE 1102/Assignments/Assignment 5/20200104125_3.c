// Write a recursive function which can count the number of digits in a given number.

#include<stdio.h>

int digit(int);

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    printf("%d\n",digit(n));

    return 0;
}

int digit(int x)
{
    int temp,mod;
    static int count=0;

    if(x==0)
        return count;

    else
    {
        temp=x;
        mod = temp%10;
        count++;

        return digit(x/10);
    }
}
