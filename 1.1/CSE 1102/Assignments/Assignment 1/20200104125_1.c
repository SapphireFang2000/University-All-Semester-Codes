//Write a program to find out whether it is an odd number or even number using switch case.
#include<stdio.h>
int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d",&num);

    switch(num%2)
    {
    case 0:
        printf("The number is even.\n");
        break;

    case 1:
        printf("The number is odd.\n");
        break;
    }

    return 0;
}
