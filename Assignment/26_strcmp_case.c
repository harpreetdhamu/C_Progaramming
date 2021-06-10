/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP To implement strcmp, strcasecmp function
Date:30-May-2019
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int num,Option,result;
char ch,str1[50],str2[50];
int my_strcmp(const char *s1, const char *s2);
int my_strncasecmp(const char *s1, const char *s2);
int main()
{
	do
	{
		//puts("Enter a string1 and string2");
		//scanf("%s\n%s",str1,str2);
		puts("Enter a string1");
		fgets(str1,50,stdin);
		fflush(stdin);
		puts("Enter a string2");
		fgets(str2,50,stdin);
		fflush(stdin);
		printf("Enter a Option :\n1. String compare\n2. String case compare\n");
		scanf("%d",&Option);
		getchar();
		switch(Option)
		{
			case 1:
				/*Function call string compare*/
				result = my_strcmp(str1,str2);
				!(result)?puts("String is same"):puts("string are not same");
				break;
			case 2:
				/*Function call string n case compare */

				result = my_strncasecmp(str1,str2);
				!(result)?puts("String is same"):puts("string are not same");
				break;
			default:
				printf("Wrong Option\n");
				break;
		}
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

/*Function of string compare*/
int my_strcmp(const char *s1, const char *s2)/*Formal Argument*/
{
	while(*s1 && *s2 && *s1 == *s2)
	{
		*s1++;
		*s2++;
	}
	return (*s1 - *s2);
}
/*Function of string case compare*/
int my_strncasecmp(const char *s1, const char *s2)/*Actual Arguments*/
{
	while(toupper(*s1) && toupper(*s2) && toupper(*s1) == toupper(*s2))
	{
		*s1++;
		*s2++;
	}
	return (toupper(*s1) - toupper(*s2));
}




