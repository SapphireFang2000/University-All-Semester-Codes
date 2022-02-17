#include<stdio.h>

int main()
{
    int h,ts;
    float cc;

    printf("Enter the Value of Hardness, Carbon Content and Tensile Strength : ");

    scanf("%d%f%d",&h,&cc,&ts);

    if(h>60 && cc<0.7 && ts>5000)
        printf("Grade is 10\n");

    else if(h>60 && cc<0.7 && ts<5000)
            printf("Grade is 9\n");

    else if(h<60 && cc<0.7 && ts>5000)
            printf("Grade is 8\n");

    else if(h>60 && cc>0.7 && ts>5000)
            printf("Grade is 7\n");

    else if(h>60 || cc<0.7 || ts>5000)
            printf("Grade is 6\n");

    else
        printf("Grade is 5\n");

    return 0;
}
