#include<stdio.h>
#include<string.h>

/*Function prototype */
char *my_strstr(char *haystack,char *needle);

int main()
{
	/* Declare two arrays */
	char s1[100]; 
	char s2[20]; 

	/* Read the first string */
	printf("Enter a string ");
	scanf("%[^\n]",s1);

	getchar();
	
	/*Read the second string */
	printf("Enter a substring");
	scanf("%[^\n]",s2);
	
	/* Call the function */
	char *p = my_strstr(s1,s2);
	
	/* Print the string */
	printf("The string is%s\n", p);
}

char *my_strstr(char *s1,char *s2)
{
	/* P is pointing to string2 */
	char *p = s2;
	/* Calculate the length of string2 */
	int len = strlen(s2);
	int match = 0;

	while(*s1)
	{
		while(*s1 != 32)
		{
			while(*s2)
			{
				printf("*s1 = %c\n*s2 = %c\n",*s1,*s2);
				/* Check if the word in string2 is equal to string2  */
				if(*s1 == *s2)
				{
					match = 1;
					s1++;
					s2++;
					continue;
				}
				else
				{
					/* If the character in string1 is not equal to character in string2  , do nothing till the next word */ 
					match = 0;
					while(*s1 != 32)
						s1++;
					s1++;
					s2 = p;
				}
			}
			/* If match is 1 return address to previous word */
			if(match == 1)
				return (s1 - (len + 1));
		}
	}
}
