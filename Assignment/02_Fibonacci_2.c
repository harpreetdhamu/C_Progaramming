/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies pvt.ltd. Banglore
Title:Wap to generate fibbonacci numbers <= 'n' 
Date:02-May-2019
 */


#include <stdio.h>
#include <stdlib.h>

int limit, num1 = 1, num2 = 0, i, sum = 0, diff = 0;
int main()
{
	printf("Enter a number:\n");
	scanf("%d",&limit);


	/*if limit is positive number the enter the inside the if */	
	if (limit >= 0)
	{
		printf("Positive fibbonaci numbers :\n");
		for(i=0; i <= limit; i++)
		{
			/*limit is less than total sum of two values then print the total sum and swap the num1 and num2 data */
			if(sum <= limit )
			{
				printf("%d,",sum);
				/*to add two numbers  */
				sum = num1 + num2;
				num1 = num2;
				num2 = sum;
			}
		}
		printf("\n");
	}
	/*if limit is negative number the enter the inside the if */	
	else if (limit <= 0)
	{
		printf("Negative fibbonaci numbers :\n");
		for(i = limit; i <= 0; i++)
		{
			/*limit is greater than total difference of two values then print the total difference and swap the num1 and num2 data */
			/*absulate function is used for return the absulate value of integer */
			if(abs(limit) >= abs(diff))
			{
				printf("%d,",diff);
				/*to subtraction of  two numbers  */
				diff = num1 - num2;
				num1 = num2;
				num2 = diff;
			}
		}
		printf("\n");
	}
}
