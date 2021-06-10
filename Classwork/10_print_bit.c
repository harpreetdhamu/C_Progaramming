#include <stdio.h>

int main()
{
char count,shift,Hex;
printf("Enter a Hex Number:\n");
scanf("%hhx",&Hex);
printf("Binary Number %x\n",Hex);
	for (count = 31; count >= 0; count--)
	{
		shift = Hex >> count;
		if (shift & 1)
		printf("1");
	else
		printf("0");
	}
	printf("\n");
}
