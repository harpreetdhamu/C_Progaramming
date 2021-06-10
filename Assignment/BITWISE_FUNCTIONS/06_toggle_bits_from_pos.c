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


/*invert the n number of bits from pos positionth bit of num.return the new value of num*/
int toggle_bits_from_pos(int num, int lsb, int position)
{
	int fetch, new_pos;
	printf("Binary of new number \n");
	binary(num);/*function call for print binary number of num*/

	new_pos = position - lsb + 1;/*position for where to fetch the bits*/
	
	/*mask for invert the n number of bits from pos positionth bit of num*/
	fetch = ((1 << lsb)-1)<< new_pos;
	
	new_num = num ^ fetch ;
	
	printf("Binary of new number n\n");
	binary(new_num); /*call the function to print new number*/ 
	
	return (new_num);


}
