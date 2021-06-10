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

// unsigned int mask = (1 << sizeof(num)*8-1);

/*fetch n number of bits from given position 'pos' (starting from lsb) of num and return the decimal value of it*/
int get_nbits_from_pos(int num, int lsb, int position)
{
	int fetch, fetch_lsb, new_pos;

	printf("Binary of new number \n");
	binary(num);/*call the function print binary number of num*/
	
	new_pos = position - lsb + 1;/*postion where to fetch the bits*/
	
	/*mask for fetch the bits from given position*/
	fetch = ((1 << lsb)-1) << new_pos;
	
	fetch_lsb = num & fetch;
	
	new_num = fetch_lsb >> new_pos;
	
	printf("Binary of new number n\n");
	binary(new_num); /*call the function to print new number*/ 
	
	return (new_num);

}
