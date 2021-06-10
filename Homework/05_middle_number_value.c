/*WAP to find the middle number (by value) of given 3
numbers*/

#include<stdio.h>
int num1, num2,num3;
int main()
{
 printf("Enter a Value of num1,num2,num3:\n");
 scanf("%d %d %d", &num1, &num2, &num3);

 if (num1 > num2)
 	{
	if(num2 > num3)	
		{
 		printf("Number %d is Middle\n",num2);
 		}
	else if (num3 > num1)
		{
 		printf("Number %d is Middle\n",num1);
 		}
	else
		{
 		printf("Number %d is Middle\n",num3);
		}	
	}
 else
 	{
	if(num2 < num3)	
		{
 		printf("Number %d is Middle\n",num2);
 		}
	else if (num3 < num1)
		{
 		printf("Number %d is Middle\n",num1);
 		}
	else
		{
 		printf("Number %d is Middle\n",num3);
		}	
	}
}

