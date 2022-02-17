// Write a program to merge two arrays removing the duplicate elements.

#include<stdio.h>

int main()
{
    int n1,n2,i,j;

    printf("How much number do you want to input in 1st array: ");
    scanf("%d",&n1);

    int a[n1+1];

    printf("Enter the Elements of 1st Array : ");

    for(i=0; i<n1; i++)
        scanf("%d",&a[i]);

    printf("How much number do you want to input in 2nd array: ");
    scanf("%d",&n2);

    int b[n2+1];

    printf("Enter the Elements of 2nd Array : ");

    for(i=0; i<n2; i++)
        scanf("%d",&b[i]);

    int c[n1+n2+1];

    for(i=0; i<n1; i++)
        c[i]=a[i];

    for(i; i<n1+n2; i++)
        c[i]=b[i-n1];

    for(i=0; i<n1+n2-1; i++)
    {
        for(j=i+1; j<n1+n2; j++)
        {
            if(c[i]==c[j])
                c[j] = -1;
        }
    }

    for(i=0; i<n1+n2; i++)
    {
        if(c[i] != -1)
            printf("%d ",c[i]);
    }

    printf("\n");

    return 0;
}
