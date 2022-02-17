#include<stdio.h>
int main()
{
    int n,i,a;

    printf("Enter a number: ");
    scanf("%d",&n);

    a=0;
    i=2;

    while(i <= n/2)
    {
        if(n%i == 0)
        {
            a=1;
            break;
        }
        i++;
    }

    if(a==0)
        printf("%d is a Prime Number\n",n);
    else
        printf("%d is not a Prime Number\n",n);

    return 0;
}
