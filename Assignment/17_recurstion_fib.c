/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies pvt.ltd. Banglore
Title:Wap WAP to generate fibbonacci numbers <= 'n' using recursions 
Date:23-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int limit,i,sum = 0;
char sign, ch;
/*Function Declaration*/
int fib(int,char);
int main()
{
	do
	{
		i= 0,sum = 0;
		printf("Enter a number:\n");
		scanf("%d",&limit);

		/*check the limit is positive or negative*/
		sign=(limit >= 0)?'+':'-';

		while (abs(sum) <= abs(limit))
		{
			printf("%d,",sum);
			sum = fib(i,sign);
			i++;
		}
		printf("\n");
		printf("Do you want to continue (y/n):\n");
		scanf("%s",&ch);
		if (ch == 'Y' || ch == 'y')
			continue;
		else if (ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong input\n");
			exit(2);
		}
	}while(1);
}
/*function for recursive fibonacci positive or negative*/
int fib(int n,char sign)
{

	if (n == 0)
		return 0;
	else if(n == 1) 
		return 1;
	else
	{
		if (sign == '+')
			return (fib(n - 1,sign) + fib(n - 2,sign));
		else
			return fib(abs(n - 2),sign) - fib(abs(n - 1),sign);
	}
}
