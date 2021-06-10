/*Based on previous example print following pyramid
  
 *
 * * *
 * * * * *
 * * * * * * *
 */

#include<stdio.h>

//int i,j;
int main()
{
int i,j,n,k;
printf("Enter a Number:\n ");
scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=1;j<=n*2-1;j++)
		{
			if(j>=n+1-i && j<=n-1+i && k)
			{
				printf("*");
				k=0;
			}
			else
			{
			printf(" ");
			k=1;
			}
		}
		printf("\n");
	}
	//return 0;
}
