//Write a programme to find out first n perfect number where is the input from user.
#include<stdio.h>
int main()
{
    int n,i,j,sum;

    printf("Enter a value of n: ");
    scanf("%d",&n);
    printf("All the perfect number between 1 to %d is ",n);

    for(i=1;i<=n;i++)
    {
        sum=0;

        for(j=1;j<i;j++)
        {
            if(i%j==0)
                sum = sum+j;
        }

        if(sum==i)
        {
            printf("%d,",i);
        }
    }

    printf("\n");

    return 0;
}