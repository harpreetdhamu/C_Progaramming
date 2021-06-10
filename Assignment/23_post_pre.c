/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP for pre and post increment and passing int pointer as their parameter
Date:27-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int num, ch, Option;
unsigned int iter, i, mask = 0x01; 
unsigned int in_post_pre(int*);
//unsigned int in_pre(int*);
int main()
{
	do
	{	
		printf("Enter a number:\n");
		scanf("%d",&num);

		printf("Enter a Option :\n1. Post increment\n2. Pre increment\n");
		scanf("%d",&Option);
		switch(Option)
		{
			case 1:
				/*Function call post increment*/
				i = num;
				in_post_pre(&num);/*Actual Arguments*/
				printf("i = %d and num = %d\n",i,num);
				break;
			case 2:
				/*Function call pre increment*/

				i = in_post_pre(&num);/*Actual Arguments*/
				printf("i = %d and num = %d\n",i,num);
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

/*Function of Post and pre increment*/
unsigned int in_post_pre(int *num) /*Formal Argument*/
{

	unsigned int mask = 0x01;
	while( *num & mask)
	{
		*num = *num ^ mask ;
		mask = mask << 1;
	}
	*num = *num | mask;
	return *num;
}
#if 0
/*Function of pre increment*/
unsigned int in_pre(int *num)/*Actual Arguments*/
{
	unsigned int mask = 0x01, flag;
	//	*num = -(~(*num));
	flag = *num & mask;
	if (flag != 0)
	{
		while( flag != 0)
		{
			*num = *num ^ mask ;
			mask = mask << 1;
			flag = *num & mask;
		}
		*num = *num | mask;
	}
	else
	{
		*num = *num ^ mask ;
	}
	return *num;
}

#endif 



