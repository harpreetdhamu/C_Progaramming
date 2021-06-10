/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies pvt.ltd. Banglore
Title: WAP to find factorial for given number using recursive method and without using any other function than main function 
Date:23-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int limit,i,sum = 0;
char sign, ch;
int fact(int);
int main()
{
	do
	{
	printf("Enter a number:\n");
	scanf("%d",&limit);
	sum = fact(limit);
	printf("%d\n",sum);

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

		}while(ch == 'y');
}
int fact(int n)
{
	if (n <= 1)
		return 1;
	else
		return (n * fact(n -1));
}
