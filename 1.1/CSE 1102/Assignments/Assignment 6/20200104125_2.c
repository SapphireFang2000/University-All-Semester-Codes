// Write a program to swap the values of two variables using call by reference.

#include<stdio.h>

int swp(int*,int*);

int main()
{
    int a,b;

    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    swp(&a,&b);

    printf("The swaping values are %d %d\n",a,b);

    return 0;
}

int swp(int *a,int *b)
{
   int temp;

   temp=*a;
   *a=*b;
   *b=temp;
}
