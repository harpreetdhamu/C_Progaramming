#include <stdio.h>

extern char num;

int func_1()
{
	printf("num is %d from file2\n", num);

	return 0;
}
