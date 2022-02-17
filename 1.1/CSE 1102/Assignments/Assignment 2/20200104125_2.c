//Write a programme to determine GCD and LCM of three numbers.
#include<stdio.h>
int main()
{
    int n;
    printf("1. GCD\n2. LCM\nWhich one do you want to calculate: \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            //GCD
            int n1, n2, n3, minimum,gcd=1,i;
            printf("Enter three positive integer:");
            scanf("%d %d %d", &n1, &n2, &n3);

            minimum = (n1 < n2) ? (n1 < n3 ? n1 : n3) : (n2 <n3 ? n2 : n3);

            for (i=2; i<=minimum/2; i++)
            {
                if (n1%i==0 &&n2%i ==0 && n3%i==0)
                {
                    gcd =i;
                }

            }
            printf("GCD= %d\n",gcd);
            break ;
        }
        case 2:
        {
            //LCD
            int i, n1, n2, n3, maximum;
            printf("Enter three positive integers:");
            scanf("%d %d %d", &n1, &n2, &n3);

            maximum = (n1 > n2 && n1 > n3) ? n1 : (n2 >n3 ? n2 : n3);

            for ( i = maximum; ; i++)
            {
                if (i % n1 == 0 && i % n2 == 0 && i % n3== 0)
                {
                    printf("LCM= %d\n",i);
                    break;
                }
            }

        }
    }
    return 0;
}