/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap to implement your own c-type library (any four)
1 - isalpha == checks for an alphanumeric character
2 - isalnum == checks for an alphabetic character; in the standard "c" locale, it is equivalent to (isupper(c) || islower(c))
3 - isascii == checks whether c is a 7-bit unsigned char value that fits into the ascii character set
4 - isblank == checks for a blank character; that is, a space or a tab
date:14-may-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int result, cha, option;
char ch;
/*function declaration*/
int isalpha(int);
int is_alnum(char); 
char is_ascii(char);
int isblank(int);
int main()
{
	do
	{
		printf("select functions from below list\n");
		printf("1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isblank\n");
		printf("Enter a option\n");
		scanf("%d",&option);
		getchar();
		switch (option)
		{
			case 1:
				printf("Enter a character\n");
				scanf("%c",&ch);
				result = isalpha(ch);/*call function alpha and pass character value*/
				(result == 0)?printf("Character is alpha\n"):printf("Character is not alpha\n");
				printf("\n");
				break;
			case 2:
				printf("Enter a character\n");
				scanf("%c",&ch);
				result=is_alnum(ch);/*call function alpha_numeric and pass character value*/
 
				(result == 0)?printf("Character is alpha_numeric\n"):printf("Character is not alpha_numeric\n");
				break;
			case 3:
				printf("Enter a character\n");
				scanf("%c",&ch);
				getchar();
				result=is_ascii(ch); /*call function ascii and pass character value*/

				(result == 0)?printf("Character is ascii\n"):printf("Character is not ascii\n");
				break;
			case 4:
				printf("Enter a character\n");
				scanf("%c",&ch);
				getchar();
				result=isblank(ch);/*call function blank and pass character value*/
 
				(result == 0)?printf("Character is blank\n"):printf("Character is not blank\n");
				break;
			default:
				printf("Please enter a number 1-4\n");
				//break;
		}


		printf("Do you want to continue(y/n)\n");
		scanf("%ls",&cha);

		if (cha == 'Y' || cha == 'y')
			continue;
		else if (cha == 'N' || cha == 'n')
			exit(1);
		else
		{
			printf("Wrong input\n");
			exit(1);
		}
	}while(1);
}
/*function for checks for an alphabetic character*/
int isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z'))
		return 0;
	else
		return 1;
}
/*function for checks for an alpha_numeric character*/
int is_alnum(char ch)
{
	if ((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z')||(ch >= '0' && ch <= '9'))
		return 0;
	else
		return 1;
}
/*function for checks for an ascii caracter*/
char is_ascii(char ch)
{
	if (ch >=0  && ch <= 127)
		return 0;
	else
		return 1;
}
/*function for checks for blank character*/
int isblank(int ch)
{
	if ((ch == 32)||(ch == 9))
		return 0;
	else
		return 1;
}
