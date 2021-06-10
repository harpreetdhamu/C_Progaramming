/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title: To implement strtok function 
Date:10-may-2019
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function Prototype*/
char* my_strtok(char *str,const char *delim);

int main()
{
	/*Local variables*/
	char str1[100], delim[100], *ptr, ch;
	do
	{

		printf("Enter the string 1 \n");
		fgets(str1,50,stdin);
		fflush(stdin);
		printf("Enter the string 2 delimeter \n");
		fgets(delim,50,stdin);
		fflush(stdin);
		/* pass the address if both strings to function my strtok*/
		ptr = my_strtok(str1,delim);
		while(ptr != NULL)
		{
			printf("%s",ptr);
			ptr = my_strtok(NULL,delim);
		}
		printf("\n");

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
			exit(2);
		}

	}while(1);
	return 0;

}

/*Function Should treat string2 as delimitter in string1 and should return 1 st field.If you call again my_strtok (NULL, string2), it should return second field in string1 treating string2 as delimitter.*/

char *my_strtok(char *str,const char *del)
{
	static char buff[33];
	static char *ptr;
	char *str2;
	int i=0,j;

	if(str == NULL)
		str = ptr;
	str2 = str;
	while(*str2)
	{
		buff[i] = *str2;
		for(j = 0; del[j]; j++)

			if(*str2 == del[j])
			{
				buff[i] = '\0';
				ptr = str2 + 1;
				return buff;
			}

		str2++;
		i++;

	}
	return NULL;
}
