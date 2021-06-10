/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP Implement the below mentioned bitwise functionsint
int get_nbits(int num, int n);
int replace_nbits(int num, int n, int val);
int get_nbits_from_pos(int num, int n, int pos);
int replace_nbits_from_pos(int num, int n, int pos, int val);
int toggle_bits_from_pos(int num, int n, int pos);
int print_bits(unsigned int num, int n) 
Date:14-May-2019
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "bitwiselib.c"
int Num,Lsb,Power,Char,N_bit,Option,Val,New_Num,Position,New_Val_Num;
int main()
{
	do
	{
		printf("Select bit operation from below list\n");
		printf("1. get_nbits\n2. set(replace)_nbits\n3. get_nbits_from_pos\n4. set(replace)_nbits_from_pos\n5. toggle_bits_from_pos\n6. print_bits\n");
		printf("Enter a Option\n");
		scanf("%d",&Option);
		switch (Option)
		{
			case 1:
				printf("Enter a Number N:\n");
				scanf("%d",&Num);
				printf("Enter a Number Lsb:\n");
				scanf("%d",&Lsb);
				get_nbit(Num,Lsb);/*Call get nbit function and pass values*/
				printf("Get N_bit == %d\n",N_bit);
				break;
			case 2:
				printf("Enter a Number N:\n");
				scanf("%d",&Num);
				printf("Enter a Number n Lsb:\n");
				scanf("%d",&Lsb);
				printf("Enter a Number Val:\n");
				scanf("%d",&Val);

				replace_nbits(Num,Lsb,Val);/*Call get nbit function and pass values*/
				printf("New Value of Num == %d\n",New_Num);
				break;
			case 3:
				printf("Enter a Number N:\n");
				scanf("%d",&Num);
				printf("Enter a Number n Lsb:\n");
				scanf("%d",&Lsb);
				printf("Enter a Position:\n");
				scanf("%d",&Position);
				get_nbits_from_pos(Num,Lsb,Position);/*Call get nbit from position function and pass values*/
				printf("New Value of Num == %d\n",New_Num);
				break;
			case 4:
				printf("Enter a Number N:\n");
				scanf("%d",&Num);
				printf("Enter a Number Val:\n");
				scanf("%d",&Val);
				printf("Enter a Number n Lsb:\n");
				scanf("%d",&Lsb);
				printf("Enter a Position:\n");
				scanf("%d",&Position);
				replace_nbits_from_pos(Num,Lsb,Position,Val);/*Call replace bit  from position function and pass values*/
				printf("New Value of Num == %d\n",New_Num);
				break;
			case 5:
				printf("Enter a Number N:\n");
				scanf("%d",&Num);
				printf("Enter a Number n Lsb:\n");
				scanf("%d",&Lsb);
				printf("Enter a Position:\n");
				scanf("%d",&Position);
				toggle_bits_from_pos(Num,Lsb,Position);/*Call toggle bit function and pass values*/
				printf("New Value of Num == %d\n",New_Num);
				break;
			case 6:
				printf("Enter a Number N:\n");
				scanf("%d",&Num);
				printf("Enter a Number Lsb:\n");
				scanf("%d",&Lsb);
				/*n(lsb) is greater than integer size, assign n(lsb) value as sizeof integ    er*/
				Lsb = (Lsb > sizeof(int)*8| Lsb < 0)?sizeof(int)*8: Lsb;
				print_bits(Num,Lsb); /*Call print nbit function and pass values*/
				printf("New Number of Num == %d\n",Num);
				break;
			default:
				printf("Please Enter a Number 1-6\n");
				break;
		}


		printf("Do You Want to Continue(Y/N)\n");
		scanf("%ls",&Char);
		if (Char == 'Y' || Char == 'y')
		{
			continue;
		}
		else if (Char == 'N' || Char == 'n')
		{
			exit(1);
		}
		else
		{
			printf("Wrong Input\n");
			exit(1);
		}
	}while(1);
}
