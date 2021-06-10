#include <stdio.h>

union FloatBits
{

	struct
	{
		unsigned m : 23;
		unsigned e : 8;
		unsigned s : 1;
	} elements;
};

int main()
{
	union FloatBits fb ;
	fb.elements.s = 0x0;
	fb.elements.e =0x80;
	fb.elements.m =0x13333;
	printf("Sign: %X\n", fb.elements.s);
	printf("Exponent: %X\n", fb.elements.e);
	printf("Mantissa: %X\n", fb.elements.m);
	printf("degree: %f\n",fb.degree);

	return 0;
}
