#include "common.h"

int get_nbit(int num, int lsb)/*formal argument*/
{
	int lsb_mask;
	printf("Binary of number n\n");
	binary(num);
	/* mask for extract n bits from number*/
	lsb_mask = ((1 << lsb)-1);
	n_bit= (lsb_mask & num);
	return (n_bit);
}
