#include<stdio.h>
int main()
{
    int a,b,c;

    printf("Enter Three angle values of the triangle: \n");
    scanf("%d%d%d",&a,&b,&c);

    if(a==b && b==c && a==c)
        printf("The Triangle is Equilateral.\n");

    else if(a==b || a==c || b==c)
        printf("The Triangle is Isosceles.\n");

    else if(a!=b && a!=c && b!=c)
        printf("The Triangle is Scalene.\n");

    return 0;
}
