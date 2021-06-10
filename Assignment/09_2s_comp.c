/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to print bits of signed and unsigned types for given number and check for 2’s complement
Date:07-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int num1, ch, mask = (1 << sizeof(num1) * 8 -1), power, comp=0;
unsigned int iter, shift;
int main()
{
	do
	{	
		printf("Enter a number:\n");
		scanf("%d",&num1);
		/*number is greter than 2^20 then exit the program*/
		power = pow(2,20);
		if (num1 > power)
		{
			printf("Oops!!!enter a valid number \n");
			exit(1);
		}
		printf("Binary number is: %d\n",num1);
		for(iter=mask;iter!=0;iter>>=1)
		{
			(num1 & iter)?printf("1"):printf("0");
		}
		printf("\n");
		/*compliment of given number*/
		comp=(~ num1) + 1;
		printf("2's Compliment number is: %d\n",num1);
		for(iter=mask;iter!=0;iter>>=1)
		{
			(comp & iter)?printf("1"):printf("0");
		}
		printf("\n");

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
