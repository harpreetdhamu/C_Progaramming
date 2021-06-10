#include <stdio.h>

int main()
{
char count,Mask,Hex;
printf("Enter a Hex Number:\n");
scanf("%hhx",&Hex);
printf("Binary Number %x\n",Hex);
	for (count = 31; count >= 0; count--)
	{
		Mask = Hex << count;
		if (Hex & Mask==0)
		printf("1");
	else
		printf("0");
}
	printf("\n");
}
