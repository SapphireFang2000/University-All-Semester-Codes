// Write a program to print all the prime numbers from an integer array and find out their sum.

#include<stdio.h>
int main()
{
    int n,i,j,sum = 0;

    printf("How much number do you want to input in an array: ");
    scanf("%d",&n);

    int a[n+1];

    printf("Enter the Elements of Array : ");

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("All the prime numbers from the given array are: ");

    for(i=0; i<n; i++)
    {
        int count=0;

        if(a[i]>=2)
        {
            for(j=2; j<=a[i]/2; j++)
            {
                if(a[i]%j==0)
                {
                    count++;
                    break;
                }
            }

            if(count==0)
            {
                printf("%d ",a[i]);
                sum = sum + a[i];
            }
        }
    }

    printf("\n");
    printf("The sum of all the prime numbers from the given array is: %d\n",sum);

    return 0;
}
