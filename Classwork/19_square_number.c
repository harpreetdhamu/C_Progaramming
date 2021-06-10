#include<stdio.h>

int x,y,Result;
int	square(int);
int main()
{
	printf("Enter a Number\n");
	scanf("%d",&x);
	Result = square(x);
printf("Square is: %d\n ",Result);
//return y ;
}

int	square(int x)
{
int y=0;
y=x * x ;
return y;
}
