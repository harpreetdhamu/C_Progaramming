/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
   Title:Wap to print “hello” in x format.
   Date:02-May-2019
 */


#include <stdio.h>
#include <stdlib.h>

int i ,j , num1;
int main()
{
	printf("Enter a number:\n");
	scanf("%d",&num1);
	/* number is less than 3 and greater than 32 then shows the message.*/	
	if(num1 < 3 || num1 > 32)
	{
		printf("Error!!! please enter a valid input between 3-32\n");
		exit(1);
	}
	for(i=1;i<=num1;i++)
	{
		/*number is even then enter inside if and execute this loop */
		if(num1 % 2 == 0)
		{
			for(j = 1; j <= num1; j++)
			{
				/*this logic print the "hello" in x format */
				(j == i || j == num1 + 1 - i)?printf("hello"):printf(" ");
			}
			printf("\n");
		}
		else

		/*number is odd then execute this loop */
		{
			for(j = 1; j <= num1; j++)
			{
				/*this logic print the "hello" in x format */
				if (j == i || j == num1 + 1 - i)
				{
					printf("hello");
					/*if coloumm j is eqaul to middle of row i then print the hello */
					j == ((num1 + 1) / 2)?printf("hello"):printf(" ");

				}
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
