#include <stdio.h>

int main()
{
	int num = 5;

	printf("%zu %zu %zu\n", sizeof(int), sizeof(2*6), sizeof 5);

	//printf("%zu %zu %zu\n", sizeof(int), sizeof num, sizeof 5);
	return 0;
}
