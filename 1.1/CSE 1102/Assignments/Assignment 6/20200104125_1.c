// Write a program to calculate sum and average using call by reference.

#include<stdio.h>

int sum(int a[],int*);

int main()
{
    int n,add;

    printf("How many numbers do you want to sum and average: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter the %d numbers: ",n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    add=sum(a,&n);

    printf("The sum of %d numbers is: %d  and average is: %.2f.\n",n,add,(float)add/n);

    return 0;
}

int sum(int a[],int *n)
{
    int x=0;

    for(int i=0;i<*n;i++)
        x+=a[i];

    return x;
}

