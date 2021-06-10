
#include<stdio.h>

void sum_product(int *Num,int *Num1 );
int main()
{

int Num,Num1,Total=0;
printf("Enter a Number:\n ");
scanf("%d",&Num);
Num1 = Num;
sum_product(&Num, &Num1);

printf("%d,%d\n",Num,Num1);

}

void sum_product(int *Num, int *Num1)
{
*Num =*Num + *Num;

*Num1 =*Num1 * *Num1; 

}
