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

//int num, lsb, power, ch, n_bit, option, val, new_num, position, new_val_num;
unsigned int mask = (1 << sizeof(num)*8-1);
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
