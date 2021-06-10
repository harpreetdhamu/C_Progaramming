/*WAP Program To to Grade for given Percentage*/

#include<stdio.h>

float num;
void main()
{

 printf("Enter a Percentage:");
 scanf("%f", &num);
if (num >100)
	{
 	printf("Error!!!:Your Percentage %.2f is Wrong Please Enter Right Percentage\n",num);
	}
 else if (num >= 90 )
 	{
 	printf("Your Percentage %.2f and Grade is A++\n",num);
 	}
 else if (num >= 80 )
 	{
 	printf("Your Percentage %.2f and Grade is A\n",num);
 	}
 else if (num >= 70 )
 	{
 	printf("Your Percentage %.2f and Grade is B+\n",num);
 	}
 else if (num >= 60 )
 	{
 	printf("Your Percentage %.2f and Grade is B\n",num);
 	}
 else if (num >= 50 )
 	{
 	printf("Your Percentage %.2f and Grade is C+\n",num);
 	}
 else if (num >= 40 )
 	{
 	printf("Your Percentage %.2f and Grade is C\n",num);
 	}
 else if (num <= 40)
	{
 	printf("Your Percentage %.2f and Grade is F\n",num);
 	}
 else 
 	{
	printf("This is not your Result\n");
	}
}
