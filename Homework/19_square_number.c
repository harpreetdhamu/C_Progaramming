/*WAP to print power of two series using for loop
 */

#include<stdio.h>

void square(int *Num );
int main()
{

int Num,Total=0;
printf("Emter a Number:\n ");
scanf("%d",&Num);
square(&Num);

printf("%d,",Num);

}

void square(int *Num)
{
*Num =*Num * *Num;
}
