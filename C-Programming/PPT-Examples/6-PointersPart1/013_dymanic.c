#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	int *p,num,i;
	puts("Enter a Number n:");
	scanf("%d",&num);
	p =(int*) malloc(num * sizeof(int));
	if (p == NULL)
	{
		puts("Momory not available in heap");
		exit(0);
	}
//	for(i=0;i<num;i++)
//	{
		puts("Enter an integer:");
		scanf("%d",p+i);
//	}

	for(i=0;i<num;i++)
	{
		printf("%d\t",*p+i);
	}
}
