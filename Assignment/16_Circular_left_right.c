/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to  Read an int, & a no. n. Circular right & left shift the int by n
Date:07-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int num, position, ch, Option;
unsigned int iter, Right, mask = (1 << sizeof(num) * 8 -1);
unsigned int Left_Shift(unsigned int,int);
unsigned int Right_Shift(unsigned int,int);
int main()
{
	do
	{	
		printf("Enter a number:\n");
		scanf("%x",&num);
		printf("Enter a position:\n");
		scanf("%d",&position);

		/* Print the binary of Given number*/
		printf("Binary Of number Before Shifting\n");
		for(iter=mask;iter!=0;iter>>=1)
		{
		(num&iter)?printf("1"):printf("0");
		}
		printf("\n");

		printf("Enter a Option :\n1. RightShift\n2. LeftShift\n");
		scanf("%d",&Option);
		switch(Option)
		{
			case 1:
				/*Function call right shift*/
				Right_Shift(num,position);/*Actual Arguments*/
				break;
			case 2:
				/*Function call Left shift*/

				Left_Shift(num,position);/*Actual Arguments*/
				break;
			default:
				printf("Wrong Option\n");
				break;
		}

		printf("Do You Want to Continue(Y/N)\n");
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
			printf("Wrong Input\n");
			exit(1);
		}
	}while(1);
}

/*Function of Left shift*/
unsigned int Right_Shift(unsigned int num,int position) /*Formal Argument*/
{
	int chbit = 8;
	unsigned int iter, Right_Shift=0;
	/*Swaping the lsb bits and msb bits*/

	Right_Shift = (num >> position) | (num << (sizeof(num)*chbit - position));
	/* Print the binary of After Right Shifting number*/
	printf("Binary Of number After Right Shifting\n");
	for(iter=mask;iter!=0;iter>>=1)
	{
	(Right_Shift&iter)?printf("1"):printf("0");
	}
	printf("\n");
	return 0 ;
}
/*Function of Left shift*/
unsigned int Left_Shift(unsigned int num,int position)/*Actual Arguments*/
{
	int chbit = 8;
	unsigned int iter, Left_Shift=0;
	/*Swaping the lsb bits and msb bits*/

	Left_Shift = (num << position) | (num >> (sizeof(num)*chbit - position));
	/* Print the binary of After Left Shifting number*/
	printf("Binary Of number After Left Shifting\n");

	for(iter=mask;iter!=0;iter>>=1)
	{
		(Left_Shift&iter)?printf("1"):printf("0");
	}
	printf("\n");
	return 0;
}




