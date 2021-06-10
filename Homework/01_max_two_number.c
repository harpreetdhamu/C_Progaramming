/*WAP a Program To Find maximun of two Number*/

#include<stdio.h>

int num1, num2;
int main()
{
 printf("Enter a Two Number:");
 scanf("%d %d", &num1, &num2);

 if (num1 > num2)
 	{
 	printf("The Number is Greater\n");
 	}
 else if (num1 < num2)
 	{
	printf("The Number is Smallest\n");
 	}
 else
	{
 	printf("Both Number a Equal\n");
 	}
}
