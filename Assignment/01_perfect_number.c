/*
Author Name      : Chanchal Parkash
Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title			 : Wap to check whether a given number is perfect or not 
Date			 :02_May_2019
 */


#include <stdio.h>
#include <stdlib.h>

int num, sum=0, rem, i;
char ch;
int main()
{
	do
	{
		sum = 0;
		printf("Enter a number:\n");
		scanf("%d",&num);
		/* if number is greater than 2^20 then exit */
		if (num >= 1048576)
		{
			printf("Error!!! number is out of range\n");
			exit(1);
		}
		else 
		{

			/* if number is negative than exit */
			if (num < 0)
			{
				printf("Error!!! please enter a valid number\n");
				exit(1);
			}
		}



		for(i=1;i<=(num-1);i++)
		{
			/*to check the reminder if reminder is 0 then i value is add with sum and store value in sum  */
			rem = num % i;
			if(rem == 0)
			{
				sum= sum + i;

			}
		}
		/*if sum of total number is equal to enter number then number perfect otherwise not perfect*/
		if(sum == num)
		{
			printf("The number %d is prefect number\n",num);
		}
		else
		{
			printf("The number %d is not a prefect number\n",num);
		}

		printf("Do you want to continue(y/n)\n");
		scanf("%s",&ch);
		if (ch =='Y' || ch == 'y')
		{
			continue;
		}
		else
		{
			if(ch == 'N' || ch == 'n')
			{
				exit(1);
			}
		}


	}while(1);

}
