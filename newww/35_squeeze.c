/*	Author Name : Shritij Shere
 *	Organisation Name : EMERTXE
 *	Title : Program to sort implement squeeze function
 *	Date : 29/5/2019
 */


#include <stdio.h>
#include <string.h>
/* Function prototype for squeeze(); */
char squeeze(const char *s1,char *s2);
int main()
{
	char OPT = 'y';
	do{
		char s1[100],s2[100];
		/* Read two strings */
		printf("Enter the first string ");
		scanf("%[^\n]",s1);
		getchar();
		printf("Enter the second string ");
		scanf("%[^\n]",s2);

		/* Call the function */
		squeeze(s1,s2);

		printf("Do you want to continue(y/n): ");
		getchar();
		scanf("%c",&OPT);
		getchar();
	}while(OPT == 'y' || OPT == 'Y');
	return 0;
}

char squeeze(const char *s1,char *s2)
{
	/* Declare a string to store the resultant string */
	char s3[100];
	char *ptr = s3;
	char *ptr1 = s2;
	int match ;
	while(*s1)
	{
		match = 0;
		s2 = ptr1;
		while(*s2)
		{
			/* Set match = 1 if character in string1 matches to any character in string 2 */
			if(*s1 == *s2)
			{
				match = 1;
			}
			s2++;
		}
		if(!match)
		{
			/* If the match is not set then copy the character to string3 */
			*ptr = *s1;
			ptr++;
		}
		s1++;
	}
	*ptr = '\0';
	printf("After squeeze\n %s \n",s3);
}
