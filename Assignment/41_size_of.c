/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:To define a macro SIZEOF(x), where x is a variable, without using sizeof operator
stdin buffer
Date:16-June-2019
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZEOF(a) (char*)(&a + 1) - (char*)(&a)
int x,option;
char ch;
float y;
double z;
unsigned int a;
long int b;
long double c;
int main()
{
	do
	{
		printf("Select a type you find a size:\n1.int\n2.char\n3.float\n4.double\n5.unsigned int\n6.long int\n7.long double\nselect a option:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("size of int = %zu\n",SIZEOF(x));
				break;
			case 2:
				printf("size of char = %zu\n",SIZEOF(ch));
				break;
			case 3:
				printf("size of float = %zu\n",SIZEOF(y));
				break;
			case 4:
				printf("size of double = %zu\n",SIZEOF(z));
				break;
			case 5:
				printf("size of unsigned int = %zu\n",SIZEOF(a));
				break;
			case 6:
				printf("size of long int = %zu\n",SIZEOF(b));
				break;
			case 7:
				printf("size of long double = %zu\n",SIZEOF(c));
				break;
			default:
				printf("Wrong option\n");
				break;
		}
		printf("Do you want to continue (y/n):\n");
		scanf("%s",&ch);
		if (ch == 'Y' || ch == 'y')
			continue;
		else if (ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong input\n");
			exit(2);
		}
	}while(1);
}



