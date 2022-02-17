//Write a programme to check wheather a number is prime or not.
#include<stdio.h>
int main()
{
    int n,i,count=0;

    printf("Enter a number: ");
    scanf("%d",&n);

    for(i=2;i<n;i++)
    {
        if(n%i==0)
            count++;
            break;
    }

    if(count==0)
        printf("The number is a prime number.\n");

    else
        printf("The number is not a prime number.\n");

    return 0;
}