#include<stdio.h>
#include<stdlib.h>
void main ()
{
    int a[10],i,value;

    printf("Enter the Elements of Array : ");

    for(i=0; i<5; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("enter value which will be deleted : ");
    scanf("%d",&value);

    for(i=0; i<5; i++)
    {
        if(a[i]==value)
        {
            for(; i<4; i++)
                a[i]=a[i+1];

            for (i=0; i<4; i++)
                printf("%d\t",a[i]);
        }

    }

}
