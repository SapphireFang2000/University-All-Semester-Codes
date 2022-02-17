//Wrinte a c programme and print 0 to n fibonacci number.
#include<stdio.h>
int main()
{
    int n,i=0,num1=0,num2=1,fibo=0;

    scanf("%d",&n);

    while(i<n)
    {
        if(i<=1)
            fibo = i;

        else
        {
            fibo = num1 + num2;
            num1 = num2;
            num2 = fibo;
        }

        i++;

        printf("%d ",fibo);
    }

    printf("\n");

    return 0;
}
