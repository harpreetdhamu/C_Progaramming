#include <stdio.h>

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	int *ptr = array;

	printf("%d\n", *ptr);

	return 0;
}
