#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int *ptr[3];

	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;
printf("%p,%p,%p\n",ptr[0],ptr[1],ptr[2]);
printf("%d,%d,%d\n",*ptr[0],*ptr[1],*ptr[2]);
printf("%d,%d\n",**ptr,ptr[0][0]);
printf("%d,%d,%d\n",(*(*ptr+0)+0),(*(*ptr+1)+0),(*(*ptr+2)+0));
	return 0;
}
