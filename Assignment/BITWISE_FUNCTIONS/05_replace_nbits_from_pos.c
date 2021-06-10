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


/* fetch n number of bits from lsb of val.place those fetched bits from pos positionth bit of num and return new value of num.*/
int replace_nbits_from_pos(int num, int lsb,int position,int val)
{
	int fetch, fetch_lsb_val, new_val, fetch_num_clear, new_pos;

	printf("Binary of new number \n");
	binary(num);/*function call for print binary number of num*/
	
	printf("Binary of value\n");
	binary(val);/*function for print binary number of value*/
	
	new_pos = position - lsb + 1;/*position for where to fetch the bits*/
	/*mask for fetch n number of bits from lsb of val*/
	
	fetch_lsb_val = ((1 << lsb)-1);
	
	new_val = fetch_lsb_val & val;
	/*mask for clear the bits for number that given position and place the fetch lsb bits in clear lsb number*/
	
	fetch_num_clear = ~((1 << lsb)-1)<< new_pos;
	
	new_val_num = fetch_num_clear & num;
	
	new_num = new_val_num | (new_val << new_pos);
	
	printf("Binary of new number n\n");
	binary(new_num); /*call the function to print new number*/ 
	
	return (new_num);
}

