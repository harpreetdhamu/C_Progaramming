/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to print bits of float & double. check ieee std
Date:07-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int position, ch, option;
int iter, result;
float num;
double num1;
void float_num(int*);
void double_num(long*);
int main()
{
	do
	{	
		printf("Enter a option :\n1. Float\n2. Double\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter a number:\n");
				scanf("%f",&num);
				float_num((int*)&num);//actual arguments
				break;
			case 2:
				printf("Enter a number:\n");
				scanf("%lf",&num1);
				//function call double float
				double_num((long*)&num1);//actual arguments
				break;
			default:
				printf("Wrong option\n");
				break;
		}
		getchar();

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

//function of float num
void float_num(int* num) //formal argument
{
	int count = 0;
	unsigned int mask = (1<<(sizeof(int)*8)-1);
	printf("IEEE-32 float binary representation\n");
	printf("Sign\tExponent\t\tMantisa\n");
	/*	for(iter = mask;iter !=0;iter>>=1)
		{

		if (count == 1 || count == 9)
		printf("       ");
		(*num & iter)?printf("1"):printf("0");
		++count;
		}*/
	while(mask)
	{
		if (count == 1 || count == 9)
			printf("\t");
		((*num & mask) != 0)?printf("1"):printf("0");
		++count;
		mask >>= 1;
	}
	printf("\n");
}

//function of double flaot
void double_num(long* num)
{ 
	int count = 0;
	unsigned long mask = (1ull<<(sizeof(long)*8)-1);
	printf("IEEE-64 float binary representation\n");
	printf("Sign\t  Exponent\t\t\t\tMantisa\n");
	while(mask)
	{
		if (count == 1 || count == 12)
			printf("\t");
		((*num & mask) != 0)?printf("1"):printf("0");
		++count;
		mask >>= 1;
	}
	printf("\n");
}




