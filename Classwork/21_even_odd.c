#include<stdio.h>
#include<math.h>
int Num,Even,Odd, Result;
int Even_Odd(int);
int main()
{
	printf("Enter a Number\n");
	scanf("%d",&Num);
	Result= Even_Odd(Num);
	printf(" Number zero 'O' Is Even and Number one '1' is odd :%d \n ",Result);
	//return y ;
}


int Even_Odd(int Num)
{
	Result;
	if(Num %2 == 0)
		Result = 0;
	else
		Result = 1;
	return Result;
}
