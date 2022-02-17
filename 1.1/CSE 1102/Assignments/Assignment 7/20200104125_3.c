// Write a program to separate odd and even integers in separate arrays.

#include<stdio.h>
int main()
{
    int n,i,j=0,k=0;

    printf("How much number do you want to input in an array: ");
    scanf("%d",&n);

    int a[n+1],odd[n+1],even[n+1];

    printf("Enter the Elements of Array : ");

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(i=0; i<n; i++)
    {
        if(a[i]%2==0)
        {
            even[j] = a[i];
            j++;
        }

        else
        {
            odd[k] = a[i];
            k++;
        }
    }

    printf("The even integers array is: ");

    for(i=0; i<j; i++)
        printf("%d ",even[i]);

    printf("\n");

    printf("The odd integers array is: ");

    for(i=0; i<k; i++)
        printf("%d ",odd[i]);

    printf("\n");

    return 0;
}
