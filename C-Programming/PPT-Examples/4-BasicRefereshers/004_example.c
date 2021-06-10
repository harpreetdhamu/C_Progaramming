#include <stdio.h>

int main()
{
	short int count1;
	int long count2;
	short count3;

	printf("short is %zu bytes\n", sizeof(short int));
	printf("long int is %zu bytes\n", sizeof(int long));
	printf("short is %zu bytes\n", sizeof(short));

	return 0;
}

