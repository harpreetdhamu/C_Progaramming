#include <stdio.h>

#include <stdio.h>
int *func(void)
{
	int a = 10;
//return &a;
}
int main()
{
	int *ptr;
	ptr = func();
	printf( "Hello World\n" );
	printf( " *ptr = %d\n" , *ptr);
}
