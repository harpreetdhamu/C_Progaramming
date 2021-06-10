#include <stdio.h>

int main()
{
	int x;
	int *ptr;

	x = 5;
	ptr = &x;

	printf("%ls\n",ptr);
	
	return 0;
}
