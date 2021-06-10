/*
   Author Name: chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP Read int i, Read 0 ≤ a ≤ b ≤ 31. Read an int n, put the (b-a+1) lsb’s of n into [b:a]
Date:13-May-2019
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int num, num_I, ch, fetch, lsb, new_number, new_mask, fetch_I, new_mask_I, I_new;
unsigned int iter, pos_a, pos_b, mask = (1 << sizeof(num)*8 -1);
/*Function Declarations*/
unsigned binary(int);
unsigned set_nbits_from_pos(int,int,int);
int main()
{
	do
	{	
		printf("Enter a number N:\n");
		scanf("%d",&num);
		printf("Enter a number I:\n");
		scanf("%d",&num_I);
		printf("Enter a Position A:\n");
		scanf("%d",&pos_a);
		printf("Enter a Position B:\n");
		scanf("%d",&pos_b);


		/*pos_a  and pos_b is Greater than 31 then exit the program*/
		if (pos_a < 0 || pos_a  > 31 || pos_b < pos_a || pos_b > 31)
		{
			printf("Oops!!!Enter  Valid number \n");
			exit(1);
		}

		/*fetch How many Bits from Given Poistion number N */
		lsb = (pos_b - pos_a + 1);

		set_nbits_from_pos(num, num_I, lsb);

		printf("Do You Want to Continue(Y/N)\n");
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
			printf("Wrong Input\n");
			exit(1);
		}
	}while(1);
}
/*Function of  number n convert to Binary Form */
unsigned binary(int num)/*Formal Argument*/
{
	for(iter=mask;iter!=0;iter>>=1)
	{
		(num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
	return 0;
}
unsigned set_nbits_from_pos(int num,int num_I,int lsb)
{
	printf("Binary Of number N\n");
	binary(num);/*Actual arguments and function call to Num n */
	printf("Binary Of number I\n");
	binary(num_I);/*Actual arguments and function Call to num_I*/
	/*mask of number N lsb Bits*/
	fetch = ((1 << lsb)-1);

	new_mask = fetch & num;/*fetch the lsb bits and store in new_mask  */
	/*mask of clear the bits of num I*/
	fetch_I = ((1 << lsb)-1);

	new_mask_I = ~(fetch_I<<lsb);/*Invert the Fetch I Bits and shift his position */
	/* Clear the bits in num I for placing a num N lsb bits */
	new_number = new_mask_I & num_I;

	/* place the  num N lsb bits in num I position [b:a] */
	I_new = new_number | (new_mask << pos_a);
	printf("I_new = %d\n\n",I_new);
	printf("Binary Of I_new \n");
	binary(I_new);/*Actual arguments and function call to new I*/
	return 0;
}
