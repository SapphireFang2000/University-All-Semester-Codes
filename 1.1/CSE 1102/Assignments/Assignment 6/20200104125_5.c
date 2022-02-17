// Write a program to copy the elements of one array into another array.

#include<stdio.h>

int main()
{
    int n,i;

    printf("How many numbers do you want to input: ");
    scanf("%d",&n);

    int a[n+1],b[n+1];

    printf("Enter %d numbers to 'a' array: ",n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(i=0; i<n; i++)
        b[i]=a[i];

    printf("The copy of 'a' array to 'b' array is ");

    for(i=0; i<n; i++)
        printf("%d ",b[i]);

    printf("\n");

    return 0;
}
