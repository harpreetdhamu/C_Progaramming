/*	Author Name : Shritij Shere
 *	Organisation Name : EMERTXE
 *	Title : Program to remove extra blanks
 *	Date : 29/5/2019
 */

#include<stdio.h>
char rm_blanks(const char *str1,char *str2)
{
	while (*str1)
	{
		/* Copy the first space to string2 */
		if (*str1 == ' ')
		{
			*str2 = ' ';
			/* Do nothing for extra spaces */
			while(*++str1 == ' ');
			*str2++;
		}
		/* Copy elements from string1 to string2 */
		*str2 = *str1;
		*str1++;
		*str2++;
	}
	/* Add null to indicate end of the string */
	*str2 = '\0';
}

int main()
{
	char OPT = 'y';
	do{
		/* Declaring two strings */
		char str1[100],str2[100];

		printf("Enter a string ");
		getchar();
		scanf("%[^\n]",str1);

		/* Calling the function */
		rm_blanks(str1,str2);

		/* Printing the new string */
		printf("The new string is %s \n",str2);

		printf("Do you want to continue(y/n) : ");
		getchar();
		scanf("%c",&OPT);
	}while(OPT == 'y' || OPT == 'Y');
	return 0;
}
