/* Write a function which receives a float and an int from main(), 
finds the  product of these two and returns the product which is printed in the  main(). */

#include <stdio.h>

float product(float,int);

int main()
{
	float n1;
	int n2;

	printf("Enter a float value and a integer value: ");
	scanf("%f%d",&n1,&n2);

	float product_result = product(n1,n2);

	printf("Product = %.2f\n",product_result);
}

float product(float n1,int n2)
{
	return n1*n2;
}
