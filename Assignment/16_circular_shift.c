/*
   Author Name: Chanchal Parkash
   Organization Name: Emertxe Information Technoligies Pvt.Ltd. Banglore
Title:WAP to  Read an int, & a no. n. Circular right & left shift the int by n
Date:07-May-2019
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int i,j,Num,Position,lsb,Mask=0x80000000,Power,Charbit=8,Char;
unsigned int iter,LeftShift,RightShift;
int main()
{
	do
	{	
	printf("Enter a Number:\n");
	scanf("%d",&Num);
	printf("Enter a Position:\n");
	scanf("%d",&Position);
	/*
	   Power=pow(2,20);
	   if (Num > Power)
	   {
	   printf("Oops!!!Enter a Valid Number \n");
	   exit(1);
	   }*/
printf("Binary Of Number Before Shifting\n");
	 for(iter=Mask;iter!=0;iter>>=1)
     {
         if(Num&iter)
         {
             printf("1");
         }
         else
         {
             printf("0");
         }
     }
         printf("\n");
		 RightShift = (Num << Position) | (Num >> (sizeof(Num)*Charbit - Position));

printf("Binary Of Number After Right Shifting\n");
	 
for(iter=Mask;iter!=0;iter>>=1)
     {
         if(RightShift&iter)
         {
             printf("1");
         }
         else
         {
             printf("0");
         }
     }
         printf("\n");
		 
		 LeftShift = (Num >> Position) | (Num << (sizeof(Num)*Charbit - Position));

printf("Binary Of Number After Left Shifting\n");
	 
for(iter=Mask;iter!=0;iter>>=1)
     {
         if(LeftShift&iter)
         {
             printf("1");
         }
         else
         {
             printf("0");
         }
     }
         printf("\n");




   printf("Do You Want to Continue(Y/N)\n");
   scanf("%ls",&Char);
   if (Char == 'Y' || Char == 'y')
   {
   continue;
   }
   else if (Char == 'N' || Char == 'n')
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

