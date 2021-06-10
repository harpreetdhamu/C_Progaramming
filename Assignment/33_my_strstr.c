/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP To implement own strstr() function
Date:18-june-2019
 */


#include <stdio.h>
#include <stdlib.h>

/*Function Prototype*/
char *my_strstr(char *str, char *substr);

int main()
{
	/*Local variable*/
	char ch,str1[50],str2[50];
	do
	{
		puts("Enter a string1");
		scanf("%[a-z A-Z]",str1);
		getchar();
		printf("\n");
		puts("Enter a sub string2");
		scanf("%[a-z A-Z]",str2);
		getchar();
		printf("\n");
		/*pass the address of string 1 and string 2 to my_strstr function and return string is printing*/
		printf("Returned String 1: %s\n", my_strstr(str1,str2));

		printf("Do You Want to Continue(Y/N)\n");
		scanf("%s",&ch);
		getchar();
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

/*This function takes two strings s1 and s2 as an argument and finds the first occurrence of the sub-string s2 in the string s1. */
char *my_strstr( char *str, char *substr)
{

	while(*str)
	{
		char *start = str;
		char *s2 = substr;
		/* If first character of sub string match, check for whole string*/
		while(*str && *s2 && *str == *s2)
		{
			*str++;
			*s2++;
		}
		/* If complete sub string match, return starting address*/
		if(!*s2)
			return start;
		/*Increament main string */
		str = start + 1;
	}
	return NULL;
}




