/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap a to check given three numbers which number is smallest 
Date:30-April-2019
 */


#include <stdio.h>

int num1, num2, num3;
int main()
{
	printf("Enter a three number:\n");
	scanf("%d %d %d",&num1,&num2,&num3);
	/* number 1 is less than number 2 then print num1*/	

	if (num1 < num2 )
	{
		printf("Number %d is smallest\n",num1);
	}
	/* number 2 is less than number 3 then print num2*/	
	else if ( num2 < num3)
	{
		printf("Number %d is smallest\n",num2);
	}
	/* number 3 is less than number 1 then print num3*/	
	else if (num3 < num1)
	{
		printf("Number %d is smallest\n",num3);
	}
	else
	{
		printf("Error!!");
	}
}
