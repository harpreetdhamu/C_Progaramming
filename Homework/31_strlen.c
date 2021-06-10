#include <stdio.h>
int count;
size_t my_strlen(const char *str)
{
	while (*str)
	{
		*str++;
		count++;
	}
	return count;
}

int main()
{
	char str[] = "Hello World";
int len = my_strlen(str);
	printf("%d",len);

	return 0;
}

