// Write a program to find out the sum of the numbers in a list of array.

#include<stdio.h>

int main()
{
    int n,i,sum=0;

    printf("How many numbers do you want to sum: ");
    scanf("%d",&n);

    int a[n+1];

    printf("Enter %d numbers: ",n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(i=0; i<n; i++)
        sum = sum + a[i];

    printf("The result is %d.\n",sum);

    return 0;
}
