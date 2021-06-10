#include <stdio.h>
#include <ctype.h>
int my_strncasecmp(const char *s1, const char *s2)
{
	while (*s1 &&  *s2 && toupper(*s1) == toupper(*s2))
	{
		*s1++;
		*s2++;
	}

	return (toupper(*s1) -toupper(*s2));
}

int main()
{
	int result = 0;
	char str1[100],str2[100];
	puts("Enter a string 1 :");
	fgets(str1,100,stdin);
	puts("Enter a string 2 :");
	fgets(str2,100,stdin);
	result = my_strncasecmp(str1,str2);
	!(result)?puts("String is same"):puts("String is not same");
	return 0;
}

