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

int Num,Lsb,Power,Char,N_bit,Option,Val,New_Num,Position,New_Val_Num;
unsigned int iter,Mask=0x80000000;
/*Function Declarations*/
int binary_number(int Num);
int Value(int Val);
int New_number(int New_Num);
int get_nbit(int Num, int Lsb);
int replace_nbits(int Num, int Lsb, int Val);
int get_nbits_from_pos(int Num, int Lsb, int Position);
int replace_nbits_from_pos(int Num, int Lsb,int Position,int Val);
int toggle_bits_from_pos(int Num, int Lsb, int Position);
int print_bits(unsigned int Num, int Lsb); 




/*Function To Print binary number of Number*/
int binary_number(int Num)
{
	printf("Binary Of Number N\n");
	for(iter=Mask;iter!=0;iter>>=1)
	{
		(Num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
}
/*Function To Print Value of Number*/
int Value(int Val)
{
	printf("Binary Of Value\n");
	for(iter=Mask;iter!=0;iter>>=1)
	{
		(Val & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
}
/*Function To Print binary number of New Number*/
int New_number(int New_Num)
{
	printf("Binary Of New Number N\n");
	for(iter=Mask;iter!=0;iter>>=1)
	{
		(New_Num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
}

/*Take N bits from LSB end and return the corresponding decimal of that.*/
int get_nbit(int Num, int Lsb)/*Formal Argument*/
{
	int Lsb_Mask;
	binary_number(Num);
	/* Mask For Extract n Bits From Number*/
	Lsb_Mask = ((1 << Lsb)-1);
	N_bit= (Lsb_Mask & Num);
	return (N_bit);
}
/* Fetch n number of bits from LSB end of val and replace in the last n bits of num. Return new value of num return lsb in integer form */
int replace_nbits(int Num, int Lsb, int Val)
{
	int Mask_Val,Fetch_Lsb,Mask_Num,Clear_Lsb_Num;
	binary_number(Num);/*Call the Function Print binary Number*/
	Value(Val);/*Call The Function Print value*/
	/*Mask For Fetch The N number of Lsb from Value*/
	Mask_Val = ((1 << Lsb)-1);
	Fetch_Lsb = Mask_Val & Val;
	/*Mask for clear the bits for Number that given position and place the fetch Lsb bits in clear Lsb number*/
	Mask_Num=~((1 << Lsb)-1);
	Clear_Lsb_Num = Mask_Num & Num;
	New_Num = Clear_Lsb_Num | Fetch_Lsb;
	New_number(New_Num);/*Call the function to print new number*/
	return (New_Num);
}
/*Fetch n number of bits from given position 'pos' (starting from LSB) of num and return the decimal value of it*/
int get_nbits_from_pos(int Num, int Lsb, int Position)
{
	int Fetch,Fetch_Lsb,New_Pos;
	binary_number(Num);/*Call the function print binary number of Num*/
	New_Pos= Position - Lsb +1;/*Postion where to fetch the bits*/
	/*Mask for fetch the bits from given position*/
	Fetch = ((1 << Lsb)-1) << New_Pos;
	Fetch_Lsb = Num & Fetch;
	New_Num= Fetch_Lsb >> New_Pos;
	New_number(New_Num); /*Call the function to print new number*/ 
	return (New_Num);

}
/* Fetch n number of bits from LSB of val.Place those fetched bits from pos positionth bit of num and return new value of num.*/
int replace_nbits_from_pos(int Num, int Lsb,int Position,int Val)
{
	int Fetch,Fetch_Lsb_Val,New_Val,Fetch_Num_Clear,New_Pos;
	binary_number(Num);/*function call for print binary number of num*/
	Value(Val);/*function for print binary number of value*/
	New_Pos= Position - Lsb +1;/*position for where to fetch the bits*/
	/*Mask for Fetch n number of bits from LSB of val*/
	Fetch_Lsb_Val= ((1 << Lsb)-1);
	New_Val = Fetch_Lsb_Val & Val;
	/*Mask for clear the bits for Number that given position and place the fetch Lsb bits in clear Lsb number*/
	Fetch_Num_Clear = ~((1 << Lsb)-1)<< New_Pos;
	New_Val_Num= Fetch_Num_Clear & Num;
	New_Num = New_Val_Num | (New_Val << New_Pos);
	New_number(New_Num); /*Call the function to print new number*/ 
	return (New_Num);
}
/*Invert the n number of bits from pos positionth bit of num.Return the new value of num*/
int toggle_bits_from_pos(int Num, int Lsb, int Position)
{
	int Fetch,New_Pos;
	binary_number(Num);/*function call for print binary number of num*/
	New_Pos= Position - Lsb + 1;/*position for where to fetch the bits*/
	/*Mask for Invert the n number of bits from pos positionth bit of num*/
	Fetch = ((1 << Lsb)-1)<< New_Pos;
	New_Num = Num ^ Fetch ;
	New_number(New_Num); /*Call the function to print new number*/ 
	return (New_Num);

}
/*Print n number of bits of num from LSB end.*/
int print_bits(unsigned int Num, int Lsb)
{
	binary_number(Num);/*function call for print binary number of num*/
	/*Mask for print N number of bits from number*/
	Mask= Mask >>(Mask - Lsb);
	printf("Binary Of New Number \n");
	for(iter=Mask;iter!=0;iter>>=1)
	{
		(Num & iter)?printf("1"):printf("0");
	}
	printf("\n\n");
	return (Num);
}
