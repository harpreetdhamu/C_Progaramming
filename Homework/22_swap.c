
#include<stdio.h>

void swap(int *Num,int *Num1 );
int main()
{

int Num,Num1,Total=0;
printf("Enter a Number Before Swapping:\n ");
scanf("%d %d",&Num,&Num1);

swap(&Num, &Num1);

printf("Enter a Number after Swapping:\n ");
printf("%d,%d\n",Num,Num1);

}

void swap(int *Num, int *Num1)
{
	int temp=0;
	temp= *Num;
	*Num = *Num1;
	*Num1 = temp;

}
