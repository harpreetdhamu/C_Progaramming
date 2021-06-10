/*WAP to print power of two series using for loop
 */

#include<stdio.h>

void square_cube(int *Num,int *Num1 );
int main()
{

int Num,Num1,Total=0;
printf("Enter a Number:\n ");
scanf("%d",&Num);
Num1=Num;
square_cube(&Num, &Num1);

printf("Square ==%d,Cube ==%d\n",Num,Num1);

}

void square_cube(int *Num, int *Num1)
{
*Num =*Num * *Num;

*Num1 =*Num1 * *Num1 * *Num1;

}
