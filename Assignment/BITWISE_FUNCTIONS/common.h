#ifndef COMMON_H
#define COMMON_H

/*1. Standatd Header*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*2. Macro*/

#define SUCCESS 0
#define FAILURE 1

#define LIST_NOT_EMPTY 0
#define LIST_EMPTY 1
#define DATA_NOT_FOUND 2  


/*3. User Defined datatype*/
int num, lsb, power, ch, n_bit, option, val, new_num, position, new_val_num;

unsigned int iter;
//unsigned int mask = (1 << sizeof(num)*8-1);
/*4. Function Declarations*/

int binary(int);

int get_nbit(int num, int lsb);

int replace_nbits(int num, int lsb, int val);

int get_nbits_from_pos(int num, int lsb, int position);

int replace_nbits_from_pos(int num, int lsb,int position,int val);

int toggle_bits_from_pos(int num, int lsb, int position);

int print_bits(unsigned int num, int lsb);


#endif

