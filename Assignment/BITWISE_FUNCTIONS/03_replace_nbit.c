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
/*take n bits from lsb end and return the corresponding decimal of that.*/

// unsigned int mask = (1 << sizeof(num)*8-1);
int replace_nbits(int num, int lsb, int val)
{
	int mask_val, fetch_lsb, mask_num, clear_lsb_num;
	printf("Binary of new number \n");
	binary(num);/*call the function print binary number*/

	printf("Binary of value\n");
	binary(val);/*call the function print value*/
	/*mask for fetch the n number of lsb from value*/
	
	mask_val = ((1 << lsb)-1);
	
	fetch_lsb = mask_val & val;
	
	/*mask for clear the bits for number that given position and place the fetch lsb bits in clear lsb number*/
	mask_num = ~((1 << lsb)-1);
	
	clear_lsb_num = mask_num & num;
	
	new_num = clear_lsb_num | fetch_lsb;
	
	printf("Binary of new number n\n");
	binary(new_num);/*call the function to print new number*/
	
	return (new_num);
}
