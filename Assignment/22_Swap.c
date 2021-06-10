/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to swap two variables by using pass by reference method. 
Date:07-May-2019
 */

#include <stdio.h>
#include <stdlib.h>

int num, num1, ch;
void swap(int *num,int *num1 );/*function declaration*/
int main()
{
	do
	{
		printf("Enter a number before swapping:\n ");
		scanf("%d %d",&num,&num1);

		swap(&num, &num1);/*function call*/

		printf("Enter a number after swapping:\n ");
		printf("%d,%d\n",num,num1);

		printf("Do you want a continue (y/n):\n");
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
/*function for swapping two numbers*/
void swap(int *num, int *num1)
{
	int temp = 0;
	temp = *num;
	*num = *num1;
	*num1 = temp;
}
