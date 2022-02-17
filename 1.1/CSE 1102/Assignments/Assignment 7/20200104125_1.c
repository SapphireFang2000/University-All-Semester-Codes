// Write a program to delete a specific value from an array input from the user.

#include<stdio.h>

int main()
{
    int n,i,j,value,count = 0;

    printf("How much number do you want to input in an array: ");
    scanf("%d",&n);

    int a[n+1];

    printf("Enter the Elements of Array : ");

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("Enter the value which will be deleted : ");
    scanf("%d",&value);

    for(i=0; i<n; i++)
    {
        if(a[i]==value)
            count++;
    }

    if(count==n)
        printf("All the value of array are same.");

    else if(count==0)
        printf("The value %d does not found in the given array.",value);

    else
    {
        for(i=0; i<n; i++)
        {
            if(a[i]==value)
                a[i] = -1;
        }

        for(i=0; i<n; i++)
        {
            if(a[i]!=-1)
                printf("%d ",a[i]);
        }
    }

    printf("\n");

    return 0;
}
