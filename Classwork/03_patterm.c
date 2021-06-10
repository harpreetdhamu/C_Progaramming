/* WAP a Program to Print a pattern
 *  12344321
 *  123  321
 *  12    21
 *  1      1
 */

#include<stdio.h>
int main()
{
int i,j,k;
for(i=1;i<=4;i++)
{
k=1;
for (j=1;j<=8;j++)
	{	
	if(j<=5-i || j>=4+i)
		{	
		printf("%d",k);
		//j<4?k++:k--;
                	if (j<4)
			{
		 	k++;
			}	
			else if (j>4)	
			{
			k--;
			}
		}	
	else
		{		
		printf("-");
		if(j==4)
		k--;
		}
	}	
	printf("\n");
}
}
