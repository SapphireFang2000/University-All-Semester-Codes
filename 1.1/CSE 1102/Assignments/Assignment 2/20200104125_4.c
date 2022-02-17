//2*7*12*.....*37.
#include<stdio.h>
int main()
{
    int i,multi=1;

    printf("2*7*12*.....*37.\n");

    for(i=2;i<=37;i+=5)
        multi = multi*i;

    printf("Result= %d.\n",multi);

    return 0;
}