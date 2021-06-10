#include <stdio.h>
struct Nibble
{
	unsigned char lower	: 4;
	unsigned char upper	: 4;
};

int main()
{
	struct Nibble nibble;

	nibble.upper = 0x0A;
	nibble.lower = 0x02;
	printf("before swapping %#x\n",nibble);
	unsigned char temp = nibble.upper;
	nibble.upper = nibble.lower;
	nibble.lower = temp;
	printf("after swapping %#x\n",nibble);

	return 0;
}
