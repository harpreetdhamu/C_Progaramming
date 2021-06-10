#include<stdio.h>
int main()
	{
	int num,mask;
mask=0x1;
printf("Enter a number:\n");
scanf("%d",&num);
if((num & mask)==0)
	printf("even number\n");
else

	printf("odd number\n");
	
	}
