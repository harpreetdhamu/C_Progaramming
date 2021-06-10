/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to Implement your own c-type library (any four)
1 - isalpha == checks for an alphanumeric character
2 - isalnum == checks for an alphabetic character; in the standard "C" locale, it is equivalent to (isupper(c) || islower(c))
3 - isascii == checks whether c is a 7-bit unsigned char value that fits into the ASCII character set
4 - isblank == checks for a blank character; that is, a space or a tab
Date:14-May-2019
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int Result,Char,Option;
char Ch;
/*Function declaration*/
int isalpha(int);
int isalnum(int); 
char is_ascii(char);
int isblank(int);
int main()
{
	do
	{
		printf("Select Functions from below list\n");
		printf("1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isblank\n");
		printf("Enter a Option\n");
		scanf("%d",&Option);
		getchar();
		switch (Option)
		{
			case 1:
				printf("Enter a Character\n");
				scanf("%c",&Ch);
				Result = isalpha(Ch);/*Call Function alpha and pass Character Value*/
				(Result == 0)?printf("Character is Alpha\n"):printf("Character is not Alpha\n");
				printf("\n");
				break;
			case 2:
				printf("Enter a Character\n");
				scanf("%c",&Ch);
				Result=isalnum(Ch);/*Call Function alpha_Numeric and pass Character Value*/
 
				(Result == 0)?printf("Character is Alpha_Numeric\n"):printf("Character is not Alpha_Numeric\n");
				break;
			case 3:
				printf("Enter a Character\n");
				scanf("%c",&Ch);
				getchar();
				Result=is_ascii(Ch); /*Call Function Ascii and pass Character Value*/

				(Result == 0)?printf("Character is Ascii\n"):printf("Character is not Ascii\n");
				break;
			case 4:
				printf("Enter a Character\n");
				scanf("%c",&Ch);
				getchar();
				Result=isblank(Ch);/*Call Function Blank and pass Character Value*/
 
				(Result == 0)?printf("Character is blank\n"):printf("Character is not blank\n");
				break;
			default:
				printf("Please Enter a Number 1-4\n");
				//break;
		}


		printf("Do You Want to Continue(Y/N)\n");
		scanf("%ls",&Char);

		if (Char == 'Y' || Char == 'y')
			continue;
		else if (Char == 'N' || Char == 'n')
			exit(1);
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}
	}while(1);
}
/*Function for checks for an alphabetic character*/
int isalpha(int Ch)
{
	if ((Ch >= 'a' && Ch <= 'z')||(Ch >= 'A' && Ch <= 'Z'))
		return 0;
	else
		return 1;
}
/*Function for checks for an alpha_Numeric character*/
int isalnum(int Ch)
{
	if ((Ch >= 'a' && Ch <= 'z')||(Ch >= 'A' && Ch <= 'Z')||(Ch >= '0' && Ch <= '9'))
		return 0;
	else
		return 1;
}
/*Function for checks for an Ascii Caracter*/
char is_ascii(char Ch)
{
	if (Ch >= 33 && Ch <= 127)
		return 0;
	else
		return 1;
}
/*Function for checks for Blank character*/
int isblank(int Ch)
{
	if ((Ch == 32)||(Ch == 9))
		return 0;
	else
		return 1;
}
