/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies pvt.ltd. Banglore
Title:Wap WAP to generate fibbonacci numbers <= 'n' using recursions 
Date:23-May-2019
 */


#include <stdio.h>
#include <stdlib.h>
int fib(int,int,int);

int limit, num1 = 1, num2 = 0, i, sum = 0, diff = 0;
int main()
{
	printf("Enter a number:\n");
	scanf("%d",&limit);
	fib(num1,num2,limit);
	printf("\n");
}

int fib(int num1,int num2,int limit)
{
	if (num1 <= limit)
	{
		sum = num1 + num2;
		printf("%d",num1);

		return(fib(num2,sum,num1 + num2));

	}
	else
		printf("\n");
return 1;
}
