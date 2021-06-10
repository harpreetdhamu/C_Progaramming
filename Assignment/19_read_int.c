/*
   Author Name: Chanchal Parkash
   organization name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAF read_int to read an integer
Date:07-May-2019
 */
#include <stdio.h>
#include <stdlib.h>

int temp, num;
int read_int(int*);/*Function declaration for read_int*/
char ch;
int main() 
{
	do
	{
		printf("Please enter a number:\n");
		/*call the function read_int and pass the address of num*/
		temp = read_int(&num);
		printf("Your entered number is:\n");
		printf("%d\n",temp);
		printf("Do you want to continue (Y/N):\n");
		scanf("%s",&ch);
		getchar();
		if(ch == 'Y' || ch == 'y')
			continue;
		else if(ch == 'N' || ch == 'n')
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}

	}while(1);
	return 0;
}
/*Function for Read integer from user*/
int read_int(int *c)
{
	/*getchar return the character read as an unsigned char cast to an int and stored in int type pointer his ASCII value*/
	*c = getchar();
	int ret = 0;
	//	while (*c != '\n') 
	if(*c >='A' && *c <= 'z')
	{
		printf("Invalid input\n");
		exit(1);
	}
	while (*c >= '0' && *c <= '9') 
	{
		/*calculation for given number character by character.*/
		ret = 10 * ret + *c - '0';
		*c = getchar();
	}
	return ret;
}



