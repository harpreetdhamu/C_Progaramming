#include <stdio.h>

int x = 10;
int x;

int foo()
{
	printf("x %d\n", x);

	return 0;
}

int main()
{
	foo();

	return 0;
}
