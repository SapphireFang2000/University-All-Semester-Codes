/* Write two different functions to calculate the GCD and LCM of two numbers. 
Call these functions from main() and print the results in main().*/ 

#include<stdio.h>

int gcdvalue(int,int);
int lcmvalue(int,int);

int main()
{
	int rem,gcd,lcm,n1,n2;

	printf("Enter Two Number: ");
	scanf("%d%d",&n1,&n2);

	printf("GCD = %d\n",gcdvalue(n1,n2));
	printf("LCM = %d\n",lcmvalue(n1,n2));

	return 0;
}

int gcdvalue(int num1, int num2)
{
	int n1,n2,gcd,rem;

	n1=num1;
	n2=num2;

	while(n2!=0)
	{
		rem=n1%n2;
		n1=n2;
		n2=rem;
	}
	return n1;
}

int lcmvalue(int num1, int num2)
{
	int gcd = gcdvalue(num1,num2);
	return (num1*num2)/gcd;
}