#include <stdio.h>

int *foo()
{
	static int i = 10;
	int *j = &i;

	return j;
}

int main()
{
	int *i;

	i = foo();
	printf("Hello\n");
	printf("*i %d\n", *i);

	return 0;
}
