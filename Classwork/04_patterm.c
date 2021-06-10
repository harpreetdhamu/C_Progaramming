/* WAP a Program to Print a pattern
 *  12344321
 *  123  321
 *  12    21
 *  1      1
 */

#include<stdio.h>
int main()
{
int i,j,k,n,p,q,r;
printf("Enter a Number: ");
scanf("%d",&n);
if (n>9 && n<2)
{
printf("Error: Enter Valid Number")
}
//mid=(p+1-i)/2
for(i=1;i<=n;i++)
{
k=1;
p=n*2;
for (j=1;j<=p;j++)
	{
	q=(p+2)/2;
r=p/2;
	if(j<=q-i || j>=r+i)
		{	
		printf("%d",k);
		//j<4?k++:k--;
                	if (j<r)
			{
		 	k++;
			}	
			else if (j>r)	
			{
			k--;
			}
		}	
	else
		{		
		printf(" ");
		if(j==r)
		k--;
		}
	}	
	printf("\n");
}
}
