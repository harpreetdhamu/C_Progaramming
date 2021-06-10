#include<stdio.h>
int main()
{
char num,i,mask;
printf("Enter a HEX Number:\n");
scanf("%hhx",&num);

printf("Before Swapping  a HEX Number %hhx:\n",num);
 for(i=15;i>=0;i--)
 {
 mask=1<<i;
 if((num & mask) ==0)
	 printf("0");
 else 
	 printf("1");
 }
 printf("\n");
	num=(num>>4)|(num<<4);
printf("After swapping a HEX Number %hhx:\n",num);
 for(i=15;i>=0;i--)
 {
 mask=1<<i;
 if((num & mask) ==0)
	 printf("0");
 else 
	 printf("1");
 }
 printf("\n");

}
