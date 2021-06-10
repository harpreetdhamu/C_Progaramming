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

#if 0
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int num, lsb, power, ch, n_bit, option, val, new_num, position, new_val_num;
unsigned int iter, mask = (1 << sizeof(num)*8-1);
/*function declarations*/
int binary(int);
int get_nbit(int num, int lsb);
int replace_nbits(int num, int lsb, int val);
int get_nbits_from_pos(int num, int lsb, int position);
int replace_nbits_from_pos(int num, int lsb,int position,int val);
int toggle_bits_from_pos(int num, int lsb, int position);
int print_bits(unsigned int num, int lsb); 
int main()
{
	do
	{
		printf("Select bit operation from below list\n");
		printf("1. Get_nbits\n2. Set(replace)_nbits\n3. Get_nbits_from_pos\n4. Set(replace)_nbits_from_pos\n5. Toggle_bits_from_pos\n6. Print_bits\n");
		printf("Enter a option\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				printf("Enter a number n:\n");
				scanf("%d",&num);
				printf("Enter a number lsb:\n");
				scanf("%d",&lsb);
				get_nbit(num,lsb);/*call get nbit function and pass values*/
				printf("Get n_bit == %d\n",n_bit);
				break;
			case 2:
				printf("Enter a number n:\n");
				scanf("%d",&num);
				printf("Enter a number n lsb:\n");
				scanf("%d",&lsb);
				printf("Enter a number val:\n");
				scanf("%d",&val);

				replace_nbits(num,lsb,val);/*call get nbit function and pass values*/
				printf("New value of num == %d\n",new_num);
				break;
			case 3:
				printf("Enter a number n:\n");
				scanf("%d",&num);
				printf("Enter a number n lsb:\n");
				scanf("%d",&lsb);
				printf("Enter a position:\n");
				scanf("%d",&position);
				get_nbits_from_pos(num,lsb,position);/*call get nbit from position function and pass values*/
				printf("New value of num == %d\n",new_num);
				break;
			case 4:
				printf("Enter a number n:\n");
				scanf("%d",&num);
				printf("Enter a number val:\n");
				scanf("%d",&val);
				printf("Enter a number n lsb:\n");
				scanf("%d",&lsb);
				printf("Enter a position:\n");
				scanf("%d",&position);
				replace_nbits_from_pos(num,lsb,position,val);/*call replace bit  from position function and pass values*/
				printf("New value of num == %d\n",new_num);
				break;
			case 5:
				printf("Enter a number n:\n");
				scanf("%d",&num);
				printf("Enter a number n lsb:\n");
				scanf("%d",&lsb);
				printf("Enter a position:\n");
				scanf("%d",&position);
				toggle_bits_from_pos(num,lsb,position);/*call toggle bit function and pass values*/
				printf("New value of num == %d\n",new_num);
				break;
			case 6:
				printf("Enter a number n:\n");
				scanf("%d",&num);
				printf("Enter a number lsb:\n");
				scanf("%d",&lsb);
				/*n(lsb) is greater than integer size, assign n(lsb) value as sizeof integ    er*/
				lsb = (lsb > sizeof(int)*8| lsb < 0)?sizeof(int)*8: lsb;
				print_bits(num,lsb); /*call print nbit function and pass values*/
				printf("New number of num == %d\n",num);
				break;
			default:
				printf("Please enter a number 1-6\n");
				break;
		}


		printf("Do you want to continue(y/n)\n");
		scanf("%ls",&ch);
		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else if (ch == 'N' || ch == 'n')
		{
			exit(1);
		}
		else
		{
			printf("Wrong input\n");
			exit(1);
		}
	}while(1);
}
/*function to print binary number of number*/
int binary(int num)
{
	for(iter=mask;iter!=0;iter>>=1)
	{
		(num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
}
/*take n bits from lsb end and return the corresponding decimal of that.*/
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
/* fetch n number of bits from lsb end of val and replace in the last n bits of num. return new value of num return lsb in integer form */
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
/*fetch n number of bits from given position 'pos' (starting from lsb) of num and return the decimal value of it*/
int get_nbits_from_pos(int num, int lsb, int position)
{
	int fetch, fetch_lsb, new_pos;
	printf("Binary of new number \n");
	binary(num);/*call the function print binary number of num*/
	new_pos = position - lsb +1;/*postion where to fetch the bits*/
	/*mask for fetch the bits from given position*/
	fetch = ((1 << lsb)-1) << new_pos;
	fetch_lsb = num & fetch;
	new_num = fetch_lsb >> new_pos;
	printf("Binary of new number n\n");
	binary(new_num); /*call the function to print new number*/ 
	return (new_num);

}
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
/*print n number of bits of num from lsb end.*/
int print_bits(unsigned int num, int lsb)
{
	printf("Binary of number \n");
	binary(num);/*function call for print binary number of num*/
	/*mask for print n number of bits from number*/
	mask = mask >> (mask - lsb);
	printf("Binary of new number \n");
	for(iter=mask;iter!=0;iter>>=1)
	{
		(num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
	return (num);
}

#endif
