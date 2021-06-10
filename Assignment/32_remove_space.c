/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Replace each string of one or more blanks by a single blank 
Date:10-may-2019
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size, i , j,length;
char str1[50];

char blanks(const char *str1,char *str2);/*function Prototype */
int main()
{
	printf("Enter the string with more spaces in between two words\n\n");
	fgets(str1,50,stdin);
	fflush(stdin);
	/* alloacate dynamic memory for string 2*/
	char *str2 = (char*)malloc(50);
	/* pass the address of str1 and str2*/
	blanks(str1,str2);

	printf("String with reduced space\n");
	printf("%s\n",str2);
	free(str2);
	str2 ='\0';
}
/* function for removing the blank space in string*/
char blanks(const char *str1, char *str2)
{
	while(*str1 != '\0')
	{
		if(*str1 == ' ')
		{
			*str2 = ' ';
			while(*++str1 == ' ');
			*str2++;
		}
		*str2 = *str1;
		*str1++;
		*str2++;
	}
}


