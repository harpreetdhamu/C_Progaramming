/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:Wap implement the below mentioned bitwise functionsint
int get_nbits(int num, int n);
int replace_nbits(int num, int n, int val);
int get_nbits_from_pos(int num, int n, int pos);
int replace_nbits_from_pos(int num, int n, int pos, int val);
int toggle_bits_from_pos(int num, int n, int pos);
int print_bits(unsigned int num, int n) 
Date:14-May-2019
 */


#include "common.h"

/*function to print binary number of number*/
int binary(int num)
{

	unsigned int mask = (1 << sizeof(num)*8-1);
	for(iter=mask;iter!=0;iter>>=1)
	{
		(num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
}
