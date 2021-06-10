/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies pvt.ltd. Banglore
Title: WAP to find factorial for given number using recursive method and without using any other function than main function 
Date:23-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned int i,sum = 1;
int n;
char ch;

int main()
{
	do
	{
		if(!i++)
		{
			printf("Enter a number:\n");
			scanf("%d",&n);
			if(n < 0 || n > 16)
			{
			printf("Oops!!! Invalid option enter number between 1-16\n");
				exit(1);	
			}
		}

		if (n < 1)
		{
			i=0;
			return 1;
		}
		/*Factorial of a non-negative integer, is multiplication of all integers smaller than or equal to n.*/
		sum = sum * n--;
		/*call the function main*/
		main();
		if (!i++)
		{
			printf("%d\n",sum);
		}
		i=0;
		sum =1;
		printf("Do you want to continue(y/n)\n");
		scanf("%s",&ch);

		if (ch == 'Y' || ch == 'y')
			continue;
		else if (ch == 'N' || ch == 'n')
			exit(2);
		else
		{
			printf("Wrong input\n");
			exit(3);
		}
	}while(1);
}
