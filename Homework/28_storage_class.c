#include <stdio.h>
int foo();
int foo2();
int main()

{
	system("clear");
	int i;
	for(i =20;i<40;i++)
	{
		printf("%d,",foo());


	}
		printf("\n");
}

int foo()
{
//static int i;
//	int j=20
//static int i = ++j;
static int i = 0;
	i++;
	return (i);
}

int foo2()
{
//static int i;
	return 10;
}
