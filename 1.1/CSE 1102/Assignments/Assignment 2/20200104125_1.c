//x and n input through keyboard. write a programme to compute x^n, n!, ncr, npr.
#include<stdio.h>
int main()
{
    int x,n,r,a,i,multi=1,fact1=1,fact2=1,fact3=1,diff,result;

    printf("1. x^n\n2. n!\n3. ncr\n4. npr\nWhich function do you want to calculate: ");
    scanf("%d",&a);

    //x^n
    if(a==1)
    {
        printf("Enter the value of x and n: ");
        scanf("%d%d",&x,&n);

        for(i=1;i<=n;i++)
            multi = multi*x;

        printf("Result= %d.\n",multi);
    }

    //n!
    else if(a==2)
    {
        printf("Enter the value of n: ");
        scanf("%d",&n);

        for(i=1;i<=n;i++)
            fact1 = fact1*i;

        printf("Result= %d.\n",fact1);
    }

    //ncr
    else if(a==3)
    {
        printf("Enter the value of n and r: ");
        scanf("%d%d",&n,&r);

        diff = n-r;

        for(i=1;i<=n;i++)
            fact1 = fact1*i;

        for(i=1;i<=r;i++)
            fact2 = fact2*i;

        for(i=1;i<=diff;i++)
            fact3 = fact3*i;

        result = fact1/(fact2*fact3);

        printf("Result= %d.\n",result);
    }

    //npr
    else if(a==4)
    {
        printf("Enter the value of n and r: ");
        scanf("%d%d",&n,&r);

        diff = n-r;

        for(i=1;i<=n;i++)
            fact1 = fact1*i;

        for(i=1;i<=diff;i++)
            fact3 = fact3*i;

        result = fact1/fact3;

        printf("Result= %d.\n",result);
    }

    return 0;
}