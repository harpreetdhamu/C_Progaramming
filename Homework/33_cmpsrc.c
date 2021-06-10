#include <stdio.h>
//int count;
int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 )
	{
			*s1++;
     		*s2++;
	}
	
	return (*s1 - *s2);
}

int main()
{
	int result = 0;
	char str[100],str1[100];
	puts("Enter a string 1 :");
	fgets(str,100,stdin);
	puts("Enter a string 2 :");
	fgets(str1,100,stdin);
	result = my_strcmp(str,str1);
	!(result )?puts("string is same"):puts("string is not same");
	return 0;
}

