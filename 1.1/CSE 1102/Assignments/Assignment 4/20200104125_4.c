/* Write a program which receives 5 integers and returns the sum , average and  standard deviation of these numbers. 
Call this function from main() and print  the results in main(). */

#include<stdio.h>
#include<math.h>

int sum(int,int,int,int,int);
float avg(int,int,int,int,int);
float stdDev(int,int,int,int,int);

int main()
{
    int a,b,c,d,e;

    printf("Enter five numbers: ");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    printf("Sum: %d\n", sum(a,b,c,d,e));
    printf("Average: %.2f\n", avg(a,b,c,d,e));
    printf("Standard Deviation: %f\n", stdDev(a,b,c,d,e));

    return 0;
}

int sum(int num1,int num2,int num3,int num4,int num5)
{
    return num1+num2+num3+num4+num5;
}

float avg(int num1,int num2,int num3,int num4,int num5)
{
    return sum(num1,num2,num3,num4,num5)/(float)5;
}

float stdDev(int num1,int num2,int num3,int num4,int num5)
{

    float variance=0, mean = avg(num1,num2,num3,num4,num5);

    variance=(num1-mean)*(num1-mean)+(num2-mean)*(num2-mean)+(num3-mean)*(num3-mean)+(num4-mean)*(num4-mean)+(num5-mean)*(num5-mean);

    return sqrt(variance/5);
}