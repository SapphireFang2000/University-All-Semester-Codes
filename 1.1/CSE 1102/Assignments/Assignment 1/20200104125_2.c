//Write a program to find out the maximum of 2 numbers using switch case.
#include<stdio.h>
int main()
{
    int num1,num2;

    printf("Enter two number: ");
    scanf("%d%d",&num1,&num2);

    switch(num1>num2)
    {
        case 0:
            printf("The maximum number is %d.\n",num2);
            break;

        case 1:
            printf("The maximum number is %d.\n",num1);
            break;
    }

    return 0;
}

