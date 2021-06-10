/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap a  to check whether a number is even or odd
Date:30-April-2019
 */


#include <stdio.h>

int num1, rem;
int main()
{
	printf("Enter a number:\n");
	scanf("%d",&num1);
	/* number1 modulus by 2 and its reminder is stored in rem variable*/	
	rem = num1 % 2;
	if (rem == 0 )
	{
		if (num1 > 0)
		{	
			printf("Number %d is positive even\n",num1);
		}
		else 
		{
			printf("Number %d is negative  even\n",num1);
		}
	}
	else

	{
		if (num1 < 0)
		{	
			printf("Number %d is negative odd\n",num1);
		}
		else 
		{
			printf("Number %d is positive odd\n",num1);
		}
	}
	}
