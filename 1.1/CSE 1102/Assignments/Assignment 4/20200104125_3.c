// Write a function to check whether a number is an Armstrong number or not.

#include<stdio.h>

int armstrongNumber(int);

void main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    if(n == armstrongNumber(n))
        printf("Armstrong Number.\n");
    else
        printf("Not an Armstrong Number.\n");
}

int armstrongNumber(int number)
{
    int i,count=0,sum=0,rem,r,flag;

    flag = number;

    while(number!=0)
    {
        rem = number%10;
        count++;
        number /= 10;
    }
    while(flag!=0)
    {
        int p=1;
        r = flag%10;
        for(i=1; i<=count; i++)
        {
            p = p*r;
        }
        sum = sum+p;

        flag /= 10;
    }
    return sum;
}