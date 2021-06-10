#include <stdio.h>

struct Nibble
{
	unsigned char upper	: 4;
	unsigned char lower	: 4;
};

int main()
{
	struct Nibble nibble;
	char *p = (char*)&nibble;
	nibble.upper = 0x0A;
	nibble.lower = 0x02;

printf("upper = %#x,lower = %#x byte = %#x\n ",nibble.upper,nibble.lower,*p);
	return 0;
}
