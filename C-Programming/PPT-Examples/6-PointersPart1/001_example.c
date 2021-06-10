#include <stdio.h>

int main()
{
	int x;
	int *ptr;

	x = 5;
ptr =(int *)5;
printf("%ld\n",sizeof(ptr));
printf("%ld\n",sizeof(int *));

	return 0;
}
