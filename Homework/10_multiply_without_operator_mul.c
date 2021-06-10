/*W.A.P to multiply 2 nos without multiplication operator
 */

#include<stdio.h>

int Num1,Num2,Total=0,i;
int main()
{
printf("Enter a Two Numbers:\n ");
scanf("%d %d",&Num1,&Num2);
i=Num2;
do
{
Total=Num1 + Total;
i--;
}while(i>0);

printf("Number1: %d Multiply Number2: %d is %d :\n ",Num1,Num2,Total);
//printf("%d,",Total);
}
