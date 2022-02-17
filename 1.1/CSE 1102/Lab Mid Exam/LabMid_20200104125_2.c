#include<stdio.h>
int main()
{
    int n,sum;

    printf("3+5+9+17+....+(up to nth term) = sum\nEnter the value of n: ");
    scanf("%d",&n);

    sum = pow(2,n+1)+(n-2);

    printf("%d",sum);

    return 0;
}
