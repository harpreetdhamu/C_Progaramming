#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char concat(char *dest,int count, ...);
int main()
{
	int ret;
	static char dest[50];
	concat(dest,4,"hello","how","are","you");
	printf("%s \n", dest);
	return 0;
}

char concat(char *dest,int count,...)
{
	va_list ap;
	int iter;
	char *s;
	va_start(ap, count);

	for (iter = 0; iter < count; iter++)
	{
		s = va_arg(ap, char *);
		strcat(dest,s);
	}
	va_end(ap);
	return *dest;
}
