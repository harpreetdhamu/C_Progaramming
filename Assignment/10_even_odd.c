/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to check whether a given number is odd or even and its signedness
Date:07-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int num1, ch, mask=0x1, mask2=0x80000000, power;

int main()
{
	do
	{
		printf("Enter a number:\n");
		scanf("%d",&num1);
		/* these functions return the value of x=2 raised to the power of y=20*/
		power = pow(2,20);
		/*number is greater than 2 power of 20 then exit and shows the message */
		if (num1 > power)
		{
			printf("Oops!!!enter a valid number \n");
			exit(1);
		}

		if(!(num1 & mask2))
		{ 
			/* number is  bitwise and(&) with mask if number is equal zero then number positive else number is negative */
			if((num1 & mask)==0)
				printf("%d is Positive even number\n",num1);
			else
				printf("%d is Positive odd number\n",num1);
		}
		else 
		{
			if((num1 & mask)==0)
				printf("%d is Negative even number\n",num1);
			else
				printf("%d is Negative odd number\n",num1);
		}
		/*to shows the promt do you want to continue or not */
		printf("Do you want to continue(y/n)\n");
		scanf("%ls",&ch);
		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else if (ch == 'N' || ch == 'n')
		{
			exit(1);
		}
		else
		{
			printf("Wrong input\n");
			exit(1);
		}
	}while(1);
}
