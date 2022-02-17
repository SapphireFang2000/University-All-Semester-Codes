// Write a program to find out the maximum, minimum of an array of numbers.

#include<stdio.h>

int main()
{
    int n,i,max,min;

    printf("How many numbers do you want to input: ");
    scanf("%d",&n);

    int a[n+1];

    printf("Enter %d numbers: ",n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    max = a[0];
    min = a[0];

    for(i=1; i<n; i++)
    {
        if(max<a[i])
            max = a[i];

        if(min>a[i])
            min = a[i];
    }

    printf("The maximum number is %d.\n",max);
    printf("The minimum number is %d.\n",min);

    return 0;
}
