#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "";
	int ret;

	ret = strlen(str);
	printf("%d\n", ret);
		printf("%zu,",sizeof(str));
		

	return 0;
}
