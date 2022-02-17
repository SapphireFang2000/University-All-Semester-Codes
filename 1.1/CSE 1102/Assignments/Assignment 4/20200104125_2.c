/* A prime integer is entered through the keyboard. Write a function to obtain  the prime factors of this number. 
For example, prime factors of 24 are 2, 2,  2 and 3 whereas prime factors of 35 are 5 and 7. */

#include<stdio.h>

int primefactor(int x);

int main()
{
	int n;

	printf("Enter a Positive Number: ");
	scanf("%d",&n);

	primefactor(n);

	return 0;
}

int primefactor(int x)
{
	int i;

	for(i=2;x>1;i++)
	{
		while(x%i==0)
		{
			printf("%d ",i);
			x=x/i;
		}
	}
}