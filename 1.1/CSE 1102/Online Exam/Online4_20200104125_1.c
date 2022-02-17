#include<stdio.h>
#include<math.h>
int main()
{
    float i,j,n,x,multi=1,result=1;

    printf("Enter X and N: ");
    scanf("%f%f",&x,&n);

    for(i=2; i<=n; i=i+2)
    {
        int fact=1;
        for(j=i; j>=1; j--)
        {
            fact = fact*j;
        }

        multi = pow(x,i);
        result = result + (multi/fact);
    }

    printf("%.2f\n",result);

    return 0;
}
