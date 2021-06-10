#include<stdio.h>
int main()
{
int y=30;
int x=25;
//const int *p = &x;
int *const p = &x;
//	*p = 50;
	printf("%d",x);
	p =&y;

	printf("%d",y);
}
