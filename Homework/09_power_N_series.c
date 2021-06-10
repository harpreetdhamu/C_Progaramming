/*WAP to print power of N series using While loop
 */

#include<stdio.h>

int Power,Num,Total=1,i=0;
int main()
{
printf("Enter a Number and Power:\n ");
scanf("%d %d",&Num,&Power);

while(i<Power)
{

Total=Total*Num;
printf("%d,",Total);
i++;
}
printf("\n");
}
