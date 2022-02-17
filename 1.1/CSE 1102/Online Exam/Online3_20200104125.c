#include<stdio.h>
int main()
{
    int a,b,c,min,i,gcd;
    printf("Enter the 3 numbers a,b,c : ");
    scanf("%d%d%d",&a,&b,&c);
    min=a<b && a<c? a:b<c?b:c;
    for(i=2;i<=min/2;i++)
    {
        if(a%i==0 && b%i==0 && c%i==0)
        {
            gcd = i;
            break;
        }
    }
    printf("\n gcd = %d",i);
    return 0;
}
