/*WAP to find the greatest of given 3 numbers*/

#include<stdio.h>

int num1, num2,num3;
int main()
{
 printf("Enter a Value of num1,num2,num3:\n");
 scanf("%d %d %d", &num1, &num2, &num3);

 if (num1 > num2)
 	{
	if(num1 > num3)	
		{
 		printf("Number %d is Greater\n",num1);
 		}
	else
		{
 		printf("Number %d is Greater\n",num3);
 		}
	}
 else if (num2 > num3)
	{
 	printf("Number %d is Greater\n",num2);
 	}
 else
 	{
 	printf("Number %d is Greater\n",num3);
 	}
}

