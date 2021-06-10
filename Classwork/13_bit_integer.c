#include <stdio.h>

int main()
{
char count,Mask,Num;
printf("Enter a Number:\n");
scanf("%hhx",&Num);
//printf("Binary Number %x\n",Hex);
	for (count = 31; count >= 0; count--)
	{
	//	Num = Num << 1;
		if (Num & 0xde)
		printf("1");
	else
		printf("0");
}
	printf("\n");
}
