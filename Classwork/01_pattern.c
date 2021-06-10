/*WAP a Program to print a pattern
 *****
 * *
 * * 
 * *
 ***** */


#include<stdio.h>

void main()
{
 int i,j;
 for(i=1; i<=5; i++)
   {
   for(j=1; j<=5; j++)
    	{
		if(j<=5)
		{
		printf("*");
		}	
		else
		{
		printf("-");
		}
   	}
   printf("\n");
   }
 

}

