#include<stdio.h>
void addition();
void substraction();
void multi();
void div();
void main()
{
    int ch;
    printf("Enter choice : \n1 for addition \n2 for substraction \n3 for multi \n4 for div \n");
    scanf("%d",&ch);
    if( ch == 1)
        addition();
    else if (ch == 2)
    substraction();
    else if (ch == 3)
        multi();
    else if (ch == 4)
        div ();
    else
        printf("Invalid input");


}
void addition ()
{
    int a,b;
    printf("Enter a & b: ");
    scanf(" %d %d",&a ,&b);
    printf("res = %d\n",(a+b));
}
void substraction ()
{
    int a,b;
    printf("Enter a & b: ");
    scanf(" %d %d",&a ,&b);
    printf("res = %d\n",(a-b));
}
void multi ()
{
    int a,b;
    printf("Enter a & b: ");
    scanf(" %d %d",&a ,&b);
    printf("res = %d\n",(a*b));
}
void div ()
{
    float a,b;
    printf("Enter a & b: ");
    scanf(" %f %f",&a ,&b);
    printf("res = %.2f\n",(a/b));
}
