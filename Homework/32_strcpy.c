#include <stdio.h>
//int count;
char *my_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		*src++;
		*dest++;
	}
	*dest = '\0';
	return dest;
}

int main()
{
	char str[100],str1[100];
	puts("Enter a string before printing:");
	fgets(str,100,stdin);
	//puts();
	my_strcpy(str1,str);
	puts("Enter a string after printing:");
	puts(str1);
//	printf("%s",str1);

	return 0;
}

