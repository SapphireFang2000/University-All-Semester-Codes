// Write a recursive function that can reverse a number given as input.

#include<stdio.h>
int reverse(int);
int main()
{
    int n;

    printf("Enter a Number: ");
    scanf("%d",&n);

    printf("The reverse number of %d is %d.\n",n,reverse(n));

    return 0;
}

int reverse(int x)
{
    int temp,mod;
    static int sum=0;

    if(x==0)
        return sum;

    else
    {
        temp=x;
        mod = temp%10;
        sum = sum*10 + mod;

        return reverse(x/10);
    }

}
